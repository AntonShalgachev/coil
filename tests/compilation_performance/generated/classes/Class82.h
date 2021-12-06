#pragma once

#include "../../Common.h"

class Class82
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(short arg0, int arg1, short arg2, unsigned arg3, int arg4);
    int method1(unsigned arg0, double arg1, bool arg2, int arg3, short arg4);
    unsigned method2(unsigned arg0, double arg1, bool arg2, float arg3, unsigned arg4);
    void method3(bool arg0, int arg1, short arg2, unsigned arg3, float arg4);
    void method4(bool arg0, float arg1, float arg2, short arg3, double arg4);
    void method5(short arg0, short arg1, int arg2, double arg3, short arg4);
    float method6(double arg0, float arg1, int arg2, float arg3, bool arg4);
    void method7(float arg0, double arg1, short arg2, double arg3, float arg4);
    bool method8(int arg0, bool arg1, float arg2, bool arg3, float arg4);
    void method9(float arg0, double arg1, int arg2, unsigned arg3, float arg4);
    void method10(unsigned arg0, short arg1, double arg2, unsigned arg3, bool arg4);
    void method11(bool arg0, float arg1, bool arg2, double arg3, float arg4);
    void method12(unsigned arg0, short arg1, bool arg2, float arg3, unsigned arg4);
    int method13(int arg0, short arg1, int arg2, float arg3, short arg4);
    void method14(int arg0, double arg1, bool arg2, double arg3, int arg4);
};

namespace ns_Class82
{
    short method0(short arg0, int arg1, short arg2, unsigned arg3, int arg4);
    int method1(unsigned arg0, double arg1, bool arg2, int arg3, short arg4);
    unsigned method2(unsigned arg0, double arg1, bool arg2, float arg3, unsigned arg4);
    void method3(bool arg0, int arg1, short arg2, unsigned arg3, float arg4);
    void method4(bool arg0, float arg1, float arg2, short arg3, double arg4);
    void method5(short arg0, short arg1, int arg2, double arg3, short arg4);
    float method6(double arg0, float arg1, int arg2, float arg3, bool arg4);
    void method7(float arg0, double arg1, short arg2, double arg3, float arg4);
    bool method8(int arg0, bool arg1, float arg2, bool arg3, float arg4);
    void method9(float arg0, double arg1, int arg2, unsigned arg3, float arg4);
    void method10(unsigned arg0, short arg1, double arg2, unsigned arg3, bool arg4);
    void method11(bool arg0, float arg1, bool arg2, double arg3, float arg4);
    void method12(unsigned arg0, short arg1, bool arg2, float arg3, unsigned arg4);
    int method13(int arg0, short arg1, int arg2, float arg3, short arg4);
    void method14(int arg0, double arg1, bool arg2, double arg3, int arg4);
}
