#pragma once

// Generated with seed '88005553773'

#include "../../Common.h"


class ClassWithBindings238
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
    [[maybe_unused]] double method0(short arg0, double arg1, short arg2, bool arg3, short arg4);
    [[maybe_unused]] bool method1(short arg0, bool arg1, int arg2, unsigned arg3, int arg4);
    [[maybe_unused]] void method2(short arg0, bool arg1, double arg2, int arg3, int arg4);

    [[maybe_unused]] unsigned memberVariable0{};
    [[maybe_unused]] int memberVariable1{};
    [[maybe_unused]] double memberVariable2{};

    [[maybe_unused]] static double function0(unsigned arg0, double arg1, int arg2, unsigned arg3, double arg4);
    [[maybe_unused]] static bool function1(bool arg0, double arg1, double arg2, unsigned arg3, float arg4);
    [[maybe_unused]] static void function2(double arg0, double arg1, int arg2, bool arg3, double arg4);

    [[maybe_unused]] inline static float variable0{};
    [[maybe_unused]] inline static short variable1{};
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