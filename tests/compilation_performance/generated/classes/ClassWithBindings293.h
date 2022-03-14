#pragma once

// Generated with seed '88005553828'

#include "../../Common.h"


class ClassWithBindings293
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
    [[maybe_unused]] void method0(unsigned arg0, bool arg1, unsigned arg2, int arg3, short arg4);
    [[maybe_unused]] float method1(int arg0, float arg1, int arg2, int arg3, unsigned arg4);
    [[maybe_unused]] unsigned method2(int arg0, int arg1, unsigned arg2, bool arg3, bool arg4);

    [[maybe_unused]] float memberVariable0{};
    [[maybe_unused]] short memberVariable1{};
    [[maybe_unused]] float memberVariable2{};

    [[maybe_unused]] static void function0(short arg0, bool arg1, unsigned arg2, short arg3, unsigned arg4);
    [[maybe_unused]] static int function1(bool arg0, int arg1, int arg2, short arg3, int arg4);
    [[maybe_unused]] static short function2(unsigned arg0, double arg1, short arg2, unsigned arg3, bool arg4);

    [[maybe_unused]] inline static float variable0{};
    [[maybe_unused]] inline static short variable1{};
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