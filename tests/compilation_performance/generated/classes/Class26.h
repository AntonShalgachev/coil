#pragma once

// Generated with seed '88005553561'

#include "../../Common.h"

#include "Class1.h"
#include "Class10.h"
#include "Class13.h"
#include "Class14.h"
#include "Class19.h"
#include "Class25.h"
#include "Class32.h"
#include "Class33.h"
#include "Class36.h"
#include "Class37.h"
#include "Class44.h"
#include "Class50.h"
#include "Class52.h"
#include "Class75.h"
#include "Class76.h"
#include "Class78.h"
#include "Class79.h"
#include "Class83.h"
#include "Class90.h"
#include "Class92.h"

class Class26
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(short arg0, unsigned arg1, int arg2, double arg3, bool arg4);
    void method1(short arg0, int arg1, float arg2, float arg3, float arg4);
    void method2(int arg0, double arg1, float arg2, int arg3, double arg4);
    void method3(unsigned arg0, bool arg1, unsigned arg2, float arg3, bool arg4);
    void method4(int arg0, bool arg1, int arg2, bool arg3, int arg4);
    double method5(float arg0, int arg1, double arg2, double arg3, double arg4);
    int method6(bool arg0, unsigned arg1, bool arg2, bool arg3, int arg4);
    float method7(float arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    bool method8(bool arg0, bool arg1, int arg2, double arg3, double arg4);
    short method9(unsigned arg0, float arg1, unsigned arg2, float arg3, short arg4);
    int method10(int arg0, float arg1, unsigned arg2, unsigned arg3, int arg4);
    double method11(bool arg0, double arg1, bool arg2, double arg3, bool arg4);
    bool method12(unsigned arg0, bool arg1, bool arg2, bool arg3, bool arg4);
    void method13(unsigned arg0, double arg1, int arg2, bool arg3, unsigned arg4);
    void method14(double arg0, unsigned arg1, int arg2, unsigned arg3, bool arg4);

    static void function0(bool arg0, int arg1, int arg2, double arg3, bool arg4);
    static float function1(bool arg0, float arg1, unsigned arg2, float arg3, short arg4);
    static int function2(double arg0, int arg1, short arg2, bool arg3, bool arg4);
    static void function3(unsigned arg0, bool arg1, int arg2, float arg3, short arg4);
    static int function4(short arg0, int arg1, unsigned arg2, int arg3, short arg4);
    static void function5(double arg0, short arg1, bool arg2, bool arg3, double arg4);
    static int function6(float arg0, int arg1, short arg2, int arg3, double arg4);
    static bool function7(int arg0, int arg1, bool arg2, bool arg3, float arg4);
    static int function8(bool arg0, int arg1, bool arg2, short arg3, bool arg4);
    static void function9(int arg0, double arg1, int arg2, double arg3, float arg4);
    static short function10(short arg0, bool arg1, short arg2, int arg3, int arg4);
    static double function11(float arg0, double arg1, float arg2, unsigned arg3, int arg4);
    static void function12(float arg0, unsigned arg1, double arg2, double arg3, int arg4);
    static void function13(int arg0, unsigned arg1, short arg2, int arg3, short arg4);
    static void function14(unsigned arg0, short arg1, float arg2, bool arg3, unsigned arg4);
};
