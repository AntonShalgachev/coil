#pragma once

// Generated with seed '88005553717'

#include "../../Common.h"


class ClassWithBindings182
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
    [[maybe_unused]] double method0(float arg0, int arg1, double arg2, short arg3, bool arg4);
    [[maybe_unused]] double method1(short arg0, unsigned arg1, unsigned arg2, double arg3, unsigned arg4);
    [[maybe_unused]] unsigned method2(short arg0, int arg1, float arg2, double arg3, unsigned arg4);

    [[maybe_unused]] unsigned memberVariable0{};
    [[maybe_unused]] bool memberVariable1{};
    [[maybe_unused]] short memberVariable2{};

    [[maybe_unused]] static void function0(short arg0, short arg1, short arg2, unsigned arg3, bool arg4);
    [[maybe_unused]] static double function1(bool arg0, double arg1, double arg2, int arg3, unsigned arg4);
    [[maybe_unused]] static short function2(short arg0, double arg1, int arg2, unsigned arg3, short arg4);

    [[maybe_unused]] inline static int variable0{};
    [[maybe_unused]] inline static int variable1{};
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
