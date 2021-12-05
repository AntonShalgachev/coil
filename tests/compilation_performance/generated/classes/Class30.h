#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class30
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, double arg1, float arg2, int arg3, int arg4);
    int method1(unsigned arg0, bool arg1, int arg2, int arg3, short arg4);
    void method2(short arg0, int arg1, unsigned arg2, unsigned arg3, double arg4);
    float method3(float arg0, int arg1, bool arg2, unsigned arg3, float arg4);
    void method4(float arg0, int arg1, short arg2, unsigned arg3, short arg4);
    unsigned method5(int arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    double method6(int arg0, bool arg1, short arg2, float arg3, double arg4);
    void method7(bool arg0, float arg1, float arg2, bool arg3, short arg4);
    void method8(short arg0, double arg1, double arg2, double arg3, int arg4);
    float method9(unsigned arg0, unsigned arg1, float arg2, float arg3, double arg4);
    double method10(unsigned arg0, float arg1, float arg2, double arg3, double arg4);
    float method11(bool arg0, float arg1, unsigned arg2, double arg3, short arg4);
    short method12(float arg0, short arg1, short arg2, float arg3, float arg4);
    void method13(float arg0, short arg1, bool arg2, short arg3, float arg4);
    int method14(int arg0, float arg1, unsigned arg2, bool arg3, unsigned arg4);
};

namespace ns_Class30
{
    void method0(short arg0, double arg1, float arg2, int arg3, int arg4);
    int method1(unsigned arg0, bool arg1, int arg2, int arg3, short arg4);
    void method2(short arg0, int arg1, unsigned arg2, unsigned arg3, double arg4);
    float method3(float arg0, int arg1, bool arg2, unsigned arg3, float arg4);
    void method4(float arg0, int arg1, short arg2, unsigned arg3, short arg4);
    unsigned method5(int arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    double method6(int arg0, bool arg1, short arg2, float arg3, double arg4);
    void method7(bool arg0, float arg1, float arg2, bool arg3, short arg4);
    void method8(short arg0, double arg1, double arg2, double arg3, int arg4);
    float method9(unsigned arg0, unsigned arg1, float arg2, float arg3, double arg4);
    double method10(unsigned arg0, float arg1, float arg2, double arg3, double arg4);
    float method11(bool arg0, float arg1, unsigned arg2, double arg3, short arg4);
    short method12(float arg0, short arg1, short arg2, float arg3, float arg4);
    void method13(float arg0, short arg1, bool arg2, short arg3, float arg4);
    int method14(int arg0, float arg1, unsigned arg2, bool arg3, unsigned arg4);
}
