#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class84
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(float arg0, short arg1, double arg2, short arg3, unsigned arg4);
    void method1(float arg0, unsigned arg1, short arg2, double arg3, bool arg4);
    void method2(float arg0, bool arg1, int arg2, float arg3, double arg4);
    float method3(float arg0, bool arg1, int arg2, bool arg3, short arg4);
    int method4(double arg0, double arg1, int arg2, double arg3, int arg4);
    void method5(bool arg0, unsigned arg1, unsigned arg2, double arg3, int arg4);
    unsigned method6(double arg0, int arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method7(unsigned arg0, float arg1, int arg2, bool arg3, bool arg4);
    unsigned method8(unsigned arg0, bool arg1, unsigned arg2, bool arg3, short arg4);
    void method9(int arg0, int arg1, short arg2, short arg3, short arg4);
    int method10(unsigned arg0, unsigned arg1, short arg2, double arg3, int arg4);
    double method11(double arg0, int arg1, double arg2, bool arg3, float arg4);
    void method12(double arg0, int arg1, double arg2, bool arg3, bool arg4);
    void method13(double arg0, bool arg1, unsigned arg2, float arg3, unsigned arg4);
    float method14(double arg0, float arg1, float arg2, unsigned arg3, bool arg4);
};

namespace ns_Class84
{
    short method0(float arg0, short arg1, double arg2, short arg3, unsigned arg4);
    void method1(float arg0, unsigned arg1, short arg2, double arg3, bool arg4);
    void method2(float arg0, bool arg1, int arg2, float arg3, double arg4);
    float method3(float arg0, bool arg1, int arg2, bool arg3, short arg4);
    int method4(double arg0, double arg1, int arg2, double arg3, int arg4);
    void method5(bool arg0, unsigned arg1, unsigned arg2, double arg3, int arg4);
    unsigned method6(double arg0, int arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method7(unsigned arg0, float arg1, int arg2, bool arg3, bool arg4);
    unsigned method8(unsigned arg0, bool arg1, unsigned arg2, bool arg3, short arg4);
    void method9(int arg0, int arg1, short arg2, short arg3, short arg4);
    int method10(unsigned arg0, unsigned arg1, short arg2, double arg3, int arg4);
    double method11(double arg0, int arg1, double arg2, bool arg3, float arg4);
    void method12(double arg0, int arg1, double arg2, bool arg3, bool arg4);
    void method13(double arg0, bool arg1, unsigned arg2, float arg3, unsigned arg4);
    float method14(double arg0, float arg1, float arg2, unsigned arg3, bool arg4);
}
