#pragma once

#include "../../Common.h"

class Class32
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, short arg1, double arg2, unsigned arg3, bool arg4);
    void method1(float arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    void method2(unsigned arg0, double arg1, float arg2, int arg3, unsigned arg4);
    double method3(unsigned arg0, double arg1, float arg2, float arg3, double arg4);
    double method4(float arg0, short arg1, int arg2, double arg3, unsigned arg4);
    bool method5(bool arg0, double arg1, int arg2, int arg3, float arg4);
    unsigned method6(bool arg0, unsigned arg1, short arg2, short arg3, unsigned arg4);
    void method7(bool arg0, short arg1, float arg2, float arg3, float arg4);
    unsigned method8(double arg0, int arg1, float arg2, int arg3, unsigned arg4);
    void method9(float arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    double method10(float arg0, unsigned arg1, int arg2, short arg3, double arg4);
    int method11(bool arg0, unsigned arg1, int arg2, double arg3, unsigned arg4);
    void method12(int arg0, float arg1, int arg2, int arg3, short arg4);
    float method13(short arg0, double arg1, short arg2, int arg3, float arg4);
    void method14(bool arg0, unsigned arg1, double arg2, bool arg3, unsigned arg4);
};

namespace ns_Class32
{
    void method0(int arg0, short arg1, double arg2, unsigned arg3, bool arg4);
    void method1(float arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    void method2(unsigned arg0, double arg1, float arg2, int arg3, unsigned arg4);
    double method3(unsigned arg0, double arg1, float arg2, float arg3, double arg4);
    double method4(float arg0, short arg1, int arg2, double arg3, unsigned arg4);
    bool method5(bool arg0, double arg1, int arg2, int arg3, float arg4);
    unsigned method6(bool arg0, unsigned arg1, short arg2, short arg3, unsigned arg4);
    void method7(bool arg0, short arg1, float arg2, float arg3, float arg4);
    unsigned method8(double arg0, int arg1, float arg2, int arg3, unsigned arg4);
    void method9(float arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    double method10(float arg0, unsigned arg1, int arg2, short arg3, double arg4);
    int method11(bool arg0, unsigned arg1, int arg2, double arg3, unsigned arg4);
    void method12(int arg0, float arg1, int arg2, int arg3, short arg4);
    float method13(short arg0, double arg1, short arg2, int arg3, float arg4);
    void method14(bool arg0, unsigned arg1, double arg2, bool arg3, unsigned arg4);
}
