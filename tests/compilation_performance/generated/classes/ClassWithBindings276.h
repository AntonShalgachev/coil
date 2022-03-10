#pragma once

// Generated with seed '88005553811'

#include "../../Common.h"


class ClassWithBindings276
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
    [[maybe_unused]] void method0(short arg0, float arg1, unsigned arg2, short arg3, double arg4);
    [[maybe_unused]] short method1(bool arg0, short arg1, float arg2, double arg3, int arg4);
    [[maybe_unused]] void method2(double arg0, unsigned arg1, bool arg2, int arg3, double arg4);

    [[maybe_unused]] short memberVariable0{};
    [[maybe_unused]] float memberVariable1{};
    [[maybe_unused]] int memberVariable2{};

    [[maybe_unused]] static void function0(int arg0, float arg1, double arg2, bool arg3, double arg4);
    [[maybe_unused]] static double function1(double arg0, double arg1, double arg2, int arg3, double arg4);
    [[maybe_unused]] static bool function2(short arg0, bool arg1, int arg2, unsigned arg3, int arg4);

    [[maybe_unused]] inline static double variable0{};
    [[maybe_unused]] inline static short variable1{};
    [[maybe_unused]] inline static int variable2{};

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
