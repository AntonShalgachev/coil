#pragma once

#include "../../Common.h"

class Class88
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(unsigned arg0, short arg1, unsigned arg2, double arg3, short arg4);
    void method1(double arg0, bool arg1, int arg2, int arg3, float arg4);
    short method2(unsigned arg0, short arg1, short arg2, unsigned arg3, short arg4);
    bool method3(int arg0, short arg1, bool arg2, int arg3, int arg4);
    float method4(bool arg0, bool arg1, int arg2, float arg3, float arg4);
    unsigned method5(bool arg0, double arg1, unsigned arg2, unsigned arg3, int arg4);
    short method6(bool arg0, int arg1, bool arg2, short arg3, bool arg4);
    short method7(int arg0, short arg1, short arg2, double arg3, short arg4);
    void method8(unsigned arg0, int arg1, short arg2, short arg3, short arg4);
    double method9(bool arg0, bool arg1, double arg2, float arg3, bool arg4);
    void method10(float arg0, bool arg1, short arg2, bool arg3, double arg4);
    bool method11(float arg0, int arg1, short arg2, bool arg3, bool arg4);
    int method12(int arg0, double arg1, double arg2, short arg3, int arg4);
    void method13(unsigned arg0, int arg1, short arg2, double arg3, bool arg4);
    void method14(unsigned arg0, float arg1, short arg2, bool arg3, unsigned arg4);
};

namespace ns_Class88
{
    short method0(unsigned arg0, short arg1, unsigned arg2, double arg3, short arg4);
    void method1(double arg0, bool arg1, int arg2, int arg3, float arg4);
    short method2(unsigned arg0, short arg1, short arg2, unsigned arg3, short arg4);
    bool method3(int arg0, short arg1, bool arg2, int arg3, int arg4);
    float method4(bool arg0, bool arg1, int arg2, float arg3, float arg4);
    unsigned method5(bool arg0, double arg1, unsigned arg2, unsigned arg3, int arg4);
    short method6(bool arg0, int arg1, bool arg2, short arg3, bool arg4);
    short method7(int arg0, short arg1, short arg2, double arg3, short arg4);
    void method8(unsigned arg0, int arg1, short arg2, short arg3, short arg4);
    double method9(bool arg0, bool arg1, double arg2, float arg3, bool arg4);
    void method10(float arg0, bool arg1, short arg2, bool arg3, double arg4);
    bool method11(float arg0, int arg1, short arg2, bool arg3, bool arg4);
    int method12(int arg0, double arg1, double arg2, short arg3, int arg4);
    void method13(unsigned arg0, int arg1, short arg2, double arg3, bool arg4);
    void method14(unsigned arg0, float arg1, short arg2, bool arg3, unsigned arg4);
}
