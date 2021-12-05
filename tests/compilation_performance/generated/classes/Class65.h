#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class65
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(bool arg0, short arg1, float arg2, double arg3, short arg4);
    void method1(double arg0, unsigned arg1, double arg2, int arg3, unsigned arg4);
    short method2(float arg0, double arg1, short arg2, float arg3, float arg4);
    void method3(bool arg0, double arg1, float arg2, short arg3, short arg4);
    unsigned method4(short arg0, unsigned arg1, bool arg2, double arg3, short arg4);
    int method5(unsigned arg0, int arg1, double arg2, int arg3, unsigned arg4);
    void method6(float arg0, float arg1, short arg2, bool arg3, bool arg4);
    void method7(int arg0, int arg1, bool arg2, double arg3, short arg4);
    void method8(unsigned arg0, unsigned arg1, short arg2, float arg3, bool arg4);
    float method9(bool arg0, double arg1, unsigned arg2, unsigned arg3, float arg4);
    float method10(int arg0, float arg1, float arg2, short arg3, double arg4);
    void method11(unsigned arg0, int arg1, bool arg2, int arg3, unsigned arg4);
    short method12(int arg0, bool arg1, short arg2, short arg3, int arg4);
    double method13(float arg0, bool arg1, double arg2, double arg3, double arg4);
    float method14(int arg0, short arg1, double arg2, int arg3, float arg4);
};

namespace ns_Class65
{
    void method0(bool arg0, short arg1, float arg2, double arg3, short arg4);
    void method1(double arg0, unsigned arg1, double arg2, int arg3, unsigned arg4);
    short method2(float arg0, double arg1, short arg2, float arg3, float arg4);
    void method3(bool arg0, double arg1, float arg2, short arg3, short arg4);
    unsigned method4(short arg0, unsigned arg1, bool arg2, double arg3, short arg4);
    int method5(unsigned arg0, int arg1, double arg2, int arg3, unsigned arg4);
    void method6(float arg0, float arg1, short arg2, bool arg3, bool arg4);
    void method7(int arg0, int arg1, bool arg2, double arg3, short arg4);
    void method8(unsigned arg0, unsigned arg1, short arg2, float arg3, bool arg4);
    float method9(bool arg0, double arg1, unsigned arg2, unsigned arg3, float arg4);
    float method10(int arg0, float arg1, float arg2, short arg3, double arg4);
    void method11(unsigned arg0, int arg1, bool arg2, int arg3, unsigned arg4);
    short method12(int arg0, bool arg1, short arg2, short arg3, int arg4);
    double method13(float arg0, bool arg1, double arg2, double arg3, double arg4);
    float method14(int arg0, short arg1, double arg2, int arg3, float arg4);
}
