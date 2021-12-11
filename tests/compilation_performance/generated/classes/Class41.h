#pragma once

#include "../../Common.h"

class Class41
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, short arg1, int arg2, double arg3, short arg4);
    int method1(double arg0, float arg1, bool arg2, int arg3, double arg4);
    float method2(float arg0, unsigned arg1, int arg2, double arg3, bool arg4);
    short method3(short arg0, bool arg1, bool arg2, bool arg3, float arg4);
    double method4(double arg0, double arg1, bool arg2, float arg3, float arg4);
    void method5(int arg0, int arg1, int arg2, unsigned arg3, unsigned arg4);
    void method6(bool arg0, unsigned arg1, float arg2, float arg3, int arg4);
    void method7(unsigned arg0, double arg1, int arg2, int arg3, short arg4);
    void method8(short arg0, unsigned arg1, unsigned arg2, bool arg3, int arg4);
    double method9(unsigned arg0, double arg1, double arg2, bool arg3, float arg4);
    short method10(short arg0, int arg1, bool arg2, bool arg3, short arg4);
    short method11(unsigned arg0, short arg1, short arg2, short arg3, double arg4);
    unsigned method12(float arg0, bool arg1, double arg2, int arg3, unsigned arg4);
    void method13(bool arg0, short arg1, int arg2, bool arg3, float arg4);
    int method14(bool arg0, double arg1, unsigned arg2, int arg3, int arg4);
};

namespace ns_Class41
{
    void method0(short arg0, short arg1, int arg2, double arg3, short arg4);
    int method1(double arg0, float arg1, bool arg2, int arg3, double arg4);
    float method2(float arg0, unsigned arg1, int arg2, double arg3, bool arg4);
    short method3(short arg0, bool arg1, bool arg2, bool arg3, float arg4);
    double method4(double arg0, double arg1, bool arg2, float arg3, float arg4);
    void method5(int arg0, int arg1, int arg2, unsigned arg3, unsigned arg4);
    void method6(bool arg0, unsigned arg1, float arg2, float arg3, int arg4);
    void method7(unsigned arg0, double arg1, int arg2, int arg3, short arg4);
    void method8(short arg0, unsigned arg1, unsigned arg2, bool arg3, int arg4);
    double method9(unsigned arg0, double arg1, double arg2, bool arg3, float arg4);
    short method10(short arg0, int arg1, bool arg2, bool arg3, short arg4);
    short method11(unsigned arg0, short arg1, short arg2, short arg3, double arg4);
    unsigned method12(float arg0, bool arg1, double arg2, int arg3, unsigned arg4);
    void method13(bool arg0, short arg1, int arg2, bool arg3, float arg4);
    int method14(bool arg0, double arg1, unsigned arg2, int arg3, int arg4);
}