#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class83
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(unsigned arg0, int arg1, int arg2, int arg3, int arg4);
    void method1(float arg0, unsigned arg1, short arg2, double arg3, short arg4);
    void method2(short arg0, float arg1, int arg2, unsigned arg3, unsigned arg4);
    short method3(short arg0, float arg1, int arg2, float arg3, int arg4);
    double method4(unsigned arg0, float arg1, double arg2, unsigned arg3, bool arg4);
    void method5(int arg0, double arg1, bool arg2, bool arg3, float arg4);
    double method6(float arg0, short arg1, double arg2, int arg3, double arg4);
    void method7(double arg0, short arg1, unsigned arg2, int arg3, double arg4);
    void method8(int arg0, unsigned arg1, int arg2, float arg3, double arg4);
    short method9(unsigned arg0, short arg1, bool arg2, int arg3, float arg4);
    bool method10(bool arg0, bool arg1, int arg2, float arg3, unsigned arg4);
    unsigned method11(float arg0, bool arg1, float arg2, unsigned arg3, bool arg4);
    void method12(bool arg0, short arg1, float arg2, short arg3, float arg4);
    double method13(bool arg0, double arg1, double arg2, bool arg3, int arg4);
    void method14(int arg0, int arg1, float arg2, float arg3, double arg4);
};

namespace ns_Class83
{
    int method0(unsigned arg0, int arg1, int arg2, int arg3, int arg4);
    void method1(float arg0, unsigned arg1, short arg2, double arg3, short arg4);
    void method2(short arg0, float arg1, int arg2, unsigned arg3, unsigned arg4);
    short method3(short arg0, float arg1, int arg2, float arg3, int arg4);
    double method4(unsigned arg0, float arg1, double arg2, unsigned arg3, bool arg4);
    void method5(int arg0, double arg1, bool arg2, bool arg3, float arg4);
    double method6(float arg0, short arg1, double arg2, int arg3, double arg4);
    void method7(double arg0, short arg1, unsigned arg2, int arg3, double arg4);
    void method8(int arg0, unsigned arg1, int arg2, float arg3, double arg4);
    short method9(unsigned arg0, short arg1, bool arg2, int arg3, float arg4);
    bool method10(bool arg0, bool arg1, int arg2, float arg3, unsigned arg4);
    unsigned method11(float arg0, bool arg1, float arg2, unsigned arg3, bool arg4);
    void method12(bool arg0, short arg1, float arg2, short arg3, float arg4);
    double method13(bool arg0, double arg1, double arg2, bool arg3, int arg4);
    void method14(int arg0, int arg1, float arg2, float arg3, double arg4);
}
