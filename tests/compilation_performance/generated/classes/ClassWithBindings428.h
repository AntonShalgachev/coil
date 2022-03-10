#pragma once

// Generated with seed '88005553963'

#include "../../Common.h"


class ClassWithBindings428
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
    [[maybe_unused]] int method0(unsigned arg0, int arg1, short arg2, int arg3, float arg4);
    [[maybe_unused]] void method1(unsigned arg0, bool arg1, short arg2, int arg3, unsigned arg4);
    [[maybe_unused]] bool method2(bool arg0, bool arg1, float arg2, double arg3, double arg4);

    [[maybe_unused]] unsigned memberVariable0{};
    [[maybe_unused]] short memberVariable1{};
    [[maybe_unused]] float memberVariable2{};

    [[maybe_unused]] static void function0(float arg0, float arg1, int arg2, float arg3, short arg4);
    [[maybe_unused]] static short function1(bool arg0, bool arg1, unsigned arg2, double arg3, short arg4);
    [[maybe_unused]] static float function2(short arg0, float arg1, bool arg2, double arg3, double arg4);

    [[maybe_unused]] inline static bool variable0{};
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
