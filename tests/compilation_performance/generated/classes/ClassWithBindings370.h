#pragma once

// Generated with seed '88005553905'

#include "../../Common.h"


class ClassWithBindings370
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
    [[maybe_unused]] unsigned method0(short arg0, unsigned arg1, double arg2, short arg3, unsigned arg4);
    [[maybe_unused]] short method1(short arg0, double arg1, bool arg2, double arg3, short arg4);
    [[maybe_unused]] float method2(float arg0, float arg1, short arg2, double arg3, int arg4);

    [[maybe_unused]] bool memberVariable0{};
    [[maybe_unused]] double memberVariable1{};
    [[maybe_unused]] double memberVariable2{};

    [[maybe_unused]] static int function0(double arg0, int arg1, unsigned arg2, double arg3, int arg4);
    [[maybe_unused]] static bool function1(int arg0, bool arg1, unsigned arg2, bool arg3, int arg4);
    [[maybe_unused]] static short function2(short arg0, float arg1, short arg2, bool arg3, double arg4);

    [[maybe_unused]] inline static short variable0{};
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