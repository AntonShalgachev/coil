#pragma once

#include "ExecutionInput.h"
#include "Expected.h"
#include "Lexer.h"
#include "Utils.h"

#include <cctype>
#include <optional>
#include <string_view>

namespace coil
{
    struct ExecutionInput;

    class DefaultLexer : public Lexer
    {
    public:
        DefaultLexer(std::string_view groupParenthesis = "()", std::string_view quotes = "'\"", std::string_view groupSeparators = ",;|")
            : m_groupParentheses(groupParenthesis), m_quotes(quotes), m_groupSeparators(groupSeparators)
        {
        }

        Expected<ExecutionInput, std::string> parse(std::string_view str) const override
        {
            auto tokens = tokenize(str);
            if (!tokens)
                return makeUnexpected(std::move(tokens).error());

            return parse(*std::move(tokens));
        }

    private:
        enum class CharType
        {
            Group,
            Quote,
            Space,
            String,
            Assignment,
        };

        enum class TokenType
        {
            String,
            GroupString,
            Assignment,
        };

        struct Token
        {
            Token(TokenType type, std::string_view value) : type(type), value(value) {}

            TokenType type = TokenType::String;
            std::string_view value;
        };

        static bool isSpace(unsigned char c)
        {
            return std::isspace(c);
        }

        bool isGroupChar(unsigned char c) const
        {
            return std::find(m_groupParentheses.begin(), m_groupParentheses.end(), c) != m_groupParentheses.end();
        }

        bool isQuote(unsigned char c) const
        {
            return std::find(m_quotes.begin(), m_quotes.end(), c) != m_quotes.end();
        }

        bool isGroupSeparator(unsigned char c) const
        {
            if (isSpace(c))
                return true;

            return std::find(m_groupSeparators.begin(), m_groupSeparators.end(), c) != m_groupSeparators.end();
        }

        CharType getCharType(unsigned char c) const
        {
            if (c == '=')
                return CharType::Assignment;
            if (isSpace(c))
                return CharType::Space;
            if (isGroupChar(c))
                return CharType::Group;
            if (isQuote(c))
                return CharType::Quote;

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

        std::vector<std::string_view> splitGroup(std::string_view str) const
        {
            std::vector<std::string_view> result;

            for (std::size_t i = 0; i < str.size(); i++)
            {
                while ((i < str.size()) && isGroupSeparator(str[i]))
                    i++;

                if (i >= str.size())
                    break;

                std::size_t stringBegin = i;
                bool inQuotes = false;
                auto shouldSkipChar = [this](unsigned char c, bool inQuotes) { return inQuotes || !isGroupSeparator(c); };
                while ((i < str.size()) && shouldSkipChar(str[i], inQuotes))
                {
                    if (isQuote(str[i]))
                        inQuotes = !inQuotes;
                    i++;
                }

                std::size_t stringEnd = i;
                if (isQuote(str[stringBegin]) && isQuote(str[stringEnd - 1]))
                {
                    stringBegin++;
                    stringEnd--;
                }

                result.push_back(str.substr(stringBegin, stringEnd - stringBegin));
            }

            return result;
        }

        Value createValue(Token const& token) const
        {
            if (token.type == TokenType::GroupString)
                return Value{splitGroup(token.value)};

            return Value{{token.value}};
        }

        coil::Expected<std::vector<Token>, std::string> tokenize(std::string_view str) const
        {
            std::vector<Token> tokens;

            for (std::size_t i = 0; i < str.size(); i++)
            {
                while ((i < str.size()) && getCharType(str[i]) == CharType::Space)
                    i++;

                if (i >= str.size())
                    break;

                std::size_t tokenBegin = i;
                switch (getCharType(str[i]))
                {
                case CharType::String:
                {
                    i++;
                    TokenType type = TokenType::String;
                    while ((i < str.size()) && getCharType(str[i]) == CharType::String)
                    {
                        if (isGroupSeparator(str[i]))
                            type = TokenType::GroupString;
                        i++;
                    }

                    tokens.emplace_back(type, str.substr(tokenBegin, i - tokenBegin));
                    i--; // return to the last 'String' char
                    break;
                }
                case CharType::Assignment:
                    tokens.emplace_back(TokenType::Assignment, str.substr(i, 1));
                    break;
                case CharType::Quote:
                    i++;
                    while ((i < str.size()) && getCharType(str[i]) != CharType::Quote)
                        i++;

                    if (i >= str.size())
                        return makeUnexpected(formatString("Token '%c' doesn't have a corresponding opening/closing quote", str[tokenBegin]));

                    tokens.emplace_back(TokenType::String, str.substr(tokenBegin + 1, i - tokenBegin - 1));
                    break;
                case CharType::Group:
                    i++;
                    while ((i < str.size()) && getCharType(str[i]) != CharType::Group)
                        i++;

                    if (i >= str.size())
                        return makeUnexpected(formatString("Token '%c' doesn't have a corresponding opening/closing token", str[tokenBegin]));

                    tokens.emplace_back(TokenType::GroupString, str.substr(tokenBegin + 1, i - tokenBegin - 1));
                    break;
                default:
                    return makeUnexpected("Internal error"); // @NOCOVERAGE
                }
            }

            return {std::move(tokens)};
        }

        Expected<ExecutionInput, std::string> parse(std::vector<Token> tokens) const
        {
            ExecutionInput input;

            if (tokens.empty())
                return ExecutionInput{};

            Token const& firstToken = tokens.front();
            if (firstToken.type != TokenType::String)
                return makeUnexpected(formatString("Unexpected token '%.*s' at the beginning of the expression", firstToken.value.size(), firstToken.value.data()));

            input.name = firstToken.value;

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

            ArgTokens argTokens;
            StringTokenType nextTokenType = StringTokenType::PrimaryToken;

            auto addCurrentTokens = [this, &tokens, &input, &argTokens]() {
                if (!argTokens.primaryTokenIndex)
                    return;

                Token const& primaryToken = tokens[*argTokens.primaryTokenIndex];
                if (argTokens.secondaryTokenIndex)
                {
                    Token const& secondaryToken = tokens[*argTokens.secondaryTokenIndex];
                    input.namedArguments.emplace_back(primaryToken.value, createValue(secondaryToken));
                }
                else
                {
                    input.arguments.push_back(createValue(primaryToken));
                }

                argTokens.reset();
            };

            for (std::size_t i = 1; i < tokens.size(); i++)
            {
                Token const& token = tokens[i];

                switch (token.type)
                {
                case TokenType::Assignment:
                    if (!argTokens.primaryTokenIndex)
                        return makeUnexpected("Unexpected token '=': no name for the named argument is provided");
                    if (nextTokenType == StringTokenType::SecondaryToken)
                        return makeUnexpected("Expected an argument value, found '='");
                    nextTokenType = StringTokenType::SecondaryToken;
                    break;
                case TokenType::String:
                case TokenType::GroupString:
                    switch (nextTokenType)
                    {
                    case StringTokenType::PrimaryToken:
                        if (argTokens.primaryTokenIndex)
                            addCurrentTokens();
                        argTokens.primaryTokenIndex = i;
                        break;
                    case StringTokenType::SecondaryToken:
                        if (!argTokens.primaryTokenIndex)
                            return makeUnexpected("Internal error"); // @NOCOVERAGE

                        argTokens.secondaryTokenIndex = i;
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

            return {std::move(input)};
        }

    private:
        std::string_view m_groupParentheses;
        std::string_view m_quotes;
        std::string_view m_groupSeparators;
    };
}
