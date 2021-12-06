#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class14
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, unsigned arg1, short arg2, short arg3, bool arg4);
    unsigned method1(short arg0, unsigned arg1, double arg2, int arg3, int arg4);
    void method2(bool arg0, bool arg1, int arg2, double arg3, float arg4);
    int method3(float arg0, unsigned arg1, int arg2, bool arg3, unsigned arg4);
    double method4(float arg0, unsigned arg1, int arg2, double arg3, unsigned arg4);
    void method5(double arg0, unsigned arg1, double arg2, double arg3, unsigned arg4);
    float method6(int arg0, int arg1, float arg2, double arg3, short arg4);
    void method7(bool arg0, double arg1, unsigned arg2, int arg3, int arg4);
    double method8(unsigned arg0, double arg1, double arg2, float arg3, unsigned arg4);
    void method9(double arg0, float arg1, bool arg2, double arg3, int arg4);
    double method10(short arg0, bool arg1, unsigned arg2, bool arg3, double arg4);
    void method11(short arg0, int arg1, int arg2, unsigned arg3, int arg4);
    void method12(bool arg0, unsigned arg1, bool arg2, int arg3, short arg4);
    short method13(int arg0, int arg1, int arg2, short arg3, short arg4);
    int method14(int arg0, double arg1, float arg2, bool arg3, bool arg4);
};

namespace ns_Class14
{
    void method0(short arg0, unsigned arg1, short arg2, short arg3, bool arg4);
    unsigned method1(short arg0, unsigned arg1, double arg2, int arg3, int arg4);
    void method2(bool arg0, bool arg1, int arg2, double arg3, float arg4);
    int method3(float arg0, unsigned arg1, int arg2, bool arg3, unsigned arg4);
    double method4(float arg0, unsigned arg1, int arg2, double arg3, unsigned arg4);
    void method5(double arg0, unsigned arg1, double arg2, double arg3, unsigned arg4);
    float method6(int arg0, int arg1, float arg2, double arg3, short arg4);
    void method7(bool arg0, double arg1, unsigned arg2, int arg3, int arg4);
    double method8(unsigned arg0, double arg1, double arg2, float arg3, unsigned arg4);
    void method9(double arg0, float arg1, bool arg2, double arg3, int arg4);
    double method10(short arg0, bool arg1, unsigned arg2, bool arg3, double arg4);
    void method11(short arg0, int arg1, int arg2, unsigned arg3, int arg4);
    void method12(bool arg0, unsigned arg1, bool arg2, int arg3, short arg4);
    short method13(int arg0, int arg1, int arg2, short arg3, short arg4);
    int method14(int arg0, double arg1, float arg2, bool arg3, bool arg4);
}
