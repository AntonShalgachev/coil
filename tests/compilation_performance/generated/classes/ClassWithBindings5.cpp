#include "ClassWithBindings5.h"

void ClassWithBindings5::work()
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
void ClassWithBindings5::registerBindings(coil::Bindings& bindings)
{
    bindings["method0"] = coil::bind(&ClassWithBindings5::method0, this);
    bindings["method1"] = coil::bind(&ClassWithBindings5::method1, this);
    bindings["method2"] = coil::bind(&ClassWithBindings5::method2, this);
    bindings["method3"] = coil::bind(&ClassWithBindings5::method3, this);
    bindings["method4"] = coil::bind(&ClassWithBindings5::method4, this);
    bindings["method5"] = coil::bind(&ClassWithBindings5::method5, this);
    bindings["method6"] = coil::bind(&ClassWithBindings5::method6, this);
    bindings["method7"] = coil::bind(&ClassWithBindings5::method7, this);
    bindings["method8"] = coil::bind(&ClassWithBindings5::method8, this);
    bindings["method9"] = coil::bind(&ClassWithBindings5::method9, this);
    bindings["method10"] = coil::bind(&ClassWithBindings5::method10, this);
    bindings["method11"] = coil::bind(&ClassWithBindings5::method11, this);
    bindings["method12"] = coil::bind(&ClassWithBindings5::method12, this);
    bindings["method13"] = coil::bind(&ClassWithBindings5::method13, this);
    bindings["method14"] = coil::bind(&ClassWithBindings5::method14, this);

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
    bindings["memberVariable10"] = coil::variable(&memberVariable10);
    bindings["memberVariable11"] = coil::variable(&memberVariable11);
    bindings["memberVariable12"] = coil::variable(&memberVariable12);
    bindings["memberVariable13"] = coil::variable(&memberVariable13);
    bindings["memberVariable14"] = coil::variable(&memberVariable14);

    bindings["ClassWithBindings5_function0"] = [](coil::Context context, double arg0, short arg1, bool arg2, unsigned arg3, int arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<double>("key");
        args.getOrReport<double>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings5::function0(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings5_function1"] = [](coil::Context context, float arg0, int arg1, short arg2, bool arg3, int arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<float>("key");
        args.getOrReport<float>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings5::function1(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings5_function2"] = [](coil::Context context, unsigned arg0, short arg1, float arg2, bool arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<unsigned>("key");
        args.getOrReport<unsigned>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings5::function2(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings5_function3"] = [](coil::Context context, float arg0, unsigned arg1, float arg2, double arg3, unsigned arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<float>("key");
        args.getOrReport<float>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings5::function3(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings5_function4"] = [](coil::Context context, double arg0, bool arg1, int arg2, int arg3, unsigned arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<double>("key");
        args.getOrReport<double>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings5::function4(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings5_function5"] = [](coil::Context context, short arg0, float arg1, double arg2, double arg3, float arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<short>("key");
        args.getOrReport<short>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings5::function5(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings5_function6"] = [](coil::Context context, int arg0, unsigned arg1, int arg2, float arg3, double arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<int>("key");
        args.getOrReport<int>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings5::function6(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings5_function7"] = [](coil::Context context, bool arg0, bool arg1, unsigned arg2, float arg3, int arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<bool>("key");
        args.getOrReport<bool>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings5::function7(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings5_function8"] = [](coil::Context context, float arg0, float arg1, double arg2, unsigned arg3, bool arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<float>("key");
        args.getOrReport<float>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings5::function8(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings5_function9"] = [](coil::Context context, float arg0, short arg1, unsigned arg2, bool arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<float>("key");
        args.getOrReport<float>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings5::function9(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings5_function10"] = [](coil::Context context, float arg0, short arg1, short arg2, float arg3, unsigned arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<float>("key");
        args.getOrReport<float>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings5::function10(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings5_function11"] = [](coil::Context context, short arg0, double arg1, double arg2, short arg3, bool arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<short>("key");
        args.getOrReport<short>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings5::function11(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings5_function12"] = [](coil::Context context, unsigned arg0, unsigned arg1, int arg2, bool arg3, float arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<unsigned>("key");
        args.getOrReport<unsigned>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings5::function12(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings5_function13"] = [](coil::Context context, unsigned arg0, bool arg1, unsigned arg2, unsigned arg3, bool arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<unsigned>("key");
        args.getOrReport<unsigned>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings5::function13(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings5_function14"] = [](coil::Context context, bool arg0, int arg1, bool arg2, int arg3, float arg4)
    {
        context.reportError("Task failed successfully");
        auto& args = context.namedArgs();
        args.get("key");
        args.get<bool>("key");
        args.getOrReport<bool>("key", coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings5::function14(arg0, arg1, arg2, arg3, arg4);
    };

    bindings["ClassWithBindings5_variable0"] = coil::variable(&ClassWithBindings5::variable0);
    bindings["ClassWithBindings5_variable1"] = coil::variable(&ClassWithBindings5::variable1);
    bindings["ClassWithBindings5_variable2"] = coil::variable(&ClassWithBindings5::variable2);
    bindings["ClassWithBindings5_variable3"] = coil::variable(&ClassWithBindings5::variable3);
    bindings["ClassWithBindings5_variable4"] = coil::variable(&ClassWithBindings5::variable4);
    bindings["ClassWithBindings5_variable5"] = coil::variable(&ClassWithBindings5::variable5);
    bindings["ClassWithBindings5_variable6"] = coil::variable(&ClassWithBindings5::variable6);
    bindings["ClassWithBindings5_variable7"] = coil::variable(&ClassWithBindings5::variable7);
    bindings["ClassWithBindings5_variable8"] = coil::variable(&ClassWithBindings5::variable8);
    bindings["ClassWithBindings5_variable9"] = coil::variable(&ClassWithBindings5::variable9);
    bindings["ClassWithBindings5_variable10"] = coil::variable(&ClassWithBindings5::variable10);
    bindings["ClassWithBindings5_variable11"] = coil::variable(&ClassWithBindings5::variable11);
    bindings["ClassWithBindings5_variable12"] = coil::variable(&ClassWithBindings5::variable12);
    bindings["ClassWithBindings5_variable13"] = coil::variable(&ClassWithBindings5::variable13);
    bindings["ClassWithBindings5_variable14"] = coil::variable(&ClassWithBindings5::variable14);
}
#endif

#if USE_MANUAL
void ClassWithBindings5::registerBindings(DumbBindings& bindings)
{
    bindings.registerCommand("ClassWithBindings5_method0", [this](auto const& args) { return method0Command(args); });
    bindings.registerCommand("ClassWithBindings5_method1", [this](auto const& args) { return method1Command(args); });
    bindings.registerCommand("ClassWithBindings5_method2", [this](auto const& args) { return method2Command(args); });
    bindings.registerCommand("ClassWithBindings5_method3", [this](auto const& args) { return method3Command(args); });
    bindings.registerCommand("ClassWithBindings5_method4", [this](auto const& args) { return method4Command(args); });
    bindings.registerCommand("ClassWithBindings5_method5", [this](auto const& args) { return method5Command(args); });
    bindings.registerCommand("ClassWithBindings5_method6", [this](auto const& args) { return method6Command(args); });
    bindings.registerCommand("ClassWithBindings5_method7", [this](auto const& args) { return method7Command(args); });
    bindings.registerCommand("ClassWithBindings5_method8", [this](auto const& args) { return method8Command(args); });
    bindings.registerCommand("ClassWithBindings5_method9", [this](auto const& args) { return method9Command(args); });
    bindings.registerCommand("ClassWithBindings5_method10", [this](auto const& args) { return method10Command(args); });
    bindings.registerCommand("ClassWithBindings5_method11", [this](auto const& args) { return method11Command(args); });
    bindings.registerCommand("ClassWithBindings5_method12", [this](auto const& args) { return method12Command(args); });
    bindings.registerCommand("ClassWithBindings5_method13", [this](auto const& args) { return method13Command(args); });
    bindings.registerCommand("ClassWithBindings5_method14", [this](auto const& args) { return method14Command(args); });

    bindings.registerCommand("ClassWithBindings5_memberVariable0", [this](auto const& args) { return memberVariable0Command(args); });
    bindings.registerCommand("ClassWithBindings5_memberVariable1", [this](auto const& args) { return memberVariable1Command(args); });
    bindings.registerCommand("ClassWithBindings5_memberVariable2", [this](auto const& args) { return memberVariable2Command(args); });
    bindings.registerCommand("ClassWithBindings5_memberVariable3", [this](auto const& args) { return memberVariable3Command(args); });
    bindings.registerCommand("ClassWithBindings5_memberVariable4", [this](auto const& args) { return memberVariable4Command(args); });
    bindings.registerCommand("ClassWithBindings5_memberVariable5", [this](auto const& args) { return memberVariable5Command(args); });
    bindings.registerCommand("ClassWithBindings5_memberVariable6", [this](auto const& args) { return memberVariable6Command(args); });
    bindings.registerCommand("ClassWithBindings5_memberVariable7", [this](auto const& args) { return memberVariable7Command(args); });
    bindings.registerCommand("ClassWithBindings5_memberVariable8", [this](auto const& args) { return memberVariable8Command(args); });
    bindings.registerCommand("ClassWithBindings5_memberVariable9", [this](auto const& args) { return memberVariable9Command(args); });
    bindings.registerCommand("ClassWithBindings5_memberVariable10", [this](auto const& args) { return memberVariable10Command(args); });
    bindings.registerCommand("ClassWithBindings5_memberVariable11", [this](auto const& args) { return memberVariable11Command(args); });
    bindings.registerCommand("ClassWithBindings5_memberVariable12", [this](auto const& args) { return memberVariable12Command(args); });
    bindings.registerCommand("ClassWithBindings5_memberVariable13", [this](auto const& args) { return memberVariable13Command(args); });
    bindings.registerCommand("ClassWithBindings5_memberVariable14", [this](auto const& args) { return memberVariable14Command(args); });

    bindings.registerCommand("ClassWithBindings5_function0", ClassWithBindings5::function0Command);
    bindings.registerCommand("ClassWithBindings5_function1", ClassWithBindings5::function1Command);
    bindings.registerCommand("ClassWithBindings5_function2", ClassWithBindings5::function2Command);
    bindings.registerCommand("ClassWithBindings5_function3", ClassWithBindings5::function3Command);
    bindings.registerCommand("ClassWithBindings5_function4", ClassWithBindings5::function4Command);
    bindings.registerCommand("ClassWithBindings5_function5", ClassWithBindings5::function5Command);
    bindings.registerCommand("ClassWithBindings5_function6", ClassWithBindings5::function6Command);
    bindings.registerCommand("ClassWithBindings5_function7", ClassWithBindings5::function7Command);
    bindings.registerCommand("ClassWithBindings5_function8", ClassWithBindings5::function8Command);
    bindings.registerCommand("ClassWithBindings5_function9", ClassWithBindings5::function9Command);
    bindings.registerCommand("ClassWithBindings5_function10", ClassWithBindings5::function10Command);
    bindings.registerCommand("ClassWithBindings5_function11", ClassWithBindings5::function11Command);
    bindings.registerCommand("ClassWithBindings5_function12", ClassWithBindings5::function12Command);
    bindings.registerCommand("ClassWithBindings5_function13", ClassWithBindings5::function13Command);
    bindings.registerCommand("ClassWithBindings5_function14", ClassWithBindings5::function14Command);

    bindings.registerCommand("ClassWithBindings5_variable0", ClassWithBindings5::variable0Command);
    bindings.registerCommand("ClassWithBindings5_variable1", ClassWithBindings5::variable1Command);
    bindings.registerCommand("ClassWithBindings5_variable2", ClassWithBindings5::variable2Command);
    bindings.registerCommand("ClassWithBindings5_variable3", ClassWithBindings5::variable3Command);
    bindings.registerCommand("ClassWithBindings5_variable4", ClassWithBindings5::variable4Command);
    bindings.registerCommand("ClassWithBindings5_variable5", ClassWithBindings5::variable5Command);
    bindings.registerCommand("ClassWithBindings5_variable6", ClassWithBindings5::variable6Command);
    bindings.registerCommand("ClassWithBindings5_variable7", ClassWithBindings5::variable7Command);
    bindings.registerCommand("ClassWithBindings5_variable8", ClassWithBindings5::variable8Command);
    bindings.registerCommand("ClassWithBindings5_variable9", ClassWithBindings5::variable9Command);
    bindings.registerCommand("ClassWithBindings5_variable10", ClassWithBindings5::variable10Command);
    bindings.registerCommand("ClassWithBindings5_variable11", ClassWithBindings5::variable11Command);
    bindings.registerCommand("ClassWithBindings5_variable12", ClassWithBindings5::variable12Command);
    bindings.registerCommand("ClassWithBindings5_variable13", ClassWithBindings5::variable13Command);
    bindings.registerCommand("ClassWithBindings5_variable14", ClassWithBindings5::variable14Command);
}
#endif

std::optional<float> ClassWithBindings5::workInternally(std::vector<std::string> const& values)
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

unsigned ClassWithBindings5::method0(unsigned arg0, float arg1, float arg2, unsigned arg3, short arg4)
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

    return arg3;
}
bool ClassWithBindings5::method1(bool arg0, int arg1, bool arg2, int arg3, int arg4)
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
void ClassWithBindings5::method2(int arg0, double arg1, double arg2, float arg3, bool arg4)
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
void ClassWithBindings5::method3(bool arg0, short arg1, short arg2, unsigned arg3, float arg4)
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
void ClassWithBindings5::method4(float arg0, int arg1, short arg2, int arg3, short arg4)
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
void ClassWithBindings5::method5(float arg0, double arg1, unsigned arg2, bool arg3, unsigned arg4)
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
void ClassWithBindings5::method6(unsigned arg0, int arg1, float arg2, short arg3, int arg4)
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
float ClassWithBindings5::method7(double arg0, int arg1, float arg2, bool arg3, unsigned arg4)
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
int ClassWithBindings5::method8(float arg0, int arg1, float arg2, unsigned arg3, double arg4)
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
void ClassWithBindings5::method9(float arg0, double arg1, short arg2, int arg3, unsigned arg4)
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
void ClassWithBindings5::method10(double arg0, short arg1, int arg2, unsigned arg3, unsigned arg4)
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
void ClassWithBindings5::method11(double arg0, unsigned arg1, short arg2, bool arg3, bool arg4)
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
void ClassWithBindings5::method12(int arg0, int arg1, double arg2, float arg3, unsigned arg4)
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
float ClassWithBindings5::method13(double arg0, double arg1, float arg2, double arg3, double arg4)
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
int ClassWithBindings5::method14(bool arg0, int arg1, bool arg2, unsigned arg3, int arg4)
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

void ClassWithBindings5::function0(double arg0, short arg1, bool arg2, unsigned arg3, int arg4)
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
bool ClassWithBindings5::function1(float arg0, int arg1, short arg2, bool arg3, int arg4)
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

    return arg3;
}
short ClassWithBindings5::function2(unsigned arg0, short arg1, float arg2, bool arg3, short arg4)
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
float ClassWithBindings5::function3(float arg0, unsigned arg1, float arg2, double arg3, unsigned arg4)
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
double ClassWithBindings5::function4(double arg0, bool arg1, int arg2, int arg3, unsigned arg4)
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
void ClassWithBindings5::function5(short arg0, float arg1, double arg2, double arg3, float arg4)
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
float ClassWithBindings5::function6(int arg0, unsigned arg1, int arg2, float arg3, double arg4)
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

    return arg3;
}
bool ClassWithBindings5::function7(bool arg0, bool arg1, unsigned arg2, float arg3, int arg4)
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
void ClassWithBindings5::function8(float arg0, float arg1, double arg2, unsigned arg3, bool arg4)
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
void ClassWithBindings5::function9(float arg0, short arg1, unsigned arg2, bool arg3, short arg4)
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
void ClassWithBindings5::function10(float arg0, short arg1, short arg2, float arg3, unsigned arg4)
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
short ClassWithBindings5::function11(short arg0, double arg1, double arg2, short arg3, bool arg4)
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
bool ClassWithBindings5::function12(unsigned arg0, unsigned arg1, int arg2, bool arg3, float arg4)
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

    return arg3;
}
void ClassWithBindings5::function13(unsigned arg0, bool arg1, unsigned arg2, unsigned arg3, bool arg4)
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
bool ClassWithBindings5::function14(bool arg0, int arg1, bool arg2, int arg3, float arg4)
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

////////////////////////////////////////////////////////////////////////////////////////////

#if USE_MANUAL

std::string ClassWithBindings5::method0Command(std::vector<std::string> const& arguments)
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
    float arg1{};
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
    short arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    auto returnValue = method0(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings5::method1Command(std::vector<std::string> const& arguments)
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
    int arg1{};
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

    auto returnValue = method1(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings5::method2Command(std::vector<std::string> const& arguments)
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
    double arg1{};
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
    bool arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    method2(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings5::method3Command(std::vector<std::string> const& arguments)
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
    short arg1{};
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
    float arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    method3(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings5::method4Command(std::vector<std::string> const& arguments)
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
    int arg1{};
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

    method4(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings5::method5Command(std::vector<std::string> const& arguments)
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
    double arg1{};
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
    bool arg3{};
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

    method5(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings5::method6Command(std::vector<std::string> const& arguments)
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
    int arg1{};
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

    method6(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings5::method7Command(std::vector<std::string> const& arguments)
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
    int arg1{};
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
    bool arg3{};
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

    auto returnValue = method7(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings5::method8Command(std::vector<std::string> const& arguments)
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
    int arg1{};
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
    double arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    auto returnValue = method8(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings5::method9Command(std::vector<std::string> const& arguments)
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
    int arg3{};
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

    method9(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings5::method10Command(std::vector<std::string> const& arguments)
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
    short arg1{};
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

    method10(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings5::method11Command(std::vector<std::string> const& arguments)
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
    bool arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    method11(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings5::method12Command(std::vector<std::string> const& arguments)
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
    unsigned arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    method12(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings5::method13Command(std::vector<std::string> const& arguments)
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
    double arg1{};
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
    double arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    auto returnValue = method13(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings5::method14Command(std::vector<std::string> const& arguments)
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
    int arg1{};
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
    int arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    auto returnValue = method14(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}

std::string ClassWithBindings5::memberVariable0Command(std::vector<std::string> const& arguments)
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
std::string ClassWithBindings5::memberVariable1Command(std::vector<std::string> const& arguments)
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

        memberVariable1 = newValue;
    }

    return std::to_string(memberVariable1);
}
std::string ClassWithBindings5::memberVariable2Command(std::vector<std::string> const& arguments)
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

        memberVariable2 = newValue;
    }

    return std::to_string(memberVariable2);
}
std::string ClassWithBindings5::memberVariable3Command(std::vector<std::string> const& arguments)
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

        memberVariable3 = newValue;
    }

    return std::to_string(memberVariable3);
}
std::string ClassWithBindings5::memberVariable4Command(std::vector<std::string> const& arguments)
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

        memberVariable4 = newValue;
    }

    return std::to_string(memberVariable4);
}
std::string ClassWithBindings5::memberVariable5Command(std::vector<std::string> const& arguments)
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

        memberVariable5 = newValue;
    }

    return std::to_string(memberVariable5);
}
std::string ClassWithBindings5::memberVariable6Command(std::vector<std::string> const& arguments)
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

        memberVariable6 = newValue;
    }

    return std::to_string(memberVariable6);
}
std::string ClassWithBindings5::memberVariable7Command(std::vector<std::string> const& arguments)
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

        memberVariable7 = newValue;
    }

    return std::to_string(memberVariable7);
}
std::string ClassWithBindings5::memberVariable8Command(std::vector<std::string> const& arguments)
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

        memberVariable8 = newValue;
    }

    return std::to_string(memberVariable8);
}
std::string ClassWithBindings5::memberVariable9Command(std::vector<std::string> const& arguments)
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
std::string ClassWithBindings5::memberVariable10Command(std::vector<std::string> const& arguments)
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

        memberVariable10 = newValue;
    }

    return std::to_string(memberVariable10);
}
std::string ClassWithBindings5::memberVariable11Command(std::vector<std::string> const& arguments)
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

        memberVariable11 = newValue;
    }

    return std::to_string(memberVariable11);
}
std::string ClassWithBindings5::memberVariable12Command(std::vector<std::string> const& arguments)
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

        memberVariable12 = newValue;
    }

    return std::to_string(memberVariable12);
}
std::string ClassWithBindings5::memberVariable13Command(std::vector<std::string> const& arguments)
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

        memberVariable13 = newValue;
    }

    return std::to_string(memberVariable13);
}
std::string ClassWithBindings5::memberVariable14Command(std::vector<std::string> const& arguments)
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

        memberVariable14 = newValue;
    }

    return std::to_string(memberVariable14);
}

