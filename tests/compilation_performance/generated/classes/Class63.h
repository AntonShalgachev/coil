#pragma once

// Generated with seed '88005553598'

#include "../../Common.h"

#include "Class2.h"
#include "Class7.h"
#include "Class10.h"
#include "Class16.h"
#include "Class26.h"
#include "Class28.h"
#include "Class29.h"
#include "Class38.h"
#include "Class39.h"
#include "Class43.h"
#include "Class51.h"
#include "Class56.h"
#include "Class64.h"
#include "Class66.h"
#include "Class69.h"
#include "Class72.h"
#include "Class75.h"
#include "Class85.h"
#include "Class86.h"
#include "Class89.h"

class Class63
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(float arg0, double arg1, double arg2, int arg3, short arg4);
    unsigned method1(float arg0, short arg1, float arg2, unsigned arg3, unsigned arg4);
    unsigned method2(short arg0, unsigned arg1, float arg2, float arg3, float arg4);
    void method3(int arg0, bool arg1, unsigned arg2, double arg3, unsigned arg4);
    int method4(int arg0, float arg1, short arg2, bool arg3, float arg4);
    bool method5(short arg0, bool arg1, float arg2, unsigned arg3, double arg4);
    void method6(bool arg0, unsigned arg1, short arg2, bool arg3, unsigned arg4);
    void method7(int arg0, unsigned arg1, short arg2, float arg3, float arg4);
    void method8(float arg0, double arg1, unsigned arg2, int arg3, bool arg4);
    void method9(double arg0, unsigned arg1, short arg2, unsigned arg3, bool arg4);
    short method10(bool arg0, unsigned arg1, short arg2, short arg3, bool arg4);
    double method11(double arg0, double arg1, short arg2, bool arg3, float arg4);
    bool method12(bool arg0, bool arg1, double arg2, short arg3, double arg4);
    void method13(bool arg0, unsigned arg1, int arg2, short arg3, float arg4);
    double method14(double arg0, float arg1, int arg2, unsigned arg3, unsigned arg4);

    static float function0(short arg0, bool arg1, double arg2, float arg3, double arg4);
    static void function1(int arg0, bool arg1, double arg2, bool arg3, bool arg4);
    static void function2(int arg0, int arg1, int arg2, unsigned arg3, double arg4);
    static void function3(double arg0, float arg1, int arg2, bool arg3, float arg4);
    static int function4(float arg0, float arg1, int arg2, float arg3, unsigned arg4);
    static bool function5(bool arg0, double arg1, int arg2, bool arg3, unsigned arg4);
    static void function6(short arg0, bool arg1, bool arg2, short arg3, bool arg4);
    static int function7(bool arg0, float arg1, bool arg2, unsigned arg3, int arg4);
    static int function8(bool arg0, int arg1, short arg2, double arg3, unsigned arg4);
    static int function9(float arg0, int arg1, unsigned arg2, bool arg3, int arg4);
    static void function10(unsigned arg0, bool arg1, bool arg2, int arg3, short arg4);
    static void function11(float arg0, double arg1, bool arg2, double arg3, double arg4);
    static bool function12(short arg0, float arg1, short arg2, bool arg3, int arg4);
    static void function13(short arg0, float arg1, float arg2, double arg3, int arg4);
    static float function14(short arg0, float arg1, float arg2, double arg3, bool arg4);
};
