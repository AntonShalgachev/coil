#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class86
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(bool arg0, unsigned arg1, float arg2, unsigned arg3, int arg4);
    void method1(float arg0, short arg1, float arg2, bool arg3, double arg4);
    void method2(float arg0, double arg1, bool arg2, float arg3, float arg4);
    void method3(int arg0, int arg1, int arg2, float arg3, double arg4);
    void method4(short arg0, unsigned arg1, int arg2, bool arg3, float arg4);
    unsigned method5(short arg0, float arg1, unsigned arg2, short arg3, int arg4);
    float method6(unsigned arg0, float arg1, int arg2, float arg3, int arg4);
    void method7(unsigned arg0, double arg1, unsigned arg2, short arg3, double arg4);
    bool method8(bool arg0, unsigned arg1, unsigned arg2, short arg3, bool arg4);
    unsigned method9(int arg0, unsigned arg1, bool arg2, short arg3, unsigned arg4);
    void method10(double arg0, int arg1, short arg2, float arg3, unsigned arg4);
    void method11(float arg0, int arg1, unsigned arg2, float arg3, short arg4);
    bool method12(int arg0, bool arg1, float arg2, double arg3, bool arg4);
    float method13(float arg0, bool arg1, double arg2, float arg3, float arg4);
    void method14(bool arg0, unsigned arg1, bool arg2, double arg3, int arg4);
};

namespace ns_Class86
{
    float method0(bool arg0, unsigned arg1, float arg2, unsigned arg3, int arg4);
    void method1(float arg0, short arg1, float arg2, bool arg3, double arg4);
    void method2(float arg0, double arg1, bool arg2, float arg3, float arg4);
    void method3(int arg0, int arg1, int arg2, float arg3, double arg4);
    void method4(short arg0, unsigned arg1, int arg2, bool arg3, float arg4);
    unsigned method5(short arg0, float arg1, unsigned arg2, short arg3, int arg4);
    float method6(unsigned arg0, float arg1, int arg2, float arg3, int arg4);
    void method7(unsigned arg0, double arg1, unsigned arg2, short arg3, double arg4);
    bool method8(bool arg0, unsigned arg1, unsigned arg2, short arg3, bool arg4);
    unsigned method9(int arg0, unsigned arg1, bool arg2, short arg3, unsigned arg4);
    void method10(double arg0, int arg1, short arg2, float arg3, unsigned arg4);
    void method11(float arg0, int arg1, unsigned arg2, float arg3, short arg4);
    bool method12(int arg0, bool arg1, float arg2, double arg3, bool arg4);
    float method13(float arg0, bool arg1, double arg2, float arg3, float arg4);
    void method14(bool arg0, unsigned arg1, bool arg2, double arg3, int arg4);
}
