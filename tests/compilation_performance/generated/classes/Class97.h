#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class97
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(float arg0, float arg1, short arg2, bool arg3, short arg4);
    short method1(float arg0, short arg1, int arg2, float arg3, unsigned arg4);
    float method2(bool arg0, int arg1, float arg2, float arg3, int arg4);
    void method3(short arg0, int arg1, double arg2, double arg3, short arg4);
    float method4(short arg0, double arg1, short arg2, float arg3, bool arg4);
    double method5(bool arg0, double arg1, unsigned arg2, unsigned arg3, double arg4);
    void method6(float arg0, int arg1, int arg2, short arg3, float arg4);
    void method7(int arg0, unsigned arg1, bool arg2, float arg3, bool arg4);
    void method8(double arg0, bool arg1, int arg2, bool arg3, unsigned arg4);
    void method9(float arg0, double arg1, double arg2, double arg3, int arg4);
    void method10(float arg0, int arg1, double arg2, short arg3, short arg4);
    bool method11(float arg0, short arg1, bool arg2, double arg3, unsigned arg4);
    short method12(short arg0, bool arg1, bool arg2, int arg3, short arg4);
    bool method13(bool arg0, bool arg1, int arg2, int arg3, bool arg4);
    float method14(int arg0, bool arg1, double arg2, float arg3, bool arg4);
};

namespace ns_Class97
{
    short method0(float arg0, float arg1, short arg2, bool arg3, short arg4);
    short method1(float arg0, short arg1, int arg2, float arg3, unsigned arg4);
    float method2(bool arg0, int arg1, float arg2, float arg3, int arg4);
    void method3(short arg0, int arg1, double arg2, double arg3, short arg4);
    float method4(short arg0, double arg1, short arg2, float arg3, bool arg4);
    double method5(bool arg0, double arg1, unsigned arg2, unsigned arg3, double arg4);
    void method6(float arg0, int arg1, int arg2, short arg3, float arg4);
    void method7(int arg0, unsigned arg1, bool arg2, float arg3, bool arg4);
    void method8(double arg0, bool arg1, int arg2, bool arg3, unsigned arg4);
    void method9(float arg0, double arg1, double arg2, double arg3, int arg4);
    void method10(float arg0, int arg1, double arg2, short arg3, short arg4);
    bool method11(float arg0, short arg1, bool arg2, double arg3, unsigned arg4);
    short method12(short arg0, bool arg1, bool arg2, int arg3, short arg4);
    bool method13(bool arg0, bool arg1, int arg2, int arg3, bool arg4);
    float method14(int arg0, bool arg1, double arg2, float arg3, bool arg4);
}
