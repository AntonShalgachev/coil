#pragma once

#include "../../Common.h"

class Class67
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, float arg1, int arg2, bool arg3, int arg4);
    void method1(int arg0, int arg1, double arg2, double arg3, unsigned arg4);
    short method2(bool arg0, short arg1, int arg2, unsigned arg3, unsigned arg4);
    void method3(float arg0, short arg1, bool arg2, int arg3, short arg4);
    double method4(float arg0, bool arg1, double arg2, unsigned arg3, unsigned arg4);
    bool method5(bool arg0, short arg1, int arg2, int arg3, bool arg4);
    bool method6(short arg0, bool arg1, short arg2, double arg3, int arg4);
    void method7(bool arg0, float arg1, short arg2, double arg3, double arg4);
    unsigned method8(unsigned arg0, bool arg1, unsigned arg2, short arg3, double arg4);
    void method9(double arg0, short arg1, int arg2, int arg3, float arg4);
    bool method10(bool arg0, unsigned arg1, bool arg2, double arg3, int arg4);
    int method11(int arg0, int arg1, float arg2, double arg3, int arg4);
    unsigned method12(unsigned arg0, bool arg1, short arg2, double arg3, short arg4);
    void method13(short arg0, bool arg1, bool arg2, double arg3, int arg4);
    void method14(bool arg0, int arg1, unsigned arg2, short arg3, double arg4);
};

namespace ns_Class67
{
    void method0(short arg0, float arg1, int arg2, bool arg3, int arg4);
    void method1(int arg0, int arg1, double arg2, double arg3, unsigned arg4);
    short method2(bool arg0, short arg1, int arg2, unsigned arg3, unsigned arg4);
    void method3(float arg0, short arg1, bool arg2, int arg3, short arg4);
    double method4(float arg0, bool arg1, double arg2, unsigned arg3, unsigned arg4);
    bool method5(bool arg0, short arg1, int arg2, int arg3, bool arg4);
    bool method6(short arg0, bool arg1, short arg2, double arg3, int arg4);
    void method7(bool arg0, float arg1, short arg2, double arg3, double arg4);
    unsigned method8(unsigned arg0, bool arg1, unsigned arg2, short arg3, double arg4);
    void method9(double arg0, short arg1, int arg2, int arg3, float arg4);
    bool method10(bool arg0, unsigned arg1, bool arg2, double arg3, int arg4);
    int method11(int arg0, int arg1, float arg2, double arg3, int arg4);
    unsigned method12(unsigned arg0, bool arg1, short arg2, double arg3, short arg4);
    void method13(short arg0, bool arg1, bool arg2, double arg3, int arg4);
    void method14(bool arg0, int arg1, unsigned arg2, short arg3, double arg4);
}
