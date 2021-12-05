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
    unsigned method0(double arg0, unsigned arg1, float arg2, int arg3, int arg4);
    void method1(bool arg0, bool arg1, bool arg2, bool arg3, short arg4);
    void method2(bool arg0, double arg1, float arg2, short arg3, short arg4);
    void method3(int arg0, bool arg1, unsigned arg2, float arg3, float arg4);
    void method4(bool arg0, float arg1, int arg2, short arg3, double arg4);
    int method5(int arg0, double arg1, bool arg2, int arg3, int arg4);
    float method6(int arg0, float arg1, float arg2, double arg3, float arg4);
    short method7(unsigned arg0, short arg1, int arg2, double arg3, double arg4);
    short method8(short arg0, unsigned arg1, unsigned arg2, bool arg3, unsigned arg4);
    short method9(double arg0, bool arg1, unsigned arg2, short arg3, int arg4);
    void method10(unsigned arg0, unsigned arg1, short arg2, double arg3, float arg4);
    float method11(unsigned arg0, float arg1, unsigned arg2, int arg3, float arg4);
    void method12(int arg0, double arg1, double arg2, short arg3, bool arg4);
    int method13(float arg0, int arg1, int arg2, double arg3, double arg4);
    short method14(float arg0, short arg1, short arg2, double arg3, float arg4);
};

namespace ns_Class26
{
    unsigned method0(double arg0, unsigned arg1, float arg2, int arg3, int arg4);
    void method1(bool arg0, bool arg1, bool arg2, bool arg3, short arg4);
    void method2(bool arg0, double arg1, float arg2, short arg3, short arg4);
    void method3(int arg0, bool arg1, unsigned arg2, float arg3, float arg4);
    void method4(bool arg0, float arg1, int arg2, short arg3, double arg4);
    int method5(int arg0, double arg1, bool arg2, int arg3, int arg4);
    float method6(int arg0, float arg1, float arg2, double arg3, float arg4);
    short method7(unsigned arg0, short arg1, int arg2, double arg3, double arg4);
    short method8(short arg0, unsigned arg1, unsigned arg2, bool arg3, unsigned arg4);
    short method9(double arg0, bool arg1, unsigned arg2, short arg3, int arg4);
    void method10(unsigned arg0, unsigned arg1, short arg2, double arg3, float arg4);
    float method11(unsigned arg0, float arg1, unsigned arg2, int arg3, float arg4);
    void method12(int arg0, double arg1, double arg2, short arg3, bool arg4);
    int method13(float arg0, int arg1, int arg2, double arg3, double arg4);
    short method14(float arg0, short arg1, short arg2, double arg3, float arg4);
}
