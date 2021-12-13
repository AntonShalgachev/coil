#pragma once

// Generated with seed '88005553634'

#include "../../Common.h"

#include "Class4.h"
#include "Class12.h"
#include "Class13.h"
#include "Class14.h"
#include "Class31.h"
#include "Class35.h"
#include "Class48.h"
#include "Class50.h"
#include "Class52.h"
#include "Class60.h"
#include "Class61.h"
#include "Class62.h"
#include "Class63.h"
#include "Class71.h"
#include "Class72.h"
#include "Class75.h"
#include "Class84.h"
#include "Class86.h"
#include "Class89.h"
#include "Class95.h"

class Class99
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(float arg0, float arg1, unsigned arg2, double arg3, bool arg4);
    int method1(double arg0, int arg1, short arg2, bool arg3, short arg4);
    void method2(unsigned arg0, bool arg1, unsigned arg2, float arg3, double arg4);
    unsigned method3(float arg0, double arg1, bool arg2, int arg3, unsigned arg4);
    void method4(double arg0, int arg1, short arg2, bool arg3, short arg4);
    unsigned method5(int arg0, bool arg1, short arg2, unsigned arg3, float arg4);
    void method6(float arg0, unsigned arg1, int arg2, int arg3, bool arg4);
    void method7(int arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    void method8(int arg0, bool arg1, unsigned arg2, unsigned arg3, short arg4);
    unsigned method9(bool arg0, unsigned arg1, unsigned arg2, float arg3, unsigned arg4);
    void method10(int arg0, double arg1, float arg2, double arg3, unsigned arg4);
    short method11(short arg0, bool arg1, double arg2, double arg3, float arg4);
    float method12(float arg0, double arg1, bool arg2, float arg3, float arg4);
    bool method13(double arg0, bool arg1, double arg2, unsigned arg3, int arg4);
    void method14(bool arg0, int arg1, short arg2, float arg3, double arg4);

    static void function0(int arg0, bool arg1, float arg2, double arg3, short arg4);
    static void function1(bool arg0, short arg1, double arg2, unsigned arg3, short arg4);
    static void function2(unsigned arg0, short arg1, double arg2, unsigned arg3, int arg4);
    static short function3(short arg0, double arg1, short arg2, bool arg3, unsigned arg4);
    static double function4(int arg0, unsigned arg1, short arg2, float arg3, double arg4);
    static float function5(float arg0, unsigned arg1, int arg2, short arg3, int arg4);
    static void function6(short arg0, double arg1, double arg2, bool arg3, short arg4);
    static void function7(float arg0, bool arg1, unsigned arg2, float arg3, short arg4);
    static float function8(double arg0, float arg1, bool arg2, bool arg3, double arg4);
    static unsigned function9(unsigned arg0, short arg1, bool arg2, int arg3, bool arg4);
    static short function10(unsigned arg0, int arg1, bool arg2, short arg3, unsigned arg4);
    static void function11(unsigned arg0, unsigned arg1, int arg2, short arg3, double arg4);
    static void function12(short arg0, unsigned arg1, bool arg2, bool arg3, int arg4);
    static int function13(double arg0, bool arg1, unsigned arg2, float arg3, int arg4);
    static bool function14(float arg0, double arg1, bool arg2, float arg3, short arg4);
};
