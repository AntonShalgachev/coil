#pragma once

// Generated with seed '88005553620'

#include "../../Common.h"

#include "Class2.h"
#include "Class9.h"
#include "Class10.h"
#include "Class15.h"
#include "Class26.h"
#include "Class27.h"
#include "Class34.h"
#include "Class35.h"
#include "Class36.h"
#include "Class41.h"
#include "Class42.h"
#include "Class51.h"
#include "Class54.h"
#include "Class56.h"
#include "Class60.h"
#include "Class61.h"
#include "Class64.h"
#include "Class66.h"
#include "Class83.h"

class Class85
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(unsigned arg0, float arg1, int arg2, double arg3, int arg4);
    bool method1(double arg0, double arg1, int arg2, int arg3, bool arg4);
    short method2(short arg0, short arg1, bool arg2, short arg3, short arg4);
    unsigned method3(double arg0, unsigned arg1, float arg2, short arg3, float arg4);
    void method4(bool arg0, int arg1, int arg2, int arg3, double arg4);
    float method5(int arg0, short arg1, float arg2, int arg3, double arg4);
    void method6(unsigned arg0, short arg1, int arg2, unsigned arg3, int arg4);
    void method7(bool arg0, short arg1, double arg2, float arg3, short arg4);
    float method8(float arg0, unsigned arg1, float arg2, float arg3, double arg4);
    short method9(double arg0, bool arg1, short arg2, double arg3, float arg4);
    void method10(short arg0, int arg1, bool arg2, bool arg3, float arg4);
    unsigned method11(unsigned arg0, bool arg1, short arg2, unsigned arg3, double arg4);
    void method12(float arg0, bool arg1, short arg2, int arg3, short arg4);
    void method13(short arg0, short arg1, float arg2, unsigned arg3, int arg4);
    int method14(int arg0, int arg1, bool arg2, double arg3, unsigned arg4);

    static void function0(unsigned arg0, int arg1, bool arg2, int arg3, float arg4);
    static void function1(unsigned arg0, float arg1, bool arg2, float arg3, double arg4);
    static short function2(short arg0, int arg1, short arg2, bool arg3, double arg4);
    static void function3(unsigned arg0, double arg1, short arg2, bool arg3, double arg4);
    static void function4(short arg0, int arg1, unsigned arg2, short arg3, float arg4);
    static void function5(short arg0, int arg1, bool arg2, int arg3, short arg4);
    static void function6(double arg0, float arg1, int arg2, unsigned arg3, double arg4);
    static void function7(short arg0, double arg1, bool arg2, unsigned arg3, double arg4);
    static void function8(float arg0, unsigned arg1, bool arg2, unsigned arg3, short arg4);
    static unsigned function9(int arg0, double arg1, unsigned arg2, float arg3, double arg4);
    static unsigned function10(bool arg0, unsigned arg1, bool arg2, unsigned arg3, short arg4);
    static double function11(int arg0, unsigned arg1, short arg2, double arg3, int arg4);
    static void function12(bool arg0, unsigned arg1, float arg2, short arg3, float arg4);
    static double function13(double arg0, double arg1, bool arg2, short arg3, float arg4);
    static float function14(float arg0, double arg1, double arg2, double arg3, float arg4);
};
