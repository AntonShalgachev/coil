#pragma once

#include "../../Common.h"

class Class94
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(short arg0, int arg1, int arg2, unsigned arg3, int arg4);
    void method1(double arg0, float arg1, float arg2, int arg3, bool arg4);
    void method2(int arg0, double arg1, float arg2, unsigned arg3, bool arg4);
    void method3(short arg0, bool arg1, short arg2, bool arg3, double arg4);
    void method4(short arg0, float arg1, double arg2, short arg3, float arg4);
    short method5(unsigned arg0, double arg1, double arg2, float arg3, short arg4);
    void method6(double arg0, double arg1, unsigned arg2, double arg3, float arg4);
    void method7(double arg0, unsigned arg1, bool arg2, unsigned arg3, short arg4);
    double method8(short arg0, double arg1, double arg2, double arg3, unsigned arg4);
    double method9(unsigned arg0, double arg1, double arg2, unsigned arg3, float arg4);
    double method10(double arg0, float arg1, bool arg2, short arg3, int arg4);
    float method11(int arg0, bool arg1, float arg2, bool arg3, unsigned arg4);
    void method12(double arg0, float arg1, short arg2, unsigned arg3, float arg4);
    bool method13(int arg0, bool arg1, bool arg2, bool arg3, double arg4);
    double method14(double arg0, double arg1, unsigned arg2, float arg3, int arg4);
};

namespace ns_Class94
{
    int method0(short arg0, int arg1, int arg2, unsigned arg3, int arg4);
    void method1(double arg0, float arg1, float arg2, int arg3, bool arg4);
    void method2(int arg0, double arg1, float arg2, unsigned arg3, bool arg4);
    void method3(short arg0, bool arg1, short arg2, bool arg3, double arg4);
    void method4(short arg0, float arg1, double arg2, short arg3, float arg4);
    short method5(unsigned arg0, double arg1, double arg2, float arg3, short arg4);
    void method6(double arg0, double arg1, unsigned arg2, double arg3, float arg4);
    void method7(double arg0, unsigned arg1, bool arg2, unsigned arg3, short arg4);
    double method8(short arg0, double arg1, double arg2, double arg3, unsigned arg4);
    double method9(unsigned arg0, double arg1, double arg2, unsigned arg3, float arg4);
    double method10(double arg0, float arg1, bool arg2, short arg3, int arg4);
    float method11(int arg0, bool arg1, float arg2, bool arg3, unsigned arg4);
    void method12(double arg0, float arg1, short arg2, unsigned arg3, float arg4);
    bool method13(int arg0, bool arg1, bool arg2, bool arg3, double arg4);
    double method14(double arg0, double arg1, unsigned arg2, float arg3, int arg4);
}
