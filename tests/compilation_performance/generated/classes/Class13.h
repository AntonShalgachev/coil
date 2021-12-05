#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class13
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    float method1(bool arg0, unsigned arg1, bool arg2, float arg3, double arg4);
    void method2(unsigned arg0, bool arg1, float arg2, int arg3, bool arg4);
    float method3(bool arg0, double arg1, float arg2, double arg3, double arg4);
    unsigned method4(float arg0, float arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method5(short arg0, unsigned arg1, short arg2, bool arg3, short arg4);
    bool method6(double arg0, bool arg1, float arg2, unsigned arg3, float arg4);
    float method7(float arg0, bool arg1, bool arg2, int arg3, double arg4);
    void method8(float arg0, short arg1, float arg2, double arg3, float arg4);
    void method9(double arg0, float arg1, short arg2, bool arg3, bool arg4);
    void method10(short arg0, int arg1, unsigned arg2, float arg3, short arg4);
    void method11(double arg0, bool arg1, short arg2, double arg3, unsigned arg4);
    void method12(unsigned arg0, bool arg1, float arg2, int arg3, bool arg4);
    short method13(int arg0, unsigned arg1, unsigned arg2, short arg3, double arg4);
    short method14(int arg0, int arg1, short arg2, float arg3, short arg4);
};

namespace ns_Class13
{
    void method0(int arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    float method1(bool arg0, unsigned arg1, bool arg2, float arg3, double arg4);
    void method2(unsigned arg0, bool arg1, float arg2, int arg3, bool arg4);
    float method3(bool arg0, double arg1, float arg2, double arg3, double arg4);
    unsigned method4(float arg0, float arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method5(short arg0, unsigned arg1, short arg2, bool arg3, short arg4);
    bool method6(double arg0, bool arg1, float arg2, unsigned arg3, float arg4);
    float method7(float arg0, bool arg1, bool arg2, int arg3, double arg4);
    void method8(float arg0, short arg1, float arg2, double arg3, float arg4);
    void method9(double arg0, float arg1, short arg2, bool arg3, bool arg4);
    void method10(short arg0, int arg1, unsigned arg2, float arg3, short arg4);
    void method11(double arg0, bool arg1, short arg2, double arg3, unsigned arg4);
    void method12(unsigned arg0, bool arg1, float arg2, int arg3, bool arg4);
    short method13(int arg0, unsigned arg1, unsigned arg2, short arg3, double arg4);
    short method14(int arg0, int arg1, short arg2, float arg3, short arg4);
}
