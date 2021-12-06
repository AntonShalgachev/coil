#pragma once

#include "../../Common.h"

class Class93
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(bool arg0, float arg1, unsigned arg2, double arg3, int arg4);
    void method1(double arg0, short arg1, bool arg2, float arg3, bool arg4);
    void method2(double arg0, bool arg1, short arg2, unsigned arg3, float arg4);
    void method3(short arg0, unsigned arg1, float arg2, int arg3, bool arg4);
    bool method4(unsigned arg0, bool arg1, bool arg2, bool arg3, bool arg4);
    short method5(short arg0, unsigned arg1, double arg2, double arg3, bool arg4);
    void method6(int arg0, int arg1, short arg2, short arg3, short arg4);
    bool method7(float arg0, unsigned arg1, double arg2, int arg3, bool arg4);
    void method8(short arg0, float arg1, float arg2, unsigned arg3, float arg4);
    short method9(double arg0, int arg1, short arg2, short arg3, double arg4);
    short method10(short arg0, float arg1, unsigned arg2, int arg3, unsigned arg4);
    void method11(bool arg0, unsigned arg1, double arg2, short arg3, int arg4);
    void method12(float arg0, float arg1, double arg2, unsigned arg3, unsigned arg4);
    void method13(unsigned arg0, unsigned arg1, unsigned arg2, short arg3, double arg4);
    void method14(unsigned arg0, unsigned arg1, double arg2, int arg3, bool arg4);
};

namespace ns_Class93
{
    unsigned method0(bool arg0, float arg1, unsigned arg2, double arg3, int arg4);
    void method1(double arg0, short arg1, bool arg2, float arg3, bool arg4);
    void method2(double arg0, bool arg1, short arg2, unsigned arg3, float arg4);
    void method3(short arg0, unsigned arg1, float arg2, int arg3, bool arg4);
    bool method4(unsigned arg0, bool arg1, bool arg2, bool arg3, bool arg4);
    short method5(short arg0, unsigned arg1, double arg2, double arg3, bool arg4);
    void method6(int arg0, int arg1, short arg2, short arg3, short arg4);
    bool method7(float arg0, unsigned arg1, double arg2, int arg3, bool arg4);
    void method8(short arg0, float arg1, float arg2, unsigned arg3, float arg4);
    short method9(double arg0, int arg1, short arg2, short arg3, double arg4);
    short method10(short arg0, float arg1, unsigned arg2, int arg3, unsigned arg4);
    void method11(bool arg0, unsigned arg1, double arg2, short arg3, int arg4);
    void method12(float arg0, float arg1, double arg2, unsigned arg3, unsigned arg4);
    void method13(unsigned arg0, unsigned arg1, unsigned arg2, short arg3, double arg4);
    void method14(unsigned arg0, unsigned arg1, double arg2, int arg3, bool arg4);
}
