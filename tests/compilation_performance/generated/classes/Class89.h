#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class89
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, float arg1, bool arg2, bool arg3, double arg4);
    void method1(bool arg0, double arg1, bool arg2, float arg3, int arg4);
    void method2(bool arg0, bool arg1, unsigned arg2, int arg3, short arg4);
    void method3(float arg0, double arg1, unsigned arg2, unsigned arg3, bool arg4);
    float method4(int arg0, float arg1, unsigned arg2, int arg3, bool arg4);
    void method5(bool arg0, int arg1, float arg2, bool arg3, short arg4);
    void method6(bool arg0, float arg1, short arg2, int arg3, bool arg4);
    bool method7(unsigned arg0, float arg1, int arg2, unsigned arg3, bool arg4);
    void method8(int arg0, bool arg1, unsigned arg2, bool arg3, int arg4);
    double method9(double arg0, unsigned arg1, double arg2, double arg3, short arg4);
    short method10(float arg0, float arg1, bool arg2, short arg3, bool arg4);
    void method11(float arg0, bool arg1, double arg2, int arg3, double arg4);
    double method12(double arg0, double arg1, bool arg2, bool arg3, float arg4);
    short method13(short arg0, double arg1, short arg2, float arg3, bool arg4);
    void method14(int arg0, double arg1, bool arg2, double arg3, int arg4);
};

namespace ns_Class89
{
    void method0(short arg0, float arg1, bool arg2, bool arg3, double arg4);
    void method1(bool arg0, double arg1, bool arg2, float arg3, int arg4);
    void method2(bool arg0, bool arg1, unsigned arg2, int arg3, short arg4);
    void method3(float arg0, double arg1, unsigned arg2, unsigned arg3, bool arg4);
    float method4(int arg0, float arg1, unsigned arg2, int arg3, bool arg4);
    void method5(bool arg0, int arg1, float arg2, bool arg3, short arg4);
    void method6(bool arg0, float arg1, short arg2, int arg3, bool arg4);
    bool method7(unsigned arg0, float arg1, int arg2, unsigned arg3, bool arg4);
    void method8(int arg0, bool arg1, unsigned arg2, bool arg3, int arg4);
    double method9(double arg0, unsigned arg1, double arg2, double arg3, short arg4);
    short method10(float arg0, float arg1, bool arg2, short arg3, bool arg4);
    void method11(float arg0, bool arg1, double arg2, int arg3, double arg4);
    double method12(double arg0, double arg1, bool arg2, bool arg3, float arg4);
    short method13(short arg0, double arg1, short arg2, float arg3, bool arg4);
    void method14(int arg0, double arg1, bool arg2, double arg3, int arg4);
}
