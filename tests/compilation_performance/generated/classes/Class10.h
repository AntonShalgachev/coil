#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class10
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, double arg1, int arg2, bool arg3, bool arg4);
    void method1(unsigned arg0, double arg1, float arg2, bool arg3, unsigned arg4);
    void method2(float arg0, unsigned arg1, int arg2, int arg3, unsigned arg4);
    float method3(int arg0, short arg1, float arg2, float arg3, unsigned arg4);
    void method4(unsigned arg0, double arg1, short arg2, double arg3, int arg4);
    short method5(double arg0, short arg1, short arg2, short arg3, unsigned arg4);
    void method6(float arg0, int arg1, short arg2, double arg3, unsigned arg4);
    void method7(unsigned arg0, float arg1, float arg2, bool arg3, bool arg4);
    void method8(short arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    float method9(unsigned arg0, float arg1, short arg2, float arg3, float arg4);
    float method10(unsigned arg0, bool arg1, int arg2, float arg3, int arg4);
    float method11(unsigned arg0, float arg1, short arg2, unsigned arg3, float arg4);
    void method12(unsigned arg0, float arg1, float arg2, int arg3, unsigned arg4);
    void method13(unsigned arg0, unsigned arg1, int arg2, unsigned arg3, bool arg4);
    void method14(double arg0, bool arg1, double arg2, bool arg3, unsigned arg4);
};

namespace ns_Class10
{
    void method0(float arg0, double arg1, int arg2, bool arg3, bool arg4);
    void method1(unsigned arg0, double arg1, float arg2, bool arg3, unsigned arg4);
    void method2(float arg0, unsigned arg1, int arg2, int arg3, unsigned arg4);
    float method3(int arg0, short arg1, float arg2, float arg3, unsigned arg4);
    void method4(unsigned arg0, double arg1, short arg2, double arg3, int arg4);
    short method5(double arg0, short arg1, short arg2, short arg3, unsigned arg4);
    void method6(float arg0, int arg1, short arg2, double arg3, unsigned arg4);
    void method7(unsigned arg0, float arg1, float arg2, bool arg3, bool arg4);
    void method8(short arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    float method9(unsigned arg0, float arg1, short arg2, float arg3, float arg4);
    float method10(unsigned arg0, bool arg1, int arg2, float arg3, int arg4);
    float method11(unsigned arg0, float arg1, short arg2, unsigned arg3, float arg4);
    void method12(unsigned arg0, float arg1, float arg2, int arg3, unsigned arg4);
    void method13(unsigned arg0, unsigned arg1, int arg2, unsigned arg3, bool arg4);
    void method14(double arg0, bool arg1, double arg2, bool arg3, unsigned arg4);
}
