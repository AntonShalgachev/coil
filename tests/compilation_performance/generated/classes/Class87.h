#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class87
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
    void method1(unsigned arg0, float arg1, float arg2, int arg3, int arg4);
    void method2(int arg0, unsigned arg1, unsigned arg2, short arg3, bool arg4);
    void method3(bool arg0, unsigned arg1, unsigned arg2, short arg3, int arg4);
    short method4(short arg0, bool arg1, bool arg2, bool arg3, bool arg4);
    void method5(int arg0, double arg1, unsigned arg2, unsigned arg3, short arg4);
    float method6(unsigned arg0, double arg1, bool arg2, float arg3, float arg4);
    void method7(int arg0, double arg1, int arg2, int arg3, double arg4);
    double method8(float arg0, unsigned arg1, bool arg2, double arg3, unsigned arg4);
    float method9(int arg0, float arg1, unsigned arg2, float arg3, short arg4);
    void method10(short arg0, int arg1, short arg2, int arg3, unsigned arg4);
    float method11(float arg0, bool arg1, double arg2, float arg3, unsigned arg4);
    void method12(float arg0, float arg1, unsigned arg2, float arg3, bool arg4);
    void method13(unsigned arg0, unsigned arg1, unsigned arg2, double arg3, bool arg4);
    int method14(float arg0, int arg1, bool arg2, float arg3, double arg4);
};

namespace ns_Class87
{
    void method0(float arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
    void method1(unsigned arg0, float arg1, float arg2, int arg3, int arg4);
    void method2(int arg0, unsigned arg1, unsigned arg2, short arg3, bool arg4);
    void method3(bool arg0, unsigned arg1, unsigned arg2, short arg3, int arg4);
    short method4(short arg0, bool arg1, bool arg2, bool arg3, bool arg4);
    void method5(int arg0, double arg1, unsigned arg2, unsigned arg3, short arg4);
    float method6(unsigned arg0, double arg1, bool arg2, float arg3, float arg4);
    void method7(int arg0, double arg1, int arg2, int arg3, double arg4);
    double method8(float arg0, unsigned arg1, bool arg2, double arg3, unsigned arg4);
    float method9(int arg0, float arg1, unsigned arg2, float arg3, short arg4);
    void method10(short arg0, int arg1, short arg2, int arg3, unsigned arg4);
    float method11(float arg0, bool arg1, double arg2, float arg3, unsigned arg4);
    void method12(float arg0, float arg1, unsigned arg2, float arg3, bool arg4);
    void method13(unsigned arg0, unsigned arg1, unsigned arg2, double arg3, bool arg4);
    int method14(float arg0, int arg1, bool arg2, float arg3, double arg4);
}
