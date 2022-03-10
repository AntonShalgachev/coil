#pragma once

// Generated with seed '88005553988'

#include "../../Common.h"


class ClassWithBindings453
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
    [[maybe_unused]] void method0(bool arg0, double arg1, bool arg2, int arg3, unsigned arg4);
    [[maybe_unused]] bool method1(bool arg0, unsigned arg1, short arg2, int arg3, double arg4);
    [[maybe_unused]] bool method2(unsigned arg0, unsigned arg1, bool arg2, float arg3, bool arg4);

    [[maybe_unused]] bool memberVariable0{};
    [[maybe_unused]] short memberVariable1{};
    [[maybe_unused]] unsigned memberVariable2{};

    [[maybe_unused]] static void function0(float arg0, unsigned arg1, int arg2, short arg3, float arg4);
    [[maybe_unused]] static void function1(float arg0, bool arg1, double arg2, float arg3, float arg4);
    [[maybe_unused]] static void function2(short arg0, bool arg1, int arg2, short arg3, bool arg4);

    [[maybe_unused]] inline static float variable0{};
    [[maybe_unused]] inline static double variable1{};
    [[maybe_unused]] inline static short variable2{};

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
