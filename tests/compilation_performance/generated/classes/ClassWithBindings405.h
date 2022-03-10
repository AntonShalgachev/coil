#pragma once

// Generated with seed '88005553940'

#include "../../Common.h"


class ClassWithBindings405
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
    [[maybe_unused]] unsigned method0(short arg0, bool arg1, unsigned arg2, float arg3, unsigned arg4);
    [[maybe_unused]] short method1(double arg0, short arg1, int arg2, float arg3, short arg4);
    [[maybe_unused]] void method2(short arg0, double arg1, unsigned arg2, float arg3, bool arg4);

    [[maybe_unused]] float memberVariable0{};
    [[maybe_unused]] short memberVariable1{};
    [[maybe_unused]] short memberVariable2{};

    [[maybe_unused]] static double function0(double arg0, unsigned arg1, unsigned arg2, int arg3, bool arg4);
    [[maybe_unused]] static short function1(float arg0, float arg1, int arg2, short arg3, float arg4);
    [[maybe_unused]] static unsigned function2(unsigned arg0, double arg1, unsigned arg2, float arg3, unsigned arg4);

    [[maybe_unused]] inline static int variable0{};
    [[maybe_unused]] inline static unsigned variable1{};
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
