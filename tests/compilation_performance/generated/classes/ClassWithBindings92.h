#pragma once

// Generated with seed '88005553627'

#include "../../Common.h"


class ClassWithBindings92
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
    [[maybe_unused]] void method0(int arg0, double arg1, double arg2, short arg3, int arg4);
    [[maybe_unused]] void method1(int arg0, unsigned arg1, short arg2, unsigned arg3, float arg4);
    [[maybe_unused]] short method2(unsigned arg0, float arg1, short arg2, bool arg3, short arg4);
    [[maybe_unused]] void method3(int arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    [[maybe_unused]] void method4(short arg0, float arg1, unsigned arg2, bool arg3, short arg4);
    [[maybe_unused]] short method5(short arg0, unsigned arg1, short arg2, int arg3, unsigned arg4);
    [[maybe_unused]] unsigned method6(unsigned arg0, float arg1, int arg2, unsigned arg3, unsigned arg4);
    [[maybe_unused]] short method7(float arg0, float arg1, unsigned arg2, int arg3, short arg4);
    [[maybe_unused]] void method8(int arg0, unsigned arg1, int arg2, unsigned arg3, float arg4);
    [[maybe_unused]] double method9(double arg0, unsigned arg1, double arg2, int arg3, bool arg4);

    [[maybe_unused]] bool memberVariable0{};
    [[maybe_unused]] int memberVariable1{};
    [[maybe_unused]] double memberVariable2{};
    [[maybe_unused]] bool memberVariable3{};
    [[maybe_unused]] int memberVariable4{};
    [[maybe_unused]] int memberVariable5{};
    [[maybe_unused]] short memberVariable6{};
    [[maybe_unused]] float memberVariable7{};
    [[maybe_unused]] unsigned memberVariable8{};
    [[maybe_unused]] bool memberVariable9{};

    [[maybe_unused]] static void function0(short arg0, bool arg1, int arg2, bool arg3, bool arg4);
    [[maybe_unused]] static void function1(bool arg0, short arg1, double arg2, short arg3, double arg4);
    [[maybe_unused]] static double function2(float arg0, double arg1, float arg2, unsigned arg3, float arg4);
    [[maybe_unused]] static unsigned function3(float arg0, float arg1, short arg2, unsigned arg3, bool arg4);
    [[maybe_unused]] static void function4(float arg0, short arg1, float arg2, short arg3, int arg4);
    [[maybe_unused]] static void function5(int arg0, short arg1, double arg2, int arg3, int arg4);
    [[maybe_unused]] static short function6(short arg0, short arg1, bool arg2, bool arg3, bool arg4);
    [[maybe_unused]] static int function7(int arg0, bool arg1, bool arg2, int arg3, bool arg4);
    [[maybe_unused]] static short function8(short arg0, short arg1, float arg2, unsigned arg3, unsigned arg4);
    [[maybe_unused]] static unsigned function9(unsigned arg0, double arg1, double arg2, unsigned arg3, bool arg4);

    [[maybe_unused]] inline static float variable0{};
    [[maybe_unused]] inline static int variable1{};
    [[maybe_unused]] inline static short variable2{};
    [[maybe_unused]] inline static unsigned variable3{};
    [[maybe_unused]] inline static short variable4{};
    [[maybe_unused]] inline static bool variable5{};
    [[maybe_unused]] inline static float variable6{};
    [[maybe_unused]] inline static float variable7{};
    [[maybe_unused]] inline static double variable8{};
    [[maybe_unused]] inline static float variable9{};

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
