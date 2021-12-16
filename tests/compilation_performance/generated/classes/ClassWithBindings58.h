#pragma once

// Generated with seed '88005553593'

#include "../../Common.h"

#include "ClassWithBindings9.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings22.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings34.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings86.h"
#include "ClassWithBindings95.h"

class ClassWithBindings58
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, short arg1, bool arg2, unsigned arg3, short arg4);
    void method1(bool arg0, bool arg1, bool arg2, int arg3, unsigned arg4);
    bool method2(bool arg0, bool arg1, short arg2, float arg3, bool arg4);
    float method3(short arg0, unsigned arg1, float arg2, int arg3, float arg4);
    void method4(double arg0, float arg1, bool arg2, short arg3, float arg4);
    void method5(unsigned arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    void method6(float arg0, unsigned arg1, float arg2, double arg3, float arg4);
    void method7(int arg0, bool arg1, int arg2, float arg3, float arg4);
    void method8(bool arg0, short arg1, short arg2, unsigned arg3, double arg4);
    void method9(float arg0, int arg1, unsigned arg2, short arg3, short arg4);
    void method10(unsigned arg0, short arg1, unsigned arg2, double arg3, double arg4);
    void method11(short arg0, bool arg1, float arg2, double arg3, double arg4);
    int method12(int arg0, int arg1, float arg2, float arg3, int arg4);
    bool method13(bool arg0, short arg1, bool arg2, short arg3, short arg4);
    void method14(short arg0, unsigned arg1, double arg2, double arg3, int arg4);

    int memberVariable0{};
    bool memberVariable1{};
    short memberVariable2{};
    bool memberVariable3{};
    short memberVariable4{};
    short memberVariable5{};
    bool memberVariable6{};
    int memberVariable7{};
    bool memberVariable8{};
    short memberVariable9{};
    short memberVariable10{};
    bool memberVariable11{};
    double memberVariable12{};
    short memberVariable13{};
    float memberVariable14{};

    static void function0(short arg0, bool arg1, short arg2, unsigned arg3, unsigned arg4);
    static int function1(double arg0, int arg1, float arg2, int arg3, double arg4);
    static void function2(float arg0, double arg1, float arg2, short arg3, int arg4);
    static double function3(unsigned arg0, short arg1, short arg2, double arg3, short arg4);
    static bool function4(int arg0, int arg1, unsigned arg2, bool arg3, float arg4);
    static void function5(double arg0, unsigned arg1, bool arg2, unsigned arg3, float arg4);
    static bool function6(int arg0, unsigned arg1, short arg2, unsigned arg3, bool arg4);
    static short function7(int arg0, int arg1, short arg2, bool arg3, float arg4);
    static bool function8(double arg0, bool arg1, double arg2, short arg3, bool arg4);
    static short function9(bool arg0, bool arg1, short arg2, float arg3, short arg4);
    static bool function10(float arg0, short arg1, int arg2, float arg3, bool arg4);
    static void function11(bool arg0, bool arg1, bool arg2, unsigned arg3, double arg4);
    static int function12(double arg0, double arg1, unsigned arg2, int arg3, double arg4);
    static int function13(int arg0, float arg1, float arg2, short arg3, int arg4);
    static double function14(unsigned arg0, bool arg1, unsigned arg2, double arg3, unsigned arg4);

    inline static bool variable0{};
    inline static bool variable1{};
    inline static int variable2{};
    inline static int variable3{};
    inline static unsigned variable4{};
    inline static bool variable5{};
    inline static double variable6{};
    inline static double variable7{};
    inline static unsigned variable8{};
    inline static bool variable9{};
    inline static bool variable10{};
    inline static int variable11{};
    inline static double variable12{};
    inline static unsigned variable13{};
    inline static int variable14{};
};
