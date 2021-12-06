#pragma once

#include "../../Common.h"

class Class83
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(int arg0, float arg1, double arg2, double arg3, float arg4);
    void method1(unsigned arg0, float arg1, short arg2, unsigned arg3, float arg4);
    float method2(unsigned arg0, short arg1, float arg2, int arg3, short arg4);
    unsigned method3(double arg0, double arg1, bool arg2, unsigned arg3, float arg4);
    bool method4(float arg0, bool arg1, bool arg2, unsigned arg3, float arg4);
    void method5(bool arg0, int arg1, int arg2, bool arg3, int arg4);
    void method6(int arg0, bool arg1, unsigned arg2, bool arg3, unsigned arg4);
    double method7(int arg0, double arg1, bool arg2, unsigned arg3, short arg4);
    void method8(unsigned arg0, bool arg1, bool arg2, unsigned arg3, double arg4);
    int method9(unsigned arg0, double arg1, int arg2, float arg3, unsigned arg4);
    void method10(float arg0, unsigned arg1, int arg2, short arg3, unsigned arg4);
    void method11(bool arg0, unsigned arg1, bool arg2, unsigned arg3, short arg4);
    void method12(float arg0, short arg1, unsigned arg2, bool arg3, unsigned arg4);
    int method13(float arg0, float arg1, float arg2, int arg3, unsigned arg4);
    void method14(unsigned arg0, float arg1, short arg2, int arg3, float arg4);
};

namespace ns_Class83
{
    int method0(int arg0, float arg1, double arg2, double arg3, float arg4);
    void method1(unsigned arg0, float arg1, short arg2, unsigned arg3, float arg4);
    float method2(unsigned arg0, short arg1, float arg2, int arg3, short arg4);
    unsigned method3(double arg0, double arg1, bool arg2, unsigned arg3, float arg4);
    bool method4(float arg0, bool arg1, bool arg2, unsigned arg3, float arg4);
    void method5(bool arg0, int arg1, int arg2, bool arg3, int arg4);
    void method6(int arg0, bool arg1, unsigned arg2, bool arg3, unsigned arg4);
    double method7(int arg0, double arg1, bool arg2, unsigned arg3, short arg4);
    void method8(unsigned arg0, bool arg1, bool arg2, unsigned arg3, double arg4);
    int method9(unsigned arg0, double arg1, int arg2, float arg3, unsigned arg4);
    void method10(float arg0, unsigned arg1, int arg2, short arg3, unsigned arg4);
    void method11(bool arg0, unsigned arg1, bool arg2, unsigned arg3, short arg4);
    void method12(float arg0, short arg1, unsigned arg2, bool arg3, unsigned arg4);
    int method13(float arg0, float arg1, float arg2, int arg3, unsigned arg4);
    void method14(unsigned arg0, float arg1, short arg2, int arg3, float arg4);
}
