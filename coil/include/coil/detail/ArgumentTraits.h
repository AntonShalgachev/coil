#pragma once
#include "coil/Context.h"
#include "coil/NamedArgs.h"

namespace coil::detail
{
    template<typename T>
    struct IsExplicitTargetArgument : std::is_pointer<T> {};

    template<typename T>
    struct IsContextArgument : std::is_same<T, Context&> {};

    template<typename T>
    struct IsNamedArgsArgument : std::is_same<T, NamedArgs> {};

    template<typename T>
    struct IsUserArgument : std::negation<std::disjunction<IsExplicitTargetArgument<T>, IsContextArgument<T>, IsNamedArgsArgument<T>>> {};
}
