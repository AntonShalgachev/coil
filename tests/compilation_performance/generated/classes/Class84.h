#pragma once

// Generated with seed '88005553619'

#include "../../Common.h"

#include "Class2.h"
#include "Class4.h"
#include "Class5.h"
#include "Class11.h"
#include "Class33.h"
#include "Class37.h"
#include "Class41.h"
#include "Class44.h"
#include "Class46.h"
#include "Class47.h"
#include "Class49.h"
#include "Class50.h"
#include "Class55.h"
#include "Class61.h"
#include "Class62.h"
#include "Class67.h"
#include "Class68.h"
#include "Class77.h"
#include "Class85.h"
#include "Class96.h"

class Class84
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(int arg0, float arg1, bool arg2, int arg3, unsigned arg4);
    unsigned method1(double arg0, unsigned arg1, float arg2, unsigned arg3, int arg4);
    short method2(double arg0, int arg1, int arg2, double arg3, short arg4);
    void method3(short arg0, double arg1, int arg2, unsigned arg3, double arg4);
    int method4(int arg0, bool arg1, double arg2, int arg3, double arg4);
    void method5(int arg0, bool arg1, int arg2, unsigned arg3, double arg4);
    void method6(bool arg0, short arg1, short arg2, bool arg3, int arg4);
    void method7(double arg0, int arg1, double arg2, int arg3, unsigned arg4);
    int method8(double arg0, double arg1, float arg2, int arg3, double arg4);
    void method9(bool arg0, double arg1, float arg2, float arg3, double arg4);
    void method10(bool arg0, bool arg1, bool arg2, double arg3, short arg4);
    void method11(float arg0, double arg1, unsigned arg2, double arg3, unsigned arg4);
    float method12(short arg0, float arg1, short arg2, double arg3, short arg4);
    void method13(bool arg0, short arg1, int arg2, float arg3, int arg4);
    void method14(short arg0, short arg1, float arg2, unsigned arg3, bool arg4);

    static bool function0(bool arg0, unsigned arg1, short arg2, bool arg3, double arg4);
    static void function1(short arg0, float arg1, float arg2, short arg3, int arg4);
    static void function2(double arg0, short arg1, float arg2, unsigned arg3, int arg4);
    static void function3(int arg0, int arg1, int arg2, float arg3, float arg4);
    static float function4(short arg0, float arg1, int arg2, bool arg3, bool arg4);
    static double function5(double arg0, float arg1, short arg2, bool arg3, unsigned arg4);
    static short function6(double arg0, short arg1, float arg2, bool arg3, short arg4);
    static void function7(short arg0, bool arg1, unsigned arg2, unsigned arg3, float arg4);
    static void function8(bool arg0, bool arg1, short arg2, int arg3, int arg4);
    static void function9(bool arg0, short arg1, short arg2, float arg3, bool arg4);
    static bool function10(bool arg0, bool arg1, unsigned arg2, float arg3, double arg4);
    static unsigned function11(unsigned arg0, float arg1, bool arg2, unsigned arg3, unsigned arg4);
    static void function12(unsigned arg0, float arg1, double arg2, bool arg3, short arg4);
    static unsigned function13(unsigned arg0, bool arg1, unsigned arg2, short arg3, short arg4);
    static bool function14(short arg0, bool arg1, double arg2, bool arg3, short arg4);
};
