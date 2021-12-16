#pragma once

// Generated with seed '88005553630'

#include "../../Common.h"

#include "ClassWithBindings7.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings22.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings42.h"
#include "ClassWithBindings43.h"
#include "ClassWithBindings56.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings83.h"
#include "ClassWithBindings97.h"
#include "ClassWithBindings98.h"

class ClassWithBindings95
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, float arg1, bool arg2, double arg3, double arg4);
    void method1(unsigned arg0, float arg1, bool arg2, int arg3, bool arg4);
    bool method2(bool arg0, bool arg1, short arg2, double arg3, double arg4);
    short method3(bool arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    void method4(bool arg0, float arg1, float arg2, double arg3, unsigned arg4);
    double method5(int arg0, unsigned arg1, double arg2, unsigned arg3, unsigned arg4);
    void method6(float arg0, double arg1, int arg2, double arg3, double arg4);
    double method7(double arg0, float arg1, double arg2, int arg3, short arg4);
    void method8(double arg0, short arg1, short arg2, float arg3, bool arg4);
    void method9(unsigned arg0, float arg1, float arg2, unsigned arg3, float arg4);
    void method10(unsigned arg0, int arg1, int arg2, unsigned arg3, double arg4);
    short method11(unsigned arg0, short arg1, short arg2, double arg3, bool arg4);
    double method12(short arg0, unsigned arg1, unsigned arg2, float arg3, double arg4);
    void method13(short arg0, int arg1, int arg2, unsigned arg3, float arg4);
    void method14(short arg0, float arg1, float arg2, float arg3, short arg4);

    bool memberVariable0{};
    unsigned memberVariable1{};
    unsigned memberVariable2{};
    short memberVariable3{};
    int memberVariable4{};
    short memberVariable5{};
    bool memberVariable6{};
    float memberVariable7{};
    unsigned memberVariable8{};
    double memberVariable9{};
    int memberVariable10{};
    float memberVariable11{};
    short memberVariable12{};
    double memberVariable13{};
    unsigned memberVariable14{};

    static int function0(float arg0, double arg1, int arg2, float arg3, bool arg4);
    static unsigned function1(bool arg0, double arg1, unsigned arg2, short arg3, unsigned arg4);
    static void function2(float arg0, float arg1, short arg2, bool arg3, short arg4);
    static short function3(bool arg0, short arg1, int arg2, short arg3, unsigned arg4);
    static bool function4(bool arg0, float arg1, unsigned arg2, bool arg3, short arg4);
    static int function5(bool arg0, bool arg1, short arg2, int arg3, short arg4);
    static double function6(double arg0, bool arg1, short arg2, int arg3, double arg4);
    static void function7(double arg0, float arg1, int arg2, int arg3, unsigned arg4);
    static short function8(int arg0, double arg1, short arg2, short arg3, float arg4);
    static void function9(unsigned arg0, bool arg1, float arg2, float arg3, short arg4);
    static double function10(bool arg0, double arg1, float arg2, double arg3, unsigned arg4);
    static short function11(bool arg0, unsigned arg1, short arg2, double arg3, short arg4);
    static float function12(float arg0, float arg1, int arg2, float arg3, int arg4);
    static void function13(unsigned arg0, int arg1, int arg2, float arg3, short arg4);
    static double function14(float arg0, int arg1, float arg2, int arg3, double arg4);

    inline static bool variable0{};
    inline static float variable1{};
    inline static float variable2{};
    inline static float variable3{};
    inline static short variable4{};
    inline static bool variable5{};
    inline static double variable6{};
    inline static int variable7{};
    inline static float variable8{};
    inline static bool variable9{};
    inline static short variable10{};
    inline static short variable11{};
    inline static double variable12{};
    inline static int variable13{};
    inline static short variable14{};
};
