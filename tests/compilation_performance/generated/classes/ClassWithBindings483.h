#pragma once

// Generated with seed '88005554018'

#include "../../Common.h"


class ClassWithBindings483
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
    [[maybe_unused]] double method0(float arg0, float arg1, bool arg2, unsigned arg3, double arg4);
    [[maybe_unused]] void method1(unsigned arg0, unsigned arg1, int arg2, bool arg3, short arg4);
    [[maybe_unused]] int method2(unsigned arg0, double arg1, bool arg2, bool arg3, int arg4);

    [[maybe_unused]] double memberVariable0{};
    [[maybe_unused]] double memberVariable1{};
    [[maybe_unused]] float memberVariable2{};

    [[maybe_unused]] static bool function0(short arg0, short arg1, unsigned arg2, bool arg3, bool arg4);
    [[maybe_unused]] static int function1(bool arg0, unsigned arg1, bool arg2, float arg3, int arg4);
    [[maybe_unused]] static double function2(int arg0, double arg1, bool arg2, bool arg3, double arg4);

    [[maybe_unused]] inline static int variable0{};
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
