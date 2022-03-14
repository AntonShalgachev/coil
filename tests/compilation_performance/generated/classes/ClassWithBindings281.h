#pragma once

// Generated with seed '88005553816'

#include "../../Common.h"


class ClassWithBindings281
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
    [[maybe_unused]] short method0(float arg0, float arg1, double arg2, short arg3, int arg4);
    [[maybe_unused]] void method1(double arg0, int arg1, bool arg2, int arg3, float arg4);
    [[maybe_unused]] float method2(int arg0, unsigned arg1, int arg2, unsigned arg3, float arg4);

    [[maybe_unused]] float memberVariable0{};
    [[maybe_unused]] unsigned memberVariable1{};
    [[maybe_unused]] unsigned memberVariable2{};

    [[maybe_unused]] static void function0(short arg0, unsigned arg1, double arg2, bool arg3, short arg4);
    [[maybe_unused]] static void function1(bool arg0, int arg1, float arg2, double arg3, bool arg4);
    [[maybe_unused]] static bool function2(short arg0, float arg1, bool arg2, bool arg3, bool arg4);

    [[maybe_unused]] inline static bool variable0{};
    [[maybe_unused]] inline static bool variable1{};
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