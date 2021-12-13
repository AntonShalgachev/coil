#pragma once

// Generated with seed '88005553570'

#include "../../Common.h"

#include "Class0.h"
#include "Class2.h"
#include "Class4.h"
#include "Class6.h"
#include "Class11.h"
#include "Class14.h"
#include "Class18.h"
#include "Class25.h"
#include "Class41.h"
#include "Class47.h"
#include "Class48.h"
#include "Class60.h"
#include "Class68.h"
#include "Class73.h"
#include "Class74.h"
#include "Class75.h"
#include "Class76.h"
#include "Class86.h"
#include "Class94.h"
#include "Class96.h"

class Class35
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(float arg0, int arg1, bool arg2, unsigned arg3, short arg4);
    void method1(bool arg0, double arg1, float arg2, short arg3, bool arg4);
    void method2(unsigned arg0, float arg1, float arg2, bool arg3, float arg4);
    int method3(float arg0, int arg1, bool arg2, double arg3, short arg4);
    void method4(double arg0, unsigned arg1, int arg2, bool arg3, float arg4);
    unsigned method5(double arg0, int arg1, double arg2, unsigned arg3, short arg4);
    void method6(unsigned arg0, unsigned arg1, float arg2, unsigned arg3, short arg4);
    void method7(bool arg0, bool arg1, float arg2, short arg3, unsigned arg4);
    void method8(int arg0, short arg1, int arg2, float arg3, bool arg4);
    int method9(unsigned arg0, float arg1, int arg2, int arg3, short arg4);
    unsigned method10(double arg0, unsigned arg1, int arg2, double arg3, short arg4);
    short method11(short arg0, unsigned arg1, unsigned arg2, bool arg3, int arg4);
    void method12(double arg0, short arg1, float arg2, int arg3, double arg4);
    unsigned method13(double arg0, int arg1, short arg2, unsigned arg3, short arg4);
    void method14(bool arg0, int arg1, int arg2, int arg3, bool arg4);

    static unsigned function0(bool arg0, unsigned arg1, unsigned arg2, bool arg3, double arg4);
    static float function1(int arg0, unsigned arg1, unsigned arg2, float arg3, float arg4);
    static int function2(int arg0, float arg1, int arg2, int arg3, bool arg4);
    static void function3(unsigned arg0, double arg1, int arg2, double arg3, unsigned arg4);
    static void function4(unsigned arg0, int arg1, bool arg2, float arg3, float arg4);
    static double function5(double arg0, bool arg1, float arg2, double arg3, float arg4);
    static void function6(bool arg0, unsigned arg1, bool arg2, short arg3, unsigned arg4);
    static void function7(int arg0, short arg1, bool arg2, bool arg3, short arg4);
    static void function8(short arg0, double arg1, bool arg2, double arg3, bool arg4);
    static void function9(short arg0, unsigned arg1, float arg2, bool arg3, unsigned arg4);
    static unsigned function10(short arg0, unsigned arg1, float arg2, unsigned arg3, double arg4);
    static float function11(unsigned arg0, float arg1, short arg2, float arg3, float arg4);
    static int function12(double arg0, int arg1, unsigned arg2, double arg3, unsigned arg4);
    static unsigned function13(unsigned arg0, double arg1, int arg2, unsigned arg3, int arg4);
    static double function14(double arg0, unsigned arg1, int arg2, float arg3, double arg4);
};
