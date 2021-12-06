#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class39
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(int arg0, int arg1, int arg2, bool arg3, int arg4);
    float method1(double arg0, float arg1, int arg2, short arg3, int arg4);
    void method2(double arg0, float arg1, short arg2, int arg3, bool arg4);
    void method3(unsigned arg0, double arg1, unsigned arg2, float arg3, unsigned arg4);
    void method4(int arg0, float arg1, unsigned arg2, double arg3, float arg4);
    unsigned method5(int arg0, int arg1, float arg2, unsigned arg3, unsigned arg4);
    void method6(unsigned arg0, float arg1, unsigned arg2, float arg3, unsigned arg4);
    void method7(short arg0, float arg1, float arg2, short arg3, double arg4);
    void method8(double arg0, double arg1, bool arg2, unsigned arg3, bool arg4);
    void method9(bool arg0, int arg1, bool arg2, bool arg3, unsigned arg4);
    void method10(unsigned arg0, float arg1, int arg2, unsigned arg3, double arg4);
    unsigned method11(bool arg0, unsigned arg1, float arg2, unsigned arg3, double arg4);
    void method12(short arg0, unsigned arg1, unsigned arg2, float arg3, int arg4);
    void method13(double arg0, int arg1, double arg2, bool arg3, bool arg4);
    int method14(unsigned arg0, short arg1, short arg2, int arg3, short arg4);
};

namespace ns_Class39
{
    int method0(int arg0, int arg1, int arg2, bool arg3, int arg4);
    float method1(double arg0, float arg1, int arg2, short arg3, int arg4);
    void method2(double arg0, float arg1, short arg2, int arg3, bool arg4);
    void method3(unsigned arg0, double arg1, unsigned arg2, float arg3, unsigned arg4);
    void method4(int arg0, float arg1, unsigned arg2, double arg3, float arg4);
    unsigned method5(int arg0, int arg1, float arg2, unsigned arg3, unsigned arg4);
    void method6(unsigned arg0, float arg1, unsigned arg2, float arg3, unsigned arg4);
    void method7(short arg0, float arg1, float arg2, short arg3, double arg4);
    void method8(double arg0, double arg1, bool arg2, unsigned arg3, bool arg4);
    void method9(bool arg0, int arg1, bool arg2, bool arg3, unsigned arg4);
    void method10(unsigned arg0, float arg1, int arg2, unsigned arg3, double arg4);
    unsigned method11(bool arg0, unsigned arg1, float arg2, unsigned arg3, double arg4);
    void method12(short arg0, unsigned arg1, unsigned arg2, float arg3, int arg4);
    void method13(double arg0, int arg1, double arg2, bool arg3, bool arg4);
    int method14(unsigned arg0, short arg1, short arg2, int arg3, short arg4);
}
