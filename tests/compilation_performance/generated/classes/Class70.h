#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class70
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(unsigned arg0, float arg1, unsigned arg2, float arg3, float arg4);
    short method1(bool arg0, int arg1, short arg2, float arg3, unsigned arg4);
    short method2(bool arg0, int arg1, int arg2, short arg3, bool arg4);
    int method3(bool arg0, unsigned arg1, int arg2, double arg3, short arg4);
    float method4(unsigned arg0, int arg1, float arg2, float arg3, short arg4);
    void method5(short arg0, float arg1, double arg2, unsigned arg3, unsigned arg4);
    unsigned method6(short arg0, unsigned arg1, float arg2, float arg3, int arg4);
    void method7(double arg0, float arg1, int arg2, short arg3, float arg4);
    void method8(double arg0, int arg1, float arg2, float arg3, short arg4);
    void method9(float arg0, double arg1, double arg2, int arg3, float arg4);
    bool method10(double arg0, bool arg1, bool arg2, float arg3, double arg4);
    void method11(double arg0, double arg1, float arg2, double arg3, int arg4);
    void method12(unsigned arg0, int arg1, float arg2, float arg3, bool arg4);
    int method13(int arg0, int arg1, double arg2, short arg3, short arg4);
    float method14(float arg0, unsigned arg1, float arg2, float arg3, int arg4);
};

namespace ns_Class70
{
    float method0(unsigned arg0, float arg1, unsigned arg2, float arg3, float arg4);
    short method1(bool arg0, int arg1, short arg2, float arg3, unsigned arg4);
    short method2(bool arg0, int arg1, int arg2, short arg3, bool arg4);
    int method3(bool arg0, unsigned arg1, int arg2, double arg3, short arg4);
    float method4(unsigned arg0, int arg1, float arg2, float arg3, short arg4);
    void method5(short arg0, float arg1, double arg2, unsigned arg3, unsigned arg4);
    unsigned method6(short arg0, unsigned arg1, float arg2, float arg3, int arg4);
    void method7(double arg0, float arg1, int arg2, short arg3, float arg4);
    void method8(double arg0, int arg1, float arg2, float arg3, short arg4);
    void method9(float arg0, double arg1, double arg2, int arg3, float arg4);
    bool method10(double arg0, bool arg1, bool arg2, float arg3, double arg4);
    void method11(double arg0, double arg1, float arg2, double arg3, int arg4);
    void method12(unsigned arg0, int arg1, float arg2, float arg3, bool arg4);
    int method13(int arg0, int arg1, double arg2, short arg3, short arg4);
    float method14(float arg0, unsigned arg1, float arg2, float arg3, int arg4);
}
