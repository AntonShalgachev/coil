#pragma once

// Generated with seed '88005553542'

#include "../../Common.h"

#include "Class6.h"
#include "Class10.h"
#include "Class15.h"
#include "Class24.h"
#include "Class25.h"
#include "Class26.h"
#include "Class29.h"
#include "Class32.h"
#include "Class33.h"
#include "Class35.h"
#include "Class37.h"
#include "Class39.h"
#include "Class47.h"
#include "Class51.h"
#include "Class58.h"
#include "Class61.h"
#include "Class64.h"
#include "Class69.h"
#include "Class70.h"
#include "Class76.h"

class Class7
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(short arg0, bool arg1, unsigned arg2, unsigned arg3, float arg4);
    bool method1(bool arg0, int arg1, double arg2, float arg3, float arg4);
    double method2(short arg0, short arg1, int arg2, double arg3, unsigned arg4);
    float method3(double arg0, double arg1, double arg2, float arg3, short arg4);
    void method4(double arg0, float arg1, unsigned arg2, float arg3, double arg4);
    void method5(float arg0, int arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method6(double arg0, double arg1, short arg2, float arg3, float arg4);
    void method7(bool arg0, float arg1, short arg2, short arg3, int arg4);
    short method8(double arg0, short arg1, float arg2, int arg3, int arg4);
    unsigned method9(float arg0, unsigned arg1, double arg2, short arg3, bool arg4);
    double method10(unsigned arg0, double arg1, double arg2, unsigned arg3, double arg4);
    double method11(float arg0, double arg1, float arg2, unsigned arg3, bool arg4);
    void method12(double arg0, double arg1, short arg2, unsigned arg3, double arg4);
    void method13(bool arg0, float arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method14(int arg0, double arg1, int arg2, double arg3, unsigned arg4);

    static void function0(unsigned arg0, short arg1, bool arg2, short arg3, int arg4);
    static short function1(float arg0, short arg1, bool arg2, short arg3, int arg4);
    static void function2(unsigned arg0, bool arg1, double arg2, bool arg3, unsigned arg4);
    static void function3(short arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    static int function4(bool arg0, unsigned arg1, unsigned arg2, short arg3, int arg4);
    static unsigned function5(short arg0, bool arg1, unsigned arg2, float arg3, short arg4);
    static short function6(double arg0, bool arg1, int arg2, short arg3, unsigned arg4);
    static void function7(int arg0, double arg1, int arg2, unsigned arg3, short arg4);
    static unsigned function8(unsigned arg0, float arg1, double arg2, unsigned arg3, double arg4);
    static void function9(short arg0, bool arg1, double arg2, float arg3, int arg4);
    static void function10(short arg0, bool arg1, bool arg2, double arg3, double arg4);
    static unsigned function11(unsigned arg0, double arg1, unsigned arg2, bool arg3, int arg4);
    static void function12(int arg0, short arg1, double arg2, float arg3, unsigned arg4);
    static void function13(short arg0, bool arg1, int arg2, float arg3, bool arg4);
    static bool function14(bool arg0, short arg1, short arg2, float arg3, float arg4);
};
