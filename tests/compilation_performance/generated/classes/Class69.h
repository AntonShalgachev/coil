#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class69
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(bool arg0, unsigned arg1, float arg2, float arg3, int arg4);
    void method1(double arg0, short arg1, short arg2, unsigned arg3, int arg4);
    double method2(double arg0, int arg1, double arg2, bool arg3, int arg4);
    short method3(double arg0, short arg1, double arg2, short arg3, int arg4);
    int method4(int arg0, int arg1, double arg2, unsigned arg3, short arg4);
    short method5(unsigned arg0, float arg1, short arg2, float arg3, short arg4);
    void method6(float arg0, bool arg1, float arg2, double arg3, int arg4);
    void method7(bool arg0, bool arg1, int arg2, short arg3, bool arg4);
    void method8(double arg0, double arg1, unsigned arg2, bool arg3, bool arg4);
    unsigned method9(bool arg0, double arg1, unsigned arg2, float arg3, short arg4);
    float method10(double arg0, float arg1, bool arg2, float arg3, double arg4);
    void method11(int arg0, short arg1, float arg2, float arg3, int arg4);
    int method12(unsigned arg0, int arg1, double arg2, unsigned arg3, int arg4);
    void method13(float arg0, double arg1, short arg2, unsigned arg3, double arg4);
    void method14(double arg0, double arg1, int arg2, short arg3, int arg4);
};

namespace ns_Class69
{
    void method0(bool arg0, unsigned arg1, float arg2, float arg3, int arg4);
    void method1(double arg0, short arg1, short arg2, unsigned arg3, int arg4);
    double method2(double arg0, int arg1, double arg2, bool arg3, int arg4);
    short method3(double arg0, short arg1, double arg2, short arg3, int arg4);
    int method4(int arg0, int arg1, double arg2, unsigned arg3, short arg4);
    short method5(unsigned arg0, float arg1, short arg2, float arg3, short arg4);
    void method6(float arg0, bool arg1, float arg2, double arg3, int arg4);
    void method7(bool arg0, bool arg1, int arg2, short arg3, bool arg4);
    void method8(double arg0, double arg1, unsigned arg2, bool arg3, bool arg4);
    unsigned method9(bool arg0, double arg1, unsigned arg2, float arg3, short arg4);
    float method10(double arg0, float arg1, bool arg2, float arg3, double arg4);
    void method11(int arg0, short arg1, float arg2, float arg3, int arg4);
    int method12(unsigned arg0, int arg1, double arg2, unsigned arg3, int arg4);
    void method13(float arg0, double arg1, short arg2, unsigned arg3, double arg4);
    void method14(double arg0, double arg1, int arg2, short arg3, int arg4);
}
