#pragma once

// Generated with seed '88005553563'

#include "../../Common.h"

#include "ClassWithBindings12.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings97.h"

class ClassWithBindings28
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, int arg1, bool arg2, short arg3, bool arg4);
    void method1(short arg0, int arg1, short arg2, bool arg3, double arg4);
    void method2(double arg0, int arg1, short arg2, float arg3, float arg4);
    void method3(float arg0, unsigned arg1, short arg2, unsigned arg3, short arg4);
    void method4(float arg0, short arg1, int arg2, bool arg3, bool arg4);
    float method5(bool arg0, short arg1, int arg2, int arg3, float arg4);
    void method6(bool arg0, short arg1, bool arg2, double arg3, float arg4);
    float method7(short arg0, float arg1, double arg2, unsigned arg3, short arg4);
    bool method8(unsigned arg0, float arg1, double arg2, bool arg3, float arg4);
    void method9(short arg0, float arg1, short arg2, bool arg3, short arg4);
    unsigned method10(short arg0, float arg1, float arg2, bool arg3, unsigned arg4);
    void method11(float arg0, short arg1, bool arg2, float arg3, short arg4);
    unsigned method12(unsigned arg0, bool arg1, short arg2, unsigned arg3, float arg4);
    void method13(short arg0, bool arg1, short arg2, double arg3, double arg4);
    double method14(double arg0, unsigned arg1, short arg2, float arg3, double arg4);

    unsigned memberVariable0{};
    int memberVariable1{};
    unsigned memberVariable2{};
    double memberVariable3{};
    unsigned memberVariable4{};
    int memberVariable5{};
    int memberVariable6{};
    float memberVariable7{};
    bool memberVariable8{};
    bool memberVariable9{};
    bool memberVariable10{};
    short memberVariable11{};
    int memberVariable12{};
    float memberVariable13{};
    short memberVariable14{};

    static unsigned function0(double arg0, short arg1, bool arg2, float arg3, unsigned arg4);
    static void function1(short arg0, int arg1, int arg2, short arg3, int arg4);
    static short function2(short arg0, float arg1, bool arg2, double arg3, double arg4);
    static short function3(unsigned arg0, bool arg1, int arg2, double arg3, short arg4);
    static double function4(unsigned arg0, double arg1, int arg2, short arg3, float arg4);
    static bool function5(int arg0, bool arg1, short arg2, float arg3, bool arg4);
    static void function6(double arg0, unsigned arg1, bool arg2, int arg3, unsigned arg4);
    static short function7(int arg0, short arg1, bool arg2, short arg3, bool arg4);
    static bool function8(bool arg0, unsigned arg1, double arg2, bool arg3, double arg4);
    static void function9(short arg0, int arg1, double arg2, short arg3, short arg4);
    static short function10(unsigned arg0, float arg1, float arg2, short arg3, double arg4);
    static float function11(unsigned arg0, bool arg1, float arg2, int arg3, bool arg4);
    static void function12(unsigned arg0, bool arg1, bool arg2, double arg3, bool arg4);
    static int function13(short arg0, int arg1, int arg2, unsigned arg3, unsigned arg4);
    static unsigned function14(int arg0, unsigned arg1, unsigned arg2, short arg3, unsigned arg4);

    inline static bool variable0{};
    inline static bool variable1{};
    inline static double variable2{};
    inline static short variable3{};
    inline static int variable4{};
    inline static short variable5{};
    inline static float variable6{};
    inline static int variable7{};
    inline static bool variable8{};
    inline static unsigned variable9{};
    inline static float variable10{};
    inline static double variable11{};
    inline static short variable12{};
    inline static short variable13{};
    inline static double variable14{};
};
