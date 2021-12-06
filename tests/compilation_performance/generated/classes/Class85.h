#pragma once

#include "../../Common.h"

class Class85
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, double arg1, int arg2, int arg3, double arg4);
    void method1(double arg0, int arg1, double arg2, unsigned arg3, bool arg4);
    void method2(int arg0, float arg1, bool arg2, int arg3, double arg4);
    int method3(unsigned arg0, bool arg1, int arg2, double arg3, bool arg4);
    short method4(short arg0, bool arg1, double arg2, float arg3, int arg4);
    void method5(bool arg0, unsigned arg1, int arg2, int arg3, double arg4);
    void method6(unsigned arg0, unsigned arg1, unsigned arg2, float arg3, double arg4);
    void method7(double arg0, unsigned arg1, short arg2, short arg3, bool arg4);
    unsigned method8(unsigned arg0, int arg1, double arg2, double arg3, double arg4);
    void method9(float arg0, double arg1, double arg2, bool arg3, unsigned arg4);
    bool method10(bool arg0, unsigned arg1, short arg2, double arg3, short arg4);
    void method11(unsigned arg0, double arg1, float arg2, bool arg3, int arg4);
    bool method12(float arg0, bool arg1, int arg2, bool arg3, int arg4);
    void method13(short arg0, int arg1, unsigned arg2, unsigned arg3, double arg4);
    void method14(unsigned arg0, double arg1, unsigned arg2, int arg3, bool arg4);
};

namespace ns_Class85
{
    void method0(float arg0, double arg1, int arg2, int arg3, double arg4);
    void method1(double arg0, int arg1, double arg2, unsigned arg3, bool arg4);
    void method2(int arg0, float arg1, bool arg2, int arg3, double arg4);
    int method3(unsigned arg0, bool arg1, int arg2, double arg3, bool arg4);
    short method4(short arg0, bool arg1, double arg2, float arg3, int arg4);
    void method5(bool arg0, unsigned arg1, int arg2, int arg3, double arg4);
    void method6(unsigned arg0, unsigned arg1, unsigned arg2, float arg3, double arg4);
    void method7(double arg0, unsigned arg1, short arg2, short arg3, bool arg4);
    unsigned method8(unsigned arg0, int arg1, double arg2, double arg3, double arg4);
    void method9(float arg0, double arg1, double arg2, bool arg3, unsigned arg4);
    bool method10(bool arg0, unsigned arg1, short arg2, double arg3, short arg4);
    void method11(unsigned arg0, double arg1, float arg2, bool arg3, int arg4);
    bool method12(float arg0, bool arg1, int arg2, bool arg3, int arg4);
    void method13(short arg0, int arg1, unsigned arg2, unsigned arg3, double arg4);
    void method14(unsigned arg0, double arg1, unsigned arg2, int arg3, bool arg4);
}
