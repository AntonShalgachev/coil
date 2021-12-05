#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class39
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, bool arg1, short arg2, bool arg3, unsigned arg4);
    float method1(float arg0, float arg1, float arg2, float arg3, int arg4);
    short method2(double arg0, float arg1, float arg2, float arg3, short arg4);
    void method3(bool arg0, unsigned arg1, int arg2, short arg3, float arg4);
    bool method4(bool arg0, unsigned arg1, double arg2, unsigned arg3, short arg4);
    void method5(double arg0, int arg1, bool arg2, float arg3, int arg4);
    float method6(int arg0, int arg1, float arg2, unsigned arg3, float arg4);
    void method7(double arg0, bool arg1, bool arg2, double arg3, float arg4);
    short method8(short arg0, short arg1, int arg2, short arg3, double arg4);
    short method9(float arg0, int arg1, short arg2, short arg3, unsigned arg4);
    void method10(float arg0, short arg1, short arg2, float arg3, double arg4);
    float method11(float arg0, float arg1, unsigned arg2, double arg3, short arg4);
    void method12(short arg0, bool arg1, short arg2, double arg3, double arg4);
    double method13(double arg0, float arg1, unsigned arg2, unsigned arg3, double arg4);
    void method14(bool arg0, float arg1, int arg2, int arg3, bool arg4);
};

namespace ns_Class39
{
    void method0(unsigned arg0, bool arg1, short arg2, bool arg3, unsigned arg4);
    float method1(float arg0, float arg1, float arg2, float arg3, int arg4);
    short method2(double arg0, float arg1, float arg2, float arg3, short arg4);
    void method3(bool arg0, unsigned arg1, int arg2, short arg3, float arg4);
    bool method4(bool arg0, unsigned arg1, double arg2, unsigned arg3, short arg4);
    void method5(double arg0, int arg1, bool arg2, float arg3, int arg4);
    float method6(int arg0, int arg1, float arg2, unsigned arg3, float arg4);
    void method7(double arg0, bool arg1, bool arg2, double arg3, float arg4);
    short method8(short arg0, short arg1, int arg2, short arg3, double arg4);
    short method9(float arg0, int arg1, short arg2, short arg3, unsigned arg4);
    void method10(float arg0, short arg1, short arg2, float arg3, double arg4);
    float method11(float arg0, float arg1, unsigned arg2, double arg3, short arg4);
    void method12(short arg0, bool arg1, short arg2, double arg3, double arg4);
    double method13(double arg0, float arg1, unsigned arg2, unsigned arg3, double arg4);
    void method14(bool arg0, float arg1, int arg2, int arg3, bool arg4);
}
