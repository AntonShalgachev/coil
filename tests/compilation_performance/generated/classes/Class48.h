#pragma once

#include "../../Common.h"

class Class48
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, short arg1, bool arg2, double arg3, bool arg4);
    void method1(bool arg0, float arg1, double arg2, bool arg3, float arg4);
    float method2(float arg0, int arg1, bool arg2, short arg3, float arg4);
    unsigned method3(double arg0, unsigned arg1, double arg2, unsigned arg3, unsigned arg4);
    void method4(float arg0, bool arg1, double arg2, short arg3, short arg4);
    void method5(int arg0, int arg1, short arg2, int arg3, double arg4);
    bool method6(unsigned arg0, float arg1, int arg2, double arg3, bool arg4);
    void method7(short arg0, float arg1, short arg2, unsigned arg3, short arg4);
    void method8(unsigned arg0, bool arg1, int arg2, short arg3, bool arg4);
    void method9(float arg0, bool arg1, short arg2, int arg3, int arg4);
    int method10(bool arg0, int arg1, short arg2, float arg3, bool arg4);
    unsigned method11(double arg0, double arg1, double arg2, unsigned arg3, float arg4);
    void method12(bool arg0, short arg1, short arg2, double arg3, bool arg4);
    bool method13(int arg0, bool arg1, float arg2, float arg3, bool arg4);
    void method14(double arg0, double arg1, double arg2, int arg3, bool arg4);
};

namespace ns_Class48
{
    void method0(double arg0, short arg1, bool arg2, double arg3, bool arg4);
    void method1(bool arg0, float arg1, double arg2, bool arg3, float arg4);
    float method2(float arg0, int arg1, bool arg2, short arg3, float arg4);
    unsigned method3(double arg0, unsigned arg1, double arg2, unsigned arg3, unsigned arg4);
    void method4(float arg0, bool arg1, double arg2, short arg3, short arg4);
    void method5(int arg0, int arg1, short arg2, int arg3, double arg4);
    bool method6(unsigned arg0, float arg1, int arg2, double arg3, bool arg4);
    void method7(short arg0, float arg1, short arg2, unsigned arg3, short arg4);
    void method8(unsigned arg0, bool arg1, int arg2, short arg3, bool arg4);
    void method9(float arg0, bool arg1, short arg2, int arg3, int arg4);
    int method10(bool arg0, int arg1, short arg2, float arg3, bool arg4);
    unsigned method11(double arg0, double arg1, double arg2, unsigned arg3, float arg4);
    void method12(bool arg0, short arg1, short arg2, double arg3, bool arg4);
    bool method13(int arg0, bool arg1, float arg2, float arg3, bool arg4);
    void method14(double arg0, double arg1, double arg2, int arg3, bool arg4);
}
