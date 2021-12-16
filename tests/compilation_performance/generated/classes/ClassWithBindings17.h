#pragma once

// Generated with seed '88005553552'

#include "../../Common.h"

#include "ClassWithBindings3.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings20.h"
#include "ClassWithBindings24.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings56.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings93.h"
#include "ClassWithBindings99.h"

class ClassWithBindings17
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(int arg0, float arg1, short arg2, float arg3, int arg4);
    void method1(float arg0, float arg1, bool arg2, float arg3, int arg4);
    void method2(float arg0, int arg1, bool arg2, float arg3, bool arg4);
    void method3(bool arg0, int arg1, int arg2, float arg3, double arg4);
    bool method4(short arg0, bool arg1, short arg2, short arg3, bool arg4);
    void method5(float arg0, unsigned arg1, bool arg2, double arg3, unsigned arg4);
    void method6(bool arg0, float arg1, double arg2, float arg3, float arg4);
    void method7(short arg0, double arg1, float arg2, int arg3, int arg4);
    float method8(float arg0, int arg1, unsigned arg2, int arg3, int arg4);
    void method9(int arg0, float arg1, int arg2, float arg3, unsigned arg4);
    bool method10(unsigned arg0, bool arg1, short arg2, bool arg3, short arg4);
    int method11(double arg0, int arg1, double arg2, unsigned arg3, float arg4);
    bool method12(int arg0, int arg1, bool arg2, float arg3, int arg4);
    bool method13(float arg0, double arg1, float arg2, bool arg3, bool arg4);
    void method14(short arg0, double arg1, double arg2, short arg3, int arg4);

    int memberVariable0{};
    unsigned memberVariable1{};
    unsigned memberVariable2{};
    short memberVariable3{};
    unsigned memberVariable4{};
    float memberVariable5{};
    bool memberVariable6{};
    int memberVariable7{};
    bool memberVariable8{};
    unsigned memberVariable9{};
    double memberVariable10{};
    bool memberVariable11{};
    int memberVariable12{};
    unsigned memberVariable13{};
    short memberVariable14{};

    static void function0(bool arg0, bool arg1, double arg2, short arg3, unsigned arg4);
    static void function1(float arg0, float arg1, unsigned arg2, unsigned arg3, short arg4);
    static bool function2(short arg0, bool arg1, int arg2, bool arg3, short arg4);
    static void function3(short arg0, int arg1, bool arg2, short arg3, int arg4);
    static void function4(int arg0, int arg1, double arg2, unsigned arg3, unsigned arg4);
    static void function5(unsigned arg0, int arg1, int arg2, int arg3, short arg4);
    static double function6(double arg0, double arg1, double arg2, int arg3, double arg4);
    static int function7(float arg0, int arg1, float arg2, short arg3, unsigned arg4);
    static double function8(bool arg0, bool arg1, double arg2, double arg3, short arg4);
    static bool function9(int arg0, bool arg1, short arg2, float arg3, short arg4);
    static unsigned function10(unsigned arg0, int arg1, unsigned arg2, bool arg3, unsigned arg4);
    static float function11(int arg0, double arg1, float arg2, float arg3, double arg4);
    static unsigned function12(unsigned arg0, double arg1, float arg2, bool arg3, double arg4);
    static void function13(unsigned arg0, float arg1, int arg2, unsigned arg3, short arg4);
    static short function14(short arg0, float arg1, double arg2, short arg3, double arg4);

    inline static bool variable0{};
    inline static double variable1{};
    inline static short variable2{};
    inline static int variable3{};
    inline static short variable4{};
    inline static float variable5{};
    inline static unsigned variable6{};
    inline static short variable7{};
    inline static double variable8{};
    inline static unsigned variable9{};
    inline static double variable10{};
    inline static unsigned variable11{};
    inline static float variable12{};
    inline static short variable13{};
    inline static double variable14{};
};
