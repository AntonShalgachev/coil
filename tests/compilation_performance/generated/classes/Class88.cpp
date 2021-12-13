#include "Class88.h"

void Class88::work()
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
void Class88::registerBindings(GeneralBindings& bindings)
{
    ::bind<Class88>(bindings, "method0", &Class88::method0);
    ::bind<Class88>(bindings, "method1", &Class88::method1);
    ::bind<Class88>(bindings, "method2", &Class88::method2);
    ::bind<Class88>(bindings, "method3", &Class88::method3);
    ::bind<Class88>(bindings, "method4", &Class88::method4);
    ::bind<Class88>(bindings, "method5", &Class88::method5);
    ::bind<Class88>(bindings, "method6", &Class88::method6);
    ::bind<Class88>(bindings, "method7", &Class88::method7);
    ::bind<Class88>(bindings, "method8", &Class88::method8);
    ::bind<Class88>(bindings, "method9", &Class88::method9);
    ::bind<Class88>(bindings, "method10", &Class88::method10);
    ::bind<Class88>(bindings, "method11", &Class88::method11);
    ::bind<Class88>(bindings, "method12", &Class88::method12);
    ::bind<Class88>(bindings, "method13", &Class88::method13);
    ::bind<Class88>(bindings, "method14", &Class88::method14);

    bindings["Class88_function0"] = [](coil::Context context, coil::NamedArgs args, double arg0, float arg1, double arg2, bool arg3, double arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<double>("key");
        args.get<double>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class88::function0(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class88_function1"] = [](coil::Context context, coil::NamedArgs args, float arg0, double arg1, double arg2, unsigned arg3, float arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<float>("key");
        args.get<float>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class88::function1(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class88_function2"] = [](coil::Context context, coil::NamedArgs args, float arg0, float arg1, unsigned arg2, double arg3, float arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<float>("key");
        args.get<float>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class88::function2(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class88_function3"] = [](coil::Context context, coil::NamedArgs args, unsigned arg0, unsigned arg1, short arg2, float arg3, float arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<unsigned>("key");
        args.get<unsigned>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class88::function3(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class88_function4"] = [](coil::Context context, coil::NamedArgs args, short arg0, double arg1, double arg2, bool arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<short>("key");
        args.get<short>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class88::function4(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class88_function5"] = [](coil::Context context, coil::NamedArgs args, unsigned arg0, double arg1, unsigned arg2, float arg3, float arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<unsigned>("key");
        args.get<unsigned>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class88::function5(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class88_function6"] = [](coil::Context context, coil::NamedArgs args, short arg0, float arg1, float arg2, double arg3, bool arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<short>("key");
        args.get<short>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class88::function6(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class88_function7"] = [](coil::Context context, coil::NamedArgs args, int arg0, double arg1, short arg2, int arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<int>("key");
        args.get<int>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class88::function7(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class88_function8"] = [](coil::Context context, coil::NamedArgs args, bool arg0, short arg1, double arg2, float arg3, float arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<bool>("key");
        args.get<bool>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class88::function8(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class88_function9"] = [](coil::Context context, coil::NamedArgs args, int arg0, short arg1, short arg2, unsigned arg3, double arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<int>("key");
        args.get<int>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class88::function9(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class88_function10"] = [](coil::Context context, coil::NamedArgs args, bool arg0, unsigned arg1, short arg2, double arg3, bool arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<bool>("key");
        args.get<bool>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class88::function10(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class88_function11"] = [](coil::Context context, coil::NamedArgs args, double arg0, unsigned arg1, unsigned arg2, double arg3, bool arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<double>("key");
        args.get<double>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class88::function11(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class88_function12"] = [](coil::Context context, coil::NamedArgs args, int arg0, unsigned arg1, float arg2, unsigned arg3, int arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<int>("key");
        args.get<int>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class88::function12(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class88_function13"] = [](coil::Context context, coil::NamedArgs args, float arg0, float arg1, bool arg2, float arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<float>("key");
        args.get<float>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class88::function13(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class88_function14"] = [](coil::Context context, coil::NamedArgs args, bool arg0, float arg1, int arg2, int arg3, int arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<bool>("key");
        args.get<bool>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class88::function14(arg0, arg1, arg2, arg3, arg4);
    };
}
#endif

std::optional<float> Class88::workInternally(std::vector<std::string> const& values)
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

double Class88::method0(unsigned arg0, int arg1, unsigned arg2, double arg3, double arg4)
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
void Class88::method1(double arg0, bool arg1, short arg2, bool arg3, short arg4)
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
void Class88::method2(unsigned arg0, int arg1, short arg2, bool arg3, float arg4)
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
int Class88::method3(short arg0, double arg1, unsigned arg2, int arg3, int arg4)
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
float Class88::method4(int arg0, int arg1, float arg2, bool arg3, bool arg4)
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
int Class88::method5(short arg0, int arg1, int arg2, double arg3, float arg4)
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
int Class88::method6(double arg0, double arg1, unsigned arg2, int arg3, unsigned arg4)
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
void Class88::method7(double arg0, unsigned arg1, short arg2, unsigned arg3, int arg4)
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
bool Class88::method8(short arg0, double arg1, unsigned arg2, short arg3, bool arg4)
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
void Class88::method9(float arg0, bool arg1, float arg2, float arg3, short arg4)
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
float Class88::method10(float arg0, bool arg1, double arg2, double arg3, double arg4)
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
unsigned Class88::method11(unsigned arg0, bool arg1, short arg2, double arg3, int arg4)
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
int Class88::method12(float arg0, int arg1, float arg2, int arg3, bool arg4)
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
void Class88::method13(bool arg0, int arg1, bool arg2, float arg3, float arg4)
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
int Class88::method14(int arg0, unsigned arg1, unsigned arg2, float arg3, unsigned arg4)
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

void Class88::function0(double arg0, float arg1, double arg2, bool arg3, double arg4)
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
void Class88::function1(float arg0, double arg1, double arg2, unsigned arg3, float arg4)
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
double Class88::function2(float arg0, float arg1, unsigned arg2, double arg3, float arg4)
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
float Class88::function3(unsigned arg0, unsigned arg1, short arg2, float arg3, float arg4)
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
void Class88::function4(short arg0, double arg1, double arg2, bool arg3, short arg4)
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
void Class88::function5(unsigned arg0, double arg1, unsigned arg2, float arg3, float arg4)
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
void Class88::function6(short arg0, float arg1, float arg2, double arg3, bool arg4)
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
void Class88::function7(int arg0, double arg1, short arg2, int arg3, short arg4)
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
float Class88::function8(bool arg0, short arg1, double arg2, float arg3, float arg4)
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
int Class88::function9(int arg0, short arg1, short arg2, unsigned arg3, double arg4)
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
void Class88::function10(bool arg0, unsigned arg1, short arg2, double arg3, bool arg4)
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
double Class88::function11(double arg0, unsigned arg1, unsigned arg2, double arg3, bool arg4)
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
void Class88::function12(int arg0, unsigned arg1, float arg2, unsigned arg3, int arg4)
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
void Class88::function13(float arg0, float arg1, bool arg2, float arg3, short arg4)
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
void Class88::function14(bool arg0, float arg1, int arg2, int arg3, int arg4)
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
