#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class19
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, bool arg1, short arg2, int arg3, unsigned arg4);
    void method1(float arg0, double arg1, short arg2, unsigned arg3, short arg4);
    int method2(int arg0, float arg1, double arg2, unsigned arg3, int arg4);
    void method3(double arg0, float arg1, double arg2, short arg3, short arg4);
    void method4(short arg0, unsigned arg1, short arg2, int arg3, float arg4);
    void method5(float arg0, float arg1, int arg2, float arg3, bool arg4);
    bool method6(bool arg0, float arg1, bool arg2, float arg3, short arg4);
    void method7(double arg0, float arg1, int arg2, unsigned arg3, short arg4);
    int method8(float arg0, int arg1, short arg2, short arg3, double arg4);
    void method9(bool arg0, double arg1, short arg2, double arg3, int arg4);
    float method10(double arg0, int arg1, unsigned arg2, bool arg3, float arg4);
    void method11(double arg0, float arg1, bool arg2, double arg3, int arg4);
    bool method12(short arg0, unsigned arg1, bool arg2, bool arg3, bool arg4);
    void method13(bool arg0, int arg1, short arg2, float arg3, double arg4);
    int method14(bool arg0, bool arg1, int arg2, bool arg3, int arg4);
};

namespace ns_Class19
{
    void method0(float arg0, bool arg1, short arg2, int arg3, unsigned arg4);
    void method1(float arg0, double arg1, short arg2, unsigned arg3, short arg4);
    int method2(int arg0, float arg1, double arg2, unsigned arg3, int arg4);
    void method3(double arg0, float arg1, double arg2, short arg3, short arg4);
    void method4(short arg0, unsigned arg1, short arg2, int arg3, float arg4);
    void method5(float arg0, float arg1, int arg2, float arg3, bool arg4);
    bool method6(bool arg0, float arg1, bool arg2, float arg3, short arg4);
    void method7(double arg0, float arg1, int arg2, unsigned arg3, short arg4);
    int method8(float arg0, int arg1, short arg2, short arg3, double arg4);
    void method9(bool arg0, double arg1, short arg2, double arg3, int arg4);
    float method10(double arg0, int arg1, unsigned arg2, bool arg3, float arg4);
    void method11(double arg0, float arg1, bool arg2, double arg3, int arg4);
    bool method12(short arg0, unsigned arg1, bool arg2, bool arg3, bool arg4);
    void method13(bool arg0, int arg1, short arg2, float arg3, double arg4);
    int method14(bool arg0, bool arg1, int arg2, bool arg3, int arg4);
}
