#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class70
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, bool arg1, int arg2, double arg3, int arg4);
    void method1(float arg0, short arg1, unsigned arg2, bool arg3, float arg4);
    void method2(int arg0, int arg1, short arg2, double arg3, unsigned arg4);
    void method3(bool arg0, short arg1, double arg2, short arg3, unsigned arg4);
    double method4(int arg0, double arg1, bool arg2, double arg3, float arg4);
    void method5(short arg0, short arg1, int arg2, float arg3, bool arg4);
    double method6(unsigned arg0, unsigned arg1, unsigned arg2, double arg3, double arg4);
    void method7(double arg0, double arg1, short arg2, unsigned arg3, double arg4);
    float method8(bool arg0, float arg1, double arg2, bool arg3, double arg4);
    void method9(unsigned arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    void method10(double arg0, double arg1, bool arg2, unsigned arg3, bool arg4);
    void method11(short arg0, unsigned arg1, double arg2, double arg3, double arg4);
    void method12(short arg0, unsigned arg1, short arg2, float arg3, short arg4);
    void method13(float arg0, int arg1, float arg2, unsigned arg3, double arg4);
    void method14(double arg0, bool arg1, bool arg2, float arg3, bool arg4);
};

namespace ns_Class70
{
    void method0(unsigned arg0, bool arg1, int arg2, double arg3, int arg4);
    void method1(float arg0, short arg1, unsigned arg2, bool arg3, float arg4);
    void method2(int arg0, int arg1, short arg2, double arg3, unsigned arg4);
    void method3(bool arg0, short arg1, double arg2, short arg3, unsigned arg4);
    double method4(int arg0, double arg1, bool arg2, double arg3, float arg4);
    void method5(short arg0, short arg1, int arg2, float arg3, bool arg4);
    double method6(unsigned arg0, unsigned arg1, unsigned arg2, double arg3, double arg4);
    void method7(double arg0, double arg1, short arg2, unsigned arg3, double arg4);
    float method8(bool arg0, float arg1, double arg2, bool arg3, double arg4);
    void method9(unsigned arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    void method10(double arg0, double arg1, bool arg2, unsigned arg3, bool arg4);
    void method11(short arg0, unsigned arg1, double arg2, double arg3, double arg4);
    void method12(short arg0, unsigned arg1, short arg2, float arg3, short arg4);
    void method13(float arg0, int arg1, float arg2, unsigned arg3, double arg4);
    void method14(double arg0, bool arg1, bool arg2, float arg3, bool arg4);
}
