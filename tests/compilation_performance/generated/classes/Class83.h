#pragma once

// Generated with seed '88005553618'

#include "../../Common.h"

#include "Class1.h"
#include "Class2.h"
#include "Class4.h"
#include "Class5.h"
#include "Class13.h"
#include "Class17.h"
#include "Class24.h"
#include "Class25.h"
#include "Class37.h"
#include "Class38.h"
#include "Class41.h"
#include "Class45.h"
#include "Class55.h"
#include "Class59.h"
#include "Class61.h"
#include "Class80.h"
#include "Class94.h"
#include "Class96.h"
#include "Class98.h"

class Class83
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(double arg0, bool arg1, float arg2, unsigned arg3, double arg4);
    bool method1(unsigned arg0, int arg1, unsigned arg2, bool arg3, float arg4);
    unsigned method2(unsigned arg0, short arg1, float arg2, short arg3, bool arg4);
    void method3(short arg0, short arg1, bool arg2, unsigned arg3, bool arg4);
    unsigned method4(float arg0, unsigned arg1, unsigned arg2, short arg3, short arg4);
    void method5(int arg0, float arg1, double arg2, float arg3, int arg4);
    void method6(double arg0, short arg1, short arg2, double arg3, int arg4);
    void method7(short arg0, unsigned arg1, float arg2, double arg3, bool arg4);
    bool method8(bool arg0, bool arg1, unsigned arg2, int arg3, short arg4);
    short method9(short arg0, float arg1, int arg2, int arg3, unsigned arg4);
    void method10(bool arg0, float arg1, unsigned arg2, double arg3, double arg4);
    bool method11(float arg0, bool arg1, int arg2, unsigned arg3, float arg4);
    void method12(bool arg0, bool arg1, short arg2, unsigned arg3, short arg4);
    void method13(float arg0, double arg1, double arg2, float arg3, int arg4);
    void method14(bool arg0, int arg1, unsigned arg2, bool arg3, double arg4);

    static void function0(bool arg0, float arg1, int arg2, short arg3, int arg4);
    static void function1(short arg0, double arg1, unsigned arg2, short arg3, bool arg4);
    static short function2(unsigned arg0, unsigned arg1, bool arg2, int arg3, short arg4);
    static void function3(int arg0, unsigned arg1, double arg2, short arg3, unsigned arg4);
    static short function4(bool arg0, short arg1, short arg2, unsigned arg3, int arg4);
    static bool function5(bool arg0, bool arg1, float arg2, short arg3, short arg4);
    static short function6(int arg0, int arg1, float arg2, double arg3, short arg4);
    static void function7(float arg0, int arg1, bool arg2, bool arg3, int arg4);
    static int function8(int arg0, unsigned arg1, bool arg2, float arg3, bool arg4);
    static void function9(unsigned arg0, float arg1, float arg2, double arg3, int arg4);
    static void function10(short arg0, short arg1, int arg2, float arg3, short arg4);
    static void function11(unsigned arg0, float arg1, bool arg2, double arg3, bool arg4);
    static unsigned function12(float arg0, short arg1, float arg2, unsigned arg3, bool arg4);
    static void function13(float arg0, int arg1, double arg2, short arg3, int arg4);
    static void function14(bool arg0, int arg1, bool arg2, double arg3, unsigned arg4);
};
