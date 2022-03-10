#pragma once

// Generated with seed '88005553645'

#include "../../Common.h"


class ClassWithBindings110
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
    [[maybe_unused]] bool method0(int arg0, float arg1, bool arg2, float arg3, unsigned arg4);
    [[maybe_unused]] float method1(bool arg0, int arg1, float arg2, short arg3, double arg4);
    [[maybe_unused]] bool method2(float arg0, bool arg1, double arg2, int arg3, bool arg4);

    [[maybe_unused]] int memberVariable0{};
    [[maybe_unused]] short memberVariable1{};
    [[maybe_unused]] short memberVariable2{};

    [[maybe_unused]] static unsigned function0(bool arg0, short arg1, unsigned arg2, float arg3, float arg4);
    [[maybe_unused]] static short function1(double arg0, short arg1, float arg2, float arg3, bool arg4);
    [[maybe_unused]] static void function2(double arg0, unsigned arg1, bool arg2, float arg3, int arg4);

    [[maybe_unused]] inline static short variable0{};
    [[maybe_unused]] inline static float variable1{};
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
