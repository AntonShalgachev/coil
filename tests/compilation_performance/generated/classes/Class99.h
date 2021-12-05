#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class99
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, bool arg1, float arg2, bool arg3, int arg4);
    void method1(float arg0, double arg1, double arg2, int arg3, bool arg4);
    short method2(short arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    unsigned method3(float arg0, unsigned arg1, unsigned arg2, double arg3, short arg4);
    void method4(unsigned arg0, bool arg1, unsigned arg2, int arg3, float arg4);
    float method5(float arg0, short arg1, float arg2, float arg3, short arg4);
    short method6(double arg0, int arg1, short arg2, short arg3, unsigned arg4);
    void method7(int arg0, float arg1, unsigned arg2, short arg3, int arg4);
    float method8(double arg0, float arg1, double arg2, float arg3, bool arg4);
    void method9(double arg0, short arg1, double arg2, bool arg3, int arg4);
    double method10(short arg0, float arg1, double arg2, bool arg3, bool arg4);
    short method11(short arg0, bool arg1, short arg2, unsigned arg3, unsigned arg4);
    double method12(double arg0, int arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method13(short arg0, short arg1, float arg2, double arg3, unsigned arg4);
    void method14(short arg0, int arg1, short arg2, unsigned arg3, unsigned arg4);
};

namespace ns_Class99
{
    void method0(short arg0, bool arg1, float arg2, bool arg3, int arg4);
    void method1(float arg0, double arg1, double arg2, int arg3, bool arg4);
    short method2(short arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    unsigned method3(float arg0, unsigned arg1, unsigned arg2, double arg3, short arg4);
    void method4(unsigned arg0, bool arg1, unsigned arg2, int arg3, float arg4);
    float method5(float arg0, short arg1, float arg2, float arg3, short arg4);
    short method6(double arg0, int arg1, short arg2, short arg3, unsigned arg4);
    void method7(int arg0, float arg1, unsigned arg2, short arg3, int arg4);
    float method8(double arg0, float arg1, double arg2, float arg3, bool arg4);
    void method9(double arg0, short arg1, double arg2, bool arg3, int arg4);
    double method10(short arg0, float arg1, double arg2, bool arg3, bool arg4);
    short method11(short arg0, bool arg1, short arg2, unsigned arg3, unsigned arg4);
    double method12(double arg0, int arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method13(short arg0, short arg1, float arg2, double arg3, unsigned arg4);
    void method14(short arg0, int arg1, short arg2, unsigned arg3, unsigned arg4);
}
