#pragma once

// Generated with seed '88005553616'

#include "../../Common.h"

#include "ClassWithBindings3.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings24.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings42.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings87.h"
#include "ClassWithBindings88.h"
#include "ClassWithBindings94.h"
#include "ClassWithBindings98.h"
#include "ClassWithBindings99.h"

class ClassWithBindings81
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, float arg1, bool arg2, short arg3, double arg4);
    short method1(short arg0, short arg1, int arg2, unsigned arg3, int arg4);
    void method2(bool arg0, double arg1, bool arg2, float arg3, float arg4);
    void method3(float arg0, bool arg1, bool arg2, unsigned arg3, double arg4);
    bool method4(short arg0, int arg1, int arg2, short arg3, bool arg4);
    float method5(int arg0, short arg1, float arg2, bool arg3, float arg4);
    void method6(double arg0, double arg1, double arg2, unsigned arg3, int arg4);
    void method7(double arg0, int arg1, short arg2, bool arg3, short arg4);
    void method8(float arg0, unsigned arg1, bool arg2, short arg3, int arg4);
    float method9(int arg0, bool arg1, int arg2, float arg3, int arg4);
    void method10(float arg0, unsigned arg1, short arg2, int arg3, short arg4);
    bool method11(unsigned arg0, double arg1, int arg2, double arg3, bool arg4);
    void method12(unsigned arg0, short arg1, short arg2, bool arg3, float arg4);
    float method13(unsigned arg0, float arg1, double arg2, unsigned arg3, float arg4);
    void method14(float arg0, short arg1, float arg2, int arg3, double arg4);

    double memberVariable0{};
    double memberVariable1{};
    unsigned memberVariable2{};
    double memberVariable3{};
    double memberVariable4{};
    bool memberVariable5{};
    double memberVariable6{};
    double memberVariable7{};
    int memberVariable8{};
    double memberVariable9{};
    float memberVariable10{};
    double memberVariable11{};
    float memberVariable12{};
    double memberVariable13{};
    unsigned memberVariable14{};

    static int function0(float arg0, int arg1, int arg2, bool arg3, double arg4);
    static unsigned function1(unsigned arg0, double arg1, unsigned arg2, double arg3, float arg4);
    static bool function2(double arg0, int arg1, bool arg2, float arg3, float arg4);
    static void function3(float arg0, unsigned arg1, int arg2, unsigned arg3, float arg4);
    static int function4(unsigned arg0, short arg1, unsigned arg2, int arg3, int arg4);
    static void function5(short arg0, int arg1, float arg2, bool arg3, unsigned arg4);
    static void function6(int arg0, short arg1, float arg2, bool arg3, bool arg4);
    static unsigned function7(unsigned arg0, double arg1, bool arg2, float arg3, unsigned arg4);
    static unsigned function8(float arg0, unsigned arg1, double arg2, unsigned arg3, bool arg4);
    static float function9(float arg0, double arg1, double arg2, float arg3, double arg4);
    static double function10(bool arg0, bool arg1, double arg2, short arg3, int arg4);
    static void function11(unsigned arg0, float arg1, int arg2, unsigned arg3, unsigned arg4);
    static void function12(int arg0, bool arg1, short arg2, short arg3, double arg4);
    static bool function13(bool arg0, short arg1, int arg2, bool arg3, double arg4);
    static void function14(short arg0, bool arg1, short arg2, int arg3, short arg4);

    inline static float variable0{};
    inline static int variable1{};
    inline static unsigned variable2{};
    inline static float variable3{};
    inline static float variable4{};
    inline static short variable5{};
    inline static short variable6{};
    inline static float variable7{};
    inline static unsigned variable8{};
    inline static bool variable9{};
    inline static unsigned variable10{};
    inline static unsigned variable11{};
    inline static unsigned variable12{};
    inline static int variable13{};
    inline static bool variable14{};
};
