#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class63
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    double method1(unsigned arg0, bool arg1, double arg2, short arg3, int arg4);
    float method2(int arg0, bool arg1, short arg2, float arg3, int arg4);
    void method3(int arg0, int arg1, float arg2, int arg3, float arg4);
    unsigned method4(double arg0, unsigned arg1, double arg2, double arg3, int arg4);
    int method5(unsigned arg0, bool arg1, float arg2, float arg3, int arg4);
    void method6(unsigned arg0, float arg1, double arg2, double arg3, float arg4);
    void method7(double arg0, double arg1, double arg2, float arg3, int arg4);
    void method8(bool arg0, unsigned arg1, unsigned arg2, bool arg3, float arg4);
    double method9(double arg0, double arg1, int arg2, int arg3, unsigned arg4);
    void method10(bool arg0, int arg1, short arg2, double arg3, float arg4);
    short method11(double arg0, short arg1, int arg2, bool arg3, bool arg4);
    void method12(unsigned arg0, float arg1, float arg2, unsigned arg3, double arg4);
    short method13(int arg0, bool arg1, short arg2, short arg3, short arg4);
    short method14(float arg0, unsigned arg1, int arg2, int arg3, short arg4);
};

namespace ns_Class63
{
    void method0(float arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    double method1(unsigned arg0, bool arg1, double arg2, short arg3, int arg4);
    float method2(int arg0, bool arg1, short arg2, float arg3, int arg4);
    void method3(int arg0, int arg1, float arg2, int arg3, float arg4);
    unsigned method4(double arg0, unsigned arg1, double arg2, double arg3, int arg4);
    int method5(unsigned arg0, bool arg1, float arg2, float arg3, int arg4);
    void method6(unsigned arg0, float arg1, double arg2, double arg3, float arg4);
    void method7(double arg0, double arg1, double arg2, float arg3, int arg4);
    void method8(bool arg0, unsigned arg1, unsigned arg2, bool arg3, float arg4);
    double method9(double arg0, double arg1, int arg2, int arg3, unsigned arg4);
    void method10(bool arg0, int arg1, short arg2, double arg3, float arg4);
    short method11(double arg0, short arg1, int arg2, bool arg3, bool arg4);
    void method12(unsigned arg0, float arg1, float arg2, unsigned arg3, double arg4);
    short method13(int arg0, bool arg1, short arg2, short arg3, short arg4);
    short method14(float arg0, unsigned arg1, int arg2, int arg3, short arg4);
}
