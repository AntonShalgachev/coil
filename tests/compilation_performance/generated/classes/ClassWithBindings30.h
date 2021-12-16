#pragma once

// Generated with seed '88005553565'

#include "../../Common.h"

#include "ClassWithBindings1.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings67.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings86.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings98.h"
#include "ClassWithBindings99.h"

class ClassWithBindings30
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(bool arg0, int arg1, float arg2, bool arg3, unsigned arg4);
    void method1(double arg0, int arg1, float arg2, double arg3, unsigned arg4);
    float method2(float arg0, float arg1, double arg2, float arg3, unsigned arg4);
    void method3(int arg0, unsigned arg1, short arg2, short arg3, double arg4);
    void method4(int arg0, double arg1, float arg2, unsigned arg3, unsigned arg4);
    unsigned method5(short arg0, double arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    bool method6(unsigned arg0, double arg1, double arg2, bool arg3, unsigned arg4);
    void method7(int arg0, int arg1, double arg2, unsigned arg3, float arg4);
    void method8(short arg0, bool arg1, int arg2, short arg3, float arg4);
    int method9(int arg0, int arg1, float arg2, bool arg3, short arg4);
    double method10(unsigned arg0, float arg1, double arg2, double arg3, short arg4);
    int method11(int arg0, double arg1, bool arg2, short arg3, double arg4);
    bool method12(short arg0, float arg1, bool arg2, float arg3, float arg4);
    float method13(double arg0, unsigned arg1, float arg2, float arg3, short arg4);
    unsigned method14(unsigned arg0, float arg1, unsigned arg2, short arg3, float arg4);

    bool memberVariable0{};
    int memberVariable1{};
    bool memberVariable2{};
    int memberVariable3{};
    float memberVariable4{};
    double memberVariable5{};
    unsigned memberVariable6{};
    unsigned memberVariable7{};
    double memberVariable8{};
    int memberVariable9{};
    bool memberVariable10{};
    int memberVariable11{};
    float memberVariable12{};
    float memberVariable13{};
    short memberVariable14{};

    static void function0(unsigned arg0, bool arg1, double arg2, short arg3, double arg4);
    static unsigned function1(bool arg0, float arg1, unsigned arg2, double arg3, bool arg4);
    static short function2(double arg0, float arg1, short arg2, int arg3, short arg4);
    static void function3(float arg0, unsigned arg1, int arg2, unsigned arg3, float arg4);
    static float function4(short arg0, unsigned arg1, float arg2, float arg3, bool arg4);
    static short function5(short arg0, double arg1, unsigned arg2, bool arg3, int arg4);
    static void function6(unsigned arg0, bool arg1, unsigned arg2, double arg3, short arg4);
    static void function7(unsigned arg0, double arg1, int arg2, bool arg3, float arg4);
    static unsigned function8(unsigned arg0, unsigned arg1, bool arg2, double arg3, double arg4);
    static void function9(float arg0, bool arg1, short arg2, unsigned arg3, unsigned arg4);
    static void function10(float arg0, int arg1, bool arg2, float arg3, short arg4);
    static void function11(unsigned arg0, unsigned arg1, int arg2, int arg3, bool arg4);
    static void function12(double arg0, float arg1, int arg2, bool arg3, bool arg4);
    static void function13(bool arg0, unsigned arg1, double arg2, int arg3, double arg4);
    static void function14(unsigned arg0, int arg1, short arg2, bool arg3, int arg4);

    inline static double variable0{};
    inline static float variable1{};
    inline static int variable2{};
    inline static unsigned variable3{};
    inline static unsigned variable4{};
    inline static double variable5{};
    inline static bool variable6{};
    inline static bool variable7{};
    inline static float variable8{};
    inline static float variable9{};
    inline static int variable10{};
    inline static short variable11{};
    inline static int variable12{};
    inline static double variable13{};
    inline static double variable14{};
};