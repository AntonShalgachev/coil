#pragma once

// Generated with seed '88005553560'

#include "../../Common.h"


class ClassWithBindings25
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
    [[maybe_unused]] void method0(float arg0, short arg1, unsigned arg2, short arg3, bool arg4);
    [[maybe_unused]] void method1(float arg0, double arg1, short arg2, bool arg3, float arg4);
    [[maybe_unused]] bool method2(bool arg0, unsigned arg1, short arg2, float arg3, short arg4);
    [[maybe_unused]] bool method3(double arg0, double arg1, bool arg2, double arg3, int arg4);
    [[maybe_unused]] void method4(unsigned arg0, unsigned arg1, int arg2, double arg3, bool arg4);
    [[maybe_unused]] void method5(bool arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    [[maybe_unused]] double method6(double arg0, unsigned arg1, double arg2, short arg3, short arg4);
    [[maybe_unused]] void method7(float arg0, double arg1, short arg2, unsigned arg3, bool arg4);
    [[maybe_unused]] short method8(float arg0, unsigned arg1, unsigned arg2, bool arg3, short arg4);
    [[maybe_unused]] void method9(bool arg0, double arg1, short arg2, unsigned arg3, int arg4);

    [[maybe_unused]] bool memberVariable0{};
    [[maybe_unused]] double memberVariable1{};
    [[maybe_unused]] unsigned memberVariable2{};
    [[maybe_unused]] unsigned memberVariable3{};
    [[maybe_unused]] int memberVariable4{};
    [[maybe_unused]] double memberVariable5{};
    [[maybe_unused]] bool memberVariable6{};
    [[maybe_unused]] bool memberVariable7{};
    [[maybe_unused]] double memberVariable8{};
    [[maybe_unused]] unsigned memberVariable9{};

    [[maybe_unused]] static void function0(double arg0, short arg1, unsigned arg2, short arg3, bool arg4);
    [[maybe_unused]] static short function1(int arg0, double arg1, bool arg2, int arg3, short arg4);
    [[maybe_unused]] static int function2(double arg0, float arg1, int arg2, bool arg3, unsigned arg4);
    [[maybe_unused]] static void function3(int arg0, bool arg1, short arg2, int arg3, bool arg4);
    [[maybe_unused]] static bool function4(double arg0, double arg1, bool arg2, bool arg3, int arg4);
    [[maybe_unused]] static short function5(bool arg0, short arg1, int arg2, int arg3, float arg4);
    [[maybe_unused]] static void function6(int arg0, double arg1, double arg2, short arg3, unsigned arg4);
    [[maybe_unused]] static unsigned function7(bool arg0, unsigned arg1, int arg2, unsigned arg3, int arg4);
    [[maybe_unused]] static void function8(short arg0, double arg1, unsigned arg2, float arg3, float arg4);
    [[maybe_unused]] static int function9(short arg0, double arg1, double arg2, int arg3, int arg4);

    [[maybe_unused]] inline static unsigned variable0{};
    [[maybe_unused]] inline static int variable1{};
    [[maybe_unused]] inline static bool variable2{};
    [[maybe_unused]] inline static bool variable3{};
    [[maybe_unused]] inline static bool variable4{};
    [[maybe_unused]] inline static unsigned variable5{};
    [[maybe_unused]] inline static short variable6{};
    [[maybe_unused]] inline static double variable7{};
    [[maybe_unused]] inline static unsigned variable8{};
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
