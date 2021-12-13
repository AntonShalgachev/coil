#pragma once

// Generated with seed '88005553539'

#include "../../Common.h"

#include "Class9.h"
#include "Class14.h"
#include "Class22.h"
#include "Class26.h"
#include "Class29.h"
#include "Class32.h"
#include "Class37.h"
#include "Class46.h"
#include "Class47.h"
#include "Class48.h"
#include "Class50.h"
#include "Class53.h"
#include "Class55.h"
#include "Class62.h"
#include "Class64.h"
#include "Class77.h"
#include "Class79.h"
#include "Class85.h"
#include "Class91.h"

class Class4
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, bool arg1, bool arg2, unsigned arg3, bool arg4);
    short method1(int arg0, float arg1, unsigned arg2, bool arg3, short arg4);
    float method2(unsigned arg0, float arg1, double arg2, float arg3, float arg4);
    void method3(int arg0, short arg1, bool arg2, unsigned arg3, float arg4);
    bool method4(double arg0, float arg1, int arg2, bool arg3, float arg4);
    void method5(short arg0, short arg1, double arg2, bool arg3, short arg4);
    float method6(double arg0, float arg1, int arg2, short arg3, float arg4);
    int method7(int arg0, bool arg1, bool arg2, bool arg3, bool arg4);
    void method8(bool arg0, double arg1, int arg2, float arg3, unsigned arg4);
    short method9(bool arg0, bool arg1, short arg2, float arg3, double arg4);
    void method10(double arg0, float arg1, short arg2, double arg3, bool arg4);
    short method11(short arg0, short arg1, double arg2, float arg3, short arg4);
    void method12(bool arg0, short arg1, bool arg2, int arg3, double arg4);
    bool method13(double arg0, short arg1, double arg2, short arg3, bool arg4);
    short method14(short arg0, unsigned arg1, unsigned arg2, double arg3, float arg4);

    static void function0(short arg0, unsigned arg1, int arg2, float arg3, bool arg4);
    static void function1(int arg0, bool arg1, bool arg2, double arg3, short arg4);
    static void function2(bool arg0, int arg1, float arg2, float arg3, double arg4);
    static short function3(short arg0, bool arg1, bool arg2, short arg3, float arg4);
    static float function4(bool arg0, double arg1, int arg2, unsigned arg3, float arg4);
    static short function5(bool arg0, short arg1, float arg2, short arg3, unsigned arg4);
    static void function6(float arg0, int arg1, float arg2, short arg3, unsigned arg4);
    static int function7(bool arg0, short arg1, int arg2, short arg3, double arg4);
    static int function8(bool arg0, double arg1, int arg2, float arg3, float arg4);
    static void function9(bool arg0, float arg1, double arg2, bool arg3, int arg4);
    static void function10(double arg0, double arg1, float arg2, double arg3, unsigned arg4);
    static short function11(unsigned arg0, double arg1, short arg2, short arg3, int arg4);
    static int function12(float arg0, unsigned arg1, int arg2, bool arg3, short arg4);
    static void function13(double arg0, unsigned arg1, bool arg2, double arg3, double arg4);
    static void function14(unsigned arg0, bool arg1, float arg2, double arg3, float arg4);
};
