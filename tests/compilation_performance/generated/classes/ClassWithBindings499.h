#pragma once

// Generated with seed '88005554034'

#include "../../Common.h"


class ClassWithBindings499
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
    [[maybe_unused]] double method0(double arg0, unsigned arg1, float arg2, double arg3, int arg4);
    [[maybe_unused]] int method1(float arg0, int arg1, double arg2, bool arg3, int arg4);
    [[maybe_unused]] void method2(unsigned arg0, float arg1, float arg2, short arg3, short arg4);

    [[maybe_unused]] bool memberVariable0{};
    [[maybe_unused]] float memberVariable1{};
    [[maybe_unused]] double memberVariable2{};

    [[maybe_unused]] static void function0(double arg0, unsigned arg1, unsigned arg2, int arg3, int arg4);
    [[maybe_unused]] static unsigned function1(unsigned arg0, double arg1, bool arg2, bool arg3, unsigned arg4);
    [[maybe_unused]] static short function2(double arg0, unsigned arg1, short arg2, short arg3, int arg4);

    [[maybe_unused]] inline static int variable0{};
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
