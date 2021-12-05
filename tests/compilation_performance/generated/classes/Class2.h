#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class2
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, float arg1, bool arg2, short arg3, double arg4);
    void method1(short arg0, double arg1, int arg2, int arg3, short arg4);
    short method2(int arg0, short arg1, unsigned arg2, unsigned arg3, short arg4);
    double method3(double arg0, double arg1, int arg2, double arg3, short arg4);
    void method4(double arg0, double arg1, bool arg2, double arg3, int arg4);
    float method5(float arg0, float arg1, int arg2, float arg3, bool arg4);
    void method6(int arg0, short arg1, bool arg2, int arg3, int arg4);
    void method7(bool arg0, unsigned arg1, unsigned arg2, short arg3, float arg4);
    void method8(int arg0, double arg1, double arg2, double arg3, int arg4);
    void method9(unsigned arg0, bool arg1, bool arg2, short arg3, double arg4);
    void method10(unsigned arg0, unsigned arg1, bool arg2, float arg3, float arg4);
    unsigned method11(int arg0, float arg1, unsigned arg2, int arg3, short arg4);
    unsigned method12(short arg0, double arg1, short arg2, short arg3, unsigned arg4);
    unsigned method13(float arg0, int arg1, short arg2, unsigned arg3, unsigned arg4);
    unsigned method14(unsigned arg0, float arg1, double arg2, short arg3, float arg4);
};

namespace ns_Class2
{
    void method0(double arg0, float arg1, bool arg2, short arg3, double arg4);
    void method1(short arg0, double arg1, int arg2, int arg3, short arg4);
    short method2(int arg0, short arg1, unsigned arg2, unsigned arg3, short arg4);
    double method3(double arg0, double arg1, int arg2, double arg3, short arg4);
    void method4(double arg0, double arg1, bool arg2, double arg3, int arg4);
    float method5(float arg0, float arg1, int arg2, float arg3, bool arg4);
    void method6(int arg0, short arg1, bool arg2, int arg3, int arg4);
    void method7(bool arg0, unsigned arg1, unsigned arg2, short arg3, float arg4);
    void method8(int arg0, double arg1, double arg2, double arg3, int arg4);
    void method9(unsigned arg0, bool arg1, bool arg2, short arg3, double arg4);
    void method10(unsigned arg0, unsigned arg1, bool arg2, float arg3, float arg4);
    unsigned method11(int arg0, float arg1, unsigned arg2, int arg3, short arg4);
    unsigned method12(short arg0, double arg1, short arg2, short arg3, unsigned arg4);
    unsigned method13(float arg0, int arg1, short arg2, unsigned arg3, unsigned arg4);
    unsigned method14(unsigned arg0, float arg1, double arg2, short arg3, float arg4);
}
