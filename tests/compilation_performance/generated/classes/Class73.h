#pragma once

#include "../../Common.h"

class Class73
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(int arg0, double arg1, short arg2, float arg3, bool arg4);
    void method1(short arg0, unsigned arg1, short arg2, unsigned arg3, float arg4);
    void method2(short arg0, int arg1, unsigned arg2, double arg3, int arg4);
    void method3(unsigned arg0, bool arg1, double arg2, int arg3, int arg4);
    short method4(unsigned arg0, short arg1, short arg2, unsigned arg3, unsigned arg4);
    int method5(unsigned arg0, bool arg1, int arg2, double arg3, unsigned arg4);
    float method6(float arg0, float arg1, short arg2, int arg3, short arg4);
    void method7(unsigned arg0, float arg1, float arg2, bool arg3, double arg4);
    void method8(bool arg0, float arg1, double arg2, float arg3, double arg4);
    void method9(float arg0, double arg1, unsigned arg2, double arg3, double arg4);
    short method10(short arg0, int arg1, short arg2, unsigned arg3, double arg4);
    void method11(bool arg0, bool arg1, int arg2, double arg3, bool arg4);
    int method12(double arg0, unsigned arg1, double arg2, int arg3, short arg4);
    float method13(int arg0, float arg1, float arg2, unsigned arg3, bool arg4);
    short method14(int arg0, short arg1, bool arg2, float arg3, double arg4);
};

namespace ns_Class73
{
    float method0(int arg0, double arg1, short arg2, float arg3, bool arg4);
    void method1(short arg0, unsigned arg1, short arg2, unsigned arg3, float arg4);
    void method2(short arg0, int arg1, unsigned arg2, double arg3, int arg4);
    void method3(unsigned arg0, bool arg1, double arg2, int arg3, int arg4);
    short method4(unsigned arg0, short arg1, short arg2, unsigned arg3, unsigned arg4);
    int method5(unsigned arg0, bool arg1, int arg2, double arg3, unsigned arg4);
    float method6(float arg0, float arg1, short arg2, int arg3, short arg4);
    void method7(unsigned arg0, float arg1, float arg2, bool arg3, double arg4);
    void method8(bool arg0, float arg1, double arg2, float arg3, double arg4);
    void method9(float arg0, double arg1, unsigned arg2, double arg3, double arg4);
    short method10(short arg0, int arg1, short arg2, unsigned arg3, double arg4);
    void method11(bool arg0, bool arg1, int arg2, double arg3, bool arg4);
    int method12(double arg0, unsigned arg1, double arg2, int arg3, short arg4);
    float method13(int arg0, float arg1, float arg2, unsigned arg3, bool arg4);
    short method14(int arg0, short arg1, bool arg2, float arg3, double arg4);
}
