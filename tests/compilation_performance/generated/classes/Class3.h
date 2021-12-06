#pragma once

#include "../../Common.h"

class Class3
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(float arg0, bool arg1, short arg2, short arg3, bool arg4);
    void method1(short arg0, double arg1, unsigned arg2, double arg3, double arg4);
    int method2(int arg0, double arg1, unsigned arg2, short arg3, short arg4);
    void method3(double arg0, bool arg1, double arg2, double arg3, unsigned arg4);
    void method4(int arg0, double arg1, float arg2, float arg3, short arg4);
    void method5(unsigned arg0, unsigned arg1, short arg2, unsigned arg3, double arg4);
    double method6(double arg0, double arg1, short arg2, int arg3, float arg4);
    void method7(short arg0, unsigned arg1, int arg2, unsigned arg3, float arg4);
    void method8(float arg0, unsigned arg1, double arg2, int arg3, unsigned arg4);
    int method9(int arg0, short arg1, short arg2, float arg3, double arg4);
    int method10(float arg0, float arg1, bool arg2, int arg3, int arg4);
    bool method11(double arg0, unsigned arg1, bool arg2, unsigned arg3, bool arg4);
    void method12(double arg0, int arg1, float arg2, unsigned arg3, float arg4);
    int method13(int arg0, int arg1, short arg2, int arg3, bool arg4);
    void method14(double arg0, unsigned arg1, float arg2, double arg3, float arg4);
};

namespace ns_Class3
{
    float method0(float arg0, bool arg1, short arg2, short arg3, bool arg4);
    void method1(short arg0, double arg1, unsigned arg2, double arg3, double arg4);
    int method2(int arg0, double arg1, unsigned arg2, short arg3, short arg4);
    void method3(double arg0, bool arg1, double arg2, double arg3, unsigned arg4);
    void method4(int arg0, double arg1, float arg2, float arg3, short arg4);
    void method5(unsigned arg0, unsigned arg1, short arg2, unsigned arg3, double arg4);
    double method6(double arg0, double arg1, short arg2, int arg3, float arg4);
    void method7(short arg0, unsigned arg1, int arg2, unsigned arg3, float arg4);
    void method8(float arg0, unsigned arg1, double arg2, int arg3, unsigned arg4);
    int method9(int arg0, short arg1, short arg2, float arg3, double arg4);
    int method10(float arg0, float arg1, bool arg2, int arg3, int arg4);
    bool method11(double arg0, unsigned arg1, bool arg2, unsigned arg3, bool arg4);
    void method12(double arg0, int arg1, float arg2, unsigned arg3, float arg4);
    int method13(int arg0, int arg1, short arg2, int arg3, bool arg4);
    void method14(double arg0, unsigned arg1, float arg2, double arg3, float arg4);
}
