#pragma once

// Generated with seed '88005553622'

#include "../../Common.h"

#include "Class9.h"
#include "Class11.h"
#include "Class12.h"
#include "Class16.h"
#include "Class18.h"
#include "Class19.h"
#include "Class26.h"
#include "Class40.h"
#include "Class45.h"
#include "Class46.h"
#include "Class51.h"
#include "Class60.h"
#include "Class63.h"
#include "Class67.h"
#include "Class72.h"
#include "Class81.h"
#include "Class84.h"
#include "Class86.h"
#include "Class93.h"
#include "Class94.h"

class Class87
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(float arg0, bool arg1, bool arg2, unsigned arg3, float arg4);
    void method1(float arg0, double arg1, short arg2, double arg3, short arg4);
    void method2(int arg0, int arg1, short arg2, float arg3, int arg4);
    void method3(int arg0, bool arg1, short arg2, float arg3, bool arg4);
    void method4(unsigned arg0, short arg1, float arg2, bool arg3, unsigned arg4);
    void method5(bool arg0, bool arg1, float arg2, int arg3, short arg4);
    float method6(float arg0, bool arg1, int arg2, bool arg3, int arg4);
    bool method7(bool arg0, float arg1, float arg2, short arg3, short arg4);
    short method8(short arg0, double arg1, unsigned arg2, short arg3, double arg4);
    int method9(double arg0, double arg1, unsigned arg2, int arg3, short arg4);
    void method10(bool arg0, bool arg1, short arg2, unsigned arg3, float arg4);
    unsigned method11(unsigned arg0, short arg1, unsigned arg2, unsigned arg3, double arg4);
    unsigned method12(short arg0, unsigned arg1, float arg2, float arg3, bool arg4);
    void method13(short arg0, unsigned arg1, int arg2, unsigned arg3, int arg4);
    unsigned method14(double arg0, double arg1, bool arg2, unsigned arg3, bool arg4);

    static void function0(float arg0, double arg1, unsigned arg2, float arg3, double arg4);
    static double function1(float arg0, bool arg1, bool arg2, double arg3, bool arg4);
    static short function2(int arg0, short arg1, int arg2, unsigned arg3, bool arg4);
    static void function3(bool arg0, bool arg1, short arg2, double arg3, short arg4);
    static void function4(unsigned arg0, unsigned arg1, bool arg2, float arg3, unsigned arg4);
    static short function5(bool arg0, bool arg1, short arg2, bool arg3, int arg4);
    static void function6(double arg0, short arg1, unsigned arg2, short arg3, short arg4);
    static unsigned function7(unsigned arg0, double arg1, short arg2, int arg3, float arg4);
    static void function8(double arg0, int arg1, unsigned arg2, bool arg3, double arg4);
    static void function9(float arg0, bool arg1, int arg2, float arg3, short arg4);
    static void function10(int arg0, bool arg1, short arg2, unsigned arg3, float arg4);
    static void function11(float arg0, unsigned arg1, unsigned arg2, float arg3, int arg4);
    static unsigned function12(double arg0, bool arg1, short arg2, unsigned arg3, bool arg4);
    static unsigned function13(unsigned arg0, double arg1, float arg2, unsigned arg3, double arg4);
    static void function14(double arg0, bool arg1, int arg2, bool arg3, float arg4);
};
