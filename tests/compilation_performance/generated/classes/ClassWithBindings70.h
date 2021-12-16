#pragma once

// Generated with seed '88005553605'

#include "../../Common.h"

#include "ClassWithBindings5.h"
#include "ClassWithBindings6.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings20.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings42.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings81.h"
#include "ClassWithBindings87.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings98.h"

class ClassWithBindings70
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, unsigned arg1, short arg2, unsigned arg3, int arg4);
    void method1(int arg0, unsigned arg1, unsigned arg2, short arg3, bool arg4);
    void method2(short arg0, float arg1, int arg2, unsigned arg3, int arg4);
    float method3(short arg0, float arg1, float arg2, int arg3, unsigned arg4);
    float method4(double arg0, int arg1, unsigned arg2, float arg3, bool arg4);
    int method5(int arg0, double arg1, short arg2, double arg3, float arg4);
    short method6(bool arg0, float arg1, short arg2, double arg3, float arg4);
    void method7(bool arg0, short arg1, float arg2, float arg3, short arg4);
    double method8(int arg0, bool arg1, unsigned arg2, unsigned arg3, double arg4);
    void method9(int arg0, int arg1, bool arg2, unsigned arg3, double arg4);
    void method10(short arg0, short arg1, double arg2, int arg3, bool arg4);
    unsigned method11(float arg0, unsigned arg1, float arg2, unsigned arg3, bool arg4);
    void method12(short arg0, unsigned arg1, double arg2, bool arg3, short arg4);
    void method13(unsigned arg0, double arg1, unsigned arg2, short arg3, int arg4);
    double method14(short arg0, int arg1, double arg2, double arg3, double arg4);

    short memberVariable0{};
    bool memberVariable1{};
    short memberVariable2{};
    int memberVariable3{};
    short memberVariable4{};
    int memberVariable5{};
    unsigned memberVariable6{};
    int memberVariable7{};
    double memberVariable8{};
    short memberVariable9{};
    unsigned memberVariable10{};
    bool memberVariable11{};
    short memberVariable12{};
    float memberVariable13{};
    short memberVariable14{};

    static double function0(int arg0, float arg1, float arg2, unsigned arg3, double arg4);
    static void function1(int arg0, int arg1, short arg2, double arg3, short arg4);
    static float function2(float arg0, double arg1, float arg2, double arg3, double arg4);
    static float function3(unsigned arg0, float arg1, int arg2, double arg3, int arg4);
    static void function4(bool arg0, int arg1, int arg2, double arg3, int arg4);
    static void function5(float arg0, unsigned arg1, short arg2, unsigned arg3, double arg4);
    static float function6(float arg0, unsigned arg1, int arg2, short arg3, unsigned arg4);
    static void function7(short arg0, bool arg1, short arg2, int arg3, int arg4);
    static void function8(float arg0, bool arg1, double arg2, bool arg3, double arg4);
    static void function9(short arg0, short arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    static void function10(bool arg0, unsigned arg1, int arg2, double arg3, int arg4);
    static void function11(double arg0, double arg1, unsigned arg2, int arg3, unsigned arg4);
    static double function12(unsigned arg0, int arg1, double arg2, bool arg3, float arg4);
    static void function13(int arg0, short arg1, float arg2, double arg3, float arg4);
    static void function14(short arg0, bool arg1, bool arg2, double arg3, int arg4);

    inline static bool variable0{};
    inline static short variable1{};
    inline static bool variable2{};
    inline static short variable3{};
    inline static short variable4{};
    inline static bool variable5{};
    inline static bool variable6{};
    inline static int variable7{};
    inline static float variable8{};
    inline static bool variable9{};
    inline static float variable10{};
    inline static float variable11{};
    inline static int variable12{};
    inline static unsigned variable13{};
    inline static short variable14{};
};
