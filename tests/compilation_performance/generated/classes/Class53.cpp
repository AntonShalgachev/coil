#include "Class53.h"

void Class53::work()
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
void Class53::registerBindings(GeneralBindings& bindings)
{
    ::bind<Class53>(bindings, "method0", &Class53::method0);
    ::bind<Class53>(bindings, "method1", &Class53::method1);
    ::bind<Class53>(bindings, "method2", &Class53::method2);
    ::bind<Class53>(bindings, "method3", &Class53::method3);
    ::bind<Class53>(bindings, "method4", &Class53::method4);
    ::bind<Class53>(bindings, "method5", &Class53::method5);
    ::bind<Class53>(bindings, "method6", &Class53::method6);
    ::bind<Class53>(bindings, "method7", &Class53::method7);
    ::bind<Class53>(bindings, "method8", &Class53::method8);
    ::bind<Class53>(bindings, "method9", &Class53::method9);
    ::bind<Class53>(bindings, "method10", &Class53::method10);
    ::bind<Class53>(bindings, "method11", &Class53::method11);
    ::bind<Class53>(bindings, "method12", &Class53::method12);
    ::bind<Class53>(bindings, "method13", &Class53::method13);
    ::bind<Class53>(bindings, "method14", &Class53::method14);

    bindings["Class53_function0"] = [](coil::Context context, coil::NamedArgs args, short arg0, unsigned arg1, bool arg2, short arg3, double arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<short>("key");
        args.get<short>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class53::function0(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class53_function1"] = [](coil::Context context, coil::NamedArgs args, float arg0, short arg1, double arg2, int arg3, bool arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<float>("key");
        args.get<float>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class53::function1(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class53_function2"] = [](coil::Context context, coil::NamedArgs args, float arg0, bool arg1, bool arg2, int arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<float>("key");
        args.get<float>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class53::function2(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class53_function3"] = [](coil::Context context, coil::NamedArgs args, double arg0, double arg1, bool arg2, unsigned arg3, int arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<double>("key");
        args.get<double>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class53::function3(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class53_function4"] = [](coil::Context context, coil::NamedArgs args, short arg0, float arg1, int arg2, short arg3, int arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<short>("key");
        args.get<short>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class53::function4(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class53_function5"] = [](coil::Context context, coil::NamedArgs args, bool arg0, int arg1, int arg2, int arg3, unsigned arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<bool>("key");
        args.get<bool>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class53::function5(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class53_function6"] = [](coil::Context context, coil::NamedArgs args, int arg0, float arg1, double arg2, float arg3, double arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<int>("key");
        args.get<int>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class53::function6(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class53_function7"] = [](coil::Context context, coil::NamedArgs args, float arg0, int arg1, short arg2, bool arg3, float arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<float>("key");
        args.get<float>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class53::function7(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class53_function8"] = [](coil::Context context, coil::NamedArgs args, unsigned arg0, int arg1, bool arg2, short arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<unsigned>("key");
        args.get<unsigned>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class53::function8(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class53_function9"] = [](coil::Context context, coil::NamedArgs args, short arg0, bool arg1, double arg2, double arg3, float arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<short>("key");
        args.get<short>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class53::function9(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class53_function10"] = [](coil::Context context, coil::NamedArgs args, short arg0, bool arg1, short arg2, int arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<short>("key");
        args.get<short>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class53::function10(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class53_function11"] = [](coil::Context context, coil::NamedArgs args, short arg0, int arg1, float arg2, bool arg3, unsigned arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<short>("key");
        args.get<short>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class53::function11(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class53_function12"] = [](coil::Context context, coil::NamedArgs args, int arg0, double arg1, unsigned arg2, short arg3, double arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<int>("key");
        args.get<int>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class53::function12(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class53_function13"] = [](coil::Context context, coil::NamedArgs args, unsigned arg0, double arg1, int arg2, int arg3, float arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<unsigned>("key");
        args.get<unsigned>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class53::function13(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class53_function14"] = [](coil::Context context, coil::NamedArgs args, short arg0, int arg1, bool arg2, int arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<short>("key");
        args.get<short>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class53::function14(arg0, arg1, arg2, arg3, arg4);
    };
}
#endif

std::optional<float> Class53::workInternally(std::vector<std::string> const& values)
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

void Class53::method0(float arg0, short arg1, double arg2, unsigned arg3, bool arg4)
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
unsigned Class53::method1(double arg0, unsigned arg1, bool arg2, float arg3, int arg4)
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
float Class53::method2(float arg0, unsigned arg1, float arg2, double arg3, bool arg4)
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
int Class53::method3(float arg0, int arg1, double arg2, int arg3, unsigned arg4)
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
double Class53::method4(unsigned arg0, float arg1, double arg2, unsigned arg3, short arg4)
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
double Class53::method5(float arg0, unsigned arg1, float arg2, double arg3, short arg4)
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
void Class53::method6(short arg0, unsigned arg1, short arg2, float arg3, short arg4)
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
void Class53::method7(int arg0, bool arg1, bool arg2, int arg3, unsigned arg4)
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
void Class53::method8(unsigned arg0, bool arg1, short arg2, short arg3, bool arg4)
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
float Class53::method9(double arg0, float arg1, float arg2, unsigned arg3, double arg4)
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
void Class53::method10(double arg0, bool arg1, short arg2, short arg3, unsigned arg4)
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
void Class53::method11(float arg0, bool arg1, short arg2, bool arg3, bool arg4)
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
void Class53::method12(bool arg0, int arg1, double arg2, float arg3, bool arg4)
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
short Class53::method13(short arg0, int arg1, int arg2, double arg3, int arg4)
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
void Class53::method14(short arg0, double arg1, int arg2, short arg3, unsigned arg4)
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

unsigned Class53::function0(short arg0, unsigned arg1, bool arg2, short arg3, double arg4)
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
int Class53::function1(float arg0, short arg1, double arg2, int arg3, bool arg4)
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
void Class53::function2(float arg0, bool arg1, bool arg2, int arg3, short arg4)
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
bool Class53::function3(double arg0, double arg1, bool arg2, unsigned arg3, int arg4)
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
void Class53::function4(short arg0, float arg1, int arg2, short arg3, int arg4)
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
int Class53::function5(bool arg0, int arg1, int arg2, int arg3, unsigned arg4)
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
void Class53::function6(int arg0, float arg1, double arg2, float arg3, double arg4)
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
void Class53::function7(float arg0, int arg1, short arg2, bool arg3, float arg4)
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
void Class53::function8(unsigned arg0, int arg1, bool arg2, short arg3, short arg4)
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
void Class53::function9(short arg0, bool arg1, double arg2, double arg3, float arg4)
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
short Class53::function10(short arg0, bool arg1, short arg2, int arg3, short arg4)
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
void Class53::function11(short arg0, int arg1, float arg2, bool arg3, unsigned arg4)
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
void Class53::function12(int arg0, double arg1, unsigned arg2, short arg3, double arg4)
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
void Class53::function13(unsigned arg0, double arg1, int arg2, int arg3, float arg4)
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
void Class53::function14(short arg0, int arg1, bool arg2, int arg3, short arg4)
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
