#pragma once

// Generated with seed '88005553777'

#include "../../Common.h"


class ClassWithBindings242
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
    [[maybe_unused]] double method0(double arg0, unsigned arg1, unsigned arg2, float arg3, double arg4);
    [[maybe_unused]] void method1(float arg0, double arg1, short arg2, double arg3, bool arg4);
    [[maybe_unused]] void method2(bool arg0, short arg1, double arg2, bool arg3, unsigned arg4);

    [[maybe_unused]] short memberVariable0{};
    [[maybe_unused]] bool memberVariable1{};
    [[maybe_unused]] float memberVariable2{};

    [[maybe_unused]] static void function0(bool arg0, float arg1, double arg2, double arg3, bool arg4);
    [[maybe_unused]] static bool function1(float arg0, int arg1, double arg2, bool arg3, double arg4);
    [[maybe_unused]] static double function2(double arg0, short arg1, short arg2, double arg3, float arg4);

    [[maybe_unused]] inline static int variable0{};
    [[maybe_unused]] inline static short variable1{};
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
