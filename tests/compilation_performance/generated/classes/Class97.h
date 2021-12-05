#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class97
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, double arg1, short arg2, float arg3, unsigned arg4);
    void method1(short arg0, short arg1, float arg2, bool arg3, int arg4);
    int method2(int arg0, float arg1, unsigned arg2, double arg3, int arg4);
    short method3(short arg0, unsigned arg1, float arg2, short arg3, short arg4);
    short method4(short arg0, bool arg1, float arg2, double arg3, int arg4);
    float method5(unsigned arg0, int arg1, float arg2, float arg3, unsigned arg4);
    double method6(double arg0, bool arg1, float arg2, int arg3, bool arg4);
    double method7(double arg0, short arg1, double arg2, int arg3, short arg4);
    void method8(bool arg0, int arg1, double arg2, int arg3, int arg4);
    unsigned method9(double arg0, unsigned arg1, short arg2, int arg3, unsigned arg4);
    void method10(short arg0, int arg1, unsigned arg2, double arg3, double arg4);
    int method11(short arg0, int arg1, int arg2, bool arg3, unsigned arg4);
    short method12(float arg0, int arg1, short arg2, bool arg3, int arg4);
    unsigned method13(short arg0, unsigned arg1, short arg2, short arg3, double arg4);
    void method14(bool arg0, unsigned arg1, unsigned arg2, float arg3, int arg4);
};

namespace ns_Class97
{
    void method0(unsigned arg0, double arg1, short arg2, float arg3, unsigned arg4);
    void method1(short arg0, short arg1, float arg2, bool arg3, int arg4);
    int method2(int arg0, float arg1, unsigned arg2, double arg3, int arg4);
    short method3(short arg0, unsigned arg1, float arg2, short arg3, short arg4);
    short method4(short arg0, bool arg1, float arg2, double arg3, int arg4);
    float method5(unsigned arg0, int arg1, float arg2, float arg3, unsigned arg4);
    double method6(double arg0, bool arg1, float arg2, int arg3, bool arg4);
    double method7(double arg0, short arg1, double arg2, int arg3, short arg4);
    void method8(bool arg0, int arg1, double arg2, int arg3, int arg4);
    unsigned method9(double arg0, unsigned arg1, short arg2, int arg3, unsigned arg4);
    void method10(short arg0, int arg1, unsigned arg2, double arg3, double arg4);
    int method11(short arg0, int arg1, int arg2, bool arg3, unsigned arg4);
    short method12(float arg0, int arg1, short arg2, bool arg3, int arg4);
    unsigned method13(short arg0, unsigned arg1, short arg2, short arg3, double arg4);
    void method14(bool arg0, unsigned arg1, unsigned arg2, float arg3, int arg4);
}
