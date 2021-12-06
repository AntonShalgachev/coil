#pragma once

#include "../../Common.h"

class Class77
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, float arg1, float arg2, double arg3, double arg4);
    double method1(int arg0, double arg1, bool arg2, double arg3, double arg4);
    unsigned method2(short arg0, double arg1, unsigned arg2, short arg3, int arg4);
    unsigned method3(short arg0, double arg1, double arg2, unsigned arg3, bool arg4);
    void method4(float arg0, short arg1, unsigned arg2, float arg3, float arg4);
    void method5(unsigned arg0, short arg1, int arg2, unsigned arg3, float arg4);
    void method6(bool arg0, int arg1, double arg2, short arg3, int arg4);
    short method7(double arg0, short arg1, short arg2, int arg3, unsigned arg4);
    void method8(bool arg0, double arg1, bool arg2, short arg3, float arg4);
    void method9(short arg0, short arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method10(short arg0, short arg1, short arg2, unsigned arg3, float arg4);
    void method11(int arg0, int arg1, float arg2, float arg3, bool arg4);
    void method12(int arg0, unsigned arg1, short arg2, short arg3, double arg4);
    bool method13(int arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    unsigned method14(short arg0, int arg1, float arg2, float arg3, unsigned arg4);
};

namespace ns_Class77
{
    void method0(short arg0, float arg1, float arg2, double arg3, double arg4);
    double method1(int arg0, double arg1, bool arg2, double arg3, double arg4);
    unsigned method2(short arg0, double arg1, unsigned arg2, short arg3, int arg4);
    unsigned method3(short arg0, double arg1, double arg2, unsigned arg3, bool arg4);
    void method4(float arg0, short arg1, unsigned arg2, float arg3, float arg4);
    void method5(unsigned arg0, short arg1, int arg2, unsigned arg3, float arg4);
    void method6(bool arg0, int arg1, double arg2, short arg3, int arg4);
    short method7(double arg0, short arg1, short arg2, int arg3, unsigned arg4);
    void method8(bool arg0, double arg1, bool arg2, short arg3, float arg4);
    void method9(short arg0, short arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method10(short arg0, short arg1, short arg2, unsigned arg3, float arg4);
    void method11(int arg0, int arg1, float arg2, float arg3, bool arg4);
    void method12(int arg0, unsigned arg1, short arg2, short arg3, double arg4);
    bool method13(int arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    unsigned method14(short arg0, int arg1, float arg2, float arg3, unsigned arg4);
}
