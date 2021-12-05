#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class24
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(float arg0, int arg1, bool arg2, unsigned arg3, short arg4);
    int method1(double arg0, int arg1, double arg2, int arg3, int arg4);
    float method2(int arg0, float arg1, bool arg2, float arg3, unsigned arg4);
    short method3(bool arg0, bool arg1, float arg2, short arg3, int arg4);
    void method4(int arg0, int arg1, unsigned arg2, double arg3, bool arg4);
    void method5(bool arg0, bool arg1, float arg2, bool arg3, int arg4);
    void method6(int arg0, double arg1, double arg2, float arg3, short arg4);
    float method7(bool arg0, double arg1, unsigned arg2, float arg3, bool arg4);
    void method8(bool arg0, bool arg1, unsigned arg2, int arg3, float arg4);
    void method9(float arg0, float arg1, short arg2, bool arg3, short arg4);
    void method10(unsigned arg0, double arg1, bool arg2, double arg3, int arg4);
    void method11(unsigned arg0, bool arg1, bool arg2, bool arg3, int arg4);
    double method12(float arg0, unsigned arg1, unsigned arg2, double arg3, double arg4);
    double method13(double arg0, double arg1, unsigned arg2, short arg3, short arg4);
    void method14(bool arg0, float arg1, double arg2, unsigned arg3, double arg4);
};

namespace ns_Class24
{
    short method0(float arg0, int arg1, bool arg2, unsigned arg3, short arg4);
    int method1(double arg0, int arg1, double arg2, int arg3, int arg4);
    float method2(int arg0, float arg1, bool arg2, float arg3, unsigned arg4);
    short method3(bool arg0, bool arg1, float arg2, short arg3, int arg4);
    void method4(int arg0, int arg1, unsigned arg2, double arg3, bool arg4);
    void method5(bool arg0, bool arg1, float arg2, bool arg3, int arg4);
    void method6(int arg0, double arg1, double arg2, float arg3, short arg4);
    float method7(bool arg0, double arg1, unsigned arg2, float arg3, bool arg4);
    void method8(bool arg0, bool arg1, unsigned arg2, int arg3, float arg4);
    void method9(float arg0, float arg1, short arg2, bool arg3, short arg4);
    void method10(unsigned arg0, double arg1, bool arg2, double arg3, int arg4);
    void method11(unsigned arg0, bool arg1, bool arg2, bool arg3, int arg4);
    double method12(float arg0, unsigned arg1, unsigned arg2, double arg3, double arg4);
    double method13(double arg0, double arg1, unsigned arg2, short arg3, short arg4);
    void method14(bool arg0, float arg1, double arg2, unsigned arg3, double arg4);
}
