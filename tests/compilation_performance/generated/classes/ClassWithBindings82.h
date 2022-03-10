#pragma once

// Generated with seed '88005553617'

#include "../../Common.h"


class ClassWithBindings82
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
    [[maybe_unused]] float method0(short arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    [[maybe_unused]] float method1(unsigned arg0, float arg1, float arg2, int arg3, double arg4);
    [[maybe_unused]] void method2(unsigned arg0, bool arg1, float arg2, int arg3, unsigned arg4);

    [[maybe_unused]] unsigned memberVariable0{};
    [[maybe_unused]] unsigned memberVariable1{};
    [[maybe_unused]] unsigned memberVariable2{};

    [[maybe_unused]] static double function0(double arg0, unsigned arg1, double arg2, float arg3, double arg4);
    [[maybe_unused]] static void function1(short arg0, short arg1, float arg2, unsigned arg3, double arg4);
    [[maybe_unused]] static void function2(unsigned arg0, unsigned arg1, unsigned arg2, int arg3, unsigned arg4);

    [[maybe_unused]] inline static unsigned variable0{};
    [[maybe_unused]] inline static unsigned variable1{};
    [[maybe_unused]] inline static float variable2{};

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
