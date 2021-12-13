#pragma once

// Generated with seed '88005553577'

#include "../../Common.h"

#include "Class1.h"
#include "Class7.h"
#include "Class14.h"
#include "Class17.h"
#include "Class20.h"
#include "Class23.h"
#include "Class26.h"
#include "Class32.h"
#include "Class45.h"
#include "Class46.h"
#include "Class56.h"
#include "Class58.h"
#include "Class60.h"
#include "Class68.h"
#include "Class71.h"
#include "Class79.h"
#include "Class93.h"
#include "Class98.h"
#include "Class99.h"

class Class42
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(float arg0, unsigned arg1, bool arg2, bool arg3, int arg4);
    int method1(int arg0, int arg1, short arg2, double arg3, double arg4);
    void method2(short arg0, short arg1, unsigned arg2, bool arg3, short arg4);
    void method3(double arg0, bool arg1, double arg2, int arg3, bool arg4);
    void method4(double arg0, bool arg1, short arg2, bool arg3, float arg4);
    unsigned method5(unsigned arg0, short arg1, short arg2, short arg3, bool arg4);
    double method6(float arg0, double arg1, unsigned arg2, bool arg3, float arg4);
    void method7(int arg0, float arg1, short arg2, int arg3, float arg4);
    int method8(int arg0, int arg1, unsigned arg2, bool arg3, short arg4);
    double method9(short arg0, double arg1, short arg2, short arg3, short arg4);
    void method10(bool arg0, unsigned arg1, unsigned arg2, float arg3, unsigned arg4);
    void method11(bool arg0, short arg1, bool arg2, float arg3, bool arg4);
    void method12(float arg0, float arg1, float arg2, bool arg3, unsigned arg4);
    unsigned method13(double arg0, double arg1, unsigned arg2, bool arg3, int arg4);
    void method14(short arg0, unsigned arg1, short arg2, short arg3, short arg4);

    static unsigned function0(unsigned arg0, bool arg1, int arg2, bool arg3, bool arg4);
    static void function1(short arg0, int arg1, bool arg2, bool arg3, unsigned arg4);
    static float function2(float arg0, bool arg1, float arg2, float arg3, int arg4);
    static unsigned function3(unsigned arg0, int arg1, float arg2, unsigned arg3, unsigned arg4);
    static void function4(short arg0, unsigned arg1, double arg2, float arg3, unsigned arg4);
    static void function5(bool arg0, float arg1, int arg2, bool arg3, bool arg4);
    static int function6(int arg0, int arg1, unsigned arg2, short arg3, unsigned arg4);
    static double function7(short arg0, short arg1, double arg2, bool arg3, bool arg4);
    static bool function8(bool arg0, int arg1, short arg2, float arg3, unsigned arg4);
    static bool function9(short arg0, double arg1, unsigned arg2, bool arg3, bool arg4);
    static unsigned function10(short arg0, bool arg1, unsigned arg2, unsigned arg3, bool arg4);
    static unsigned function11(double arg0, short arg1, double arg2, unsigned arg3, float arg4);
    static bool function12(short arg0, short arg1, int arg2, unsigned arg3, bool arg4);
    static double function13(short arg0, double arg1, bool arg2, unsigned arg3, float arg4);
    static bool function14(double arg0, unsigned arg1, int arg2, bool arg3, float arg4);
};
