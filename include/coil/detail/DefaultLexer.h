#pragma once

#include "Lexer.h"
#include "String.h"
#include "StringView.h"

namespace coil
{
    struct ExecutionInput;
    struct Value;
    class StringView;

    template<typename T>
    class Vector;

    template<typename T, typename E>
    class Expected;

    class DefaultLexer : public Lexer
    {
    public:
        DefaultLexer(StringView groupParenthesis = "()", StringView quotes = "'\"", StringView groupSeparators = ",;|", StringView spaceCharacters = " \t\n\r");

        Expected<ExecutionInput, String> parse(StringView str) const override;

    private:
        enum class CharType;
        struct Token;

        bool isGroupChar(unsigned char c) const;
        bool isQuote(unsigned char c) const;
        bool isGroupSeparator(unsigned char c) const;
        bool isSpace(unsigned char c) const;
        CharType getCharType(unsigned char c) const;

        Vector<StringView> splitGroup(StringView str) const;
        Value createValue(Token const& token) const;

        coil::Expected<Vector<Token>, String> tokenize(StringView str) const;
        Expected<ExecutionInput, String> parse(Vector<Token> tokens) const;

    private:
        String m_groupParentheses;
        String m_quotes;
        String m_groupSeparators;
        String m_spaceCharacters;
    };
}
