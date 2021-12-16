#include "ClassWithBindings56.h"

void ClassWithBindings56::work()
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

#ifdef DEBUG_BINDINGS
void ClassWithBindings56::registerBindings(GeneralBindings& bindings)
{
    ::bind<ClassWithBindings56>(bindings, "method0", &ClassWithBindings56::method0);
    ::bind<ClassWithBindings56>(bindings, "method1", &ClassWithBindings56::method1);
    ::bind<ClassWithBindings56>(bindings, "method2", &ClassWithBindings56::method2);
    ::bind<ClassWithBindings56>(bindings, "method3", &ClassWithBindings56::method3);
    ::bind<ClassWithBindings56>(bindings, "method4", &ClassWithBindings56::method4);
    ::bind<ClassWithBindings56>(bindings, "method5", &ClassWithBindings56::method5);
    ::bind<ClassWithBindings56>(bindings, "method6", &ClassWithBindings56::method6);
    ::bind<ClassWithBindings56>(bindings, "method7", &ClassWithBindings56::method7);
    ::bind<ClassWithBindings56>(bindings, "method8", &ClassWithBindings56::method8);
    ::bind<ClassWithBindings56>(bindings, "method9", &ClassWithBindings56::method9);
    ::bind<ClassWithBindings56>(bindings, "method10", &ClassWithBindings56::method10);
    ::bind<ClassWithBindings56>(bindings, "method11", &ClassWithBindings56::method11);
    ::bind<ClassWithBindings56>(bindings, "method12", &ClassWithBindings56::method12);
    ::bind<ClassWithBindings56>(bindings, "method13", &ClassWithBindings56::method13);
    ::bind<ClassWithBindings56>(bindings, "method14", &ClassWithBindings56::method14);

    ::bind<ClassWithBindings56>(bindings, "memberVariable0", &ClassWithBindings56::memberVariable0);
    ::bind<ClassWithBindings56>(bindings, "memberVariable1", &ClassWithBindings56::memberVariable1);
    ::bind<ClassWithBindings56>(bindings, "memberVariable2", &ClassWithBindings56::memberVariable2);
    ::bind<ClassWithBindings56>(bindings, "memberVariable3", &ClassWithBindings56::memberVariable3);
    ::bind<ClassWithBindings56>(bindings, "memberVariable4", &ClassWithBindings56::memberVariable4);
    ::bind<ClassWithBindings56>(bindings, "memberVariable5", &ClassWithBindings56::memberVariable5);
    ::bind<ClassWithBindings56>(bindings, "memberVariable6", &ClassWithBindings56::memberVariable6);
    ::bind<ClassWithBindings56>(bindings, "memberVariable7", &ClassWithBindings56::memberVariable7);
    ::bind<ClassWithBindings56>(bindings, "memberVariable8", &ClassWithBindings56::memberVariable8);
    ::bind<ClassWithBindings56>(bindings, "memberVariable9", &ClassWithBindings56::memberVariable9);
    ::bind<ClassWithBindings56>(bindings, "memberVariable10", &ClassWithBindings56::memberVariable10);
    ::bind<ClassWithBindings56>(bindings, "memberVariable11", &ClassWithBindings56::memberVariable11);
    ::bind<ClassWithBindings56>(bindings, "memberVariable12", &ClassWithBindings56::memberVariable12);
    ::bind<ClassWithBindings56>(bindings, "memberVariable13", &ClassWithBindings56::memberVariable13);
    ::bind<ClassWithBindings56>(bindings, "memberVariable14", &ClassWithBindings56::memberVariable14);

    bindings["ClassWithBindings56_function0"] = [](coil::Context context, coil::NamedArgs args, float arg0, double arg1, unsigned arg2, int arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<float>("key");
        args.get<float>("key", context, coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings56::function0(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings56_function1"] = [](coil::Context context, coil::NamedArgs args, float arg0, unsigned arg1, int arg2, unsigned arg3, float arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<float>("key");
        args.get<float>("key", context, coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings56::function1(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings56_function2"] = [](coil::Context context, coil::NamedArgs args, unsigned arg0, unsigned arg1, short arg2, double arg3, bool arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<unsigned>("key");
        args.get<unsigned>("key", context, coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings56::function2(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings56_function3"] = [](coil::Context context, coil::NamedArgs args, bool arg0, float arg1, float arg2, float arg3, float arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<bool>("key");
        args.get<bool>("key", context, coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings56::function3(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings56_function4"] = [](coil::Context context, coil::NamedArgs args, int arg0, float arg1, unsigned arg2, double arg3, int arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<int>("key");
        args.get<int>("key", context, coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings56::function4(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings56_function5"] = [](coil::Context context, coil::NamedArgs args, bool arg0, short arg1, unsigned arg2, unsigned arg3, unsigned arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<bool>("key");
        args.get<bool>("key", context, coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings56::function5(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings56_function6"] = [](coil::Context context, coil::NamedArgs args, short arg0, short arg1, bool arg2, short arg3, bool arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<short>("key");
        args.get<short>("key", context, coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings56::function6(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings56_function7"] = [](coil::Context context, coil::NamedArgs args, short arg0, short arg1, short arg2, double arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<short>("key");
        args.get<short>("key", context, coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings56::function7(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings56_function8"] = [](coil::Context context, coil::NamedArgs args, float arg0, int arg1, unsigned arg2, bool arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<float>("key");
        args.get<float>("key", context, coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings56::function8(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings56_function9"] = [](coil::Context context, coil::NamedArgs args, double arg0, double arg1, float arg2, bool arg3, int arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<double>("key");
        args.get<double>("key", context, coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings56::function9(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings56_function10"] = [](coil::Context context, coil::NamedArgs args, double arg0, double arg1, double arg2, unsigned arg3, bool arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<double>("key");
        args.get<double>("key", context, coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings56::function10(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings56_function11"] = [](coil::Context context, coil::NamedArgs args, double arg0, short arg1, double arg2, float arg3, double arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<double>("key");
        args.get<double>("key", context, coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings56::function11(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings56_function12"] = [](coil::Context context, coil::NamedArgs args, int arg0, int arg1, double arg2, double arg3, unsigned arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<int>("key");
        args.get<int>("key", context, coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings56::function12(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings56_function13"] = [](coil::Context context, coil::NamedArgs args, float arg0, float arg1, short arg2, short arg3, double arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<float>("key");
        args.get<float>("key", context, coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings56::function13(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["ClassWithBindings56_function14"] = [](coil::Context context, coil::NamedArgs args, float arg0, bool arg1, bool arg2, int arg3, unsigned arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<float>("key");
        args.get<float>("key", context, coil::NamedArgs::ArgType::Optional);
        return ClassWithBindings56::function14(arg0, arg1, arg2, arg3, arg4);
    };

    bindings["ClassWithBindings56_variable0"] = &ClassWithBindings56::variable0;
    bindings["ClassWithBindings56_variable1"] = &ClassWithBindings56::variable1;
    bindings["ClassWithBindings56_variable2"] = &ClassWithBindings56::variable2;
    bindings["ClassWithBindings56_variable3"] = &ClassWithBindings56::variable3;
    bindings["ClassWithBindings56_variable4"] = &ClassWithBindings56::variable4;
    bindings["ClassWithBindings56_variable5"] = &ClassWithBindings56::variable5;
    bindings["ClassWithBindings56_variable6"] = &ClassWithBindings56::variable6;
    bindings["ClassWithBindings56_variable7"] = &ClassWithBindings56::variable7;
    bindings["ClassWithBindings56_variable8"] = &ClassWithBindings56::variable8;
    bindings["ClassWithBindings56_variable9"] = &ClassWithBindings56::variable9;
    bindings["ClassWithBindings56_variable10"] = &ClassWithBindings56::variable10;
    bindings["ClassWithBindings56_variable11"] = &ClassWithBindings56::variable11;
    bindings["ClassWithBindings56_variable12"] = &ClassWithBindings56::variable12;
    bindings["ClassWithBindings56_variable13"] = &ClassWithBindings56::variable13;
    bindings["ClassWithBindings56_variable14"] = &ClassWithBindings56::variable14;
}
#endif

std::optional<float> ClassWithBindings56::workInternally(std::vector<std::string> const& values)
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

void ClassWithBindings56::method0(bool arg0, float arg1, int arg2, bool arg3, int arg4)
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
void ClassWithBindings56::method1(short arg0, double arg1, double arg2, bool arg3, short arg4)
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
short ClassWithBindings56::method2(short arg0, int arg1, short arg2, double arg3, double arg4)
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
void ClassWithBindings56::method3(unsigned arg0, int arg1, short arg2, float arg3, unsigned arg4)
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
void ClassWithBindings56::method4(float arg0, int arg1, int arg2, float arg3, bool arg4)
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
short ClassWithBindings56::method5(bool arg0, unsigned arg1, int arg2, double arg3, short arg4)
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
void ClassWithBindings56::method6(double arg0, bool arg1, unsigned arg2, int arg3, short arg4)
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
void ClassWithBindings56::method7(short arg0, unsigned arg1, float arg2, double arg3, short arg4)
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
float ClassWithBindings56::method8(short arg0, float arg1, bool arg2, float arg3, double arg4)
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
void ClassWithBindings56::method9(unsigned arg0, short arg1, short arg2, bool arg3, int arg4)
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
void ClassWithBindings56::method10(bool arg0, short arg1, float arg2, unsigned arg3, int arg4)
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
unsigned ClassWithBindings56::method11(float arg0, bool arg1, short arg2, short arg3, unsigned arg4)
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
void ClassWithBindings56::method12(double arg0, float arg1, int arg2, unsigned arg3, short arg4)
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
void ClassWithBindings56::method13(float arg0, double arg1, int arg2, unsigned arg3, bool arg4)
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
short ClassWithBindings56::method14(short arg0, unsigned arg1, short arg2, short arg3, bool arg4)
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

void ClassWithBindings56::function0(float arg0, double arg1, unsigned arg2, int arg3, short arg4)
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
unsigned ClassWithBindings56::function1(float arg0, unsigned arg1, int arg2, unsigned arg3, float arg4)
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
void ClassWithBindings56::function2(unsigned arg0, unsigned arg1, short arg2, double arg3, bool arg4)
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
void ClassWithBindings56::function3(bool arg0, float arg1, float arg2, float arg3, float arg4)
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
double ClassWithBindings56::function4(int arg0, float arg1, unsigned arg2, double arg3, int arg4)
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
void ClassWithBindings56::function5(bool arg0, short arg1, unsigned arg2, unsigned arg3, unsigned arg4)
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
void ClassWithBindings56::function6(short arg0, short arg1, bool arg2, short arg3, bool arg4)
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
void ClassWithBindings56::function7(short arg0, short arg1, short arg2, double arg3, short arg4)
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
void ClassWithBindings56::function8(float arg0, int arg1, unsigned arg2, bool arg3, short arg4)
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
double ClassWithBindings56::function9(double arg0, double arg1, float arg2, bool arg3, int arg4)
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
void ClassWithBindings56::function10(double arg0, double arg1, double arg2, unsigned arg3, bool arg4)
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
float ClassWithBindings56::function11(double arg0, short arg1, double arg2, float arg3, double arg4)
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
void ClassWithBindings56::function12(int arg0, int arg1, double arg2, double arg3, unsigned arg4)
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
void ClassWithBindings56::function13(float arg0, float arg1, short arg2, short arg3, double arg4)
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
void ClassWithBindings56::function14(float arg0, bool arg1, bool arg2, int arg3, unsigned arg4)
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
