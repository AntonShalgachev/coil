#pragma once

// Generated with seed '88005553618'

#include "../../Common.h"

#include "ClassWithBindings3.h"
#include "ClassWithBindings6.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings16.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings20.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings42.h"
#include "ClassWithBindings48.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings93.h"
#include "ClassWithBindings94.h"
#include "ClassWithBindings98.h"

class ClassWithBindings83
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(double arg0, bool arg1, unsigned arg2, short arg3, int arg4);
    unsigned method1(float arg0, int arg1, unsigned arg2, double arg3, unsigned arg4);
    unsigned method2(bool arg0, unsigned arg1, bool arg2, short arg3, int arg4);
    int method3(int arg0, float arg1, bool arg2, double arg3, int arg4);
    float method4(bool arg0, bool arg1, float arg2, float arg3, int arg4);
    unsigned method5(double arg0, unsigned arg1, unsigned arg2, bool arg3, bool arg4);
    void method6(int arg0, short arg1, int arg2, unsigned arg3, float arg4);
    float method7(double arg0, float arg1, unsigned arg2, int arg3, float arg4);
    bool method8(bool arg0, int arg1, bool arg2, bool arg3, float arg4);
    bool method9(int arg0, short arg1, int arg2, short arg3, bool arg4);
    void method10(double arg0, float arg1, short arg2, int arg3, unsigned arg4);
    float method11(bool arg0, float arg1, unsigned arg2, bool arg3, int arg4);
    int method12(short arg0, int arg1, unsigned arg2, float arg3, short arg4);
    void method13(double arg0, bool arg1, double arg2, unsigned arg3, int arg4);
    bool method14(double arg0, double arg1, bool arg2, float arg3, int arg4);

    float memberVariable0{};
    bool memberVariable1{};
    float memberVariable2{};
    float memberVariable3{};
    float memberVariable4{};
    unsigned memberVariable5{};
    double memberVariable6{};
    bool memberVariable7{};
    double memberVariable8{};
    bool memberVariable9{};
    short memberVariable10{};
    double memberVariable11{};
    unsigned memberVariable12{};
    int memberVariable13{};
    float memberVariable14{};

    static bool function0(bool arg0, double arg1, float arg2, int arg3, bool arg4);
    static int function1(int arg0, bool arg1, int arg2, float arg3, double arg4);
    static void function2(bool arg0, int arg1, int arg2, short arg3, short arg4);
    static void function3(double arg0, double arg1, float arg2, short arg3, short arg4);
    static void function4(unsigned arg0, short arg1, int arg2, float arg3, float arg4);
    static void function5(int arg0, unsigned arg1, float arg2, unsigned arg3, unsigned arg4);
    static void function6(double arg0, bool arg1, short arg2, float arg3, double arg4);
    static double function7(short arg0, double arg1, double arg2, int arg3, unsigned arg4);
    static void function8(int arg0, float arg1, float arg2, unsigned arg3, int arg4);
    static void function9(unsigned arg0, double arg1, unsigned arg2, float arg3, bool arg4);
    static void function10(short arg0, unsigned arg1, float arg2, bool arg3, unsigned arg4);
    static float function11(double arg0, float arg1, float arg2, bool arg3, float arg4);
    static float function12(float arg0, short arg1, short arg2, int arg3, int arg4);
    static void function13(bool arg0, float arg1, double arg2, int arg3, float arg4);
    static void function14(bool arg0, int arg1, short arg2, float arg3, short arg4);

    inline static unsigned variable0{};
    inline static double variable1{};
    inline static int variable2{};
    inline static unsigned variable3{};
    inline static int variable4{};
    inline static unsigned variable5{};
    inline static float variable6{};
    inline static int variable7{};
    inline static bool variable8{};
    inline static float variable9{};
    inline static short variable10{};
    inline static unsigned variable11{};
    inline static int variable12{};
    inline static short variable13{};
    inline static int variable14{};
};
