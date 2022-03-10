#pragma once

// Generated with seed '88005553696'

#include "../../Common.h"


class ClassWithBindings161
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
    [[maybe_unused]] float method0(float arg0, short arg1, float arg2, short arg3, bool arg4);
    [[maybe_unused]] void method1(short arg0, int arg1, bool arg2, int arg3, short arg4);
    [[maybe_unused]] void method2(short arg0, int arg1, bool arg2, double arg3, short arg4);

    [[maybe_unused]] int memberVariable0{};
    [[maybe_unused]] float memberVariable1{};
    [[maybe_unused]] float memberVariable2{};

    [[maybe_unused]] static bool function0(unsigned arg0, float arg1, int arg2, bool arg3, short arg4);
    [[maybe_unused]] static void function1(double arg0, double arg1, int arg2, float arg3, short arg4);
    [[maybe_unused]] static bool function2(double arg0, short arg1, bool arg2, int arg3, unsigned arg4);

    [[maybe_unused]] inline static int variable0{};
    [[maybe_unused]] inline static bool variable1{};
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
