#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class48
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(bool arg0, float arg1, float arg2, double arg3, int arg4);
    void method1(float arg0, bool arg1, unsigned arg2, unsigned arg3, bool arg4);
    bool method2(bool arg0, unsigned arg1, float arg2, unsigned arg3, bool arg4);
    float method3(bool arg0, int arg1, bool arg2, unsigned arg3, float arg4);
    unsigned method4(short arg0, unsigned arg1, unsigned arg2, float arg3, float arg4);
    void method5(double arg0, int arg1, short arg2, unsigned arg3, int arg4);
    void method6(float arg0, short arg1, int arg2, unsigned arg3, bool arg4);
    float method7(int arg0, float arg1, float arg2, short arg3, float arg4);
    bool method8(short arg0, float arg1, unsigned arg2, unsigned arg3, bool arg4);
    unsigned method9(int arg0, unsigned arg1, short arg2, unsigned arg3, float arg4);
    int method10(int arg0, double arg1, int arg2, bool arg3, double arg4);
    void method11(short arg0, short arg1, short arg2, double arg3, short arg4);
    bool method12(unsigned arg0, double arg1, double arg2, bool arg3, unsigned arg4);
    float method13(float arg0, float arg1, double arg2, unsigned arg3, unsigned arg4);
    void method14(int arg0, float arg1, unsigned arg2, int arg3, float arg4);
};

namespace ns_Class48
{
    int method0(bool arg0, float arg1, float arg2, double arg3, int arg4);
    void method1(float arg0, bool arg1, unsigned arg2, unsigned arg3, bool arg4);
    bool method2(bool arg0, unsigned arg1, float arg2, unsigned arg3, bool arg4);
    float method3(bool arg0, int arg1, bool arg2, unsigned arg3, float arg4);
    unsigned method4(short arg0, unsigned arg1, unsigned arg2, float arg3, float arg4);
    void method5(double arg0, int arg1, short arg2, unsigned arg3, int arg4);
    void method6(float arg0, short arg1, int arg2, unsigned arg3, bool arg4);
    float method7(int arg0, float arg1, float arg2, short arg3, float arg4);
    bool method8(short arg0, float arg1, unsigned arg2, unsigned arg3, bool arg4);
    unsigned method9(int arg0, unsigned arg1, short arg2, unsigned arg3, float arg4);
    int method10(int arg0, double arg1, int arg2, bool arg3, double arg4);
    void method11(short arg0, short arg1, short arg2, double arg3, short arg4);
    bool method12(unsigned arg0, double arg1, double arg2, bool arg3, unsigned arg4);
    float method13(float arg0, float arg1, double arg2, unsigned arg3, unsigned arg4);
    void method14(int arg0, float arg1, unsigned arg2, int arg3, float arg4);
}
