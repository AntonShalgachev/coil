#pragma once

// Generated with seed '88005553541'

#include "../../Common.h"

#include "Class2.h"
#include "Class8.h"
#include "Class9.h"
#include "Class12.h"
#include "Class13.h"
#include "Class16.h"
#include "Class23.h"
#include "Class28.h"
#include "Class33.h"
#include "Class36.h"
#include "Class41.h"
#include "Class44.h"
#include "Class53.h"
#include "Class55.h"
#include "Class59.h"
#include "Class67.h"
#include "Class68.h"
#include "Class80.h"
#include "Class98.h"
#include "Class99.h"

class Class6
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, unsigned arg1, float arg2, bool arg3, bool arg4);
    short method1(double arg0, unsigned arg1, short arg2, bool arg3, unsigned arg4);
    bool method2(unsigned arg0, float arg1, bool arg2, bool arg3, short arg4);
    void method3(double arg0, bool arg1, unsigned arg2, int arg3, int arg4);
    double method4(int arg0, float arg1, bool arg2, double arg3, bool arg4);
    float method5(double arg0, float arg1, unsigned arg2, short arg3, unsigned arg4);
    bool method6(unsigned arg0, float arg1, bool arg2, bool arg3, int arg4);
    int method7(short arg0, int arg1, double arg2, bool arg3, bool arg4);
    void method8(double arg0, int arg1, double arg2, int arg3, bool arg4);
    void method9(int arg0, double arg1, unsigned arg2, short arg3, int arg4);
    void method10(unsigned arg0, short arg1, double arg2, short arg3, unsigned arg4);
    void method11(int arg0, bool arg1, unsigned arg2, bool arg3, double arg4);
    void method12(bool arg0, double arg1, unsigned arg2, int arg3, int arg4);
    void method13(double arg0, bool arg1, double arg2, unsigned arg3, int arg4);
    void method14(short arg0, short arg1, short arg2, float arg3, unsigned arg4);

    static void function0(float arg0, bool arg1, double arg2, unsigned arg3, float arg4);
    static void function1(float arg0, short arg1, short arg2, unsigned arg3, bool arg4);
    static void function2(unsigned arg0, short arg1, bool arg2, int arg3, unsigned arg4);
    static void function3(short arg0, unsigned arg1, unsigned arg2, float arg3, float arg4);
    static double function4(unsigned arg0, float arg1, double arg2, bool arg3, int arg4);
    static float function5(double arg0, float arg1, float arg2, float arg3, unsigned arg4);
    static void function6(bool arg0, int arg1, unsigned arg2, short arg3, unsigned arg4);
    static int function7(bool arg0, short arg1, float arg2, double arg3, int arg4);
    static void function8(bool arg0, int arg1, double arg2, short arg3, float arg4);
    static void function9(float arg0, float arg1, unsigned arg2, double arg3, short arg4);
    static void function10(short arg0, bool arg1, short arg2, float arg3, bool arg4);
    static float function11(float arg0, float arg1, bool arg2, int arg3, double arg4);
    static float function12(short arg0, unsigned arg1, float arg2, unsigned arg3, unsigned arg4);
    static unsigned function13(short arg0, short arg1, unsigned arg2, int arg3, short arg4);
    static unsigned function14(bool arg0, unsigned arg1, double arg2, unsigned arg3, double arg4);
};
