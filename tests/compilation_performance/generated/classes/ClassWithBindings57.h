#pragma once

// Generated with seed '88005553592'

#include "../../Common.h"

#include "ClassWithBindings8.h"
#include "ClassWithBindings10.h"
#include "ClassWithBindings11.h"
#include "ClassWithBindings18.h"
#include "ClassWithBindings20.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings87.h"
#include "ClassWithBindings91.h"
#include "ClassWithBindings98.h"

class ClassWithBindings57
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, float arg1, unsigned arg2, float arg3, unsigned arg4);
    void method1(float arg0, float arg1, short arg2, unsigned arg3, int arg4);
    float method2(short arg0, float arg1, bool arg2, bool arg3, unsigned arg4);
    void method3(bool arg0, bool arg1, short arg2, float arg3, float arg4);
    void method4(int arg0, bool arg1, unsigned arg2, int arg3, short arg4);
    int method5(bool arg0, float arg1, double arg2, int arg3, int arg4);
    short method6(unsigned arg0, unsigned arg1, float arg2, int arg3, short arg4);
    void method7(int arg0, float arg1, unsigned arg2, float arg3, short arg4);
    int method8(short arg0, int arg1, short arg2, unsigned arg3, bool arg4);
    bool method9(bool arg0, double arg1, int arg2, bool arg3, int arg4);
    void method10(int arg0, unsigned arg1, int arg2, short arg3, int arg4);
    bool method11(unsigned arg0, bool arg1, double arg2, bool arg3, short arg4);
    void method12(bool arg0, double arg1, double arg2, float arg3, unsigned arg4);
    int method13(int arg0, float arg1, bool arg2, float arg3, int arg4);
    double method14(short arg0, bool arg1, unsigned arg2, double arg3, float arg4);

    unsigned memberVariable0{};
    double memberVariable1{};
    short memberVariable2{};
    float memberVariable3{};
    double memberVariable4{};
    short memberVariable5{};
    int memberVariable6{};
    unsigned memberVariable7{};
    double memberVariable8{};
    short memberVariable9{};
    double memberVariable10{};
    short memberVariable11{};
    bool memberVariable12{};
    bool memberVariable13{};
    unsigned memberVariable14{};

    static void function0(bool arg0, unsigned arg1, float arg2, short arg3, int arg4);
    static void function1(double arg0, unsigned arg1, double arg2, short arg3, double arg4);
    static float function2(short arg0, unsigned arg1, float arg2, int arg3, float arg4);
    static bool function3(double arg0, bool arg1, bool arg2, double arg3, double arg4);
    static void function4(float arg0, short arg1, bool arg2, double arg3, double arg4);
    static void function5(bool arg0, int arg1, unsigned arg2, bool arg3, double arg4);
    static void function6(bool arg0, bool arg1, int arg2, float arg3, double arg4);
    static double function7(unsigned arg0, double arg1, unsigned arg2, double arg3, bool arg4);
    static short function8(short arg0, float arg1, short arg2, bool arg3, bool arg4);
    static short function9(double arg0, double arg1, short arg2, int arg3, float arg4);
    static unsigned function10(float arg0, unsigned arg1, float arg2, double arg3, double arg4);
    static float function11(short arg0, float arg1, float arg2, bool arg3, float arg4);
    static unsigned function12(unsigned arg0, int arg1, unsigned arg2, float arg3, bool arg4);
    static int function13(short arg0, float arg1, int arg2, int arg3, unsigned arg4);
    static short function14(int arg0, float arg1, short arg2, float arg3, unsigned arg4);

    inline static int variable0{};
    inline static unsigned variable1{};
    inline static short variable2{};
    inline static float variable3{};
    inline static short variable4{};
    inline static short variable5{};
    inline static double variable6{};
    inline static unsigned variable7{};
    inline static short variable8{};
    inline static double variable9{};
    inline static float variable10{};
    inline static float variable11{};
    inline static double variable12{};
    inline static float variable13{};
    inline static unsigned variable14{};
};