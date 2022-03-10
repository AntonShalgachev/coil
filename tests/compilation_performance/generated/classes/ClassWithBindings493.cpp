#include "ClassWithBindings493.h"

void ClassWithBindings493::work()
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
void ClassWithBindings493::registerBindings(coil::Bindings& bindings)
{
    bindings["method0"] = coil::bind(&ClassWithBindings493::method0, this);
    bindings["method1"] = coil::bind(&ClassWithBindings493::method1, this);
    bindings["method2"] = coil::bind(&ClassWithBindings493::method2, this);

    bindings["memberVariable0"] = coil::variable(&memberVariable0);
    bindings["memberVariable1"] = coil::variable(&memberVariable1);
    bindings["memberVariable2"] = coil::variable(&memberVariable2);

    bindings["ClassWithBindings493_function0"] = [](coil::Context context, unsigned arg0, double arg1, short arg2, unsigned arg3, double arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<unsigned>("key");
        args.getOrReport<unsigned>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings493::function0(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings493_function1"] = [](coil::Context context, int arg0, unsigned arg1, short arg2, bool arg3, double arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<int>("key");
        args.getOrReport<int>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings493::function1(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings493_function2"] = [](coil::Context context, int arg0, int arg1, unsigned arg2, float arg3, double arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<int>("key");
        args.getOrReport<int>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings493::function2(arg0, arg1, arg2, arg3, arg4);
    };

    bindings["ClassWithBindings493_variable0"] = coil::variable(&ClassWithBindings493::variable0);
    bindings["ClassWithBindings493_variable1"] = coil::variable(&ClassWithBindings493::variable1);
    bindings["ClassWithBindings493_variable2"] = coil::variable(&ClassWithBindings493::variable2);
}
#endif

#if USE_MANUAL
void ClassWithBindings493::registerBindings(DumbBindings& bindings)
{
    bindings.registerCommand("ClassWithBindings493_method0", [this](auto const& args) { return method0Command(args); });
    bindings.registerCommand("ClassWithBindings493_method1", [this](auto const& args) { return method1Command(args); });
    bindings.registerCommand("ClassWithBindings493_method2", [this](auto const& args) { return method2Command(args); });

    bindings.registerCommand("ClassWithBindings493_memberVariable0", [this](auto const& args) { return memberVariable0Command(args); });
    bindings.registerCommand("ClassWithBindings493_memberVariable1", [this](auto const& args) { return memberVariable1Command(args); });
    bindings.registerCommand("ClassWithBindings493_memberVariable2", [this](auto const& args) { return memberVariable2Command(args); });

    bindings.registerCommand("ClassWithBindings493_function0", ClassWithBindings493::function0Command);
    bindings.registerCommand("ClassWithBindings493_function1", ClassWithBindings493::function1Command);
    bindings.registerCommand("ClassWithBindings493_function2", ClassWithBindings493::function2Command);

    bindings.registerCommand("ClassWithBindings493_variable0", ClassWithBindings493::variable0Command);
    bindings.registerCommand("ClassWithBindings493_variable1", ClassWithBindings493::variable1Command);
    bindings.registerCommand("ClassWithBindings493_variable2", ClassWithBindings493::variable2Command);
}
#endif

std::optional<float> ClassWithBindings493::workInternally(std::vector<std::string> const& values)
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

unsigned ClassWithBindings493::method0(bool arg0, bool arg1, unsigned arg2, short arg3, float arg4)
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

    return arg2;
}
void ClassWithBindings493::method1(short arg0, short arg1, bool arg2, short arg3, double arg4)
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
short ClassWithBindings493::method2(int arg0, bool arg1, short arg2, short arg3, double arg4)
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

    return arg2;
}

double ClassWithBindings493::function0(unsigned arg0, double arg1, short arg2, unsigned arg3, double arg4)
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
unsigned ClassWithBindings493::function1(int arg0, unsigned arg1, short arg2, bool arg3, double arg4)
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

    return arg1;
}
int ClassWithBindings493::function2(int arg0, int arg1, unsigned arg2, float arg3, double arg4)
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

std::string ClassWithBindings493::method0Command(std::vector<std::string> const& arguments)
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
    bool arg1{};
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
    short arg3{};
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

    auto returnValue = method0(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings493::method1Command(std::vector<std::string> const& arguments)
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
    short arg1{};
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
    short arg3{};
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

    method1(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings493::method2Command(std::vector<std::string> const& arguments)
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
    bool arg1{};
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
    double arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    auto returnValue = method2(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}

std::string ClassWithBindings493::memberVariable0Command(std::vector<std::string> const& arguments)
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

        memberVariable0 = newValue;
    }

    return std::to_string(memberVariable0);
}
std::string ClassWithBindings493::memberVariable1Command(std::vector<std::string> const& arguments)
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
std::string ClassWithBindings493::memberVariable2Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() > 1)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    if (arguments.size() == 1)
    {
        unsigned newValue;
        if (!tryConvert(arguments[0], newValue))
        {
            std::cout << "Failed to convert argument!" << std::endl;
            return {};
        }

        memberVariable2 = newValue;
    }

    return std::to_string(memberVariable2);
}

std::string ClassWithBindings493::function0Command(std::vector<std::string> const& arguments)
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
    unsigned arg3{};
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

    auto returnValue = function0(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings493::function1Command(std::vector<std::string> const& arguments)
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
    unsigned arg1{};
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
    bool arg3{};
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

    auto returnValue = function1(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings493::function2Command(std::vector<std::string> const& arguments)
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

    auto returnValue = function2(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}

std::string ClassWithBindings493::variable0Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() > 1)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }

    if (arguments.size() == 1)
    {
        short newValue;
        if (!tryConvert(arguments[0], newValue))
        {
            std::cout << "Failed to convert argument!" << std::endl;
            return {};
        }

        variable0 = newValue;
    }

    return std::to_string(variable0);
}
std::string ClassWithBindings493::variable1Command(std::vector<std::string> const& arguments)
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
std::string ClassWithBindings493::variable2Command(std::vector<std::string> const& arguments)
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

        variable2 = newValue;
    }

    return std::to_string(variable2);
}

#endif
