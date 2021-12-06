#pragma once

#include "../../Common.h"

class Class86
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(int arg0, short arg1, double arg2, float arg3, float arg4);
    float method1(unsigned arg0, bool arg1, unsigned arg2, float arg3, double arg4);
    void method2(short arg0, double arg1, short arg2, unsigned arg3, short arg4);
    void method3(double arg0, bool arg1, float arg2, double arg3, double arg4);
    void method4(float arg0, double arg1, unsigned arg2, float arg3, int arg4);
    bool method5(double arg0, bool arg1, double arg2, bool arg3, unsigned arg4);
    bool method6(double arg0, bool arg1, short arg2, short arg3, double arg4);
    void method7(float arg0, short arg1, unsigned arg2, unsigned arg3, short arg4);
    void method8(int arg0, short arg1, float arg2, bool arg3, unsigned arg4);
    bool method9(short arg0, bool arg1, short arg2, short arg3, short arg4);
    double method10(double arg0, double arg1, double arg2, bool arg3, int arg4);
    void method11(bool arg0, double arg1, short arg2, int arg3, int arg4);
    int method12(int arg0, unsigned arg1, short arg2, double arg3, bool arg4);
    void method13(int arg0, unsigned arg1, short arg2, unsigned arg3, double arg4);
    float method14(double arg0, short arg1, double arg2, float arg3, bool arg4);
};

namespace ns_Class86
{
    short method0(int arg0, short arg1, double arg2, float arg3, float arg4);
    float method1(unsigned arg0, bool arg1, unsigned arg2, float arg3, double arg4);
    void method2(short arg0, double arg1, short arg2, unsigned arg3, short arg4);
    void method3(double arg0, bool arg1, float arg2, double arg3, double arg4);
    void method4(float arg0, double arg1, unsigned arg2, float arg3, int arg4);
    bool method5(double arg0, bool arg1, double arg2, bool arg3, unsigned arg4);
    bool method6(double arg0, bool arg1, short arg2, short arg3, double arg4);
    void method7(float arg0, short arg1, unsigned arg2, unsigned arg3, short arg4);
    void method8(int arg0, short arg1, float arg2, bool arg3, unsigned arg4);
    bool method9(short arg0, bool arg1, short arg2, short arg3, short arg4);
    double method10(double arg0, double arg1, double arg2, bool arg3, int arg4);
    void method11(bool arg0, double arg1, short arg2, int arg3, int arg4);
    int method12(int arg0, unsigned arg1, short arg2, double arg3, bool arg4);
    void method13(int arg0, unsigned arg1, short arg2, unsigned arg3, double arg4);
    float method14(double arg0, short arg1, double arg2, float arg3, bool arg4);
}
