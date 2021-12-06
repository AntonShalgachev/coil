#pragma once

#include "../../Common.h"

class Class6
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, double arg1, unsigned arg2, bool arg3, float arg4);
    void method1(int arg0, bool arg1, double arg2, bool arg3, double arg4);
    void method2(bool arg0, unsigned arg1, double arg2, bool arg3, double arg4);
    bool method3(float arg0, double arg1, bool arg2, float arg3, bool arg4);
    void method4(int arg0, unsigned arg1, bool arg2, int arg3, unsigned arg4);
    void method5(int arg0, unsigned arg1, short arg2, int arg3, bool arg4);
    void method6(float arg0, bool arg1, double arg2, float arg3, int arg4);
    void method7(short arg0, short arg1, bool arg2, double arg3, float arg4);
    void method8(double arg0, int arg1, int arg2, short arg3, int arg4);
    void method9(int arg0, double arg1, float arg2, short arg3, float arg4);
    void method10(unsigned arg0, double arg1, unsigned arg2, float arg3, double arg4);
    void method11(double arg0, int arg1, short arg2, bool arg3, unsigned arg4);
    unsigned method12(unsigned arg0, float arg1, float arg2, double arg3, bool arg4);
    bool method13(bool arg0, unsigned arg1, bool arg2, int arg3, short arg4);
    unsigned method14(unsigned arg0, int arg1, int arg2, double arg3, int arg4);
};

namespace ns_Class6
{
    void method0(float arg0, double arg1, unsigned arg2, bool arg3, float arg4);
    void method1(int arg0, bool arg1, double arg2, bool arg3, double arg4);
    void method2(bool arg0, unsigned arg1, double arg2, bool arg3, double arg4);
    bool method3(float arg0, double arg1, bool arg2, float arg3, bool arg4);
    void method4(int arg0, unsigned arg1, bool arg2, int arg3, unsigned arg4);
    void method5(int arg0, unsigned arg1, short arg2, int arg3, bool arg4);
    void method6(float arg0, bool arg1, double arg2, float arg3, int arg4);
    void method7(short arg0, short arg1, bool arg2, double arg3, float arg4);
    void method8(double arg0, int arg1, int arg2, short arg3, int arg4);
    void method9(int arg0, double arg1, float arg2, short arg3, float arg4);
    void method10(unsigned arg0, double arg1, unsigned arg2, float arg3, double arg4);
    void method11(double arg0, int arg1, short arg2, bool arg3, unsigned arg4);
    unsigned method12(unsigned arg0, float arg1, float arg2, double arg3, bool arg4);
    bool method13(bool arg0, unsigned arg1, bool arg2, int arg3, short arg4);
    unsigned method14(unsigned arg0, int arg1, int arg2, double arg3, int arg4);
}
