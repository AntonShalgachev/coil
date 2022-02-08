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
            m_tokenGroups.resize(0);

            if (auto res = tokenize(str); !res)
                return makeUnexpected(res.error());

            auto result = parse();

            if (result)
                return std::ref(m_input);

            return makeUnexpected(std::move(result).error());
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

        static std::size_t const invalidIndex = static_cast<std::size_t>(-1);

        struct TokenGroup
        {
            std::size_t primaryTokenIndex = invalidIndex;
            std::size_t secondaryTokenIndex = invalidIndex;
            std::size_t separatorTokenIndex = invalidIndex;

            bool lacksSecondaryToken() const
            {
                bool const separatorTokenValid = separatorTokenIndex != invalidIndex;
                bool const secondaryTokenValid = secondaryTokenIndex != invalidIndex;
                return separatorTokenValid && !secondaryTokenValid;
            }
        };

        Expected<void, std::string> groupTokens() const
        {
            for (std::size_t i = 0; i < m_tokens.size(); i++)
            {
                bool const hasPreviousGroup = !m_tokenGroups.empty();

                if (m_tokens[i].type == TokenType::String)
                {
                    if (hasPreviousGroup && m_tokenGroups.back().lacksSecondaryToken())
                        m_tokenGroups.back().secondaryTokenIndex = i;
                    else
                        m_tokenGroups.push_back(TokenGroup{ i, invalidIndex, invalidIndex });
                }
                else
                {
                    std::string_view tokenValue = m_tokens[i].value;

                    if (!hasPreviousGroup)
                        return makeUnexpected(utils::formatString("Unexpected token '%.*s' at the beginning of the expression", tokenValue.size(), tokenValue.data()));

                    TokenGroup& previousGroup = m_tokenGroups.back();

                    if (previousGroup.secondaryTokenIndex != invalidIndex)
                        return makeUnexpected(utils::formatString("Unexpected token '%.*s'; previous token group is already complete", tokenValue.size(), tokenValue.data()));
                    if (previousGroup.separatorTokenIndex != invalidIndex)
                        return makeUnexpected(utils::formatString("Unexpected token '%.*s'; previous token group already has a token", tokenValue.size(), tokenValue.data()));
                    if (i + 1 >= m_tokens.size())
                        return makeUnexpected(utils::formatString("Unexpected token '%.*s' at the end of the expression", tokenValue.size(), tokenValue.data()));

                    previousGroup.separatorTokenIndex = i;
                }
            }

            return {};
        }

        Expected<void, std::string> parse() const
        {
            auto tokenGroups = groupTokens();

            if (!tokenGroups)
                return makeUnexpected(tokenGroups.error());

            for (TokenGroup const& group : m_tokenGroups)
            {
                if (group.lacksSecondaryToken())
                {
                    return makeUnexpected("Lexer internal error");
                }

                Token const& primaryToken = m_tokens[group.primaryTokenIndex];

                TokenType type = group.separatorTokenIndex != invalidIndex ? m_tokens[group.separatorTokenIndex].type : TokenType::String;
                std::string_view secondaryTokenValue = group.secondaryTokenIndex != invalidIndex ? m_tokens[group.secondaryTokenIndex].value : std::string_view{};

                if (m_input.categoryPath.empty())
                {
                    if (type == TokenType::Dot)
                        m_input.categoryPath.push_back(secondaryTokenValue);
                    else if (type == TokenType::String)
                        m_input.categoryPath.push_back(primaryToken.value);
                    else
                        return makeUnexpected("Unexpected named argument at the beginning of the expression");
                }
                else
                {
                    if (type == TokenType::Assignment)
                        m_input.namedArguments.emplace_back(primaryToken.value, secondaryTokenValue);
                    else if (type == TokenType::String)
                        m_input.arguments.emplace_back(primaryToken.value);
                    else
                        return makeUnexpected("Unexpected token '.' when the function name has already been defined");
                }
            }

            return {};
        }

        // TODO not thread safe
        mutable ExecutionInput m_input;
        mutable std::vector<Token> m_tokens;
        mutable std::vector<TokenGroup> m_tokenGroups;
    };
}
