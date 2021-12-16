#pragma once

// Generated with seed '88005553607'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings8.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings20.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings63.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings93.h"
#include "ClassWithBindings94.h"
#include "ClassWithBindings98.h"

class ClassWithBindings72
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, short arg1, unsigned arg2, double arg3, float arg4);
    void method1(int arg0, short arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method2(double arg0, double arg1, double arg2, int arg3, unsigned arg4);
    short method3(unsigned arg0, float arg1, short arg2, int arg3, int arg4);
    int method4(bool arg0, float arg1, float arg2, int arg3, int arg4);
    void method5(float arg0, short arg1, bool arg2, int arg3, short arg4);
    void method6(short arg0, bool arg1, double arg2, short arg3, float arg4);
    float method7(int arg0, short arg1, float arg2, unsigned arg3, unsigned arg4);
    double method8(double arg0, short arg1, short arg2, float arg3, bool arg4);
    void method9(unsigned arg0, int arg1, bool arg2, int arg3, unsigned arg4);
    void method10(int arg0, double arg1, short arg2, bool arg3, bool arg4);
    void method11(int arg0, bool arg1, unsigned arg2, short arg3, double arg4);
    void method12(int arg0, unsigned arg1, double arg2, float arg3, double arg4);
    void method13(bool arg0, int arg1, float arg2, double arg3, unsigned arg4);
    void method14(float arg0, short arg1, bool arg2, float arg3, double arg4);

    bool memberVariable0{};
    short memberVariable1{};
    int memberVariable2{};
    short memberVariable3{};
    bool memberVariable4{};
    int memberVariable5{};
    float memberVariable6{};
    short memberVariable7{};
    unsigned memberVariable8{};
    short memberVariable9{};
    bool memberVariable10{};
    double memberVariable11{};
    short memberVariable12{};
    int memberVariable13{};
    int memberVariable14{};

    static void function0(short arg0, float arg1, double arg2, unsigned arg3, short arg4);
    static bool function1(bool arg0, unsigned arg1, bool arg2, int arg3, short arg4);
    static short function2(short arg0, int arg1, short arg2, double arg3, float arg4);
    static void function3(float arg0, short arg1, short arg2, bool arg3, short arg4);
    static void function4(int arg0, float arg1, double arg2, short arg3, unsigned arg4);
    static float function5(int arg0, int arg1, double arg2, float arg3, bool arg4);
    static double function6(double arg0, int arg1, int arg2, int arg3, float arg4);
    static int function7(int arg0, int arg1, float arg2, float arg3, bool arg4);
    static short function8(short arg0, double arg1, short arg2, float arg3, unsigned arg4);
    static void function9(int arg0, double arg1, short arg2, unsigned arg3, double arg4);
    static void function10(short arg0, int arg1, unsigned arg2, int arg3, unsigned arg4);
    static int function11(int arg0, short arg1, bool arg2, short arg3, float arg4);
    static void function12(float arg0, short arg1, double arg2, unsigned arg3, unsigned arg4);
    static void function13(unsigned arg0, double arg1, bool arg2, double arg3, int arg4);
    static void function14(double arg0, unsigned arg1, short arg2, int arg3, int arg4);

    inline static unsigned variable0{};
    inline static float variable1{};
    inline static float variable2{};
    inline static short variable3{};
    inline static float variable4{};
    inline static short variable5{};
    inline static unsigned variable6{};
    inline static bool variable7{};
    inline static float variable8{};
    inline static short variable9{};
    inline static int variable10{};
    inline static int variable11{};
    inline static int variable12{};
    inline static short variable13{};
    inline static short variable14{};
};
