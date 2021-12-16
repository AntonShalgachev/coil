#pragma once

// Generated with seed '88005553602'

#include "../../Common.h"

#include "ClassWithBindings1.h"
#include "ClassWithBindings3.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings34.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings48.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings76.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings83.h"
#include "ClassWithBindings87.h"
#include "ClassWithBindings90.h"

class ClassWithBindings67
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, float arg1, unsigned arg2, int arg3, float arg4);
    void method1(float arg0, int arg1, int arg2, short arg3, float arg4);
    void method2(bool arg0, bool arg1, int arg2, float arg3, int arg4);
    unsigned method3(double arg0, double arg1, double arg2, unsigned arg3, double arg4);
    unsigned method4(unsigned arg0, int arg1, short arg2, short arg3, int arg4);
    void method5(double arg0, unsigned arg1, unsigned arg2, int arg3, double arg4);
    void method6(short arg0, bool arg1, float arg2, double arg3, unsigned arg4);
    void method7(float arg0, short arg1, short arg2, float arg3, int arg4);
    void method8(bool arg0, bool arg1, bool arg2, int arg3, bool arg4);
    void method9(short arg0, float arg1, unsigned arg2, short arg3, float arg4);
    void method10(bool arg0, int arg1, short arg2, unsigned arg3, float arg4);
    unsigned method11(int arg0, short arg1, int arg2, unsigned arg3, bool arg4);
    int method12(int arg0, float arg1, bool arg2, int arg3, unsigned arg4);
    void method13(unsigned arg0, bool arg1, int arg2, short arg3, float arg4);
    unsigned method14(unsigned arg0, bool arg1, double arg2, int arg3, bool arg4);

    int memberVariable0{};
    float memberVariable1{};
    bool memberVariable2{};
    double memberVariable3{};
    double memberVariable4{};
    double memberVariable5{};
    bool memberVariable6{};
    bool memberVariable7{};
    short memberVariable8{};
    double memberVariable9{};
    double memberVariable10{};
    double memberVariable11{};
    int memberVariable12{};
    double memberVariable13{};
    unsigned memberVariable14{};

    static void function0(unsigned arg0, float arg1, unsigned arg2, double arg3, double arg4);
    static double function1(int arg0, bool arg1, int arg2, float arg3, double arg4);
    static double function2(int arg0, int arg1, double arg2, int arg3, double arg4);
    static double function3(int arg0, float arg1, double arg2, int arg3, int arg4);
    static void function4(double arg0, int arg1, short arg2, double arg3, int arg4);
    static void function5(int arg0, bool arg1, unsigned arg2, unsigned arg3, float arg4);
    static unsigned function6(unsigned arg0, bool arg1, bool arg2, float arg3, unsigned arg4);
    static int function7(int arg0, float arg1, unsigned arg2, int arg3, unsigned arg4);
    static void function8(bool arg0, double arg1, float arg2, float arg3, short arg4);
    static double function9(bool arg0, bool arg1, double arg2, float arg3, float arg4);
    static unsigned function10(double arg0, double arg1, short arg2, bool arg3, unsigned arg4);
    static unsigned function11(int arg0, bool arg1, int arg2, unsigned arg3, bool arg4);
    static void function12(short arg0, float arg1, double arg2, unsigned arg3, float arg4);
    static double function13(double arg0, int arg1, unsigned arg2, double arg3, unsigned arg4);
    static short function14(bool arg0, short arg1, int arg2, int arg3, short arg4);

    inline static bool variable0{};
    inline static int variable1{};
    inline static double variable2{};
    inline static int variable3{};
    inline static int variable4{};
    inline static bool variable5{};
    inline static double variable6{};
    inline static short variable7{};
    inline static float variable8{};
    inline static float variable9{};
    inline static double variable10{};
    inline static bool variable11{};
    inline static float variable12{};
    inline static float variable13{};
    inline static short variable14{};
};
