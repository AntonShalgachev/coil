#pragma once

#include "../../Common.h"

class Class66
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, float arg1, short arg2, int arg3, float arg4);
    bool method1(short arg0, unsigned arg1, bool arg2, int arg3, unsigned arg4);
    double method2(double arg0, double arg1, short arg2, short arg3, int arg4);
    void method3(bool arg0, bool arg1, double arg2, double arg3, unsigned arg4);
    bool method4(int arg0, bool arg1, bool arg2, int arg3, short arg4);
    void method5(double arg0, double arg1, unsigned arg2, int arg3, short arg4);
    unsigned method6(bool arg0, unsigned arg1, bool arg2, unsigned arg3, short arg4);
    void method7(double arg0, unsigned arg1, float arg2, bool arg3, int arg4);
    bool method8(double arg0, double arg1, double arg2, bool arg3, short arg4);
    void method9(bool arg0, double arg1, unsigned arg2, int arg3, int arg4);
    void method10(short arg0, unsigned arg1, bool arg2, float arg3, bool arg4);
    short method11(unsigned arg0, float arg1, bool arg2, short arg3, int arg4);
    unsigned method12(unsigned arg0, unsigned arg1, int arg2, float arg3, float arg4);
    unsigned method13(unsigned arg0, bool arg1, unsigned arg2, bool arg3, bool arg4);
    void method14(double arg0, bool arg1, float arg2, unsigned arg3, short arg4);
};

namespace ns_Class66
{
    void method0(short arg0, float arg1, short arg2, int arg3, float arg4);
    bool method1(short arg0, unsigned arg1, bool arg2, int arg3, unsigned arg4);
    double method2(double arg0, double arg1, short arg2, short arg3, int arg4);
    void method3(bool arg0, bool arg1, double arg2, double arg3, unsigned arg4);
    bool method4(int arg0, bool arg1, bool arg2, int arg3, short arg4);
    void method5(double arg0, double arg1, unsigned arg2, int arg3, short arg4);
    unsigned method6(bool arg0, unsigned arg1, bool arg2, unsigned arg3, short arg4);
    void method7(double arg0, unsigned arg1, float arg2, bool arg3, int arg4);
    bool method8(double arg0, double arg1, double arg2, bool arg3, short arg4);
    void method9(bool arg0, double arg1, unsigned arg2, int arg3, int arg4);
    void method10(short arg0, unsigned arg1, bool arg2, float arg3, bool arg4);
    short method11(unsigned arg0, float arg1, bool arg2, short arg3, int arg4);
    unsigned method12(unsigned arg0, unsigned arg1, int arg2, float arg3, float arg4);
    unsigned method13(unsigned arg0, bool arg1, unsigned arg2, bool arg3, bool arg4);
    void method14(double arg0, bool arg1, float arg2, unsigned arg3, short arg4);
}
