#pragma once

#include "../../Common.h"

class Class4
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, double arg1, float arg2, double arg3, unsigned arg4);
    void method1(unsigned arg0, short arg1, unsigned arg2, float arg3, unsigned arg4);
    void method2(bool arg0, unsigned arg1, float arg2, bool arg3, short arg4);
    void method3(float arg0, double arg1, double arg2, short arg3, bool arg4);
    double method4(double arg0, bool arg1, double arg2, double arg3, double arg4);
    unsigned method5(unsigned arg0, int arg1, bool arg2, double arg3, bool arg4);
    void method6(bool arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    void method7(float arg0, short arg1, unsigned arg2, int arg3, short arg4);
    short method8(short arg0, unsigned arg1, short arg2, float arg3, float arg4);
    void method9(unsigned arg0, short arg1, bool arg2, bool arg3, float arg4);
    bool method10(unsigned arg0, unsigned arg1, short arg2, short arg3, bool arg4);
    void method11(double arg0, int arg1, bool arg2, unsigned arg3, short arg4);
    bool method12(float arg0, bool arg1, int arg2, bool arg3, unsigned arg4);
    int method13(short arg0, int arg1, short arg2, int arg3, short arg4);
    void method14(short arg0, bool arg1, short arg2, short arg3, double arg4);
};

namespace ns_Class4
{
    void method0(short arg0, double arg1, float arg2, double arg3, unsigned arg4);
    void method1(unsigned arg0, short arg1, unsigned arg2, float arg3, unsigned arg4);
    void method2(bool arg0, unsigned arg1, float arg2, bool arg3, short arg4);
    void method3(float arg0, double arg1, double arg2, short arg3, bool arg4);
    double method4(double arg0, bool arg1, double arg2, double arg3, double arg4);
    unsigned method5(unsigned arg0, int arg1, bool arg2, double arg3, bool arg4);
    void method6(bool arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    void method7(float arg0, short arg1, unsigned arg2, int arg3, short arg4);
    short method8(short arg0, unsigned arg1, short arg2, float arg3, float arg4);
    void method9(unsigned arg0, short arg1, bool arg2, bool arg3, float arg4);
    bool method10(unsigned arg0, unsigned arg1, short arg2, short arg3, bool arg4);
    void method11(double arg0, int arg1, bool arg2, unsigned arg3, short arg4);
    bool method12(float arg0, bool arg1, int arg2, bool arg3, unsigned arg4);
    int method13(short arg0, int arg1, short arg2, int arg3, short arg4);
    void method14(short arg0, bool arg1, short arg2, short arg3, double arg4);
}
