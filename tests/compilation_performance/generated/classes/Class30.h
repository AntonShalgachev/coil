#pragma once

// Generated with seed '88005553565'

#include "../../Common.h"

#include "Class2.h"
#include "Class4.h"
#include "Class8.h"
#include "Class31.h"
#include "Class37.h"
#include "Class42.h"
#include "Class44.h"
#include "Class47.h"
#include "Class48.h"
#include "Class56.h"
#include "Class57.h"
#include "Class60.h"
#include "Class66.h"
#include "Class75.h"
#include "Class76.h"
#include "Class79.h"
#include "Class83.h"
#include "Class95.h"
#include "Class96.h"
#include "Class97.h"

class Class30
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(float arg0, short arg1, int arg2, int arg3, double arg4);
    void method1(int arg0, short arg1, int arg2, float arg3, int arg4);
    void method2(int arg0, unsigned arg1, double arg2, int arg3, unsigned arg4);
    void method3(unsigned arg0, unsigned arg1, int arg2, short arg3, short arg4);
    int method4(int arg0, bool arg1, int arg2, int arg3, float arg4);
    bool method5(double arg0, int arg1, int arg2, double arg3, bool arg4);
    void method6(bool arg0, int arg1, short arg2, float arg3, unsigned arg4);
    void method7(unsigned arg0, double arg1, double arg2, short arg3, double arg4);
    void method8(unsigned arg0, float arg1, short arg2, double arg3, short arg4);
    double method9(float arg0, short arg1, float arg2, double arg3, double arg4);
    void method10(float arg0, short arg1, unsigned arg2, double arg3, float arg4);
    void method11(int arg0, float arg1, bool arg2, bool arg3, float arg4);
    void method12(double arg0, float arg1, float arg2, float arg3, int arg4);
    bool method13(bool arg0, int arg1, short arg2, short arg3, unsigned arg4);
    double method14(float arg0, int arg1, int arg2, int arg3, double arg4);

    static void function0(short arg0, unsigned arg1, float arg2, unsigned arg3, short arg4);
    static unsigned function1(short arg0, double arg1, unsigned arg2, unsigned arg3, float arg4);
    static int function2(unsigned arg0, float arg1, int arg2, float arg3, short arg4);
    static short function3(bool arg0, short arg1, bool arg2, float arg3, int arg4);
    static float function4(bool arg0, bool arg1, float arg2, bool arg3, int arg4);
    static void function5(unsigned arg0, float arg1, double arg2, int arg3, double arg4);
    static short function6(short arg0, short arg1, bool arg2, bool arg3, unsigned arg4);
    static void function7(float arg0, bool arg1, bool arg2, float arg3, short arg4);
    static void function8(double arg0, bool arg1, int arg2, short arg3, int arg4);
    static void function9(int arg0, bool arg1, float arg2, bool arg3, int arg4);
    static short function10(double arg0, short arg1, short arg2, float arg3, int arg4);
    static void function11(int arg0, int arg1, unsigned arg2, bool arg3, int arg4);
    static bool function12(float arg0, short arg1, float arg2, bool arg3, int arg4);
    static void function13(double arg0, bool arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    static void function14(double arg0, float arg1, short arg2, bool arg3, float arg4);
};
