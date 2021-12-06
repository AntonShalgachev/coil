#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class98
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, short arg1, double arg2, double arg3, short arg4);
    void method1(int arg0, unsigned arg1, unsigned arg2, short arg3, unsigned arg4);
    void method2(short arg0, float arg1, double arg2, double arg3, float arg4);
    double method3(double arg0, bool arg1, double arg2, double arg3, int arg4);
    void method4(int arg0, double arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    unsigned method5(bool arg0, int arg1, int arg2, unsigned arg3, short arg4);
    double method6(double arg0, unsigned arg1, short arg2, short arg3, int arg4);
    short method7(short arg0, int arg1, unsigned arg2, float arg3, unsigned arg4);
    void method8(double arg0, int arg1, short arg2, short arg3, float arg4);
    void method9(short arg0, float arg1, int arg2, int arg3, bool arg4);
    unsigned method10(short arg0, float arg1, short arg2, unsigned arg3, bool arg4);
    short method11(unsigned arg0, short arg1, bool arg2, double arg3, float arg4);
    float method12(float arg0, float arg1, unsigned arg2, float arg3, int arg4);
    void method13(double arg0, double arg1, double arg2, short arg3, int arg4);
    int method14(int arg0, short arg1, short arg2, bool arg3, unsigned arg4);
};

namespace ns_Class98
{
    void method0(unsigned arg0, short arg1, double arg2, double arg3, short arg4);
    void method1(int arg0, unsigned arg1, unsigned arg2, short arg3, unsigned arg4);
    void method2(short arg0, float arg1, double arg2, double arg3, float arg4);
    double method3(double arg0, bool arg1, double arg2, double arg3, int arg4);
    void method4(int arg0, double arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    unsigned method5(bool arg0, int arg1, int arg2, unsigned arg3, short arg4);
    double method6(double arg0, unsigned arg1, short arg2, short arg3, int arg4);
    short method7(short arg0, int arg1, unsigned arg2, float arg3, unsigned arg4);
    void method8(double arg0, int arg1, short arg2, short arg3, float arg4);
    void method9(short arg0, float arg1, int arg2, int arg3, bool arg4);
    unsigned method10(short arg0, float arg1, short arg2, unsigned arg3, bool arg4);
    short method11(unsigned arg0, short arg1, bool arg2, double arg3, float arg4);
    float method12(float arg0, float arg1, unsigned arg2, float arg3, int arg4);
    void method13(double arg0, double arg1, double arg2, short arg3, int arg4);
    int method14(int arg0, short arg1, short arg2, bool arg3, unsigned arg4);
}
