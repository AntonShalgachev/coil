#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class22
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(unsigned arg0, bool arg1, short arg2, double arg3, unsigned arg4);
    float method1(int arg0, float arg1, short arg2, bool arg3, short arg4);
    void method2(float arg0, float arg1, int arg2, float arg3, float arg4);
    void method3(float arg0, unsigned arg1, short arg2, float arg3, unsigned arg4);
    void method4(double arg0, float arg1, bool arg2, short arg3, bool arg4);
    unsigned method5(short arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    void method6(float arg0, int arg1, double arg2, bool arg3, float arg4);
    float method7(float arg0, double arg1, float arg2, unsigned arg3, short arg4);
    unsigned method8(unsigned arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    unsigned method9(int arg0, bool arg1, bool arg2, bool arg3, unsigned arg4);
    void method10(unsigned arg0, int arg1, int arg2, bool arg3, bool arg4);
    int method11(unsigned arg0, short arg1, bool arg2, int arg3, unsigned arg4);
    void method12(double arg0, double arg1, unsigned arg2, double arg3, short arg4);
    short method13(short arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    float method14(float arg0, int arg1, int arg2, int arg3, float arg4);
};

namespace ns_Class22
{
    double method0(unsigned arg0, bool arg1, short arg2, double arg3, unsigned arg4);
    float method1(int arg0, float arg1, short arg2, bool arg3, short arg4);
    void method2(float arg0, float arg1, int arg2, float arg3, float arg4);
    void method3(float arg0, unsigned arg1, short arg2, float arg3, unsigned arg4);
    void method4(double arg0, float arg1, bool arg2, short arg3, bool arg4);
    unsigned method5(short arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    void method6(float arg0, int arg1, double arg2, bool arg3, float arg4);
    float method7(float arg0, double arg1, float arg2, unsigned arg3, short arg4);
    unsigned method8(unsigned arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    unsigned method9(int arg0, bool arg1, bool arg2, bool arg3, unsigned arg4);
    void method10(unsigned arg0, int arg1, int arg2, bool arg3, bool arg4);
    int method11(unsigned arg0, short arg1, bool arg2, int arg3, unsigned arg4);
    void method12(double arg0, double arg1, unsigned arg2, double arg3, short arg4);
    short method13(short arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    float method14(float arg0, int arg1, int arg2, int arg3, float arg4);
}
