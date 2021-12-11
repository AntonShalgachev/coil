#pragma once

#include "../../Common.h"

class Class56
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, double arg1, bool arg2, double arg3, short arg4);
    double method1(double arg0, float arg1, int arg2, double arg3, bool arg4);
    float method2(bool arg0, float arg1, unsigned arg2, short arg3, int arg4);
    void method3(bool arg0, int arg1, bool arg2, int arg3, unsigned arg4);
    float method4(short arg0, float arg1, double arg2, float arg3, float arg4);
    double method5(double arg0, double arg1, int arg2, short arg3, double arg4);
    void method6(float arg0, short arg1, double arg2, double arg3, float arg4);
    short method7(short arg0, short arg1, unsigned arg2, bool arg3, float arg4);
    void method8(double arg0, double arg1, int arg2, short arg3, int arg4);
    void method9(double arg0, unsigned arg1, short arg2, int arg3, int arg4);
    float method10(float arg0, float arg1, int arg2, unsigned arg3, unsigned arg4);
    void method11(int arg0, bool arg1, unsigned arg2, int arg3, float arg4);
    void method12(double arg0, int arg1, bool arg2, short arg3, unsigned arg4);
    void method13(bool arg0, double arg1, double arg2, double arg3, short arg4);
    bool method14(short arg0, int arg1, short arg2, bool arg3, double arg4);
};

namespace ns_Class56
{
    void method0(int arg0, double arg1, bool arg2, double arg3, short arg4);
    double method1(double arg0, float arg1, int arg2, double arg3, bool arg4);
    float method2(bool arg0, float arg1, unsigned arg2, short arg3, int arg4);
    void method3(bool arg0, int arg1, bool arg2, int arg3, unsigned arg4);
    float method4(short arg0, float arg1, double arg2, float arg3, float arg4);
    double method5(double arg0, double arg1, int arg2, short arg3, double arg4);
    void method6(float arg0, short arg1, double arg2, double arg3, float arg4);
    short method7(short arg0, short arg1, unsigned arg2, bool arg3, float arg4);
    void method8(double arg0, double arg1, int arg2, short arg3, int arg4);
    void method9(double arg0, unsigned arg1, short arg2, int arg3, int arg4);
    float method10(float arg0, float arg1, int arg2, unsigned arg3, unsigned arg4);
    void method11(int arg0, bool arg1, unsigned arg2, int arg3, float arg4);
    void method12(double arg0, int arg1, bool arg2, short arg3, unsigned arg4);
    void method13(bool arg0, double arg1, double arg2, double arg3, short arg4);
    bool method14(short arg0, int arg1, short arg2, bool arg3, double arg4);
}