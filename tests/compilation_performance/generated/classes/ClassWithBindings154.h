#pragma once

// Generated with seed '88005553689'

#include "../../Common.h"


class ClassWithBindings154
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
    [[maybe_unused]] void method0(double arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
    [[maybe_unused]] void method1(unsigned arg0, unsigned arg1, int arg2, double arg3, int arg4);
    [[maybe_unused]] float method2(int arg0, int arg1, unsigned arg2, bool arg3, float arg4);

    [[maybe_unused]] short memberVariable0{};
    [[maybe_unused]] bool memberVariable1{};
    [[maybe_unused]] float memberVariable2{};

    [[maybe_unused]] static void function0(bool arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
    [[maybe_unused]] static void function1(float arg0, unsigned arg1, double arg2, unsigned arg3, double arg4);
    [[maybe_unused]] static float function2(unsigned arg0, short arg1, bool arg2, short arg3, float arg4);

    [[maybe_unused]] inline static short variable0{};
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
