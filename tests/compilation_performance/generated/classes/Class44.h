#pragma once

#include "../../Common.h"

class Class44
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, bool arg1, short arg2, bool arg3, int arg4);
    void method1(bool arg0, unsigned arg1, unsigned arg2, short arg3, double arg4);
    short method2(float arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    short method3(double arg0, unsigned arg1, int arg2, bool arg3, short arg4);
    void method4(short arg0, bool arg1, bool arg2, int arg3, short arg4);
    bool method5(short arg0, bool arg1, bool arg2, float arg3, unsigned arg4);
    double method6(double arg0, double arg1, double arg2, float arg3, double arg4);
    void method7(float arg0, double arg1, int arg2, bool arg3, int arg4);
    void method8(int arg0, float arg1, double arg2, double arg3, short arg4);
    unsigned method9(float arg0, unsigned arg1, short arg2, float arg3, short arg4);
    void method10(bool arg0, short arg1, double arg2, short arg3, short arg4);
    void method11(bool arg0, double arg1, unsigned arg2, short arg3, float arg4);
    void method12(unsigned arg0, unsigned arg1, short arg2, int arg3, short arg4);
    int method13(double arg0, float arg1, int arg2, float arg3, short arg4);
    void method14(float arg0, float arg1, float arg2, short arg3, bool arg4);
};

namespace ns_Class44
{
    void method0(short arg0, bool arg1, short arg2, bool arg3, int arg4);
    void method1(bool arg0, unsigned arg1, unsigned arg2, short arg3, double arg4);
    short method2(float arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    short method3(double arg0, unsigned arg1, int arg2, bool arg3, short arg4);
    void method4(short arg0, bool arg1, bool arg2, int arg3, short arg4);
    bool method5(short arg0, bool arg1, bool arg2, float arg3, unsigned arg4);
    double method6(double arg0, double arg1, double arg2, float arg3, double arg4);
    void method7(float arg0, double arg1, int arg2, bool arg3, int arg4);
    void method8(int arg0, float arg1, double arg2, double arg3, short arg4);
    unsigned method9(float arg0, unsigned arg1, short arg2, float arg3, short arg4);
    void method10(bool arg0, short arg1, double arg2, short arg3, short arg4);
    void method11(bool arg0, double arg1, unsigned arg2, short arg3, float arg4);
    void method12(unsigned arg0, unsigned arg1, short arg2, int arg3, short arg4);
    int method13(double arg0, float arg1, int arg2, float arg3, short arg4);
    void method14(float arg0, float arg1, float arg2, short arg3, bool arg4);
}
