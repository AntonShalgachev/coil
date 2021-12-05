#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class95
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(short arg0, float arg1, short arg2, float arg3, unsigned arg4);
    void method1(short arg0, unsigned arg1, double arg2, unsigned arg3, float arg4);
    double method2(double arg0, float arg1, short arg2, double arg3, unsigned arg4);
    double method3(unsigned arg0, double arg1, unsigned arg2, double arg3, float arg4);
    void method4(float arg0, double arg1, float arg2, int arg3, int arg4);
    void method5(short arg0, int arg1, bool arg2, int arg3, bool arg4);
    bool method6(bool arg0, double arg1, short arg2, double arg3, short arg4);
    void method7(short arg0, unsigned arg1, float arg2, bool arg3, double arg4);
    void method8(short arg0, double arg1, float arg2, double arg3, double arg4);
    short method9(short arg0, float arg1, short arg2, double arg3, float arg4);
    double method10(double arg0, short arg1, float arg2, short arg3, short arg4);
    double method11(short arg0, double arg1, unsigned arg2, float arg3, unsigned arg4);
    void method12(short arg0, float arg1, unsigned arg2, short arg3, double arg4);
    bool method13(int arg0, bool arg1, float arg2, float arg3, double arg4);
    void method14(unsigned arg0, double arg1, bool arg2, float arg3, int arg4);
};

namespace ns_Class95
{
    unsigned method0(short arg0, float arg1, short arg2, float arg3, unsigned arg4);
    void method1(short arg0, unsigned arg1, double arg2, unsigned arg3, float arg4);
    double method2(double arg0, float arg1, short arg2, double arg3, unsigned arg4);
    double method3(unsigned arg0, double arg1, unsigned arg2, double arg3, float arg4);
    void method4(float arg0, double arg1, float arg2, int arg3, int arg4);
    void method5(short arg0, int arg1, bool arg2, int arg3, bool arg4);
    bool method6(bool arg0, double arg1, short arg2, double arg3, short arg4);
    void method7(short arg0, unsigned arg1, float arg2, bool arg3, double arg4);
    void method8(short arg0, double arg1, float arg2, double arg3, double arg4);
    short method9(short arg0, float arg1, short arg2, double arg3, float arg4);
    double method10(double arg0, short arg1, float arg2, short arg3, short arg4);
    double method11(short arg0, double arg1, unsigned arg2, float arg3, unsigned arg4);
    void method12(short arg0, float arg1, unsigned arg2, short arg3, double arg4);
    bool method13(int arg0, bool arg1, float arg2, float arg3, double arg4);
    void method14(unsigned arg0, double arg1, bool arg2, float arg3, int arg4);
}
