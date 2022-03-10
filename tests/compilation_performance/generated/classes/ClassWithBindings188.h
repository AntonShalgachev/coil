#pragma once

// Generated with seed '88005553723'

#include "../../Common.h"


class ClassWithBindings188
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
    [[maybe_unused]] void method0(float arg0, float arg1, float arg2, unsigned arg3, float arg4);
    [[maybe_unused]] unsigned method1(bool arg0, float arg1, unsigned arg2, double arg3, unsigned arg4);
    [[maybe_unused]] float method2(float arg0, int arg1, unsigned arg2, double arg3, short arg4);

    [[maybe_unused]] unsigned memberVariable0{};
    [[maybe_unused]] double memberVariable1{};
    [[maybe_unused]] float memberVariable2{};

    [[maybe_unused]] static bool function0(short arg0, unsigned arg1, int arg2, int arg3, bool arg4);
    [[maybe_unused]] static unsigned function1(double arg0, unsigned arg1, float arg2, unsigned arg3, float arg4);
    [[maybe_unused]] static float function2(short arg0, int arg1, float arg2, double arg3, float arg4);

    [[maybe_unused]] inline static int variable0{};
    [[maybe_unused]] inline static int variable1{};
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
