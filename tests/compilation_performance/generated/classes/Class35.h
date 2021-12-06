#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class35
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, short arg1, short arg2, unsigned arg3, short arg4);
    void method1(bool arg0, double arg1, bool arg2, unsigned arg3, short arg4);
    void method2(float arg0, bool arg1, float arg2, float arg3, unsigned arg4);
    short method3(unsigned arg0, unsigned arg1, short arg2, short arg3, int arg4);
    double method4(float arg0, double arg1, bool arg2, short arg3, int arg4);
    short method5(int arg0, short arg1, bool arg2, float arg3, double arg4);
    double method6(int arg0, double arg1, double arg2, double arg3, short arg4);
    void method7(int arg0, short arg1, double arg2, short arg3, short arg4);
    bool method8(short arg0, short arg1, unsigned arg2, bool arg3, int arg4);
    void method9(float arg0, unsigned arg1, unsigned arg2, unsigned arg3, short arg4);
    void method10(unsigned arg0, bool arg1, float arg2, unsigned arg3, short arg4);
    double method11(short arg0, short arg1, float arg2, double arg3, float arg4);
    float method12(unsigned arg0, int arg1, int arg2, int arg3, float arg4);
    void method13(double arg0, double arg1, float arg2, double arg3, unsigned arg4);
    int method14(float arg0, unsigned arg1, int arg2, short arg3, bool arg4);
};

namespace ns_Class35
{
    void method0(unsigned arg0, short arg1, short arg2, unsigned arg3, short arg4);
    void method1(bool arg0, double arg1, bool arg2, unsigned arg3, short arg4);
    void method2(float arg0, bool arg1, float arg2, float arg3, unsigned arg4);
    short method3(unsigned arg0, unsigned arg1, short arg2, short arg3, int arg4);
    double method4(float arg0, double arg1, bool arg2, short arg3, int arg4);
    short method5(int arg0, short arg1, bool arg2, float arg3, double arg4);
    double method6(int arg0, double arg1, double arg2, double arg3, short arg4);
    void method7(int arg0, short arg1, double arg2, short arg3, short arg4);
    bool method8(short arg0, short arg1, unsigned arg2, bool arg3, int arg4);
    void method9(float arg0, unsigned arg1, unsigned arg2, unsigned arg3, short arg4);
    void method10(unsigned arg0, bool arg1, float arg2, unsigned arg3, short arg4);
    double method11(short arg0, short arg1, float arg2, double arg3, float arg4);
    float method12(unsigned arg0, int arg1, int arg2, int arg3, float arg4);
    void method13(double arg0, double arg1, float arg2, double arg3, unsigned arg4);
    int method14(float arg0, unsigned arg1, int arg2, short arg3, bool arg4);
}
