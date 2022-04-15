#include "ClassWithBindings139.h"

void ClassWithBindings139::work()
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
void ClassWithBindings139::registerBindings(coil::Bindings& bindings)
{
    bindings["method0"] = coil::bind(&ClassWithBindings139::method0, this);
    bindings["method1"] = coil::bind(&ClassWithBindings139::method1, this);
    bindings["method2"] = coil::bind(&ClassWithBindings139::method2, this);
    bindings["method3"] = coil::bind(&ClassWithBindings139::method3, this);
    bindings["method4"] = coil::bind(&ClassWithBindings139::method4, this);
    bindings["method5"] = coil::bind(&ClassWithBindings139::method5, this);
    bindings["method6"] = coil::bind(&ClassWithBindings139::method6, this);
    bindings["method7"] = coil::bind(&ClassWithBindings139::method7, this);
    bindings["method8"] = coil::bind(&ClassWithBindings139::method8, this);
    bindings["method9"] = coil::bind(&ClassWithBindings139::method9, this);
    bindings["method10"] = coil::bind(&ClassWithBindings139::method10, this);
    bindings["method11"] = coil::bind(&ClassWithBindings139::method11, this);

    bindings["memberVariable0"] = coil::variable(&memberVariable0);
    bindings["memberVariable1"] = coil::variable(&memberVariable1);
    bindings["memberVariable2"] = coil::variable(&memberVariable2);
    bindings["memberVariable3"] = coil::variable(&memberVariable3);
    bindings["memberVariable4"] = coil::variable(&memberVariable4);
    bindings["memberVariable5"] = coil::variable(&memberVariable5);
    bindings["memberVariable6"] = coil::variable(&memberVariable6);
    bindings["memberVariable7"] = coil::variable(&memberVariable7);
    bindings["memberVariable8"] = coil::variable(&memberVariable8);
    bindings["memberVariable9"] = coil::variable(&memberVariable9);

    bindings["ClassWithBindings139_function0"] = [](coil::Context context)
    {
        context.reportError("Task failed successfully");
        auto args = context.namedArgs();
        args.get("key");
        return ClassWithBindings139::function0();
    };
    bindings["ClassWithBindings139_function1"] = [](coil::Context context)
    {
        context.reportError("Task failed successfully");
        auto args = context.namedArgs();
        args.get("key");
        return ClassWithBindings139::function1();
    };
    bindings["ClassWithBindings139_function2"] = [](coil::Context context)
    {
        context.reportError("Task failed successfully");
        auto args = context.namedArgs();
        args.get("key");
        return ClassWithBindings139::function2();
    };
    bindings["ClassWithBindings139_function3"] = [](coil::Context context)
    {
        context.reportError("Task failed successfully");
        auto args = context.namedArgs();
        args.get("key");
        return ClassWithBindings139::function3();
    };
    bindings["ClassWithBindings139_function4"] = [](coil::Context context, float arg0)
    {
        context.reportError("Task failed successfully");
        auto args = context.namedArgs();
        args.get("key");
        args.get<float>("key");
        args.getOrReport<float>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings139::function4(arg0);
    };
    bindings["ClassWithBindings139_function5"] = [](coil::Context context, int arg0)
    {
        context.reportError("Task failed successfully");
        auto args = context.namedArgs();
        args.get("key");
        args.get<int>("key");
        args.getOrReport<int>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings139::function5(arg0);
    };
    bindings["ClassWithBindings139_function6"] = [](coil::Context context, double arg0)
    {
        context.reportError("Task failed successfully");
        auto args = context.namedArgs();
        args.get("key");
        args.get<double>("key");
        args.getOrReport<double>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings139::function6(arg0);
    };
    bindings["ClassWithBindings139_function7"] = [](coil::Context context, int arg0)
    {
        context.reportError("Task failed successfully");
        auto args = context.namedArgs();
        args.get("key");
        args.get<int>("key");
        args.getOrReport<int>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings139::function7(arg0);
    };
    bindings["ClassWithBindings139_function8"] = [](coil::Context context, short arg0, int arg1)
    {
        context.reportError("Task failed successfully");
        auto args = context.namedArgs();
        args.get("key");
        args.get<short>("key");
        args.getOrReport<short>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings139::function8(arg0, arg1);
    };
    bindings["ClassWithBindings139_function9"] = [](coil::Context context, int arg0, double arg1)
    {
        context.reportError("Task failed successfully");
        auto args = context.namedArgs();
        args.get("key");
        args.get<int>("key");
        args.getOrReport<int>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings139::function9(arg0, arg1);
    };
    bindings["ClassWithBindings139_function10"] = [](coil::Context context, double arg0, int arg1)
    {
        context.reportError("Task failed successfully");
        auto args = context.namedArgs();
        args.get("key");
        args.get<double>("key");
        args.getOrReport<double>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings139::function10(arg0, arg1);
    };
    bindings["ClassWithBindings139_function11"] = [](coil::Context context, double arg0, int arg1)
    {
        context.reportError("Task failed successfully");
        auto args = context.namedArgs();
        args.get("key");
        args.get<double>("key");
        args.getOrReport<double>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings139::function11(arg0, arg1);
    };

    bindings["ClassWithBindings139_variable0"] = coil::variable(&ClassWithBindings139::variable0);
    bindings["ClassWithBindings139_variable1"] = coil::variable(&ClassWithBindings139::variable1);
    bindings["ClassWithBindings139_variable2"] = coil::variable(&ClassWithBindings139::variable2);
    bindings["ClassWithBindings139_variable3"] = coil::variable(&ClassWithBindings139::variable3);
    bindings["ClassWithBindings139_variable4"] = coil::variable(&ClassWithBindings139::variable4);
    bindings["ClassWithBindings139_variable5"] = coil::variable(&ClassWithBindings139::variable5);
    bindings["ClassWithBindings139_variable6"] = coil::variable(&ClassWithBindings139::variable6);
    bindings["ClassWithBindings139_variable7"] = coil::variable(&ClassWithBindings139::variable7);
    bindings["ClassWithBindings139_variable8"] = coil::variable(&ClassWithBindings139::variable8);
    bindings["ClassWithBindings139_variable9"] = coil::variable(&ClassWithBindings139::variable9);
}
#endif

