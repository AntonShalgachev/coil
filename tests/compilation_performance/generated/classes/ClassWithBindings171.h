#pragma once

// Generated with seed '88005553706'

#include "../../Common.h"


class ClassWithBindings171
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
    [[maybe_unused]] void method0(int arg0, float arg1, short arg2, float arg3, unsigned arg4);
    [[maybe_unused]] void method1(short arg0, short arg1, unsigned arg2, double arg3, float arg4);
    [[maybe_unused]] void method2(unsigned arg0, unsigned arg1, bool arg2, double arg3, int arg4);
    [[maybe_unused]] bool method3(float arg0, unsigned arg1, short arg2, bool arg3, double arg4);
    [[maybe_unused]] bool method4(int arg0, bool arg1, double arg2, int arg3, unsigned arg4);
    [[maybe_unused]] short method5(bool arg0, short arg1, int arg2, bool arg3, int arg4);
    [[maybe_unused]] void method6(short arg0, short arg1, int arg2, float arg3, float arg4);
    [[maybe_unused]] int method7(double arg0, short arg1, int arg2, unsigned arg3, float arg4);
    [[maybe_unused]] bool method8(short arg0, bool arg1, double arg2, double arg3, unsigned arg4);
    [[maybe_unused]] int method9(int arg0, short arg1, double arg2, float arg3, unsigned arg4);

    [[maybe_unused]] double memberVariable0{};
    [[maybe_unused]] short memberVariable1{};
    [[maybe_unused]] short memberVariable2{};
    [[maybe_unused]] bool memberVariable3{};
    [[maybe_unused]] int memberVariable4{};
    [[maybe_unused]] int memberVariable5{};
    [[maybe_unused]] int memberVariable6{};
    [[maybe_unused]] bool memberVariable7{};
    [[maybe_unused]] bool memberVariable8{};
    [[maybe_unused]] int memberVariable9{};

    [[maybe_unused]] static void function0(unsigned arg0, bool arg1, int arg2, unsigned arg3, int arg4);
    [[maybe_unused]] static void function1(int arg0, double arg1, float arg2, float arg3, unsigned arg4);
    [[maybe_unused]] static void function2(float arg0, unsigned arg1, bool arg2, bool arg3, float arg4);
    [[maybe_unused]] static void function3(float arg0, double arg1, short arg2, unsigned arg3, float arg4);
    [[maybe_unused]] static void function4(short arg0, float arg1, int arg2, bool arg3, short arg4);
    [[maybe_unused]] static void function5(short arg0, double arg1, short arg2, short arg3, bool arg4);
    [[maybe_unused]] static void function6(short arg0, double arg1, float arg2, float arg3, float arg4);
    [[maybe_unused]] static double function7(float arg0, double arg1, double arg2, double arg3, int arg4);
    [[maybe_unused]] static int function8(short arg0, float arg1, float arg2, bool arg3, int arg4);
    [[maybe_unused]] static void function9(int arg0, bool arg1, unsigned arg2, int arg3, bool arg4);

    [[maybe_unused]] inline static unsigned variable0{};
    [[maybe_unused]] inline static int variable1{};
    [[maybe_unused]] inline static int variable2{};
    [[maybe_unused]] inline static short variable3{};
    [[maybe_unused]] inline static bool variable4{};
    [[maybe_unused]] inline static bool variable5{};
    [[maybe_unused]] inline static int variable6{};
    [[maybe_unused]] inline static double variable7{};
    [[maybe_unused]] inline static float variable8{};
    [[maybe_unused]] inline static int variable9{};

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
