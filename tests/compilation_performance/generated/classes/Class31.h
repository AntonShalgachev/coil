#pragma once

#include "../../Common.h"

class Class31
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(double arg0, bool arg1, double arg2, bool arg3, bool arg4);
    bool method1(double arg0, int arg1, short arg2, bool arg3, unsigned arg4);
    bool method2(unsigned arg0, bool arg1, int arg2, int arg3, double arg4);
    bool method3(unsigned arg0, double arg1, int arg2, bool arg3, unsigned arg4);
    bool method4(short arg0, short arg1, bool arg2, bool arg3, bool arg4);
    short method5(int arg0, short arg1, float arg2, int arg3, bool arg4);
    void method6(float arg0, bool arg1, unsigned arg2, short arg3, float arg4);
    short method7(double arg0, double arg1, short arg2, bool arg3, short arg4);
    float method8(bool arg0, int arg1, float arg2, float arg3, double arg4);
    bool method9(short arg0, double arg1, double arg2, short arg3, bool arg4);
    int method10(short arg0, float arg1, short arg2, float arg3, int arg4);
    int method11(bool arg0, int arg1, float arg2, bool arg3, int arg4);
    void method12(unsigned arg0, int arg1, double arg2, double arg3, bool arg4);
    void method13(int arg0, int arg1, float arg2, double arg3, unsigned arg4);
    void method14(int arg0, float arg1, float arg2, double arg3, int arg4);
};

namespace ns_Class31
{
    bool method0(double arg0, bool arg1, double arg2, bool arg3, bool arg4);
    bool method1(double arg0, int arg1, short arg2, bool arg3, unsigned arg4);
    bool method2(unsigned arg0, bool arg1, int arg2, int arg3, double arg4);
    bool method3(unsigned arg0, double arg1, int arg2, bool arg3, unsigned arg4);
    bool method4(short arg0, short arg1, bool arg2, bool arg3, bool arg4);
    short method5(int arg0, short arg1, float arg2, int arg3, bool arg4);
    void method6(float arg0, bool arg1, unsigned arg2, short arg3, float arg4);
    short method7(double arg0, double arg1, short arg2, bool arg3, short arg4);
    float method8(bool arg0, int arg1, float arg2, float arg3, double arg4);
    bool method9(short arg0, double arg1, double arg2, short arg3, bool arg4);
    int method10(short arg0, float arg1, short arg2, float arg3, int arg4);
    int method11(bool arg0, int arg1, float arg2, bool arg3, int arg4);
    void method12(unsigned arg0, int arg1, double arg2, double arg3, bool arg4);
    void method13(int arg0, int arg1, float arg2, double arg3, unsigned arg4);
    void method14(int arg0, float arg1, float arg2, double arg3, int arg4);
}
