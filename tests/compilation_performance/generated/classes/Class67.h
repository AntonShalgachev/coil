#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class67
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(bool arg0, bool arg1, float arg2, int arg3, bool arg4);
    void method1(bool arg0, bool arg1, bool arg2, int arg3, int arg4);
    void method2(double arg0, int arg1, bool arg2, short arg3, short arg4);
    void method3(int arg0, unsigned arg1, float arg2, short arg3, bool arg4);
    double method4(short arg0, double arg1, bool arg2, float arg3, int arg4);
    void method5(short arg0, short arg1, short arg2, unsigned arg3, double arg4);
    bool method6(bool arg0, short arg1, int arg2, int arg3, bool arg4);
    void method7(unsigned arg0, unsigned arg1, double arg2, double arg3, bool arg4);
    float method8(int arg0, double arg1, short arg2, short arg3, float arg4);
    void method9(float arg0, bool arg1, float arg2, short arg3, unsigned arg4);
    short method10(double arg0, int arg1, float arg2, short arg3, float arg4);
    void method11(float arg0, int arg1, unsigned arg2, int arg3, float arg4);
    void method12(bool arg0, int arg1, unsigned arg2, int arg3, int arg4);
    void method13(float arg0, unsigned arg1, short arg2, float arg3, float arg4);
    bool method14(bool arg0, bool arg1, unsigned arg2, bool arg3, short arg4);
};

namespace ns_Class67
{
    bool method0(bool arg0, bool arg1, float arg2, int arg3, bool arg4);
    void method1(bool arg0, bool arg1, bool arg2, int arg3, int arg4);
    void method2(double arg0, int arg1, bool arg2, short arg3, short arg4);
    void method3(int arg0, unsigned arg1, float arg2, short arg3, bool arg4);
    double method4(short arg0, double arg1, bool arg2, float arg3, int arg4);
    void method5(short arg0, short arg1, short arg2, unsigned arg3, double arg4);
    bool method6(bool arg0, short arg1, int arg2, int arg3, bool arg4);
    void method7(unsigned arg0, unsigned arg1, double arg2, double arg3, bool arg4);
    float method8(int arg0, double arg1, short arg2, short arg3, float arg4);
    void method9(float arg0, bool arg1, float arg2, short arg3, unsigned arg4);
    short method10(double arg0, int arg1, float arg2, short arg3, float arg4);
    void method11(float arg0, int arg1, unsigned arg2, int arg3, float arg4);
    void method12(bool arg0, int arg1, unsigned arg2, int arg3, int arg4);
    void method13(float arg0, unsigned arg1, short arg2, float arg3, float arg4);
    bool method14(bool arg0, bool arg1, unsigned arg2, bool arg3, short arg4);
}
