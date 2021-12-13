#pragma once

// Generated with seed '88005553553'

#include "../../Common.h"

#include "Class3.h"
#include "Class6.h"
#include "Class14.h"
#include "Class21.h"
#include "Class29.h"
#include "Class30.h"
#include "Class36.h"
#include "Class37.h"
#include "Class45.h"
#include "Class46.h"
#include "Class48.h"
#include "Class49.h"
#include "Class60.h"
#include "Class64.h"
#include "Class70.h"
#include "Class71.h"
#include "Class78.h"
#include "Class79.h"
#include "Class80.h"
#include "Class96.h"

class Class18
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, unsigned arg1, short arg2, float arg3, float arg4);
    void method1(int arg0, short arg1, double arg2, float arg3, int arg4);
    void method2(unsigned arg0, double arg1, unsigned arg2, unsigned arg3, double arg4);
    void method3(bool arg0, bool arg1, bool arg2, double arg3, double arg4);
    void method4(unsigned arg0, int arg1, bool arg2, unsigned arg3, double arg4);
    void method5(int arg0, short arg1, unsigned arg2, bool arg3, double arg4);
    double method6(bool arg0, bool arg1, double arg2, unsigned arg3, double arg4);
    unsigned method7(unsigned arg0, short arg1, int arg2, double arg3, short arg4);
    void method8(unsigned arg0, short arg1, float arg2, short arg3, double arg4);
    unsigned method9(unsigned arg0, short arg1, bool arg2, int arg3, short arg4);
    void method10(short arg0, double arg1, bool arg2, int arg3, double arg4);
    float method11(bool arg0, double arg1, float arg2, bool arg3, unsigned arg4);
    float method12(unsigned arg0, bool arg1, float arg2, float arg3, float arg4);
    bool method13(bool arg0, bool arg1, short arg2, float arg3, int arg4);
    void method14(float arg0, double arg1, short arg2, float arg3, bool arg4);

    static float function0(unsigned arg0, bool arg1, unsigned arg2, float arg3, unsigned arg4);
    static void function1(unsigned arg0, unsigned arg1, float arg2, bool arg3, unsigned arg4);
    static void function2(double arg0, float arg1, float arg2, double arg3, int arg4);
    static double function3(int arg0, int arg1, double arg2, bool arg3, float arg4);
    static void function4(short arg0, float arg1, bool arg2, short arg3, short arg4);
    static void function5(int arg0, int arg1, int arg2, unsigned arg3, bool arg4);
    static void function6(short arg0, int arg1, double arg2, unsigned arg3, double arg4);
    static void function7(float arg0, float arg1, double arg2, float arg3, bool arg4);
    static void function8(unsigned arg0, bool arg1, double arg2, bool arg3, short arg4);
    static float function9(int arg0, float arg1, int arg2, bool arg3, unsigned arg4);
    static bool function10(float arg0, bool arg1, float arg2, unsigned arg3, short arg4);
    static unsigned function11(double arg0, unsigned arg1, int arg2, float arg3, bool arg4);
    static double function12(bool arg0, bool arg1, unsigned arg2, double arg3, unsigned arg4);
    static float function13(bool arg0, float arg1, bool arg2, bool arg3, double arg4);
    static void function14(float arg0, short arg1, short arg2, int arg3, short arg4);
};
