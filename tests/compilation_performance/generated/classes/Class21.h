#pragma once

#include "../../Common.h"

class Class21
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(double arg0, bool arg1, bool arg2, double arg3, double arg4);
    double method1(float arg0, double arg1, unsigned arg2, double arg3, int arg4);
    short method2(bool arg0, double arg1, float arg2, short arg3, double arg4);
    void method3(float arg0, unsigned arg1, unsigned arg2, double arg3, double arg4);
    void method4(short arg0, int arg1, double arg2, float arg3, unsigned arg4);
    double method5(int arg0, short arg1, unsigned arg2, short arg3, double arg4);
    int method6(short arg0, double arg1, int arg2, short arg3, double arg4);
    unsigned method7(float arg0, double arg1, double arg2, unsigned arg3, short arg4);
    void method8(int arg0, double arg1, short arg2, int arg3, float arg4);
    void method9(float arg0, bool arg1, bool arg2, unsigned arg3, double arg4);
    short method10(int arg0, short arg1, bool arg2, double arg3, bool arg4);
    void method11(short arg0, double arg1, float arg2, short arg3, double arg4);
    void method12(unsigned arg0, bool arg1, double arg2, float arg3, double arg4);
    unsigned method13(int arg0, short arg1, unsigned arg2, bool arg3, int arg4);
    unsigned method14(double arg0, double arg1, unsigned arg2, double arg3, short arg4);
};

namespace ns_Class21
{
    bool method0(double arg0, bool arg1, bool arg2, double arg3, double arg4);
    double method1(float arg0, double arg1, unsigned arg2, double arg3, int arg4);
    short method2(bool arg0, double arg1, float arg2, short arg3, double arg4);
    void method3(float arg0, unsigned arg1, unsigned arg2, double arg3, double arg4);
    void method4(short arg0, int arg1, double arg2, float arg3, unsigned arg4);
    double method5(int arg0, short arg1, unsigned arg2, short arg3, double arg4);
    int method6(short arg0, double arg1, int arg2, short arg3, double arg4);
    unsigned method7(float arg0, double arg1, double arg2, unsigned arg3, short arg4);
    void method8(int arg0, double arg1, short arg2, int arg3, float arg4);
    void method9(float arg0, bool arg1, bool arg2, unsigned arg3, double arg4);
    short method10(int arg0, short arg1, bool arg2, double arg3, bool arg4);
    void method11(short arg0, double arg1, float arg2, short arg3, double arg4);
    void method12(unsigned arg0, bool arg1, double arg2, float arg3, double arg4);
    unsigned method13(int arg0, short arg1, unsigned arg2, bool arg3, int arg4);
    unsigned method14(double arg0, double arg1, unsigned arg2, double arg3, short arg4);
}
