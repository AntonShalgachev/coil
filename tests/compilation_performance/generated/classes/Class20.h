#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class20
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, double arg1, unsigned arg2, float arg3, unsigned arg4);
    short method1(double arg0, double arg1, short arg2, unsigned arg3, int arg4);
    int method2(unsigned arg0, bool arg1, int arg2, double arg3, int arg4);
    void method3(short arg0, double arg1, short arg2, short arg3, float arg4);
    unsigned method4(short arg0, int arg1, int arg2, unsigned arg3, float arg4);
    int method5(float arg0, int arg1, int arg2, unsigned arg3, double arg4);
    bool method6(bool arg0, unsigned arg1, bool arg2, bool arg3, float arg4);
    double method7(unsigned arg0, unsigned arg1, int arg2, double arg3, double arg4);
    double method8(double arg0, bool arg1, double arg2, unsigned arg3, short arg4);
    void method9(float arg0, unsigned arg1, bool arg2, int arg3, int arg4);
    void method10(bool arg0, int arg1, int arg2, double arg3, unsigned arg4);
    unsigned method11(short arg0, unsigned arg1, double arg2, double arg3, double arg4);
    void method12(double arg0, unsigned arg1, unsigned arg2, double arg3, short arg4);
    void method13(short arg0, double arg1, unsigned arg2, unsigned arg3, int arg4);
    void method14(int arg0, int arg1, float arg2, short arg3, unsigned arg4);
};

namespace ns_Class20
{
    unsigned method0(unsigned arg0, double arg1, unsigned arg2, float arg3, unsigned arg4);
    short method1(double arg0, double arg1, short arg2, unsigned arg3, int arg4);
    int method2(unsigned arg0, bool arg1, int arg2, double arg3, int arg4);
    void method3(short arg0, double arg1, short arg2, short arg3, float arg4);
    unsigned method4(short arg0, int arg1, int arg2, unsigned arg3, float arg4);
    int method5(float arg0, int arg1, int arg2, unsigned arg3, double arg4);
    bool method6(bool arg0, unsigned arg1, bool arg2, bool arg3, float arg4);
    double method7(unsigned arg0, unsigned arg1, int arg2, double arg3, double arg4);
    double method8(double arg0, bool arg1, double arg2, unsigned arg3, short arg4);
    void method9(float arg0, unsigned arg1, bool arg2, int arg3, int arg4);
    void method10(bool arg0, int arg1, int arg2, double arg3, unsigned arg4);
    unsigned method11(short arg0, unsigned arg1, double arg2, double arg3, double arg4);
    void method12(double arg0, unsigned arg1, unsigned arg2, double arg3, short arg4);
    void method13(short arg0, double arg1, unsigned arg2, unsigned arg3, int arg4);
    void method14(int arg0, int arg1, float arg2, short arg3, unsigned arg4);
}