#if USE_MANUAL
void ClassWithBindings139::registerBindings(DumbBindings& bindings)
{
    bindings.registerCommand("ClassWithBindings139_method0", [this](auto const& args) { return method0Command(args); });
    bindings.registerCommand("ClassWithBindings139_method1", [this](auto const& args) { return method1Command(args); });
    bindings.registerCommand("ClassWithBindings139_method2", [this](auto const& args) { return method2Command(args); });
    bindings.registerCommand("ClassWithBindings139_method3", [this](auto const& args) { return method3Command(args); });
    bindings.registerCommand("ClassWithBindings139_method4", [this](auto const& args) { return method4Command(args); });
    bindings.registerCommand("ClassWithBindings139_method5", [this](auto const& args) { return method5Command(args); });
    bindings.registerCommand("ClassWithBindings139_method6", [this](auto const& args) { return method6Command(args); });
    bindings.registerCommand("ClassWithBindings139_method7", [this](auto const& args) { return method7Command(args); });
    bindings.registerCommand("ClassWithBindings139_method8", [this](auto const& args) { return method8Command(args); });
    bindings.registerCommand("ClassWithBindings139_method9", [this](auto const& args) { return method9Command(args); });
    bindings.registerCommand("ClassWithBindings139_method10", [this](auto const& args) { return method10Command(args); });
    bindings.registerCommand("ClassWithBindings139_method11", [this](auto const& args) { return method11Command(args); });

    bindings.registerCommand("ClassWithBindings139_memberVariable0", [this](auto const& args) { return memberVariable0Command(args); });
    bindings.registerCommand("ClassWithBindings139_memberVariable1", [this](auto const& args) { return memberVariable1Command(args); });
    bindings.registerCommand("ClassWithBindings139_memberVariable2", [this](auto const& args) { return memberVariable2Command(args); });
    bindings.registerCommand("ClassWithBindings139_memberVariable3", [this](auto const& args) { return memberVariable3Command(args); });
    bindings.registerCommand("ClassWithBindings139_memberVariable4", [this](auto const& args) { return memberVariable4Command(args); });
    bindings.registerCommand("ClassWithBindings139_memberVariable5", [this](auto const& args) { return memberVariable5Command(args); });
    bindings.registerCommand("ClassWithBindings139_memberVariable6", [this](auto const& args) { return memberVariable6Command(args); });
    bindings.registerCommand("ClassWithBindings139_memberVariable7", [this](auto const& args) { return memberVariable7Command(args); });
    bindings.registerCommand("ClassWithBindings139_memberVariable8", [this](auto const& args) { return memberVariable8Command(args); });
    bindings.registerCommand("ClassWithBindings139_memberVariable9", [this](auto const& args) { return memberVariable9Command(args); });

    bindings.registerCommand("ClassWithBindings139_function0", ClassWithBindings139::function0Command);
    bindings.registerCommand("ClassWithBindings139_function1", ClassWithBindings139::function1Command);
    bindings.registerCommand("ClassWithBindings139_function2", ClassWithBindings139::function2Command);
    bindings.registerCommand("ClassWithBindings139_function3", ClassWithBindings139::function3Command);
    bindings.registerCommand("ClassWithBindings139_function4", ClassWithBindings139::function4Command);
    bindings.registerCommand("ClassWithBindings139_function5", ClassWithBindings139::function5Command);
    bindings.registerCommand("ClassWithBindings139_function6", ClassWithBindings139::function6Command);
    bindings.registerCommand("ClassWithBindings139_function7", ClassWithBindings139::function7Command);
    bindings.registerCommand("ClassWithBindings139_function8", ClassWithBindings139::function8Command);
    bindings.registerCommand("ClassWithBindings139_function9", ClassWithBindings139::function9Command);
    bindings.registerCommand("ClassWithBindings139_function10", ClassWithBindings139::function10Command);
    bindings.registerCommand("ClassWithBindings139_function11", ClassWithBindings139::function11Command);

    bindings.registerCommand("ClassWithBindings139_variable0", ClassWithBindings139::variable0Command);
    bindings.registerCommand("ClassWithBindings139_variable1", ClassWithBindings139::variable1Command);
    bindings.registerCommand("ClassWithBindings139_variable2", ClassWithBindings139::variable2Command);
    bindings.registerCommand("ClassWithBindings139_variable3", ClassWithBindings139::variable3Command);
    bindings.registerCommand("ClassWithBindings139_variable4", ClassWithBindings139::variable4Command);
    bindings.registerCommand("ClassWithBindings139_variable5", ClassWithBindings139::variable5Command);
    bindings.registerCommand("ClassWithBindings139_variable6", ClassWithBindings139::variable6Command);
    bindings.registerCommand("ClassWithBindings139_variable7", ClassWithBindings139::variable7Command);
    bindings.registerCommand("ClassWithBindings139_variable8", ClassWithBindings139::variable8Command);
    bindings.registerCommand("ClassWithBindings139_variable9", ClassWithBindings139::variable9Command);
}
#endif

