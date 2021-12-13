#pragma once

// Generated with seed '88005553594'

#include "../../Common.h"

#include "Class8.h"
#include "Class13.h"
#include "Class24.h"
#include "Class28.h"
#include "Class31.h"
#include "Class32.h"
#include "Class35.h"
#include "Class43.h"
#include "Class44.h"
#include "Class47.h"
#include "Class48.h"
#include "Class49.h"
#include "Class70.h"
#include "Class73.h"
#include "Class75.h"
#include "Class76.h"
#include "Class77.h"
#include "Class95.h"
#include "Class97.h"
#include "Class99.h"

class Class59
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, bool arg1, double arg2, int arg3, bool arg4);
    void method1(float arg0, short arg1, unsigned arg2, unsigned arg3, bool arg4);
    short method2(float arg0, short arg1, int arg2, short arg3, bool arg4);
    float method3(unsigned arg0, float arg1, short arg2, double arg3, short arg4);
    void method4(bool arg0, float arg1, double arg2, unsigned arg3, int arg4);
    double method5(double arg0, bool arg1, bool arg2, unsigned arg3, int arg4);
    void method6(double arg0, unsigned arg1, unsigned arg2, short arg3, bool arg4);
    int method7(double arg0, int arg1, double arg2, int arg3, short arg4);
    void method8(short arg0, float arg1, short arg2, float arg3, bool arg4);
    void method9(short arg0, unsigned arg1, double arg2, bool arg3, bool arg4);
    void method10(double arg0, double arg1, float arg2, short arg3, float arg4);
    void method11(float arg0, bool arg1, int arg2, int arg3, double arg4);
    void method12(short arg0, float arg1, unsigned arg2, bool arg3, float arg4);
    unsigned method13(bool arg0, unsigned arg1, double arg2, bool arg3, unsigned arg4);
    int method14(unsigned arg0, double arg1, unsigned arg2, float arg3, int arg4);

    static short function0(int arg0, unsigned arg1, float arg2, short arg3, double arg4);
    static void function1(short arg0, unsigned arg1, int arg2, double arg3, double arg4);
    static double function2(float arg0, double arg1, unsigned arg2, double arg3, bool arg4);
    static void function3(unsigned arg0, double arg1, float arg2, unsigned arg3, float arg4);
    static void function4(bool arg0, unsigned arg1, double arg2, unsigned arg3, short arg4);
    static void function5(float arg0, short arg1, float arg2, bool arg3, float arg4);
    static double function6(double arg0, float arg1, double arg2, double arg3, float arg4);
    static double function7(unsigned arg0, double arg1, bool arg2, bool arg3, short arg4);
    static bool function8(unsigned arg0, bool arg1, bool arg2, double arg3, float arg4);
    static unsigned function9(float arg0, short arg1, double arg2, unsigned arg3, unsigned arg4);
    static void function10(short arg0, short arg1, short arg2, float arg3, float arg4);
    static short function11(short arg0, float arg1, unsigned arg2, bool arg3, short arg4);
    static void function12(short arg0, double arg1, unsigned arg2, bool arg3, int arg4);
    static float function13(float arg0, unsigned arg1, float arg2, bool arg3, double arg4);
    static void function14(float arg0, short arg1, unsigned arg2, float arg3, int arg4);
};
