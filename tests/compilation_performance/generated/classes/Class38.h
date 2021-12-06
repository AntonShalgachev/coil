#pragma once

#include "../../Common.h"

class Class38
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, bool arg1, int arg2, short arg3, bool arg4);
    void method1(unsigned arg0, short arg1, unsigned arg2, double arg3, unsigned arg4);
    void method2(int arg0, int arg1, bool arg2, double arg3, double arg4);
    void method3(float arg0, short arg1, short arg2, int arg3, float arg4);
    void method4(unsigned arg0, unsigned arg1, short arg2, unsigned arg3, int arg4);
    void method5(float arg0, int arg1, bool arg2, bool arg3, float arg4);
    unsigned method6(int arg0, double arg1, unsigned arg2, float arg3, short arg4);
    bool method7(float arg0, float arg1, float arg2, double arg3, bool arg4);
    void method8(short arg0, double arg1, float arg2, double arg3, unsigned arg4);
    int method9(int arg0, float arg1, double arg2, unsigned arg3, double arg4);
    void method10(unsigned arg0, double arg1, float arg2, double arg3, short arg4);
    double method11(double arg0, double arg1, float arg2, int arg3, unsigned arg4);
    void method12(short arg0, short arg1, unsigned arg2, unsigned arg3, int arg4);
    void method13(unsigned arg0, float arg1, float arg2, unsigned arg3, bool arg4);
    int method14(unsigned arg0, unsigned arg1, int arg2, bool arg3, int arg4);
};

namespace ns_Class38
{
    void method0(int arg0, bool arg1, int arg2, short arg3, bool arg4);
    void method1(unsigned arg0, short arg1, unsigned arg2, double arg3, unsigned arg4);
    void method2(int arg0, int arg1, bool arg2, double arg3, double arg4);
    void method3(float arg0, short arg1, short arg2, int arg3, float arg4);
    void method4(unsigned arg0, unsigned arg1, short arg2, unsigned arg3, int arg4);
    void method5(float arg0, int arg1, bool arg2, bool arg3, float arg4);
    unsigned method6(int arg0, double arg1, unsigned arg2, float arg3, short arg4);
    bool method7(float arg0, float arg1, float arg2, double arg3, bool arg4);
    void method8(short arg0, double arg1, float arg2, double arg3, unsigned arg4);
    int method9(int arg0, float arg1, double arg2, unsigned arg3, double arg4);
    void method10(unsigned arg0, double arg1, float arg2, double arg3, short arg4);
    double method11(double arg0, double arg1, float arg2, int arg3, unsigned arg4);
    void method12(short arg0, short arg1, unsigned arg2, unsigned arg3, int arg4);
    void method13(unsigned arg0, float arg1, float arg2, unsigned arg3, bool arg4);
    int method14(unsigned arg0, unsigned arg1, int arg2, bool arg3, int arg4);
}
