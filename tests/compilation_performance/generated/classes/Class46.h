#pragma once

// Generated with seed '88005553581'

#include "../../Common.h"

#include "Class1.h"
#include "Class2.h"
#include "Class6.h"
#include "Class8.h"
#include "Class9.h"
#include "Class12.h"
#include "Class18.h"
#include "Class37.h"
#include "Class42.h"
#include "Class50.h"
#include "Class51.h"
#include "Class57.h"
#include "Class58.h"
#include "Class59.h"
#include "Class64.h"
#include "Class68.h"
#include "Class69.h"
#include "Class75.h"
#include "Class80.h"
#include "Class88.h"

class Class46
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, unsigned arg1, unsigned arg2, bool arg3, bool arg4);
    short method1(unsigned arg0, unsigned arg1, unsigned arg2, short arg3, unsigned arg4);
    void method2(int arg0, short arg1, int arg2, bool arg3, unsigned arg4);
    unsigned method3(float arg0, unsigned arg1, float arg2, float arg3, int arg4);
    void method4(unsigned arg0, unsigned arg1, short arg2, int arg3, float arg4);
    float method5(unsigned arg0, double arg1, bool arg2, double arg3, float arg4);
    void method6(float arg0, float arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    unsigned method7(unsigned arg0, short arg1, unsigned arg2, int arg3, float arg4);
    void method8(short arg0, bool arg1, int arg2, unsigned arg3, short arg4);
    void method9(unsigned arg0, double arg1, unsigned arg2, short arg3, float arg4);
    float method10(unsigned arg0, int arg1, float arg2, float arg3, short arg4);
    void method11(unsigned arg0, float arg1, bool arg2, bool arg3, float arg4);
    void method12(unsigned arg0, unsigned arg1, float arg2, unsigned arg3, short arg4);
    void method13(bool arg0, double arg1, int arg2, unsigned arg3, short arg4);
    void method14(int arg0, float arg1, short arg2, float arg3, bool arg4);

    static void function0(unsigned arg0, short arg1, bool arg2, unsigned arg3, double arg4);
    static double function1(short arg0, double arg1, int arg2, double arg3, int arg4);
    static void function2(int arg0, int arg1, bool arg2, bool arg3, bool arg4);
    static double function3(bool arg0, bool arg1, double arg2, int arg3, double arg4);
    static float function4(float arg0, double arg1, int arg2, short arg3, bool arg4);
    static void function5(double arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    static double function6(bool arg0, float arg1, bool arg2, double arg3, float arg4);
    static void function7(float arg0, bool arg1, int arg2, short arg3, bool arg4);
    static void function8(int arg0, unsigned arg1, bool arg2, unsigned arg3, short arg4);
    static double function9(int arg0, bool arg1, unsigned arg2, float arg3, double arg4);
    static short function10(float arg0, short arg1, short arg2, short arg3, bool arg4);
    static void function11(bool arg0, bool arg1, double arg2, float arg3, bool arg4);
    static void function12(float arg0, unsigned arg1, short arg2, short arg3, int arg4);
    static void function13(short arg0, bool arg1, short arg2, unsigned arg3, double arg4);
    static void function14(int arg0, short arg1, int arg2, double arg3, bool arg4);
};
