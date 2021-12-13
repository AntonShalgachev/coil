#pragma once

// Generated with seed '88005553567'

#include "../../Common.h"

#include "Class12.h"
#include "Class13.h"
#include "Class14.h"
#include "Class17.h"
#include "Class21.h"
#include "Class29.h"
#include "Class30.h"
#include "Class37.h"
#include "Class38.h"
#include "Class39.h"
#include "Class45.h"
#include "Class49.h"
#include "Class66.h"
#include "Class67.h"
#include "Class70.h"
#include "Class72.h"
#include "Class76.h"
#include "Class81.h"
#include "Class89.h"

class Class32
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(float arg0, unsigned arg1, short arg2, short arg3, float arg4);
    void method1(short arg0, bool arg1, int arg2, int arg3, double arg4);
    unsigned method2(bool arg0, short arg1, short arg2, unsigned arg3, bool arg4);
    void method3(double arg0, float arg1, short arg2, unsigned arg3, float arg4);
    void method4(double arg0, bool arg1, double arg2, int arg3, unsigned arg4);
    float method5(int arg0, int arg1, float arg2, short arg3, unsigned arg4);
    void method6(short arg0, unsigned arg1, unsigned arg2, double arg3, short arg4);
    void method7(int arg0, double arg1, short arg2, double arg3, float arg4);
    void method8(unsigned arg0, unsigned arg1, double arg2, short arg3, int arg4);
    void method9(bool arg0, double arg1, unsigned arg2, float arg3, int arg4);
    short method10(bool arg0, short arg1, bool arg2, double arg3, short arg4);
    int method11(short arg0, int arg1, short arg2, short arg3, int arg4);
    void method12(int arg0, float arg1, bool arg2, int arg3, unsigned arg4);
    bool method13(short arg0, unsigned arg1, bool arg2, bool arg3, unsigned arg4);
    void method14(double arg0, short arg1, unsigned arg2, double arg3, short arg4);

    static void function0(bool arg0, short arg1, bool arg2, int arg3, unsigned arg4);
    static void function1(bool arg0, double arg1, short arg2, float arg3, int arg4);
    static double function2(bool arg0, float arg1, short arg2, double arg3, unsigned arg4);
    static void function3(int arg0, unsigned arg1, float arg2, float arg3, short arg4);
    static void function4(unsigned arg0, float arg1, int arg2, unsigned arg3, bool arg4);
    static void function5(bool arg0, double arg1, unsigned arg2, int arg3, short arg4);
    static unsigned function6(short arg0, unsigned arg1, short arg2, unsigned arg3, bool arg4);
    static short function7(bool arg0, short arg1, double arg2, double arg3, unsigned arg4);
    static void function8(bool arg0, float arg1, bool arg2, unsigned arg3, bool arg4);
    static void function9(short arg0, short arg1, bool arg2, float arg3, bool arg4);
    static double function10(short arg0, float arg1, float arg2, double arg3, unsigned arg4);
    static short function11(short arg0, float arg1, unsigned arg2, short arg3, double arg4);
    static void function12(unsigned arg0, double arg1, float arg2, float arg3, bool arg4);
    static short function13(short arg0, unsigned arg1, int arg2, bool arg3, unsigned arg4);
    static void function14(int arg0, float arg1, double arg2, short arg3, unsigned arg4);
};
