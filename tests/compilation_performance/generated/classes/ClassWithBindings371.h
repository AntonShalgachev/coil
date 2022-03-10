#pragma once

// Generated with seed '88005553906'

#include "../../Common.h"


class ClassWithBindings371
{
public:
    void work();

#if USE_COIL
    void registerBindings(coil::Bindings& bindings);
#endif

#if USE_MANUAL
    void registerBindings(DumbBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    [[maybe_unused]] double method0(int arg0, float arg1, bool arg2, double arg3, bool arg4);
    [[maybe_unused]] void method1(bool arg0, int arg1, bool arg2, unsigned arg3, bool arg4);
    [[maybe_unused]] short method2(int arg0, double arg1, bool arg2, short arg3, short arg4);

    [[maybe_unused]] bool memberVariable0{};
    [[maybe_unused]] double memberVariable1{};
    [[maybe_unused]] bool memberVariable2{};

    [[maybe_unused]] static double function0(unsigned arg0, bool arg1, double arg2, bool arg3, unsigned arg4);
    [[maybe_unused]] static void function1(bool arg0, unsigned arg1, double arg2, short arg3, double arg4);
    [[maybe_unused]] static double function2(double arg0, unsigned arg1, short arg2, unsigned arg3, double arg4);

    [[maybe_unused]] inline static short variable0{};
    [[maybe_unused]] inline static short variable1{};
    [[maybe_unused]] inline static bool variable2{};

#if USE_MANUAL
    std::string method0Command(std::vector<std::string> const& arguments);
    std::string method1Command(std::vector<std::string> const& arguments);
    std::string method2Command(std::vector<std::string> const& arguments);

    std::string memberVariable0Command(std::vector<std::string> const& arguments);
    std::string memberVariable1Command(std::vector<std::string> const& arguments);
    std::string memberVariable2Command(std::vector<std::string> const& arguments);

    static std::string function0Command(std::vector<std::string> const& arguments);
    static std::string function1Command(std::vector<std::string> const& arguments);
    static std::string function2Command(std::vector<std::string> const& arguments);

    static std::string variable0Command(std::vector<std::string> const& arguments);
    static std::string variable1Command(std::vector<std::string> const& arguments);
    static std::string variable2Command(std::vector<std::string> const& arguments);
#endif
};
