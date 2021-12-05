#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class44
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, unsigned arg1, int arg2, double arg3, int arg4);
    bool method1(bool arg0, short arg1, short arg2, double arg3, float arg4);
    unsigned method2(float arg0, float arg1, int arg2, unsigned arg3, short arg4);
    float method3(short arg0, bool arg1, bool arg2, float arg3, short arg4);
    float method4(double arg0, int arg1, float arg2, double arg3, double arg4);
    unsigned method5(short arg0, short arg1, short arg2, unsigned arg3, unsigned arg4);
    void method6(double arg0, int arg1, double arg2, int arg3, short arg4);
    void method7(float arg0, double arg1, int arg2, unsigned arg3, double arg4);
    void method8(double arg0, short arg1, float arg2, unsigned arg3, short arg4);
    unsigned method9(float arg0, short arg1, short arg2, double arg3, unsigned arg4);
    void method10(short arg0, unsigned arg1, short arg2, float arg3, float arg4);
    int method11(bool arg0, int arg1, int arg2, short arg3, float arg4);
    void method12(bool arg0, float arg1, short arg2, float arg3, double arg4);
    void method13(int arg0, float arg1, double arg2, unsigned arg3, double arg4);
    void method14(short arg0, bool arg1, unsigned arg2, double arg3, bool arg4);
};

namespace ns_Class44
{
    void method0(unsigned arg0, unsigned arg1, int arg2, double arg3, int arg4);
    bool method1(bool arg0, short arg1, short arg2, double arg3, float arg4);
    unsigned method2(float arg0, float arg1, int arg2, unsigned arg3, short arg4);
    float method3(short arg0, bool arg1, bool arg2, float arg3, short arg4);
    float method4(double arg0, int arg1, float arg2, double arg3, double arg4);
    unsigned method5(short arg0, short arg1, short arg2, unsigned arg3, unsigned arg4);
    void method6(double arg0, int arg1, double arg2, int arg3, short arg4);
    void method7(float arg0, double arg1, int arg2, unsigned arg3, double arg4);
    void method8(double arg0, short arg1, float arg2, unsigned arg3, short arg4);
    unsigned method9(float arg0, short arg1, short arg2, double arg3, unsigned arg4);
    void method10(short arg0, unsigned arg1, short arg2, float arg3, float arg4);
    int method11(bool arg0, int arg1, int arg2, short arg3, float arg4);
    void method12(bool arg0, float arg1, short arg2, float arg3, double arg4);
    void method13(int arg0, float arg1, double arg2, unsigned arg3, double arg4);
    void method14(short arg0, bool arg1, unsigned arg2, double arg3, bool arg4);
}
