#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class47
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, double arg1, float arg2, int arg3, unsigned arg4);
    void method1(double arg0, int arg1, short arg2, short arg3, int arg4);
    int method2(short arg0, short arg1, unsigned arg2, int arg3, double arg4);
    void method3(float arg0, bool arg1, double arg2, bool arg3, bool arg4);
    void method4(unsigned arg0, short arg1, short arg2, bool arg3, double arg4);
    void method5(short arg0, short arg1, double arg2, int arg3, double arg4);
    void method6(int arg0, int arg1, short arg2, bool arg3, unsigned arg4);
    void method7(unsigned arg0, unsigned arg1, int arg2, short arg3, double arg4);
    double method8(short arg0, int arg1, double arg2, unsigned arg3, int arg4);
    int method9(float arg0, unsigned arg1, short arg2, int arg3, unsigned arg4);
    void method10(float arg0, short arg1, int arg2, float arg3, double arg4);
    void method11(double arg0, short arg1, double arg2, short arg3, unsigned arg4);
    void method12(double arg0, bool arg1, int arg2, bool arg3, short arg4);
    float method13(int arg0, float arg1, bool arg2, double arg3, float arg4);
    void method14(float arg0, short arg1, double arg2, int arg3, unsigned arg4);
};

namespace ns_Class47
{
    void method0(int arg0, double arg1, float arg2, int arg3, unsigned arg4);
    void method1(double arg0, int arg1, short arg2, short arg3, int arg4);
    int method2(short arg0, short arg1, unsigned arg2, int arg3, double arg4);
    void method3(float arg0, bool arg1, double arg2, bool arg3, bool arg4);
    void method4(unsigned arg0, short arg1, short arg2, bool arg3, double arg4);
    void method5(short arg0, short arg1, double arg2, int arg3, double arg4);
    void method6(int arg0, int arg1, short arg2, bool arg3, unsigned arg4);
    void method7(unsigned arg0, unsigned arg1, int arg2, short arg3, double arg4);
    double method8(short arg0, int arg1, double arg2, unsigned arg3, int arg4);
    int method9(float arg0, unsigned arg1, short arg2, int arg3, unsigned arg4);
    void method10(float arg0, short arg1, int arg2, float arg3, double arg4);
    void method11(double arg0, short arg1, double arg2, short arg3, unsigned arg4);
    void method12(double arg0, bool arg1, int arg2, bool arg3, short arg4);
    float method13(int arg0, float arg1, bool arg2, double arg3, float arg4);
    void method14(float arg0, short arg1, double arg2, int arg3, unsigned arg4);
}
