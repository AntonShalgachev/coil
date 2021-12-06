#pragma once

#include "../../Common.h"

class Class33
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(bool arg0, float arg1, unsigned arg2, bool arg3, int arg4);
    void method1(float arg0, int arg1, double arg2, unsigned arg3, float arg4);
    void method2(int arg0, short arg1, unsigned arg2, float arg3, bool arg4);
    unsigned method3(short arg0, unsigned arg1, bool arg2, short arg3, float arg4);
    short method4(unsigned arg0, bool arg1, int arg2, bool arg3, short arg4);
    unsigned method5(short arg0, short arg1, unsigned arg2, double arg3, bool arg4);
    bool method6(short arg0, bool arg1, unsigned arg2, float arg3, bool arg4);
    double method7(float arg0, double arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method8(float arg0, short arg1, short arg2, unsigned arg3, double arg4);
    bool method9(bool arg0, bool arg1, double arg2, float arg3, bool arg4);
    void method10(double arg0, bool arg1, int arg2, float arg3, bool arg4);
    void method11(unsigned arg0, bool arg1, bool arg2, int arg3, unsigned arg4);
    short method12(float arg0, bool arg1, double arg2, double arg3, short arg4);
    void method13(bool arg0, unsigned arg1, unsigned arg2, bool arg3, double arg4);
    void method14(float arg0, double arg1, short arg2, float arg3, float arg4);
};

namespace ns_Class33
{
    float method0(bool arg0, float arg1, unsigned arg2, bool arg3, int arg4);
    void method1(float arg0, int arg1, double arg2, unsigned arg3, float arg4);
    void method2(int arg0, short arg1, unsigned arg2, float arg3, bool arg4);
    unsigned method3(short arg0, unsigned arg1, bool arg2, short arg3, float arg4);
    short method4(unsigned arg0, bool arg1, int arg2, bool arg3, short arg4);
    unsigned method5(short arg0, short arg1, unsigned arg2, double arg3, bool arg4);
    bool method6(short arg0, bool arg1, unsigned arg2, float arg3, bool arg4);
    double method7(float arg0, double arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method8(float arg0, short arg1, short arg2, unsigned arg3, double arg4);
    bool method9(bool arg0, bool arg1, double arg2, float arg3, bool arg4);
    void method10(double arg0, bool arg1, int arg2, float arg3, bool arg4);
    void method11(unsigned arg0, bool arg1, bool arg2, int arg3, unsigned arg4);
    short method12(float arg0, bool arg1, double arg2, double arg3, short arg4);
    void method13(bool arg0, unsigned arg1, unsigned arg2, bool arg3, double arg4);
    void method14(float arg0, double arg1, short arg2, float arg3, float arg4);
}
