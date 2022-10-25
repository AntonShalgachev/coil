#include "Common.h"

#if USE_COIL

#if HAS_ARGS_EXTERN_TEMPLATES
COIL_TYPE_SERIALIZER_TEMPLATE(short);
COIL_TYPE_SERIALIZER_TEMPLATE(int);
COIL_TYPE_SERIALIZER_TEMPLATE(unsigned);
COIL_TYPE_SERIALIZER_TEMPLATE(float);
COIL_TYPE_SERIALIZER_TEMPLATE(double);

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
COIL_FUNCTION_ARGS_TEMPLATE(int, int);
COIL_FUNCTION_ARGS_TEMPLATE(int, short);
COIL_FUNCTION_ARGS_TEMPLATE(int, bool);
COIL_FUNCTION_ARGS_TEMPLATE(int, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(int, float);
COIL_FUNCTION_ARGS_TEMPLATE(int, double);
COIL_FUNCTION_ARGS_TEMPLATE(short, int);
COIL_FUNCTION_ARGS_TEMPLATE(short, short);
COIL_FUNCTION_ARGS_TEMPLATE(short, bool);
COIL_FUNCTION_ARGS_TEMPLATE(short, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(short, float);
COIL_FUNCTION_ARGS_TEMPLATE(short, double);
COIL_FUNCTION_ARGS_TEMPLATE(bool, int);
COIL_FUNCTION_ARGS_TEMPLATE(bool, short);
COIL_FUNCTION_ARGS_TEMPLATE(bool, bool);
COIL_FUNCTION_ARGS_TEMPLATE(bool, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(bool, float);
COIL_FUNCTION_ARGS_TEMPLATE(bool, double);
COIL_FUNCTION_ARGS_TEMPLATE(unsigned, int);
COIL_FUNCTION_ARGS_TEMPLATE(unsigned, short);
COIL_FUNCTION_ARGS_TEMPLATE(unsigned, bool);
COIL_FUNCTION_ARGS_TEMPLATE(unsigned, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(unsigned, float);
COIL_FUNCTION_ARGS_TEMPLATE(unsigned, double);
COIL_FUNCTION_ARGS_TEMPLATE(float, int);
COIL_FUNCTION_ARGS_TEMPLATE(float, short);
COIL_FUNCTION_ARGS_TEMPLATE(float, bool);
COIL_FUNCTION_ARGS_TEMPLATE(float, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(float, float);
COIL_FUNCTION_ARGS_TEMPLATE(float, double);
COIL_FUNCTION_ARGS_TEMPLATE(double, int);
COIL_FUNCTION_ARGS_TEMPLATE(double, short);
COIL_FUNCTION_ARGS_TEMPLATE(double, bool);
COIL_FUNCTION_ARGS_TEMPLATE(double, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(double, float);
COIL_FUNCTION_ARGS_TEMPLATE(double, double);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, int);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, short);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, bool);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, float);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, double);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, int, int);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, int, short);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, int, bool);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, int, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, int, float);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, int, double);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, short, int);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, short, short);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, short, bool);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, short, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, short, float);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, short, double);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, bool, int);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, bool, short);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, bool, bool);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, bool, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, bool, float);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, bool, double);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, unsigned, int);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, unsigned, short);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, unsigned, bool);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, unsigned, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, unsigned, float);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, unsigned, double);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, float, int);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, float, short);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, float, bool);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, float, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, float, float);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, float, double);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, double, int);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, double, short);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, double, bool);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, double, unsigned);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, double, float);
COIL_FUNCTION_ARGS_TEMPLATE(coil::Context, double, double);
#endif

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
