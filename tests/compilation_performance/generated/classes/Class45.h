#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class45
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(double arg0, float arg1, float arg2, unsigned arg3, bool arg4);
    void method1(short arg0, bool arg1, short arg2, unsigned arg3, unsigned arg4);
    void method2(float arg0, int arg1, short arg2, float arg3, bool arg4);
    void method3(bool arg0, int arg1, unsigned arg2, bool arg3, float arg4);
    unsigned method4(int arg0, double arg1, int arg2, short arg3, unsigned arg4);
    void method5(float arg0, short arg1, unsigned arg2, double arg3, unsigned arg4);
    float method6(double arg0, bool arg1, float arg2, float arg3, int arg4);
    short method7(float arg0, bool arg1, int arg2, short arg3, int arg4);
    void method8(double arg0, double arg1, bool arg2, bool arg3, unsigned arg4);
    double method9(bool arg0, short arg1, unsigned arg2, double arg3, int arg4);
    short method10(bool arg0, short arg1, short arg2, float arg3, float arg4);
    short method11(double arg0, unsigned arg1, short arg2, short arg3, short arg4);
    void method12(float arg0, float arg1, unsigned arg2, int arg3, short arg4);
    void method13(bool arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    bool method14(bool arg0, float arg1, unsigned arg2, bool arg3, double arg4);
};

namespace ns_Class45
{
    double method0(double arg0, float arg1, float arg2, unsigned arg3, bool arg4);
    void method1(short arg0, bool arg1, short arg2, unsigned arg3, unsigned arg4);
    void method2(float arg0, int arg1, short arg2, float arg3, bool arg4);
    void method3(bool arg0, int arg1, unsigned arg2, bool arg3, float arg4);
    unsigned method4(int arg0, double arg1, int arg2, short arg3, unsigned arg4);
    void method5(float arg0, short arg1, unsigned arg2, double arg3, unsigned arg4);
    float method6(double arg0, bool arg1, float arg2, float arg3, int arg4);
    short method7(float arg0, bool arg1, int arg2, short arg3, int arg4);
    void method8(double arg0, double arg1, bool arg2, bool arg3, unsigned arg4);
    double method9(bool arg0, short arg1, unsigned arg2, double arg3, int arg4);
    short method10(bool arg0, short arg1, short arg2, float arg3, float arg4);
    short method11(double arg0, unsigned arg1, short arg2, short arg3, short arg4);
    void method12(float arg0, float arg1, unsigned arg2, int arg3, short arg4);
    void method13(bool arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    bool method14(bool arg0, float arg1, unsigned arg2, bool arg3, double arg4);
}
