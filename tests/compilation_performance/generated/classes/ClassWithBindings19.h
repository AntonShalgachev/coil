#pragma once

// Generated with seed '88005553554'

#include "../../Common.h"


class ClassWithBindings19
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
    [[maybe_unused]] void method0(short arg0, bool arg1, short arg2, unsigned arg3, short arg4);
    [[maybe_unused]] int method1(float arg0, int arg1, int arg2, unsigned arg3, int arg4);
    [[maybe_unused]] void method2(int arg0, int arg1, bool arg2, short arg3, int arg4);

    [[maybe_unused]] float memberVariable0{};
    [[maybe_unused]] unsigned memberVariable1{};
    [[maybe_unused]] unsigned memberVariable2{};

    [[maybe_unused]] static double function0(double arg0, float arg1, unsigned arg2, int arg3, unsigned arg4);
    [[maybe_unused]] static int function1(unsigned arg0, double arg1, float arg2, int arg3, bool arg4);
    [[maybe_unused]] static void function2(int arg0, int arg1, float arg2, double arg3, float arg4);

    [[maybe_unused]] inline static int variable0{};
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
