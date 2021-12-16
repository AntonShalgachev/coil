#pragma once

// Generated with seed '88005553574'

#include "../../Common.h"

#include "ClassWithBindings4.h"
#include "ClassWithBindings7.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings43.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings75.h"
#include "ClassWithBindings81.h"
#include "ClassWithBindings87.h"
#include "ClassWithBindings89.h"
#include "ClassWithBindings96.h"
#include "ClassWithBindings99.h"

class ClassWithBindings39
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(int arg0, double arg1, bool arg2, bool arg3, float arg4);
    bool method1(short arg0, float arg1, double arg2, double arg3, bool arg4);
    short method2(bool arg0, float arg1, short arg2, unsigned arg3, short arg4);
    void method3(unsigned arg0, unsigned arg1, short arg2, unsigned arg3, int arg4);
    short method4(short arg0, bool arg1, short arg2, short arg3, bool arg4);
    void method5(int arg0, double arg1, float arg2, bool arg3, unsigned arg4);
    void method6(double arg0, unsigned arg1, bool arg2, float arg3, int arg4);
    short method7(int arg0, bool arg1, short arg2, float arg3, short arg4);
    bool method8(unsigned arg0, bool arg1, bool arg2, bool arg3, int arg4);
    void method9(short arg0, short arg1, float arg2, bool arg3, double arg4);
    void method10(bool arg0, int arg1, int arg2, bool arg3, int arg4);
    void method11(short arg0, double arg1, short arg2, int arg3, bool arg4);
    bool method12(float arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    void method13(double arg0, double arg1, unsigned arg2, unsigned arg3, bool arg4);
    double method14(double arg0, bool arg1, int arg2, float arg3, int arg4);

    float memberVariable0{};
    unsigned memberVariable1{};
    bool memberVariable2{};
    double memberVariable3{};
    bool memberVariable4{};
    float memberVariable5{};
    int memberVariable6{};
    short memberVariable7{};
    short memberVariable8{};
    unsigned memberVariable9{};
    bool memberVariable10{};
    float memberVariable11{};
    unsigned memberVariable12{};
    int memberVariable13{};
    double memberVariable14{};

    static float function0(double arg0, float arg1, float arg2, int arg3, float arg4);
    static void function1(short arg0, bool arg1, short arg2, double arg3, bool arg4);
    static void function2(int arg0, short arg1, unsigned arg2, double arg3, int arg4);
    static int function3(bool arg0, unsigned arg1, int arg2, float arg3, int arg4);
    static double function4(double arg0, float arg1, short arg2, float arg3, float arg4);
    static unsigned function5(unsigned arg0, int arg1, unsigned arg2, float arg3, float arg4);
    static void function6(bool arg0, double arg1, short arg2, float arg3, int arg4);
    static void function7(bool arg0, float arg1, float arg2, int arg3, float arg4);
    static double function8(double arg0, int arg1, short arg2, bool arg3, bool arg4);
    static float function9(float arg0, bool arg1, short arg2, float arg3, int arg4);
    static void function10(double arg0, unsigned arg1, int arg2, float arg3, short arg4);
    static unsigned function11(short arg0, bool arg1, unsigned arg2, unsigned arg3, double arg4);
    static double function12(unsigned arg0, double arg1, int arg2, unsigned arg3, int arg4);
    static void function13(float arg0, bool arg1, short arg2, unsigned arg3, double arg4);
    static void function14(int arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);

    inline static unsigned variable0{};
    inline static float variable1{};
    inline static bool variable2{};
    inline static unsigned variable3{};
    inline static int variable4{};
    inline static short variable5{};
    inline static unsigned variable6{};
    inline static bool variable7{};
    inline static float variable8{};
    inline static int variable9{};
    inline static int variable10{};
    inline static float variable11{};
    inline static double variable12{};
    inline static unsigned variable13{};
    inline static float variable14{};
};