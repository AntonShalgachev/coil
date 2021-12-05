#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class77
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(bool arg0, int arg1, unsigned arg2, bool arg3, int arg4);
    short method1(double arg0, short arg1, double arg2, bool arg3, float arg4);
    double method2(bool arg0, float arg1, double arg2, float arg3, double arg4);
    bool method3(bool arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method4(float arg0, float arg1, float arg2, int arg3, short arg4);
    void method5(unsigned arg0, unsigned arg1, float arg2, float arg3, int arg4);
    void method6(double arg0, int arg1, double arg2, unsigned arg3, bool arg4);
    int method7(int arg0, int arg1, unsigned arg2, double arg3, bool arg4);
    float method8(short arg0, double arg1, float arg2, double arg3, bool arg4);
    void method9(double arg0, int arg1, int arg2, float arg3, unsigned arg4);
    void method10(bool arg0, float arg1, bool arg2, double arg3, double arg4);
    void method11(short arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    float method12(float arg0, int arg1, bool arg2, float arg3, unsigned arg4);
    void method13(unsigned arg0, short arg1, double arg2, int arg3, short arg4);
    void method14(bool arg0, double arg1, unsigned arg2, int arg3, bool arg4);
};

namespace ns_Class77
{
    void method0(bool arg0, int arg1, unsigned arg2, bool arg3, int arg4);
    short method1(double arg0, short arg1, double arg2, bool arg3, float arg4);
    double method2(bool arg0, float arg1, double arg2, float arg3, double arg4);
    bool method3(bool arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method4(float arg0, float arg1, float arg2, int arg3, short arg4);
    void method5(unsigned arg0, unsigned arg1, float arg2, float arg3, int arg4);
    void method6(double arg0, int arg1, double arg2, unsigned arg3, bool arg4);
    int method7(int arg0, int arg1, unsigned arg2, double arg3, bool arg4);
    float method8(short arg0, double arg1, float arg2, double arg3, bool arg4);
    void method9(double arg0, int arg1, int arg2, float arg3, unsigned arg4);
    void method10(bool arg0, float arg1, bool arg2, double arg3, double arg4);
    void method11(short arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    float method12(float arg0, int arg1, bool arg2, float arg3, unsigned arg4);
    void method13(unsigned arg0, short arg1, double arg2, int arg3, short arg4);
    void method14(bool arg0, double arg1, unsigned arg2, int arg3, bool arg4);
}
