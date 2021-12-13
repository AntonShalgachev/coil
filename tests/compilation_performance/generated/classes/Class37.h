#pragma once

// Generated with seed '88005553572'

#include "../../Common.h"

#include "Class8.h"
#include "Class11.h"
#include "Class12.h"
#include "Class17.h"
#include "Class21.h"
#include "Class22.h"
#include "Class25.h"
#include "Class26.h"
#include "Class28.h"
#include "Class46.h"
#include "Class47.h"
#include "Class48.h"
#include "Class55.h"
#include "Class65.h"
#include "Class78.h"
#include "Class80.h"
#include "Class86.h"
#include "Class94.h"
#include "Class97.h"

class Class37
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(int arg0, unsigned arg1, int arg2, int arg3, float arg4);
    int method1(unsigned arg0, int arg1, double arg2, unsigned arg3, int arg4);
    void method2(short arg0, int arg1, int arg2, bool arg3, double arg4);
    void method3(double arg0, bool arg1, float arg2, short arg3, float arg4);
    void method4(unsigned arg0, int arg1, float arg2, float arg3, bool arg4);
    bool method5(unsigned arg0, short arg1, bool arg2, short arg3, int arg4);
    void method6(bool arg0, int arg1, int arg2, bool arg3, int arg4);
    void method7(short arg0, unsigned arg1, double arg2, int arg3, short arg4);
    double method8(double arg0, int arg1, unsigned arg2, int arg3, unsigned arg4);
    void method9(int arg0, short arg1, unsigned arg2, short arg3, unsigned arg4);
    void method10(short arg0, double arg1, double arg2, double arg3, double arg4);
    bool method11(unsigned arg0, int arg1, double arg2, bool arg3, int arg4);
    double method12(int arg0, float arg1, float arg2, double arg3, int arg4);
    void method13(double arg0, short arg1, int arg2, bool arg3, double arg4);
    int method14(float arg0, int arg1, unsigned arg2, bool arg3, short arg4);

    static void function0(bool arg0, int arg1, float arg2, int arg3, int arg4);
    static short function1(short arg0, short arg1, unsigned arg2, bool arg3, double arg4);
    static void function2(unsigned arg0, int arg1, int arg2, unsigned arg3, float arg4);
    static void function3(int arg0, float arg1, bool arg2, float arg3, bool arg4);
    static float function4(bool arg0, float arg1, double arg2, unsigned arg3, float arg4);
    static void function5(bool arg0, int arg1, short arg2, short arg3, float arg4);
    static int function6(double arg0, float arg1, unsigned arg2, int arg3, float arg4);
    static int function7(int arg0, float arg1, double arg2, double arg3, unsigned arg4);
    static double function8(double arg0, float arg1, short arg2, double arg3, short arg4);
    static void function9(short arg0, int arg1, int arg2, short arg3, short arg4);
    static void function10(int arg0, bool arg1, short arg2, int arg3, bool arg4);
    static int function11(int arg0, double arg1, float arg2, short arg3, int arg4);
    static bool function12(unsigned arg0, unsigned arg1, short arg2, unsigned arg3, bool arg4);
    static float function13(float arg0, float arg1, bool arg2, float arg3, unsigned arg4);
    static bool function14(short arg0, double arg1, bool arg2, unsigned arg3, bool arg4);
};
