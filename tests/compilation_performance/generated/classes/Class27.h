#pragma once

#include "../../Common.h"

class Class27
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, int arg1, short arg2, float arg3, unsigned arg4);
    void method1(unsigned arg0, unsigned arg1, bool arg2, double arg3, double arg4);
    void method2(double arg0, double arg1, double arg2, short arg3, short arg4);
    void method3(unsigned arg0, int arg1, unsigned arg2, int arg3, short arg4);
    void method4(double arg0, double arg1, float arg2, unsigned arg3, int arg4);
    unsigned method5(unsigned arg0, double arg1, short arg2, int arg3, unsigned arg4);
    void method6(float arg0, bool arg1, float arg2, unsigned arg3, bool arg4);
    void method7(int arg0, float arg1, int arg2, unsigned arg3, double arg4);
    double method8(bool arg0, unsigned arg1, unsigned arg2, unsigned arg3, double arg4);
    float method9(double arg0, short arg1, int arg2, float arg3, unsigned arg4);
    void method10(double arg0, bool arg1, float arg2, float arg3, float arg4);
    void method11(int arg0, int arg1, int arg2, float arg3, float arg4);
    unsigned method12(float arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    void method13(double arg0, unsigned arg1, float arg2, int arg3, double arg4);
    void method14(int arg0, float arg1, unsigned arg2, short arg3, int arg4);
};

namespace ns_Class27
{
    void method0(double arg0, int arg1, short arg2, float arg3, unsigned arg4);
    void method1(unsigned arg0, unsigned arg1, bool arg2, double arg3, double arg4);
    void method2(double arg0, double arg1, double arg2, short arg3, short arg4);
    void method3(unsigned arg0, int arg1, unsigned arg2, int arg3, short arg4);
    void method4(double arg0, double arg1, float arg2, unsigned arg3, int arg4);
    unsigned method5(unsigned arg0, double arg1, short arg2, int arg3, unsigned arg4);
    void method6(float arg0, bool arg1, float arg2, unsigned arg3, bool arg4);
    void method7(int arg0, float arg1, int arg2, unsigned arg3, double arg4);
    double method8(bool arg0, unsigned arg1, unsigned arg2, unsigned arg3, double arg4);
    float method9(double arg0, short arg1, int arg2, float arg3, unsigned arg4);
    void method10(double arg0, bool arg1, float arg2, float arg3, float arg4);
    void method11(int arg0, int arg1, int arg2, float arg3, float arg4);
    unsigned method12(float arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    void method13(double arg0, unsigned arg1, float arg2, int arg3, double arg4);
    void method14(int arg0, float arg1, unsigned arg2, short arg3, int arg4);
}
