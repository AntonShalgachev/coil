#pragma once

// Generated with seed '88005553583'

#include "../../Common.h"


class ClassWithBindings48
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
    [[maybe_unused]] void method0(float arg0, int arg1, short arg2, int arg3, double arg4);
    [[maybe_unused]] int method1(double arg0, bool arg1, unsigned arg2, int arg3, int arg4);
    [[maybe_unused]] void method2(int arg0, double arg1, int arg2, float arg3, short arg4);

    [[maybe_unused]] double memberVariable0{};
    [[maybe_unused]] short memberVariable1{};
    [[maybe_unused]] unsigned memberVariable2{};

    [[maybe_unused]] static unsigned function0(unsigned arg0, int arg1, short arg2, int arg3, int arg4);
    [[maybe_unused]] static int function1(float arg0, int arg1, short arg2, double arg3, int arg4);
    [[maybe_unused]] static double function2(double arg0, double arg1, short arg2, float arg3, int arg4);

    [[maybe_unused]] inline static short variable0{};
    [[maybe_unused]] inline static bool variable1{};
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
