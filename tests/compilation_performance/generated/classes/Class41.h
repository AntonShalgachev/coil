#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class41
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(double arg0, unsigned arg1, int arg2, short arg3, bool arg4);
    void method1(int arg0, int arg1, double arg2, bool arg3, bool arg4);
    unsigned method2(unsigned arg0, unsigned arg1, double arg2, int arg3, short arg4);
    bool method3(bool arg0, float arg1, double arg2, float arg3, int arg4);
    void method4(bool arg0, unsigned arg1, int arg2, int arg3, int arg4);
    void method5(int arg0, int arg1, short arg2, short arg3, double arg4);
    int method6(float arg0, short arg1, unsigned arg2, int arg3, int arg4);
    void method7(float arg0, int arg1, unsigned arg2, short arg3, double arg4);
    void method8(unsigned arg0, bool arg1, int arg2, float arg3, bool arg4);
    float method9(int arg0, float arg1, int arg2, float arg3, float arg4);
    float method10(unsigned arg0, bool arg1, float arg2, unsigned arg3, short arg4);
    bool method11(bool arg0, bool arg1, bool arg2, float arg3, float arg4);
    void method12(bool arg0, unsigned arg1, double arg2, short arg3, int arg4);
    void method13(bool arg0, int arg1, bool arg2, float arg3, float arg4);
    float method14(int arg0, double arg1, short arg2, float arg3, double arg4);
};

namespace ns_Class41
{
    bool method0(double arg0, unsigned arg1, int arg2, short arg3, bool arg4);
    void method1(int arg0, int arg1, double arg2, bool arg3, bool arg4);
    unsigned method2(unsigned arg0, unsigned arg1, double arg2, int arg3, short arg4);
    bool method3(bool arg0, float arg1, double arg2, float arg3, int arg4);
    void method4(bool arg0, unsigned arg1, int arg2, int arg3, int arg4);
    void method5(int arg0, int arg1, short arg2, short arg3, double arg4);
    int method6(float arg0, short arg1, unsigned arg2, int arg3, int arg4);
    void method7(float arg0, int arg1, unsigned arg2, short arg3, double arg4);
    void method8(unsigned arg0, bool arg1, int arg2, float arg3, bool arg4);
    float method9(int arg0, float arg1, int arg2, float arg3, float arg4);
    float method10(unsigned arg0, bool arg1, float arg2, unsigned arg3, short arg4);
    bool method11(bool arg0, bool arg1, bool arg2, float arg3, float arg4);
    void method12(bool arg0, unsigned arg1, double arg2, short arg3, int arg4);
    void method13(bool arg0, int arg1, bool arg2, float arg3, float arg4);
    float method14(int arg0, double arg1, short arg2, float arg3, double arg4);
}
