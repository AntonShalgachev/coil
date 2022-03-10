#pragma once

// Generated with seed '88005553846'

#include "../../Common.h"


class ClassWithBindings311
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
    [[maybe_unused]] float method0(int arg0, short arg1, float arg2, float arg3, double arg4);
    [[maybe_unused]] void method1(float arg0, int arg1, unsigned arg2, double arg3, short arg4);
    [[maybe_unused]] unsigned method2(float arg0, int arg1, unsigned arg2, float arg3, bool arg4);

    [[maybe_unused]] unsigned memberVariable0{};
    [[maybe_unused]] int memberVariable1{};
    [[maybe_unused]] bool memberVariable2{};

    [[maybe_unused]] static void function0(float arg0, float arg1, float arg2, int arg3, float arg4);
    [[maybe_unused]] static void function1(float arg0, double arg1, unsigned arg2, short arg3, unsigned arg4);
    [[maybe_unused]] static int function2(int arg0, int arg1, bool arg2, double arg3, int arg4);

    [[maybe_unused]] inline static unsigned variable0{};
    [[maybe_unused]] inline static int variable1{};
    [[maybe_unused]] inline static unsigned variable2{};

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
