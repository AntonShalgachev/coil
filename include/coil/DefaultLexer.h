#pragma once

#include "ExecutionInput.h"
#include "Expected.h"
#include "Lexer.h"
#include "Utils.h"
#include "String.h"
#include "StringView.h"
#include "Optional.h"
#include "Vector.h"
#include "detail/Algorithm.h"
#include "detail/Utility.h"

#include <ctype.h>

// TODO move implementation to cpp

namespace coil
{
    struct ExecutionInput;

    class DefaultLexer : public Lexer
    {
    public:
        DefaultLexer(StringView groupParenthesis = "()", StringView quotes = "'\"", StringView groupSeparators = ",;|")
            : m_groupParentheses(groupParenthesis), m_quotes(quotes), m_groupSeparators(groupSeparators)
        {
        }

        Expected<ExecutionInput, String> parse(StringView str) const override
        {
            auto tokens = tokenize(str);
            if (!tokens)
                return makeUnexpected(Move(tokens).error());

            return parse(*Move(tokens));
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
            Token(TokenType type, StringView value) : type(type), value(value) {}

            TokenType type = TokenType::String;
            StringView value;
        };

        static bool isSpace(unsigned char c)
        {
            return isspace(c);
        }

        bool isGroupChar(unsigned char c) const
        {
            return coil::find(m_groupParentheses.begin(), m_groupParentheses.end(), c) != m_groupParentheses.end();
        }

        bool isQuote(unsigned char c) const
        {
            return coil::find(m_quotes.begin(), m_quotes.end(), c) != m_quotes.end();
        }

        bool isGroupSeparator(unsigned char c) const
        {
            if (isSpace(c))
                return true;

            return coil::find(m_groupSeparators.begin(), m_groupSeparators.end(), c) != m_groupSeparators.end();
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

        static Optional<TokenType> convertToTokenType(CharType type)
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

        Vector<StringView> splitGroup(StringView str) const
        {
            Vector<StringView> result;

            for (size_t i = 0; i < str.length(); i++)
            {
                while ((i < str.length()) && isGroupSeparator(str[i]))
                    i++;

                if (i >= str.length())
                    break;

                size_t stringBegin = i;
                bool inQuotes = false;
                auto shouldSkipChar = [this](unsigned char c, bool inQuotes) { return inQuotes || !isGroupSeparator(c); };
                while ((i < str.length()) && shouldSkipChar(str[i], inQuotes))
                {
                    if (isQuote(str[i]))
                        inQuotes = !inQuotes;
                    i++;
                }

                size_t stringEnd = i;
                if (isQuote(str[stringBegin]) && isQuote(str[stringEnd - 1]))
                {
                    stringBegin++;
                    stringEnd--;
                }

                result.pushBack(str.substr(stringBegin, stringEnd - stringBegin));
            }

            return result;
        }

        Value createValue(Token const& token) const
        {
            if (token.type == TokenType::GroupString)
                return Value{ splitGroup(token.value) };

            return Value{ {token.value} };
        }

        coil::Expected<Vector<Token>, String> tokenize(StringView str) const
        {
            Vector<Token> tokens;

            for (size_t i = 0; i < str.length(); i++)
            {
                while ((i < str.length()) && getCharType(str[i]) == CharType::Space)
                    i++;

                if (i >= str.length())
                    break;

                size_t tokenBegin = i;
                switch (getCharType(str[i]))
                {
                case CharType::String:
                {
                    i++;
                    TokenType type = TokenType::String;
                    while ((i < str.length()) && getCharType(str[i]) == CharType::String)
                    {
                        if (isGroupSeparator(str[i]))
                            type = TokenType::GroupString;
                        i++;
                    }

                    tokens.pushBack(Token{ type, str.substr(tokenBegin, i - tokenBegin) });
                    i--; // return to the last 'String' char
                    break;
                }
                case CharType::Assignment:
                    tokens.pushBack(Token{ TokenType::Assignment, str.substr(i, 1) });
                    break;
                case CharType::Quote:
                    i++;
                    while ((i < str.length()) && getCharType(str[i]) != CharType::Quote)
                        i++;

                    if (i >= str.length())
                        return makeUnexpected(sprintf("Token '%c' doesn't have a corresponding opening/closing quote", str[tokenBegin]));

                    tokens.pushBack(Token{ TokenType::String, str.substr(tokenBegin + 1, i - tokenBegin - 1) });
                    break;
                case CharType::Group:
                    i++;
                    while ((i < str.length()) && getCharType(str[i]) != CharType::Group)
                        i++;

                    if (i >= str.length())
                        return makeUnexpected(sprintf("Token '%c' doesn't have a corresponding opening/closing token", str[tokenBegin]));

                    tokens.pushBack(Token{ TokenType::GroupString, str.substr(tokenBegin + 1, i - tokenBegin - 1) });
                    break;
                default:
                    return makeUnexpected("Internal error"); // @NOCOVERAGE
                }
            }

            return {Move(tokens)};
        }

        Expected<ExecutionInput, String> parse(Vector<Token> tokens) const
        {
            ExecutionInput input;

            if (tokens.empty())
                return input;

            Token const& firstToken = tokens.front();
            if (firstToken.type != TokenType::String)
                return makeUnexpected(sprintf("Unexpected token '%.*s' at the beginning of the expression", static_cast<int>(firstToken.value.length()), firstToken.value.data()));

            input.name = firstToken.value;

            struct ArgTokens
            {
                Optional<size_t> primaryTokenIndex;
                Optional<size_t> secondaryTokenIndex;

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
                    input.namedArguments.pushBack(NamedValue{ primaryToken.value, createValue(secondaryToken) });
                }
                else
                {
                    input.arguments.pushBack(createValue(primaryToken));
                }

                argTokens.reset();
            };

            for (size_t i = 1; i < tokens.size(); i++)
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

            return {Move(input)};
        }

    private:
        StringView m_groupParentheses;
        StringView m_quotes;
        StringView m_groupSeparators;
    };
}
