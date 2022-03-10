#pragma once

// Generated with seed '88005553544'

#include "../../Common.h"


class ClassWithBindings9
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
    [[maybe_unused]] void method0(float arg0, bool arg1, double arg2, double arg3, bool arg4);
    [[maybe_unused]] float method1(bool arg0, float arg1, float arg2, bool arg3, int arg4);
    [[maybe_unused]] bool method2(float arg0, float arg1, bool arg2, double arg3, bool arg4);

    [[maybe_unused]] double memberVariable0{};
    [[maybe_unused]] double memberVariable1{};
    [[maybe_unused]] float memberVariable2{};

    [[maybe_unused]] static double function0(int arg0, unsigned arg1, double arg2, short arg3, float arg4);
    [[maybe_unused]] static unsigned function1(short arg0, int arg1, unsigned arg2, unsigned arg3, float arg4);
    [[maybe_unused]] static short function2(double arg0, short arg1, bool arg2, short arg3, bool arg4);

    [[maybe_unused]] inline static float variable0{};
    [[maybe_unused]] inline static unsigned variable1{};
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
