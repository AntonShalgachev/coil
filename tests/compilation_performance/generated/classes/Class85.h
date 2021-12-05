#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class85
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(float arg0, float arg1, int arg2, unsigned arg3, unsigned arg4);
    void method1(unsigned arg0, float arg1, unsigned arg2, float arg3, float arg4);
    void method2(short arg0, bool arg1, unsigned arg2, bool arg3, unsigned arg4);
    void method3(short arg0, double arg1, short arg2, short arg3, int arg4);
    void method4(double arg0, int arg1, short arg2, short arg3, int arg4);
    unsigned method5(int arg0, short arg1, double arg2, unsigned arg3, short arg4);
    void method6(double arg0, bool arg1, short arg2, unsigned arg3, short arg4);
    void method7(unsigned arg0, short arg1, int arg2, unsigned arg3, float arg4);
    unsigned method8(bool arg0, int arg1, unsigned arg2, int arg3, bool arg4);
    unsigned method9(float arg0, double arg1, short arg2, unsigned arg3, double arg4);
    float method10(float arg0, short arg1, float arg2, short arg3, bool arg4);
    void method11(float arg0, double arg1, float arg2, int arg3, unsigned arg4);
    short method12(bool arg0, bool arg1, bool arg2, short arg3, short arg4);
    unsigned method13(bool arg0, double arg1, unsigned arg2, bool arg3, float arg4);
    void method14(float arg0, short arg1, short arg2, int arg3, bool arg4);
};

namespace ns_Class85
{
    float method0(float arg0, float arg1, int arg2, unsigned arg3, unsigned arg4);
    void method1(unsigned arg0, float arg1, unsigned arg2, float arg3, float arg4);
    void method2(short arg0, bool arg1, unsigned arg2, bool arg3, unsigned arg4);
    void method3(short arg0, double arg1, short arg2, short arg3, int arg4);
    void method4(double arg0, int arg1, short arg2, short arg3, int arg4);
    unsigned method5(int arg0, short arg1, double arg2, unsigned arg3, short arg4);
    void method6(double arg0, bool arg1, short arg2, unsigned arg3, short arg4);
    void method7(unsigned arg0, short arg1, int arg2, unsigned arg3, float arg4);
    unsigned method8(bool arg0, int arg1, unsigned arg2, int arg3, bool arg4);
    unsigned method9(float arg0, double arg1, short arg2, unsigned arg3, double arg4);
    float method10(float arg0, short arg1, float arg2, short arg3, bool arg4);
    void method11(float arg0, double arg1, float arg2, int arg3, unsigned arg4);
    short method12(bool arg0, bool arg1, bool arg2, short arg3, short arg4);
    unsigned method13(bool arg0, double arg1, unsigned arg2, bool arg3, float arg4);
    void method14(float arg0, short arg1, short arg2, int arg3, bool arg4);
}
