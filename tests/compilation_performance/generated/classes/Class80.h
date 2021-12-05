#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class80
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, bool arg1, float arg2, short arg3, bool arg4);
    int method1(int arg0, unsigned arg1, bool arg2, short arg3, int arg4);
    unsigned method2(float arg0, unsigned arg1, short arg2, bool arg3, int arg4);
    void method3(double arg0, float arg1, bool arg2, short arg3, short arg4);
    void method4(unsigned arg0, double arg1, int arg2, int arg3, float arg4);
    unsigned method5(short arg0, unsigned arg1, double arg2, int arg3, short arg4);
    void method6(bool arg0, bool arg1, double arg2, int arg3, int arg4);
    int method7(short arg0, short arg1, short arg2, short arg3, int arg4);
    void method8(bool arg0, float arg1, float arg2, float arg3, int arg4);
    bool method9(int arg0, short arg1, unsigned arg2, bool arg3, int arg4);
    void method10(unsigned arg0, int arg1, int arg2, float arg3, float arg4);
    void method11(unsigned arg0, double arg1, double arg2, float arg3, bool arg4);
    unsigned method12(int arg0, double arg1, float arg2, unsigned arg3, int arg4);
    int method13(int arg0, int arg1, int arg2, bool arg3, int arg4);
    int method14(bool arg0, float arg1, bool arg2, float arg3, int arg4);
};

namespace ns_Class80
{
    void method0(double arg0, bool arg1, float arg2, short arg3, bool arg4);
    int method1(int arg0, unsigned arg1, bool arg2, short arg3, int arg4);
    unsigned method2(float arg0, unsigned arg1, short arg2, bool arg3, int arg4);
    void method3(double arg0, float arg1, bool arg2, short arg3, short arg4);
    void method4(unsigned arg0, double arg1, int arg2, int arg3, float arg4);
    unsigned method5(short arg0, unsigned arg1, double arg2, int arg3, short arg4);
    void method6(bool arg0, bool arg1, double arg2, int arg3, int arg4);
    int method7(short arg0, short arg1, short arg2, short arg3, int arg4);
    void method8(bool arg0, float arg1, float arg2, float arg3, int arg4);
    bool method9(int arg0, short arg1, unsigned arg2, bool arg3, int arg4);
    void method10(unsigned arg0, int arg1, int arg2, float arg3, float arg4);
    void method11(unsigned arg0, double arg1, double arg2, float arg3, bool arg4);
    unsigned method12(int arg0, double arg1, float arg2, unsigned arg3, int arg4);
    int method13(int arg0, int arg1, int arg2, bool arg3, int arg4);
    int method14(bool arg0, float arg1, bool arg2, float arg3, int arg4);
}
