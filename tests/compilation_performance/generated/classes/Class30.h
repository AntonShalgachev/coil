#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class30
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, bool arg1, bool arg2, float arg3, unsigned arg4);
    unsigned method1(unsigned arg0, bool arg1, short arg2, float arg3, double arg4);
    unsigned method2(float arg0, unsigned arg1, unsigned arg2, unsigned arg3, bool arg4);
    int method3(float arg0, int arg1, int arg2, unsigned arg3, int arg4);
    void method4(short arg0, float arg1, bool arg2, double arg3, int arg4);
    unsigned method5(bool arg0, int arg1, short arg2, unsigned arg3, int arg4);
    void method6(unsigned arg0, unsigned arg1, unsigned arg2, int arg3, float arg4);
    void method7(unsigned arg0, int arg1, bool arg2, float arg3, unsigned arg4);
    void method8(short arg0, int arg1, unsigned arg2, bool arg3, unsigned arg4);
    void method9(float arg0, bool arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method10(unsigned arg0, short arg1, float arg2, int arg3, short arg4);
    float method11(double arg0, bool arg1, bool arg2, float arg3, double arg4);
    int method12(int arg0, bool arg1, float arg2, unsigned arg3, bool arg4);
    void method13(unsigned arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    float method14(unsigned arg0, float arg1, int arg2, int arg3, short arg4);
};

namespace ns_Class30
{
    void method0(int arg0, bool arg1, bool arg2, float arg3, unsigned arg4);
    unsigned method1(unsigned arg0, bool arg1, short arg2, float arg3, double arg4);
    unsigned method2(float arg0, unsigned arg1, unsigned arg2, unsigned arg3, bool arg4);
    int method3(float arg0, int arg1, int arg2, unsigned arg3, int arg4);
    void method4(short arg0, float arg1, bool arg2, double arg3, int arg4);
    unsigned method5(bool arg0, int arg1, short arg2, unsigned arg3, int arg4);
    void method6(unsigned arg0, unsigned arg1, unsigned arg2, int arg3, float arg4);
    void method7(unsigned arg0, int arg1, bool arg2, float arg3, unsigned arg4);
    void method8(short arg0, int arg1, unsigned arg2, bool arg3, unsigned arg4);
    void method9(float arg0, bool arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method10(unsigned arg0, short arg1, float arg2, int arg3, short arg4);
    float method11(double arg0, bool arg1, bool arg2, float arg3, double arg4);
    int method12(int arg0, bool arg1, float arg2, unsigned arg3, bool arg4);
    void method13(unsigned arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    float method14(unsigned arg0, float arg1, int arg2, int arg3, short arg4);
}
