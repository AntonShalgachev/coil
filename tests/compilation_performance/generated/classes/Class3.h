#pragma once

// Generated with seed '88005553538'

#include "../../Common.h"

#include "Class23.h"
#include "Class26.h"
#include "Class28.h"
#include "Class29.h"
#include "Class31.h"
#include "Class33.h"
#include "Class41.h"
#include "Class43.h"
#include "Class45.h"
#include "Class50.h"
#include "Class53.h"
#include "Class66.h"
#include "Class72.h"
#include "Class76.h"
#include "Class79.h"
#include "Class84.h"
#include "Class87.h"
#include "Class88.h"
#include "Class89.h"
#include "Class90.h"

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
};

namespace ns_Class3
{
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
}
