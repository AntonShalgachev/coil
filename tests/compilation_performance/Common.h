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
