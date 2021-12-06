#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class24
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(short arg0, short arg1, short arg2, short arg3, int arg4);
    void method1(double arg0, float arg1, float arg2, float arg3, short arg4);
    unsigned method2(unsigned arg0, short arg1, float arg2, double arg3, short arg4);
    void method3(short arg0, short arg1, bool arg2, float arg3, double arg4);
    double method4(unsigned arg0, unsigned arg1, double arg2, double arg3, bool arg4);
    double method5(double arg0, bool arg1, double arg2, short arg3, short arg4);
    short method6(float arg0, unsigned arg1, float arg2, short arg3, double arg4);
    void method7(bool arg0, bool arg1, bool arg2, int arg3, bool arg4);
    void method8(bool arg0, double arg1, short arg2, int arg3, short arg4);
    void method9(double arg0, float arg1, short arg2, float arg3, short arg4);
    void method10(double arg0, bool arg1, unsigned arg2, bool arg3, int arg4);
    void method11(bool arg0, double arg1, int arg2, short arg3, unsigned arg4);
    void method12(int arg0, float arg1, float arg2, double arg3, double arg4);
    unsigned method13(bool arg0, float arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method14(double arg0, short arg1, double arg2, int arg3, int arg4);
};

namespace ns_Class24
{
    short method0(short arg0, short arg1, short arg2, short arg3, int arg4);
    void method1(double arg0, float arg1, float arg2, float arg3, short arg4);
    unsigned method2(unsigned arg0, short arg1, float arg2, double arg3, short arg4);
    void method3(short arg0, short arg1, bool arg2, float arg3, double arg4);
    double method4(unsigned arg0, unsigned arg1, double arg2, double arg3, bool arg4);
    double method5(double arg0, bool arg1, double arg2, short arg3, short arg4);
    short method6(float arg0, unsigned arg1, float arg2, short arg3, double arg4);
    void method7(bool arg0, bool arg1, bool arg2, int arg3, bool arg4);
    void method8(bool arg0, double arg1, short arg2, int arg3, short arg4);
    void method9(double arg0, float arg1, short arg2, float arg3, short arg4);
    void method10(double arg0, bool arg1, unsigned arg2, bool arg3, int arg4);
    void method11(bool arg0, double arg1, int arg2, short arg3, unsigned arg4);
    void method12(int arg0, float arg1, float arg2, double arg3, double arg4);
    unsigned method13(bool arg0, float arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method14(double arg0, short arg1, double arg2, int arg3, int arg4);
}
