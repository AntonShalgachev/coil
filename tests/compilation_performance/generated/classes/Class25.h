#pragma once

#include "../../Common.h"

class Class25
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(float arg0, bool arg1, double arg2, unsigned arg3, float arg4);
    void method1(short arg0, short arg1, bool arg2, bool arg3, int arg4);
    double method2(short arg0, double arg1, float arg2, unsigned arg3, bool arg4);
    int method3(bool arg0, int arg1, double arg2, bool arg3, short arg4);
    void method4(double arg0, float arg1, bool arg2, int arg3, float arg4);
    unsigned method5(double arg0, bool arg1, int arg2, float arg3, unsigned arg4);
    short method6(double arg0, short arg1, bool arg2, bool arg3, short arg4);
    void method7(int arg0, bool arg1, double arg2, short arg3, bool arg4);
    void method8(bool arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    unsigned method9(short arg0, float arg1, short arg2, unsigned arg3, short arg4);
    void method10(int arg0, float arg1, float arg2, short arg3, bool arg4);
    double method11(double arg0, double arg1, float arg2, unsigned arg3, double arg4);
    short method12(unsigned arg0, double arg1, int arg2, short arg3, int arg4);
    unsigned method13(unsigned arg0, bool arg1, short arg2, double arg3, unsigned arg4);
    unsigned method14(int arg0, double arg1, double arg2, unsigned arg3, bool arg4);
};

namespace ns_Class25
{
    unsigned method0(float arg0, bool arg1, double arg2, unsigned arg3, float arg4);
    void method1(short arg0, short arg1, bool arg2, bool arg3, int arg4);
    double method2(short arg0, double arg1, float arg2, unsigned arg3, bool arg4);
    int method3(bool arg0, int arg1, double arg2, bool arg3, short arg4);
    void method4(double arg0, float arg1, bool arg2, int arg3, float arg4);
    unsigned method5(double arg0, bool arg1, int arg2, float arg3, unsigned arg4);
    short method6(double arg0, short arg1, bool arg2, bool arg3, short arg4);
    void method7(int arg0, bool arg1, double arg2, short arg3, bool arg4);
    void method8(bool arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    unsigned method9(short arg0, float arg1, short arg2, unsigned arg3, short arg4);
    void method10(int arg0, float arg1, float arg2, short arg3, bool arg4);
    double method11(double arg0, double arg1, float arg2, unsigned arg3, double arg4);
    short method12(unsigned arg0, double arg1, int arg2, short arg3, int arg4);
    unsigned method13(unsigned arg0, bool arg1, short arg2, double arg3, unsigned arg4);
    unsigned method14(int arg0, double arg1, double arg2, unsigned arg3, bool arg4);
}
