#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class51
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, bool arg1, unsigned arg2, int arg3, short arg4);
    float method1(float arg0, double arg1, unsigned arg2, bool arg3, int arg4);
    void method2(int arg0, int arg1, unsigned arg2, bool arg3, double arg4);
    void method3(bool arg0, bool arg1, int arg2, short arg3, double arg4);
    int method4(bool arg0, int arg1, double arg2, float arg3, int arg4);
    short method5(short arg0, int arg1, float arg2, short arg3, bool arg4);
    void method6(float arg0, short arg1, unsigned arg2, bool arg3, float arg4);
    unsigned method7(unsigned arg0, float arg1, short arg2, short arg3, float arg4);
    int method8(float arg0, double arg1, double arg2, double arg3, int arg4);
    void method9(unsigned arg0, unsigned arg1, float arg2, short arg3, int arg4);
    int method10(bool arg0, float arg1, short arg2, int arg3, int arg4);
    unsigned method11(float arg0, short arg1, unsigned arg2, unsigned arg3, short arg4);
    unsigned method12(unsigned arg0, short arg1, unsigned arg2, float arg3, float arg4);
    short method13(short arg0, double arg1, int arg2, short arg3, int arg4);
    void method14(int arg0, bool arg1, unsigned arg2, int arg3, int arg4);
};

namespace ns_Class51
{
    void method0(short arg0, bool arg1, unsigned arg2, int arg3, short arg4);
    float method1(float arg0, double arg1, unsigned arg2, bool arg3, int arg4);
    void method2(int arg0, int arg1, unsigned arg2, bool arg3, double arg4);
    void method3(bool arg0, bool arg1, int arg2, short arg3, double arg4);
    int method4(bool arg0, int arg1, double arg2, float arg3, int arg4);
    short method5(short arg0, int arg1, float arg2, short arg3, bool arg4);
    void method6(float arg0, short arg1, unsigned arg2, bool arg3, float arg4);
    unsigned method7(unsigned arg0, float arg1, short arg2, short arg3, float arg4);
    int method8(float arg0, double arg1, double arg2, double arg3, int arg4);
    void method9(unsigned arg0, unsigned arg1, float arg2, short arg3, int arg4);
    int method10(bool arg0, float arg1, short arg2, int arg3, int arg4);
    unsigned method11(float arg0, short arg1, unsigned arg2, unsigned arg3, short arg4);
    unsigned method12(unsigned arg0, short arg1, unsigned arg2, float arg3, float arg4);
    short method13(short arg0, double arg1, int arg2, short arg3, int arg4);
    void method14(int arg0, bool arg1, unsigned arg2, int arg3, int arg4);
}
