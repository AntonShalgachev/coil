#include "Common.h"

#if USE_COIL

COIL_TEMPLATE(int);
COIL_TEMPLATE(short);
COIL_TEMPLATE(bool);
COIL_TEMPLATE(unsigned);
COIL_TEMPLATE(float);
COIL_TEMPLATE(double);

COIL_TYPE_SERIALIZER_TEMPLATE(int);
COIL_TYPE_SERIALIZER_TEMPLATE(short);
// no bool
COIL_TYPE_SERIALIZER_TEMPLATE(unsigned);
COIL_TYPE_SERIALIZER_TEMPLATE(float);
COIL_TYPE_SERIALIZER_TEMPLATE(double);

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
