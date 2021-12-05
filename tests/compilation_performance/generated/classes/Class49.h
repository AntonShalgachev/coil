#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class49
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(bool arg0, float arg1, bool arg2, bool arg3, unsigned arg4);
    float method1(bool arg0, float arg1, bool arg2, bool arg3, unsigned arg4);
    void method2(bool arg0, unsigned arg1, int arg2, float arg3, double arg4);
    void method3(double arg0, int arg1, unsigned arg2, bool arg3, int arg4);
    void method4(float arg0, double arg1, bool arg2, unsigned arg3, short arg4);
    float method5(double arg0, int arg1, float arg2, float arg3, float arg4);
    float method6(float arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    void method7(unsigned arg0, int arg1, short arg2, float arg3, short arg4);
    void method8(float arg0, float arg1, double arg2, bool arg3, double arg4);
    void method9(int arg0, int arg1, float arg2, unsigned arg3, unsigned arg4);
    void method10(float arg0, short arg1, unsigned arg2, int arg3, int arg4);
    bool method11(short arg0, bool arg1, unsigned arg2, float arg3, bool arg4);
    void method12(double arg0, int arg1, double arg2, float arg3, float arg4);
    int method13(int arg0, float arg1, int arg2, double arg3, short arg4);
    void method14(unsigned arg0, float arg1, unsigned arg2, float arg3, double arg4);
};

namespace ns_Class49
{
    bool method0(bool arg0, float arg1, bool arg2, bool arg3, unsigned arg4);
    float method1(bool arg0, float arg1, bool arg2, bool arg3, unsigned arg4);
    void method2(bool arg0, unsigned arg1, int arg2, float arg3, double arg4);
    void method3(double arg0, int arg1, unsigned arg2, bool arg3, int arg4);
    void method4(float arg0, double arg1, bool arg2, unsigned arg3, short arg4);
    float method5(double arg0, int arg1, float arg2, float arg3, float arg4);
    float method6(float arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    void method7(unsigned arg0, int arg1, short arg2, float arg3, short arg4);
    void method8(float arg0, float arg1, double arg2, bool arg3, double arg4);
    void method9(int arg0, int arg1, float arg2, unsigned arg3, unsigned arg4);
    void method10(float arg0, short arg1, unsigned arg2, int arg3, int arg4);
    bool method11(short arg0, bool arg1, unsigned arg2, float arg3, bool arg4);
    void method12(double arg0, int arg1, double arg2, float arg3, float arg4);
    int method13(int arg0, float arg1, int arg2, double arg3, short arg4);
    void method14(unsigned arg0, float arg1, unsigned arg2, float arg3, double arg4);
}
