#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class18
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(double arg0, short arg1, int arg2, int arg3, int arg4);
    double method1(bool arg0, double arg1, unsigned arg2, float arg3, bool arg4);
    unsigned method2(unsigned arg0, short arg1, short arg2, bool arg3, double arg4);
    float method3(float arg0, short arg1, float arg2, double arg3, float arg4);
    double method4(double arg0, unsigned arg1, double arg2, bool arg3, float arg4);
    void method5(double arg0, bool arg1, float arg2, int arg3, float arg4);
    void method6(float arg0, short arg1, float arg2, double arg3, int arg4);
    unsigned method7(int arg0, bool arg1, unsigned arg2, float arg3, unsigned arg4);
    double method8(double arg0, double arg1, bool arg2, short arg3, int arg4);
    bool method9(double arg0, float arg1, short arg2, bool arg3, unsigned arg4);
    void method10(float arg0, bool arg1, double arg2, bool arg3, bool arg4);
    unsigned method11(short arg0, double arg1, unsigned arg2, double arg3, unsigned arg4);
    bool method12(bool arg0, double arg1, double arg2, bool arg3, int arg4);
    float method13(bool arg0, float arg1, float arg2, int arg3, unsigned arg4);
    void method14(int arg0, double arg1, bool arg2, float arg3, float arg4);
};

namespace ns_Class18
{
    int method0(double arg0, short arg1, int arg2, int arg3, int arg4);
    double method1(bool arg0, double arg1, unsigned arg2, float arg3, bool arg4);
    unsigned method2(unsigned arg0, short arg1, short arg2, bool arg3, double arg4);
    float method3(float arg0, short arg1, float arg2, double arg3, float arg4);
    double method4(double arg0, unsigned arg1, double arg2, bool arg3, float arg4);
    void method5(double arg0, bool arg1, float arg2, int arg3, float arg4);
    void method6(float arg0, short arg1, float arg2, double arg3, int arg4);
    unsigned method7(int arg0, bool arg1, unsigned arg2, float arg3, unsigned arg4);
    double method8(double arg0, double arg1, bool arg2, short arg3, int arg4);
    bool method9(double arg0, float arg1, short arg2, bool arg3, unsigned arg4);
    void method10(float arg0, bool arg1, double arg2, bool arg3, bool arg4);
    unsigned method11(short arg0, double arg1, unsigned arg2, double arg3, unsigned arg4);
    bool method12(bool arg0, double arg1, double arg2, bool arg3, int arg4);
    float method13(bool arg0, float arg1, float arg2, int arg3, unsigned arg4);
    void method14(int arg0, double arg1, bool arg2, float arg3, float arg4);
}
