#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class45
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, short arg1, short arg2, bool arg3, unsigned arg4);
    unsigned method1(int arg0, unsigned arg1, unsigned arg2, int arg3, double arg4);
    short method2(double arg0, double arg1, unsigned arg2, short arg3, float arg4);
    void method3(float arg0, float arg1, float arg2, float arg3, double arg4);
    void method4(unsigned arg0, short arg1, short arg2, short arg3, float arg4);
    void method5(float arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
    double method6(unsigned arg0, double arg1, double arg2, short arg3, int arg4);
    short method7(int arg0, int arg1, int arg2, short arg3, short arg4);
    void method8(short arg0, float arg1, short arg2, int arg3, unsigned arg4);
    short method9(float arg0, short arg1, short arg2, unsigned arg3, unsigned arg4);
    float method10(double arg0, float arg1, short arg2, float arg3, float arg4);
    short method11(double arg0, bool arg1, double arg2, bool arg3, short arg4);
    int method12(unsigned arg0, float arg1, int arg2, unsigned arg3, unsigned arg4);
    double method13(double arg0, int arg1, double arg2, double arg3, bool arg4);
    void method14(bool arg0, int arg1, int arg2, float arg3, unsigned arg4);
};

namespace ns_Class45
{
    void method0(float arg0, short arg1, short arg2, bool arg3, unsigned arg4);
    unsigned method1(int arg0, unsigned arg1, unsigned arg2, int arg3, double arg4);
    short method2(double arg0, double arg1, unsigned arg2, short arg3, float arg4);
    void method3(float arg0, float arg1, float arg2, float arg3, double arg4);
    void method4(unsigned arg0, short arg1, short arg2, short arg3, float arg4);
    void method5(float arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
    double method6(unsigned arg0, double arg1, double arg2, short arg3, int arg4);
    short method7(int arg0, int arg1, int arg2, short arg3, short arg4);
    void method8(short arg0, float arg1, short arg2, int arg3, unsigned arg4);
    short method9(float arg0, short arg1, short arg2, unsigned arg3, unsigned arg4);
    float method10(double arg0, float arg1, short arg2, float arg3, float arg4);
    short method11(double arg0, bool arg1, double arg2, bool arg3, short arg4);
    int method12(unsigned arg0, float arg1, int arg2, unsigned arg3, unsigned arg4);
    double method13(double arg0, int arg1, double arg2, double arg3, bool arg4);
    void method14(bool arg0, int arg1, int arg2, float arg3, unsigned arg4);
}
