#pragma once

#include "../../Common.h"

class Class79
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(bool arg0, short arg1, double arg2, short arg3, bool arg4);
    double method1(int arg0, double arg1, double arg2, float arg3, int arg4);
    short method2(int arg0, short arg1, float arg2, float arg3, int arg4);
    void method3(double arg0, unsigned arg1, short arg2, bool arg3, double arg4);
    short method4(double arg0, unsigned arg1, bool arg2, short arg3, unsigned arg4);
    void method5(unsigned arg0, bool arg1, float arg2, bool arg3, bool arg4);
    void method6(int arg0, bool arg1, float arg2, short arg3, unsigned arg4);
    short method7(short arg0, unsigned arg1, int arg2, int arg3, int arg4);
    void method8(unsigned arg0, unsigned arg1, bool arg2, float arg3, short arg4);
    void method9(short arg0, float arg1, unsigned arg2, unsigned arg3, double arg4);
    bool method10(bool arg0, bool arg1, short arg2, double arg3, float arg4);
    void method11(short arg0, int arg1, float arg2, bool arg3, short arg4);
    void method12(int arg0, double arg1, short arg2, short arg3, int arg4);
    void method13(double arg0, unsigned arg1, short arg2, int arg3, double arg4);
    void method14(short arg0, unsigned arg1, double arg2, int arg3, float arg4);
};

namespace ns_Class79
{
    short method0(bool arg0, short arg1, double arg2, short arg3, bool arg4);
    double method1(int arg0, double arg1, double arg2, float arg3, int arg4);
    short method2(int arg0, short arg1, float arg2, float arg3, int arg4);
    void method3(double arg0, unsigned arg1, short arg2, bool arg3, double arg4);
    short method4(double arg0, unsigned arg1, bool arg2, short arg3, unsigned arg4);
    void method5(unsigned arg0, bool arg1, float arg2, bool arg3, bool arg4);
    void method6(int arg0, bool arg1, float arg2, short arg3, unsigned arg4);
    short method7(short arg0, unsigned arg1, int arg2, int arg3, int arg4);
    void method8(unsigned arg0, unsigned arg1, bool arg2, float arg3, short arg4);
    void method9(short arg0, float arg1, unsigned arg2, unsigned arg3, double arg4);
    bool method10(bool arg0, bool arg1, short arg2, double arg3, float arg4);
    void method11(short arg0, int arg1, float arg2, bool arg3, short arg4);
    void method12(int arg0, double arg1, short arg2, short arg3, int arg4);
    void method13(double arg0, unsigned arg1, short arg2, int arg3, double arg4);
    void method14(short arg0, unsigned arg1, double arg2, int arg3, float arg4);
}
