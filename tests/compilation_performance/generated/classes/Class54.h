#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class54
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, short arg1, short arg2, double arg3, short arg4);
    unsigned method1(short arg0, unsigned arg1, unsigned arg2, float arg3, double arg4);
    void method2(bool arg0, double arg1, float arg2, int arg3, bool arg4);
    void method3(bool arg0, float arg1, int arg2, float arg3, float arg4);
    void method4(short arg0, int arg1, short arg2, short arg3, float arg4);
    short method5(float arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    int method6(unsigned arg0, float arg1, int arg2, unsigned arg3, bool arg4);
    void method7(double arg0, float arg1, int arg2, double arg3, int arg4);
    unsigned method8(double arg0, double arg1, bool arg2, unsigned arg3, int arg4);
    void method9(int arg0, short arg1, unsigned arg2, int arg3, short arg4);
    void method10(float arg0, float arg1, float arg2, bool arg3, bool arg4);
    short method11(float arg0, unsigned arg1, short arg2, unsigned arg3, short arg4);
    int method12(bool arg0, int arg1, int arg2, bool arg3, float arg4);
    void method13(float arg0, float arg1, double arg2, short arg3, short arg4);
    void method14(short arg0, short arg1, double arg2, bool arg3, float arg4);
};

namespace ns_Class54
{
    void method0(double arg0, short arg1, short arg2, double arg3, short arg4);
    unsigned method1(short arg0, unsigned arg1, unsigned arg2, float arg3, double arg4);
    void method2(bool arg0, double arg1, float arg2, int arg3, bool arg4);
    void method3(bool arg0, float arg1, int arg2, float arg3, float arg4);
    void method4(short arg0, int arg1, short arg2, short arg3, float arg4);
    short method5(float arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    int method6(unsigned arg0, float arg1, int arg2, unsigned arg3, bool arg4);
    void method7(double arg0, float arg1, int arg2, double arg3, int arg4);
    unsigned method8(double arg0, double arg1, bool arg2, unsigned arg3, int arg4);
    void method9(int arg0, short arg1, unsigned arg2, int arg3, short arg4);
    void method10(float arg0, float arg1, float arg2, bool arg3, bool arg4);
    short method11(float arg0, unsigned arg1, short arg2, unsigned arg3, short arg4);
    int method12(bool arg0, int arg1, int arg2, bool arg3, float arg4);
    void method13(float arg0, float arg1, double arg2, short arg3, short arg4);
    void method14(short arg0, short arg1, double arg2, bool arg3, float arg4);
}
