#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class12
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(int arg0, int arg1, double arg2, bool arg3, int arg4);
    void method1(bool arg0, bool arg1, unsigned arg2, float arg3, int arg4);
    void method2(float arg0, int arg1, unsigned arg2, int arg3, int arg4);
    short method3(float arg0, int arg1, bool arg2, bool arg3, short arg4);
    void method4(int arg0, int arg1, int arg2, bool arg3, unsigned arg4);
    void method5(bool arg0, bool arg1, int arg2, double arg3, int arg4);
    float method6(unsigned arg0, float arg1, float arg2, bool arg3, int arg4);
    void method7(unsigned arg0, double arg1, short arg2, bool arg3, short arg4);
    void method8(double arg0, double arg1, int arg2, double arg3, int arg4);
    void method9(double arg0, int arg1, double arg2, short arg3, int arg4);
    void method10(unsigned arg0, double arg1, bool arg2, float arg3, float arg4);
    short method11(double arg0, float arg1, short arg2, unsigned arg3, bool arg4);
    void method12(int arg0, unsigned arg1, short arg2, float arg3, double arg4);
    void method13(short arg0, double arg1, bool arg2, int arg3, short arg4);
    double method14(unsigned arg0, float arg1, float arg2, double arg3, double arg4);
};

namespace ns_Class12
{
    int method0(int arg0, int arg1, double arg2, bool arg3, int arg4);
    void method1(bool arg0, bool arg1, unsigned arg2, float arg3, int arg4);
    void method2(float arg0, int arg1, unsigned arg2, int arg3, int arg4);
    short method3(float arg0, int arg1, bool arg2, bool arg3, short arg4);
    void method4(int arg0, int arg1, int arg2, bool arg3, unsigned arg4);
    void method5(bool arg0, bool arg1, int arg2, double arg3, int arg4);
    float method6(unsigned arg0, float arg1, float arg2, bool arg3, int arg4);
    void method7(unsigned arg0, double arg1, short arg2, bool arg3, short arg4);
    void method8(double arg0, double arg1, int arg2, double arg3, int arg4);
    void method9(double arg0, int arg1, double arg2, short arg3, int arg4);
    void method10(unsigned arg0, double arg1, bool arg2, float arg3, float arg4);
    short method11(double arg0, float arg1, short arg2, unsigned arg3, bool arg4);
    void method12(int arg0, unsigned arg1, short arg2, float arg3, double arg4);
    void method13(short arg0, double arg1, bool arg2, int arg3, short arg4);
    double method14(unsigned arg0, float arg1, float arg2, double arg3, double arg4);
}
