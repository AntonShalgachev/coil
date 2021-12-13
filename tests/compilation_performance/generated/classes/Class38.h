#pragma once

// Generated with seed '88005553573'

#include "../../Common.h"

#include "Class2.h"
#include "Class3.h"
#include "Class6.h"
#include "Class7.h"
#include "Class19.h"
#include "Class21.h"
#include "Class24.h"
#include "Class25.h"
#include "Class27.h"
#include "Class47.h"
#include "Class50.h"
#include "Class62.h"
#include "Class77.h"
#include "Class79.h"
#include "Class85.h"
#include "Class86.h"
#include "Class90.h"
#include "Class91.h"
#include "Class96.h"
#include "Class99.h"

class Class38
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(float arg0, unsigned arg1, short arg2, double arg3, float arg4);
    bool method1(unsigned arg0, short arg1, bool arg2, bool arg3, short arg4);
    void method2(short arg0, bool arg1, short arg2, short arg3, bool arg4);
    float method3(bool arg0, float arg1, bool arg2, int arg3, double arg4);
    int method4(int arg0, short arg1, int arg2, bool arg3, int arg4);
    void method5(float arg0, bool arg1, double arg2, float arg3, double arg4);
    void method6(double arg0, short arg1, short arg2, double arg3, float arg4);
    void method7(bool arg0, int arg1, short arg2, bool arg3, bool arg4);
    float method8(float arg0, double arg1, short arg2, int arg3, float arg4);
    short method9(short arg0, double arg1, float arg2, int arg3, short arg4);
    void method10(unsigned arg0, short arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method11(int arg0, double arg1, short arg2, float arg3, unsigned arg4);
    void method12(int arg0, float arg1, short arg2, float arg3, int arg4);
    void method13(short arg0, float arg1, unsigned arg2, unsigned arg3, double arg4);
    unsigned method14(float arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);

    static bool function0(double arg0, double arg1, bool arg2, float arg3, float arg4);
    static int function1(double arg0, int arg1, unsigned arg2, short arg3, bool arg4);
    static void function2(int arg0, int arg1, float arg2, int arg3, bool arg4);
    static bool function3(unsigned arg0, bool arg1, double arg2, unsigned arg3, unsigned arg4);
    static bool function4(int arg0, short arg1, short arg2, float arg3, bool arg4);
    static void function5(double arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    static void function6(int arg0, double arg1, int arg2, double arg3, int arg4);
    static void function7(double arg0, bool arg1, bool arg2, double arg3, unsigned arg4);
    static void function8(float arg0, float arg1, bool arg2, float arg3, int arg4);
    static void function9(short arg0, bool arg1, int arg2, double arg3, bool arg4);
    static void function10(short arg0, double arg1, float arg2, unsigned arg3, unsigned arg4);
    static void function11(bool arg0, short arg1, double arg2, bool arg3, float arg4);
    static int function12(short arg0, double arg1, double arg2, float arg3, int arg4);
    static int function13(bool arg0, unsigned arg1, int arg2, unsigned arg3, double arg4);
    static unsigned function14(bool arg0, int arg1, unsigned arg2, int arg3, short arg4);
};
