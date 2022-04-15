#pragma once

// Generated with seed '88005553535'

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
    [[maybe_unused]] void method0();
    [[maybe_unused]] void method1();
    [[maybe_unused]] void method2();
    [[maybe_unused]] void method3();
    [[maybe_unused]] short method4(short arg0);
    [[maybe_unused]] void method5(double arg0);
    [[maybe_unused]] void method6(short arg0);
    [[maybe_unused]] double method7(double arg0);
    [[maybe_unused]] short method8(short arg0, unsigned arg1);
    [[maybe_unused]] void method9(bool arg0, bool arg1);
    [[maybe_unused]] void method10(bool arg0, unsigned arg1);
    [[maybe_unused]] void method11(int arg0, float arg1);

    [[maybe_unused]] short memberVariable0{};
    [[maybe_unused]] bool memberVariable1{};
    [[maybe_unused]] bool memberVariable2{};
    [[maybe_unused]] short memberVariable3{};
    [[maybe_unused]] bool memberVariable4{};
    [[maybe_unused]] int memberVariable5{};
    [[maybe_unused]] unsigned memberVariable6{};
    [[maybe_unused]] float memberVariable7{};
    [[maybe_unused]] short memberVariable8{};
    [[maybe_unused]] int memberVariable9{};

    [[maybe_unused]] static void function0();
    [[maybe_unused]] static void function1();
    [[maybe_unused]] static void function2();
    [[maybe_unused]] static void function3();
    [[maybe_unused]] static float function4(float arg0);
    [[maybe_unused]] static void function5(int arg0);
    [[maybe_unused]] static double function6(double arg0);
    [[maybe_unused]] static int function7(int arg0);
    [[maybe_unused]] static void function8(short arg0, int arg1);
    [[maybe_unused]] static void function9(int arg0, double arg1);
    [[maybe_unused]] static void function10(double arg0, int arg1);
    [[maybe_unused]] static void function11(double arg0, int arg1);

    [[maybe_unused]] inline static float variable0{};
    [[maybe_unused]] inline static bool variable1{};
    [[maybe_unused]] inline static double variable2{};
    [[maybe_unused]] inline static short variable3{};
    [[maybe_unused]] inline static double variable4{};
    [[maybe_unused]] inline static unsigned variable5{};
    [[maybe_unused]] inline static unsigned variable6{};
    [[maybe_unused]] inline static int variable7{};
    [[maybe_unused]] inline static short variable8{};
    [[maybe_unused]] inline static unsigned variable9{};

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
    std::string method10Command(std::vector<std::string> const& arguments);
    std::string method11Command(std::vector<std::string> const& arguments);

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
    static std::string function10Command(std::vector<std::string> const& arguments);
    static std::string function11Command(std::vector<std::string> const& arguments);

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
