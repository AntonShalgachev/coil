#pragma once

#include "../../Common.h"

class Class89
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, unsigned arg1, bool arg2, double arg3, double arg4);
    void method1(float arg0, bool arg1, unsigned arg2, unsigned arg3, short arg4);
    void method2(double arg0, double arg1, unsigned arg2, short arg3, double arg4);
    void method3(int arg0, short arg1, short arg2, bool arg3, bool arg4);
    unsigned method4(short arg0, float arg1, double arg2, unsigned arg3, unsigned arg4);
    unsigned method5(unsigned arg0, int arg1, short arg2, short arg3, double arg4);
    void method6(float arg0, short arg1, unsigned arg2, float arg3, unsigned arg4);
    bool method7(float arg0, short arg1, bool arg2, double arg3, int arg4);
    void method8(int arg0, short arg1, float arg2, short arg3, unsigned arg4);
    int method9(unsigned arg0, unsigned arg1, double arg2, unsigned arg3, int arg4);
    void method10(unsigned arg0, bool arg1, short arg2, unsigned arg3, int arg4);
    void method11(float arg0, short arg1, double arg2, unsigned arg3, float arg4);
    double method12(double arg0, short arg1, bool arg2, double arg3, double arg4);
    void method13(double arg0, int arg1, double arg2, bool arg3, float arg4);
    bool method14(bool arg0, short arg1, bool arg2, double arg3, bool arg4);
};

namespace ns_Class89
{
    void method0(int arg0, unsigned arg1, bool arg2, double arg3, double arg4);
    void method1(float arg0, bool arg1, unsigned arg2, unsigned arg3, short arg4);
    void method2(double arg0, double arg1, unsigned arg2, short arg3, double arg4);
    void method3(int arg0, short arg1, short arg2, bool arg3, bool arg4);
    unsigned method4(short arg0, float arg1, double arg2, unsigned arg3, unsigned arg4);
    unsigned method5(unsigned arg0, int arg1, short arg2, short arg3, double arg4);
    void method6(float arg0, short arg1, unsigned arg2, float arg3, unsigned arg4);
    bool method7(float arg0, short arg1, bool arg2, double arg3, int arg4);
    void method8(int arg0, short arg1, float arg2, short arg3, unsigned arg4);
    int method9(unsigned arg0, unsigned arg1, double arg2, unsigned arg3, int arg4);
    void method10(unsigned arg0, bool arg1, short arg2, unsigned arg3, int arg4);
    void method11(float arg0, short arg1, double arg2, unsigned arg3, float arg4);
    double method12(double arg0, short arg1, bool arg2, double arg3, double arg4);
    void method13(double arg0, int arg1, double arg2, bool arg3, float arg4);
    bool method14(bool arg0, short arg1, bool arg2, double arg3, bool arg4);
}
