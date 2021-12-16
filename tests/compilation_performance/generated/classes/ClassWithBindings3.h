#pragma once

// Generated with seed '88005553538'

#include "../../Common.h"

#include "ClassWithBindings11.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings78.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings83.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings88.h"

class ClassWithBindings3
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, int arg1, unsigned arg2, int arg3, double arg4);
    void method1(float arg0, float arg1, short arg2, unsigned arg3, unsigned arg4);
    void method2(float arg0, int arg1, int arg2, unsigned arg3, bool arg4);
    int method3(bool arg0, int arg1, int arg2, bool arg3, int arg4);
    bool method4(short arg0, float arg1, int arg2, bool arg3, short arg4);
    void method5(bool arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
    void method6(int arg0, float arg1, double arg2, float arg3, double arg4);
    void method7(short arg0, int arg1, short arg2, short arg3, short arg4);
    void method8(float arg0, unsigned arg1, double arg2, bool arg3, short arg4);
    int method9(int arg0, short arg1, double arg2, float arg3, int arg4);
    double method10(double arg0, unsigned arg1, float arg2, unsigned arg3, double arg4);
    unsigned method11(double arg0, short arg1, int arg2, int arg3, unsigned arg4);
    void method12(int arg0, unsigned arg1, double arg2, float arg3, unsigned arg4);
    void method13(bool arg0, float arg1, short arg2, unsigned arg3, double arg4);
    void method14(float arg0, int arg1, short arg2, unsigned arg3, unsigned arg4);

    unsigned memberVariable0{};
    int memberVariable1{};
    float memberVariable2{};
    float memberVariable3{};
    bool memberVariable4{};
    int memberVariable5{};
    short memberVariable6{};
    bool memberVariable7{};
    float memberVariable8{};
    unsigned memberVariable9{};
    float memberVariable10{};
    float memberVariable11{};
    unsigned memberVariable12{};
    float memberVariable13{};
    unsigned memberVariable14{};

    static float function0(bool arg0, int arg1, int arg2, unsigned arg3, float arg4);
    static void function1(short arg0, double arg1, float arg2, double arg3, double arg4);
    static void function2(float arg0, bool arg1, float arg2, int arg3, bool arg4);
    static void function3(short arg0, double arg1, bool arg2, bool arg3, short arg4);
    static void function4(double arg0, bool arg1, bool arg2, float arg3, unsigned arg4);
    static short function5(int arg0, unsigned arg1, short arg2, int arg3, float arg4);
    static float function6(unsigned arg0, float arg1, double arg2, float arg3, int arg4);
    static short function7(short arg0, short arg1, short arg2, unsigned arg3, bool arg4);
    static bool function8(unsigned arg0, bool arg1, int arg2, double arg3, unsigned arg4);
    static void function9(int arg0, int arg1, float arg2, unsigned arg3, float arg4);
    static void function10(float arg0, bool arg1, double arg2, short arg3, double arg4);
    static void function11(unsigned arg0, double arg1, int arg2, unsigned arg3, unsigned arg4);
    static void function12(int arg0, short arg1, unsigned arg2, double arg3, short arg4);
    static void function13(float arg0, bool arg1, double arg2, int arg3, float arg4);
    static float function14(short arg0, short arg1, short arg2, short arg3, float arg4);

    inline static bool variable0{};
    inline static short variable1{};
    inline static float variable2{};
    inline static float variable3{};
    inline static double variable4{};
    inline static float variable5{};
    inline static float variable6{};
    inline static bool variable7{};
    inline static short variable8{};
    inline static unsigned variable9{};
    inline static short variable10{};
    inline static float variable11{};
    inline static double variable12{};
    inline static float variable13{};
    inline static short variable14{};
};