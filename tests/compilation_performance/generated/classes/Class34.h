#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class34
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(int arg0, bool arg1, bool arg2, double arg3, unsigned arg4);
    void method1(unsigned arg0, double arg1, float arg2, bool arg3, double arg4);
    float method2(bool arg0, bool arg1, float arg2, short arg3, float arg4);
    void method3(bool arg0, double arg1, int arg2, unsigned arg3, bool arg4);
    int method4(unsigned arg0, int arg1, bool arg2, int arg3, bool arg4);
    float method5(double arg0, int arg1, float arg2, float arg3, float arg4);
    void method6(float arg0, unsigned arg1, short arg2, float arg3, float arg4);
    void method7(unsigned arg0, int arg1, double arg2, unsigned arg3, double arg4);
    float method8(short arg0, float arg1, float arg2, bool arg3, unsigned arg4);
    float method9(unsigned arg0, short arg1, float arg2, int arg3, float arg4);
    short method10(unsigned arg0, unsigned arg1, unsigned arg2, short arg3, float arg4);
    void method11(float arg0, short arg1, short arg2, unsigned arg3, float arg4);
    void method12(unsigned arg0, bool arg1, double arg2, double arg3, double arg4);
    double method13(double arg0, double arg1, int arg2, double arg3, bool arg4);
    unsigned method14(float arg0, unsigned arg1, unsigned arg2, float arg3, bool arg4);
};

namespace ns_Class34
{
    bool method0(int arg0, bool arg1, bool arg2, double arg3, unsigned arg4);
    void method1(unsigned arg0, double arg1, float arg2, bool arg3, double arg4);
    float method2(bool arg0, bool arg1, float arg2, short arg3, float arg4);
    void method3(bool arg0, double arg1, int arg2, unsigned arg3, bool arg4);
    int method4(unsigned arg0, int arg1, bool arg2, int arg3, bool arg4);
    float method5(double arg0, int arg1, float arg2, float arg3, float arg4);
    void method6(float arg0, unsigned arg1, short arg2, float arg3, float arg4);
    void method7(unsigned arg0, int arg1, double arg2, unsigned arg3, double arg4);
    float method8(short arg0, float arg1, float arg2, bool arg3, unsigned arg4);
    float method9(unsigned arg0, short arg1, float arg2, int arg3, float arg4);
    short method10(unsigned arg0, unsigned arg1, unsigned arg2, short arg3, float arg4);
    void method11(float arg0, short arg1, short arg2, unsigned arg3, float arg4);
    void method12(unsigned arg0, bool arg1, double arg2, double arg3, double arg4);
    double method13(double arg0, double arg1, int arg2, double arg3, bool arg4);
    unsigned method14(float arg0, unsigned arg1, unsigned arg2, float arg3, bool arg4);
}
