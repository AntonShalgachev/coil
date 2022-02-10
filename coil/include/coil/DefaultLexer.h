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
            Number,
            Dot,
            Assignment,
        };

        enum class TokenType
        {
            String,
            Dot,
            Assignment,
        };

        struct Token
        {
            TokenType type = TokenType::String;
            std::string_view value;
        };

        static CharType getCharType(CharType currentCharType, unsigned char c)
        {
            if (c == '=')
                return CharType::Assignment;
            if (std::isspace(c))
                return CharType::Space;

            if (c == '.' && currentCharType == CharType::Number)
                return CharType::Number;
            if (c == '.' && currentCharType != CharType::Number)
                return CharType::Dot;

            if (std::isdigit(c) && currentCharType != CharType::String)
                return CharType::Number;

            return CharType::String;
        }

        static std::optional<TokenType> convertToTokenType(CharType type)
        {
            switch (type)
            {
            case CharType::String:
            case CharType::Number:
                return TokenType::String;
            case CharType::Dot:
                return TokenType::Dot;
            case CharType::Assignment:
                return TokenType::Assignment;
            default:
                break;
            }

            return {};
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
                CharType charType = getCharType(currentCharType, str[i]);

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
                Path,
                PrimaryToken,
                SecondaryToken,
            };

            ArgTokens tokens;
            StringTokenType nextTokenType = StringTokenType::Path;

            auto addCurrentTokens = [this, &tokens]() {
                if (!tokens.primaryTokenIndex)
                    return;

                std::string_view primaryValue = m_tokens[*tokens.primaryTokenIndex].value;
                if (tokens.secondaryTokenIndex)
                {
                    std::string_view secondaryValue = m_tokens[*tokens.secondaryTokenIndex].value;
                    m_input.namedArguments.emplace_back(primaryValue, secondaryValue);
                }
                else
                {
                    m_input.arguments.push_back(primaryValue);
                }

                tokens.reset();
            };

            for (std::size_t i = 0; i < m_tokens.size(); i++)
            {
                Token const& token = m_tokens[i];

                switch (token.type)
                {
                case TokenType::Assignment:
                    if (m_input.categoryPath.empty())
                        return makeUnexpected("Unexpected token '=' at the beginning of the expression");
                    if (!tokens.primaryTokenIndex)
                        return makeUnexpected("Unexpected token '=': no named for the named argument is provided");
                    nextTokenType = StringTokenType::SecondaryToken;
                    break;
                case TokenType::Dot:
                    if (m_input.categoryPath.empty())
                        return makeUnexpected("Unexpected token '.' at the beginning of the expression");
                    if (!m_input.arguments.empty() || !m_input.namedArguments.empty() || !tokens.empty())
                        return makeUnexpected("Unexpected token '.' after an argument was specified");
                    nextTokenType = StringTokenType::Path;
                    break;
                case TokenType::String:
                    switch (nextTokenType)
                    {
                    case StringTokenType::Path:
                        m_input.categoryPath.push_back(token.value);
                        break;
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

            if (nextTokenType == StringTokenType::Path)
                return makeUnexpected("Expected a command name, found end of string");
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
