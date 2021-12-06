#pragma once

#include "../../Common.h"

class Class62
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(double arg0, unsigned arg1, float arg2, unsigned arg3, bool arg4);
    float method1(short arg0, bool arg1, bool arg2, float arg3, unsigned arg4);
    void method2(int arg0, int arg1, unsigned arg2, int arg3, float arg4);
    bool method3(int arg0, double arg1, int arg2, unsigned arg3, bool arg4);
    void method4(float arg0, bool arg1, short arg2, int arg3, double arg4);
    void method5(double arg0, bool arg1, double arg2, float arg3, unsigned arg4);
    void method6(bool arg0, float arg1, double arg2, bool arg3, double arg4);
    void method7(float arg0, int arg1, float arg2, int arg3, unsigned arg4);
    void method8(short arg0, float arg1, unsigned arg2, short arg3, float arg4);
    void method9(int arg0, float arg1, int arg2, float arg3, float arg4);
    void method10(unsigned arg0, short arg1, short arg2, int arg3, double arg4);
    void method11(bool arg0, int arg1, bool arg2, int arg3, int arg4);
    float method12(float arg0, short arg1, int arg2, unsigned arg3, float arg4);
    void method13(short arg0, float arg1, float arg2, float arg3, bool arg4);
    unsigned method14(unsigned arg0, unsigned arg1, bool arg2, int arg3, unsigned arg4);
};

namespace ns_Class62
{
    bool method0(double arg0, unsigned arg1, float arg2, unsigned arg3, bool arg4);
    float method1(short arg0, bool arg1, bool arg2, float arg3, unsigned arg4);
    void method2(int arg0, int arg1, unsigned arg2, int arg3, float arg4);
    bool method3(int arg0, double arg1, int arg2, unsigned arg3, bool arg4);
    void method4(float arg0, bool arg1, short arg2, int arg3, double arg4);
    void method5(double arg0, bool arg1, double arg2, float arg3, unsigned arg4);
    void method6(bool arg0, float arg1, double arg2, bool arg3, double arg4);
    void method7(float arg0, int arg1, float arg2, int arg3, unsigned arg4);
    void method8(short arg0, float arg1, unsigned arg2, short arg3, float arg4);
    void method9(int arg0, float arg1, int arg2, float arg3, float arg4);
    void method10(unsigned arg0, short arg1, short arg2, int arg3, double arg4);
    void method11(bool arg0, int arg1, bool arg2, int arg3, int arg4);
    float method12(float arg0, short arg1, int arg2, unsigned arg3, float arg4);
    void method13(short arg0, float arg1, float arg2, float arg3, bool arg4);
    unsigned method14(unsigned arg0, unsigned arg1, bool arg2, int arg3, unsigned arg4);
}
