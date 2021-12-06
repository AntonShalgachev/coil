#pragma once

#include "../../Common.h"

class Class60
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, double arg1, int arg2, bool arg3, double arg4);
    unsigned method1(float arg0, bool arg1, float arg2, float arg3, unsigned arg4);
    int method2(int arg0, bool arg1, float arg2, int arg3, short arg4);
    bool method3(float arg0, bool arg1, short arg2, double arg3, bool arg4);
    int method4(bool arg0, int arg1, double arg2, int arg3, double arg4);
    void method5(int arg0, float arg1, int arg2, float arg3, unsigned arg4);
    short method6(bool arg0, bool arg1, unsigned arg2, short arg3, short arg4);
    short method7(double arg0, short arg1, short arg2, int arg3, double arg4);
    void method8(bool arg0, float arg1, float arg2, short arg3, short arg4);
    void method9(short arg0, unsigned arg1, short arg2, int arg3, short arg4);
    double method10(double arg0, unsigned arg1, short arg2, unsigned arg3, short arg4);
    float method11(int arg0, bool arg1, double arg2, double arg3, float arg4);
    void method12(int arg0, bool arg1, double arg2, bool arg3, unsigned arg4);
    int method13(float arg0, bool arg1, int arg2, double arg3, float arg4);
    void method14(double arg0, unsigned arg1, double arg2, int arg3, unsigned arg4);
};

namespace ns_Class60
{
    void method0(double arg0, double arg1, int arg2, bool arg3, double arg4);
    unsigned method1(float arg0, bool arg1, float arg2, float arg3, unsigned arg4);
    int method2(int arg0, bool arg1, float arg2, int arg3, short arg4);
    bool method3(float arg0, bool arg1, short arg2, double arg3, bool arg4);
    int method4(bool arg0, int arg1, double arg2, int arg3, double arg4);
    void method5(int arg0, float arg1, int arg2, float arg3, unsigned arg4);
    short method6(bool arg0, bool arg1, unsigned arg2, short arg3, short arg4);
    short method7(double arg0, short arg1, short arg2, int arg3, double arg4);
    void method8(bool arg0, float arg1, float arg2, short arg3, short arg4);
    void method9(short arg0, unsigned arg1, short arg2, int arg3, short arg4);
    double method10(double arg0, unsigned arg1, short arg2, unsigned arg3, short arg4);
    float method11(int arg0, bool arg1, double arg2, double arg3, float arg4);
    void method12(int arg0, bool arg1, double arg2, bool arg3, unsigned arg4);
    int method13(float arg0, bool arg1, int arg2, double arg3, float arg4);
    void method14(double arg0, unsigned arg1, double arg2, int arg3, unsigned arg4);
}