std::optional<float> ClassWithBindings139::workInternally(std::vector<std::string> const& values)
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

void ClassWithBindings139::method0()
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

}
void ClassWithBindings139::method1()
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

}
void ClassWithBindings139::method2()
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

}
void ClassWithBindings139::method3()
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

}
short ClassWithBindings139::method4(short arg0)
{
    std::cout << arg0;
    
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
void ClassWithBindings139::method5(double arg0)
{
    std::cout << arg0;
    
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
void ClassWithBindings139::method6(short arg0)
{
    std::cout << arg0;
    
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
double ClassWithBindings139::method7(double arg0)
{
    std::cout << arg0;
    
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
short ClassWithBindings139::method8(short arg0, unsigned arg1)
{
    std::cout << arg0 << arg1;
    
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
void ClassWithBindings139::method9(bool arg0, bool arg1)
{
    std::cout << arg0 << arg1;
    
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
void ClassWithBindings139::method10(bool arg0, unsigned arg1)
{
    std::cout << arg0 << arg1;
    
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
void ClassWithBindings139::method11(int arg0, float arg1)
{
    std::cout << arg0 << arg1;
    
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

void ClassWithBindings139::function0()
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

}
void ClassWithBindings139::function1()
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

}
void ClassWithBindings139::function2()
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

}
void ClassWithBindings139::function3()
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

}
float ClassWithBindings139::function4(float arg0)
{
    std::cout << arg0;
    
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
void ClassWithBindings139::function5(int arg0)
{
    std::cout << arg0;
    
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
double ClassWithBindings139::function6(double arg0)
{
    std::cout << arg0;
    
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
int ClassWithBindings139::function7(int arg0)
{
    std::cout << arg0;
    
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
void ClassWithBindings139::function8(short arg0, int arg1)
{
    std::cout << arg0 << arg1;
    
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
void ClassWithBindings139::function9(int arg0, double arg1)
{
    std::cout << arg0 << arg1;
    
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
void ClassWithBindings139::function10(double arg0, int arg1)
{
    std::cout << arg0 << arg1;
    
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
void ClassWithBindings139::function11(double arg0, int arg1)
{
    std::cout << arg0 << arg1;
    
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

std::string ClassWithBindings139::method0Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 0)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }


    method0();
    return {};
}
std::string ClassWithBindings139::method1Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 0)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }


    method1();
    return {};
}
std::string ClassWithBindings139::method2Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 0)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }


    method2();
    return {};
}
std::string ClassWithBindings139::method3Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 0)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }


    method3();
    return {};
}
std::string ClassWithBindings139::method4Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 1)
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

    auto returnValue = method4(arg0);
    return std::to_string(returnValue);
}
std::string ClassWithBindings139::method5Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 1)
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

    method5(arg0);
    return {};
}
std::string ClassWithBindings139::method6Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 1)
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

    method6(arg0);
    return {};
}
std::string ClassWithBindings139::method7Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 1)
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

    auto returnValue = method7(arg0);
    return std::to_string(returnValue);
}
std::string ClassWithBindings139::method8Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 2)
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
    unsigned arg1{};
    if (!tryConvert(arguments[1], arg1))
    {
        std::cout << "Failed to convert argument 1!" << std::endl;
        return {};
    }

    auto returnValue = method8(arg0, arg1);
    return std::to_string(returnValue);
}
std::string ClassWithBindings139::method9Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 2)
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

    method9(arg0, arg1);
    return {};
}
std::string ClassWithBindings139::method10Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 2)
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

    method10(arg0, arg1);
    return {};
}
std::string ClassWithBindings139::method11Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 2)
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

    method11(arg0, arg1);
    return {};
}

