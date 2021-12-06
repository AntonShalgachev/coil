#pragma once

#include "../../Common.h"

class Class13
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(int arg0, float arg1, short arg2, double arg3, unsigned arg4);
    void method1(unsigned arg0, double arg1, bool arg2, float arg3, double arg4);
    double method2(float arg0, short arg1, float arg2, double arg3, unsigned arg4);
    short method3(unsigned arg0, bool arg1, short arg2, short arg3, int arg4);
    void method4(float arg0, float arg1, short arg2, unsigned arg3, short arg4);
    double method5(double arg0, int arg1, unsigned arg2, double arg3, double arg4);
    void method6(short arg0, unsigned arg1, bool arg2, bool arg3, short arg4);
    bool method7(float arg0, bool arg1, short arg2, bool arg3, bool arg4);
    float method8(bool arg0, unsigned arg1, unsigned arg2, int arg3, float arg4);
    void method9(int arg0, unsigned arg1, unsigned arg2, short arg3, double arg4);
    void method10(short arg0, double arg1, float arg2, double arg3, short arg4);
    short method11(short arg0, bool arg1, short arg2, float arg3, float arg4);
    void method12(short arg0, double arg1, bool arg2, unsigned arg3, float arg4);
    int method13(int arg0, double arg1, int arg2, double arg3, bool arg4);
    short method14(short arg0, int arg1, bool arg2, int arg3, double arg4);
};

namespace ns_Class13
{
    short method0(int arg0, float arg1, short arg2, double arg3, unsigned arg4);
    void method1(unsigned arg0, double arg1, bool arg2, float arg3, double arg4);
    double method2(float arg0, short arg1, float arg2, double arg3, unsigned arg4);
    short method3(unsigned arg0, bool arg1, short arg2, short arg3, int arg4);
    void method4(float arg0, float arg1, short arg2, unsigned arg3, short arg4);
    double method5(double arg0, int arg1, unsigned arg2, double arg3, double arg4);
    void method6(short arg0, unsigned arg1, bool arg2, bool arg3, short arg4);
    bool method7(float arg0, bool arg1, short arg2, bool arg3, bool arg4);
    float method8(bool arg0, unsigned arg1, unsigned arg2, int arg3, float arg4);
    void method9(int arg0, unsigned arg1, unsigned arg2, short arg3, double arg4);
    void method10(short arg0, double arg1, float arg2, double arg3, short arg4);
    short method11(short arg0, bool arg1, short arg2, float arg3, float arg4);
    void method12(short arg0, double arg1, bool arg2, unsigned arg3, float arg4);
    int method13(int arg0, double arg1, int arg2, double arg3, bool arg4);
    short method14(short arg0, int arg1, bool arg2, int arg3, double arg4);
}
