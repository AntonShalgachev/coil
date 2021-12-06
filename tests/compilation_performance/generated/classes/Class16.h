#pragma once

#include "../../Common.h"

class Class16
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(bool arg0, double arg1, double arg2, int arg3, unsigned arg4);
    bool method1(unsigned arg0, bool arg1, int arg2, bool arg3, int arg4);
    double method2(int arg0, short arg1, double arg2, short arg3, bool arg4);
    unsigned method3(int arg0, double arg1, int arg2, int arg3, unsigned arg4);
    double method4(float arg0, float arg1, unsigned arg2, double arg3, short arg4);
    float method5(double arg0, float arg1, float arg2, bool arg3, bool arg4);
    void method6(short arg0, float arg1, short arg2, float arg3, unsigned arg4);
    double method7(double arg0, double arg1, float arg2, float arg3, short arg4);
    void method8(bool arg0, short arg1, short arg2, unsigned arg3, int arg4);
    double method9(double arg0, short arg1, unsigned arg2, int arg3, short arg4);
    void method10(double arg0, double arg1, int arg2, int arg3, short arg4);
    void method11(short arg0, short arg1, float arg2, int arg3, double arg4);
    float method12(float arg0, bool arg1, bool arg2, unsigned arg3, bool arg4);
    short method13(bool arg0, short arg1, float arg2, int arg3, short arg4);
    int method14(int arg0, float arg1, short arg2, bool arg3, int arg4);
};

namespace ns_Class16
{
    bool method0(bool arg0, double arg1, double arg2, int arg3, unsigned arg4);
    bool method1(unsigned arg0, bool arg1, int arg2, bool arg3, int arg4);
    double method2(int arg0, short arg1, double arg2, short arg3, bool arg4);
    unsigned method3(int arg0, double arg1, int arg2, int arg3, unsigned arg4);
    double method4(float arg0, float arg1, unsigned arg2, double arg3, short arg4);
    float method5(double arg0, float arg1, float arg2, bool arg3, bool arg4);
    void method6(short arg0, float arg1, short arg2, float arg3, unsigned arg4);
    double method7(double arg0, double arg1, float arg2, float arg3, short arg4);
    void method8(bool arg0, short arg1, short arg2, unsigned arg3, int arg4);
    double method9(double arg0, short arg1, unsigned arg2, int arg3, short arg4);
    void method10(double arg0, double arg1, int arg2, int arg3, short arg4);
    void method11(short arg0, short arg1, float arg2, int arg3, double arg4);
    float method12(float arg0, bool arg1, bool arg2, unsigned arg3, bool arg4);
    short method13(bool arg0, short arg1, float arg2, int arg3, short arg4);
    int method14(int arg0, float arg1, short arg2, bool arg3, int arg4);
}
