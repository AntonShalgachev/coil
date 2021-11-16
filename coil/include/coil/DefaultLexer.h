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
        Expected<ExecutionInput, std::string> operator()(std::string_view str) const
        {
            return parse(tokenize(str));
        }

    private:
        enum class CharType
        {
            Space,
            String,
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

        static CharType getCharType(unsigned char c)
        {
            if (c == '.')
                return CharType::Dot;
            if (c == '=')
                return CharType::Assignment;
            if (std::isspace(c))
                return CharType::Space;

            return CharType::String;
        }

        static TokenType convertToTokenType(CharType type)
        {
            switch (type)
            {
            case CharType::String:
                return TokenType::String;
            case CharType::Dot:
                return TokenType::Dot;
            case CharType::Assignment:
                return TokenType::Assignment;
            }

            // TODO logic error
            return TokenType::String;
        }

        std::vector<Token> tokenize(std::string_view str) const
        {
            std::vector<Token> tokens;

            std::size_t tokenBegin = std::string_view::npos;
            CharType currentCharType = CharType::Space;

            auto tryAddPreviousToken = [&tokens, &tokenBegin, &currentCharType, &str](std::size_t tokenEnd)
            {
                if (tokenBegin == std::string_view::npos)
                    return;
                if (currentCharType == CharType::Space)
                    return;
                
                tokens.push_back(Token{ convertToTokenType(currentCharType), str.substr(tokenBegin, tokenEnd - tokenBegin) });
            };

            for (std::size_t i = 0; i < str.size(); i++)
            {
                CharType charType = getCharType(str[i]);

                if (currentCharType != charType)
                {
                    tryAddPreviousToken(i);
                    tokenBegin = i;
                    currentCharType = charType;
                }
            }

            tryAddPreviousToken(str.size());

            return tokens;
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

        Expected<std::vector<TokenGroup>, std::string> groupTokens(std::vector<Token> const& tokens) const
        {
            std::vector<TokenGroup> tokenGroups;

            for (std::size_t i = 0; i < tokens.size(); i++)
            {
                bool const hasPreviousGroup = !tokenGroups.empty();

                if (tokens[i].type == TokenType::String)
                {
                    if (hasPreviousGroup && tokenGroups.back().lacksSecondaryToken())
                        tokenGroups.back().secondaryTokenIndex = i;
                    else
                        tokenGroups.push_back(TokenGroup{ i, invalidIndex, invalidIndex });
                }
                else
                {
                    std::string_view tokenValue = tokens[i].value;

                    if (!hasPreviousGroup)
                        return makeUnexpected(utils::formatString("Unexpected token '%.*s' at the beginning of the expression", tokenValue.size(), tokenValue.data()));

                    TokenGroup& previousGroup = tokenGroups.back();
                    if (previousGroup.secondaryTokenIndex != invalidIndex)
                    {
                        return makeUnexpected(utils::formatString("Unexpected token '%.*s'; previous token group is already complete", tokenValue.size(), tokenValue.data()));
                    }
                    if (previousGroup.separatorTokenIndex != invalidIndex)
                        return makeUnexpected(utils::formatString("Unexpected token '%.*s'; previous token group already has a token", tokenValue.size(), tokenValue.data()));

                    if (i + 1 >= tokens.size())
                        return makeUnexpected(utils::formatString("Unexpected token '%.*s' at the end of the expression", tokenValue.size(), tokenValue.data()));

                    previousGroup.separatorTokenIndex = i;
                }
            }

            return tokenGroups;
        }

        Expected<ExecutionInput, std::string> parse(std::vector<Token> tokens) const
        {
            ExecutionInput input;

            auto tokenGroups = groupTokens(tokens);

            if (!tokenGroups)
                return makeUnexpected(tokenGroups.error());

            for (TokenGroup const& group : *tokenGroups)
            {
                if (group.lacksSecondaryToken())
                {
                    // TODO logic error
                }

                Token const& primaryToken = tokens[group.primaryTokenIndex];

                TokenType type = group.separatorTokenIndex != invalidIndex ? tokens[group.separatorTokenIndex].type : TokenType::String;
                std::string_view secondaryTokenValue = group.secondaryTokenIndex != invalidIndex ? tokens[group.secondaryTokenIndex].value : std::string_view{};

                if (input.name.empty())
                {
                    if (type == TokenType::Dot)
                        input.setTargetAndName(primaryToken.value, secondaryTokenValue);
                    else if (type == TokenType::String)
                        input.name = primaryToken.value;
                    else
                        return makeUnexpected("Unexpected named argument at the beginning of the expression");
                }
                else
                {
                    if (type == TokenType::Assignment)
                        input.namedArguments.emplace(primaryToken.value, secondaryTokenValue);
                    else if (type == TokenType::String)
                        input.arguments.emplace_back(primaryToken.value);
                    else
                        return makeUnexpected("Unexpected token '.' when the function name has already been defined");
                }
            }

            return input;
        }
    };
}
