#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class36
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(bool arg0, bool arg1, float arg2, float arg3, unsigned arg4);
    float method1(double arg0, bool arg1, bool arg2, int arg3, float arg4);
    void method2(int arg0, float arg1, int arg2, float arg3, bool arg4);
    void method3(double arg0, bool arg1, bool arg2, float arg3, unsigned arg4);
    void method4(unsigned arg0, double arg1, unsigned arg2, unsigned arg3, int arg4);
    float method5(int arg0, int arg1, short arg2, float arg3, float arg4);
    void method6(float arg0, bool arg1, short arg2, bool arg3, double arg4);
    double method7(short arg0, unsigned arg1, unsigned arg2, double arg3, unsigned arg4);
    double method8(short arg0, double arg1, int arg2, bool arg3, double arg4);
    void method9(float arg0, double arg1, short arg2, unsigned arg3, unsigned arg4);
    void method10(int arg0, float arg1, double arg2, unsigned arg3, unsigned arg4);
    double method11(float arg0, double arg1, bool arg2, unsigned arg3, double arg4);
    unsigned method12(bool arg0, double arg1, int arg2, unsigned arg3, short arg4);
    void method13(short arg0, double arg1, bool arg2, double arg3, unsigned arg4);
    int method14(double arg0, unsigned arg1, double arg2, short arg3, int arg4);
};

namespace ns_Class36
{
    bool method0(bool arg0, bool arg1, float arg2, float arg3, unsigned arg4);
    float method1(double arg0, bool arg1, bool arg2, int arg3, float arg4);
    void method2(int arg0, float arg1, int arg2, float arg3, bool arg4);
    void method3(double arg0, bool arg1, bool arg2, float arg3, unsigned arg4);
    void method4(unsigned arg0, double arg1, unsigned arg2, unsigned arg3, int arg4);
    float method5(int arg0, int arg1, short arg2, float arg3, float arg4);
    void method6(float arg0, bool arg1, short arg2, bool arg3, double arg4);
    double method7(short arg0, unsigned arg1, unsigned arg2, double arg3, unsigned arg4);
    double method8(short arg0, double arg1, int arg2, bool arg3, double arg4);
    void method9(float arg0, double arg1, short arg2, unsigned arg3, unsigned arg4);
    void method10(int arg0, float arg1, double arg2, unsigned arg3, unsigned arg4);
    double method11(float arg0, double arg1, bool arg2, unsigned arg3, double arg4);
    unsigned method12(bool arg0, double arg1, int arg2, unsigned arg3, short arg4);
    void method13(short arg0, double arg1, bool arg2, double arg3, unsigned arg4);
    int method14(double arg0, unsigned arg1, double arg2, short arg3, int arg4);
}
