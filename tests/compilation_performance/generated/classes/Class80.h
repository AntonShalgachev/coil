#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class80
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, float arg1, bool arg2, double arg3, double arg4);
    double method1(short arg0, bool arg1, short arg2, double arg3, bool arg4);
    void method2(int arg0, unsigned arg1, int arg2, int arg3, bool arg4);
    void method3(bool arg0, unsigned arg1, float arg2, float arg3, float arg4);
    void method4(unsigned arg0, short arg1, bool arg2, float arg3, double arg4);
    unsigned method5(double arg0, unsigned arg1, int arg2, unsigned arg3, short arg4);
    unsigned method6(unsigned arg0, unsigned arg1, float arg2, bool arg3, int arg4);
    unsigned method7(unsigned arg0, int arg1, bool arg2, short arg3, int arg4);
    void method8(bool arg0, float arg1, bool arg2, int arg3, float arg4);
    void method9(double arg0, float arg1, double arg2, bool arg3, int arg4);
    int method10(short arg0, unsigned arg1, short arg2, int arg3, int arg4);
    void method11(int arg0, int arg1, bool arg2, unsigned arg3, unsigned arg4);
    int method12(float arg0, int arg1, double arg2, short arg3, double arg4);
    double method13(double arg0, bool arg1, double arg2, bool arg3, short arg4);
    void method14(int arg0, short arg1, bool arg2, bool arg3, float arg4);
};

namespace ns_Class80
{
    void method0(unsigned arg0, float arg1, bool arg2, double arg3, double arg4);
    double method1(short arg0, bool arg1, short arg2, double arg3, bool arg4);
    void method2(int arg0, unsigned arg1, int arg2, int arg3, bool arg4);
    void method3(bool arg0, unsigned arg1, float arg2, float arg3, float arg4);
    void method4(unsigned arg0, short arg1, bool arg2, float arg3, double arg4);
    unsigned method5(double arg0, unsigned arg1, int arg2, unsigned arg3, short arg4);
    unsigned method6(unsigned arg0, unsigned arg1, float arg2, bool arg3, int arg4);
    unsigned method7(unsigned arg0, int arg1, bool arg2, short arg3, int arg4);
    void method8(bool arg0, float arg1, bool arg2, int arg3, float arg4);
    void method9(double arg0, float arg1, double arg2, bool arg3, int arg4);
    int method10(short arg0, unsigned arg1, short arg2, int arg3, int arg4);
    void method11(int arg0, int arg1, bool arg2, unsigned arg3, unsigned arg4);
    int method12(float arg0, int arg1, double arg2, short arg3, double arg4);
    double method13(double arg0, bool arg1, double arg2, bool arg3, short arg4);
    void method14(int arg0, short arg1, bool arg2, bool arg3, float arg4);
}
