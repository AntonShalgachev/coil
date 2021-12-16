#pragma once

// Generated with seed '88005553586'

#include "../../Common.h"

#include "ClassWithBindings2.h"
#include "ClassWithBindings6.h"
#include "ClassWithBindings11.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings18.h"
#include "ClassWithBindings20.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings48.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings93.h"
#include "ClassWithBindings94.h"
#include "ClassWithBindings98.h"

class ClassWithBindings51
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(float arg0, short arg1, bool arg2, short arg3, unsigned arg4);
    short method1(short arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    double method2(unsigned arg0, bool arg1, double arg2, double arg3, unsigned arg4);
    int method3(int arg0, float arg1, bool arg2, int arg3, bool arg4);
    short method4(float arg0, short arg1, short arg2, float arg3, int arg4);
    double method5(unsigned arg0, unsigned arg1, short arg2, double arg3, double arg4);
    void method6(double arg0, double arg1, float arg2, double arg3, double arg4);
    void method7(bool arg0, unsigned arg1, int arg2, unsigned arg3, short arg4);
    bool method8(unsigned arg0, bool arg1, float arg2, float arg3, double arg4);
    double method9(double arg0, float arg1, double arg2, float arg3, bool arg4);
    unsigned method10(bool arg0, unsigned arg1, double arg2, unsigned arg3, int arg4);
    void method11(unsigned arg0, float arg1, bool arg2, double arg3, int arg4);
    double method12(float arg0, double arg1, int arg2, float arg3, unsigned arg4);
    void method13(float arg0, short arg1, short arg2, int arg3, double arg4);
    bool method14(bool arg0, double arg1, unsigned arg2, unsigned arg3, int arg4);

    int memberVariable0{};
    short memberVariable1{};
    unsigned memberVariable2{};
    float memberVariable3{};
    int memberVariable4{};
    float memberVariable5{};
    int memberVariable6{};
    short memberVariable7{};
    short memberVariable8{};
    float memberVariable9{};
    int memberVariable10{};
    short memberVariable11{};
    int memberVariable12{};
    short memberVariable13{};
    double memberVariable14{};

    static void function0(bool arg0, double arg1, int arg2, short arg3, double arg4);
    static void function1(unsigned arg0, bool arg1, bool arg2, int arg3, unsigned arg4);
    static void function2(unsigned arg0, float arg1, double arg2, unsigned arg3, bool arg4);
    static float function3(bool arg0, float arg1, int arg2, float arg3, double arg4);
    static bool function4(bool arg0, unsigned arg1, short arg2, bool arg3, int arg4);
    static void function5(short arg0, int arg1, short arg2, unsigned arg3, int arg4);
    static void function6(float arg0, unsigned arg1, int arg2, bool arg3, float arg4);
    static unsigned function7(float arg0, unsigned arg1, float arg2, unsigned arg3, short arg4);
    static void function8(bool arg0, short arg1, short arg2, double arg3, int arg4);
    static void function9(bool arg0, short arg1, double arg2, double arg3, double arg4);
    static void function10(float arg0, short arg1, double arg2, unsigned arg3, double arg4);
    static void function11(float arg0, int arg1, double arg2, unsigned arg3, float arg4);
    static void function12(float arg0, unsigned arg1, unsigned arg2, float arg3, int arg4);
    static void function13(unsigned arg0, double arg1, short arg2, float arg3, short arg4);
    static unsigned function14(int arg0, bool arg1, bool arg2, float arg3, unsigned arg4);

    inline static short variable0{};
    inline static short variable1{};
    inline static short variable2{};
    inline static bool variable3{};
    inline static unsigned variable4{};
    inline static float variable5{};
    inline static bool variable6{};
    inline static unsigned variable7{};
    inline static unsigned variable8{};
    inline static bool variable9{};
    inline static bool variable10{};
    inline static double variable11{};
    inline static bool variable12{};
    inline static double variable13{};
    inline static float variable14{};
};