#pragma once

// Generated with seed '88005553569'

#include "../../Common.h"

#include "Class2.h"
#include "Class3.h"
#include "Class9.h"
#include "Class18.h"
#include "Class23.h"
#include "Class29.h"
#include "Class30.h"
#include "Class32.h"
#include "Class37.h"
#include "Class50.h"
#include "Class53.h"
#include "Class58.h"
#include "Class60.h"
#include "Class64.h"
#include "Class65.h"
#include "Class66.h"
#include "Class70.h"
#include "Class83.h"
#include "Class85.h"
#include "Class95.h"

class Class34
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, float arg1, float arg2, float arg3, bool arg4);
    void method1(int arg0, short arg1, bool arg2, int arg3, bool arg4);
    void method2(bool arg0, double arg1, bool arg2, float arg3, bool arg4);
    unsigned method3(bool arg0, float arg1, double arg2, unsigned arg3, unsigned arg4);
    void method4(short arg0, int arg1, bool arg2, bool arg3, int arg4);
    int method5(short arg0, int arg1, unsigned arg2, double arg3, bool arg4);
    int method6(int arg0, bool arg1, double arg2, bool arg3, double arg4);
    double method7(double arg0, double arg1, double arg2, bool arg3, int arg4);
    void method8(double arg0, bool arg1, bool arg2, int arg3, float arg4);
    int method9(int arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    short method10(short arg0, int arg1, float arg2, bool arg3, float arg4);
    void method11(float arg0, float arg1, float arg2, unsigned arg3, float arg4);
    void method12(unsigned arg0, unsigned arg1, bool arg2, short arg3, short arg4);
    float method13(double arg0, short arg1, short arg2, float arg3, unsigned arg4);
    unsigned method14(float arg0, unsigned arg1, int arg2, int arg3, unsigned arg4);

    int memberVariable0{};
    unsigned memberVariable1{};
    int memberVariable2{};
    int memberVariable3{};
    int memberVariable4{};
    unsigned memberVariable5{};
    bool memberVariable6{};
    float memberVariable7{};
    short memberVariable8{};
    short memberVariable9{};
    bool memberVariable10{};
    bool memberVariable11{};
    bool memberVariable12{};
    double memberVariable13{};
    short memberVariable14{};

    static double function0(float arg0, int arg1, short arg2, double arg3, float arg4);
    static void function1(bool arg0, double arg1, bool arg2, short arg3, int arg4);
    static void function2(double arg0, unsigned arg1, unsigned arg2, double arg3, bool arg4);
    static void function3(double arg0, bool arg1, unsigned arg2, float arg3, short arg4);
    static double function4(bool arg0, int arg1, int arg2, double arg3, double arg4);
    static void function5(float arg0, unsigned arg1, bool arg2, int arg3, double arg4);
    static void function6(float arg0, float arg1, double arg2, int arg3, float arg4);
    static void function7(int arg0, double arg1, int arg2, double arg3, unsigned arg4);
    static unsigned function8(short arg0, float arg1, double arg2, float arg3, unsigned arg4);
    static void function9(int arg0, int arg1, short arg2, bool arg3, int arg4);
    static void function10(short arg0, float arg1, bool arg2, double arg3, double arg4);
    static void function11(float arg0, bool arg1, unsigned arg2, unsigned arg3, int arg4);
    static double function12(bool arg0, double arg1, int arg2, bool arg3, int arg4);
    static void function13(bool arg0, unsigned arg1, float arg2, bool arg3, int arg4);
    static void function14(bool arg0, bool arg1, short arg2, unsigned arg3, unsigned arg4);

    inline static float variable0{};
    inline static short variable1{};
    inline static short variable2{};
    inline static double variable3{};
    inline static float variable4{};
    inline static unsigned variable5{};
    inline static bool variable6{};
    inline static int variable7{};
    inline static short variable8{};
    inline static float variable9{};
    inline static double variable10{};
    inline static bool variable11{};
    inline static int variable12{};
    inline static bool variable13{};
    inline static int variable14{};
};
