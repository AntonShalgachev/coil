#pragma once

// Generated with seed '88005553584'

#include "../../Common.h"

#include "ClassWithBindings2.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings16.h"
#include "ClassWithBindings18.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings78.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings88.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings98.h"

class ClassWithBindings49
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, bool arg1, int arg2, short arg3, int arg4);
    double method1(unsigned arg0, double arg1, short arg2, float arg3, bool arg4);
    int method2(int arg0, bool arg1, float arg2, short arg3, unsigned arg4);
    void method3(short arg0, float arg1, double arg2, unsigned arg3, short arg4);
    bool method4(double arg0, bool arg1, double arg2, int arg3, float arg4);
    short method5(double arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    void method6(short arg0, int arg1, float arg2, unsigned arg3, int arg4);
    double method7(double arg0, float arg1, unsigned arg2, double arg3, double arg4);
    void method8(int arg0, double arg1, unsigned arg2, bool arg3, int arg4);
    void method9(double arg0, double arg1, unsigned arg2, float arg3, float arg4);
    void method10(int arg0, float arg1, int arg2, unsigned arg3, bool arg4);
    bool method11(unsigned arg0, bool arg1, unsigned arg2, float arg3, bool arg4);
    void method12(bool arg0, short arg1, float arg2, float arg3, int arg4);
    void method13(float arg0, float arg1, bool arg2, double arg3, short arg4);
    void method14(float arg0, double arg1, double arg2, short arg3, unsigned arg4);

    float memberVariable0{};
    short memberVariable1{};
    double memberVariable2{};
    short memberVariable3{};
    unsigned memberVariable4{};
    short memberVariable5{};
    unsigned memberVariable6{};
    float memberVariable7{};
    short memberVariable8{};
    unsigned memberVariable9{};
    bool memberVariable10{};
    double memberVariable11{};
    bool memberVariable12{};
    float memberVariable13{};
    short memberVariable14{};

    static void function0(double arg0, short arg1, short arg2, float arg3, double arg4);
    static void function1(bool arg0, double arg1, bool arg2, unsigned arg3, unsigned arg4);
    static void function2(double arg0, double arg1, float arg2, unsigned arg3, float arg4);
    static double function3(short arg0, unsigned arg1, double arg2, bool arg3, double arg4);
    static float function4(int arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    static float function5(bool arg0, int arg1, float arg2, bool arg3, float arg4);
    static void function6(float arg0, int arg1, float arg2, int arg3, double arg4);
    static void function7(float arg0, bool arg1, short arg2, float arg3, double arg4);
    static void function8(int arg0, unsigned arg1, unsigned arg2, bool arg3, double arg4);
    static void function9(int arg0, double arg1, bool arg2, short arg3, float arg4);
    static void function10(bool arg0, short arg1, short arg2, float arg3, bool arg4);
    static double function11(unsigned arg0, float arg1, double arg2, double arg3, short arg4);
    static void function12(unsigned arg0, short arg1, short arg2, short arg3, double arg4);
    static void function13(unsigned arg0, bool arg1, unsigned arg2, double arg3, short arg4);
    static void function14(float arg0, double arg1, unsigned arg2, unsigned arg3, double arg4);

    inline static bool variable0{};
    inline static float variable1{};
    inline static float variable2{};
    inline static bool variable3{};
    inline static bool variable4{};
    inline static short variable5{};
    inline static short variable6{};
    inline static short variable7{};
    inline static short variable8{};
    inline static short variable9{};
    inline static double variable10{};
    inline static int variable11{};
    inline static short variable12{};
    inline static bool variable13{};
    inline static float variable14{};
};