std::string ClassWithBindings139::memberVariable0Command(std::vector<std::string> const& arguments)
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

        memberVariable0 = newValue;
    }

    return std::to_string(memberVariable0);
}
std::string ClassWithBindings139::memberVariable1Command(std::vector<std::string> const& arguments)
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

        memberVariable1 = newValue;
    }

    return std::to_string(memberVariable1);
}
std::string ClassWithBindings139::memberVariable2Command(std::vector<std::string> const& arguments)
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

        memberVariable2 = newValue;
    }

    return std::to_string(memberVariable2);
}
std::string ClassWithBindings139::memberVariable3Command(std::vector<std::string> const& arguments)
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

        memberVariable3 = newValue;
    }

    return std::to_string(memberVariable3);
}
std::string ClassWithBindings139::memberVariable4Command(std::vector<std::string> const& arguments)
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

        memberVariable4 = newValue;
    }

    return std::to_string(memberVariable4);
}
std::string ClassWithBindings139::memberVariable5Command(std::vector<std::string> const& arguments)
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

        memberVariable5 = newValue;
    }

    return std::to_string(memberVariable5);
}
std::string ClassWithBindings139::memberVariable6Command(std::vector<std::string> const& arguments)
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

        memberVariable6 = newValue;
    }

    return std::to_string(memberVariable6);
}
std::string ClassWithBindings139::memberVariable7Command(std::vector<std::string> const& arguments)
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

        memberVariable7 = newValue;
    }

    return std::to_string(memberVariable7);
}
std::string ClassWithBindings139::memberVariable8Command(std::vector<std::string> const& arguments)
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

        memberVariable8 = newValue;
    }

    return std::to_string(memberVariable8);
}
std::string ClassWithBindings139::memberVariable9Command(std::vector<std::string> const& arguments)
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

        memberVariable9 = newValue;
    }

    return std::to_string(memberVariable9);
}

