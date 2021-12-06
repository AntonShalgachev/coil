#pragma once

#include "../../Common.h"

class Class53
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, bool arg1, int arg2, int arg3, int arg4);
    void method1(int arg0, short arg1, unsigned arg2, short arg3, short arg4);
    void method2(bool arg0, bool arg1, short arg2, short arg3, double arg4);
    void method3(int arg0, float arg1, float arg2, double arg3, double arg4);
    double method4(double arg0, int arg1, bool arg2, bool arg3, double arg4);
    unsigned method5(unsigned arg0, float arg1, bool arg2, int arg3, int arg4);
    unsigned method6(unsigned arg0, unsigned arg1, bool arg2, float arg3, unsigned arg4);
    void method7(double arg0, bool arg1, bool arg2, double arg3, float arg4);
    double method8(double arg0, int arg1, double arg2, float arg3, short arg4);
    unsigned method9(int arg0, bool arg1, unsigned arg2, double arg3, float arg4);
    double method10(int arg0, int arg1, bool arg2, double arg3, unsigned arg4);
    float method11(float arg0, bool arg1, bool arg2, unsigned arg3, double arg4);
    void method12(int arg0, unsigned arg1, bool arg2, double arg3, unsigned arg4);
    void method13(bool arg0, bool arg1, int arg2, bool arg3, unsigned arg4);
    bool method14(unsigned arg0, bool arg1, bool arg2, double arg3, unsigned arg4);
};

namespace ns_Class53
{
    unsigned method0(unsigned arg0, bool arg1, int arg2, int arg3, int arg4);
    void method1(int arg0, short arg1, unsigned arg2, short arg3, short arg4);
    void method2(bool arg0, bool arg1, short arg2, short arg3, double arg4);
    void method3(int arg0, float arg1, float arg2, double arg3, double arg4);
    double method4(double arg0, int arg1, bool arg2, bool arg3, double arg4);
    unsigned method5(unsigned arg0, float arg1, bool arg2, int arg3, int arg4);
    unsigned method6(unsigned arg0, unsigned arg1, bool arg2, float arg3, unsigned arg4);
    void method7(double arg0, bool arg1, bool arg2, double arg3, float arg4);
    double method8(double arg0, int arg1, double arg2, float arg3, short arg4);
    unsigned method9(int arg0, bool arg1, unsigned arg2, double arg3, float arg4);
    double method10(int arg0, int arg1, bool arg2, double arg3, unsigned arg4);
    float method11(float arg0, bool arg1, bool arg2, unsigned arg3, double arg4);
    void method12(int arg0, unsigned arg1, bool arg2, double arg3, unsigned arg4);
    void method13(bool arg0, bool arg1, int arg2, bool arg3, unsigned arg4);
    bool method14(unsigned arg0, bool arg1, bool arg2, double arg3, unsigned arg4);
}
