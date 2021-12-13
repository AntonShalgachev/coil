#pragma once

#if USE_SOL

using GeneralBindings = sol::state;

template<typename T, typename AnyT>
void bind(sol::state& bindings, std::string_view name, AnyT&& any)
{
    auto userType = bindings.new_usertype<T>("");
    userType[name] = std::forward<AnyT>(any);
}

template<typename Func, typename ObjectPointerT>
void bind(sol::state& bindings, std::string_view name, Func&& func, ObjectPointerT obj)
{
    using ObjectT = std::remove_pointer_t<ObjectPointerT>;
    using ObjectReferenceT = std::add_lvalue_reference_t<ObjectT>;
    bindings[name] = coil::utils::MemberFunctionFunctor<Func, ObjectReferenceT>(std::forward<Func>(func), *obj);
}

#elif USE_COIL

using GeneralBindings = coil::Bindings;

template<typename T, typename AnyT>
void bind(coil::Bindings& bindings, std::string_view name, AnyT&& any)
{
    bindings.bind<T>(name, std::forward<AnyT>(any));
}

template<typename Func, typename ObjectPointerT>
void bind(coil::Bindings& bindings, std::string_view name, Func&& func, ObjectPointerT obj)
{
    bindings.bind(name, std::forward<Func>(func), obj);
}

#endif

#if defined(USE_SOL) || defined(USE_COIL)
#define DEBUG_BINDINGS
#endif
