#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class0
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, int arg1, bool arg2, double arg3, int arg4);
    void method1(double arg0, double arg1, int arg2, short arg3, int arg4);
    int method2(double arg0, int arg1, unsigned arg2, float arg3, bool arg4);
    void method3(int arg0, unsigned arg1, double arg2, short arg3, short arg4);
    short method4(int arg0, bool arg1, unsigned arg2, double arg3, short arg4);
    bool method5(int arg0, short arg1, double arg2, bool arg3, float arg4);
    void method6(unsigned arg0, short arg1, bool arg2, short arg3, int arg4);
    void method7(bool arg0, double arg1, double arg2, unsigned arg3, unsigned arg4);
    float method8(double arg0, float arg1, float arg2, bool arg3, int arg4);
    bool method9(unsigned arg0, bool arg1, int arg2, bool arg3, int arg4);
    float method10(double arg0, float arg1, double arg2, int arg3, float arg4);
    float method11(bool arg0, float arg1, bool arg2, bool arg3, double arg4);
    void method12(double arg0, float arg1, short arg2, bool arg3, short arg4);
    short method13(short arg0, unsigned arg1, short arg2, float arg3, short arg4);
    void method14(float arg0, int arg1, double arg2, bool arg3, short arg4);
};

namespace ns_Class0
{
    void method0(double arg0, int arg1, bool arg2, double arg3, int arg4);
    void method1(double arg0, double arg1, int arg2, short arg3, int arg4);
    int method2(double arg0, int arg1, unsigned arg2, float arg3, bool arg4);
    void method3(int arg0, unsigned arg1, double arg2, short arg3, short arg4);
    short method4(int arg0, bool arg1, unsigned arg2, double arg3, short arg4);
    bool method5(int arg0, short arg1, double arg2, bool arg3, float arg4);
    void method6(unsigned arg0, short arg1, bool arg2, short arg3, int arg4);
    void method7(bool arg0, double arg1, double arg2, unsigned arg3, unsigned arg4);
    float method8(double arg0, float arg1, float arg2, bool arg3, int arg4);
    bool method9(unsigned arg0, bool arg1, int arg2, bool arg3, int arg4);
    float method10(double arg0, float arg1, double arg2, int arg3, float arg4);
    float method11(bool arg0, float arg1, bool arg2, bool arg3, double arg4);
    void method12(double arg0, float arg1, short arg2, bool arg3, short arg4);
    short method13(short arg0, unsigned arg1, short arg2, float arg3, short arg4);
    void method14(float arg0, int arg1, double arg2, bool arg3, short arg4);
}
