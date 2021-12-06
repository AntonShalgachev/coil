#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class2
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(bool arg0, float arg1, float arg2, int arg3, short arg4);
    void method1(short arg0, short arg1, int arg2, short arg3, int arg4);
    bool method2(unsigned arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    bool method3(unsigned arg0, bool arg1, float arg2, bool arg3, int arg4);
    void method4(double arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    short method5(short arg0, short arg1, short arg2, float arg3, unsigned arg4);
    void method6(bool arg0, short arg1, double arg2, float arg3, unsigned arg4);
    float method7(double arg0, float arg1, double arg2, short arg3, double arg4);
    void method8(float arg0, float arg1, int arg2, float arg3, float arg4);
    float method9(double arg0, float arg1, unsigned arg2, float arg3, short arg4);
    float method10(unsigned arg0, float arg1, double arg2, short arg3, float arg4);
    void method11(bool arg0, unsigned arg1, int arg2, double arg3, short arg4);
    void method12(bool arg0, short arg1, short arg2, int arg3, short arg4);
    void method13(unsigned arg0, float arg1, double arg2, short arg3, unsigned arg4);
    double method14(bool arg0, short arg1, float arg2, double arg3, short arg4);
};

namespace ns_Class2
{
    void method0(bool arg0, float arg1, float arg2, int arg3, short arg4);
    void method1(short arg0, short arg1, int arg2, short arg3, int arg4);
    bool method2(unsigned arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    bool method3(unsigned arg0, bool arg1, float arg2, bool arg3, int arg4);
    void method4(double arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    short method5(short arg0, short arg1, short arg2, float arg3, unsigned arg4);
    void method6(bool arg0, short arg1, double arg2, float arg3, unsigned arg4);
    float method7(double arg0, float arg1, double arg2, short arg3, double arg4);
    void method8(float arg0, float arg1, int arg2, float arg3, float arg4);
    float method9(double arg0, float arg1, unsigned arg2, float arg3, short arg4);
    float method10(unsigned arg0, float arg1, double arg2, short arg3, float arg4);
    void method11(bool arg0, unsigned arg1, int arg2, double arg3, short arg4);
    void method12(bool arg0, short arg1, short arg2, int arg3, short arg4);
    void method13(unsigned arg0, float arg1, double arg2, short arg3, unsigned arg4);
    double method14(bool arg0, short arg1, float arg2, double arg3, short arg4);
}
