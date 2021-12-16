#pragma once

// Generated with seed '88005553597'

#include "../../Common.h"

#include "ClassWithBindings4.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings22.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings56.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings63.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings81.h"
#include "ClassWithBindings89.h"
#include "ClassWithBindings94.h"

class ClassWithBindings62
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(double arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    void method1(double arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
    float method2(float arg0, unsigned arg1, short arg2, unsigned arg3, short arg4);
    void method3(unsigned arg0, float arg1, float arg2, float arg3, short arg4);
    int method4(short arg0, int arg1, float arg2, bool arg3, float arg4);
    void method5(unsigned arg0, short arg1, short arg2, unsigned arg3, unsigned arg4);
    unsigned method6(short arg0, double arg1, double arg2, int arg3, unsigned arg4);
    void method7(bool arg0, bool arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method8(double arg0, float arg1, float arg2, bool arg3, short arg4);
    float method9(short arg0, float arg1, unsigned arg2, short arg3, float arg4);
    float method10(unsigned arg0, float arg1, float arg2, bool arg3, double arg4);
    short method11(unsigned arg0, double arg1, int arg2, short arg3, int arg4);
    void method12(int arg0, short arg1, double arg2, short arg3, double arg4);
    void method13(unsigned arg0, unsigned arg1, int arg2, float arg3, int arg4);
    float method14(short arg0, unsigned arg1, float arg2, short arg3, bool arg4);

    double memberVariable0{};
    short memberVariable1{};
    unsigned memberVariable2{};
    double memberVariable3{};
    bool memberVariable4{};
    unsigned memberVariable5{};
    int memberVariable6{};
    bool memberVariable7{};
    bool memberVariable8{};
    bool memberVariable9{};
    float memberVariable10{};
    short memberVariable11{};
    float memberVariable12{};
    float memberVariable13{};
    double memberVariable14{};

    static unsigned function0(short arg0, short arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    static void function1(float arg0, unsigned arg1, bool arg2, double arg3, double arg4);
    static void function2(bool arg0, double arg1, unsigned arg2, unsigned arg3, int arg4);
    static void function3(int arg0, float arg1, bool arg2, int arg3, unsigned arg4);
    static void function4(short arg0, short arg1, unsigned arg2, float arg3, unsigned arg4);
    static double function5(short arg0, double arg1, double arg2, int arg3, short arg4);
    static void function6(short arg0, int arg1, short arg2, float arg3, double arg4);
    static void function7(int arg0, short arg1, bool arg2, short arg3, bool arg4);
    static void function8(int arg0, int arg1, float arg2, double arg3, short arg4);
    static int function9(int arg0, unsigned arg1, unsigned arg2, bool arg3, unsigned arg4);
    static unsigned function10(bool arg0, short arg1, unsigned arg2, int arg3, unsigned arg4);
    static void function11(unsigned arg0, bool arg1, unsigned arg2, double arg3, double arg4);
    static void function12(double arg0, float arg1, float arg2, float arg3, double arg4);
    static void function13(float arg0, unsigned arg1, short arg2, double arg3, short arg4);
    static void function14(double arg0, float arg1, short arg2, int arg3, float arg4);

    inline static int variable0{};
    inline static bool variable1{};
    inline static bool variable2{};
    inline static int variable3{};
    inline static short variable4{};
    inline static short variable5{};
    inline static int variable6{};
    inline static int variable7{};
    inline static bool variable8{};
    inline static double variable9{};
    inline static int variable10{};
    inline static short variable11{};
    inline static bool variable12{};
    inline static bool variable13{};
    inline static double variable14{};
};