#pragma once

// Generated with seed '88005553923'

#include "../../Common.h"


class ClassWithBindings388
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
    [[maybe_unused]] void method0(float arg0, double arg1, bool arg2, int arg3, short arg4);
    [[maybe_unused]] void method1(unsigned arg0, unsigned arg1, float arg2, int arg3, double arg4);
    [[maybe_unused]] void method2(double arg0, double arg1, double arg2, float arg3, double arg4);

    [[maybe_unused]] double memberVariable0{};
    [[maybe_unused]] double memberVariable1{};
    [[maybe_unused]] bool memberVariable2{};

    [[maybe_unused]] static unsigned function0(float arg0, double arg1, float arg2, unsigned arg3, double arg4);
    [[maybe_unused]] static short function1(unsigned arg0, unsigned arg1, float arg2, short arg3, bool arg4);
    [[maybe_unused]] static unsigned function2(float arg0, float arg1, bool arg2, short arg3, unsigned arg4);

    [[maybe_unused]] inline static int variable0{};
    [[maybe_unused]] inline static double variable1{};
    [[maybe_unused]] inline static double variable2{};

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