#pragma once

// Generated with seed '88005554020'

#include "../../Common.h"


class ClassWithBindings485
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
    [[maybe_unused]] int method0(bool arg0, int arg1, short arg2, short arg3, bool arg4);
    [[maybe_unused]] unsigned method1(short arg0, bool arg1, bool arg2, double arg3, unsigned arg4);
    [[maybe_unused]] void method2(double arg0, short arg1, double arg2, float arg3, bool arg4);

    [[maybe_unused]] float memberVariable0{};
    [[maybe_unused]] float memberVariable1{};
    [[maybe_unused]] bool memberVariable2{};

    [[maybe_unused]] static void function0(short arg0, bool arg1, double arg2, unsigned arg3, bool arg4);
    [[maybe_unused]] static double function1(double arg0, unsigned arg1, bool arg2, double arg3, double arg4);
    [[maybe_unused]] static float function2(unsigned arg0, unsigned arg1, float arg2, int arg3, short arg4);

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