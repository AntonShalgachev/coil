#pragma once

// Generated with seed '88005553599'

#include "../../Common.h"

#include "Class6.h"
#include "Class10.h"
#include "Class21.h"
#include "Class30.h"
#include "Class31.h"
#include "Class39.h"
#include "Class40.h"
#include "Class43.h"
#include "Class51.h"
#include "Class52.h"
#include "Class54.h"
#include "Class56.h"
#include "Class57.h"
#include "Class59.h"
#include "Class66.h"
#include "Class73.h"
#include "Class78.h"
#include "Class84.h"
#include "Class95.h"

class Class64
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, float arg1, int arg2, int arg3, unsigned arg4);
    void method1(int arg0, short arg1, unsigned arg2, bool arg3, short arg4);
    short method2(double arg0, float arg1, short arg2, int arg3, bool arg4);
    void method3(bool arg0, short arg1, float arg2, double arg3, unsigned arg4);
    void method4(double arg0, short arg1, float arg2, unsigned arg3, unsigned arg4);
    void method5(bool arg0, short arg1, bool arg2, short arg3, int arg4);
    void method6(float arg0, double arg1, int arg2, short arg3, double arg4);
    void method7(short arg0, bool arg1, float arg2, float arg3, unsigned arg4);
    double method8(double arg0, unsigned arg1, double arg2, int arg3, bool arg4);
    short method9(double arg0, short arg1, float arg2, short arg3, double arg4);
    double method10(bool arg0, int arg1, short arg2, double arg3, int arg4);
    float method11(unsigned arg0, float arg1, int arg2, bool arg3, float arg4);
    void method12(int arg0, short arg1, float arg2, short arg3, float arg4);
    unsigned method13(bool arg0, unsigned arg1, short arg2, short arg3, float arg4);
    bool method14(bool arg0, unsigned arg1, short arg2, unsigned arg3, float arg4);

    static double function0(float arg0, bool arg1, double arg2, double arg3, unsigned arg4);
    static short function1(float arg0, short arg1, double arg2, unsigned arg3, float arg4);
    static void function2(bool arg0, unsigned arg1, bool arg2, short arg3, short arg4);
    static float function3(bool arg0, unsigned arg1, bool arg2, unsigned arg3, float arg4);
    static double function4(int arg0, float arg1, double arg2, int arg3, double arg4);
    static double function5(double arg0, double arg1, double arg2, short arg3, short arg4);
    static void function6(unsigned arg0, bool arg1, int arg2, bool arg3, bool arg4);
    static int function7(int arg0, short arg1, bool arg2, float arg3, int arg4);
    static void function8(bool arg0, unsigned arg1, short arg2, unsigned arg3, unsigned arg4);
    static double function9(bool arg0, float arg1, short arg2, double arg3, unsigned arg4);
    static unsigned function10(unsigned arg0, unsigned arg1, int arg2, float arg3, bool arg4);
    static unsigned function11(double arg0, float arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    static double function12(int arg0, int arg1, int arg2, unsigned arg3, double arg4);
    static void function13(double arg0, double arg1, float arg2, double arg3, double arg4);
    static void function14(float arg0, unsigned arg1, double arg2, short arg3, int arg4);
};
