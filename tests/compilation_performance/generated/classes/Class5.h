#pragma once

// Generated with seed '88005553540'

#include "../../Common.h"

#include "Class1.h"
#include "Class6.h"
#include "Class7.h"
#include "Class9.h"
#include "Class13.h"
#include "Class16.h"
#include "Class21.h"
#include "Class23.h"
#include "Class26.h"
#include "Class30.h"
#include "Class33.h"
#include "Class39.h"
#include "Class40.h"
#include "Class57.h"
#include "Class71.h"
#include "Class73.h"
#include "Class85.h"
#include "Class91.h"
#include "Class96.h"

class Class5
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, float arg1, float arg2, unsigned arg3, short arg4);
    bool method1(bool arg0, int arg1, bool arg2, int arg3, int arg4);
    void method2(int arg0, double arg1, double arg2, float arg3, bool arg4);
    void method3(bool arg0, short arg1, short arg2, unsigned arg3, float arg4);
    void method4(float arg0, int arg1, short arg2, int arg3, short arg4);
    void method5(float arg0, double arg1, unsigned arg2, bool arg3, unsigned arg4);
    void method6(unsigned arg0, int arg1, float arg2, short arg3, int arg4);
    float method7(double arg0, int arg1, float arg2, bool arg3, unsigned arg4);
    int method8(float arg0, int arg1, float arg2, unsigned arg3, double arg4);
    void method9(float arg0, double arg1, short arg2, int arg3, unsigned arg4);
    void method10(double arg0, short arg1, int arg2, unsigned arg3, unsigned arg4);
    void method11(double arg0, unsigned arg1, short arg2, bool arg3, bool arg4);
    void method12(int arg0, int arg1, double arg2, float arg3, unsigned arg4);
    float method13(double arg0, double arg1, float arg2, double arg3, double arg4);
    int method14(bool arg0, int arg1, bool arg2, unsigned arg3, int arg4);

    static void function0(double arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    static bool function1(float arg0, int arg1, short arg2, bool arg3, int arg4);
    static short function2(unsigned arg0, short arg1, float arg2, bool arg3, short arg4);
    static float function3(float arg0, unsigned arg1, float arg2, double arg3, unsigned arg4);
    static double function4(double arg0, bool arg1, int arg2, int arg3, unsigned arg4);
    static void function5(short arg0, float arg1, double arg2, double arg3, float arg4);
    static float function6(int arg0, unsigned arg1, int arg2, float arg3, double arg4);
    static bool function7(bool arg0, bool arg1, unsigned arg2, float arg3, int arg4);
    static void function8(float arg0, float arg1, double arg2, unsigned arg3, bool arg4);
    static void function9(float arg0, short arg1, unsigned arg2, bool arg3, short arg4);
    static void function10(float arg0, short arg1, short arg2, float arg3, unsigned arg4);
    static short function11(short arg0, double arg1, double arg2, short arg3, bool arg4);
    static bool function12(unsigned arg0, unsigned arg1, int arg2, bool arg3, float arg4);
    static void function13(unsigned arg0, bool arg1, unsigned arg2, unsigned arg3, bool arg4);
    static bool function14(bool arg0, int arg1, bool arg2, int arg3, float arg4);
};
