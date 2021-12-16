#pragma once

// Generated with seed '88005553604'

#include "../../Common.h"

#include "ClassWithBindings2.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings6.h"
#include "ClassWithBindings16.h"
#include "ClassWithBindings22.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings91.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings99.h"

class ClassWithBindings69
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, bool arg1, unsigned arg2, unsigned arg3, float arg4);
    float method1(bool arg0, unsigned arg1, int arg2, unsigned arg3, float arg4);
    double method2(float arg0, double arg1, double arg2, bool arg3, unsigned arg4);
    short method3(float arg0, float arg1, short arg2, bool arg3, double arg4);
    void method4(float arg0, unsigned arg1, double arg2, short arg3, double arg4);
    unsigned method5(bool arg0, int arg1, unsigned arg2, double arg3, double arg4);
    void method6(unsigned arg0, short arg1, float arg2, short arg3, int arg4);
    void method7(double arg0, double arg1, double arg2, int arg3, int arg4);
    float method8(unsigned arg0, short arg1, unsigned arg2, float arg3, short arg4);
    short method9(bool arg0, bool arg1, int arg2, short arg3, float arg4);
    void method10(float arg0, short arg1, unsigned arg2, double arg3, int arg4);
    bool method11(short arg0, bool arg1, float arg2, unsigned arg3, short arg4);
    float method12(bool arg0, unsigned arg1, float arg2, float arg3, int arg4);
    void method13(double arg0, int arg1, double arg2, float arg3, unsigned arg4);
    void method14(bool arg0, short arg1, short arg2, int arg3, short arg4);

    double memberVariable0{};
    double memberVariable1{};
    bool memberVariable2{};
    int memberVariable3{};
    int memberVariable4{};
    float memberVariable5{};
    float memberVariable6{};
    int memberVariable7{};
    float memberVariable8{};
    short memberVariable9{};
    bool memberVariable10{};
    bool memberVariable11{};
    short memberVariable12{};
    short memberVariable13{};
    double memberVariable14{};

    static void function0(unsigned arg0, short arg1, unsigned arg2, short arg3, int arg4);
    static void function1(short arg0, int arg1, unsigned arg2, float arg3, bool arg4);
    static void function2(double arg0, int arg1, short arg2, bool arg3, bool arg4);
    static void function3(int arg0, bool arg1, double arg2, short arg3, double arg4);
    static int function4(bool arg0, short arg1, int arg2, double arg3, short arg4);
    static void function5(int arg0, bool arg1, unsigned arg2, unsigned arg3, double arg4);
    static void function6(unsigned arg0, float arg1, int arg2, int arg3, double arg4);
    static int function7(bool arg0, unsigned arg1, unsigned arg2, short arg3, int arg4);
    static void function8(unsigned arg0, bool arg1, float arg2, float arg3, short arg4);
    static void function9(float arg0, double arg1, double arg2, int arg3, int arg4);
    static void function10(float arg0, unsigned arg1, double arg2, float arg3, double arg4);
    static void function11(unsigned arg0, short arg1, float arg2, double arg3, unsigned arg4);
    static bool function12(bool arg0, int arg1, float arg2, float arg3, float arg4);
    static void function13(int arg0, unsigned arg1, double arg2, double arg3, float arg4);
    static void function14(float arg0, int arg1, short arg2, unsigned arg3, short arg4);

    inline static short variable0{};
    inline static double variable1{};
    inline static int variable2{};
    inline static float variable3{};
    inline static unsigned variable4{};
    inline static short variable5{};
    inline static int variable6{};
    inline static double variable7{};
    inline static int variable8{};
    inline static unsigned variable9{};
    inline static float variable10{};
    inline static short variable11{};
    inline static unsigned variable12{};
    inline static bool variable13{};
    inline static unsigned variable14{};
};