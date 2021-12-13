#pragma once

// Generated with seed '88005553621'

#include "../../Common.h"

#include "Class11.h"
#include "Class13.h"
#include "Class23.h"
#include "Class38.h"
#include "Class39.h"
#include "Class40.h"
#include "Class42.h"
#include "Class43.h"
#include "Class46.h"
#include "Class47.h"
#include "Class53.h"
#include "Class54.h"
#include "Class60.h"
#include "Class63.h"
#include "Class69.h"
#include "Class71.h"
#include "Class82.h"
#include "Class85.h"
#include "Class93.h"

class Class86
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(double arg0, unsigned arg1, unsigned arg2, float arg3, double arg4);
    void method1(int arg0, int arg1, short arg2, short arg3, double arg4);
    void method2(double arg0, float arg1, short arg2, double arg3, int arg4);
    unsigned method3(double arg0, int arg1, unsigned arg2, int arg3, bool arg4);
    void method4(float arg0, double arg1, int arg2, short arg3, float arg4);
    double method5(double arg0, short arg1, short arg2, double arg3, unsigned arg4);
    float method6(float arg0, short arg1, short arg2, short arg3, unsigned arg4);
    void method7(bool arg0, float arg1, float arg2, int arg3, int arg4);
    void method8(int arg0, unsigned arg1, int arg2, double arg3, bool arg4);
    void method9(short arg0, float arg1, float arg2, int arg3, float arg4);
    float method10(short arg0, double arg1, float arg2, float arg3, short arg4);
    short method11(short arg0, int arg1, float arg2, unsigned arg3, float arg4);
    void method12(bool arg0, unsigned arg1, unsigned arg2, unsigned arg3, bool arg4);
    double method13(short arg0, double arg1, double arg2, double arg3, bool arg4);
    double method14(unsigned arg0, float arg1, int arg2, double arg3, bool arg4);

    int memberVariable0{};
    double memberVariable1{};
    unsigned memberVariable2{};
    float memberVariable3{};
    bool memberVariable4{};
    short memberVariable5{};
    unsigned memberVariable6{};
    int memberVariable7{};
    bool memberVariable8{};
    int memberVariable9{};
    short memberVariable10{};
    float memberVariable11{};
    double memberVariable12{};
    double memberVariable13{};
    double memberVariable14{};

    static float function0(short arg0, short arg1, short arg2, float arg3, short arg4);
    static void function1(bool arg0, float arg1, float arg2, unsigned arg3, bool arg4);
    static void function2(int arg0, bool arg1, unsigned arg2, double arg3, double arg4);
    static void function3(int arg0, float arg1, unsigned arg2, bool arg3, bool arg4);
    static void function4(unsigned arg0, short arg1, float arg2, int arg3, unsigned arg4);
    static short function5(double arg0, int arg1, short arg2, short arg3, int arg4);
    static void function6(unsigned arg0, int arg1, int arg2, float arg3, bool arg4);
    static int function7(int arg0, float arg1, int arg2, int arg3, short arg4);
    static double function8(bool arg0, int arg1, unsigned arg2, double arg3, float arg4);
    static void function9(int arg0, int arg1, short arg2, bool arg3, unsigned arg4);
    static void function10(bool arg0, double arg1, int arg2, bool arg3, short arg4);
    static void function11(unsigned arg0, double arg1, double arg2, float arg3, double arg4);
    static void function12(double arg0, float arg1, short arg2, float arg3, double arg4);
    static void function13(unsigned arg0, bool arg1, short arg2, bool arg3, bool arg4);
    static float function14(int arg0, double arg1, float arg2, double arg3, short arg4);

    inline static float variable0{};
    inline static float variable1{};
    inline static double variable2{};
    inline static double variable3{};
    inline static float variable4{};
    inline static short variable5{};
    inline static double variable6{};
    inline static float variable7{};
    inline static int variable8{};
    inline static bool variable9{};
    inline static short variable10{};
    inline static bool variable11{};
    inline static int variable12{};
    inline static float variable13{};
    inline static unsigned variable14{};
};
