#pragma once

// Generated with seed '88005553675'

#include "../../Common.h"


class ClassWithBindings140
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
    [[maybe_unused]] bool method0(double arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    [[maybe_unused]] double method1(unsigned arg0, bool arg1, bool arg2, double arg3, bool arg4);
    [[maybe_unused]] void method2(float arg0, bool arg1, int arg2, short arg3, short arg4);

    [[maybe_unused]] int memberVariable0{};
    [[maybe_unused]] float memberVariable1{};
    [[maybe_unused]] float memberVariable2{};

    [[maybe_unused]] static void function0(bool arg0, short arg1, short arg2, float arg3, bool arg4);
    [[maybe_unused]] static void function1(short arg0, float arg1, short arg2, unsigned arg3, unsigned arg4);
    [[maybe_unused]] static unsigned function2(bool arg0, int arg1, short arg2, unsigned arg3, unsigned arg4);

    [[maybe_unused]] inline static short variable0{};
    [[maybe_unused]] inline static double variable1{};
    [[maybe_unused]] inline static short variable2{};

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
