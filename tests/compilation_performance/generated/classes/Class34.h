#pragma once

#include "../../Common.h"

class Class34
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(int arg0, bool arg1, int arg2, double arg3, bool arg4);
    void method1(unsigned arg0, unsigned arg1, double arg2, float arg3, float arg4);
    void method2(int arg0, bool arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method3(int arg0, double arg1, int arg2, double arg3, double arg4);
    float method4(float arg0, float arg1, double arg2, float arg3, unsigned arg4);
    int method5(bool arg0, short arg1, double arg2, int arg3, int arg4);
    void method6(double arg0, unsigned arg1, int arg2, short arg3, int arg4);
    void method7(unsigned arg0, bool arg1, double arg2, short arg3, int arg4);
    void method8(double arg0, bool arg1, float arg2, float arg3, int arg4);
    bool method9(bool arg0, int arg1, int arg2, float arg3, float arg4);
    void method10(int arg0, short arg1, bool arg2, float arg3, int arg4);
    void method11(float arg0, short arg1, unsigned arg2, int arg3, double arg4);
    bool method12(unsigned arg0, int arg1, bool arg2, double arg3, unsigned arg4);
    void method13(float arg0, short arg1, unsigned arg2, float arg3, double arg4);
    void method14(float arg0, int arg1, unsigned arg2, int arg3, float arg4);
};

namespace ns_Class34
{
    int method0(int arg0, bool arg1, int arg2, double arg3, bool arg4);
    void method1(unsigned arg0, unsigned arg1, double arg2, float arg3, float arg4);
    void method2(int arg0, bool arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method3(int arg0, double arg1, int arg2, double arg3, double arg4);
    float method4(float arg0, float arg1, double arg2, float arg3, unsigned arg4);
    int method5(bool arg0, short arg1, double arg2, int arg3, int arg4);
    void method6(double arg0, unsigned arg1, int arg2, short arg3, int arg4);
    void method7(unsigned arg0, bool arg1, double arg2, short arg3, int arg4);
    void method8(double arg0, bool arg1, float arg2, float arg3, int arg4);
    bool method9(bool arg0, int arg1, int arg2, float arg3, float arg4);
    void method10(int arg0, short arg1, bool arg2, float arg3, int arg4);
    void method11(float arg0, short arg1, unsigned arg2, int arg3, double arg4);
    bool method12(unsigned arg0, int arg1, bool arg2, double arg3, unsigned arg4);
    void method13(float arg0, short arg1, unsigned arg2, float arg3, double arg4);
    void method14(float arg0, int arg1, unsigned arg2, int arg3, float arg4);
}
