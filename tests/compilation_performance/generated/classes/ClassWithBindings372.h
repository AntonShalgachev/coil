#pragma once

// Generated with seed '88005553907'

#include "../../Common.h"


class ClassWithBindings372
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
    [[maybe_unused]] double method0(double arg0, short arg1, double arg2, int arg3, double arg4);
    [[maybe_unused]] void method1(unsigned arg0, double arg1, int arg2, bool arg3, int arg4);
    [[maybe_unused]] bool method2(unsigned arg0, bool arg1, double arg2, int arg3, bool arg4);

    [[maybe_unused]] unsigned memberVariable0{};
    [[maybe_unused]] float memberVariable1{};
    [[maybe_unused]] short memberVariable2{};

    [[maybe_unused]] static short function0(unsigned arg0, short arg1, short arg2, unsigned arg3, bool arg4);
    [[maybe_unused]] static short function1(double arg0, short arg1, double arg2, bool arg3, float arg4);
    [[maybe_unused]] static bool function2(short arg0, int arg1, float arg2, bool arg3, bool arg4);

    [[maybe_unused]] inline static bool variable0{};
    [[maybe_unused]] inline static float variable1{};
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
