#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class91
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, unsigned arg1, unsigned arg2, short arg3, double arg4);
    int method1(double arg0, unsigned arg1, int arg2, int arg3, int arg4);
    void method2(unsigned arg0, float arg1, bool arg2, short arg3, short arg4);
    void method3(bool arg0, unsigned arg1, short arg2, short arg3, short arg4);
    void method4(short arg0, bool arg1, double arg2, bool arg3, double arg4);
    short method5(bool arg0, short arg1, bool arg2, int arg3, unsigned arg4);
    void method6(unsigned arg0, float arg1, double arg2, unsigned arg3, short arg4);
    unsigned method7(bool arg0, unsigned arg1, unsigned arg2, double arg3, short arg4);
    void method8(float arg0, short arg1, bool arg2, int arg3, double arg4);
    void method9(float arg0, short arg1, int arg2, float arg3, short arg4);
    void method10(bool arg0, double arg1, double arg2, int arg3, bool arg4);
    void method11(unsigned arg0, double arg1, bool arg2, short arg3, int arg4);
    unsigned method12(bool arg0, short arg1, double arg2, unsigned arg3, unsigned arg4);
    int method13(int arg0, unsigned arg1, int arg2, double arg3, double arg4);
    short method14(unsigned arg0, unsigned arg1, int arg2, short arg3, int arg4);
};

namespace ns_Class91
{
    void method0(unsigned arg0, unsigned arg1, unsigned arg2, short arg3, double arg4);
    int method1(double arg0, unsigned arg1, int arg2, int arg3, int arg4);
    void method2(unsigned arg0, float arg1, bool arg2, short arg3, short arg4);
    void method3(bool arg0, unsigned arg1, short arg2, short arg3, short arg4);
    void method4(short arg0, bool arg1, double arg2, bool arg3, double arg4);
    short method5(bool arg0, short arg1, bool arg2, int arg3, unsigned arg4);
    void method6(unsigned arg0, float arg1, double arg2, unsigned arg3, short arg4);
    unsigned method7(bool arg0, unsigned arg1, unsigned arg2, double arg3, short arg4);
    void method8(float arg0, short arg1, bool arg2, int arg3, double arg4);
    void method9(float arg0, short arg1, int arg2, float arg3, short arg4);
    void method10(bool arg0, double arg1, double arg2, int arg3, bool arg4);
    void method11(unsigned arg0, double arg1, bool arg2, short arg3, int arg4);
    unsigned method12(bool arg0, short arg1, double arg2, unsigned arg3, unsigned arg4);
    int method13(int arg0, unsigned arg1, int arg2, double arg3, double arg4);
    short method14(unsigned arg0, unsigned arg1, int arg2, short arg3, int arg4);
}
