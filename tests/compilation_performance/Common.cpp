#include "Common.h"

#if USE_COIL

TEST_TEMPLATE(int);
TEST_TEMPLATE(short);
TEST_TEMPLATE(bool);
TEST_TEMPLATE(unsigned);
TEST_TEMPLATE(float);
TEST_TEMPLATE(double);

COIL_FUNCTION_ARGS_TEMPLATE(short, bool, double, float, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(bool, short, bool, short, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(bool, bool, double, double, double);
COIL_FUNCTION_ARGS_TEMPLATE(unsigned, unsigned, int, double, int);
COIL_FUNCTION_ARGS_TEMPLATE(int, int, unsigned, int, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(unsigned, short, int, unsigned, short);
COIL_FUNCTION_ARGS_TEMPLATE(unsigned, double, unsigned, int, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(int, float, bool, bool, bool);
COIL_FUNCTION_ARGS_TEMPLATE(int, float, int, float, bool);
COIL_FUNCTION_ARGS_TEMPLATE(bool, bool, float, unsigned, float);

COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, float, unsigned, int, double, float);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, int, short, unsigned, float, float);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, float, short, float, double, int);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, double, int, double, double, double);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, unsigned, int, unsigned, float, double);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, unsigned, int, short, float, bool);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, double, float, short, float, float);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, double, short, float, short, short);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, float, float, int, int, double);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, short, short, bool, int, float);

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
