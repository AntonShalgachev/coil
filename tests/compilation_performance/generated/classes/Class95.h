#pragma once

#include "../../Common.h"

class Class95
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, bool arg1, int arg2, double arg3, double arg4);
    void method1(float arg0, bool arg1, int arg2, int arg3, int arg4);
    float method2(bool arg0, float arg1, int arg2, bool arg3, float arg4);
    void method3(float arg0, double arg1, unsigned arg2, double arg3, int arg4);
    void method4(bool arg0, bool arg1, int arg2, unsigned arg3, int arg4);
    void method5(unsigned arg0, short arg1, int arg2, unsigned arg3, short arg4);
    bool method6(int arg0, int arg1, bool arg2, bool arg3, unsigned arg4);
    void method7(bool arg0, short arg1, unsigned arg2, float arg3, short arg4);
    void method8(int arg0, short arg1, short arg2, unsigned arg3, bool arg4);
    void method9(short arg0, unsigned arg1, float arg2, int arg3, float arg4);
    void method10(float arg0, unsigned arg1, short arg2, short arg3, unsigned arg4);
    float method11(double arg0, float arg1, float arg2, float arg3, int arg4);
    void method12(bool arg0, bool arg1, bool arg2, bool arg3, bool arg4);
    unsigned method13(double arg0, float arg1, unsigned arg2, short arg3, float arg4);
    bool method14(unsigned arg0, short arg1, bool arg2, float arg3, double arg4);
};

namespace ns_Class95
{
    void method0(short arg0, bool arg1, int arg2, double arg3, double arg4);
    void method1(float arg0, bool arg1, int arg2, int arg3, int arg4);
    float method2(bool arg0, float arg1, int arg2, bool arg3, float arg4);
    void method3(float arg0, double arg1, unsigned arg2, double arg3, int arg4);
    void method4(bool arg0, bool arg1, int arg2, unsigned arg3, int arg4);
    void method5(unsigned arg0, short arg1, int arg2, unsigned arg3, short arg4);
    bool method6(int arg0, int arg1, bool arg2, bool arg3, unsigned arg4);
    void method7(bool arg0, short arg1, unsigned arg2, float arg3, short arg4);
    void method8(int arg0, short arg1, short arg2, unsigned arg3, bool arg4);
    void method9(short arg0, unsigned arg1, float arg2, int arg3, float arg4);
    void method10(float arg0, unsigned arg1, short arg2, short arg3, unsigned arg4);
    float method11(double arg0, float arg1, float arg2, float arg3, int arg4);
    void method12(bool arg0, bool arg1, bool arg2, bool arg3, bool arg4);
    unsigned method13(double arg0, float arg1, unsigned arg2, short arg3, float arg4);
    bool method14(unsigned arg0, short arg1, bool arg2, float arg3, double arg4);
}
