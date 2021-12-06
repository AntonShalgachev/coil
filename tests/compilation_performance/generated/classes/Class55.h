#pragma once

#include "../../Common.h"

class Class55
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(float arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    void method1(bool arg0, float arg1, int arg2, short arg3, float arg4);
    bool method2(bool arg0, int arg1, unsigned arg2, double arg3, float arg4);
    bool method3(bool arg0, double arg1, short arg2, int arg3, float arg4);
    void method4(int arg0, int arg1, double arg2, double arg3, double arg4);
    float method5(int arg0, double arg1, float arg2, bool arg3, double arg4);
    void method6(float arg0, unsigned arg1, short arg2, bool arg3, bool arg4);
    void method7(int arg0, int arg1, unsigned arg2, short arg3, unsigned arg4);
    void method8(bool arg0, unsigned arg1, float arg2, int arg3, int arg4);
    float method9(unsigned arg0, unsigned arg1, int arg2, float arg3, float arg4);
    double method10(double arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    void method11(double arg0, float arg1, double arg2, unsigned arg3, float arg4);
    void method12(int arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    float method13(bool arg0, float arg1, int arg2, float arg3, unsigned arg4);
    void method14(float arg0, double arg1, int arg2, bool arg3, double arg4);
};

namespace ns_Class55
{
    int method0(float arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    void method1(bool arg0, float arg1, int arg2, short arg3, float arg4);
    bool method2(bool arg0, int arg1, unsigned arg2, double arg3, float arg4);
    bool method3(bool arg0, double arg1, short arg2, int arg3, float arg4);
    void method4(int arg0, int arg1, double arg2, double arg3, double arg4);
    float method5(int arg0, double arg1, float arg2, bool arg3, double arg4);
    void method6(float arg0, unsigned arg1, short arg2, bool arg3, bool arg4);
    void method7(int arg0, int arg1, unsigned arg2, short arg3, unsigned arg4);
    void method8(bool arg0, unsigned arg1, float arg2, int arg3, int arg4);
    float method9(unsigned arg0, unsigned arg1, int arg2, float arg3, float arg4);
    double method10(double arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    void method11(double arg0, float arg1, double arg2, unsigned arg3, float arg4);
    void method12(int arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    float method13(bool arg0, float arg1, int arg2, float arg3, unsigned arg4);
    void method14(float arg0, double arg1, int arg2, bool arg3, double arg4);
}
