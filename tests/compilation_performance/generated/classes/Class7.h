#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class7
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, short arg1, bool arg2, bool arg3, float arg4);
    void method1(double arg0, float arg1, bool arg2, int arg3, short arg4);
    void method2(double arg0, int arg1, bool arg2, unsigned arg3, int arg4);
    void method3(double arg0, double arg1, unsigned arg2, double arg3, float arg4);
    short method4(int arg0, short arg1, unsigned arg2, float arg3, double arg4);
    void method5(float arg0, int arg1, short arg2, float arg3, double arg4);
    void method6(float arg0, unsigned arg1, unsigned arg2, short arg3, short arg4);
    float method7(double arg0, double arg1, float arg2, float arg3, int arg4);
    double method8(int arg0, double arg1, short arg2, double arg3, unsigned arg4);
    unsigned method9(double arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    unsigned method10(int arg0, unsigned arg1, unsigned arg2, bool arg3, int arg4);
    void method11(short arg0, double arg1, float arg2, int arg3, bool arg4);
    void method12(int arg0, double arg1, int arg2, bool arg3, unsigned arg4);
    void method13(float arg0, bool arg1, unsigned arg2, double arg3, short arg4);
    short method14(short arg0, bool arg1, int arg2, short arg3, int arg4);
};

namespace ns_Class7
{
    void method0(float arg0, short arg1, bool arg2, bool arg3, float arg4);
    void method1(double arg0, float arg1, bool arg2, int arg3, short arg4);
    void method2(double arg0, int arg1, bool arg2, unsigned arg3, int arg4);
    void method3(double arg0, double arg1, unsigned arg2, double arg3, float arg4);
    short method4(int arg0, short arg1, unsigned arg2, float arg3, double arg4);
    void method5(float arg0, int arg1, short arg2, float arg3, double arg4);
    void method6(float arg0, unsigned arg1, unsigned arg2, short arg3, short arg4);
    float method7(double arg0, double arg1, float arg2, float arg3, int arg4);
    double method8(int arg0, double arg1, short arg2, double arg3, unsigned arg4);
    unsigned method9(double arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    unsigned method10(int arg0, unsigned arg1, unsigned arg2, bool arg3, int arg4);
    void method11(short arg0, double arg1, float arg2, int arg3, bool arg4);
    void method12(int arg0, double arg1, int arg2, bool arg3, unsigned arg4);
    void method13(float arg0, bool arg1, unsigned arg2, double arg3, short arg4);
    short method14(short arg0, bool arg1, int arg2, short arg3, int arg4);
}
