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
    void method0(short arg0, bool arg1, float arg2, float arg3, int arg4);
    unsigned method1(double arg0, unsigned arg1, int arg2, double arg3, int arg4);
    double method2(double arg0, unsigned arg1, bool arg2, double arg3, short arg4);
    float method3(unsigned arg0, unsigned arg1, unsigned arg2, float arg3, int arg4);
    bool method4(int arg0, bool arg1, int arg2, bool arg3, unsigned arg4);
    double method5(double arg0, bool arg1, unsigned arg2, short arg3, double arg4);
    int method6(float arg0, short arg1, float arg2, int arg3, float arg4);
    void method7(float arg0, double arg1, short arg2, unsigned arg3, float arg4);
    bool method8(unsigned arg0, bool arg1, unsigned arg2, int arg3, int arg4);
    void method9(bool arg0, double arg1, float arg2, unsigned arg3, unsigned arg4);
    double method10(double arg0, double arg1, float arg2, float arg3, short arg4);
    float method11(unsigned arg0, float arg1, float arg2, int arg3, unsigned arg4);
    int method12(int arg0, double arg1, float arg2, int arg3, float arg4);
    unsigned method13(unsigned arg0, bool arg1, bool arg2, short arg3, float arg4);
    float method14(unsigned arg0, float arg1, short arg2, bool arg3, int arg4);
};

namespace ns_Class20
{
    void method0(short arg0, bool arg1, float arg2, float arg3, int arg4);
    unsigned method1(double arg0, unsigned arg1, int arg2, double arg3, int arg4);
    double method2(double arg0, unsigned arg1, bool arg2, double arg3, short arg4);
    float method3(unsigned arg0, unsigned arg1, unsigned arg2, float arg3, int arg4);
    bool method4(int arg0, bool arg1, int arg2, bool arg3, unsigned arg4);
    double method5(double arg0, bool arg1, unsigned arg2, short arg3, double arg4);
    int method6(float arg0, short arg1, float arg2, int arg3, float arg4);
    void method7(float arg0, double arg1, short arg2, unsigned arg3, float arg4);
    bool method8(unsigned arg0, bool arg1, unsigned arg2, int arg3, int arg4);
    void method9(bool arg0, double arg1, float arg2, unsigned arg3, unsigned arg4);
    double method10(double arg0, double arg1, float arg2, float arg3, short arg4);
    float method11(unsigned arg0, float arg1, float arg2, int arg3, unsigned arg4);
    int method12(int arg0, double arg1, float arg2, int arg3, float arg4);
    unsigned method13(unsigned arg0, bool arg1, bool arg2, short arg3, float arg4);
    float method14(unsigned arg0, float arg1, short arg2, bool arg3, int arg4);
}
