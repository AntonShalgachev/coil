#pragma once

#include "ExecutionInput.h"
#include "Expected.h"

#include <string>
#include <string_view>

namespace coil
{
    class Lexer
    {
    public:
        virtual Expected<ExecutionInput, std::string> parse(std::string_view str) const = 0;
        virtual ~Lexer() = default;
    };
}
