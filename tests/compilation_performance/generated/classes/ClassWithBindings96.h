#pragma once

// Generated with seed '88005553631'

#include "../../Common.h"

#include "ClassWithBindings10.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings18.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings24.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings34.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings48.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings56.h"
#include "ClassWithBindings63.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings76.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings94.h"

class ClassWithBindings96
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, float arg1, int arg2, double arg3, short arg4);
    void method1(float arg0, bool arg1, float arg2, short arg3, unsigned arg4);
    void method2(bool arg0, short arg1, bool arg2, unsigned arg3, float arg4);
    void method3(bool arg0, float arg1, bool arg2, bool arg3, unsigned arg4);
    void method4(int arg0, short arg1, float arg2, short arg3, short arg4);
    int method5(unsigned arg0, int arg1, double arg2, float arg3, double arg4);
    bool method6(bool arg0, short arg1, int arg2, short arg3, bool arg4);
    void method7(bool arg0, bool arg1, int arg2, double arg3, int arg4);
    int method8(unsigned arg0, int arg1, int arg2, unsigned arg3, int arg4);
    short method9(short arg0, int arg1, short arg2, int arg3, unsigned arg4);
    float method10(float arg0, bool arg1, float arg2, float arg3, double arg4);
    unsigned method11(bool arg0, float arg1, double arg2, float arg3, unsigned arg4);
    double method12(double arg0, bool arg1, double arg2, int arg3, int arg4);
    void method13(double arg0, float arg1, short arg2, unsigned arg3, float arg4);
    double method14(float arg0, double arg1, bool arg2, int arg3, unsigned arg4);

    double memberVariable0{};
    short memberVariable1{};
    short memberVariable2{};
    int memberVariable3{};
    bool memberVariable4{};
    bool memberVariable5{};
    int memberVariable6{};
    float memberVariable7{};
    bool memberVariable8{};
    float memberVariable9{};
    double memberVariable10{};
    float memberVariable11{};
    float memberVariable12{};
    int memberVariable13{};
    unsigned memberVariable14{};

    static void function0(short arg0, double arg1, int arg2, unsigned arg3, bool arg4);
    static double function1(bool arg0, double arg1, short arg2, bool arg3, int arg4);
    static void function2(int arg0, float arg1, short arg2, bool arg3, bool arg4);
    static void function3(int arg0, unsigned arg1, int arg2, float arg3, unsigned arg4);
    static double function4(double arg0, short arg1, float arg2, short arg3, unsigned arg4);
    static double function5(int arg0, unsigned arg1, double arg2, short arg3, bool arg4);
    static void function6(bool arg0, short arg1, unsigned arg2, unsigned arg3, short arg4);
    static unsigned function7(double arg0, float arg1, unsigned arg2, short arg3, float arg4);
    static float function8(float arg0, int arg1, int arg2, double arg3, float arg4);
    static void function9(int arg0, bool arg1, int arg2, float arg3, bool arg4);
    static double function10(float arg0, double arg1, double arg2, double arg3, short arg4);
    static short function11(short arg0, double arg1, short arg2, bool arg3, bool arg4);
    static unsigned function12(float arg0, unsigned arg1, unsigned arg2, double arg3, unsigned arg4);
    static void function13(float arg0, float arg1, int arg2, bool arg3, double arg4);
    static unsigned function14(bool arg0, float arg1, short arg2, int arg3, unsigned arg4);

    inline static double variable0{};
    inline static float variable1{};
    inline static unsigned variable2{};
    inline static float variable3{};
    inline static double variable4{};
    inline static int variable5{};
    inline static float variable6{};
    inline static double variable7{};
    inline static unsigned variable8{};
    inline static float variable9{};
    inline static float variable10{};
    inline static float variable11{};
    inline static int variable12{};
    inline static float variable13{};
    inline static int variable14{};
};
