#pragma once
#include "coil/Context.h"

namespace coil
{
    namespace detail
    {
        template<typename T>
        struct IsExplicitTargetArgument : std::is_pointer<T> {};

        template<typename T>
        struct IsContextArgument : std::is_same<T, Context&> {};

        template<typename T>
        struct IsUserArgument : std::negation<std::disjunction<IsExplicitTargetArgument<T>, IsContextArgument<T>>> {};
    }
}
