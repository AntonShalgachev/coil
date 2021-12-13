#pragma once

// Generated with seed '88005553552'

#include "../../Common.h"

#include "Class3.h"
#include "Class15.h"
#include "Class19.h"
#include "Class20.h"
#include "Class24.h"
#include "Class25.h"
#include "Class27.h"
#include "Class31.h"
#include "Class32.h"
#include "Class39.h"
#include "Class55.h"
#include "Class56.h"
#include "Class59.h"
#include "Class60.h"
#include "Class64.h"
#include "Class68.h"
#include "Class74.h"
#include "Class84.h"
#include "Class93.h"
#include "Class99.h"

class Class17
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(int arg0, float arg1, short arg2, float arg3, int arg4);
    void method1(float arg0, float arg1, bool arg2, float arg3, int arg4);
    void method2(float arg0, int arg1, bool arg2, float arg3, bool arg4);
    void method3(bool arg0, int arg1, int arg2, float arg3, double arg4);
    bool method4(short arg0, bool arg1, short arg2, short arg3, bool arg4);
    void method5(float arg0, unsigned arg1, bool arg2, double arg3, unsigned arg4);
    void method6(bool arg0, float arg1, double arg2, float arg3, float arg4);
    void method7(short arg0, double arg1, float arg2, int arg3, int arg4);
    float method8(float arg0, int arg1, unsigned arg2, int arg3, int arg4);
    void method9(int arg0, float arg1, int arg2, float arg3, unsigned arg4);
    bool method10(unsigned arg0, bool arg1, short arg2, bool arg3, short arg4);
    int method11(double arg0, int arg1, double arg2, unsigned arg3, float arg4);
    bool method12(int arg0, int arg1, bool arg2, float arg3, int arg4);
    bool method13(float arg0, double arg1, float arg2, bool arg3, bool arg4);
    void method14(short arg0, double arg1, double arg2, short arg3, int arg4);

    static void function0(bool arg0, bool arg1, double arg2, short arg3, unsigned arg4);
    static void function1(float arg0, float arg1, unsigned arg2, unsigned arg3, short arg4);
    static bool function2(short arg0, bool arg1, int arg2, bool arg3, short arg4);
    static void function3(short arg0, int arg1, bool arg2, short arg3, int arg4);
    static void function4(int arg0, int arg1, double arg2, unsigned arg3, unsigned arg4);
    static void function5(unsigned arg0, int arg1, int arg2, int arg3, short arg4);
    static double function6(double arg0, double arg1, double arg2, int arg3, double arg4);
    static int function7(float arg0, int arg1, float arg2, short arg3, unsigned arg4);
    static double function8(bool arg0, bool arg1, double arg2, double arg3, short arg4);
    static bool function9(int arg0, bool arg1, short arg2, float arg3, short arg4);
    static unsigned function10(unsigned arg0, int arg1, unsigned arg2, bool arg3, unsigned arg4);
    static float function11(int arg0, double arg1, float arg2, float arg3, double arg4);
    static unsigned function12(unsigned arg0, double arg1, float arg2, bool arg3, double arg4);
    static void function13(unsigned arg0, float arg1, int arg2, unsigned arg3, short arg4);
    static short function14(short arg0, float arg1, double arg2, short arg3, double arg4);
};
