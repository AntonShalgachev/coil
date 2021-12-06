#pragma once

#include "../../Common.h"

class Class28
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, double arg1, float arg2, short arg3, float arg4);
    int method1(int arg0, short arg1, float arg2, bool arg3, float arg4);
    int method2(bool arg0, int arg1, bool arg2, bool arg3, unsigned arg4);
    void method3(int arg0, float arg1, float arg2, unsigned arg3, float arg4);
    bool method4(float arg0, unsigned arg1, bool arg2, unsigned arg3, int arg4);
    unsigned method5(short arg0, double arg1, int arg2, unsigned arg3, float arg4);
    void method6(int arg0, unsigned arg1, bool arg2, unsigned arg3, int arg4);
    int method7(unsigned arg0, int arg1, unsigned arg2, double arg3, short arg4);
    void method8(int arg0, int arg1, bool arg2, int arg3, bool arg4);
    float method9(double arg0, unsigned arg1, double arg2, float arg3, short arg4);
    int method10(short arg0, float arg1, double arg2, int arg3, double arg4);
    void method11(float arg0, double arg1, bool arg2, int arg3, unsigned arg4);
    void method12(int arg0, float arg1, bool arg2, float arg3, int arg4);
    bool method13(bool arg0, int arg1, double arg2, float arg3, short arg4);
    int method14(int arg0, double arg1, int arg2, short arg3, unsigned arg4);
};

namespace ns_Class28
{
    void method0(double arg0, double arg1, float arg2, short arg3, float arg4);
    int method1(int arg0, short arg1, float arg2, bool arg3, float arg4);
    int method2(bool arg0, int arg1, bool arg2, bool arg3, unsigned arg4);
    void method3(int arg0, float arg1, float arg2, unsigned arg3, float arg4);
    bool method4(float arg0, unsigned arg1, bool arg2, unsigned arg3, int arg4);
    unsigned method5(short arg0, double arg1, int arg2, unsigned arg3, float arg4);
    void method6(int arg0, unsigned arg1, bool arg2, unsigned arg3, int arg4);
    int method7(unsigned arg0, int arg1, unsigned arg2, double arg3, short arg4);
    void method8(int arg0, int arg1, bool arg2, int arg3, bool arg4);
    float method9(double arg0, unsigned arg1, double arg2, float arg3, short arg4);
    int method10(short arg0, float arg1, double arg2, int arg3, double arg4);
    void method11(float arg0, double arg1, bool arg2, int arg3, unsigned arg4);
    void method12(int arg0, float arg1, bool arg2, float arg3, int arg4);
    bool method13(bool arg0, int arg1, double arg2, float arg3, short arg4);
    int method14(int arg0, double arg1, int arg2, short arg3, unsigned arg4);
}
