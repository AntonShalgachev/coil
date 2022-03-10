#pragma once

// Generated with seed '88005553547'

#include "../../Common.h"


class ClassWithBindings12
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
    [[maybe_unused]] bool method0(bool arg0, short arg1, int arg2, unsigned arg3, short arg4);
    [[maybe_unused]] void method1(bool arg0, short arg1, unsigned arg2, double arg3, int arg4);
    [[maybe_unused]] void method2(int arg0, int arg1, double arg2, float arg3, unsigned arg4);

    [[maybe_unused]] int memberVariable0{};
    [[maybe_unused]] bool memberVariable1{};
    [[maybe_unused]] float memberVariable2{};

    [[maybe_unused]] static int function0(int arg0, int arg1, double arg2, float arg3, double arg4);
    [[maybe_unused]] static void function1(short arg0, bool arg1, unsigned arg2, int arg3, bool arg4);
    [[maybe_unused]] static void function2(double arg0, short arg1, short arg2, bool arg3, short arg4);

    [[maybe_unused]] inline static float variable0{};
    [[maybe_unused]] inline static int variable1{};
    [[maybe_unused]] inline static float variable2{};

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
