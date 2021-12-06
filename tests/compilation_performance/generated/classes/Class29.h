#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class29
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, unsigned arg1, float arg2, int arg3, int arg4);
    int method1(double arg0, float arg1, short arg2, double arg3, int arg4);
    void method2(int arg0, bool arg1, float arg2, int arg3, int arg4);
    short method3(double arg0, double arg1, unsigned arg2, short arg3, float arg4);
    float method4(float arg0, float arg1, float arg2, int arg3, short arg4);
    void method5(bool arg0, short arg1, float arg2, bool arg3, int arg4);
    unsigned method6(bool arg0, short arg1, unsigned arg2, double arg3, short arg4);
    void method7(short arg0, short arg1, float arg2, double arg3, short arg4);
    void method8(unsigned arg0, int arg1, unsigned arg2, bool arg3, unsigned arg4);
    bool method9(unsigned arg0, bool arg1, double arg2, unsigned arg3, double arg4);
    void method10(double arg0, bool arg1, int arg2, short arg3, short arg4);
    void method11(int arg0, short arg1, unsigned arg2, int arg3, float arg4);
    float method12(float arg0, unsigned arg1, float arg2, short arg3, float arg4);
    void method13(double arg0, bool arg1, double arg2, float arg3, double arg4);
    void method14(unsigned arg0, float arg1, short arg2, unsigned arg3, float arg4);
};

namespace ns_Class29
{
    void method0(float arg0, unsigned arg1, float arg2, int arg3, int arg4);
    int method1(double arg0, float arg1, short arg2, double arg3, int arg4);
    void method2(int arg0, bool arg1, float arg2, int arg3, int arg4);
    short method3(double arg0, double arg1, unsigned arg2, short arg3, float arg4);
    float method4(float arg0, float arg1, float arg2, int arg3, short arg4);
    void method5(bool arg0, short arg1, float arg2, bool arg3, int arg4);
    unsigned method6(bool arg0, short arg1, unsigned arg2, double arg3, short arg4);
    void method7(short arg0, short arg1, float arg2, double arg3, short arg4);
    void method8(unsigned arg0, int arg1, unsigned arg2, bool arg3, unsigned arg4);
    bool method9(unsigned arg0, bool arg1, double arg2, unsigned arg3, double arg4);
    void method10(double arg0, bool arg1, int arg2, short arg3, short arg4);
    void method11(int arg0, short arg1, unsigned arg2, int arg3, float arg4);
    float method12(float arg0, unsigned arg1, float arg2, short arg3, float arg4);
    void method13(double arg0, bool arg1, double arg2, float arg3, double arg4);
    void method14(unsigned arg0, float arg1, short arg2, unsigned arg3, float arg4);
}
