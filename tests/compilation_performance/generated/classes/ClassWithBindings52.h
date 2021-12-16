#pragma once

// Generated with seed '88005553587'

#include "../../Common.h"

#include "ClassWithBindings15.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings24.h"
#include "ClassWithBindings34.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings48.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings88.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings99.h"

class ClassWithBindings52
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(bool arg0, int arg1, unsigned arg2, short arg3, float arg4);
    bool method1(unsigned arg0, int arg1, short arg2, bool arg3, bool arg4);
    unsigned method2(bool arg0, int arg1, bool arg2, int arg3, unsigned arg4);
    short method3(double arg0, double arg1, short arg2, float arg3, short arg4);
    void method4(int arg0, short arg1, double arg2, double arg3, double arg4);
    void method5(unsigned arg0, int arg1, double arg2, short arg3, unsigned arg4);
    void method6(unsigned arg0, short arg1, unsigned arg2, float arg3, float arg4);
    double method7(double arg0, int arg1, double arg2, int arg3, unsigned arg4);
    short method8(short arg0, short arg1, double arg2, unsigned arg3, unsigned arg4);
    int method9(int arg0, double arg1, double arg2, int arg3, double arg4);
    void method10(double arg0, short arg1, float arg2, double arg3, unsigned arg4);
    void method11(bool arg0, short arg1, unsigned arg2, short arg3, int arg4);
    unsigned method12(short arg0, short arg1, unsigned arg2, short arg3, float arg4);
    short method13(int arg0, unsigned arg1, short arg2, short arg3, int arg4);
    void method14(float arg0, bool arg1, short arg2, bool arg3, double arg4);

    int memberVariable0{};
    bool memberVariable1{};
    bool memberVariable2{};
    int memberVariable3{};
    double memberVariable4{};
    float memberVariable5{};
    short memberVariable6{};
    float memberVariable7{};
    double memberVariable8{};
    double memberVariable9{};
    bool memberVariable10{};
    unsigned memberVariable11{};
    double memberVariable12{};
    unsigned memberVariable13{};
    int memberVariable14{};

    static unsigned function0(int arg0, unsigned arg1, int arg2, double arg3, unsigned arg4);
    static int function1(int arg0, unsigned arg1, short arg2, short arg3, float arg4);
    static void function2(unsigned arg0, short arg1, int arg2, int arg3, float arg4);
    static void function3(short arg0, int arg1, unsigned arg2, float arg3, bool arg4);
    static float function4(unsigned arg0, float arg1, int arg2, float arg3, short arg4);
    static void function5(float arg0, double arg1, float arg2, short arg3, double arg4);
    static void function6(short arg0, bool arg1, unsigned arg2, int arg3, short arg4);
    static short function7(float arg0, float arg1, unsigned arg2, bool arg3, short arg4);
    static double function8(double arg0, int arg1, float arg2, bool arg3, double arg4);
    static short function9(short arg0, bool arg1, double arg2, short arg3, float arg4);
    static unsigned function10(short arg0, double arg1, unsigned arg2, short arg3, int arg4);
    static double function11(unsigned arg0, int arg1, unsigned arg2, short arg3, double arg4);
    static bool function12(int arg0, unsigned arg1, float arg2, float arg3, bool arg4);
    static void function13(unsigned arg0, float arg1, bool arg2, double arg3, short arg4);
    static int function14(int arg0, float arg1, bool arg2, int arg3, float arg4);

    inline static short variable0{};
    inline static double variable1{};
    inline static float variable2{};
    inline static double variable3{};
    inline static unsigned variable4{};
    inline static int variable5{};
    inline static unsigned variable6{};
    inline static float variable7{};
    inline static bool variable8{};
    inline static bool variable9{};
    inline static double variable10{};
    inline static bool variable11{};
    inline static short variable12{};
    inline static float variable13{};
    inline static int variable14{};
};
