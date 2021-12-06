#pragma once

#include "../../Common.h"

class Class90
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, int arg1, int arg2, unsigned arg3, double arg4);
    void method1(double arg0, unsigned arg1, short arg2, float arg3, double arg4);
    double method2(double arg0, unsigned arg1, float arg2, double arg3, bool arg4);
    int method3(bool arg0, int arg1, bool arg2, unsigned arg3, float arg4);
    void method4(int arg0, unsigned arg1, double arg2, bool arg3, double arg4);
    void method5(unsigned arg0, int arg1, short arg2, short arg3, unsigned arg4);
    bool method6(short arg0, float arg1, bool arg2, unsigned arg3, bool arg4);
    bool method7(unsigned arg0, bool arg1, unsigned arg2, double arg3, short arg4);
    void method8(short arg0, double arg1, double arg2, double arg3, int arg4);
    void method9(short arg0, int arg1, bool arg2, double arg3, double arg4);
    void method10(int arg0, float arg1, double arg2, double arg3, short arg4);
    void method11(short arg0, bool arg1, bool arg2, int arg3, short arg4);
    int method12(int arg0, double arg1, double arg2, unsigned arg3, int arg4);
    bool method13(float arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    void method14(unsigned arg0, float arg1, double arg2, int arg3, double arg4);
};

namespace ns_Class90
{
    void method0(int arg0, int arg1, int arg2, unsigned arg3, double arg4);
    void method1(double arg0, unsigned arg1, short arg2, float arg3, double arg4);
    double method2(double arg0, unsigned arg1, float arg2, double arg3, bool arg4);
    int method3(bool arg0, int arg1, bool arg2, unsigned arg3, float arg4);
    void method4(int arg0, unsigned arg1, double arg2, bool arg3, double arg4);
    void method5(unsigned arg0, int arg1, short arg2, short arg3, unsigned arg4);
    bool method6(short arg0, float arg1, bool arg2, unsigned arg3, bool arg4);
    bool method7(unsigned arg0, bool arg1, unsigned arg2, double arg3, short arg4);
    void method8(short arg0, double arg1, double arg2, double arg3, int arg4);
    void method9(short arg0, int arg1, bool arg2, double arg3, double arg4);
    void method10(int arg0, float arg1, double arg2, double arg3, short arg4);
    void method11(short arg0, bool arg1, bool arg2, int arg3, short arg4);
    int method12(int arg0, double arg1, double arg2, unsigned arg3, int arg4);
    bool method13(float arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    void method14(unsigned arg0, float arg1, double arg2, int arg3, double arg4);
}
