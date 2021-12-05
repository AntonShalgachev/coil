#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class46
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(unsigned arg0, bool arg1, unsigned arg2, bool arg3, bool arg4);
    void method1(bool arg0, float arg1, int arg2, short arg3, bool arg4);
    double method2(double arg0, double arg1, double arg2, int arg3, double arg4);
    void method3(double arg0, short arg1, bool arg2, unsigned arg3, float arg4);
    void method4(float arg0, float arg1, float arg2, unsigned arg3, float arg4);
    short method5(short arg0, bool arg1, short arg2, int arg3, bool arg4);
    void method6(double arg0, short arg1, short arg2, int arg3, int arg4);
    void method7(float arg0, unsigned arg1, short arg2, short arg3, bool arg4);
    void method8(short arg0, bool arg1, int arg2, double arg3, short arg4);
    bool method9(bool arg0, bool arg1, short arg2, double arg3, short arg4);
    void method10(int arg0, double arg1, double arg2, float arg3, double arg4);
    void method11(int arg0, float arg1, float arg2, short arg3, bool arg4);
    double method12(bool arg0, bool arg1, int arg2, double arg3, float arg4);
    void method13(double arg0, float arg1, double arg2, short arg3, bool arg4);
    float method14(double arg0, float arg1, float arg2, unsigned arg3, bool arg4);
};

namespace ns_Class46
{
    bool method0(unsigned arg0, bool arg1, unsigned arg2, bool arg3, bool arg4);
    void method1(bool arg0, float arg1, int arg2, short arg3, bool arg4);
    double method2(double arg0, double arg1, double arg2, int arg3, double arg4);
    void method3(double arg0, short arg1, bool arg2, unsigned arg3, float arg4);
    void method4(float arg0, float arg1, float arg2, unsigned arg3, float arg4);
    short method5(short arg0, bool arg1, short arg2, int arg3, bool arg4);
    void method6(double arg0, short arg1, short arg2, int arg3, int arg4);
    void method7(float arg0, unsigned arg1, short arg2, short arg3, bool arg4);
    void method8(short arg0, bool arg1, int arg2, double arg3, short arg4);
    bool method9(bool arg0, bool arg1, short arg2, double arg3, short arg4);
    void method10(int arg0, double arg1, double arg2, float arg3, double arg4);
    void method11(int arg0, float arg1, float arg2, short arg3, bool arg4);
    double method12(bool arg0, bool arg1, int arg2, double arg3, float arg4);
    void method13(double arg0, float arg1, double arg2, short arg3, bool arg4);
    float method14(double arg0, float arg1, float arg2, unsigned arg3, bool arg4);
}
