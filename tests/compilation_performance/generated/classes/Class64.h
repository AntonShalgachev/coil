#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class64
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, double arg1, unsigned arg2, bool arg3, bool arg4);
    void method1(unsigned arg0, bool arg1, float arg2, bool arg3, unsigned arg4);
    float method2(unsigned arg0, float arg1, float arg2, bool arg3, int arg4);
    void method3(bool arg0, double arg1, unsigned arg2, int arg3, unsigned arg4);
    bool method4(short arg0, double arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method5(unsigned arg0, bool arg1, bool arg2, unsigned arg3, float arg4);
    void method6(float arg0, short arg1, unsigned arg2, short arg3, int arg4);
    void method7(float arg0, bool arg1, float arg2, unsigned arg3, double arg4);
    void method8(unsigned arg0, float arg1, unsigned arg2, double arg3, short arg4);
    float method9(int arg0, float arg1, int arg2, double arg3, int arg4);
    double method10(int arg0, int arg1, int arg2, double arg3, short arg4);
    bool method11(unsigned arg0, bool arg1, bool arg2, double arg3, unsigned arg4);
    void method12(unsigned arg0, bool arg1, unsigned arg2, int arg3, unsigned arg4);
    void method13(int arg0, bool arg1, short arg2, double arg3, float arg4);
    void method14(double arg0, float arg1, unsigned arg2, bool arg3, unsigned arg4);
};

namespace ns_Class64
{
    void method0(short arg0, double arg1, unsigned arg2, bool arg3, bool arg4);
    void method1(unsigned arg0, bool arg1, float arg2, bool arg3, unsigned arg4);
    float method2(unsigned arg0, float arg1, float arg2, bool arg3, int arg4);
    void method3(bool arg0, double arg1, unsigned arg2, int arg3, unsigned arg4);
    bool method4(short arg0, double arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method5(unsigned arg0, bool arg1, bool arg2, unsigned arg3, float arg4);
    void method6(float arg0, short arg1, unsigned arg2, short arg3, int arg4);
    void method7(float arg0, bool arg1, float arg2, unsigned arg3, double arg4);
    void method8(unsigned arg0, float arg1, unsigned arg2, double arg3, short arg4);
    float method9(int arg0, float arg1, int arg2, double arg3, int arg4);
    double method10(int arg0, int arg1, int arg2, double arg3, short arg4);
    bool method11(unsigned arg0, bool arg1, bool arg2, double arg3, unsigned arg4);
    void method12(unsigned arg0, bool arg1, unsigned arg2, int arg3, unsigned arg4);
    void method13(int arg0, bool arg1, short arg2, double arg3, float arg4);
    void method14(double arg0, float arg1, unsigned arg2, bool arg3, unsigned arg4);
}
