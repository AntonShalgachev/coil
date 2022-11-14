#pragma once

namespace coil
{
    struct ExecutionInput;
    class String;
    class StringView;

    template<typename T, typename E>
    class Expected;

    class Lexer
    {
    public:
        virtual Expected<ExecutionInput, String> parse(StringView str) const = 0;
        virtual ~Lexer() = default;
    };
}
