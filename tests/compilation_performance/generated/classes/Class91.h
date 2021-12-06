#pragma once

#include "../../Common.h"

class Class91
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(int arg0, bool arg1, short arg2, double arg3, float arg4);
    short method1(short arg0, double arg1, double arg2, unsigned arg3, short arg4);
    void method2(unsigned arg0, short arg1, float arg2, short arg3, bool arg4);
    unsigned method3(float arg0, double arg1, float arg2, unsigned arg3, bool arg4);
    void method4(int arg0, bool arg1, unsigned arg2, int arg3, float arg4);
    void method5(short arg0, float arg1, short arg2, short arg3, short arg4);
    void method6(float arg0, bool arg1, double arg2, short arg3, int arg4);
    bool method7(bool arg0, bool arg1, unsigned arg2, bool arg3, int arg4);
    short method8(short arg0, double arg1, short arg2, float arg3, short arg4);
    double method9(unsigned arg0, double arg1, short arg2, unsigned arg3, unsigned arg4);
    unsigned method10(bool arg0, short arg1, unsigned arg2, double arg3, float arg4);
    void method11(float arg0, int arg1, short arg2, int arg3, bool arg4);
    unsigned method12(int arg0, short arg1, unsigned arg2, float arg3, unsigned arg4);
    bool method13(bool arg0, float arg1, double arg2, unsigned arg3, double arg4);
    void method14(unsigned arg0, float arg1, double arg2, unsigned arg3, bool arg4);
};

namespace ns_Class91
{
    double method0(int arg0, bool arg1, short arg2, double arg3, float arg4);
    short method1(short arg0, double arg1, double arg2, unsigned arg3, short arg4);
    void method2(unsigned arg0, short arg1, float arg2, short arg3, bool arg4);
    unsigned method3(float arg0, double arg1, float arg2, unsigned arg3, bool arg4);
    void method4(int arg0, bool arg1, unsigned arg2, int arg3, float arg4);
    void method5(short arg0, float arg1, short arg2, short arg3, short arg4);
    void method6(float arg0, bool arg1, double arg2, short arg3, int arg4);
    bool method7(bool arg0, bool arg1, unsigned arg2, bool arg3, int arg4);
    short method8(short arg0, double arg1, short arg2, float arg3, short arg4);
    double method9(unsigned arg0, double arg1, short arg2, unsigned arg3, unsigned arg4);
    unsigned method10(bool arg0, short arg1, unsigned arg2, double arg3, float arg4);
    void method11(float arg0, int arg1, short arg2, int arg3, bool arg4);
    unsigned method12(int arg0, short arg1, unsigned arg2, float arg3, unsigned arg4);
    bool method13(bool arg0, float arg1, double arg2, unsigned arg3, double arg4);
    void method14(unsigned arg0, float arg1, double arg2, unsigned arg3, bool arg4);
}
