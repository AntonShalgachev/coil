#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class71
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(float arg0, int arg1, bool arg2, int arg3, int arg4);
    void method1(bool arg0, double arg1, unsigned arg2, float arg3, float arg4);
    bool method2(bool arg0, double arg1, bool arg2, float arg3, bool arg4);
    void method3(unsigned arg0, float arg1, short arg2, double arg3, double arg4);
    unsigned method4(unsigned arg0, double arg1, short arg2, unsigned arg3, float arg4);
    void method5(float arg0, bool arg1, bool arg2, int arg3, double arg4);
    void method6(double arg0, double arg1, bool arg2, float arg3, short arg4);
    float method7(float arg0, short arg1, int arg2, bool arg3, double arg4);
    void method8(bool arg0, bool arg1, bool arg2, float arg3, int arg4);
    void method9(int arg0, float arg1, float arg2, float arg3, int arg4);
    void method10(int arg0, short arg1, float arg2, float arg3, double arg4);
    bool method11(float arg0, bool arg1, float arg2, float arg3, int arg4);
    void method12(unsigned arg0, bool arg1, float arg2, bool arg3, short arg4);
    void method13(unsigned arg0, float arg1, double arg2, short arg3, int arg4);
    void method14(float arg0, bool arg1, float arg2, double arg3, short arg4);
};

namespace ns_Class71
{
    int method0(float arg0, int arg1, bool arg2, int arg3, int arg4);
    void method1(bool arg0, double arg1, unsigned arg2, float arg3, float arg4);
    bool method2(bool arg0, double arg1, bool arg2, float arg3, bool arg4);
    void method3(unsigned arg0, float arg1, short arg2, double arg3, double arg4);
    unsigned method4(unsigned arg0, double arg1, short arg2, unsigned arg3, float arg4);
    void method5(float arg0, bool arg1, bool arg2, int arg3, double arg4);
    void method6(double arg0, double arg1, bool arg2, float arg3, short arg4);
    float method7(float arg0, short arg1, int arg2, bool arg3, double arg4);
    void method8(bool arg0, bool arg1, bool arg2, float arg3, int arg4);
    void method9(int arg0, float arg1, float arg2, float arg3, int arg4);
    void method10(int arg0, short arg1, float arg2, float arg3, double arg4);
    bool method11(float arg0, bool arg1, float arg2, float arg3, int arg4);
    void method12(unsigned arg0, bool arg1, float arg2, bool arg3, short arg4);
    void method13(unsigned arg0, float arg1, double arg2, short arg3, int arg4);
    void method14(float arg0, bool arg1, float arg2, double arg3, short arg4);
}
