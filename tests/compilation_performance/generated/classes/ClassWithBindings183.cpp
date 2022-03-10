#include "ClassWithBindings183.h"

void ClassWithBindings183::work()
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
void ClassWithBindings183::registerBindings(coil::Bindings& bindings)
{
    bindings["method0"] = coil::bind(&ClassWithBindings183::method0, this);
    bindings["method1"] = coil::bind(&ClassWithBindings183::method1, this);
    bindings["method2"] = coil::bind(&ClassWithBindings183::method2, this);

    bindings["memberVariable0"] = coil::variable(&memberVariable0);
    bindings["memberVariable1"] = coil::variable(&memberVariable1);
    bindings["memberVariable2"] = coil::variable(&memberVariable2);

    bindings["ClassWithBindings183_function0"] = [](coil::Context context, float arg0, bool arg1, float arg2, unsigned arg3, bool arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<float>("key");
        args.getOrReport<float>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings183::function0(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings183_function1"] = [](coil::Context context, int arg0, float arg1, double arg2, float arg3, double arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<int>("key");
        args.getOrReport<int>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings183::function1(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings183_function2"] = [](coil::Context context, short arg0, int arg1, int arg2, double arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<short>("key");
        args.getOrReport<short>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings183::function2(arg0, arg1, arg2, arg3, arg4);
    };

    bindings["ClassWithBindings183_variable0"] = coil::variable(&ClassWithBindings183::variable0);
    bindings["ClassWithBindings183_variable1"] = coil::variable(&ClassWithBindings183::variable1);
    bindings["ClassWithBindings183_variable2"] = coil::variable(&ClassWithBindings183::variable2);
}
#endif

#if USE_MANUAL
void ClassWithBindings183::registerBindings(DumbBindings& bindings)
{
    bindings.registerCommand("ClassWithBindings183_method0", [this](auto const& args) { return method0Command(args); });
    bindings.registerCommand("ClassWithBindings183_method1", [this](auto const& args) { return method1Command(args); });
    bindings.registerCommand("ClassWithBindings183_method2", [this](auto const& args) { return method2Command(args); });

    bindings.registerCommand("ClassWithBindings183_memberVariable0", [this](auto const& args) { return memberVariable0Command(args); });
    bindings.registerCommand("ClassWithBindings183_memberVariable1", [this](auto const& args) { return memberVariable1Command(args); });
    bindings.registerCommand("ClassWithBindings183_memberVariable2", [this](auto const& args) { return memberVariable2Command(args); });

    bindings.registerCommand("ClassWithBindings183_function0", ClassWithBindings183::function0Command);
    bindings.registerCommand("ClassWithBindings183_function1", ClassWithBindings183::function1Command);
    bindings.registerCommand("ClassWithBindings183_function2", ClassWithBindings183::function2Command);

    bindings.registerCommand("ClassWithBindings183_variable0", ClassWithBindings183::variable0Command);
    bindings.registerCommand("ClassWithBindings183_variable1", ClassWithBindings183::variable1Command);
    bindings.registerCommand("ClassWithBindings183_variable2", ClassWithBindings183::variable2Command);
}
#endif

std::optional<float> ClassWithBindings183::workInternally(std::vector<std::string> const& values)
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

int ClassWithBindings183::method0(int arg0, int arg1, unsigned arg2, unsigned arg3, unsigned arg4)
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

    return arg0;
}
void ClassWithBindings183::method1(float arg0, bool arg1, bool arg2, unsigned arg3, bool arg4)
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
void ClassWithBindings183::method2(double arg0, bool arg1, bool arg2, int arg3, int arg4)
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

void ClassWithBindings183::function0(float arg0, bool arg1, float arg2, unsigned arg3, bool arg4)
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
void ClassWithBindings183::function1(int arg0, float arg1, double arg2, float arg3, double arg4)
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
short ClassWithBindings183::function2(short arg0, int arg1, int arg2, double arg3, short arg4)
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

    return arg0;
}

////////////////////////////////////////////////////////////////////////////////////////////

#if USE_MANUAL

std::string ClassWithBindings183::method0Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 5)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    int arg0{};
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
    unsigned arg3{};
    if (!tryConvert(arguments[3], arg3))
    {
        std::cout << "Failed to convert argument 3!" << std::endl;
        return {};
    }
    unsigned arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    auto returnValue = method0(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings183::method1Command(std::vector<std::string> const& arguments)
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
    unsigned arg3{};
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
std::string ClassWithBindings183::method2Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 5)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    double arg0{};
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
    int arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    method2(arg0, arg1, arg2, arg3, arg4);
    return {};
}

std::string ClassWithBindings183::memberVariable0Command(std::vector<std::string> const& arguments)
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

        memberVariable0 = newValue;
    }

    return std::to_string(memberVariable0);
}
std::string ClassWithBindings183::memberVariable1Command(std::vector<std::string> const& arguments)
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
std::string ClassWithBindings183::memberVariable2Command(std::vector<std::string> const& arguments)
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

        memberVariable2 = newValue;
    }

    return std::to_string(memberVariable2);
}

std::string ClassWithBindings183::function0Command(std::vector<std::string> const& arguments)
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
    float arg2{};
    if (!tryConvert(arguments[2], arg2))
    {
        std::cout << "Failed to convert argument 2!" << std::endl;
        return {};
    }
    unsigned arg3{};
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

    function0(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings183::function1Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 5)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    int arg0{};
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
    double arg2{};
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
    double arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    function1(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings183::function2Command(std::vector<std::string> const& arguments)
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
    int arg2{};
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
    short arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    auto returnValue = function2(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}

std::string ClassWithBindings183::variable0Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() > 1)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    if (arguments.size() == 1)
    {
        bool newValue;
        if (!tryConvert(arguments[0], newValue))
        {
            std::cout << "Failed to convert argument!" << std::endl;
            return {};
        }

        variable0 = newValue;
    }

    return std::to_string(variable0);
}
std::string ClassWithBindings183::variable1Command(std::vector<std::string> const& arguments)
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

        variable1 = newValue;
    }

    return std::to_string(variable1);
}
std::string ClassWithBindings183::variable2Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() > 1)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    if (arguments.size() == 1)
    {
        int newValue;
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
