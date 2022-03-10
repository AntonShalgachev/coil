#pragma once

// Generated with seed '88005553944'

#include "../../Common.h"


class ClassWithBindings409
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
    [[maybe_unused]] short method0(bool arg0, int arg1, unsigned arg2, short arg3, bool arg4);
    [[maybe_unused]] void method1(float arg0, unsigned arg1, unsigned arg2, double arg3, bool arg4);
    [[maybe_unused]] void method2(float arg0, int arg1, int arg2, int arg3, double arg4);

    [[maybe_unused]] int memberVariable0{};
    [[maybe_unused]] double memberVariable1{};
    [[maybe_unused]] short memberVariable2{};

    [[maybe_unused]] static float function0(float arg0, int arg1, unsigned arg2, float arg3, short arg4);
    [[maybe_unused]] static int function1(float arg0, unsigned arg1, int arg2, int arg3, int arg4);
    [[maybe_unused]] static unsigned function2(double arg0, unsigned arg1, unsigned arg2, int arg3, bool arg4);

    [[maybe_unused]] inline static unsigned variable0{};
    [[maybe_unused]] inline static double variable1{};
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
