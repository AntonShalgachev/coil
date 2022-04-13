#pragma once

#include "coil/Coil.h"

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

#define TEST_EXTERN_TEMPLATE(T) \
    COIL_VARIABLE_EXTERN_TEMPLATE(T); \
    COIL_ARGUMENT_EXTERN_TEMPLATE(T); \
    COIL_NAMED_ARGS_EXTERN_TEMPLATE(T)

#define TEST_TEMPLATE(T) \
    COIL_VARIABLE_TEMPLATE(T); \
    COIL_ARGUMENT_TEMPLATE(T); \
    COIL_NAMED_ARGS_TEMPLATE(T)

TEST_EXTERN_TEMPLATE(int);
TEST_EXTERN_TEMPLATE(short);
TEST_EXTERN_TEMPLATE(bool);
TEST_EXTERN_TEMPLATE(unsigned);
TEST_EXTERN_TEMPLATE(float);
TEST_EXTERN_TEMPLATE(double);

COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(short, bool, double, float, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(bool, short, bool, short, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(bool, bool, double, double, double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(unsigned, unsigned, int, double, int);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(int, int, unsigned, int, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(unsigned, short, int, unsigned, short);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(unsigned, double, unsigned, int, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(int, float, bool, bool, bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(int, float, int, float, bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(bool, bool, float, unsigned, float);

COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, float, unsigned, int, double, float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, int, short, unsigned, float, float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, float, short, float, double, int);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, double, int, double, double, double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, unsigned, int, unsigned, float, double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, unsigned, int, short, float, bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, double, float, short, float, float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, double, short, float, short, short);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, float, float, int, int, double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, short, short, bool, int, float);

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
