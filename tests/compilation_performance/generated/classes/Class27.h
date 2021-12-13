#pragma once

// Generated with seed '88005553562'

#include "../../Common.h"

#include "Class1.h"
#include "Class2.h"
#include "Class15.h"
#include "Class17.h"
#include "Class20.h"
#include "Class21.h"
#include "Class30.h"
#include "Class52.h"
#include "Class55.h"
#include "Class56.h"
#include "Class58.h"
#include "Class64.h"
#include "Class71.h"
#include "Class74.h"
#include "Class75.h"
#include "Class79.h"
#include "Class80.h"
#include "Class90.h"
#include "Class93.h"

class Class27
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, unsigned arg1, bool arg2, double arg3, float arg4);
    void method1(short arg0, double arg1, int arg2, int arg3, float arg4);
    bool method2(double arg0, unsigned arg1, unsigned arg2, bool arg3, bool arg4);
    void method3(short arg0, int arg1, float arg2, unsigned arg3, int arg4);
    void method4(bool arg0, unsigned arg1, short arg2, int arg3, int arg4);
    float method5(bool arg0, int arg1, float arg2, double arg3, short arg4);
    void method6(int arg0, float arg1, bool arg2, int arg3, double arg4);
    void method7(double arg0, int arg1, short arg2, short arg3, short arg4);
    void method8(int arg0, double arg1, float arg2, float arg3, bool arg4);
    float method9(short arg0, int arg1, double arg2, short arg3, float arg4);
    void method10(float arg0, double arg1, bool arg2, short arg3, int arg4);
    void method11(bool arg0, double arg1, bool arg2, unsigned arg3, int arg4);
    short method12(bool arg0, float arg1, short arg2, double arg3, int arg4);
    void method13(unsigned arg0, bool arg1, int arg2, int arg3, int arg4);
    void method14(double arg0, double arg1, bool arg2, float arg3, int arg4);

    static double function0(float arg0, bool arg1, int arg2, double arg3, bool arg4);
    static void function1(float arg0, int arg1, float arg2, float arg3, short arg4);
    static void function2(float arg0, int arg1, double arg2, double arg3, int arg4);
    static void function3(int arg0, int arg1, bool arg2, int arg3, short arg4);
    static void function4(float arg0, unsigned arg1, double arg2, bool arg3, bool arg4);
    static void function5(int arg0, unsigned arg1, int arg2, short arg3, short arg4);
    static void function6(int arg0, int arg1, int arg2, int arg3, bool arg4);
    static void function7(unsigned arg0, unsigned arg1, int arg2, short arg3, short arg4);
    static bool function8(short arg0, bool arg1, unsigned arg2, int arg3, short arg4);
    static double function9(double arg0, short arg1, short arg2, float arg3, unsigned arg4);
    static void function10(int arg0, double arg1, short arg2, float arg3, short arg4);
    static void function11(int arg0, float arg1, int arg2, short arg3, unsigned arg4);
    static void function12(double arg0, float arg1, bool arg2, short arg3, short arg4);
    static unsigned function13(short arg0, bool arg1, double arg2, int arg3, unsigned arg4);
    static short function14(double arg0, unsigned arg1, unsigned arg2, short arg3, short arg4);
};
