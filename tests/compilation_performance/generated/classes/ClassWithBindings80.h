#pragma once

// Generated with seed '88005553615'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings1.h"
#include "ClassWithBindings6.h"
#include "ClassWithBindings7.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings34.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings76.h"
#include "ClassWithBindings78.h"
#include "ClassWithBindings83.h"
#include "ClassWithBindings87.h"
#include "ClassWithBindings89.h"
#include "ClassWithBindings93.h"
#include "ClassWithBindings95.h"
#include "ClassWithBindings97.h"
#include "ClassWithBindings99.h"

class ClassWithBindings80
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, float arg1, short arg2, bool arg3, double arg4);
    void method1(float arg0, short arg1, float arg2, double arg3, double arg4);
    void method2(float arg0, float arg1, unsigned arg2, unsigned arg3, double arg4);
    double method3(short arg0, short arg1, float arg2, bool arg3, double arg4);
    void method4(double arg0, int arg1, short arg2, bool arg3, int arg4);
    void method5(short arg0, unsigned arg1, short arg2, float arg3, double arg4);
    int method6(int arg0, float arg1, int arg2, int arg3, double arg4);
    float method7(unsigned arg0, float arg1, int arg2, float arg3, float arg4);
    float method8(int arg0, float arg1, double arg2, float arg3, unsigned arg4);
    int method9(short arg0, float arg1, unsigned arg2, double arg3, int arg4);
    short method10(int arg0, unsigned arg1, short arg2, double arg3, int arg4);
    bool method11(bool arg0, unsigned arg1, bool arg2, bool arg3, unsigned arg4);
    float method12(float arg0, bool arg1, bool arg2, int arg3, int arg4);
    int method13(float arg0, short arg1, int arg2, double arg3, double arg4);
    double method14(double arg0, int arg1, double arg2, double arg3, short arg4);

    unsigned memberVariable0{};
    short memberVariable1{};
    short memberVariable2{};
    float memberVariable3{};
    unsigned memberVariable4{};
    unsigned memberVariable5{};
    short memberVariable6{};
    unsigned memberVariable7{};
    int memberVariable8{};
    float memberVariable9{};
    int memberVariable10{};
    double memberVariable11{};
    float memberVariable12{};
    short memberVariable13{};
    int memberVariable14{};

    static int function0(int arg0, float arg1, int arg2, unsigned arg3, float arg4);
    static void function1(int arg0, unsigned arg1, short arg2, float arg3, float arg4);
    static void function2(bool arg0, double arg1, int arg2, bool arg3, float arg4);
    static void function3(double arg0, unsigned arg1, short arg2, float arg3, short arg4);
    static double function4(unsigned arg0, double arg1, float arg2, bool arg3, unsigned arg4);
    static void function5(int arg0, short arg1, int arg2, unsigned arg3, float arg4);
    static void function6(float arg0, float arg1, bool arg2, int arg3, float arg4);
    static void function7(bool arg0, float arg1, bool arg2, bool arg3, unsigned arg4);
    static void function8(int arg0, unsigned arg1, int arg2, short arg3, bool arg4);
    static void function9(int arg0, float arg1, int arg2, unsigned arg3, double arg4);
    static double function10(int arg0, double arg1, short arg2, unsigned arg3, bool arg4);
    static short function11(int arg0, float arg1, short arg2, bool arg3, int arg4);
    static float function12(float arg0, float arg1, double arg2, float arg3, double arg4);
    static bool function13(bool arg0, bool arg1, bool arg2, bool arg3, unsigned arg4);
    static bool function14(unsigned arg0, unsigned arg1, double arg2, float arg3, bool arg4);

    inline static unsigned variable0{};
    inline static unsigned variable1{};
    inline static int variable2{};
    inline static short variable3{};
    inline static int variable4{};
    inline static double variable5{};
    inline static short variable6{};
    inline static unsigned variable7{};
    inline static int variable8{};
    inline static double variable9{};
    inline static int variable10{};
    inline static int variable11{};
    inline static float variable12{};
    inline static int variable13{};
    inline static float variable14{};
};
