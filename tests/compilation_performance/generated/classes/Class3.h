#pragma once

// Generated with seed '88005553538'

#include "../../Common.h"

#include "Class5.h"
#include "Class11.h"
#include "Class15.h"
#include "Class23.h"
#include "Class25.h"
#include "Class28.h"
#include "Class31.h"
#include "Class32.h"
#include "Class33.h"
#include "Class35.h"
#include "Class40.h"
#include "Class45.h"
#include "Class56.h"
#include "Class59.h"
#include "Class66.h"
#include "Class74.h"
#include "Class76.h"
#include "Class80.h"
#include "Class95.h"
#include "Class97.h"

class Class3
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(int arg0, float arg1, double arg2, unsigned arg3, unsigned arg4);
    void method1(unsigned arg0, double arg1, double arg2, float arg3, unsigned arg4);
    void method2(float arg0, unsigned arg1, float arg2, int arg3, float arg4);
    void method3(short arg0, unsigned arg1, unsigned arg2, bool arg3, bool arg4);
    void method4(unsigned arg0, int arg1, unsigned arg2, unsigned arg3, double arg4);
    int method5(unsigned arg0, double arg1, double arg2, double arg3, int arg4);
    double method6(double arg0, unsigned arg1, unsigned arg2, double arg3, float arg4);
    bool method7(int arg0, bool arg1, bool arg2, float arg3, float arg4);
    double method8(short arg0, float arg1, unsigned arg2, double arg3, double arg4);
    unsigned method9(double arg0, int arg1, unsigned arg2, float arg3, int arg4);
    double method10(int arg0, int arg1, double arg2, float arg3, double arg4);
    unsigned method11(double arg0, bool arg1, float arg2, unsigned arg3, bool arg4);
    void method12(unsigned arg0, int arg1, double arg2, int arg3, unsigned arg4);
    void method13(int arg0, unsigned arg1, double arg2, double arg3, int arg4);
    void method14(bool arg0, double arg1, int arg2, int arg3, unsigned arg4);

    static float function0(float arg0, unsigned arg1, float arg2, bool arg3, double arg4);
    static void function1(unsigned arg0, float arg1, short arg2, short arg3, bool arg4);
    static double function2(double arg0, float arg1, int arg2, short arg3, double arg4);
    static void function3(float arg0, bool arg1, unsigned arg2, float arg3, float arg4);
    static float function4(float arg0, float arg1, unsigned arg2, short arg3, float arg4);
    static void function5(bool arg0, double arg1, float arg2, unsigned arg3, bool arg4);
    static void function6(float arg0, unsigned arg1, short arg2, double arg3, unsigned arg4);
    static short function7(float arg0, short arg1, unsigned arg2, bool arg3, int arg4);
    static void function8(double arg0, bool arg1, int arg2, int arg3, int arg4);
    static unsigned function9(unsigned arg0, bool arg1, bool arg2, bool arg3, short arg4);
    static void function10(unsigned arg0, bool arg1, float arg2, short arg3, float arg4);
    static void function11(bool arg0, unsigned arg1, double arg2, bool arg3, unsigned arg4);
    static void function12(short arg0, unsigned arg1, short arg2, int arg3, float arg4);
    static int function13(int arg0, short arg1, double arg2, unsigned arg3, int arg4);
    static int function14(int arg0, double arg1, int arg2, float arg3, int arg4);
};
