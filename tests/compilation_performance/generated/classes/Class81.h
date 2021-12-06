#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class81
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(float arg0, bool arg1, double arg2, unsigned arg3, short arg4);
    void method1(double arg0, float arg1, short arg2, bool arg3, unsigned arg4);
    int method2(int arg0, bool arg1, bool arg2, short arg3, double arg4);
    void method3(unsigned arg0, short arg1, short arg2, float arg3, bool arg4);
    unsigned method4(bool arg0, float arg1, int arg2, bool arg3, unsigned arg4);
    double method5(int arg0, double arg1, double arg2, unsigned arg3, bool arg4);
    void method6(double arg0, short arg1, unsigned arg2, unsigned arg3, float arg4);
    int method7(int arg0, bool arg1, int arg2, int arg3, unsigned arg4);
    void method8(bool arg0, int arg1, double arg2, bool arg3, float arg4);
    void method9(bool arg0, double arg1, short arg2, short arg3, float arg4);
    unsigned method10(unsigned arg0, short arg1, unsigned arg2, short arg3, double arg4);
    void method11(double arg0, short arg1, double arg2, unsigned arg3, double arg4);
    short method12(unsigned arg0, float arg1, int arg2, short arg3, bool arg4);
    double method13(double arg0, float arg1, double arg2, double arg3, int arg4);
    void method14(double arg0, unsigned arg1, short arg2, double arg3, double arg4);
};

namespace ns_Class81
{
    unsigned method0(float arg0, bool arg1, double arg2, unsigned arg3, short arg4);
    void method1(double arg0, float arg1, short arg2, bool arg3, unsigned arg4);
    int method2(int arg0, bool arg1, bool arg2, short arg3, double arg4);
    void method3(unsigned arg0, short arg1, short arg2, float arg3, bool arg4);
    unsigned method4(bool arg0, float arg1, int arg2, bool arg3, unsigned arg4);
    double method5(int arg0, double arg1, double arg2, unsigned arg3, bool arg4);
    void method6(double arg0, short arg1, unsigned arg2, unsigned arg3, float arg4);
    int method7(int arg0, bool arg1, int arg2, int arg3, unsigned arg4);
    void method8(bool arg0, int arg1, double arg2, bool arg3, float arg4);
    void method9(bool arg0, double arg1, short arg2, short arg3, float arg4);
    unsigned method10(unsigned arg0, short arg1, unsigned arg2, short arg3, double arg4);
    void method11(double arg0, short arg1, double arg2, unsigned arg3, double arg4);
    short method12(unsigned arg0, float arg1, int arg2, short arg3, bool arg4);
    double method13(double arg0, float arg1, double arg2, double arg3, int arg4);
    void method14(double arg0, unsigned arg1, short arg2, double arg3, double arg4);
}
