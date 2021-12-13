#pragma once

// Generated with seed '88005553628'

#include "../../Common.h"

#include "Class0.h"
#include "Class2.h"
#include "Class7.h"
#include "Class25.h"
#include "Class30.h"
#include "Class32.h"
#include "Class35.h"
#include "Class38.h"
#include "Class44.h"
#include "Class45.h"
#include "Class48.h"
#include "Class51.h"
#include "Class63.h"
#include "Class64.h"
#include "Class67.h"
#include "Class84.h"
#include "Class88.h"
#include "Class90.h"
#include "Class98.h"

class Class93
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, float arg1, unsigned arg2, double arg3, double arg4);
    void method1(unsigned arg0, unsigned arg1, double arg2, bool arg3, double arg4);
    float method2(double arg0, bool arg1, int arg2, double arg3, float arg4);
    unsigned method3(unsigned arg0, unsigned arg1, float arg2, unsigned arg3, short arg4);
    bool method4(float arg0, bool arg1, int arg2, bool arg3, short arg4);
    void method5(float arg0, short arg1, int arg2, short arg3, short arg4);
    void method6(bool arg0, bool arg1, short arg2, int arg3, short arg4);
    void method7(int arg0, unsigned arg1, short arg2, bool arg3, int arg4);
    float method8(double arg0, short arg1, float arg2, int arg3, int arg4);
    int method9(float arg0, unsigned arg1, bool arg2, bool arg3, int arg4);
    unsigned method10(double arg0, unsigned arg1, unsigned arg2, short arg3, float arg4);
    void method11(float arg0, bool arg1, short arg2, short arg3, float arg4);
    void method12(float arg0, unsigned arg1, int arg2, int arg3, short arg4);
    unsigned method13(float arg0, unsigned arg1, float arg2, unsigned arg3, float arg4);
    float method14(float arg0, bool arg1, int arg2, bool arg3, unsigned arg4);

    static double function0(unsigned arg0, double arg1, bool arg2, short arg3, unsigned arg4);
    static unsigned function1(float arg0, double arg1, int arg2, unsigned arg3, bool arg4);
    static void function2(unsigned arg0, short arg1, bool arg2, bool arg3, int arg4);
    static bool function3(bool arg0, double arg1, int arg2, double arg3, double arg4);
    static bool function4(bool arg0, unsigned arg1, unsigned arg2, unsigned arg3, short arg4);
    static double function5(float arg0, double arg1, int arg2, double arg3, int arg4);
    static int function6(int arg0, bool arg1, unsigned arg2, float arg3, float arg4);
    static float function7(bool arg0, float arg1, float arg2, float arg3, float arg4);
    static unsigned function8(double arg0, short arg1, unsigned arg2, bool arg3, int arg4);
    static void function9(unsigned arg0, double arg1, bool arg2, int arg3, double arg4);
    static int function10(bool arg0, bool arg1, int arg2, float arg3, unsigned arg4);
    static unsigned function11(bool arg0, int arg1, bool arg2, int arg3, unsigned arg4);
    static int function12(int arg0, short arg1, int arg2, float arg3, short arg4);
    static void function13(float arg0, short arg1, bool arg2, int arg3, short arg4);
    static void function14(float arg0, double arg1, double arg2, int arg3, double arg4);
};
