#pragma once

#include "../../Common.h"

class Class5
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, float arg1, short arg2, short arg3, bool arg4);
    int method1(int arg0, double arg1, short arg2, bool arg3, int arg4);
    int method2(double arg0, short arg1, float arg2, double arg3, int arg4);
    void method3(unsigned arg0, short arg1, int arg2, bool arg3, unsigned arg4);
    void method4(unsigned arg0, int arg1, bool arg2, short arg3, bool arg4);
    unsigned method5(unsigned arg0, float arg1, int arg2, int arg3, unsigned arg4);
    double method6(bool arg0, unsigned arg1, int arg2, double arg3, short arg4);
    int method7(int arg0, float arg1, float arg2, int arg3, double arg4);
    void method8(bool arg0, double arg1, float arg2, float arg3, unsigned arg4);
    void method9(int arg0, float arg1, bool arg2, double arg3, double arg4);
    void method10(bool arg0, unsigned arg1, int arg2, int arg3, float arg4);
    bool method11(double arg0, bool arg1, short arg2, short arg3, unsigned arg4);
    void method12(bool arg0, bool arg1, short arg2, int arg3, double arg4);
    void method13(int arg0, short arg1, unsigned arg2, double arg3, bool arg4);
    unsigned method14(float arg0, double arg1, int arg2, float arg3, unsigned arg4);
};

namespace ns_Class5
{
    unsigned method0(unsigned arg0, float arg1, short arg2, short arg3, bool arg4);
    int method1(int arg0, double arg1, short arg2, bool arg3, int arg4);
    int method2(double arg0, short arg1, float arg2, double arg3, int arg4);
    void method3(unsigned arg0, short arg1, int arg2, bool arg3, unsigned arg4);
    void method4(unsigned arg0, int arg1, bool arg2, short arg3, bool arg4);
    unsigned method5(unsigned arg0, float arg1, int arg2, int arg3, unsigned arg4);
    double method6(bool arg0, unsigned arg1, int arg2, double arg3, short arg4);
    int method7(int arg0, float arg1, float arg2, int arg3, double arg4);
    void method8(bool arg0, double arg1, float arg2, float arg3, unsigned arg4);
    void method9(int arg0, float arg1, bool arg2, double arg3, double arg4);
    void method10(bool arg0, unsigned arg1, int arg2, int arg3, float arg4);
    bool method11(double arg0, bool arg1, short arg2, short arg3, unsigned arg4);
    void method12(bool arg0, bool arg1, short arg2, int arg3, double arg4);
    void method13(int arg0, short arg1, unsigned arg2, double arg3, bool arg4);
    unsigned method14(float arg0, double arg1, int arg2, float arg3, unsigned arg4);
}
