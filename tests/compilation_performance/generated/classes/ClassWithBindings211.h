#pragma once

// Generated with seed '88005553746'

#include "../../Common.h"


class ClassWithBindings211
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
    [[maybe_unused]] unsigned method0(unsigned arg0, short arg1, int arg2, double arg3, int arg4);
    [[maybe_unused]] float method1(bool arg0, float arg1, float arg2, short arg3, int arg4);
    [[maybe_unused]] float method2(float arg0, float arg1, unsigned arg2, int arg3, float arg4);

    [[maybe_unused]] unsigned memberVariable0{};
    [[maybe_unused]] short memberVariable1{};
    [[maybe_unused]] int memberVariable2{};

    [[maybe_unused]] static unsigned function0(unsigned arg0, unsigned arg1, float arg2, int arg3, float arg4);
    [[maybe_unused]] static void function1(float arg0, int arg1, float arg2, double arg3, double arg4);
    [[maybe_unused]] static short function2(int arg0, float arg1, double arg2, short arg3, float arg4);

    [[maybe_unused]] inline static double variable0{};
    [[maybe_unused]] inline static float variable1{};
    [[maybe_unused]] inline static double variable2{};

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