std::string ClassWithBindings5::function0Command(std::vector<std::string> const& arguments)
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
    unsigned arg3{};
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

    function0(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings5::function1Command(std::vector<std::string> const& arguments)
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
    int arg1{};
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
    int arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    auto returnValue = function1(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings5::function2Command(std::vector<std::string> const& arguments)
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
    short arg1{};
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
    bool arg3{};
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
std::string ClassWithBindings5::function3Command(std::vector<std::string> const& arguments)
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
    unsigned arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    auto returnValue = function3(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings5::function4Command(std::vector<std::string> const& arguments)
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
    int arg2{};
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
    unsigned arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    auto returnValue = function4(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings5::function5Command(std::vector<std::string> const& arguments)
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
    double arg2{};
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

    function5(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings5::function6Command(std::vector<std::string> const& arguments)
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
    int arg2{};
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

    auto returnValue = function6(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings5::function7Command(std::vector<std::string> const& arguments)
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

    auto returnValue = function7(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings5::function8Command(std::vector<std::string> const& arguments)
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

    function8(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings5::function9Command(std::vector<std::string> const& arguments)
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
    short arg1{};
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
    bool arg3{};
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

    function9(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings5::function10Command(std::vector<std::string> const& arguments)
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
    short arg1{};
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
    unsigned arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    function10(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings5::function11Command(std::vector<std::string> const& arguments)
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
    double arg1{};
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
    short arg3{};
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

    auto returnValue = function11(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings5::function12Command(std::vector<std::string> const& arguments)
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
    unsigned arg1{};
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
    bool arg3{};
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

    auto returnValue = function12(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}
std::string ClassWithBindings5::function13Command(std::vector<std::string> const& arguments)
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

    function13(arg0, arg1, arg2, arg3, arg4);
    return {};
}
std::string ClassWithBindings5::function14Command(std::vector<std::string> const& arguments)
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
    int arg1{};
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
    float arg4{};
    if (!tryConvert(arguments[4], arg4))
    {
        std::cout << "Failed to convert argument 4!" << std::endl;
        return {};
    }

    auto returnValue = function14(arg0, arg1, arg2, arg3, arg4);
    return std::to_string(returnValue);
}

std::string ClassWithBindings5::variable0Command(std::vector<std::string> const& arguments)
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
std::string ClassWithBindings5::variable1Command(std::vector<std::string> const& arguments)
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

        variable1 = newValue;
    }

    return std::to_string(variable1);
}
std::string ClassWithBindings5::variable2Command(std::vector<std::string> const& arguments)
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

        variable2 = newValue;
    }

    return std::to_string(variable2);
}
std::string ClassWithBindings5::variable3Command(std::vector<std::string> const& arguments)
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

        variable3 = newValue;
    }

    return std::to_string(variable3);
}
std::string ClassWithBindings5::variable4Command(std::vector<std::string> const& arguments)
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

        variable4 = newValue;
    }

    return std::to_string(variable4);
}
std::string ClassWithBindings5::variable5Command(std::vector<std::string> const& arguments)
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

        variable5 = newValue;
    }

    return std::to_string(variable5);
}
std::string ClassWithBindings5::variable6Command(std::vector<std::string> const& arguments)
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

        variable6 = newValue;
    }

    return std::to_string(variable6);
}
std::string ClassWithBindings5::variable7Command(std::vector<std::string> const& arguments)
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

        variable7 = newValue;
    }

    return std::to_string(variable7);
}
std::string ClassWithBindings5::variable8Command(std::vector<std::string> const& arguments)
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

        variable8 = newValue;
    }

    return std::to_string(variable8);
}
std::string ClassWithBindings5::variable9Command(std::vector<std::string> const& arguments)
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

        variable9 = newValue;
    }

    return std::to_string(variable9);
}
std::string ClassWithBindings5::variable10Command(std::vector<std::string> const& arguments)
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

        variable10 = newValue;
    }

    return std::to_string(variable10);
}
std::string ClassWithBindings5::variable11Command(std::vector<std::string> const& arguments)
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

        variable11 = newValue;
    }

    return std::to_string(variable11);
}
std::string ClassWithBindings5::variable12Command(std::vector<std::string> const& arguments)
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

        variable12 = newValue;
    }

    return std::to_string(variable12);
}
std::string ClassWithBindings5::variable13Command(std::vector<std::string> const& arguments)
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

        variable13 = newValue;
    }

    return std::to_string(variable13);
}
std::string ClassWithBindings5::variable14Command(std::vector<std::string> const& arguments)
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

        variable14 = newValue;
    }

    return std::to_string(variable14);
}

#endif
