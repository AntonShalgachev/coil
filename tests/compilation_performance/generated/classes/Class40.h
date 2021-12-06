#pragma once

#include "../../Common.h"

class Class40
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, short arg1, short arg2, float arg3, float arg4);
    void method1(unsigned arg0, double arg1, short arg2, bool arg3, double arg4);
    int method2(float arg0, bool arg1, int arg2, short arg3, int arg4);
    unsigned method3(int arg0, unsigned arg1, float arg2, float arg3, bool arg4);
    double method4(double arg0, double arg1, double arg2, bool arg3, bool arg4);
    void method5(unsigned arg0, short arg1, int arg2, unsigned arg3, short arg4);
    int method6(int arg0, float arg1, bool arg2, float arg3, unsigned arg4);
    void method7(short arg0, int arg1, int arg2, bool arg3, float arg4);
    int method8(float arg0, double arg1, int arg2, double arg3, int arg4);
    float method9(bool arg0, double arg1, float arg2, bool arg3, float arg4);
    short method10(double arg0, unsigned arg1, float arg2, bool arg3, short arg4);
    void method11(double arg0, float arg1, int arg2, double arg3, unsigned arg4);
    double method12(short arg0, int arg1, double arg2, unsigned arg3, bool arg4);
    int method13(int arg0, int arg1, double arg2, float arg3, bool arg4);
    bool method14(float arg0, double arg1, bool arg2, unsigned arg3, bool arg4);
};

namespace ns_Class40
{
    void method0(int arg0, short arg1, short arg2, float arg3, float arg4);
    void method1(unsigned arg0, double arg1, short arg2, bool arg3, double arg4);
    int method2(float arg0, bool arg1, int arg2, short arg3, int arg4);
    unsigned method3(int arg0, unsigned arg1, float arg2, float arg3, bool arg4);
    double method4(double arg0, double arg1, double arg2, bool arg3, bool arg4);
    void method5(unsigned arg0, short arg1, int arg2, unsigned arg3, short arg4);
    int method6(int arg0, float arg1, bool arg2, float arg3, unsigned arg4);
    void method7(short arg0, int arg1, int arg2, bool arg3, float arg4);
    int method8(float arg0, double arg1, int arg2, double arg3, int arg4);
    float method9(bool arg0, double arg1, float arg2, bool arg3, float arg4);
    short method10(double arg0, unsigned arg1, float arg2, bool arg3, short arg4);
    void method11(double arg0, float arg1, int arg2, double arg3, unsigned arg4);
    double method12(short arg0, int arg1, double arg2, unsigned arg3, bool arg4);
    int method13(int arg0, int arg1, double arg2, float arg3, bool arg4);
    bool method14(float arg0, double arg1, bool arg2, unsigned arg3, bool arg4);
}
