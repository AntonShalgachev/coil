#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class74
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(bool arg0, short arg1, short arg2, int arg3, float arg4);
    void method1(double arg0, short arg1, short arg2, float arg3, double arg4);
    double method2(short arg0, int arg1, unsigned arg2, double arg3, float arg4);
    void method3(int arg0, short arg1, int arg2, double arg3, bool arg4);
    unsigned method4(unsigned arg0, bool arg1, bool arg2, float arg3, bool arg4);
    int method5(bool arg0, float arg1, short arg2, int arg3, bool arg4);
    float method6(float arg0, bool arg1, double arg2, bool arg3, int arg4);
    int method7(float arg0, bool arg1, int arg2, short arg3, short arg4);
    void method8(short arg0, short arg1, unsigned arg2, short arg3, int arg4);
    bool method9(bool arg0, short arg1, bool arg2, double arg3, int arg4);
    unsigned method10(short arg0, double arg1, unsigned arg2, unsigned arg3, int arg4);
    double method11(int arg0, double arg1, double arg2, int arg3, short arg4);
    unsigned method12(bool arg0, unsigned arg1, short arg2, unsigned arg3, int arg4);
    unsigned method13(short arg0, unsigned arg1, double arg2, int arg3, float arg4);
    void method14(float arg0, float arg1, short arg2, float arg3, int arg4);
};

namespace ns_Class74
{
    void method0(bool arg0, short arg1, short arg2, int arg3, float arg4);
    void method1(double arg0, short arg1, short arg2, float arg3, double arg4);
    double method2(short arg0, int arg1, unsigned arg2, double arg3, float arg4);
    void method3(int arg0, short arg1, int arg2, double arg3, bool arg4);
    unsigned method4(unsigned arg0, bool arg1, bool arg2, float arg3, bool arg4);
    int method5(bool arg0, float arg1, short arg2, int arg3, bool arg4);
    float method6(float arg0, bool arg1, double arg2, bool arg3, int arg4);
    int method7(float arg0, bool arg1, int arg2, short arg3, short arg4);
    void method8(short arg0, short arg1, unsigned arg2, short arg3, int arg4);
    bool method9(bool arg0, short arg1, bool arg2, double arg3, int arg4);
    unsigned method10(short arg0, double arg1, unsigned arg2, unsigned arg3, int arg4);
    double method11(int arg0, double arg1, double arg2, int arg3, short arg4);
    unsigned method12(bool arg0, unsigned arg1, short arg2, unsigned arg3, int arg4);
    unsigned method13(short arg0, unsigned arg1, double arg2, int arg3, float arg4);
    void method14(float arg0, float arg1, short arg2, float arg3, int arg4);
}
