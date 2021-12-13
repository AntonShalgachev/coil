#pragma once

// Generated with seed '88005553608'

#include "../../Common.h"

#include "Class3.h"
#include "Class5.h"
#include "Class8.h"
#include "Class9.h"
#include "Class14.h"
#include "Class15.h"
#include "Class19.h"
#include "Class20.h"
#include "Class26.h"
#include "Class31.h"
#include "Class32.h"
#include "Class50.h"
#include "Class58.h"
#include "Class60.h"
#include "Class66.h"
#include "Class68.h"
#include "Class83.h"
#include "Class90.h"
#include "Class96.h"
#include "Class97.h"

class Class73
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(int arg0, short arg1, bool arg2, float arg3, int arg4);
    double method1(short arg0, unsigned arg1, double arg2, bool arg3, int arg4);
    bool method2(double arg0, double arg1, bool arg2, double arg3, bool arg4);
    int method3(double arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    void method4(unsigned arg0, int arg1, bool arg2, short arg3, double arg4);
    float method5(unsigned arg0, float arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method6(float arg0, bool arg1, float arg2, bool arg3, unsigned arg4);
    void method7(float arg0, int arg1, bool arg2, float arg3, unsigned arg4);
    float method8(float arg0, float arg1, short arg2, float arg3, float arg4);
    void method9(float arg0, int arg1, unsigned arg2, short arg3, bool arg4);
    short method10(unsigned arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    void method11(short arg0, double arg1, double arg2, double arg3, unsigned arg4);
    int method12(double arg0, bool arg1, double arg2, int arg3, unsigned arg4);
    void method13(double arg0, short arg1, unsigned arg2, float arg3, short arg4);
    void method14(float arg0, short arg1, short arg2, double arg3, int arg4);

    float memberVariable0{};
    float memberVariable1{};
    int memberVariable2{};
    bool memberVariable3{};
    short memberVariable4{};
    int memberVariable5{};
    unsigned memberVariable6{};
    int memberVariable7{};
    double memberVariable8{};
    unsigned memberVariable9{};
    bool memberVariable10{};
    unsigned memberVariable11{};
    float memberVariable12{};
    unsigned memberVariable13{};
    int memberVariable14{};

    static double function0(unsigned arg0, double arg1, unsigned arg2, bool arg3, int arg4);
    static void function1(bool arg0, unsigned arg1, double arg2, bool arg3, bool arg4);
    static float function2(short arg0, bool arg1, float arg2, int arg3, short arg4);
    static void function3(double arg0, float arg1, short arg2, bool arg3, short arg4);
    static void function4(int arg0, double arg1, float arg2, double arg3, float arg4);
    static double function5(double arg0, short arg1, bool arg2, double arg3, bool arg4);
    static void function6(unsigned arg0, bool arg1, float arg2, double arg3, unsigned arg4);
    static void function7(bool arg0, float arg1, double arg2, float arg3, int arg4);
    static unsigned function8(short arg0, bool arg1, unsigned arg2, unsigned arg3, int arg4);
    static short function9(bool arg0, float arg1, short arg2, float arg3, double arg4);
    static float function10(float arg0, double arg1, float arg2, short arg3, float arg4);
    static void function11(float arg0, short arg1, float arg2, int arg3, short arg4);
    static void function12(short arg0, short arg1, int arg2, short arg3, int arg4);
    static short function13(bool arg0, short arg1, unsigned arg2, short arg3, int arg4);
    static void function14(int arg0, double arg1, unsigned arg2, double arg3, bool arg4);

    inline static short variable0{};
    inline static short variable1{};
    inline static float variable2{};
    inline static double variable3{};
    inline static float variable4{};
    inline static unsigned variable5{};
    inline static bool variable6{};
    inline static short variable7{};
    inline static short variable8{};
    inline static bool variable9{};
    inline static unsigned variable10{};
    inline static bool variable11{};
    inline static short variable12{};
    inline static int variable13{};
    inline static double variable14{};
};
