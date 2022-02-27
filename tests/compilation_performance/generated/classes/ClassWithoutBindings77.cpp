#include "ClassWithoutBindings77.h"

void ClassWithoutBindings77::work()
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


std::optional<float> ClassWithoutBindings77::workInternally(std::vector<std::string> const& values)
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

bool ClassWithoutBindings77::method0(unsigned arg0, unsigned arg1, float arg2, double arg3, bool arg4)
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
void ClassWithoutBindings77::method1(float arg0, double arg1, bool arg2, double arg3, float arg4)
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
void ClassWithoutBindings77::method2(float arg0, bool arg1, bool arg2, float arg3, double arg4)
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
short ClassWithoutBindings77::method3(bool arg0, bool arg1, float arg2, short arg3, short arg4)
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
void ClassWithoutBindings77::method4(float arg0, unsigned arg1, short arg2, int arg3, unsigned arg4)
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
void ClassWithoutBindings77::method5(bool arg0, bool arg1, float arg2, short arg3, float arg4)
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
void ClassWithoutBindings77::method6(double arg0, double arg1, short arg2, unsigned arg3, int arg4)
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
float ClassWithoutBindings77::method7(float arg0, float arg1, float arg2, bool arg3, double arg4)
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
bool ClassWithoutBindings77::method8(double arg0, float arg1, unsigned arg2, bool arg3, float arg4)
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
void ClassWithoutBindings77::method9(unsigned arg0, float arg1, unsigned arg2, short arg3, float arg4)
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
double ClassWithoutBindings77::method10(bool arg0, short arg1, double arg2, float arg3, int arg4)
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
float ClassWithoutBindings77::method11(int arg0, bool arg1, float arg2, float arg3, float arg4)
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
float ClassWithoutBindings77::method12(float arg0, double arg1, bool arg2, short arg3, unsigned arg4)
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
int ClassWithoutBindings77::method13(float arg0, unsigned arg1, int arg2, int arg3, int arg4)
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
short ClassWithoutBindings77::method14(float arg0, bool arg1, float arg2, short arg3, int arg4)
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

bool ClassWithoutBindings77::function0(unsigned arg0, int arg1, bool arg2, short arg3, bool arg4)
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
short ClassWithoutBindings77::function1(int arg0, double arg1, short arg2, short arg3, double arg4)
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
void ClassWithoutBindings77::function2(double arg0, bool arg1, float arg2, unsigned arg3, bool arg4)
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
int ClassWithoutBindings77::function3(int arg0, short arg1, double arg2, unsigned arg3, double arg4)
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
void ClassWithoutBindings77::function4(short arg0, short arg1, int arg2, int arg3, double arg4)
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
float ClassWithoutBindings77::function5(double arg0, double arg1, double arg2, unsigned arg3, float arg4)
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
void ClassWithoutBindings77::function6(double arg0, int arg1, unsigned arg2, float arg3, short arg4)
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
double ClassWithoutBindings77::function7(float arg0, double arg1, bool arg2, float arg3, double arg4)
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
void ClassWithoutBindings77::function8(unsigned arg0, bool arg1, short arg2, int arg3, int arg4)
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
short ClassWithoutBindings77::function9(float arg0, bool arg1, bool arg2, double arg3, short arg4)
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
void ClassWithoutBindings77::function10(short arg0, unsigned arg1, float arg2, float arg3, short arg4)
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
double ClassWithoutBindings77::function11(short arg0, short arg1, bool arg2, double arg3, bool arg4)
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
double ClassWithoutBindings77::function12(double arg0, bool arg1, bool arg2, float arg3, short arg4)
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
void ClassWithoutBindings77::function13(unsigned arg0, unsigned arg1, double arg2, float arg3, int arg4)
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
int ClassWithoutBindings77::function14(double arg0, int arg1, bool arg2, bool arg3, unsigned arg4)
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
