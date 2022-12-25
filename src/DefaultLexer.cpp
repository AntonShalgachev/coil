#include "coil/detail/DefaultLexer.h"

#include "coil/detail/Extern.h"

#include "coil/detail/Algorithm.h"
#include "coil/detail/ExecutionInput.h"
#include "coil/detail/Expected.h"
#include "coil/detail/Optional.h"
#include "coil/detail/Utility.h"
#include "coil/detail/Utils.h"
#include "coil/detail/Vector.h"

namespace
{
    enum class TokenType
    {
        String,
        GroupString,
        Assignment,
    };
}

enum class coil::DefaultLexer::CharType
{
    Group,
    Quote,
    Space,
    String,
    Assignment,
};

struct coil::DefaultLexer::Token
{
    Token(TokenType type, StringView value) : type(type), value(value) {}

    TokenType type = TokenType::String;
    StringView value;
};

coil::DefaultLexer::DefaultLexer(StringView groupParenthesis, StringView quotes, StringView groupSeparators, StringView spaceCharacters)
    : m_groupParentheses(groupParenthesis), m_quotes(quotes), m_groupSeparators(groupSeparators), m_spaceCharacters(spaceCharacters)
{
}

coil::Expected<coil::ExecutionInput, coil::String> coil::DefaultLexer::parse(StringView str) const
{
    auto tokens = tokenize(str);
    if (!tokens)
        return makeUnexpected(coil::move(tokens).error());

    return parse(*coil::move(tokens));
}

bool coil::DefaultLexer::isGroupChar(unsigned char c) const
{
    return coil::find(m_groupParentheses.begin(), m_groupParentheses.end(), c) != m_groupParentheses.end();
}

bool coil::DefaultLexer::isQuote(unsigned char c) const
{
    return coil::find(m_quotes.begin(), m_quotes.end(), c) != m_quotes.end();
}

bool coil::DefaultLexer::isGroupSeparator(unsigned char c) const
{
    if (isSpace(c))
        return true;

    return coil::find(m_groupSeparators.begin(), m_groupSeparators.end(), c) != m_groupSeparators.end();
}

bool coil::DefaultLexer::isSpace(unsigned char c) const
{
    return coil::find(m_spaceCharacters.begin(), m_spaceCharacters.end(), c) != m_spaceCharacters.end();
}

coil::DefaultLexer::CharType coil::DefaultLexer::getCharType(unsigned char c) const
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

coil::Vector<coil::StringView> coil::DefaultLexer::splitGroup(StringView str) const
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

coil::Value coil::DefaultLexer::createValue(Token const& token) const
{
    if (token.type == TokenType::GroupString)
        return Value{splitGroup(token.value)};

    return Value{{token.value}};
}

coil::Expected<coil::Vector<coil::DefaultLexer::Token>, coil::String> coil::DefaultLexer::tokenize(StringView str) const
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

            tokens.pushBack(Token{type, str.substr(tokenBegin, i - tokenBegin)});
            i--; // return to the last 'String' char
            break;
        }
        case CharType::Assignment:
            tokens.pushBack(Token{TokenType::Assignment, str.substr(i, 1)});
            break;
        case CharType::Quote:
            i++;
            while ((i < str.length()) && getCharType(str[i]) != CharType::Quote)
                i++;

            if (i >= str.length())
                return makeUnexpected(sprintf("Token '%c' doesn't have a corresponding opening/closing quote", str[tokenBegin]));

            tokens.pushBack(Token{TokenType::String, str.substr(tokenBegin + 1, i - tokenBegin - 1)});
            break;
        case CharType::Group:
            i++;
            while ((i < str.length()) && getCharType(str[i]) != CharType::Group)
                i++;

            if (i >= str.length())
                return makeUnexpected(sprintf("Token '%c' doesn't have a corresponding opening/closing token", str[tokenBegin]));

            tokens.pushBack(Token{TokenType::GroupString, str.substr(tokenBegin + 1, i - tokenBegin - 1)});
            break;
        default:
            return makeUnexpected("Internal error"); // @NOCOVERAGE
        }
    }

    return {coil::move(tokens)};
}

coil::Expected<coil::ExecutionInput, coil::String> coil::DefaultLexer::parse(Vector<Token> tokens) const
{
    ExecutionInput input;

    if (tokens.empty())
        return {coil::move(input)};

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
            input.namedArguments.pushBack(NamedValue{primaryToken.value, createValue(secondaryToken)});
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

    return {coil::move(input)};
}
