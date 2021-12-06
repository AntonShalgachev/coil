#pragma once

#include "../../Common.h"

class Class0
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, unsigned arg1, bool arg2, short arg3, short arg4);
    float method1(short arg0, int arg1, float arg2, float arg3, float arg4);
    unsigned method2(unsigned arg0, int arg1, float arg2, bool arg3, double arg4);
    void method3(int arg0, double arg1, int arg2, short arg3, float arg4);
    short method4(float arg0, double arg1, unsigned arg2, short arg3, short arg4);
    void method5(double arg0, short arg1, unsigned arg2, float arg3, unsigned arg4);
    short method6(bool arg0, int arg1, bool arg2, double arg3, short arg4);
    void method7(float arg0, float arg1, int arg2, unsigned arg3, float arg4);
    double method8(bool arg0, double arg1, double arg2, bool arg3, float arg4);
    void method9(unsigned arg0, short arg1, short arg2, short arg3, short arg4);
    void method10(bool arg0, unsigned arg1, short arg2, unsigned arg3, bool arg4);
    void method11(double arg0, bool arg1, short arg2, bool arg3, double arg4);
    bool method12(bool arg0, int arg1, bool arg2, bool arg3, bool arg4);
    void method13(short arg0, float arg1, unsigned arg2, float arg3, short arg4);
    void method14(bool arg0, short arg1, int arg2, int arg3, short arg4);
};

namespace ns_Class0
{
    void method0(unsigned arg0, unsigned arg1, bool arg2, short arg3, short arg4);
    float method1(short arg0, int arg1, float arg2, float arg3, float arg4);
    unsigned method2(unsigned arg0, int arg1, float arg2, bool arg3, double arg4);
    void method3(int arg0, double arg1, int arg2, short arg3, float arg4);
    short method4(float arg0, double arg1, unsigned arg2, short arg3, short arg4);
    void method5(double arg0, short arg1, unsigned arg2, float arg3, unsigned arg4);
    short method6(bool arg0, int arg1, bool arg2, double arg3, short arg4);
    void method7(float arg0, float arg1, int arg2, unsigned arg3, float arg4);
    double method8(bool arg0, double arg1, double arg2, bool arg3, float arg4);
    void method9(unsigned arg0, short arg1, short arg2, short arg3, short arg4);
    void method10(bool arg0, unsigned arg1, short arg2, unsigned arg3, bool arg4);
    void method11(double arg0, bool arg1, short arg2, bool arg3, double arg4);
    bool method12(bool arg0, int arg1, bool arg2, bool arg3, bool arg4);
    void method13(short arg0, float arg1, unsigned arg2, float arg3, short arg4);
    void method14(bool arg0, short arg1, int arg2, int arg3, short arg4);
}
