#include "Common.h"

#if USE_COIL

#if HAS_EXTERN_TEMPLATES
TEST_TEMPLATE(int);
TEST_TEMPLATE(short);
TEST_TEMPLATE(bool);
TEST_TEMPLATE(unsigned);
TEST_TEMPLATE(float);
TEST_TEMPLATE(double);

COIL_FUNCTION_ARGS_TEMPLATE();
COIL_FUNCTION_ARGS_TEMPLATE(int);
COIL_FUNCTION_ARGS_TEMPLATE(short);
COIL_FUNCTION_ARGS_TEMPLATE(bool);
COIL_FUNCTION_ARGS_TEMPLATE(unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(float);
COIL_FUNCTION_ARGS_TEMPLATE(double);

COIL_FUNCTION_ARGS_TEMPLATE(coil::Context);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, int);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, short);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, bool);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, float);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, double);
#endif // HAS_EXTERN_TEMPLATES

#endif

#ifdef USE_MANUAL
    #include <cctype>
#endif

#ifdef USE_MANUAL

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
    std::vector<std::string> arguments = {"arg1", "arg2", "arg3"};

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
