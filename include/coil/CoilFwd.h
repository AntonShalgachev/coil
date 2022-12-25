#pragma once

namespace coil
{
    class Bindings;

    class Context;
    struct Value;
    struct ExecutionInput;
    struct ExecutionResult;

    template<typename T, typename>
    struct TypeName;

    template<typename T, typename>
    struct TypeSerializer;

    template<typename T, typename E>
    class Expected;

    class String;
    class StringView;
}
