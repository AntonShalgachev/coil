#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class96
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, unsigned arg1, int arg2, unsigned arg3, unsigned arg4);
    void method1(double arg0, unsigned arg1, int arg2, unsigned arg3, float arg4);
    float method2(short arg0, float arg1, short arg2, float arg3, bool arg4);
    int method3(float arg0, int arg1, int arg2, int arg3, double arg4);
    double method4(short arg0, double arg1, bool arg2, unsigned arg3, double arg4);
    unsigned method5(bool arg0, float arg1, unsigned arg2, unsigned arg3, int arg4);
    void method6(unsigned arg0, int arg1, double arg2, unsigned arg3, unsigned arg4);
    void method7(short arg0, int arg1, bool arg2, float arg3, short arg4);
    unsigned method8(double arg0, bool arg1, bool arg2, unsigned arg3, bool arg4);
    int method9(int arg0, double arg1, int arg2, int arg3, float arg4);
    void method10(bool arg0, bool arg1, double arg2, int arg3, bool arg4);
    void method11(double arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    double method12(bool arg0, short arg1, int arg2, double arg3, int arg4);
    short method13(double arg0, short arg1, bool arg2, bool arg3, unsigned arg4);
    float method14(float arg0, float arg1, double arg2, unsigned arg3, float arg4);
};

namespace ns_Class96
{
    unsigned method0(unsigned arg0, unsigned arg1, int arg2, unsigned arg3, unsigned arg4);
    void method1(double arg0, unsigned arg1, int arg2, unsigned arg3, float arg4);
    float method2(short arg0, float arg1, short arg2, float arg3, bool arg4);
    int method3(float arg0, int arg1, int arg2, int arg3, double arg4);
    double method4(short arg0, double arg1, bool arg2, unsigned arg3, double arg4);
    unsigned method5(bool arg0, float arg1, unsigned arg2, unsigned arg3, int arg4);
    void method6(unsigned arg0, int arg1, double arg2, unsigned arg3, unsigned arg4);
    void method7(short arg0, int arg1, bool arg2, float arg3, short arg4);
    unsigned method8(double arg0, bool arg1, bool arg2, unsigned arg3, bool arg4);
    int method9(int arg0, double arg1, int arg2, int arg3, float arg4);
    void method10(bool arg0, bool arg1, double arg2, int arg3, bool arg4);
    void method11(double arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    double method12(bool arg0, short arg1, int arg2, double arg3, int arg4);
    short method13(double arg0, short arg1, bool arg2, bool arg3, unsigned arg4);
    float method14(float arg0, float arg1, double arg2, unsigned arg3, float arg4);
}
