#pragma once

#include "coil/Bindings.h"
#include "coil/Variable.h"
#include "coil/Bind.h"

#include <functional>
#include <string_view>
#include <string>
#include <sstream>
#include <iostream>
#include <random>
#include <map>
#include <unordered_map>
#include <vector>
#include <optional>
#include <charconv>

#if USE_COIL

#include "coil/Extern.h"

extern template auto coil::variable<int>(int* var);
extern template auto coil::variable<short>(short* var);
extern template auto coil::variable<bool>(bool* var);
extern template auto coil::variable<unsigned>(unsigned* var);
extern template auto coil::variable<float>(float* var);
extern template auto coil::variable<double>(double* var);

EXTERN_EXPLICIT_TYPE_SERIALIZER_TEMPLATE(int);
EXTERN_EXPLICIT_TYPE_SERIALIZER_TEMPLATE(short);
EXTERN_EXPLICIT_TYPE_SERIALIZER_TEMPLATE(bool);
EXTERN_EXPLICIT_TYPE_SERIALIZER_TEMPLATE(unsigned);
EXTERN_EXPLICIT_TYPE_SERIALIZER_TEMPLATE(float);
EXTERN_EXPLICIT_TYPE_SERIALIZER_TEMPLATE(double);

EXTERN_EXPLICIT_NAMED_ARGS_TEMPLATE(int);
EXTERN_EXPLICIT_NAMED_ARGS_TEMPLATE(short);
EXTERN_EXPLICIT_NAMED_ARGS_TEMPLATE(bool);
EXTERN_EXPLICIT_NAMED_ARGS_TEMPLATE(unsigned);
EXTERN_EXPLICIT_NAMED_ARGS_TEMPLATE(float);
EXTERN_EXPLICIT_NAMED_ARGS_TEMPLATE(double);

EXTERN_EXPLICIT_FUNCTOR_CALLER_TEMPLATE(int);
EXTERN_EXPLICIT_FUNCTOR_CALLER_TEMPLATE(short);
EXTERN_EXPLICIT_FUNCTOR_CALLER_TEMPLATE(bool);
EXTERN_EXPLICIT_FUNCTOR_CALLER_TEMPLATE(unsigned);
EXTERN_EXPLICIT_FUNCTOR_CALLER_TEMPLATE(float);
EXTERN_EXPLICIT_FUNCTOR_CALLER_TEMPLATE(double);

#endif

#if USE_MANUAL

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
