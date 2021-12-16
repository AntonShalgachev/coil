#pragma once

// Generated with seed '88005553624'

#include "../../Common.h"

#include "ClassWithBindings3.h"
#include "ClassWithBindings11.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings18.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings22.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings34.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings42.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings63.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings95.h"
#include "ClassWithBindings97.h"

class ClassWithBindings89
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, short arg1, int arg2, double arg3, int arg4);
    double method1(double arg0, double arg1, short arg2, float arg3, int arg4);
    void method2(short arg0, double arg1, int arg2, short arg3, bool arg4);
    void method3(unsigned arg0, float arg1, int arg2, float arg3, bool arg4);
    int method4(int arg0, int arg1, unsigned arg2, unsigned arg3, short arg4);
    int method5(int arg0, int arg1, int arg2, float arg3, short arg4);
    void method6(float arg0, bool arg1, double arg2, unsigned arg3, bool arg4);
    float method7(unsigned arg0, float arg1, float arg2, float arg3, short arg4);
    void method8(short arg0, int arg1, unsigned arg2, double arg3, unsigned arg4);
    bool method9(short arg0, unsigned arg1, double arg2, float arg3, bool arg4);
    float method10(int arg0, float arg1, short arg2, int arg3, int arg4);
    float method11(unsigned arg0, float arg1, float arg2, bool arg3, unsigned arg4);
    void method12(short arg0, bool arg1, bool arg2, float arg3, int arg4);
    float method13(float arg0, float arg1, double arg2, float arg3, bool arg4);
    float method14(int arg0, float arg1, float arg2, short arg3, int arg4);

    double memberVariable0{};
    int memberVariable1{};
    int memberVariable2{};
    float memberVariable3{};
    float memberVariable4{};
    short memberVariable5{};
    unsigned memberVariable6{};
    unsigned memberVariable7{};
    float memberVariable8{};
    unsigned memberVariable9{};
    int memberVariable10{};
    bool memberVariable11{};
    short memberVariable12{};
    short memberVariable13{};
    short memberVariable14{};

    static void function0(float arg0, unsigned arg1, short arg2, float arg3, float arg4);
    static void function1(double arg0, int arg1, unsigned arg2, float arg3, short arg4);
    static void function2(unsigned arg0, unsigned arg1, int arg2, double arg3, bool arg4);
    static bool function3(short arg0, int arg1, int arg2, short arg3, bool arg4);
    static void function4(float arg0, short arg1, int arg2, float arg3, short arg4);
    static void function5(short arg0, short arg1, float arg2, short arg3, float arg4);
    static void function6(unsigned arg0, bool arg1, short arg2, float arg3, float arg4);
    static short function7(bool arg0, short arg1, short arg2, double arg3, float arg4);
    static short function8(unsigned arg0, unsigned arg1, bool arg2, short arg3, short arg4);
    static void function9(unsigned arg0, float arg1, float arg2, int arg3, bool arg4);
    static void function10(float arg0, double arg1, double arg2, short arg3, unsigned arg4);
    static double function11(int arg0, unsigned arg1, bool arg2, double arg3, short arg4);
    static double function12(double arg0, unsigned arg1, int arg2, short arg3, double arg4);
    static double function13(float arg0, bool arg1, float arg2, double arg3, bool arg4);
    static float function14(float arg0, int arg1, float arg2, float arg3, float arg4);

    inline static int variable0{};
    inline static double variable1{};
    inline static double variable2{};
    inline static short variable3{};
    inline static int variable4{};
    inline static short variable5{};
    inline static unsigned variable6{};
    inline static double variable7{};
    inline static int variable8{};
    inline static bool variable9{};
    inline static short variable10{};
    inline static int variable11{};
    inline static float variable12{};
    inline static short variable13{};
    inline static unsigned variable14{};
};
