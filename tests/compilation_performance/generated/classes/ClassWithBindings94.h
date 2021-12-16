#pragma once

// Generated with seed '88005553629'

#include "../../Common.h"

#include "ClassWithBindings3.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings20.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings63.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings87.h"
#include "ClassWithBindings99.h"

class ClassWithBindings94
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, float arg1, float arg2, double arg3, double arg4);
    double method1(bool arg0, double arg1, double arg2, float arg3, double arg4);
    float method2(float arg0, float arg1, int arg2, int arg3, float arg4);
    void method3(float arg0, float arg1, int arg2, bool arg3, double arg4);
    void method4(float arg0, int arg1, unsigned arg2, float arg3, double arg4);
    int method5(double arg0, bool arg1, bool arg2, int arg3, unsigned arg4);
    void method6(short arg0, bool arg1, float arg2, bool arg3, bool arg4);
    bool method7(bool arg0, bool arg1, double arg2, float arg3, unsigned arg4);
    void method8(unsigned arg0, short arg1, float arg2, double arg3, double arg4);
    void method9(float arg0, int arg1, short arg2, unsigned arg3, double arg4);
    void method10(double arg0, float arg1, unsigned arg2, float arg3, short arg4);
    int method11(unsigned arg0, unsigned arg1, short arg2, int arg3, float arg4);
    void method12(bool arg0, double arg1, unsigned arg2, float arg3, bool arg4);
    double method13(bool arg0, double arg1, short arg2, double arg3, unsigned arg4);
    void method14(short arg0, double arg1, bool arg2, float arg3, int arg4);

    bool memberVariable0{};
    double memberVariable1{};
    bool memberVariable2{};
    bool memberVariable3{};
    short memberVariable4{};
    bool memberVariable5{};
    float memberVariable6{};
    short memberVariable7{};
    int memberVariable8{};
    int memberVariable9{};
    float memberVariable10{};
    bool memberVariable11{};
    unsigned memberVariable12{};
    int memberVariable13{};
    float memberVariable14{};

    static bool function0(bool arg0, double arg1, float arg2, int arg3, float arg4);
    static void function1(double arg0, double arg1, unsigned arg2, float arg3, unsigned arg4);
    static void function2(double arg0, unsigned arg1, float arg2, int arg3, int arg4);
    static bool function3(bool arg0, short arg1, bool arg2, float arg3, double arg4);
    static int function4(double arg0, double arg1, int arg2, float arg3, int arg4);
    static void function5(float arg0, short arg1, unsigned arg2, unsigned arg3, int arg4);
    static void function6(double arg0, unsigned arg1, int arg2, double arg3, float arg4);
    static short function7(short arg0, int arg1, unsigned arg2, short arg3, unsigned arg4);
    static bool function8(short arg0, short arg1, unsigned arg2, bool arg3, float arg4);
    static unsigned function9(int arg0, unsigned arg1, int arg2, int arg3, double arg4);
    static double function10(bool arg0, int arg1, float arg2, double arg3, float arg4);
    static void function11(unsigned arg0, double arg1, short arg2, unsigned arg3, short arg4);
    static int function12(int arg0, short arg1, bool arg2, int arg3, bool arg4);
    static double function13(double arg0, unsigned arg1, double arg2, bool arg3, double arg4);
    static void function14(int arg0, short arg1, int arg2, double arg3, unsigned arg4);

    inline static int variable0{};
    inline static bool variable1{};
    inline static double variable2{};
    inline static bool variable3{};
    inline static bool variable4{};
    inline static bool variable5{};
    inline static short variable6{};
    inline static float variable7{};
    inline static short variable8{};
    inline static int variable9{};
    inline static float variable10{};
    inline static int variable11{};
    inline static double variable12{};
    inline static short variable13{};
    inline static float variable14{};
};
