#pragma once

#include "ExecutionInput.h"
#include "Expected.h"
#include "String.h"
#include "StringView.h"

namespace coil
{
    class Lexer
    {
    public:
        virtual Expected<ExecutionInput, String> parse(StringView str) const = 0;
        virtual ~Lexer() = default;
    };
}
