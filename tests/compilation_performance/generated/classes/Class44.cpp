#include "Class44.h"

void Class44::work()
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
void Class44::registerBindings(GeneralBindings& bindings)
{
    ::bind<Class44>(bindings, "method0", &Class44::method0);
    ::bind<Class44>(bindings, "method1", &Class44::method1);
    ::bind<Class44>(bindings, "method2", &Class44::method2);
    ::bind<Class44>(bindings, "method3", &Class44::method3);
    ::bind<Class44>(bindings, "method4", &Class44::method4);
    ::bind<Class44>(bindings, "method5", &Class44::method5);
    ::bind<Class44>(bindings, "method6", &Class44::method6);
    ::bind<Class44>(bindings, "method7", &Class44::method7);
    ::bind<Class44>(bindings, "method8", &Class44::method8);
    ::bind<Class44>(bindings, "method9", &Class44::method9);
    ::bind<Class44>(bindings, "method10", &Class44::method10);
    ::bind<Class44>(bindings, "method11", &Class44::method11);
    ::bind<Class44>(bindings, "method12", &Class44::method12);
    ::bind<Class44>(bindings, "method13", &Class44::method13);
    ::bind<Class44>(bindings, "method14", &Class44::method14);

    bindings["Class44_function0"] = [](coil::Context context, coil::NamedArgs args, int arg0, float arg1, int arg2, int arg3, bool arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<int>("key");
        args.get<int>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class44::function0(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class44_function1"] = [](coil::Context context, coil::NamedArgs args, bool arg0, float arg1, unsigned arg2, unsigned arg3, unsigned arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<bool>("key");
        args.get<bool>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class44::function1(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class44_function2"] = [](coil::Context context, coil::NamedArgs args, short arg0, short arg1, bool arg2, int arg3, double arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<short>("key");
        args.get<short>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class44::function2(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class44_function3"] = [](coil::Context context, coil::NamedArgs args, short arg0, bool arg1, unsigned arg2, int arg3, int arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<short>("key");
        args.get<short>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class44::function3(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class44_function4"] = [](coil::Context context, coil::NamedArgs args, double arg0, int arg1, short arg2, unsigned arg3, unsigned arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<double>("key");
        args.get<double>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class44::function4(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class44_function5"] = [](coil::Context context, coil::NamedArgs args, unsigned arg0, float arg1, bool arg2, float arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<unsigned>("key");
        args.get<unsigned>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class44::function5(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class44_function6"] = [](coil::Context context, coil::NamedArgs args, unsigned arg0, bool arg1, int arg2, unsigned arg3, bool arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<unsigned>("key");
        args.get<unsigned>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class44::function6(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class44_function7"] = [](coil::Context context, coil::NamedArgs args, short arg0, bool arg1, float arg2, int arg3, bool arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<short>("key");
        args.get<short>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class44::function7(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class44_function8"] = [](coil::Context context, coil::NamedArgs args, int arg0, unsigned arg1, short arg2, int arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<int>("key");
        args.get<int>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class44::function8(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class44_function9"] = [](coil::Context context, coil::NamedArgs args, float arg0, double arg1, double arg2, unsigned arg3, float arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<float>("key");
        args.get<float>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class44::function9(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class44_function10"] = [](coil::Context context, coil::NamedArgs args, double arg0, int arg1, double arg2, float arg3, short arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<double>("key");
        args.get<double>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class44::function10(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class44_function11"] = [](coil::Context context, coil::NamedArgs args, int arg0, unsigned arg1, bool arg2, int arg3, double arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<int>("key");
        args.get<int>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class44::function11(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class44_function12"] = [](coil::Context context, coil::NamedArgs args, short arg0, float arg1, bool arg2, int arg3, bool arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<short>("key");
        args.get<short>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class44::function12(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class44_function13"] = [](coil::Context context, coil::NamedArgs args, unsigned arg0, unsigned arg1, unsigned arg2, float arg3, int arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<unsigned>("key");
        args.get<unsigned>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class44::function13(arg0, arg1, arg2, arg3, arg4);
    };
    bindings["Class44_function14"] = [](coil::Context context, coil::NamedArgs args, unsigned arg0, short arg1, float arg2, double arg3, float arg4)
    {
        context.reportError("Task failed successfully");
        args.get("key");
        args.get<unsigned>("key");
        args.get<unsigned>("key", context, coil::NamedArgs::ArgType::Optional);
        return Class44::function14(arg0, arg1, arg2, arg3, arg4);
    };
}
#endif

std::optional<float> Class44::workInternally(std::vector<std::string> const& values)
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

void Class44::method0(double arg0, short arg1, double arg2, bool arg3, float arg4)
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
void Class44::method1(short arg0, int arg1, short arg2, unsigned arg3, unsigned arg4)
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
double Class44::method2(int arg0, short arg1, double arg2, int arg3, unsigned arg4)
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
void Class44::method3(short arg0, bool arg1, float arg2, bool arg3, unsigned arg4)
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
void Class44::method4(bool arg0, int arg1, short arg2, int arg3, bool arg4)
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
void Class44::method5(int arg0, double arg1, double arg2, int arg3, short arg4)
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
unsigned Class44::method6(short arg0, float arg1, float arg2, short arg3, unsigned arg4)
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
void Class44::method7(double arg0, short arg1, float arg2, bool arg3, float arg4)
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
unsigned Class44::method8(bool arg0, bool arg1, unsigned arg2, int arg3, float arg4)
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
double Class44::method9(double arg0, short arg1, bool arg2, int arg3, short arg4)
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
float Class44::method10(short arg0, float arg1, unsigned arg2, float arg3, float arg4)
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
float Class44::method11(unsigned arg0, double arg1, bool arg2, short arg3, float arg4)
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
void Class44::method12(bool arg0, double arg1, short arg2, bool arg3, int arg4)
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
bool Class44::method13(bool arg0, float arg1, double arg2, bool arg3, bool arg4)
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
void Class44::method14(short arg0, double arg1, int arg2, float arg3, bool arg4)
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

int Class44::function0(int arg0, float arg1, int arg2, int arg3, bool arg4)
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
unsigned Class44::function1(bool arg0, float arg1, unsigned arg2, unsigned arg3, unsigned arg4)
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
void Class44::function2(short arg0, short arg1, bool arg2, int arg3, double arg4)
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
void Class44::function3(short arg0, bool arg1, unsigned arg2, int arg3, int arg4)
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
void Class44::function4(double arg0, int arg1, short arg2, unsigned arg3, unsigned arg4)
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
void Class44::function5(unsigned arg0, float arg1, bool arg2, float arg3, short arg4)
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
void Class44::function6(unsigned arg0, bool arg1, int arg2, unsigned arg3, bool arg4)
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
bool Class44::function7(short arg0, bool arg1, float arg2, int arg3, bool arg4)
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
short Class44::function8(int arg0, unsigned arg1, short arg2, int arg3, short arg4)
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
unsigned Class44::function9(float arg0, double arg1, double arg2, unsigned arg3, float arg4)
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
int Class44::function10(double arg0, int arg1, double arg2, float arg3, short arg4)
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
void Class44::function11(int arg0, unsigned arg1, bool arg2, int arg3, double arg4)
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
void Class44::function12(short arg0, float arg1, bool arg2, int arg3, bool arg4)
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
void Class44::function13(unsigned arg0, unsigned arg1, unsigned arg2, float arg3, int arg4)
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
void Class44::function14(unsigned arg0, short arg1, float arg2, double arg3, float arg4)
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
