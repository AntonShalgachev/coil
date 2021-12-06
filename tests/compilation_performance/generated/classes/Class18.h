#pragma once

#include "../../Common.h"

class Class18
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(bool arg0, short arg1, double arg2, int arg3, double arg4);
    bool method1(int arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    void method2(bool arg0, double arg1, bool arg2, float arg3, int arg4);
    unsigned method3(bool arg0, unsigned arg1, int arg2, bool arg3, float arg4);
    short method4(float arg0, unsigned arg1, short arg2, unsigned arg3, double arg4);
    void method5(unsigned arg0, bool arg1, int arg2, short arg3, bool arg4);
    unsigned method6(unsigned arg0, unsigned arg1, float arg2, float arg3, float arg4);
    float method7(float arg0, short arg1, bool arg2, bool arg3, float arg4);
    void method8(double arg0, float arg1, int arg2, bool arg3, float arg4);
    double method9(bool arg0, unsigned arg1, double arg2, bool arg3, int arg4);
    unsigned method10(bool arg0, bool arg1, bool arg2, bool arg3, unsigned arg4);
    void method11(unsigned arg0, bool arg1, bool arg2, bool arg3, bool arg4);
    void method12(double arg0, unsigned arg1, short arg2, double arg3, int arg4);
    void method13(int arg0, unsigned arg1, short arg2, float arg3, short arg4);
    void method14(int arg0, float arg1, unsigned arg2, short arg3, short arg4);
};

namespace ns_Class18
{
    void method0(bool arg0, short arg1, double arg2, int arg3, double arg4);
    bool method1(int arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    void method2(bool arg0, double arg1, bool arg2, float arg3, int arg4);
    unsigned method3(bool arg0, unsigned arg1, int arg2, bool arg3, float arg4);
    short method4(float arg0, unsigned arg1, short arg2, unsigned arg3, double arg4);
    void method5(unsigned arg0, bool arg1, int arg2, short arg3, bool arg4);
    unsigned method6(unsigned arg0, unsigned arg1, float arg2, float arg3, float arg4);
    float method7(float arg0, short arg1, bool arg2, bool arg3, float arg4);
    void method8(double arg0, float arg1, int arg2, bool arg3, float arg4);
    double method9(bool arg0, unsigned arg1, double arg2, bool arg3, int arg4);
    unsigned method10(bool arg0, bool arg1, bool arg2, bool arg3, unsigned arg4);
    void method11(unsigned arg0, bool arg1, bool arg2, bool arg3, bool arg4);
    void method12(double arg0, unsigned arg1, short arg2, double arg3, int arg4);
    void method13(int arg0, unsigned arg1, short arg2, float arg3, short arg4);
    void method14(int arg0, float arg1, unsigned arg2, short arg3, short arg4);
}
