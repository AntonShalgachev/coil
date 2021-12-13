#pragma once

// Generated with seed '88005553554'

#include "../../Common.h"

#include "Class0.h"
#include "Class1.h"
#include "Class8.h"
#include "Class14.h"
#include "Class15.h"
#include "Class16.h"
#include "Class20.h"
#include "Class24.h"
#include "Class32.h"
#include "Class34.h"
#include "Class42.h"
#include "Class43.h"
#include "Class55.h"
#include "Class62.h"
#include "Class68.h"
#include "Class71.h"
#include "Class82.h"
#include "Class90.h"
#include "Class94.h"
#include "Class98.h"

class Class19
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(bool arg0, bool arg1, double arg2, unsigned arg3, unsigned arg4);
    bool method1(int arg0, unsigned arg1, bool arg2, float arg3, double arg4);
    void method2(unsigned arg0, int arg1, bool arg2, double arg3, int arg4);
    void method3(float arg0, unsigned arg1, float arg2, int arg3, double arg4);
    double method4(int arg0, double arg1, bool arg2, bool arg3, bool arg4);
    void method5(int arg0, bool arg1, float arg2, unsigned arg3, unsigned arg4);
    void method6(int arg0, int arg1, short arg2, unsigned arg3, short arg4);
    void method7(unsigned arg0, int arg1, bool arg2, float arg3, bool arg4);
    void method8(bool arg0, unsigned arg1, short arg2, unsigned arg3, int arg4);
    short method9(unsigned arg0, short arg1, bool arg2, float arg3, short arg4);
    void method10(bool arg0, double arg1, short arg2, int arg3, bool arg4);
    void method11(float arg0, float arg1, int arg2, double arg3, double arg4);
    unsigned method12(int arg0, int arg1, short arg2, unsigned arg3, int arg4);
    double method13(double arg0, bool arg1, unsigned arg2, double arg3, short arg4);
    short method14(short arg0, unsigned arg1, short arg2, bool arg3, short arg4);

    static void function0(double arg0, float arg1, double arg2, unsigned arg3, short arg4);
    static void function1(int arg0, bool arg1, unsigned arg2, int arg3, int arg4);
    static void function2(float arg0, double arg1, short arg2, unsigned arg3, bool arg4);
    static void function3(unsigned arg0, float arg1, short arg2, short arg3, int arg4);
    static void function4(short arg0, float arg1, short arg2, double arg3, short arg4);
    static void function5(bool arg0, float arg1, short arg2, short arg3, int arg4);
    static unsigned function6(float arg0, bool arg1, unsigned arg2, float arg3, bool arg4);
    static unsigned function7(unsigned arg0, float arg1, int arg2, short arg3, unsigned arg4);
    static void function8(double arg0, float arg1, short arg2, short arg3, double arg4);
    static float function9(bool arg0, float arg1, float arg2, double arg3, float arg4);
    static float function10(unsigned arg0, short arg1, float arg2, unsigned arg3, float arg4);
    static float function11(int arg0, bool arg1, unsigned arg2, bool arg3, float arg4);
    static unsigned function12(unsigned arg0, float arg1, unsigned arg2, double arg3, double arg4);
    static int function13(float arg0, int arg1, unsigned arg2, bool arg3, double arg4);
    static void function14(short arg0, float arg1, float arg2, short arg3, int arg4);
};
