#pragma once

// Generated with seed '88005553617'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings6.h"
#include "ClassWithBindings7.h"
#include "ClassWithBindings18.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings67.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings88.h"
#include "ClassWithBindings93.h"
#include "ClassWithBindings96.h"
#include "ClassWithBindings99.h"

class ClassWithBindings82
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(short arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    float method1(unsigned arg0, float arg1, float arg2, int arg3, double arg4);
    void method2(unsigned arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    unsigned method3(unsigned arg0, unsigned arg1, float arg2, bool arg3, int arg4);
    bool method4(float arg0, int arg1, bool arg2, int arg3, bool arg4);
    short method5(float arg0, float arg1, short arg2, short arg3, double arg4);
    void method6(short arg0, bool arg1, double arg2, short arg3, int arg4);
    unsigned method7(short arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    unsigned method8(bool arg0, unsigned arg1, double arg2, int arg3, bool arg4);
    unsigned method9(double arg0, unsigned arg1, double arg2, bool arg3, unsigned arg4);
    void method10(unsigned arg0, bool arg1, unsigned arg2, int arg3, unsigned arg4);
    int method11(int arg0, bool arg1, int arg2, double arg3, float arg4);
    void method12(float arg0, int arg1, short arg2, short arg3, unsigned arg4);
    float method13(int arg0, unsigned arg1, float arg2, unsigned arg3, bool arg4);
    void method14(short arg0, double arg1, unsigned arg2, unsigned arg3, float arg4);

    unsigned memberVariable0{};
    unsigned memberVariable1{};
    unsigned memberVariable2{};
    bool memberVariable3{};
    int memberVariable4{};
    bool memberVariable5{};
    short memberVariable6{};
    unsigned memberVariable7{};
    float memberVariable8{};
    int memberVariable9{};
    int memberVariable10{};
    unsigned memberVariable11{};
    unsigned memberVariable12{};
    float memberVariable13{};
    bool memberVariable14{};

    static double function0(double arg0, unsigned arg1, double arg2, float arg3, double arg4);
    static void function1(short arg0, short arg1, float arg2, unsigned arg3, double arg4);
    static void function2(unsigned arg0, unsigned arg1, unsigned arg2, int arg3, unsigned arg4);
    static void function3(int arg0, float arg1, bool arg2, short arg3, double arg4);
    static void function4(unsigned arg0, short arg1, int arg2, double arg3, int arg4);
    static unsigned function5(int arg0, unsigned arg1, double arg2, int arg3, unsigned arg4);
    static void function6(unsigned arg0, unsigned arg1, float arg2, double arg3, bool arg4);
    static bool function7(unsigned arg0, bool arg1, bool arg2, short arg3, double arg4);
    static unsigned function8(unsigned arg0, bool arg1, double arg2, double arg3, float arg4);
    static void function9(unsigned arg0, int arg1, short arg2, float arg3, double arg4);
    static double function10(float arg0, unsigned arg1, double arg2, float arg3, double arg4);
    static int function11(unsigned arg0, short arg1, unsigned arg2, unsigned arg3, int arg4);
    static unsigned function12(double arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    static void function13(unsigned arg0, double arg1, bool arg2, float arg3, double arg4);
    static double function14(bool arg0, float arg1, double arg2, bool arg3, double arg4);

    inline static unsigned variable0{};
    inline static unsigned variable1{};
    inline static float variable2{};
    inline static int variable3{};
    inline static short variable4{};
    inline static short variable5{};
    inline static int variable6{};
    inline static int variable7{};
    inline static short variable8{};
    inline static double variable9{};
    inline static bool variable10{};
    inline static short variable11{};
    inline static unsigned variable12{};
    inline static float variable13{};
    inline static unsigned variable14{};
};