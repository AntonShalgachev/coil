#pragma once

// Generated with seed '88005553739'

#include "../../Common.h"


class ClassWithBindings204
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
    [[maybe_unused]] unsigned method0(unsigned arg0, unsigned arg1, unsigned arg2, double arg3, double arg4);
    [[maybe_unused]] int method1(float arg0, int arg1, double arg2, double arg3, double arg4);
    [[maybe_unused]] void method2(short arg0, float arg1, unsigned arg2, short arg3, bool arg4);

    [[maybe_unused]] double memberVariable0{};
    [[maybe_unused]] float memberVariable1{};
    [[maybe_unused]] int memberVariable2{};

    [[maybe_unused]] static void function0(float arg0, double arg1, double arg2, float arg3, float arg4);
    [[maybe_unused]] static int function1(double arg0, float arg1, short arg2, int arg3, unsigned arg4);
    [[maybe_unused]] static float function2(int arg0, bool arg1, int arg2, int arg3, float arg4);

    [[maybe_unused]] inline static int variable0{};
    [[maybe_unused]] inline static bool variable1{};
    [[maybe_unused]] inline static unsigned variable2{};

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
