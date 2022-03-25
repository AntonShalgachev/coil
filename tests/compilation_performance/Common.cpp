#include "Common.h"

#if USE_COIL

template auto coil::variable<int>(int* var);
template auto coil::variable<short>(short* var);
template auto coil::variable<bool>(bool* var);
template auto coil::variable<unsigned>(unsigned* var);
template auto coil::variable<float>(float* var);
template auto coil::variable<double>(double* var);

EXPLICIT_TYPE_SERIALIZER_TEMPLATE(int);
EXPLICIT_TYPE_SERIALIZER_TEMPLATE(short);
EXPLICIT_TYPE_SERIALIZER_TEMPLATE(bool);
EXPLICIT_TYPE_SERIALIZER_TEMPLATE(unsigned);
EXPLICIT_TYPE_SERIALIZER_TEMPLATE(float);
EXPLICIT_TYPE_SERIALIZER_TEMPLATE(double);

EXPLICIT_NAMED_ARGS_TEMPLATE(int);
EXPLICIT_NAMED_ARGS_TEMPLATE(short);
EXPLICIT_NAMED_ARGS_TEMPLATE(bool);
EXPLICIT_NAMED_ARGS_TEMPLATE(unsigned);
EXPLICIT_NAMED_ARGS_TEMPLATE(float);
EXPLICIT_NAMED_ARGS_TEMPLATE(double);

EXPLICIT_FUNCTOR_CALLER_TEMPLATE(int);
EXPLICIT_FUNCTOR_CALLER_TEMPLATE(short);
EXPLICIT_FUNCTOR_CALLER_TEMPLATE(bool);
EXPLICIT_FUNCTOR_CALLER_TEMPLATE(unsigned);
EXPLICIT_FUNCTOR_CALLER_TEMPLATE(float);
EXPLICIT_FUNCTOR_CALLER_TEMPLATE(double);

#endif

#ifdef USE_MANUAL

#include <cctype>

void DumbBindings::registerCommand(std::string name, CommandHandlerFunc func)
{
    m_commands.insert_or_assign(std::move(name), std::move(func));
}

void DumbBindings::unregisterCommand(std::string const& name)
{
    m_commands.erase(name);
}

void DumbBindings::execute(std::string)
{
    // we don't care about correctness for the compilation test
    std::string name = "func";
    std::vector<std::string> arguments = { "arg1", "arg2", "arg3" };

    if (auto it = m_commands.find(name); it != m_commands.end())
        std::cout << it->second(arguments) << std::endl;
}

bool equalCaseInsensitive(std::string_view a, std::string_view b)
{
    std::size_t const length = a.length();
    if (b.length() != length)
        return false;

    for (std::size_t i = 0; i < a.length(); i++)
        if (std::tolower(a[i]) != std::tolower(b[i]))
            return false;

    return true;
}

#endif
