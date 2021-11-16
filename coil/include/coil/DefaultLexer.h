#pragma once

#include <string>
#include <optional>
#include <cctype>

#include "DefaultLexer.h"
#include "ExecutionInput.h"

namespace coil
{
    struct ExecutionInput;

    struct DefaultLexer
    {
    public:
        ExecutionInput operator()(std::string_view str) const
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
            else if (c == '=')
                return CharType::Assignment;
            else if (std::isspace(c))
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

        std::vector<TokenGroup> groupTokens(std::vector<Token> const& tokens) const
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
                    if (hasPreviousGroup)
                    {
                        // TODO report error
                    }
                    TokenGroup& previousGroup = tokenGroups.back();
                    if (previousGroup.secondaryTokenIndex != invalidIndex)
                    {
                        // TODO report error
                    }
                    if (previousGroup.separatorTokenIndex != invalidIndex)
                    {
                        // TODO report error
                    }
                    if (i + 1 >= tokens.size())
                    {
                        // TODO report error
                    }

                    previousGroup.separatorTokenIndex = i;
                }
            }

            return tokenGroups;
        }

        ExecutionInput parse(std::vector<Token> tokens) const
        {
            ExecutionInput input;

            auto tokenGroups = groupTokens(tokens);

            for (TokenGroup const& group : tokenGroups)
            {
                if (group.lacksSecondaryToken())
                {
                    // TODO logic error
                }

                Token const& primaryToken = tokens[group.primaryTokenIndex];

                TokenType type = group.separatorTokenIndex != invalidIndex ? tokens[group.separatorTokenIndex].type : TokenType::String;
                std::string_view secondaryTokenValue = group.secondaryTokenIndex != invalidIndex ? tokens[group.secondaryTokenIndex].value : std::string_view{};

                auto parseAsFuncName = [type, &input, secondaryTokenValue, &primaryToken]()
                {
                    switch (type)
                    {
                    case coil::DefaultLexer::TokenType::Dot:
                        input.target = primaryToken.value;
                        input.name = secondaryTokenValue;
                        break;
                    case coil::DefaultLexer::TokenType::String:
                        input.name = primaryToken.value;;
                        break;
                    default:
                        // TODO report error
                        break;
                    }
                };

                auto parseAsArgument = [type, &input, secondaryTokenValue, &primaryToken]()
                {
                    if (type == TokenType::Assignment)
                        input.namedArguments.emplace(primaryToken.value, secondaryTokenValue);
                    else if (type == TokenType::String)
                        input.arguments.emplace_back(primaryToken.value);
                    else
                        ; // TODO report error
                };

                if (input.name.empty())
                    parseAsFuncName();
                else
                    parseAsArgument();
            }

            return input;
        }
    };
}
