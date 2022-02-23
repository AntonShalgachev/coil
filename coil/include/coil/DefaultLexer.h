#pragma once

#include <string_view>
#include <optional>
#include <cctype>

#include "DefaultLexer.h"
#include "ExecutionInput.h"
#include "Expected.h"
#include "utils/Utils.h"

namespace coil
{
    struct ExecutionInput;

    struct DefaultLexer
    {
    public:
        Expected<std::reference_wrapper<ExecutionInput>, std::string> operator()(std::string_view str) const
        {
            m_input.reset();
            m_tokens.resize(0);

            if (auto res = tokenize(str); !res)
                return makeUnexpected(std::move(res).error());

            if (auto res = parse(); !res)
                return makeUnexpected(std::move(res).error());

            return std::ref(m_input);
        }

    private:
        enum class CharType
        {
            Space,
            String,
            Assignment,
        };

        enum class TokenType
        {
            String,
            Assignment,
        };

        struct Token
        {
            TokenType type = TokenType::String;
            std::string_view value;
        };

        static CharType getCharType(unsigned char c)
        {
            if (c == '=')
                return CharType::Assignment;
            if (std::isspace(c))
                return CharType::Space;

            return CharType::String;
        }

        static std::optional<TokenType> convertToTokenType(CharType type)
        {
            switch (type)
            {
            case CharType::String:
                return TokenType::String;
            case CharType::Assignment:
                return TokenType::Assignment;
            default:
                break;
            }

            return {};
        }

        static ArgValue createArgValue(std::string_view value)
        {
            // TODO implement
            return ArgValue{ value };
        }

        coil::Expected<void, std::string> tokenize(std::string_view str) const
        {
            std::size_t tokenBegin = std::string_view::npos;
            CharType currentCharType = CharType::Space;

            auto tryAddPreviousToken = [this, &tokenBegin, &currentCharType, &str](std::size_t tokenEnd) -> coil::Expected<void, std::string>
            {
                if (tokenBegin == std::string_view::npos)
                    return {};
                if (currentCharType == CharType::Space)
                    return {};

                auto tokenType = convertToTokenType(currentCharType);
                if (!tokenType)
                    return makeUnexpected("Lexer internal error");

                m_tokens.push_back(Token{ *tokenType, str.substr(tokenBegin, tokenEnd - tokenBegin) });
                return {};
            };

            for (std::size_t i = 0; i < str.size(); i++)
            {
                CharType charType = getCharType(str[i]);

                if (currentCharType != charType)
                {
                    if (auto result = tryAddPreviousToken(i); !result)
                        return result;

                    tokenBegin = i;
                    currentCharType = charType;
                }
            }

            return tryAddPreviousToken(str.size());
        }

        Expected<void, std::string> parse() const
        {
            if (m_tokens.empty())
                return {};

            Token const& firstToken = m_tokens.front();
            if (firstToken.type != TokenType::String)
                return makeUnexpected(utils::formatString("Unexpected token '%.*s' at the beginning of the expression", firstToken.value.size(), firstToken.value.data()));

            m_input.name = firstToken.value;

            struct ArgTokens
            {
                std::optional<std::size_t> primaryTokenIndex;
                std::optional<std::size_t> secondaryTokenIndex;

                void reset()
                {
                    primaryTokenIndex = {};
                    secondaryTokenIndex = {};
                }

                bool empty()
                {
                    return !primaryTokenIndex && !secondaryTokenIndex;
                }
            };

            enum class StringTokenType
            {
                PrimaryToken,
                SecondaryToken,
            };

            ArgTokens tokens;
            StringTokenType nextTokenType = StringTokenType::PrimaryToken;

            auto addCurrentTokens = [this, &tokens]() {
                if (!tokens.primaryTokenIndex)
                    return;

                std::string_view primaryValue = m_tokens[*tokens.primaryTokenIndex].value;
                if (tokens.secondaryTokenIndex)
                {
                    std::string_view secondaryValue = m_tokens[*tokens.secondaryTokenIndex].value;
                    m_input.namedArguments.emplace_back(primaryValue, createArgValue(secondaryValue));
                }
                else
                {
                    m_input.arguments.push_back(createArgValue(primaryValue));
                }

                tokens.reset();
            };

            for (std::size_t i = 1; i < m_tokens.size(); i++)
            {
                Token const& token = m_tokens[i];

                switch (token.type)
                {
                case TokenType::Assignment:
                    if (!tokens.primaryTokenIndex)
                        return makeUnexpected("Unexpected token '=': no named for the named argument is provided");
                    nextTokenType = StringTokenType::SecondaryToken;
                    break;
                case TokenType::String:
                    switch (nextTokenType)
                    {
                    case StringTokenType::PrimaryToken:
                        if (tokens.primaryTokenIndex)
                            addCurrentTokens();
                        tokens.primaryTokenIndex = i;
                        break;
                    case StringTokenType::SecondaryToken:
                        if (!tokens.primaryTokenIndex)
                            return makeUnexpected("Internal error");

                        tokens.secondaryTokenIndex = i;
                        addCurrentTokens();
                        break;
                    }

                    nextTokenType = StringTokenType::PrimaryToken;
                    break;
                }
            }

            if (nextTokenType == StringTokenType::SecondaryToken)
                return makeUnexpected("Expected an argument value, found end of string");

            addCurrentTokens();

            return {};
        }

        // TODO not thread safe
        mutable ExecutionInput m_input;
        mutable std::vector<Token> m_tokens;
    };
}
