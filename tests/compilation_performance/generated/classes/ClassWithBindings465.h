#pragma once

// Generated with seed '88005554000'

#include "../../Common.h"


class ClassWithBindings465
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
    [[maybe_unused]] double method0(int arg0, bool arg1, int arg2, bool arg3, double arg4);
    [[maybe_unused]] int method1(int arg0, bool arg1, unsigned arg2, float arg3, unsigned arg4);
    [[maybe_unused]] void method2(int arg0, float arg1, short arg2, short arg3, double arg4);

    [[maybe_unused]] int memberVariable0{};
    [[maybe_unused]] double memberVariable1{};
    [[maybe_unused]] float memberVariable2{};

    [[maybe_unused]] static void function0(short arg0, bool arg1, int arg2, double arg3, double arg4);
    [[maybe_unused]] static unsigned function1(double arg0, unsigned arg1, float arg2, float arg3, double arg4);
    [[maybe_unused]] static bool function2(double arg0, float arg1, int arg2, float arg3, bool arg4);

    [[maybe_unused]] inline static float variable0{};
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
