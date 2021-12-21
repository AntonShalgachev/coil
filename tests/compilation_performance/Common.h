#pragma once

#if USE_SOL
#include "sol/sol.hpp"
#include "coil/utils/MemberFunctionFunctor.h"

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
#include "coil/Bindings.h"
#include "coil/utils/VariableWrapper.h"

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
#else
#define MANUAL_DEBUG_BINDINGS
#endif

#ifdef MANUAL_DEBUG_BINDINGS

#include <functional>

class DumbBindings
{
public:
    using CommandHandlerFunc = std::function<std::string(std::vector<std::string> const&)>;

    void registerCommand(std::string name, CommandHandlerFunc func);
    void unregisterCommand(std::string const& name);

    void execute(std::string line);

private:
    std::unordered_map<std::string, CommandHandlerFunc> m_commands;
};

bool equalCaseInsensitive(std::string_view a, std::string_view b);

template<typename T>
bool tryConvert(std::string const& arg, T& value)
{
    std::from_chars_result result = std::from_chars(arg.data(), arg.data() + arg.size(), value);
    return result.ptr == arg.data() + arg.size();
}

template<>
inline bool tryConvert<bool>(std::string const& arg, bool& value)
{
    if (arg == "1" || equalCaseInsensitive(arg, "true"))
    {
        value = true;
        return true;
    }
    if (arg == "0" || equalCaseInsensitive(arg, "false"))
    {
        value = false;
        return true;
    }

    return false;
}

#endif
