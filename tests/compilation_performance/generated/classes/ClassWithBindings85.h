#pragma once

// Generated with seed '88005553620'

#include "../../Common.h"

#include "ClassWithBindings1.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings10.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings83.h"
#include "ClassWithBindings89.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings97.h"

class ClassWithBindings85
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(int arg0, unsigned arg1, double arg2, float arg3, bool arg4);
    void method1(int arg0, short arg1, bool arg2, bool arg3, short arg4);
    double method2(float arg0, double arg1, short arg2, float arg3, int arg4);
    void method3(int arg0, bool arg1, int arg2, float arg3, int arg4);
    bool method4(bool arg0, float arg1, float arg2, double arg3, float arg4);
    void method5(double arg0, double arg1, short arg2, short arg3, float arg4);
    void method6(float arg0, int arg1, unsigned arg2, float arg3, int arg4);
    unsigned method7(short arg0, unsigned arg1, unsigned arg2, unsigned arg3, double arg4);
    void method8(unsigned arg0, unsigned arg1, float arg2, float arg3, short arg4);
    void method9(bool arg0, double arg1, float arg2, int arg3, float arg4);
    bool method10(float arg0, short arg1, float arg2, bool arg3, bool arg4);
    int method11(short arg0, double arg1, float arg2, int arg3, float arg4);
    double method12(float arg0, float arg1, double arg2, int arg3, int arg4);
    float method13(int arg0, float arg1, double arg2, double arg3, float arg4);
    bool method14(float arg0, unsigned arg1, double arg2, bool arg3, short arg4);

    unsigned memberVariable0{};
    bool memberVariable1{};
    int memberVariable2{};
    int memberVariable3{};
    float memberVariable4{};
    float memberVariable5{};
    short memberVariable6{};
    float memberVariable7{};
    float memberVariable8{};
    double memberVariable9{};
    int memberVariable10{};
    bool memberVariable11{};
    double memberVariable12{};
    unsigned memberVariable13{};
    float memberVariable14{};

    static void function0(short arg0, bool arg1, unsigned arg2, unsigned arg3, double arg4);
    static unsigned function1(bool arg0, unsigned arg1, unsigned arg2, short arg3, bool arg4);
    static unsigned function2(unsigned arg0, double arg1, int arg2, double arg3, bool arg4);
    static double function3(bool arg0, double arg1, double arg2, short arg3, short arg4);
    static unsigned function4(float arg0, float arg1, short arg2, unsigned arg3, double arg4);
    static void function5(int arg0, int arg1, int arg2, double arg3, double arg4);
    static void function6(double arg0, unsigned arg1, short arg2, int arg3, unsigned arg4);
    static bool function7(short arg0, double arg1, bool arg2, bool arg3, bool arg4);
    static void function8(double arg0, float arg1, double arg2, int arg3, int arg4);
    static int function9(float arg0, int arg1, short arg2, unsigned arg3, bool arg4);
    static float function10(unsigned arg0, float arg1, double arg2, unsigned arg3, float arg4);
    static unsigned function11(unsigned arg0, bool arg1, float arg2, short arg3, bool arg4);
    static void function12(unsigned arg0, int arg1, unsigned arg2, short arg3, int arg4);
    static void function13(int arg0, bool arg1, unsigned arg2, unsigned arg3, bool arg4);
    static void function14(int arg0, bool arg1, int arg2, int arg3, float arg4);

    inline static short variable0{};
    inline static unsigned variable1{};
    inline static float variable2{};
    inline static short variable3{};
    inline static unsigned variable4{};
    inline static float variable5{};
    inline static short variable6{};
    inline static bool variable7{};
    inline static int variable8{};
    inline static short variable9{};
    inline static bool variable10{};
    inline static int variable11{};
    inline static int variable12{};
    inline static float variable13{};
    inline static unsigned variable14{};
};