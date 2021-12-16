#pragma once

// Generated with seed '88005553562'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings22.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings91.h"

class ClassWithBindings27
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, int arg1, double arg2, float arg3, unsigned arg4);
    void method1(int arg0, double arg1, short arg2, int arg3, int arg4);
    float method2(float arg0, double arg1, int arg2, bool arg3, float arg4);
    void method3(bool arg0, bool arg1, int arg2, float arg3, short arg4);
    void method4(short arg0, float arg1, bool arg2, unsigned arg3, float arg4);
    unsigned method5(unsigned arg0, double arg1, double arg2, float arg3, unsigned arg4);
    float method6(float arg0, float arg1, bool arg2, float arg3, int arg4);
    void method7(float arg0, float arg1, float arg2, int arg3, bool arg4);
    int method8(int arg0, double arg1, double arg2, bool arg3, int arg4);
    void method9(unsigned arg0, int arg1, float arg2, unsigned arg3, float arg4);
    void method10(unsigned arg0, short arg1, unsigned arg2, unsigned arg3, short arg4);
    unsigned method11(double arg0, unsigned arg1, bool arg2, unsigned arg3, float arg4);
    void method12(int arg0, float arg1, unsigned arg2, unsigned arg3, int arg4);
    void method13(double arg0, unsigned arg1, int arg2, double arg3, bool arg4);
    short method14(int arg0, short arg1, short arg2, int arg3, bool arg4);

    short memberVariable0{};
    unsigned memberVariable1{};
    short memberVariable2{};
    int memberVariable3{};
    short memberVariable4{};
    short memberVariable5{};
    float memberVariable6{};
    int memberVariable7{};
    unsigned memberVariable8{};
    short memberVariable9{};
    unsigned memberVariable10{};
    short memberVariable11{};
    double memberVariable12{};
    unsigned memberVariable13{};
    bool memberVariable14{};

    static double function0(short arg0, short arg1, unsigned arg2, int arg3, double arg4);
    static void function1(int arg0, int arg1, short arg2, bool arg3, unsigned arg4);
    static void function2(short arg0, float arg1, unsigned arg2, double arg3, short arg4);
    static void function3(unsigned arg0, double arg1, double arg2, float arg3, double arg4);
    static void function4(bool arg0, bool arg1, float arg2, double arg3, int arg4);
    static unsigned function5(bool arg0, unsigned arg1, int arg2, unsigned arg3, int arg4);
    static int function6(unsigned arg0, double arg1, double arg2, int arg3, unsigned arg4);
    static int function7(int arg0, bool arg1, bool arg2, double arg3, double arg4);
    static void function8(unsigned arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    static void function9(float arg0, float arg1, bool arg2, float arg3, double arg4);
    static float function10(float arg0, float arg1, unsigned arg2, float arg3, int arg4);
    static bool function11(bool arg0, double arg1, bool arg2, unsigned arg3, unsigned arg4);
    static void function12(int arg0, bool arg1, bool arg2, int arg3, bool arg4);
    static bool function13(int arg0, double arg1, short arg2, bool arg3, double arg4);
    static double function14(int arg0, double arg1, short arg2, short arg3, unsigned arg4);

    inline static short variable0{};
    inline static int variable1{};
    inline static bool variable2{};
    inline static double variable3{};
    inline static int variable4{};
    inline static short variable5{};
    inline static float variable6{};
    inline static int variable7{};
    inline static bool variable8{};
    inline static int variable9{};
    inline static int variable10{};
    inline static int variable11{};
    inline static float variable12{};
    inline static short variable13{};
    inline static unsigned variable14{};
};