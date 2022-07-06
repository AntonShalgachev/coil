#pragma once

#include "coil/Coil.h"

#include <charconv>
#include <functional>
#include <iostream>
#include <map>
#include <optional>
#include <random>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

#if USE_COIL
    #define TEST_EXTERN_TEMPLATE(T)       \
        COIL_VARIABLE_EXTERN_TEMPLATE(T); \
        COIL_ARGUMENT_EXTERN_TEMPLATE(T); \
        COIL_NAMED_ARGS_EXTERN_TEMPLATE(T)

    #define TEST_TEMPLATE(T)       \
        COIL_VARIABLE_TEMPLATE(T); \
        COIL_ARGUMENT_TEMPLATE(T); \
        COIL_NAMED_ARGS_TEMPLATE(T)
#endif

#if USE_COIL

COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(short);
COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(int);
COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(unsigned);
COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(float);
COIL_TYPE_SERIALIZER_EXTERN_TEMPLATE(double);

TEST_EXTERN_TEMPLATE(int);
TEST_EXTERN_TEMPLATE(short);
TEST_EXTERN_TEMPLATE(bool);
TEST_EXTERN_TEMPLATE(unsigned);
TEST_EXTERN_TEMPLATE(float);
TEST_EXTERN_TEMPLATE(double);

COIL_FUNCTION_ARGS_EXTERN_TEMPLATE();
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(int);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(short);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(int, int);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(int, short);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(int, bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(int, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(int, float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(int, double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(short, int);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(short, short);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(short, bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(short, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(short, float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(short, double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(bool, int);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(bool, short);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(bool, bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(bool, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(bool, float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(bool, double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(unsigned, int);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(unsigned, short);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(unsigned, bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(unsigned, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(unsigned, float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(unsigned, double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(float, int);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(float, short);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(float, bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(float, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(float, float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(float, double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(double, int);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(double, short);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(double, bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(double, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(double, float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(double, double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, int);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, short);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, int, int);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, int, short);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, int, bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, int, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, int, float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, int, double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, short, int);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, short, short);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, short, bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, short, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, short, float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, short, double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, bool, int);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, bool, short);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, bool, bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, bool, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, bool, float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, bool, double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, unsigned, int);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, unsigned, short);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, unsigned, bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, unsigned, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, unsigned, float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, unsigned, double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, float, int);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, float, short);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, float, bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, float, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, float, float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, float, double);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, double, int);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, double, short);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, double, bool);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, double, unsigned);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, double, float);
COIL_FUNCTION_ARGS_EXTERN_TEMPLATE(coil::Context, double, double);

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
