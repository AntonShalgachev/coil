#pragma once

#include "../../Common.h"

class Class64
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, bool arg1, short arg2, float arg3, double arg4);
    void method1(float arg0, unsigned arg1, short arg2, bool arg3, bool arg4);
    void method2(double arg0, float arg1, unsigned arg2, short arg3, unsigned arg4);
    unsigned method3(double arg0, double arg1, unsigned arg2, int arg3, int arg4);
    void method4(bool arg0, int arg1, bool arg2, short arg3, float arg4);
    unsigned method5(unsigned arg0, unsigned arg1, float arg2, unsigned arg3, double arg4);
    int method6(int arg0, bool arg1, int arg2, double arg3, short arg4);
    void method7(unsigned arg0, bool arg1, int arg2, int arg3, int arg4);
    bool method8(bool arg0, short arg1, double arg2, float arg3, bool arg4);
    bool method9(bool arg0, short arg1, double arg2, short arg3, bool arg4);
    void method10(unsigned arg0, unsigned arg1, bool arg2, unsigned arg3, float arg4);
    void method11(double arg0, short arg1, unsigned arg2, bool arg3, short arg4);
    float method12(short arg0, float arg1, int arg2, float arg3, float arg4);
    unsigned method13(unsigned arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    void method14(int arg0, double arg1, float arg2, double arg3, double arg4);
};

namespace ns_Class64
{
    void method0(double arg0, bool arg1, short arg2, float arg3, double arg4);
    void method1(float arg0, unsigned arg1, short arg2, bool arg3, bool arg4);
    void method2(double arg0, float arg1, unsigned arg2, short arg3, unsigned arg4);
    unsigned method3(double arg0, double arg1, unsigned arg2, int arg3, int arg4);
    void method4(bool arg0, int arg1, bool arg2, short arg3, float arg4);
    unsigned method5(unsigned arg0, unsigned arg1, float arg2, unsigned arg3, double arg4);
    int method6(int arg0, bool arg1, int arg2, double arg3, short arg4);
    void method7(unsigned arg0, bool arg1, int arg2, int arg3, int arg4);
    bool method8(bool arg0, short arg1, double arg2, float arg3, bool arg4);
    bool method9(bool arg0, short arg1, double arg2, short arg3, bool arg4);
    void method10(unsigned arg0, unsigned arg1, bool arg2, unsigned arg3, float arg4);
    void method11(double arg0, short arg1, unsigned arg2, bool arg3, short arg4);
    float method12(short arg0, float arg1, int arg2, float arg3, float arg4);
    unsigned method13(unsigned arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    void method14(int arg0, double arg1, float arg2, double arg3, double arg4);
}
