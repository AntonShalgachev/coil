#include "ClassWithBindings260.h"

void ClassWithBindings260::work()
{
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

    // To trigger some template instantiations
    std::unordered_map<std::string_view, std::map<double, float>> functors;
    functors.insert_or_assign("foo", std::map<double, float>{});
    auto& innerMap = functors["bar"];
    innerMap.insert_or_assign(3.14, 3.14f);
}

#if USE_COIL
void ClassWithBindings260::registerBindings(coil::Bindings& bindings)
{
    bindings["method0"] = coil::bind(&ClassWithBindings260::method0, this);
    bindings["method1"] = coil::bind(&ClassWithBindings260::method1, this);
    bindings["method2"] = coil::bind(&ClassWithBindings260::method2, this);

    bindings["memberVariable0"] = coil::variable(&memberVariable0);
    bindings["memberVariable1"] = coil::variable(&memberVariable1);
    bindings["memberVariable2"] = coil::variable(&memberVariable2);

    bindings["ClassWithBindings260_function0"] = [](coil::Context context, float arg0, bool arg1, bool arg2, int arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<float>("key");
        args.getOrReport<float>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings260::function0(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings260_function1"] = [](coil::Context context, short arg0, float arg1, bool arg2, int arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<short>("key");
        args.getOrReport<short>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings260::function1(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings260_function2"] = [](coil::Context context, bool arg0, unsigned arg1, float arg2, double arg3, float arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<bool>("key");
        args.getOrReport<bool>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings260::function2(arg0, arg1, arg2, arg3, arg4);
    };

    bindings["ClassWithBindings260_variable0"] = coil::variable(&ClassWithBindings260::variable0);
    bindings["ClassWithBindings260_variable1"] = coil::variable(&ClassWithBindings260::variable1);
    bindings["ClassWithBindings260_variable2"] = coil::variable(&ClassWithBindings260::variable2);
}
#endif

#if USE_MANUAL
void ClassWithBindings260::registerBindings(DumbBindings& bindings)
{
    bindings.registerCommand("ClassWithBindings260_method0", [this](auto const& args) { return method0Command(args); });
    bindings.registerCommand("ClassWithBindings260_method1", [this](auto const& args) { return method1Command(args); });
    bindings.registerCommand("ClassWithBindings260_method2", [this](auto const& args) { return method2Command(args); });

    bindings.registerCommand("ClassWithBindings260_memberVariable0", [this](auto const& args) { return memberVariable0Command(args); });
    bindings.registerCommand("ClassWithBindings260_memberVariable1", [this](auto const& args) { return memberVariable1Command(args); });
    bindings.registerCommand("ClassWithBindings260_memberVariable2", [this](auto const& args) { return memberVariable2Command(args); });

    bindings.registerCommand("ClassWithBindings260_function0", ClassWithBindings260::function0Command);
    bindings.registerCommand("ClassWithBindings260_function1", ClassWithBindings260::function1Command);
    bindings.registerCommand("ClassWithBindings260_function2", ClassWithBindings260::function2Command);

    bindings.registerCommand("ClassWithBindings260_variable0", ClassWithBindings260::variable0Command);
    bindings.registerCommand("ClassWithBindings260_variable1", ClassWithBindings260::variable1Command);
    bindings.registerCommand("ClassWithBindings260_variable2", ClassWithBindings260::variable2Command);
}
#endif

std::optional<float> ClassWithBindings260::workInternally(std::vector<std::string> const& values)
{
    float res = 0.0f;
    for (std::string const& s : values)
    {
        float value = 0.0f;
        std::stringstream ss{ s };
        if (!(ss >> value))
            return {};
        res += value;
    }

    std::stringstream ss;
    ss << res;

    std::string str = ss.str();

    float result = 0.0f;
    std::from_chars(str.data(), str.data() + str.size(), result);

    return result;
}

void ClassWithBindings260::method0(short arg0, float arg1, short arg2, float arg3, int arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

}
void ClassWithBindings260::method1(short arg0, int arg1, unsigned arg2, int arg3, bool arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

}
void ClassWithBindings260::method2(unsigned arg0, double arg1, short arg2, short arg3, int arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

}

void ClassWithBindings260::function0(float arg0, bool arg1, bool arg2, int arg3, short arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

}
short ClassWithBindings260::function1(short arg0, float arg1, bool arg2, int arg3, short arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

    return arg4;
}
void ClassWithBindings260::function2(bool arg0, unsigned arg1, float arg2, double arg3, float arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

}

////////////////////////////////////////////////////////////////////////////////////////////

#if USE_MANUAL

std::string ClassWithBindings260::method0Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 5)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    short arg0{};
    if (!tryConvert(arguments[0], arg0))
    {
        std::cout << "Failed to convert argument 0!" << std::endl;
        return {};
    }
    float arg1{};
    if (!tryConvert(arguments[1], arg1))
    {
        std::cout << "Failed to convert argument 1!" << std::endl;
        return {};
    }
    short arg2{};
    if (!tryConvert(arguments[2], arg2))
    {
        std::cout << "Failed to convert argument 2!" << std::endl;
        return {};
    }
    float arg3{};
    if (!tryConvert(arguments[3], arg3))
    {
        std::cout << "Failed to convert argument 3!" << std::endl;
        return {};
    }
    int arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    method0(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings260::method1Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 5)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    short arg0{};
    if (!tryConvert(arguments[0], arg0))
    {
        std::cout << "Failed to convert argument 0!" << std::endl;
        return {};
    }
    int arg1{};
    if (!tryConvert(arguments[1], arg1))
    {
        std::cout << "Failed to convert argument 1!" << std::endl;
        return {};
    }
    unsigned arg2{};
    if (!tryConvert(arguments[2], arg2))
    {
        std::cout << "Failed to convert argument 2!" << std::endl;
        return {};
    }
    int arg3{};
    if (!tryConvert(arguments[3], arg3))
    {
        std::cout << "Failed to convert argument 3!" << std::endl;
        return {};
    }
    bool arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    method1(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings260::method2Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 5)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    unsigned arg0{};
    if (!tryConvert(arguments[0], arg0))
    {
        std::cout << "Failed to convert argument 0!" << std::endl;
        return {};
    }
    double arg1{};
    if (!tryConvert(arguments[1], arg1))
    {
        std::cout << "Failed to convert argument 1!" << std::endl;
        return {};
    }
    short arg2{};
    if (!tryConvert(arguments[2], arg2))
    {
        std::cout << "Failed to convert argument 2!" << std::endl;
        return {};
    }
    short arg3{};
    if (!tryConvert(arguments[3], arg3))
    {
        std::cout << "Failed to convert argument 3!" << std::endl;
        return {};
    }
    int arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    method2(arg0, arg1, arg2, arg3, arg4);
    return {};
}

