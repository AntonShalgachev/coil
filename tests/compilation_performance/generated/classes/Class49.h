#pragma once

#include "../../Common.h"

class Class49
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(short arg0, bool arg1, bool arg2, float arg3, unsigned arg4);
    unsigned method1(short arg0, int arg1, bool arg2, unsigned arg3, unsigned arg4);
    unsigned method2(unsigned arg0, short arg1, int arg2, unsigned arg3, unsigned arg4);
    float method3(int arg0, double arg1, float arg2, int arg3, double arg4);
    void method4(bool arg0, double arg1, unsigned arg2, unsigned arg3, float arg4);
    int method5(int arg0, double arg1, double arg2, bool arg3, float arg4);
    void method6(double arg0, short arg1, double arg2, short arg3, bool arg4);
    bool method7(double arg0, int arg1, int arg2, bool arg3, float arg4);
    short method8(short arg0, int arg1, bool arg2, double arg3, bool arg4);
    void method9(unsigned arg0, double arg1, float arg2, short arg3, int arg4);
    void method10(int arg0, double arg1, short arg2, int arg3, bool arg4);
    bool method11(int arg0, int arg1, unsigned arg2, bool arg3, unsigned arg4);
    void method12(double arg0, bool arg1, int arg2, unsigned arg3, double arg4);
    void method13(short arg0, bool arg1, float arg2, unsigned arg3, int arg4);
    void method14(short arg0, bool arg1, double arg2, double arg3, short arg4);
};

namespace ns_Class49
{
    bool method0(short arg0, bool arg1, bool arg2, float arg3, unsigned arg4);
    unsigned method1(short arg0, int arg1, bool arg2, unsigned arg3, unsigned arg4);
    unsigned method2(unsigned arg0, short arg1, int arg2, unsigned arg3, unsigned arg4);
    float method3(int arg0, double arg1, float arg2, int arg3, double arg4);
    void method4(bool arg0, double arg1, unsigned arg2, unsigned arg3, float arg4);
    int method5(int arg0, double arg1, double arg2, bool arg3, float arg4);
    void method6(double arg0, short arg1, double arg2, short arg3, bool arg4);
    bool method7(double arg0, int arg1, int arg2, bool arg3, float arg4);
    short method8(short arg0, int arg1, bool arg2, double arg3, bool arg4);
    void method9(unsigned arg0, double arg1, float arg2, short arg3, int arg4);
    void method10(int arg0, double arg1, short arg2, int arg3, bool arg4);
    bool method11(int arg0, int arg1, unsigned arg2, bool arg3, unsigned arg4);
    void method12(double arg0, bool arg1, int arg2, unsigned arg3, double arg4);
    void method13(short arg0, bool arg1, float arg2, unsigned arg3, int arg4);
    void method14(short arg0, bool arg1, double arg2, double arg3, short arg4);
}
