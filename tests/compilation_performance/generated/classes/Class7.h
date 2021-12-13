#pragma once

// Generated with seed '88005553542'

#include "../../Common.h"

#include "Class8.h"
#include "Class10.h"
#include "Class11.h"
#include "Class21.h"
#include "Class28.h"
#include "Class29.h"
#include "Class35.h"
#include "Class36.h"
#include "Class56.h"
#include "Class57.h"
#include "Class64.h"
#include "Class65.h"
#include "Class71.h"
#include "Class73.h"
#include "Class74.h"
#include "Class75.h"
#include "Class80.h"
#include "Class83.h"
#include "Class91.h"
#include "Class98.h"

class Class7
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, int arg1, bool arg2, unsigned arg3, bool arg4);
    void method1(float arg0, bool arg1, bool arg2, int arg3, bool arg4);
    float method2(float arg0, float arg1, int arg2, unsigned arg3, int arg4);
    unsigned method3(double arg0, int arg1, unsigned arg2, double arg3, float arg4);
    int method4(bool arg0, double arg1, double arg2, int arg3, int arg4);
    float method5(bool arg0, short arg1, unsigned arg2, int arg3, float arg4);
    void method6(unsigned arg0, int arg1, unsigned arg2, double arg3, float arg4);
    void method7(unsigned arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
    void method8(double arg0, int arg1, unsigned arg2, float arg3, unsigned arg4);
    void method9(double arg0, int arg1, short arg2, int arg3, float arg4);
    void method10(bool arg0, bool arg1, unsigned arg2, double arg3, bool arg4);
    void method11(unsigned arg0, double arg1, int arg2, unsigned arg3, double arg4);
    void method12(unsigned arg0, double arg1, int arg2, double arg3, float arg4);
    bool method13(float arg0, int arg1, int arg2, bool arg3, unsigned arg4);
    bool method14(bool arg0, short arg1, short arg2, double arg3, float arg4);

    static unsigned function0(unsigned arg0, float arg1, float arg2, short arg3, short arg4);
    static int function1(int arg0, double arg1, float arg2, float arg3, int arg4);
    static float function2(bool arg0, bool arg1, double arg2, short arg3, float arg4);
    static int function3(bool arg0, double arg1, double arg2, bool arg3, int arg4);
    static void function4(short arg0, int arg1, float arg2, short arg3, unsigned arg4);
    static bool function5(int arg0, int arg1, float arg2, bool arg3, short arg4);
    static void function6(double arg0, float arg1, int arg2, float arg3, bool arg4);
    static short function7(float arg0, int arg1, short arg2, int arg3, bool arg4);
    static void function8(float arg0, double arg1, unsigned arg2, short arg3, double arg4);
    static void function9(double arg0, int arg1, double arg2, double arg3, bool arg4);
    static void function10(float arg0, int arg1, short arg2, short arg3, short arg4);
    static void function11(unsigned arg0, bool arg1, bool arg2, bool arg3, float arg4);
    static short function12(bool arg0, short arg1, int arg2, short arg3, double arg4);
    static short function13(double arg0, short arg1, float arg2, short arg3, unsigned arg4);
    static void function14(bool arg0, short arg1, unsigned arg2, double arg3, unsigned arg4);
};
