#pragma once

// Generated with seed '88005553613'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings22.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings48.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings88.h"
#include "ClassWithBindings91.h"
#include "ClassWithBindings96.h"

class ClassWithBindings78
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, float arg1, short arg2, float arg3, unsigned arg4);
    void method1(int arg0, float arg1, int arg2, float arg3, float arg4);
    void method2(double arg0, bool arg1, short arg2, unsigned arg3, int arg4);
    double method3(float arg0, bool arg1, unsigned arg2, double arg3, short arg4);
    void method4(int arg0, double arg1, int arg2, int arg3, short arg4);
    int method5(int arg0, double arg1, int arg2, float arg3, unsigned arg4);
    void method6(short arg0, int arg1, unsigned arg2, short arg3, bool arg4);
    double method7(unsigned arg0, bool arg1, unsigned arg2, bool arg3, double arg4);
    void method8(bool arg0, int arg1, bool arg2, float arg3, unsigned arg4);
    void method9(unsigned arg0, int arg1, float arg2, int arg3, short arg4);
    void method10(int arg0, short arg1, unsigned arg2, float arg3, float arg4);
    void method11(float arg0, unsigned arg1, bool arg2, bool arg3, float arg4);
    void method12(float arg0, int arg1, int arg2, bool arg3, float arg4);
    void method13(unsigned arg0, short arg1, float arg2, double arg3, short arg4);
    bool method14(bool arg0, int arg1, unsigned arg2, int arg3, float arg4);

    unsigned memberVariable0{};
    float memberVariable1{};
    bool memberVariable2{};
    float memberVariable3{};
    float memberVariable4{};
    unsigned memberVariable5{};
    double memberVariable6{};
    bool memberVariable7{};
    unsigned memberVariable8{};
    float memberVariable9{};
    double memberVariable10{};
    double memberVariable11{};
    double memberVariable12{};
    bool memberVariable13{};
    bool memberVariable14{};

    static double function0(short arg0, int arg1, bool arg2, double arg3, float arg4);
    static double function1(int arg0, unsigned arg1, double arg2, bool arg3, int arg4);
    static float function2(unsigned arg0, float arg1, unsigned arg2, int arg3, float arg4);
    static void function3(short arg0, short arg1, double arg2, bool arg3, short arg4);
    static double function4(int arg0, short arg1, bool arg2, float arg3, double arg4);
    static bool function5(short arg0, int arg1, bool arg2, float arg3, short arg4);
    static int function6(float arg0, int arg1, unsigned arg2, int arg3, float arg4);
    static void function7(short arg0, bool arg1, int arg2, bool arg3, bool arg4);
    static float function8(float arg0, float arg1, int arg2, bool arg3, double arg4);
    static unsigned function9(float arg0, bool arg1, unsigned arg2, int arg3, unsigned arg4);
    static bool function10(double arg0, float arg1, int arg2, float arg3, bool arg4);
    static short function11(double arg0, bool arg1, float arg2, int arg3, short arg4);
    static int function12(float arg0, bool arg1, short arg2, int arg3, bool arg4);
    static void function13(short arg0, bool arg1, unsigned arg2, double arg3, unsigned arg4);
    static bool function14(short arg0, bool arg1, int arg2, short arg3, bool arg4);

    inline static float variable0{};
    inline static int variable1{};
    inline static double variable2{};
    inline static bool variable3{};
    inline static float variable4{};
    inline static double variable5{};
    inline static short variable6{};
    inline static unsigned variable7{};
    inline static short variable8{};
    inline static double variable9{};
    inline static short variable10{};
    inline static double variable11{};
    inline static double variable12{};
    inline static int variable13{};
    inline static int variable14{};
};
