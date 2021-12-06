#pragma once

#include "../../Common.h"

class Class69
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(double arg0, float arg1, int arg2, double arg3, unsigned arg4);
    void method1(short arg0, unsigned arg1, bool arg2, int arg3, bool arg4);
    void method2(double arg0, int arg1, short arg2, float arg3, int arg4);
    void method3(double arg0, float arg1, double arg2, short arg3, short arg4);
    unsigned method4(unsigned arg0, float arg1, bool arg2, double arg3, double arg4);
    unsigned method5(bool arg0, float arg1, double arg2, unsigned arg3, bool arg4);
    void method6(double arg0, int arg1, bool arg2, double arg3, short arg4);
    void method7(unsigned arg0, int arg1, int arg2, bool arg3, short arg4);
    short method8(short arg0, double arg1, double arg2, unsigned arg3, unsigned arg4);
    int method9(int arg0, int arg1, float arg2, double arg3, bool arg4);
    void method10(int arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    void method11(bool arg0, double arg1, unsigned arg2, float arg3, short arg4);
    double method12(int arg0, double arg1, unsigned arg2, float arg3, unsigned arg4);
    void method13(unsigned arg0, double arg1, bool arg2, float arg3, bool arg4);
    void method14(bool arg0, double arg1, short arg2, int arg3, unsigned arg4);
};

namespace ns_Class69
{
    unsigned method0(double arg0, float arg1, int arg2, double arg3, unsigned arg4);
    void method1(short arg0, unsigned arg1, bool arg2, int arg3, bool arg4);
    void method2(double arg0, int arg1, short arg2, float arg3, int arg4);
    void method3(double arg0, float arg1, double arg2, short arg3, short arg4);
    unsigned method4(unsigned arg0, float arg1, bool arg2, double arg3, double arg4);
    unsigned method5(bool arg0, float arg1, double arg2, unsigned arg3, bool arg4);
    void method6(double arg0, int arg1, bool arg2, double arg3, short arg4);
    void method7(unsigned arg0, int arg1, int arg2, bool arg3, short arg4);
    short method8(short arg0, double arg1, double arg2, unsigned arg3, unsigned arg4);
    int method9(int arg0, int arg1, float arg2, double arg3, bool arg4);
    void method10(int arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    void method11(bool arg0, double arg1, unsigned arg2, float arg3, short arg4);
    double method12(int arg0, double arg1, unsigned arg2, float arg3, unsigned arg4);
    void method13(unsigned arg0, double arg1, bool arg2, float arg3, bool arg4);
    void method14(bool arg0, double arg1, short arg2, int arg3, unsigned arg4);
}
