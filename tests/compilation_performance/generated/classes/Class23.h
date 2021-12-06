#pragma once

#include "../../Common.h"

class Class23
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(float arg0, float arg1, float arg2, bool arg3, short arg4);
    short method1(short arg0, float arg1, double arg2, unsigned arg3, short arg4);
    void method2(double arg0, double arg1, unsigned arg2, bool arg3, double arg4);
    float method3(short arg0, bool arg1, int arg2, float arg3, bool arg4);
    void method4(bool arg0, float arg1, float arg2, int arg3, short arg4);
    float method5(bool arg0, float arg1, bool arg2, double arg3, double arg4);
    short method6(float arg0, short arg1, bool arg2, double arg3, unsigned arg4);
    void method7(float arg0, double arg1, int arg2, short arg3, bool arg4);
    void method8(float arg0, int arg1, unsigned arg2, float arg3, int arg4);
    double method9(double arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    bool method10(bool arg0, int arg1, float arg2, float arg3, bool arg4);
    unsigned method11(int arg0, float arg1, unsigned arg2, unsigned arg3, int arg4);
    void method12(bool arg0, float arg1, double arg2, bool arg3, short arg4);
    void method13(short arg0, float arg1, unsigned arg2, short arg3, unsigned arg4);
    void method14(int arg0, short arg1, short arg2, float arg3, bool arg4);
};

namespace ns_Class23
{
    float method0(float arg0, float arg1, float arg2, bool arg3, short arg4);
    short method1(short arg0, float arg1, double arg2, unsigned arg3, short arg4);
    void method2(double arg0, double arg1, unsigned arg2, bool arg3, double arg4);
    float method3(short arg0, bool arg1, int arg2, float arg3, bool arg4);
    void method4(bool arg0, float arg1, float arg2, int arg3, short arg4);
    float method5(bool arg0, float arg1, bool arg2, double arg3, double arg4);
    short method6(float arg0, short arg1, bool arg2, double arg3, unsigned arg4);
    void method7(float arg0, double arg1, int arg2, short arg3, bool arg4);
    void method8(float arg0, int arg1, unsigned arg2, float arg3, int arg4);
    double method9(double arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    bool method10(bool arg0, int arg1, float arg2, float arg3, bool arg4);
    unsigned method11(int arg0, float arg1, unsigned arg2, unsigned arg3, int arg4);
    void method12(bool arg0, float arg1, double arg2, bool arg3, short arg4);
    void method13(short arg0, float arg1, unsigned arg2, short arg3, unsigned arg4);
    void method14(int arg0, short arg1, short arg2, float arg3, bool arg4);
}
