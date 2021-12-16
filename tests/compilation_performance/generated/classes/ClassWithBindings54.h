#pragma once

// Generated with seed '88005553589'

#include "../../Common.h"

#include "ClassWithBindings7.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings87.h"
#include "ClassWithBindings99.h"

class ClassWithBindings54
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(short arg0, bool arg1, bool arg2, int arg3, unsigned arg4);
    void method1(double arg0, int arg1, bool arg2, int arg3, double arg4);
    void method2(short arg0, int arg1, unsigned arg2, double arg3, unsigned arg4);
    float method3(short arg0, float arg1, unsigned arg2, int arg3, float arg4);
    void method4(float arg0, double arg1, short arg2, float arg3, double arg4);
    void method5(short arg0, bool arg1, unsigned arg2, double arg3, double arg4);
    unsigned method6(short arg0, unsigned arg1, unsigned arg2, bool arg3, double arg4);
    void method7(float arg0, short arg1, int arg2, double arg3, short arg4);
    void method8(double arg0, double arg1, unsigned arg2, float arg3, short arg4);
    void method9(double arg0, int arg1, double arg2, double arg3, int arg4);
    void method10(int arg0, int arg1, double arg2, int arg3, unsigned arg4);
    void method11(int arg0, double arg1, bool arg2, unsigned arg3, unsigned arg4);
    float method12(unsigned arg0, short arg1, short arg2, int arg3, float arg4);
    float method13(float arg0, unsigned arg1, float arg2, float arg3, unsigned arg4);
    void method14(bool arg0, bool arg1, float arg2, unsigned arg3, bool arg4);

    bool memberVariable0{};
    unsigned memberVariable1{};
    short memberVariable2{};
    short memberVariable3{};
    unsigned memberVariable4{};
    short memberVariable5{};
    unsigned memberVariable6{};
    double memberVariable7{};
    short memberVariable8{};
    float memberVariable9{};
    short memberVariable10{};
    double memberVariable11{};
    unsigned memberVariable12{};
    unsigned memberVariable13{};
    bool memberVariable14{};

    static short function0(int arg0, int arg1, double arg2, short arg3, float arg4);
    static float function1(short arg0, short arg1, float arg2, short arg3, int arg4);
    static double function2(short arg0, int arg1, double arg2, short arg3, short arg4);
    static void function3(short arg0, float arg1, double arg2, double arg3, unsigned arg4);
    static void function4(short arg0, bool arg1, unsigned arg2, short arg3, short arg4);
    static short function5(short arg0, int arg1, unsigned arg2, double arg3, short arg4);
    static short function6(short arg0, float arg1, short arg2, int arg3, unsigned arg4);
    static double function7(short arg0, short arg1, double arg2, double arg3, short arg4);
    static void function8(unsigned arg0, float arg1, int arg2, bool arg3, bool arg4);
    static short function9(unsigned arg0, bool arg1, bool arg2, short arg3, bool arg4);
    static int function10(float arg0, short arg1, int arg2, double arg3, bool arg4);
    static void function11(short arg0, float arg1, float arg2, bool arg3, unsigned arg4);
    static float function12(float arg0, int arg1, unsigned arg2, short arg3, unsigned arg4);
    static void function13(double arg0, double arg1, float arg2, float arg3, int arg4);
    static void function14(short arg0, unsigned arg1, short arg2, unsigned arg3, float arg4);

    inline static unsigned variable0{};
    inline static double variable1{};
    inline static bool variable2{};
    inline static float variable3{};
    inline static int variable4{};
    inline static double variable5{};
    inline static short variable6{};
    inline static int variable7{};
    inline static int variable8{};
    inline static short variable9{};
    inline static short variable10{};
    inline static int variable11{};
    inline static double variable12{};
    inline static int variable13{};
    inline static int variable14{};
};
