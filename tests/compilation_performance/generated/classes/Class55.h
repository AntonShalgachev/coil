#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class55
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(bool arg0, int arg1, int arg2, float arg3, float arg4);
    void method1(unsigned arg0, bool arg1, int arg2, bool arg3, short arg4);
    void method2(short arg0, double arg1, float arg2, float arg3, double arg4);
    void method3(double arg0, float arg1, float arg2, unsigned arg3, unsigned arg4);
    unsigned method4(int arg0, double arg1, double arg2, unsigned arg3, int arg4);
    float method5(short arg0, float arg1, int arg2, short arg3, short arg4);
    void method6(int arg0, bool arg1, double arg2, unsigned arg3, short arg4);
    int method7(float arg0, double arg1, int arg2, float arg3, bool arg4);
    void method8(unsigned arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    void method9(float arg0, float arg1, int arg2, double arg3, int arg4);
    void method10(float arg0, short arg1, short arg2, float arg3, int arg4);
    void method11(short arg0, short arg1, unsigned arg2, int arg3, int arg4);
    double method12(float arg0, float arg1, double arg2, double arg3, int arg4);
    void method13(float arg0, bool arg1, unsigned arg2, bool arg3, double arg4);
    void method14(unsigned arg0, int arg1, bool arg2, short arg3, unsigned arg4);
};

namespace ns_Class55
{
    int method0(bool arg0, int arg1, int arg2, float arg3, float arg4);
    void method1(unsigned arg0, bool arg1, int arg2, bool arg3, short arg4);
    void method2(short arg0, double arg1, float arg2, float arg3, double arg4);
    void method3(double arg0, float arg1, float arg2, unsigned arg3, unsigned arg4);
    unsigned method4(int arg0, double arg1, double arg2, unsigned arg3, int arg4);
    float method5(short arg0, float arg1, int arg2, short arg3, short arg4);
    void method6(int arg0, bool arg1, double arg2, unsigned arg3, short arg4);
    int method7(float arg0, double arg1, int arg2, float arg3, bool arg4);
    void method8(unsigned arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    void method9(float arg0, float arg1, int arg2, double arg3, int arg4);
    void method10(float arg0, short arg1, short arg2, float arg3, int arg4);
    void method11(short arg0, short arg1, unsigned arg2, int arg3, int arg4);
    double method12(float arg0, float arg1, double arg2, double arg3, int arg4);
    void method13(float arg0, bool arg1, unsigned arg2, bool arg3, double arg4);
    void method14(unsigned arg0, int arg1, bool arg2, short arg3, unsigned arg4);
}
