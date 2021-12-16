#pragma once

// Generated with seed '88005553571'

#include "../../Common.h"

#include "ClassWithBindings9.h"
#include "ClassWithBindings10.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings20.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings83.h"
#include "ClassWithBindings86.h"
#include "ClassWithBindings88.h"

class ClassWithBindings36
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(float arg0, int arg1, double arg2, double arg3, int arg4);
    void method1(int arg0, unsigned arg1, short arg2, double arg3, int arg4);
    void method2(float arg0, bool arg1, unsigned arg2, short arg3, unsigned arg4);
    void method3(float arg0, double arg1, float arg2, double arg3, double arg4);
    void method4(int arg0, short arg1, double arg2, float arg3, double arg4);
    void method5(int arg0, bool arg1, double arg2, int arg3, short arg4);
    bool method6(double arg0, bool arg1, int arg2, bool arg3, unsigned arg4);
    int method7(int arg0, int arg1, int arg2, int arg3, float arg4);
    void method8(bool arg0, int arg1, unsigned arg2, bool arg3, double arg4);
    void method9(float arg0, double arg1, bool arg2, int arg3, bool arg4);
    void method10(int arg0, bool arg1, short arg2, float arg3, int arg4);
    bool method11(bool arg0, bool arg1, bool arg2, double arg3, short arg4);
    void method12(double arg0, short arg1, int arg2, bool arg3, double arg4);
    float method13(float arg0, bool arg1, float arg2, unsigned arg3, bool arg4);
    void method14(double arg0, int arg1, float arg2, bool arg3, int arg4);

    float memberVariable0{};
    unsigned memberVariable1{};
    unsigned memberVariable2{};
    unsigned memberVariable3{};
    int memberVariable4{};
    short memberVariable5{};
    short memberVariable6{};
    short memberVariable7{};
    unsigned memberVariable8{};
    float memberVariable9{};
    int memberVariable10{};
    int memberVariable11{};
    short memberVariable12{};
    short memberVariable13{};
    unsigned memberVariable14{};

    static void function0(short arg0, unsigned arg1, double arg2, float arg3, double arg4);
    static void function1(bool arg0, short arg1, unsigned arg2, bool arg3, unsigned arg4);
    static double function2(short arg0, unsigned arg1, short arg2, bool arg3, double arg4);
    static void function3(double arg0, int arg1, bool arg2, double arg3, unsigned arg4);
    static void function4(bool arg0, unsigned arg1, short arg2, unsigned arg3, short arg4);
    static void function5(short arg0, bool arg1, short arg2, float arg3, short arg4);
    static int function6(double arg0, int arg1, int arg2, bool arg3, short arg4);
    static void function7(unsigned arg0, float arg1, short arg2, float arg3, bool arg4);
    static void function8(unsigned arg0, double arg1, bool arg2, short arg3, float arg4);
    static float function9(int arg0, double arg1, double arg2, int arg3, float arg4);
    static void function10(unsigned arg0, double arg1, short arg2, short arg3, short arg4);
    static unsigned function11(short arg0, unsigned arg1, unsigned arg2, short arg3, bool arg4);
    static double function12(double arg0, unsigned arg1, int arg2, int arg3, bool arg4);
    static bool function13(short arg0, float arg1, bool arg2, int arg3, double arg4);
    static unsigned function14(int arg0, bool arg1, bool arg2, bool arg3, unsigned arg4);

    inline static short variable0{};
    inline static int variable1{};
    inline static double variable2{};
    inline static short variable3{};
    inline static int variable4{};
    inline static short variable5{};
    inline static unsigned variable6{};
    inline static unsigned variable7{};
    inline static float variable8{};
    inline static short variable9{};
    inline static float variable10{};
    inline static float variable11{};
    inline static unsigned variable12{};
    inline static short variable13{};
    inline static int variable14{};
};
