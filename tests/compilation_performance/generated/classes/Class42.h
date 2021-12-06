#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class42
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(bool arg0, unsigned arg1, int arg2, int arg3, short arg4);
    void method1(float arg0, double arg1, double arg2, float arg3, bool arg4);
    double method2(float arg0, unsigned arg1, double arg2, double arg3, double arg4);
    void method3(int arg0, unsigned arg1, short arg2, float arg3, bool arg4);
    float method4(float arg0, int arg1, bool arg2, bool arg3, float arg4);
    void method5(short arg0, float arg1, int arg2, unsigned arg3, double arg4);
    float method6(double arg0, float arg1, short arg2, short arg3, unsigned arg4);
    unsigned method7(unsigned arg0, double arg1, unsigned arg2, unsigned arg3, short arg4);
    void method8(int arg0, double arg1, bool arg2, int arg3, unsigned arg4);
    void method9(bool arg0, short arg1, int arg2, short arg3, unsigned arg4);
    unsigned method10(float arg0, short arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method11(short arg0, int arg1, double arg2, float arg3, bool arg4);
    unsigned method12(bool arg0, float arg1, int arg2, unsigned arg3, float arg4);
    bool method13(bool arg0, int arg1, bool arg2, short arg3, short arg4);
    int method14(int arg0, double arg1, float arg2, short arg3, short arg4);
};

namespace ns_Class42
{
    int method0(bool arg0, unsigned arg1, int arg2, int arg3, short arg4);
    void method1(float arg0, double arg1, double arg2, float arg3, bool arg4);
    double method2(float arg0, unsigned arg1, double arg2, double arg3, double arg4);
    void method3(int arg0, unsigned arg1, short arg2, float arg3, bool arg4);
    float method4(float arg0, int arg1, bool arg2, bool arg3, float arg4);
    void method5(short arg0, float arg1, int arg2, unsigned arg3, double arg4);
    float method6(double arg0, float arg1, short arg2, short arg3, unsigned arg4);
    unsigned method7(unsigned arg0, double arg1, unsigned arg2, unsigned arg3, short arg4);
    void method8(int arg0, double arg1, bool arg2, int arg3, unsigned arg4);
    void method9(bool arg0, short arg1, int arg2, short arg3, unsigned arg4);
    unsigned method10(float arg0, short arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method11(short arg0, int arg1, double arg2, float arg3, bool arg4);
    unsigned method12(bool arg0, float arg1, int arg2, unsigned arg3, float arg4);
    bool method13(bool arg0, int arg1, bool arg2, short arg3, short arg4);
    int method14(int arg0, double arg1, float arg2, short arg3, short arg4);
}
