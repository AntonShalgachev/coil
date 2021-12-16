#pragma once

// Generated with seed '88005553612'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings1.h"
#include "ClassWithBindings11.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings76.h"
#include "ClassWithBindings86.h"
#include "ClassWithBindings88.h"
#include "ClassWithBindings89.h"
#include "ClassWithBindings95.h"
#include "ClassWithBindings99.h"

class ClassWithBindings77
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(unsigned arg0, unsigned arg1, float arg2, double arg3, bool arg4);
    void method1(float arg0, double arg1, bool arg2, double arg3, float arg4);
    void method2(float arg0, bool arg1, bool arg2, float arg3, double arg4);
    short method3(bool arg0, bool arg1, float arg2, short arg3, short arg4);
    void method4(float arg0, unsigned arg1, short arg2, int arg3, unsigned arg4);
    void method5(bool arg0, bool arg1, float arg2, short arg3, float arg4);
    void method6(double arg0, double arg1, short arg2, unsigned arg3, int arg4);
    float method7(float arg0, float arg1, float arg2, bool arg3, double arg4);
    bool method8(double arg0, float arg1, unsigned arg2, bool arg3, float arg4);
    void method9(unsigned arg0, float arg1, unsigned arg2, short arg3, float arg4);
    double method10(bool arg0, short arg1, double arg2, float arg3, int arg4);
    float method11(int arg0, bool arg1, float arg2, float arg3, float arg4);
    float method12(float arg0, double arg1, bool arg2, short arg3, unsigned arg4);
    int method13(float arg0, unsigned arg1, int arg2, int arg3, int arg4);
    short method14(float arg0, bool arg1, float arg2, short arg3, int arg4);

    double memberVariable0{};
    double memberVariable1{};
    int memberVariable2{};
    int memberVariable3{};
    double memberVariable4{};
    short memberVariable5{};
    bool memberVariable6{};
    float memberVariable7{};
    short memberVariable8{};
    double memberVariable9{};
    bool memberVariable10{};
    float memberVariable11{};
    int memberVariable12{};
    int memberVariable13{};
    int memberVariable14{};

    static bool function0(unsigned arg0, int arg1, bool arg2, short arg3, bool arg4);
    static short function1(int arg0, double arg1, short arg2, short arg3, double arg4);
    static void function2(double arg0, bool arg1, float arg2, unsigned arg3, bool arg4);
    static int function3(int arg0, short arg1, double arg2, unsigned arg3, double arg4);
    static void function4(short arg0, short arg1, int arg2, int arg3, double arg4);
    static float function5(double arg0, double arg1, double arg2, unsigned arg3, float arg4);
    static void function6(double arg0, int arg1, unsigned arg2, float arg3, short arg4);
    static double function7(float arg0, double arg1, bool arg2, float arg3, double arg4);
    static void function8(unsigned arg0, bool arg1, short arg2, int arg3, int arg4);
    static short function9(float arg0, bool arg1, bool arg2, double arg3, short arg4);
    static void function10(short arg0, unsigned arg1, float arg2, float arg3, short arg4);
    static double function11(short arg0, short arg1, bool arg2, double arg3, bool arg4);
    static double function12(double arg0, bool arg1, bool arg2, float arg3, short arg4);
    static void function13(unsigned arg0, unsigned arg1, double arg2, float arg3, int arg4);
    static int function14(double arg0, int arg1, bool arg2, bool arg3, unsigned arg4);

    inline static float variable0{};
    inline static short variable1{};
    inline static unsigned variable2{};
    inline static double variable3{};
    inline static unsigned variable4{};
    inline static bool variable5{};
    inline static unsigned variable6{};
    inline static unsigned variable7{};
    inline static short variable8{};
    inline static short variable9{};
    inline static bool variable10{};
    inline static unsigned variable11{};
    inline static bool variable12{};
    inline static short variable13{};
    inline static bool variable14{};
};