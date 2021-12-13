#pragma once

// Generated with seed '88005553567'

#include "../../Common.h"

#include "Class1.h"
#include "Class2.h"
#include "Class4.h"
#include "Class25.h"
#include "Class36.h"
#include "Class41.h"
#include "Class42.h"
#include "Class47.h"
#include "Class51.h"
#include "Class57.h"
#include "Class60.h"
#include "Class61.h"
#include "Class62.h"
#include "Class63.h"
#include "Class68.h"
#include "Class72.h"
#include "Class74.h"
#include "Class83.h"
#include "Class92.h"
#include "Class96.h"

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
};

namespace ns_Class32
{
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
}
