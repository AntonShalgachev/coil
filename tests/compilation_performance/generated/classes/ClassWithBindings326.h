#pragma once

// Generated with seed '88005553861'

#include "../../Common.h"


class ClassWithBindings326
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
    [[maybe_unused]] double method0(double arg0, float arg1, bool arg2, double arg3, float arg4);
    [[maybe_unused]] void method1(bool arg0, short arg1, int arg2, bool arg3, unsigned arg4);
    [[maybe_unused]] int method2(bool arg0, int arg1, bool arg2, float arg3, int arg4);

    [[maybe_unused]] float memberVariable0{};
    [[maybe_unused]] unsigned memberVariable1{};
    [[maybe_unused]] bool memberVariable2{};

    [[maybe_unused]] static void function0(short arg0, int arg1, int arg2, double arg3, double arg4);
    [[maybe_unused]] static void function1(float arg0, short arg1, int arg2, bool arg3, bool arg4);
    [[maybe_unused]] static int function2(double arg0, int arg1, unsigned arg2, short arg3, int arg4);

    [[maybe_unused]] inline static unsigned variable0{};
    [[maybe_unused]] inline static float variable1{};
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
