#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class52
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, float arg1, int arg2, int arg3, bool arg4);
    int method1(short arg0, bool arg1, short arg2, float arg3, int arg4);
    void method2(unsigned arg0, double arg1, int arg2, double arg3, short arg4);
    void method3(short arg0, double arg1, unsigned arg2, bool arg3, unsigned arg4);
    short method4(short arg0, float arg1, unsigned arg2, bool arg3, float arg4);
    double method5(short arg0, bool arg1, int arg2, short arg3, double arg4);
    short method6(double arg0, bool arg1, int arg2, short arg3, int arg4);
    unsigned method7(short arg0, short arg1, unsigned arg2, float arg3, short arg4);
    unsigned method8(unsigned arg0, short arg1, double arg2, short arg3, bool arg4);
    void method9(int arg0, float arg1, bool arg2, unsigned arg3, bool arg4);
    unsigned method10(unsigned arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    void method11(unsigned arg0, int arg1, short arg2, double arg3, unsigned arg4);
    void method12(double arg0, float arg1, short arg2, bool arg3, double arg4);
    void method13(unsigned arg0, bool arg1, unsigned arg2, double arg3, double arg4);
    double method14(float arg0, short arg1, double arg2, double arg3, int arg4);
};

namespace ns_Class52
{
    void method0(int arg0, float arg1, int arg2, int arg3, bool arg4);
    int method1(short arg0, bool arg1, short arg2, float arg3, int arg4);
    void method2(unsigned arg0, double arg1, int arg2, double arg3, short arg4);
    void method3(short arg0, double arg1, unsigned arg2, bool arg3, unsigned arg4);
    short method4(short arg0, float arg1, unsigned arg2, bool arg3, float arg4);
    double method5(short arg0, bool arg1, int arg2, short arg3, double arg4);
    short method6(double arg0, bool arg1, int arg2, short arg3, int arg4);
    unsigned method7(short arg0, short arg1, unsigned arg2, float arg3, short arg4);
    unsigned method8(unsigned arg0, short arg1, double arg2, short arg3, bool arg4);
    void method9(int arg0, float arg1, bool arg2, unsigned arg3, bool arg4);
    unsigned method10(unsigned arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    void method11(unsigned arg0, int arg1, short arg2, double arg3, unsigned arg4);
    void method12(double arg0, float arg1, short arg2, bool arg3, double arg4);
    void method13(unsigned arg0, bool arg1, unsigned arg2, double arg3, double arg4);
    double method14(float arg0, short arg1, double arg2, double arg3, int arg4);
}
