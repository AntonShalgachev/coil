#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class38
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, int arg1, int arg2, bool arg3, unsigned arg4);
    unsigned method1(unsigned arg0, short arg1, unsigned arg2, int arg3, bool arg4);
    void method2(double arg0, double arg1, short arg2, double arg3, double arg4);
    void method3(double arg0, double arg1, double arg2, float arg3, bool arg4);
    void method4(double arg0, short arg1, double arg2, int arg3, short arg4);
    void method5(int arg0, int arg1, unsigned arg2, double arg3, short arg4);
    float method6(unsigned arg0, float arg1, double arg2, short arg3, unsigned arg4);
    short method7(short arg0, int arg1, int arg2, bool arg3, double arg4);
    float method8(bool arg0, short arg1, unsigned arg2, float arg3, double arg4);
    void method9(float arg0, unsigned arg1, bool arg2, double arg3, float arg4);
    float method10(short arg0, bool arg1, float arg2, float arg3, double arg4);
    void method11(int arg0, bool arg1, float arg2, short arg3, float arg4);
    bool method12(float arg0, unsigned arg1, float arg2, double arg3, bool arg4);
    void method13(bool arg0, double arg1, bool arg2, bool arg3, bool arg4);
    unsigned method14(short arg0, bool arg1, unsigned arg2, int arg3, unsigned arg4);
};

namespace ns_Class38
{
    void method0(unsigned arg0, int arg1, int arg2, bool arg3, unsigned arg4);
    unsigned method1(unsigned arg0, short arg1, unsigned arg2, int arg3, bool arg4);
    void method2(double arg0, double arg1, short arg2, double arg3, double arg4);
    void method3(double arg0, double arg1, double arg2, float arg3, bool arg4);
    void method4(double arg0, short arg1, double arg2, int arg3, short arg4);
    void method5(int arg0, int arg1, unsigned arg2, double arg3, short arg4);
    float method6(unsigned arg0, float arg1, double arg2, short arg3, unsigned arg4);
    short method7(short arg0, int arg1, int arg2, bool arg3, double arg4);
    float method8(bool arg0, short arg1, unsigned arg2, float arg3, double arg4);
    void method9(float arg0, unsigned arg1, bool arg2, double arg3, float arg4);
    float method10(short arg0, bool arg1, float arg2, float arg3, double arg4);
    void method11(int arg0, bool arg1, float arg2, short arg3, float arg4);
    bool method12(float arg0, unsigned arg1, float arg2, double arg3, bool arg4);
    void method13(bool arg0, double arg1, bool arg2, bool arg3, bool arg4);
    unsigned method14(short arg0, bool arg1, unsigned arg2, int arg3, unsigned arg4);
}
