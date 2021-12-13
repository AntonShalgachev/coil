#pragma once

// Generated with seed '88005553628'

#include "../../Common.h"

#include "Class8.h"
#include "Class17.h"
#include "Class23.h"
#include "Class26.h"
#include "Class28.h"
#include "Class32.h"
#include "Class33.h"
#include "Class34.h"
#include "Class36.h"
#include "Class37.h"
#include "Class40.h"
#include "Class46.h"
#include "Class54.h"
#include "Class55.h"
#include "Class60.h"
#include "Class66.h"
#include "Class67.h"
#include "Class92.h"
#include "Class97.h"
#include "Class99.h"

class Class93
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, int arg1, unsigned arg2, unsigned arg3, int arg4);
    void method1(short arg0, double arg1, unsigned arg2, short arg3, bool arg4);
    void method2(double arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    void method3(int arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    void method4(short arg0, float arg1, int arg2, bool arg3, short arg4);
    short method5(double arg0, short arg1, double arg2, int arg3, short arg4);
    void method6(float arg0, int arg1, bool arg2, float arg3, bool arg4);
    void method7(unsigned arg0, int arg1, int arg2, int arg3, int arg4);
    void method8(float arg0, double arg1, bool arg2, unsigned arg3, double arg4);
    void method9(double arg0, float arg1, double arg2, float arg3, unsigned arg4);
    void method10(float arg0, unsigned arg1, bool arg2, int arg3, unsigned arg4);
    float method11(int arg0, float arg1, bool arg2, double arg3, int arg4);
    unsigned method12(unsigned arg0, unsigned arg1, double arg2, unsigned arg3, bool arg4);
    void method13(int arg0, float arg1, double arg2, unsigned arg3, double arg4);
    short method14(short arg0, int arg1, short arg2, int arg3, int arg4);

    static unsigned function0(unsigned arg0, int arg1, unsigned arg2, short arg3, bool arg4);
    static unsigned function1(bool arg0, bool arg1, unsigned arg2, double arg3, unsigned arg4);
    static void function2(bool arg0, float arg1, int arg2, short arg3, int arg4);
    static void function3(float arg0, int arg1, double arg2, unsigned arg3, short arg4);
    static short function4(double arg0, double arg1, bool arg2, short arg3, double arg4);
    static int function5(int arg0, double arg1, double arg2, int arg3, int arg4);
    static double function6(double arg0, double arg1, double arg2, double arg3, int arg4);
    static void function7(float arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    static short function8(int arg0, short arg1, short arg2, short arg3, short arg4);
    static void function9(double arg0, bool arg1, double arg2, float arg3, float arg4);
    static void function10(double arg0, short arg1, short arg2, unsigned arg3, int arg4);
    static int function11(float arg0, unsigned arg1, bool arg2, int arg3, float arg4);
    static void function12(bool arg0, float arg1, double arg2, float arg3, int arg4);
    static void function13(double arg0, unsigned arg1, short arg2, int arg3, float arg4);
    static void function14(bool arg0, double arg1, float arg2, bool arg3, float arg4);
};
