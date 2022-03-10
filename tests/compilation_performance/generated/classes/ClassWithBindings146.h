#pragma once

// Generated with seed '88005553681'

#include "../../Common.h"


class ClassWithBindings146
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
    [[maybe_unused]] double method0(unsigned arg0, int arg1, unsigned arg2, int arg3, double arg4);
    [[maybe_unused]] short method1(short arg0, double arg1, bool arg2, float arg3, short arg4);
    [[maybe_unused]] unsigned method2(short arg0, bool arg1, unsigned arg2, float arg3, unsigned arg4);

    [[maybe_unused]] double memberVariable0{};
    [[maybe_unused]] float memberVariable1{};
    [[maybe_unused]] float memberVariable2{};

    [[maybe_unused]] static double function0(short arg0, double arg1, double arg2, float arg3, float arg4);
    [[maybe_unused]] static void function1(float arg0, unsigned arg1, bool arg2, bool arg3, short arg4);
    [[maybe_unused]] static void function2(float arg0, double arg1, float arg2, int arg3, float arg4);

    [[maybe_unused]] inline static short variable0{};
    [[maybe_unused]] inline static double variable1{};
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
