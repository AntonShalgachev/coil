#pragma once

#include "../../Common.h"

class Class57
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(int arg0, bool arg1, short arg2, int arg3, short arg4);
    double method1(short arg0, double arg1, unsigned arg2, int arg3, float arg4);
    unsigned method2(float arg0, unsigned arg1, unsigned arg2, float arg3, short arg4);
    void method3(unsigned arg0, double arg1, float arg2, bool arg3, bool arg4);
    void method4(float arg0, float arg1, bool arg2, short arg3, int arg4);
    float method5(int arg0, double arg1, short arg2, float arg3, unsigned arg4);
    int method6(int arg0, float arg1, unsigned arg2, float arg3, int arg4);
    void method7(int arg0, bool arg1, bool arg2, short arg3, float arg4);
    void method8(bool arg0, unsigned arg1, bool arg2, double arg3, short arg4);
    void method9(short arg0, float arg1, short arg2, double arg3, float arg4);
    int method10(bool arg0, double arg1, int arg2, int arg3, float arg4);
    float method11(unsigned arg0, unsigned arg1, float arg2, float arg3, float arg4);
    void method12(unsigned arg0, bool arg1, bool arg2, bool arg3, float arg4);
    void method13(double arg0, bool arg1, bool arg2, bool arg3, bool arg4);
    short method14(bool arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
};

namespace ns_Class57
{
    int method0(int arg0, bool arg1, short arg2, int arg3, short arg4);
    double method1(short arg0, double arg1, unsigned arg2, int arg3, float arg4);
    unsigned method2(float arg0, unsigned arg1, unsigned arg2, float arg3, short arg4);
    void method3(unsigned arg0, double arg1, float arg2, bool arg3, bool arg4);
    void method4(float arg0, float arg1, bool arg2, short arg3, int arg4);
    float method5(int arg0, double arg1, short arg2, float arg3, unsigned arg4);
    int method6(int arg0, float arg1, unsigned arg2, float arg3, int arg4);
    void method7(int arg0, bool arg1, bool arg2, short arg3, float arg4);
    void method8(bool arg0, unsigned arg1, bool arg2, double arg3, short arg4);
    void method9(short arg0, float arg1, short arg2, double arg3, float arg4);
    int method10(bool arg0, double arg1, int arg2, int arg3, float arg4);
    float method11(unsigned arg0, unsigned arg1, float arg2, float arg3, float arg4);
    void method12(unsigned arg0, bool arg1, bool arg2, bool arg3, float arg4);
    void method13(double arg0, bool arg1, bool arg2, bool arg3, bool arg4);
    short method14(bool arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
}
