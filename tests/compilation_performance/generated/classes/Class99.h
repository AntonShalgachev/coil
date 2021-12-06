#pragma once

#include "../../Common.h"

class Class99
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(bool arg0, short arg1, float arg2, bool arg3, int arg4);
    unsigned method1(bool arg0, unsigned arg1, unsigned arg2, bool arg3, short arg4);
    void method2(short arg0, bool arg1, short arg2, double arg3, short arg4);
    void method3(double arg0, int arg1, unsigned arg2, bool arg3, float arg4);
    double method4(double arg0, bool arg1, short arg2, bool arg3, float arg4);
    bool method5(float arg0, double arg1, unsigned arg2, int arg3, bool arg4);
    double method6(int arg0, double arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    bool method7(int arg0, int arg1, bool arg2, bool arg3, double arg4);
    void method8(int arg0, short arg1, float arg2, short arg3, double arg4);
    double method9(bool arg0, float arg1, short arg2, double arg3, float arg4);
    void method10(int arg0, short arg1, bool arg2, bool arg3, float arg4);
    short method11(int arg0, float arg1, int arg2, double arg3, short arg4);
    short method12(unsigned arg0, bool arg1, double arg2, short arg3, bool arg4);
    short method13(int arg0, int arg1, int arg2, int arg3, short arg4);
    float method14(int arg0, short arg1, float arg2, unsigned arg3, unsigned arg4);
};

namespace ns_Class99
{
    short method0(bool arg0, short arg1, float arg2, bool arg3, int arg4);
    unsigned method1(bool arg0, unsigned arg1, unsigned arg2, bool arg3, short arg4);
    void method2(short arg0, bool arg1, short arg2, double arg3, short arg4);
    void method3(double arg0, int arg1, unsigned arg2, bool arg3, float arg4);
    double method4(double arg0, bool arg1, short arg2, bool arg3, float arg4);
    bool method5(float arg0, double arg1, unsigned arg2, int arg3, bool arg4);
    double method6(int arg0, double arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    bool method7(int arg0, int arg1, bool arg2, bool arg3, double arg4);
    void method8(int arg0, short arg1, float arg2, short arg3, double arg4);
    double method9(bool arg0, float arg1, short arg2, double arg3, float arg4);
    void method10(int arg0, short arg1, bool arg2, bool arg3, float arg4);
    short method11(int arg0, float arg1, int arg2, double arg3, short arg4);
    short method12(unsigned arg0, bool arg1, double arg2, short arg3, bool arg4);
    short method13(int arg0, int arg1, int arg2, int arg3, short arg4);
    float method14(int arg0, short arg1, float arg2, unsigned arg3, unsigned arg4);
}