std::string ClassWithBindings260::memberVariable0Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() > 1)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    if (arguments.size() == 1)
    {
        double newValue;
        if (!tryConvert(arguments[0], newValue))
        {
            std::cout << "Failed to convert argument!" << std::endl;
            return {};
        }

        memberVariable0 = newValue;
    }

    return std::to_string(memberVariable0);
}
std::string ClassWithBindings260::memberVariable1Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() > 1)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    if (arguments.size() == 1)
    {
        float newValue;
        if (!tryConvert(arguments[0], newValue))
        {
            std::cout << "Failed to convert argument!" << std::endl;
            return {};
        }

        memberVariable1 = newValue;
    }

    return std::to_string(memberVariable1);
}
std::string ClassWithBindings260::memberVariable2Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() > 1)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    if (arguments.size() == 1)
    {
        float newValue;
        if (!tryConvert(arguments[0], newValue))
        {
            std::cout << "Failed to convert argument!" << std::endl;
            return {};
        }

        memberVariable2 = newValue;
    }

    return std::to_string(memberVariable2);
}

std::string ClassWithBindings260::function0Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 5)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    float arg0{};
    if (!tryConvert(arguments[0], arg0))
    {
        std::cout << "Failed to convert argument 0!" << std::endl;
        return {};
    }
    bool arg1{};
    if (!tryConvert(arguments[1], arg1))
    {
        std::cout << "Failed to convert argument 1!" << std::endl;
        return {};
    }
    bool arg2{};
    if (!tryConvert(arguments[2], arg2))
    {
        std::cout << "Failed to convert argument 2!" << std::endl;
        return {};
    }
    int arg3{};
    if (!tryConvert(arguments[3], arg3))
    {
        std::cout << "Failed to convert argument 3!" << std::endl;
        return {};
    }
    short arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    function0(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings260::function1Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 5)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    short arg0{};
    if (!tryConvert(arguments[0], arg0))
    {
        std::cout << "Failed to convert argument 0!" << std::endl;
        return {};
    }
    float arg1{};
    if (!tryConvert(arguments[1], arg1))
    {
        std::cout << "Failed to convert argument 1!" << std::endl;
        return {};
    }
    bool arg2{};
    if (!tryConvert(arguments[2], arg2))
    {
        std::cout << "Failed to convert argument 2!" << std::endl;
        return {};
    }
    int arg3{};
    if (!tryConvert(arguments[3], arg3))
    {
        std::cout << "Failed to convert argument 3!" << std::endl;
        return {};
    }
    short arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    auto returnValue = function1(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings260::function2Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 5)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    bool arg0{};
    if (!tryConvert(arguments[0], arg0))
    {
        std::cout << "Failed to convert argument 0!" << std::endl;
        return {};
    }
    unsigned arg1{};
    if (!tryConvert(arguments[1], arg1))
    {
        std::cout << "Failed to convert argument 1!" << std::endl;
        return {};
    }
    float arg2{};
    if (!tryConvert(arguments[2], arg2))
    {
        std::cout << "Failed to convert argument 2!" << std::endl;
        return {};
    }
    double arg3{};
    if (!tryConvert(arguments[3], arg3))
    {
        std::cout << "Failed to convert argument 3!" << std::endl;
        return {};
    }
    float arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    function2(arg0, arg1, arg2, arg3, arg4);
    return {};
}

std::string ClassWithBindings260::variable0Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() > 1)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    if (arguments.size() == 1)
    {
        double newValue;
        if (!tryConvert(arguments[0], newValue))
        {
            std::cout << "Failed to convert argument!" << std::endl;
            return {};
        }

        variable0 = newValue;
    }

    return std::to_string(variable0);
}
std::string ClassWithBindings260::variable1Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() > 1)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    if (arguments.size() == 1)
    {
        double newValue;
        if (!tryConvert(arguments[0], newValue))
        {
            std::cout << "Failed to convert argument!" << std::endl;
            return {};
        }

        variable1 = newValue;
    }

    return std::to_string(variable1);
}
std::string ClassWithBindings260::variable2Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() > 1)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    if (arguments.size() == 1)
    {
        float newValue;
        if (!tryConvert(arguments[0], newValue))
        {
            std::cout << "Failed to convert argument!" << std::endl;
            return {};
        }

        variable2 = newValue;
    }

    return std::to_string(variable2);
}

#endif
