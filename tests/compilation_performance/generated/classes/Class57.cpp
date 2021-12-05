#include "Class57.h"
#include <sstream>
#include <iostream>
#include <random>

void Class57::work()
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

#ifdef DEBUG_BINDINGS
void Class57::registerBindings(GeneralBindings& bindings)
{
#ifdef USE_OBJECTS
    ::bind<Class57>(bindings, "method0", &Class57::method0);
    ::bind<Class57>(bindings, "method1", &Class57::method1);
    ::bind<Class57>(bindings, "method2", &Class57::method2);
    ::bind<Class57>(bindings, "method3", &Class57::method3);
    ::bind<Class57>(bindings, "method4", &Class57::method4);
    ::bind<Class57>(bindings, "method5", &Class57::method5);
    ::bind<Class57>(bindings, "method6", &Class57::method6);
    ::bind<Class57>(bindings, "method7", &Class57::method7);
    ::bind<Class57>(bindings, "method8", &Class57::method8);
    ::bind<Class57>(bindings, "method9", &Class57::method9);
    ::bind<Class57>(bindings, "method10", &Class57::method10);
    ::bind<Class57>(bindings, "method11", &Class57::method11);
    ::bind<Class57>(bindings, "method12", &Class57::method12);
    ::bind<Class57>(bindings, "method13", &Class57::method13);
    ::bind<Class57>(bindings, "method14", &Class57::method14);
#else
    bindings["Class57_method0"] = &ns_Class57::method0;
    bindings["Class57_method1"] = &ns_Class57::method1;
    bindings["Class57_method2"] = &ns_Class57::method2;
    bindings["Class57_method3"] = &ns_Class57::method3;
    bindings["Class57_method4"] = &ns_Class57::method4;
    bindings["Class57_method5"] = &ns_Class57::method5;
    bindings["Class57_method6"] = &ns_Class57::method6;
    bindings["Class57_method7"] = &ns_Class57::method7;
    bindings["Class57_method8"] = &ns_Class57::method8;
    bindings["Class57_method9"] = &ns_Class57::method9;
    bindings["Class57_method10"] = &ns_Class57::method10;
    bindings["Class57_method11"] = &ns_Class57::method11;
    bindings["Class57_method12"] = &ns_Class57::method12;
    bindings["Class57_method13"] = &ns_Class57::method13;
    bindings["Class57_method14"] = &ns_Class57::method14;
#endif
}
#endif

std::optional<float> Class57::workInternally(std::vector<std::string> const& values)
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

    return res;
}

void Class57::method0(double arg0, float arg1, double arg2, unsigned arg3, short arg4)
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
bool Class57::method1(bool arg0, unsigned arg1, double arg2, float arg3, float arg4)
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
bool Class57::method2(bool arg0, int arg1, bool arg2, double arg3, double arg4)
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
int Class57::method3(int arg0, short arg1, unsigned arg2, short arg3, float arg4)
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
void Class57::method4(int arg0, bool arg1, int arg2, short arg3, bool arg4)
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
void Class57::method5(bool arg0, float arg1, unsigned arg2, short arg3, bool arg4)
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
void Class57::method6(short arg0, bool arg1, bool arg2, int arg3, bool arg4)
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
void Class57::method7(short arg0, double arg1, short arg2, float arg3, bool arg4)
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
void Class57::method8(bool arg0, int arg1, int arg2, int arg3, short arg4)
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
void Class57::method9(double arg0, bool arg1, bool arg2, bool arg3, int arg4)
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
double Class57::method10(unsigned arg0, double arg1, unsigned arg2, double arg3, bool arg4)
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
void Class57::method11(short arg0, double arg1, int arg2, int arg3, double arg4)
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
int Class57::method12(int arg0, unsigned arg1, short arg2, bool arg3, int arg4)
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
void Class57::method13(unsigned arg0, bool arg1, float arg2, int arg3, unsigned arg4)
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
bool Class57::method14(short arg0, bool arg1, short arg2, int arg3, float arg4)
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

void ns_Class57::method0(double arg0, float arg1, double arg2, unsigned arg3, short arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = Class57::workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

}
bool ns_Class57::method1(bool arg0, unsigned arg1, double arg2, float arg3, float arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = Class57::workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

    return arg0;
}
bool ns_Class57::method2(bool arg0, int arg1, bool arg2, double arg3, double arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = Class57::workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

    return arg0;
}
int ns_Class57::method3(int arg0, short arg1, unsigned arg2, short arg3, float arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = Class57::workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

    return arg0;
}
void ns_Class57::method4(int arg0, bool arg1, int arg2, short arg3, bool arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = Class57::workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

}
void ns_Class57::method5(bool arg0, float arg1, unsigned arg2, short arg3, bool arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = Class57::workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

}
void ns_Class57::method6(short arg0, bool arg1, bool arg2, int arg3, bool arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = Class57::workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

}
void ns_Class57::method7(short arg0, double arg1, short arg2, float arg3, bool arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = Class57::workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

}
void ns_Class57::method8(bool arg0, int arg1, int arg2, int arg3, short arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = Class57::workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

}
void ns_Class57::method9(double arg0, bool arg1, bool arg2, bool arg3, int arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = Class57::workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

}
double ns_Class57::method10(unsigned arg0, double arg1, unsigned arg2, double arg3, bool arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = Class57::workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

    return arg1;
}
void ns_Class57::method11(short arg0, double arg1, int arg2, int arg3, double arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = Class57::workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

}
int ns_Class57::method12(int arg0, unsigned arg1, short arg2, bool arg3, int arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = Class57::workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

    return arg0;
}
void ns_Class57::method13(unsigned arg0, bool arg1, float arg2, int arg3, unsigned arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = Class57::workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

}
bool ns_Class57::method14(short arg0, bool arg1, short arg2, int arg3, float arg4)
{
    std::cout << arg0 << arg1 << arg2 << arg3 << arg4;
    
    std::vector<std::string> strings;
    std::random_device rd;
    std::uniform_real_distribution<float> dist{-10.0f, 10.0f};

    for (auto i = 0; i < 100; i++)
        strings.push_back(std::to_string(dist(rd)));

    auto result = Class57::workInternally(strings);
    if (result)
        std::cout << *result << std::endl;
    else
        std::cout << "null" << std::endl;

    return arg1;
}
