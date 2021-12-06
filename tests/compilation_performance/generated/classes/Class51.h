#pragma once

#include "../../Common.h"

class Class51
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, unsigned arg1, int arg2, bool arg3, int arg4);
    unsigned method1(float arg0, unsigned arg1, short arg2, int arg3, bool arg4);
    bool method2(bool arg0, int arg1, float arg2, unsigned arg3, float arg4);
    float method3(float arg0, short arg1, bool arg2, unsigned arg3, float arg4);
    short method4(short arg0, bool arg1, float arg2, int arg3, bool arg4);
    int method5(int arg0, float arg1, int arg2, bool arg3, int arg4);
    void method6(float arg0, double arg1, bool arg2, bool arg3, float arg4);
    bool method7(double arg0, double arg1, bool arg2, float arg3, short arg4);
    void method8(double arg0, short arg1, int arg2, int arg3, unsigned arg4);
    void method9(short arg0, short arg1, int arg2, double arg3, float arg4);
    void method10(short arg0, short arg1, int arg2, unsigned arg3, bool arg4);
    void method11(int arg0, bool arg1, bool arg2, double arg3, int arg4);
    unsigned method12(float arg0, short arg1, int arg2, unsigned arg3, double arg4);
    void method13(float arg0, int arg1, bool arg2, unsigned arg3, short arg4);
    void method14(float arg0, int arg1, float arg2, float arg3, int arg4);
};

namespace ns_Class51
{
    void method0(int arg0, unsigned arg1, int arg2, bool arg3, int arg4);
    unsigned method1(float arg0, unsigned arg1, short arg2, int arg3, bool arg4);
    bool method2(bool arg0, int arg1, float arg2, unsigned arg3, float arg4);
    float method3(float arg0, short arg1, bool arg2, unsigned arg3, float arg4);
    short method4(short arg0, bool arg1, float arg2, int arg3, bool arg4);
    int method5(int arg0, float arg1, int arg2, bool arg3, int arg4);
    void method6(float arg0, double arg1, bool arg2, bool arg3, float arg4);
    bool method7(double arg0, double arg1, bool arg2, float arg3, short arg4);
    void method8(double arg0, short arg1, int arg2, int arg3, unsigned arg4);
    void method9(short arg0, short arg1, int arg2, double arg3, float arg4);
    void method10(short arg0, short arg1, int arg2, unsigned arg3, bool arg4);
    void method11(int arg0, bool arg1, bool arg2, double arg3, int arg4);
    unsigned method12(float arg0, short arg1, int arg2, unsigned arg3, double arg4);
    void method13(float arg0, int arg1, bool arg2, unsigned arg3, short arg4);
    void method14(float arg0, int arg1, float arg2, float arg3, int arg4);
}
