#pragma once

// Generated with seed '88005553983'

#include "../../Common.h"


class ClassWithBindings448
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
    [[maybe_unused]] bool method0(bool arg0, double arg1, unsigned arg2, unsigned arg3, float arg4);
    [[maybe_unused]] bool method1(int arg0, bool arg1, unsigned arg2, bool arg3, float arg4);
    [[maybe_unused]] void method2(int arg0, unsigned arg1, short arg2, short arg3, float arg4);

    [[maybe_unused]] short memberVariable0{};
    [[maybe_unused]] double memberVariable1{};
    [[maybe_unused]] double memberVariable2{};

    [[maybe_unused]] static unsigned function0(double arg0, double arg1, bool arg2, double arg3, unsigned arg4);
    [[maybe_unused]] static double function1(bool arg0, unsigned arg1, unsigned arg2, double arg3, short arg4);
    [[maybe_unused]] static unsigned function2(double arg0, short arg1, unsigned arg2, unsigned arg3, unsigned arg4);

    [[maybe_unused]] inline static short variable0{};
    [[maybe_unused]] inline static short variable1{};
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
