#pragma once

// Generated with seed '88005553610'

#include "../../Common.h"

#include "ClassWithBindings2.h"
#include "ClassWithBindings8.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings18.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings56.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings81.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings98.h"

class ClassWithBindings75
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    void method1(float arg0, bool arg1, int arg2, int arg3, float arg4);
    void method2(short arg0, float arg1, int arg2, unsigned arg3, int arg4);
    void method3(int arg0, int arg1, double arg2, int arg3, short arg4);
    short method4(unsigned arg0, short arg1, short arg2, int arg3, int arg4);
    void method5(double arg0, int arg1, double arg2, short arg3, int arg4);
    short method6(double arg0, double arg1, short arg2, int arg3, bool arg4);
    void method7(int arg0, bool arg1, bool arg2, int arg3, float arg4);
    void method8(unsigned arg0, double arg1, double arg2, double arg3, unsigned arg4);
    bool method9(double arg0, float arg1, float arg2, bool arg3, bool arg4);
    double method10(double arg0, bool arg1, bool arg2, short arg3, double arg4);
    void method11(unsigned arg0, float arg1, bool arg2, short arg3, short arg4);
    unsigned method12(int arg0, bool arg1, unsigned arg2, int arg3, unsigned arg4);
    float method13(float arg0, unsigned arg1, short arg2, bool arg3, int arg4);
    double method14(unsigned arg0, double arg1, double arg2, short arg3, double arg4);

    short memberVariable0{};
    bool memberVariable1{};
    double memberVariable2{};
    bool memberVariable3{};
    short memberVariable4{};
    double memberVariable5{};
    float memberVariable6{};
    int memberVariable7{};
    double memberVariable8{};
    bool memberVariable9{};
    float memberVariable10{};
    short memberVariable11{};
    bool memberVariable12{};
    unsigned memberVariable13{};
    short memberVariable14{};

    static bool function0(double arg0, unsigned arg1, bool arg2, bool arg3, unsigned arg4);
    static float function1(unsigned arg0, float arg1, short arg2, float arg3, short arg4);
    static bool function2(short arg0, float arg1, bool arg2, int arg3, bool arg4);
    static bool function3(unsigned arg0, unsigned arg1, float arg2, bool arg3, int arg4);
    static void function4(short arg0, bool arg1, double arg2, int arg3, short arg4);
    static short function5(short arg0, bool arg1, float arg2, short arg3, short arg4);
    static float function6(int arg0, unsigned arg1, float arg2, unsigned arg3, float arg4);
    static bool function7(bool arg0, short arg1, int arg2, bool arg3, int arg4);
    static short function8(double arg0, unsigned arg1, short arg2, float arg3, short arg4);
    static void function9(unsigned arg0, float arg1, float arg2, short arg3, float arg4);
    static double function10(short arg0, unsigned arg1, short arg2, unsigned arg3, double arg4);
    static void function11(int arg0, unsigned arg1, double arg2, short arg3, unsigned arg4);
    static unsigned function12(unsigned arg0, float arg1, double arg2, bool arg3, double arg4);
    static double function13(double arg0, unsigned arg1, unsigned arg2, float arg3, unsigned arg4);
    static void function14(short arg0, int arg1, float arg2, double arg3, unsigned arg4);

    inline static unsigned variable0{};
    inline static float variable1{};
    inline static float variable2{};
    inline static float variable3{};
    inline static int variable4{};
    inline static int variable5{};
    inline static unsigned variable6{};
    inline static unsigned variable7{};
    inline static float variable8{};
    inline static int variable9{};
    inline static bool variable10{};
    inline static float variable11{};
    inline static int variable12{};
    inline static unsigned variable13{};
    inline static unsigned variable14{};
};
