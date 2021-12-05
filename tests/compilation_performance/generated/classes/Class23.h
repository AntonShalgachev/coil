#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class23
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(float arg0, bool arg1, int arg2, short arg3, int arg4);
    void method1(unsigned arg0, double arg1, double arg2, short arg3, int arg4);
    short method2(unsigned arg0, short arg1, unsigned arg2, float arg3, unsigned arg4);
    short method3(short arg0, bool arg1, short arg2, float arg3, bool arg4);
    unsigned method4(double arg0, unsigned arg1, short arg2, bool arg3, int arg4);
    double method5(double arg0, double arg1, short arg2, double arg3, short arg4);
    double method6(unsigned arg0, bool arg1, unsigned arg2, short arg3, double arg4);
    void method7(unsigned arg0, float arg1, float arg2, double arg3, float arg4);
    float method8(short arg0, short arg1, short arg2, float arg3, float arg4);
    void method9(int arg0, short arg1, short arg2, bool arg3, short arg4);
    unsigned method10(unsigned arg0, bool arg1, bool arg2, bool arg3, unsigned arg4);
    void method11(short arg0, double arg1, float arg2, short arg3, double arg4);
    void method12(int arg0, short arg1, bool arg2, short arg3, float arg4);
    short method13(int arg0, short arg1, double arg2, unsigned arg3, bool arg4);
    void method14(float arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
};

namespace ns_Class23
{
    int method0(float arg0, bool arg1, int arg2, short arg3, int arg4);
    void method1(unsigned arg0, double arg1, double arg2, short arg3, int arg4);
    short method2(unsigned arg0, short arg1, unsigned arg2, float arg3, unsigned arg4);
    short method3(short arg0, bool arg1, short arg2, float arg3, bool arg4);
    unsigned method4(double arg0, unsigned arg1, short arg2, bool arg3, int arg4);
    double method5(double arg0, double arg1, short arg2, double arg3, short arg4);
    double method6(unsigned arg0, bool arg1, unsigned arg2, short arg3, double arg4);
    void method7(unsigned arg0, float arg1, float arg2, double arg3, float arg4);
    float method8(short arg0, short arg1, short arg2, float arg3, float arg4);
    void method9(int arg0, short arg1, short arg2, bool arg3, short arg4);
    unsigned method10(unsigned arg0, bool arg1, bool arg2, bool arg3, unsigned arg4);
    void method11(short arg0, double arg1, float arg2, short arg3, double arg4);
    void method12(int arg0, short arg1, bool arg2, short arg3, float arg4);
    short method13(int arg0, short arg1, double arg2, unsigned arg3, bool arg4);
    void method14(float arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
}
