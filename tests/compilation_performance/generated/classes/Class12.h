#pragma once

// Generated with seed '88005553547'

#include "../../Common.h"

#include "Class3.h"
#include "Class6.h"
#include "Class10.h"
#include "Class14.h"
#include "Class15.h"
#include "Class18.h"
#include "Class19.h"
#include "Class24.h"
#include "Class29.h"
#include "Class30.h"
#include "Class40.h"
#include "Class46.h"
#include "Class51.h"
#include "Class56.h"
#include "Class59.h"
#include "Class62.h"
#include "Class65.h"
#include "Class66.h"
#include "Class72.h"
#include "Class73.h"

class Class12
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(int arg0, unsigned arg1, float arg2, double arg3, short arg4);
    void method1(unsigned arg0, int arg1, double arg2, float arg3, bool arg4);
    int method2(int arg0, unsigned arg1, int arg2, double arg3, int arg4);
    float method3(int arg0, double arg1, float arg2, bool arg3, int arg4);
    void method4(short arg0, float arg1, int arg2, unsigned arg3, short arg4);
    void method5(bool arg0, unsigned arg1, float arg2, int arg3, short arg4);
    short method6(bool arg0, bool arg1, short arg2, short arg3, float arg4);
    void method7(float arg0, unsigned arg1, double arg2, unsigned arg3, float arg4);
    bool method8(int arg0, unsigned arg1, int arg2, int arg3, bool arg4);
    unsigned method9(short arg0, unsigned arg1, bool arg2, short arg3, unsigned arg4);
    void method10(short arg0, int arg1, short arg2, double arg3, float arg4);
    bool method11(int arg0, bool arg1, bool arg2, short arg3, bool arg4);
    void method12(bool arg0, short arg1, int arg2, double arg3, short arg4);
    void method13(float arg0, int arg1, float arg2, short arg3, int arg4);
    void method14(unsigned arg0, double arg1, unsigned arg2, double arg3, double arg4);

    static unsigned function0(bool arg0, bool arg1, float arg2, unsigned arg3, bool arg4);
    static void function1(bool arg0, bool arg1, int arg2, unsigned arg3, int arg4);
    static void function2(short arg0, double arg1, bool arg2, unsigned arg3, int arg4);
    static float function3(unsigned arg0, float arg1, bool arg2, bool arg3, float arg4);
    static void function4(short arg0, unsigned arg1, short arg2, short arg3, bool arg4);
    static double function5(double arg0, bool arg1, float arg2, unsigned arg3, double arg4);
    static void function6(bool arg0, short arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    static int function7(unsigned arg0, double arg1, double arg2, short arg3, int arg4);
    static unsigned function8(bool arg0, int arg1, double arg2, unsigned arg3, short arg4);
    static void function9(double arg0, unsigned arg1, bool arg2, short arg3, double arg4);
    static bool function10(float arg0, unsigned arg1, int arg2, unsigned arg3, bool arg4);
    static unsigned function11(unsigned arg0, double arg1, unsigned arg2, unsigned arg3, short arg4);
    static void function12(unsigned arg0, bool arg1, unsigned arg2, double arg3, float arg4);
    static double function13(double arg0, double arg1, unsigned arg2, unsigned arg3, double arg4);
    static void function14(short arg0, double arg1, short arg2, bool arg3, unsigned arg4);
};
