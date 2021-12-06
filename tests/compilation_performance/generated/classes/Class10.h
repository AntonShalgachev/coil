#pragma once

#include "../../Common.h"

class Class10
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(double arg0, short arg1, int arg2, float arg3, short arg4);
    void method1(short arg0, int arg1, double arg2, float arg3, double arg4);
    void method2(int arg0, short arg1, int arg2, double arg3, int arg4);
    void method3(bool arg0, short arg1, short arg2, double arg3, unsigned arg4);
    void method4(double arg0, bool arg1, short arg2, int arg3, bool arg4);
    float method5(short arg0, double arg1, float arg2, unsigned arg3, float arg4);
    int method6(bool arg0, double arg1, unsigned arg2, short arg3, int arg4);
    void method7(double arg0, double arg1, double arg2, int arg3, double arg4);
    void method8(double arg0, double arg1, unsigned arg2, bool arg3, int arg4);
    float method9(float arg0, short arg1, bool arg2, double arg3, double arg4);
    void method10(unsigned arg0, bool arg1, double arg2, double arg3, unsigned arg4);
    void method11(bool arg0, double arg1, int arg2, bool arg3, bool arg4);
    void method12(unsigned arg0, int arg1, double arg2, float arg3, bool arg4);
    void method13(bool arg0, double arg1, float arg2, short arg3, unsigned arg4);
    void method14(bool arg0, unsigned arg1, bool arg2, float arg3, bool arg4);
};

namespace ns_Class10
{
    float method0(double arg0, short arg1, int arg2, float arg3, short arg4);
    void method1(short arg0, int arg1, double arg2, float arg3, double arg4);
    void method2(int arg0, short arg1, int arg2, double arg3, int arg4);
    void method3(bool arg0, short arg1, short arg2, double arg3, unsigned arg4);
    void method4(double arg0, bool arg1, short arg2, int arg3, bool arg4);
    float method5(short arg0, double arg1, float arg2, unsigned arg3, float arg4);
    int method6(bool arg0, double arg1, unsigned arg2, short arg3, int arg4);
    void method7(double arg0, double arg1, double arg2, int arg3, double arg4);
    void method8(double arg0, double arg1, unsigned arg2, bool arg3, int arg4);
    float method9(float arg0, short arg1, bool arg2, double arg3, double arg4);
    void method10(unsigned arg0, bool arg1, double arg2, double arg3, unsigned arg4);
    void method11(bool arg0, double arg1, int arg2, bool arg3, bool arg4);
    void method12(unsigned arg0, int arg1, double arg2, float arg3, bool arg4);
    void method13(bool arg0, double arg1, float arg2, short arg3, unsigned arg4);
    void method14(bool arg0, unsigned arg1, bool arg2, float arg3, bool arg4);
}
