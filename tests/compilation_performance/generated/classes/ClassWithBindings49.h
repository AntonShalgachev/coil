#pragma once

// Generated with seed '88005553584'

#include "../../Common.h"


class ClassWithBindings49
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
    [[maybe_unused]] void method0(unsigned arg0, bool arg1, int arg2, short arg3, int arg4);
    [[maybe_unused]] double method1(unsigned arg0, double arg1, short arg2, float arg3, bool arg4);
    [[maybe_unused]] int method2(int arg0, bool arg1, float arg2, short arg3, unsigned arg4);
    [[maybe_unused]] void method3(short arg0, float arg1, double arg2, unsigned arg3, short arg4);
    [[maybe_unused]] bool method4(double arg0, bool arg1, double arg2, int arg3, float arg4);
    [[maybe_unused]] short method5(double arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    [[maybe_unused]] void method6(short arg0, int arg1, float arg2, unsigned arg3, int arg4);
    [[maybe_unused]] double method7(double arg0, float arg1, unsigned arg2, double arg3, double arg4);
    [[maybe_unused]] void method8(int arg0, double arg1, unsigned arg2, bool arg3, int arg4);
    [[maybe_unused]] void method9(double arg0, double arg1, unsigned arg2, float arg3, float arg4);

    [[maybe_unused]] float memberVariable0{};
    [[maybe_unused]] short memberVariable1{};
    [[maybe_unused]] double memberVariable2{};
    [[maybe_unused]] short memberVariable3{};
    [[maybe_unused]] unsigned memberVariable4{};
    [[maybe_unused]] short memberVariable5{};
    [[maybe_unused]] unsigned memberVariable6{};
    [[maybe_unused]] float memberVariable7{};
    [[maybe_unused]] short memberVariable8{};
    [[maybe_unused]] unsigned memberVariable9{};

    [[maybe_unused]] static void function0(double arg0, short arg1, short arg2, float arg3, double arg4);
    [[maybe_unused]] static void function1(bool arg0, double arg1, bool arg2, unsigned arg3, unsigned arg4);
    [[maybe_unused]] static void function2(double arg0, double arg1, float arg2, unsigned arg3, float arg4);
    [[maybe_unused]] static double function3(short arg0, unsigned arg1, double arg2, bool arg3, double arg4);
    [[maybe_unused]] static float function4(int arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    [[maybe_unused]] static float function5(bool arg0, int arg1, float arg2, bool arg3, float arg4);
    [[maybe_unused]] static void function6(float arg0, int arg1, float arg2, int arg3, double arg4);
    [[maybe_unused]] static void function7(float arg0, bool arg1, short arg2, float arg3, double arg4);
    [[maybe_unused]] static void function8(int arg0, unsigned arg1, unsigned arg2, bool arg3, double arg4);
    [[maybe_unused]] static void function9(int arg0, double arg1, bool arg2, short arg3, float arg4);

    [[maybe_unused]] inline static bool variable0{};
    [[maybe_unused]] inline static float variable1{};
    [[maybe_unused]] inline static float variable2{};
    [[maybe_unused]] inline static bool variable3{};
    [[maybe_unused]] inline static bool variable4{};
    [[maybe_unused]] inline static short variable5{};
    [[maybe_unused]] inline static short variable6{};
    [[maybe_unused]] inline static short variable7{};
    [[maybe_unused]] inline static short variable8{};
    [[maybe_unused]] inline static short variable9{};

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
