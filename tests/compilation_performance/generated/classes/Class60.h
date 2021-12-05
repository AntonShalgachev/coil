#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class60
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, short arg1, float arg2, int arg3, float arg4);
    float method1(double arg0, unsigned arg1, short arg2, float arg3, float arg4);
    void method2(unsigned arg0, unsigned arg1, bool arg2, unsigned arg3, short arg4);
    void method3(bool arg0, double arg1, int arg2, float arg3, bool arg4);
    void method4(short arg0, float arg1, bool arg2, int arg3, short arg4);
    void method5(bool arg0, double arg1, unsigned arg2, unsigned arg3, double arg4);
    void method6(int arg0, float arg1, float arg2, int arg3, unsigned arg4);
    int method7(double arg0, unsigned arg1, float arg2, unsigned arg3, int arg4);
    void method8(bool arg0, short arg1, short arg2, int arg3, short arg4);
    void method9(unsigned arg0, double arg1, bool arg2, float arg3, bool arg4);
    float method10(double arg0, short arg1, unsigned arg2, float arg3, float arg4);
    void method11(float arg0, bool arg1, unsigned arg2, short arg3, float arg4);
    void method12(short arg0, double arg1, short arg2, bool arg3, unsigned arg4);
    void method13(float arg0, double arg1, bool arg2, bool arg3, unsigned arg4);
    void method14(float arg0, bool arg1, bool arg2, double arg3, unsigned arg4);
};

namespace ns_Class60
{
    void method0(unsigned arg0, short arg1, float arg2, int arg3, float arg4);
    float method1(double arg0, unsigned arg1, short arg2, float arg3, float arg4);
    void method2(unsigned arg0, unsigned arg1, bool arg2, unsigned arg3, short arg4);
    void method3(bool arg0, double arg1, int arg2, float arg3, bool arg4);
    void method4(short arg0, float arg1, bool arg2, int arg3, short arg4);
    void method5(bool arg0, double arg1, unsigned arg2, unsigned arg3, double arg4);
    void method6(int arg0, float arg1, float arg2, int arg3, unsigned arg4);
    int method7(double arg0, unsigned arg1, float arg2, unsigned arg3, int arg4);
    void method8(bool arg0, short arg1, short arg2, int arg3, short arg4);
    void method9(unsigned arg0, double arg1, bool arg2, float arg3, bool arg4);
    float method10(double arg0, short arg1, unsigned arg2, float arg3, float arg4);
    void method11(float arg0, bool arg1, unsigned arg2, short arg3, float arg4);
    void method12(short arg0, double arg1, short arg2, bool arg3, unsigned arg4);
    void method13(float arg0, double arg1, bool arg2, bool arg3, unsigned arg4);
    void method14(float arg0, bool arg1, bool arg2, double arg3, unsigned arg4);
}
