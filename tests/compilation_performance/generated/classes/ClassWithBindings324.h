#pragma once

// Generated with seed '88005553859'

#include "../../Common.h"


class ClassWithBindings324
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
    [[maybe_unused]] void method0(float arg0, int arg1, int arg2, bool arg3, unsigned arg4);
    [[maybe_unused]] double method1(bool arg0, bool arg1, float arg2, double arg3, double arg4);
    [[maybe_unused]] int method2(int arg0, int arg1, bool arg2, short arg3, float arg4);

    [[maybe_unused]] short memberVariable0{};
    [[maybe_unused]] double memberVariable1{};
    [[maybe_unused]] unsigned memberVariable2{};

    [[maybe_unused]] static short function0(double arg0, bool arg1, bool arg2, short arg3, unsigned arg4);
    [[maybe_unused]] static unsigned function1(unsigned arg0, int arg1, bool arg2, int arg3, bool arg4);
    [[maybe_unused]] static void function2(double arg0, bool arg1, float arg2, unsigned arg3, short arg4);

    [[maybe_unused]] inline static double variable0{};
    [[maybe_unused]] inline static int variable1{};
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
