#include "coil/Bindings.h"
#include "sol/sol.hpp"

#if USE_SOL
using GeneralBindings = sol::state;
#else
using GeneralBindings = coil::Bindings;
#endif

template<typename T, typename AnyT>
void bind(coil::Bindings& bindings, AnyT&& any)
{
    bindings.bind<T>("", std::forward<AnyT>(any));
}

template<typename T, typename AnyT>
void bind(sol::state& bindings, AnyT&& any)
{
    auto userType = bindings.new_usertype<T>("");
    userType[""] = std::forward<AnyT>(any);
}
