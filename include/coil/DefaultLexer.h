#pragma once

#include "DefaultLexer.h"
#include "ExecutionInput.h"
#include "Expected.h"
#include "Utils.h"

#include <cctype>
#include <optional>
#include <string_view>

namespace coil
{
    struct ExecutionInput;

    struct DefaultLexer
    {
    public:
        Expected<std::reference_wrapper<ExecutionInput>, std::string> operator()(std::string_view str) const
        {
            m_input.reset();
            m_tokens.clear();

            if (auto res = tokenize(str); !res)
                return makeUnexpected(std::move(res).error());

            if (auto res = parse(); !res)
                return makeUnexpected(std::move(res).error());

            return std::ref(m_input);
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

        static bool isGroupChar(unsigned char c)
        {
            // TODO make configurable?
            static std::vector<unsigned char> chars = {'(', ')'};
            return std::find(chars.begin(), chars.end(), c) != chars.end();
        }

        static bool isQuote(unsigned char c)
        {
            // TODO make configurable?
            static std::vector<unsigned char> quotes = {'\'', '"'};
            return std::find(quotes.begin(), quotes.end(), c) != quotes.end();
        }

        static bool isGroupSeparator(unsigned char c)
        {
            // TODO make configurable?
            static std::vector<unsigned char> chars = {',', ';', '|'};

            if (isSpace(c))
                return true;

            return std::find(chars.begin(), chars.end(), c) != chars.end();
        }

        static CharType getCharType(unsigned char c)
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
                auto shouldSkipChar = [](unsigned char c, bool inQuotes) { return inQuotes || !isGroupSeparator(c); };
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

        Value createAnyArg(Token const& token) const
        {
            if (token.type == TokenType::GroupString)
                return Value{splitGroup(token.value)};

            return Value{{token.value}};
        }

        coil::Expected<void, std::string> tokenize(std::string_view str) const
        {
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

                    m_tokens.emplace_back(type, str.substr(tokenBegin, i - tokenBegin));
                    i--; // return to the last 'String' char
                    break;
                }
                case CharType::Assignment:
                    m_tokens.emplace_back(TokenType::Assignment, str.substr(i, 1));
                    break;
                case CharType::Quote:
                    i++;
                    while ((i < str.size()) && getCharType(str[i]) != CharType::Quote)
                        i++;

                    if (i >= str.size())
                        return makeUnexpected(formatString("Token '%c' doesn't have a corresponding opening/closing quote", str[tokenBegin]));

                    m_tokens.emplace_back(TokenType::String, str.substr(tokenBegin + 1, i - tokenBegin - 1));
                    break;
                case CharType::Group:
                    i++;
                    while ((i < str.size()) && getCharType(str[i]) != CharType::Group)
                        i++;

                    if (i >= str.size())
                        return makeUnexpected(formatString("Token '%c' doesn't have a corresponding opening/closing token", str[tokenBegin]));

                    m_tokens.emplace_back(TokenType::GroupString, str.substr(tokenBegin + 1, i - tokenBegin - 1));
                    break;
                default:
                    return makeUnexpected("Internal error"); // @NOCOVERAGE
                }
            }

            return {};
        }

        Expected<void, std::string> parse() const
        {
            if (m_tokens.empty())
                return {};

            Token const& firstToken = m_tokens.front();
            if (firstToken.type != TokenType::String)
                return makeUnexpected(formatString("Unexpected token '%.*s' at the beginning of the expression", firstToken.value.size(), firstToken.value.data()));

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

                Token const& primaryToken = m_tokens[*tokens.primaryTokenIndex];
                if (tokens.secondaryTokenIndex)
                {
                    Token const& secondaryToken = m_tokens[*tokens.secondaryTokenIndex];
                    m_input.namedArguments.emplace_back(primaryToken.value, createAnyArg(secondaryToken));
                }
                else
                {
                    m_input.arguments.push_back(createAnyArg(primaryToken));
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
                        if (tokens.primaryTokenIndex)
                            addCurrentTokens();
                        tokens.primaryTokenIndex = i;
                        break;
                    case StringTokenType::SecondaryToken:
                        if (!tokens.primaryTokenIndex)
                            return makeUnexpected("Internal error"); // @NOCOVERAGE

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
