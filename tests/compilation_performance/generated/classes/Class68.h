#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class68
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(float arg0, short arg1, short arg2, float arg3, float arg4);
    unsigned method1(unsigned arg0, short arg1, bool arg2, int arg3, bool arg4);
    void method2(short arg0, double arg1, unsigned arg2, double arg3, int arg4);
    unsigned method3(unsigned arg0, float arg1, int arg2, bool arg3, short arg4);
    double method4(double arg0, unsigned arg1, float arg2, float arg3, unsigned arg4);
    unsigned method5(short arg0, unsigned arg1, bool arg2, int arg3, unsigned arg4);
    int method6(double arg0, float arg1, float arg2, int arg3, int arg4);
    void method7(float arg0, float arg1, float arg2, unsigned arg3, short arg4);
    short method8(short arg0, unsigned arg1, bool arg2, float arg3, double arg4);
    bool method9(int arg0, short arg1, int arg2, bool arg3, double arg4);
    int method10(float arg0, double arg1, unsigned arg2, short arg3, int arg4);
    float method11(int arg0, float arg1, float arg2, float arg3, float arg4);
    void method12(short arg0, short arg1, float arg2, unsigned arg3, bool arg4);
    int method13(int arg0, short arg1, unsigned arg2, int arg3, float arg4);
    void method14(unsigned arg0, bool arg1, unsigned arg2, bool arg3, float arg4);
};

namespace ns_Class68
{
    float method0(float arg0, short arg1, short arg2, float arg3, float arg4);
    unsigned method1(unsigned arg0, short arg1, bool arg2, int arg3, bool arg4);
    void method2(short arg0, double arg1, unsigned arg2, double arg3, int arg4);
    unsigned method3(unsigned arg0, float arg1, int arg2, bool arg3, short arg4);
    double method4(double arg0, unsigned arg1, float arg2, float arg3, unsigned arg4);
    unsigned method5(short arg0, unsigned arg1, bool arg2, int arg3, unsigned arg4);
    int method6(double arg0, float arg1, float arg2, int arg3, int arg4);
    void method7(float arg0, float arg1, float arg2, unsigned arg3, short arg4);
    short method8(short arg0, unsigned arg1, bool arg2, float arg3, double arg4);
    bool method9(int arg0, short arg1, int arg2, bool arg3, double arg4);
    int method10(float arg0, double arg1, unsigned arg2, short arg3, int arg4);
    float method11(int arg0, float arg1, float arg2, float arg3, float arg4);
    void method12(short arg0, short arg1, float arg2, unsigned arg3, bool arg4);
    int method13(int arg0, short arg1, unsigned arg2, int arg3, float arg4);
    void method14(unsigned arg0, bool arg1, unsigned arg2, bool arg3, float arg4);
}
