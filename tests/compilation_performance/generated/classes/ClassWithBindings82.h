#pragma once

// Generated with seed '88005553617'

#include "../../Common.h"


class ClassWithBindings82
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
    [[maybe_unused]] float method0(short arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    [[maybe_unused]] float method1(unsigned arg0, float arg1, float arg2, int arg3, double arg4);
    [[maybe_unused]] void method2(unsigned arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    [[maybe_unused]] unsigned method3(unsigned arg0, unsigned arg1, float arg2, bool arg3, int arg4);
    [[maybe_unused]] bool method4(float arg0, int arg1, bool arg2, int arg3, bool arg4);
    [[maybe_unused]] short method5(float arg0, float arg1, short arg2, short arg3, double arg4);
    [[maybe_unused]] void method6(short arg0, bool arg1, double arg2, short arg3, int arg4);
    [[maybe_unused]] unsigned method7(short arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    [[maybe_unused]] unsigned method8(bool arg0, unsigned arg1, double arg2, int arg3, bool arg4);
    [[maybe_unused]] unsigned method9(double arg0, unsigned arg1, double arg2, bool arg3, unsigned arg4);

    [[maybe_unused]] unsigned memberVariable0{};
    [[maybe_unused]] unsigned memberVariable1{};
    [[maybe_unused]] unsigned memberVariable2{};
    [[maybe_unused]] bool memberVariable3{};
    [[maybe_unused]] int memberVariable4{};
    [[maybe_unused]] bool memberVariable5{};
    [[maybe_unused]] short memberVariable6{};
    [[maybe_unused]] unsigned memberVariable7{};
    [[maybe_unused]] float memberVariable8{};
    [[maybe_unused]] int memberVariable9{};

    [[maybe_unused]] static double function0(double arg0, unsigned arg1, double arg2, float arg3, double arg4);
    [[maybe_unused]] static void function1(short arg0, short arg1, float arg2, unsigned arg3, double arg4);
    [[maybe_unused]] static void function2(unsigned arg0, unsigned arg1, unsigned arg2, int arg3, unsigned arg4);
    [[maybe_unused]] static void function3(int arg0, float arg1, bool arg2, short arg3, double arg4);
    [[maybe_unused]] static void function4(unsigned arg0, short arg1, int arg2, double arg3, int arg4);
    [[maybe_unused]] static unsigned function5(int arg0, unsigned arg1, double arg2, int arg3, unsigned arg4);
    [[maybe_unused]] static void function6(unsigned arg0, unsigned arg1, float arg2, double arg3, bool arg4);
    [[maybe_unused]] static bool function7(unsigned arg0, bool arg1, bool arg2, short arg3, double arg4);
    [[maybe_unused]] static unsigned function8(unsigned arg0, bool arg1, double arg2, double arg3, float arg4);
    [[maybe_unused]] static void function9(unsigned arg0, int arg1, short arg2, float arg3, double arg4);

    [[maybe_unused]] inline static unsigned variable0{};
    [[maybe_unused]] inline static unsigned variable1{};
    [[maybe_unused]] inline static float variable2{};
    [[maybe_unused]] inline static int variable3{};
    [[maybe_unused]] inline static short variable4{};
    [[maybe_unused]] inline static short variable5{};
    [[maybe_unused]] inline static int variable6{};
    [[maybe_unused]] inline static int variable7{};
    [[maybe_unused]] inline static short variable8{};
    [[maybe_unused]] inline static double variable9{};

#if USE_MANUAL
    std::string method0Command(std::vector<std::string> const& arguments);
    std::string method1Command(std::vector<std::string> const& arguments);
    std::string method2Command(std::vector<std::string> const& arguments);
    std::string method3Command(std::vector<std::string> const& arguments);
    std::string method4Command(std::vector<std::string> const& arguments);
    std::string method5Command(std::vector<std::string> const& arguments);
    std::string method6Command(std::vector<std::string> const& arguments);
    std::string method7Command(std::vector<std::string> const& arguments);
    std::string method8Command(std::vector<std::string> const& arguments);
    std::string method9Command(std::vector<std::string> const& arguments);

    std::string memberVariable0Command(std::vector<std::string> const& arguments);
    std::string memberVariable1Command(std::vector<std::string> const& arguments);
    std::string memberVariable2Command(std::vector<std::string> const& arguments);
    std::string memberVariable3Command(std::vector<std::string> const& arguments);
    std::string memberVariable4Command(std::vector<std::string> const& arguments);
    std::string memberVariable5Command(std::vector<std::string> const& arguments);
    std::string memberVariable6Command(std::vector<std::string> const& arguments);
    std::string memberVariable7Command(std::vector<std::string> const& arguments);
    std::string memberVariable8Command(std::vector<std::string> const& arguments);
    std::string memberVariable9Command(std::vector<std::string> const& arguments);

    static std::string function0Command(std::vector<std::string> const& arguments);
    static std::string function1Command(std::vector<std::string> const& arguments);
    static std::string function2Command(std::vector<std::string> const& arguments);
    static std::string function3Command(std::vector<std::string> const& arguments);
    static std::string function4Command(std::vector<std::string> const& arguments);
    static std::string function5Command(std::vector<std::string> const& arguments);
    static std::string function6Command(std::vector<std::string> const& arguments);
    static std::string function7Command(std::vector<std::string> const& arguments);
    static std::string function8Command(std::vector<std::string> const& arguments);
    static std::string function9Command(std::vector<std::string> const& arguments);

    static std::string variable0Command(std::vector<std::string> const& arguments);
    static std::string variable1Command(std::vector<std::string> const& arguments);
    static std::string variable2Command(std::vector<std::string> const& arguments);
    static std::string variable3Command(std::vector<std::string> const& arguments);
    static std::string variable4Command(std::vector<std::string> const& arguments);
    static std::string variable5Command(std::vector<std::string> const& arguments);
    static std::string variable6Command(std::vector<std::string> const& arguments);
    static std::string variable7Command(std::vector<std::string> const& arguments);
    static std::string variable8Command(std::vector<std::string> const& arguments);
    static std::string variable9Command(std::vector<std::string> const& arguments);
#endif
};
