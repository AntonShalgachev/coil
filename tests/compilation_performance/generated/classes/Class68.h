#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class68
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, double arg1, float arg2, int arg3, double arg4);
    void method1(unsigned arg0, double arg1, short arg2, float arg3, short arg4);
    void method2(float arg0, short arg1, bool arg2, short arg3, int arg4);
    void method3(float arg0, bool arg1, double arg2, bool arg3, float arg4);
    double method4(short arg0, unsigned arg1, float arg2, short arg3, double arg4);
    int method5(unsigned arg0, unsigned arg1, short arg2, int arg3, int arg4);
    void method6(int arg0, bool arg1, float arg2, short arg3, double arg4);
    unsigned method7(double arg0, unsigned arg1, unsigned arg2, double arg3, unsigned arg4);
    unsigned method8(short arg0, short arg1, unsigned arg2, unsigned arg3, double arg4);
    void method9(double arg0, unsigned arg1, bool arg2, short arg3, float arg4);
    void method10(unsigned arg0, float arg1, unsigned arg2, int arg3, float arg4);
    void method11(bool arg0, int arg1, int arg2, short arg3, float arg4);
    void method12(bool arg0, short arg1, bool arg2, bool arg3, float arg4);
    void method13(float arg0, unsigned arg1, bool arg2, short arg3, short arg4);
    float method14(unsigned arg0, float arg1, float arg2, short arg3, int arg4);
};

namespace ns_Class68
{
    void method0(float arg0, double arg1, float arg2, int arg3, double arg4);
    void method1(unsigned arg0, double arg1, short arg2, float arg3, short arg4);
    void method2(float arg0, short arg1, bool arg2, short arg3, int arg4);
    void method3(float arg0, bool arg1, double arg2, bool arg3, float arg4);
    double method4(short arg0, unsigned arg1, float arg2, short arg3, double arg4);
    int method5(unsigned arg0, unsigned arg1, short arg2, int arg3, int arg4);
    void method6(int arg0, bool arg1, float arg2, short arg3, double arg4);
    unsigned method7(double arg0, unsigned arg1, unsigned arg2, double arg3, unsigned arg4);
    unsigned method8(short arg0, short arg1, unsigned arg2, unsigned arg3, double arg4);
    void method9(double arg0, unsigned arg1, bool arg2, short arg3, float arg4);
    void method10(unsigned arg0, float arg1, unsigned arg2, int arg3, float arg4);
    void method11(bool arg0, int arg1, int arg2, short arg3, float arg4);
    void method12(bool arg0, short arg1, bool arg2, bool arg3, float arg4);
    void method13(float arg0, unsigned arg1, bool arg2, short arg3, short arg4);
    float method14(unsigned arg0, float arg1, float arg2, short arg3, int arg4);
}
