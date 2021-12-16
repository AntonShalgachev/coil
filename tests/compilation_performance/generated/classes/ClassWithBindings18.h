#pragma once

// Generated with seed '88005553553'

#include "../../Common.h"

#include "ClassWithBindings3.h"
#include "ClassWithBindings6.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings48.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings78.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings96.h"

class ClassWithBindings18
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, unsigned arg1, short arg2, float arg3, float arg4);
    void method1(int arg0, short arg1, double arg2, float arg3, int arg4);
    void method2(unsigned arg0, double arg1, unsigned arg2, unsigned arg3, double arg4);
    void method3(bool arg0, bool arg1, bool arg2, double arg3, double arg4);
    void method4(unsigned arg0, int arg1, bool arg2, unsigned arg3, double arg4);
    void method5(int arg0, short arg1, unsigned arg2, bool arg3, double arg4);
    double method6(bool arg0, bool arg1, double arg2, unsigned arg3, double arg4);
    unsigned method7(unsigned arg0, short arg1, int arg2, double arg3, short arg4);
    void method8(unsigned arg0, short arg1, float arg2, short arg3, double arg4);
    unsigned method9(unsigned arg0, short arg1, bool arg2, int arg3, short arg4);
    void method10(short arg0, double arg1, bool arg2, int arg3, double arg4);
    float method11(bool arg0, double arg1, float arg2, bool arg3, unsigned arg4);
    float method12(unsigned arg0, bool arg1, float arg2, float arg3, float arg4);
    bool method13(bool arg0, bool arg1, short arg2, float arg3, int arg4);
    void method14(float arg0, double arg1, short arg2, float arg3, bool arg4);

    unsigned memberVariable0{};
    double memberVariable1{};
    float memberVariable2{};
    double memberVariable3{};
    double memberVariable4{};
    short memberVariable5{};
    double memberVariable6{};
    unsigned memberVariable7{};
    short memberVariable8{};
    unsigned memberVariable9{};
    double memberVariable10{};
    float memberVariable11{};
    unsigned memberVariable12{};
    unsigned memberVariable13{};
    float memberVariable14{};

    static float function0(unsigned arg0, bool arg1, unsigned arg2, float arg3, unsigned arg4);
    static void function1(unsigned arg0, unsigned arg1, float arg2, bool arg3, unsigned arg4);
    static void function2(double arg0, float arg1, float arg2, double arg3, int arg4);
    static double function3(int arg0, int arg1, double arg2, bool arg3, float arg4);
    static void function4(short arg0, float arg1, bool arg2, short arg3, short arg4);
    static void function5(int arg0, int arg1, int arg2, unsigned arg3, bool arg4);
    static void function6(short arg0, int arg1, double arg2, unsigned arg3, double arg4);
    static void function7(float arg0, float arg1, double arg2, float arg3, bool arg4);
    static void function8(unsigned arg0, bool arg1, double arg2, bool arg3, short arg4);
    static float function9(int arg0, float arg1, int arg2, bool arg3, unsigned arg4);
    static bool function10(float arg0, bool arg1, float arg2, unsigned arg3, short arg4);
    static unsigned function11(double arg0, unsigned arg1, int arg2, float arg3, bool arg4);
    static double function12(bool arg0, bool arg1, unsigned arg2, double arg3, unsigned arg4);
    static float function13(bool arg0, float arg1, bool arg2, bool arg3, double arg4);
    static void function14(float arg0, short arg1, short arg2, int arg3, short arg4);

    inline static short variable0{};
    inline static short variable1{};
    inline static float variable2{};
    inline static int variable3{};
    inline static short variable4{};
    inline static double variable5{};
    inline static double variable6{};
    inline static float variable7{};
    inline static int variable8{};
    inline static short variable9{};
    inline static int variable10{};
    inline static unsigned variable11{};
    inline static double variable12{};
    inline static double variable13{};
    inline static int variable14{};
};