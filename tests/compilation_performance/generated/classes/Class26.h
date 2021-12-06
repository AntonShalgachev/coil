#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class26
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(double arg0, unsigned arg1, double arg2, unsigned arg3, unsigned arg4);
    void method1(double arg0, short arg1, double arg2, bool arg3, bool arg4);
    float method2(short arg0, int arg1, bool arg2, bool arg3, float arg4);
    short method3(unsigned arg0, int arg1, int arg2, unsigned arg3, short arg4);
    void method4(bool arg0, bool arg1, double arg2, unsigned arg3, short arg4);
    void method5(unsigned arg0, unsigned arg1, float arg2, unsigned arg3, double arg4);
    void method6(double arg0, unsigned arg1, double arg2, double arg3, int arg4);
    void method7(short arg0, bool arg1, unsigned arg2, bool arg3, double arg4);
    void method8(short arg0, unsigned arg1, short arg2, unsigned arg3, bool arg4);
    short method9(int arg0, short arg1, bool arg2, double arg3, bool arg4);
    short method10(double arg0, float arg1, short arg2, int arg3, bool arg4);
    int method11(short arg0, short arg1, int arg2, short arg3, int arg4);
    void method12(double arg0, int arg1, double arg2, float arg3, short arg4);
    void method13(unsigned arg0, int arg1, float arg2, double arg3, short arg4);
    void method14(double arg0, bool arg1, double arg2, float arg3, unsigned arg4);
};

namespace ns_Class26
{
    double method0(double arg0, unsigned arg1, double arg2, unsigned arg3, unsigned arg4);
    void method1(double arg0, short arg1, double arg2, bool arg3, bool arg4);
    float method2(short arg0, int arg1, bool arg2, bool arg3, float arg4);
    short method3(unsigned arg0, int arg1, int arg2, unsigned arg3, short arg4);
    void method4(bool arg0, bool arg1, double arg2, unsigned arg3, short arg4);
    void method5(unsigned arg0, unsigned arg1, float arg2, unsigned arg3, double arg4);
    void method6(double arg0, unsigned arg1, double arg2, double arg3, int arg4);
    void method7(short arg0, bool arg1, unsigned arg2, bool arg3, double arg4);
    void method8(short arg0, unsigned arg1, short arg2, unsigned arg3, bool arg4);
    short method9(int arg0, short arg1, bool arg2, double arg3, bool arg4);
    short method10(double arg0, float arg1, short arg2, int arg3, bool arg4);
    int method11(short arg0, short arg1, int arg2, short arg3, int arg4);
    void method12(double arg0, int arg1, double arg2, float arg3, short arg4);
    void method13(unsigned arg0, int arg1, float arg2, double arg3, short arg4);
    void method14(double arg0, bool arg1, double arg2, float arg3, unsigned arg4);
}