std::string ClassWithBindings139::function0Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 0)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }


    function0();
    return {};
}
std::string ClassWithBindings139::function1Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 0)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }


    function1();
    return {};
}
std::string ClassWithBindings139::function2Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 0)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }


    function2();
    return {};
}
std::string ClassWithBindings139::function3Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 0)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return {};
    }


    function3();
    return {};
}
std::string ClassWithBindings139::function4Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 1)
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

    auto returnValue = function4(arg0);
    return std::to_string(returnValue);
}
std::string ClassWithBindings139::function5Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 1)
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

    function5(arg0);
    return {};
}
std::string ClassWithBindings139::function6Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 1)
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

    auto returnValue = function6(arg0);
    return std::to_string(returnValue);
}
std::string ClassWithBindings139::function7Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 1)
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

    auto returnValue = function7(arg0);
    return std::to_string(returnValue);
}
std::string ClassWithBindings139::function8Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 2)
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

    function8(arg0, arg1);
    return {};
}
std::string ClassWithBindings139::function9Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 2)
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
    double arg1{};
    if (!tryConvert(arguments[1], arg1))
    {
        std::cout << "Failed to convert argument 1!" << std::endl;
        return {};
    }

    function9(arg0, arg1);
    return {};
}
std::string ClassWithBindings139::function10Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 2)
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
    int arg1{};
    if (!tryConvert(arguments[1], arg1))
    {
        std::cout << "Failed to convert argument 1!" << std::endl;
        return {};
    }

    function10(arg0, arg1);
    return {};
}
std::string ClassWithBindings139::function11Command(std::vector<std::string> const& arguments)
{
    if (arguments.size() != 2)
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
    int arg1{};
    if (!tryConvert(arguments[1], arg1))
    {
        std::cout << "Failed to convert argument 1!" << std::endl;
        return {};
    }

    function11(arg0, arg1);
    return {};
}

std::string ClassWithBindings139::variable0Command(std::vector<std::string> const& arguments)
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

        variable0 = newValue;
    }

    return std::to_string(variable0);
}
std::string ClassWithBindings139::variable1Command(std::vector<std::string> const& arguments)
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

        variable1 = newValue;
    }

    return std::to_string(variable1);
}
std::string ClassWithBindings139::variable2Command(std::vector<std::string> const& arguments)
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
std::string ClassWithBindings139::variable3Command(std::vector<std::string> const& arguments)
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

        variable3 = newValue;
    }

    return std::to_string(variable3);
}
std::string ClassWithBindings139::variable4Command(std::vector<std::string> const& arguments)
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

        variable4 = newValue;
    }

    return std::to_string(variable4);
}
std::string ClassWithBindings139::variable5Command(std::vector<std::string> const& arguments)
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

        variable5 = newValue;
    }

    return std::to_string(variable5);
}
std::string ClassWithBindings139::variable6Command(std::vector<std::string> const& arguments)
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

        variable6 = newValue;
    }

    return std::to_string(variable6);
}
std::string ClassWithBindings139::variable7Command(std::vector<std::string> const& arguments)
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

        variable7 = newValue;
    }

    return std::to_string(variable7);
}
std::string ClassWithBindings139::variable8Command(std::vector<std::string> const& arguments)
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

        variable8 = newValue;
    }

    return std::to_string(variable8);
}
std::string ClassWithBindings139::variable9Command(std::vector<std::string> const& arguments)
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

        variable9 = newValue;
    }

    return std::to_string(variable9);
}

#endif
