#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class76
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(int arg0, unsigned arg1, int arg2, bool arg3, short arg4);
    int method1(float arg0, unsigned arg1, bool arg2, int arg3, int arg4);
    float method2(bool arg0, unsigned arg1, int arg2, float arg3, unsigned arg4);
    int method3(bool arg0, double arg1, int arg2, int arg3, bool arg4);
    void method4(short arg0, short arg1, int arg2, double arg3, unsigned arg4);
    double method5(double arg0, int arg1, int arg2, bool arg3, bool arg4);
    void method6(double arg0, unsigned arg1, int arg2, double arg3, short arg4);
    int method7(bool arg0, short arg1, double arg2, bool arg3, int arg4);
    void method8(short arg0, unsigned arg1, short arg2, bool arg3, short arg4);
    unsigned method9(float arg0, unsigned arg1, unsigned arg2, unsigned arg3, double arg4);
    void method10(float arg0, short arg1, unsigned arg2, float arg3, int arg4);
    float method11(double arg0, float arg1, float arg2, bool arg3, float arg4);
    unsigned method12(unsigned arg0, bool arg1, double arg2, short arg3, unsigned arg4);
    int method13(unsigned arg0, bool arg1, unsigned arg2, float arg3, int arg4);
    void method14(float arg0, unsigned arg1, short arg2, short arg3, bool arg4);
};

namespace ns_Class76
{
    unsigned method0(int arg0, unsigned arg1, int arg2, bool arg3, short arg4);
    int method1(float arg0, unsigned arg1, bool arg2, int arg3, int arg4);
    float method2(bool arg0, unsigned arg1, int arg2, float arg3, unsigned arg4);
    int method3(bool arg0, double arg1, int arg2, int arg3, bool arg4);
    void method4(short arg0, short arg1, int arg2, double arg3, unsigned arg4);
    double method5(double arg0, int arg1, int arg2, bool arg3, bool arg4);
    void method6(double arg0, unsigned arg1, int arg2, double arg3, short arg4);
    int method7(bool arg0, short arg1, double arg2, bool arg3, int arg4);
    void method8(short arg0, unsigned arg1, short arg2, bool arg3, short arg4);
    unsigned method9(float arg0, unsigned arg1, unsigned arg2, unsigned arg3, double arg4);
    void method10(float arg0, short arg1, unsigned arg2, float arg3, int arg4);
    float method11(double arg0, float arg1, float arg2, bool arg3, float arg4);
    unsigned method12(unsigned arg0, bool arg1, double arg2, short arg3, unsigned arg4);
    int method13(unsigned arg0, bool arg1, unsigned arg2, float arg3, int arg4);
    void method14(float arg0, unsigned arg1, short arg2, short arg3, bool arg4);
}
