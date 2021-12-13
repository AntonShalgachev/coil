#pragma once

// Generated with seed '88005553540'

#include "../../Common.h"

#include "Class2.h"
#include "Class8.h"
#include "Class22.h"
#include "Class23.h"
#include "Class28.h"
#include "Class31.h"
#include "Class37.h"
#include "Class38.h"
#include "Class48.h"
#include "Class50.h"
#include "Class54.h"
#include "Class61.h"
#include "Class62.h"
#include "Class63.h"
#include "Class73.h"
#include "Class75.h"
#include "Class76.h"
#include "Class80.h"
#include "Class83.h"
#include "Class99.h"

class Class5
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(int arg0, short arg1, bool arg2, float arg3, unsigned arg4);
    int method1(float arg0, unsigned arg1, int arg2, double arg3, int arg4);
    unsigned method2(bool arg0, unsigned arg1, unsigned arg2, short arg3, int arg4);
    void method3(int arg0, bool arg1, unsigned arg2, double arg3, unsigned arg4);
    void method4(short arg0, float arg1, bool arg2, float arg3, float arg4);
    int method5(float arg0, bool arg1, short arg2, bool arg3, int arg4);
    short method6(short arg0, double arg1, double arg2, short arg3, int arg4);
    int method7(float arg0, int arg1, float arg2, bool arg3, bool arg4);
    float method8(float arg0, float arg1, float arg2, bool arg3, bool arg4);
    short method9(unsigned arg0, short arg1, double arg2, short arg3, bool arg4);
    void method10(int arg0, unsigned arg1, short arg2, double arg3, bool arg4);
    void method11(unsigned arg0, float arg1, double arg2, double arg3, unsigned arg4);
    void method12(double arg0, short arg1, short arg2, short arg3, int arg4);
    int method13(int arg0, bool arg1, int arg2, int arg3, short arg4);
    short method14(short arg0, double arg1, double arg2, float arg3, double arg4);

    static float function0(float arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    static double function1(double arg0, double arg1, unsigned arg2, double arg3, unsigned arg4);
    static void function2(short arg0, unsigned arg1, double arg2, float arg3, float arg4);
    static void function3(short arg0, unsigned arg1, int arg2, double arg3, bool arg4);
    static void function4(unsigned arg0, bool arg1, unsigned arg2, int arg3, int arg4);
    static void function5(float arg0, unsigned arg1, unsigned arg2, unsigned arg3, bool arg4);
    static void function6(double arg0, double arg1, bool arg2, int arg3, float arg4);
    static unsigned function7(double arg0, unsigned arg1, unsigned arg2, bool arg3, unsigned arg4);
    static void function8(bool arg0, bool arg1, int arg2, float arg3, short arg4);
    static int function9(float arg0, double arg1, int arg2, double arg3, short arg4);
    static void function10(int arg0, unsigned arg1, double arg2, bool arg3, double arg4);
    static bool function11(bool arg0, unsigned arg1, bool arg2, short arg3, int arg4);
    static void function12(bool arg0, short arg1, int arg2, double arg3, float arg4);
    static double function13(short arg0, double arg1, float arg2, float arg3, double arg4);
    static void function14(float arg0, double arg1, float arg2, double arg3, double arg4);
};
