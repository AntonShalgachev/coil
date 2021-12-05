#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class15
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, short arg1, float arg2, float arg3, unsigned arg4);
    void method1(float arg0, bool arg1, bool arg2, double arg3, int arg4);
    double method2(float arg0, int arg1, int arg2, double arg3, short arg4);
    void method3(unsigned arg0, bool arg1, double arg2, bool arg3, short arg4);
    void method4(int arg0, unsigned arg1, double arg2, float arg3, short arg4);
    int method5(unsigned arg0, int arg1, int arg2, int arg3, bool arg4);
    void method6(bool arg0, float arg1, double arg2, double arg3, int arg4);
    float method7(short arg0, short arg1, int arg2, float arg3, short arg4);
    float method8(bool arg0, float arg1, int arg2, bool arg3, float arg4);
    void method9(float arg0, unsigned arg1, short arg2, int arg3, float arg4);
    bool method10(short arg0, bool arg1, double arg2, unsigned arg3, short arg4);
    void method11(short arg0, bool arg1, float arg2, unsigned arg3, unsigned arg4);
    double method12(short arg0, unsigned arg1, float arg2, bool arg3, double arg4);
    void method13(double arg0, int arg1, bool arg2, bool arg3, short arg4);
    void method14(float arg0, float arg1, double arg2, short arg3, double arg4);
};

namespace ns_Class15
{
    void method0(unsigned arg0, short arg1, float arg2, float arg3, unsigned arg4);
    void method1(float arg0, bool arg1, bool arg2, double arg3, int arg4);
    double method2(float arg0, int arg1, int arg2, double arg3, short arg4);
    void method3(unsigned arg0, bool arg1, double arg2, bool arg3, short arg4);
    void method4(int arg0, unsigned arg1, double arg2, float arg3, short arg4);
    int method5(unsigned arg0, int arg1, int arg2, int arg3, bool arg4);
    void method6(bool arg0, float arg1, double arg2, double arg3, int arg4);
    float method7(short arg0, short arg1, int arg2, float arg3, short arg4);
    float method8(bool arg0, float arg1, int arg2, bool arg3, float arg4);
    void method9(float arg0, unsigned arg1, short arg2, int arg3, float arg4);
    bool method10(short arg0, bool arg1, double arg2, unsigned arg3, short arg4);
    void method11(short arg0, bool arg1, float arg2, unsigned arg3, unsigned arg4);
    double method12(short arg0, unsigned arg1, float arg2, bool arg3, double arg4);
    void method13(double arg0, int arg1, bool arg2, bool arg3, short arg4);
    void method14(float arg0, float arg1, double arg2, short arg3, double arg4);
}
