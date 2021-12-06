#pragma once

#include "../../Common.h"

class Class1
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(bool arg0, double arg1, double arg2, float arg3, bool arg4);
    void method1(unsigned arg0, short arg1, float arg2, short arg3, short arg4);
    double method2(bool arg0, unsigned arg1, unsigned arg2, double arg3, float arg4);
    void method3(float arg0, float arg1, short arg2, float arg3, float arg4);
    short method4(int arg0, bool arg1, bool arg2, short arg3, int arg4);
    unsigned method5(double arg0, unsigned arg1, bool arg2, unsigned arg3, int arg4);
    float method6(double arg0, float arg1, bool arg2, int arg3, unsigned arg4);
    void method7(short arg0, int arg1, unsigned arg2, bool arg3, short arg4);
    double method8(float arg0, double arg1, float arg2, bool arg3, double arg4);
    void method9(short arg0, float arg1, double arg2, int arg3, double arg4);
    void method10(short arg0, int arg1, float arg2, unsigned arg3, double arg4);
    void method11(int arg0, bool arg1, bool arg2, double arg3, int arg4);
    int method12(bool arg0, short arg1, float arg2, bool arg3, int arg4);
    bool method13(unsigned arg0, unsigned arg1, bool arg2, float arg3, double arg4);
    void method14(int arg0, unsigned arg1, bool arg2, double arg3, unsigned arg4);
};

namespace ns_Class1
{
    bool method0(bool arg0, double arg1, double arg2, float arg3, bool arg4);
    void method1(unsigned arg0, short arg1, float arg2, short arg3, short arg4);
    double method2(bool arg0, unsigned arg1, unsigned arg2, double arg3, float arg4);
    void method3(float arg0, float arg1, short arg2, float arg3, float arg4);
    short method4(int arg0, bool arg1, bool arg2, short arg3, int arg4);
    unsigned method5(double arg0, unsigned arg1, bool arg2, unsigned arg3, int arg4);
    float method6(double arg0, float arg1, bool arg2, int arg3, unsigned arg4);
    void method7(short arg0, int arg1, unsigned arg2, bool arg3, short arg4);
    double method8(float arg0, double arg1, float arg2, bool arg3, double arg4);
    void method9(short arg0, float arg1, double arg2, int arg3, double arg4);
    void method10(short arg0, int arg1, float arg2, unsigned arg3, double arg4);
    void method11(int arg0, bool arg1, bool arg2, double arg3, int arg4);
    int method12(bool arg0, short arg1, float arg2, bool arg3, int arg4);
    bool method13(unsigned arg0, unsigned arg1, bool arg2, float arg3, double arg4);
    void method14(int arg0, unsigned arg1, bool arg2, double arg3, unsigned arg4);
}
