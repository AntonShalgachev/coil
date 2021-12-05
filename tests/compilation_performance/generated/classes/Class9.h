#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class9
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, double arg1, int arg2, bool arg3, int arg4);
    void method1(int arg0, short arg1, short arg2, int arg3, unsigned arg4);
    void method2(float arg0, short arg1, int arg2, int arg3, unsigned arg4);
    void method3(short arg0, unsigned arg1, bool arg2, bool arg3, int arg4);
    void method4(bool arg0, bool arg1, short arg2, short arg3, float arg4);
    unsigned method5(int arg0, unsigned arg1, unsigned arg2, bool arg3, bool arg4);
    void method6(unsigned arg0, int arg1, int arg2, bool arg3, bool arg4);
    void method7(bool arg0, int arg1, int arg2, unsigned arg3, unsigned arg4);
    void method8(unsigned arg0, unsigned arg1, double arg2, int arg3, bool arg4);
    float method9(int arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    void method10(float arg0, float arg1, short arg2, double arg3, short arg4);
    void method11(short arg0, double arg1, float arg2, bool arg3, int arg4);
    void method12(float arg0, unsigned arg1, int arg2, short arg3, double arg4);
    void method13(int arg0, short arg1, short arg2, int arg3, bool arg4);
    void method14(short arg0, float arg1, float arg2, bool arg3, short arg4);
};

namespace ns_Class9
{
    void method0(unsigned arg0, double arg1, int arg2, bool arg3, int arg4);
    void method1(int arg0, short arg1, short arg2, int arg3, unsigned arg4);
    void method2(float arg0, short arg1, int arg2, int arg3, unsigned arg4);
    void method3(short arg0, unsigned arg1, bool arg2, bool arg3, int arg4);
    void method4(bool arg0, bool arg1, short arg2, short arg3, float arg4);
    unsigned method5(int arg0, unsigned arg1, unsigned arg2, bool arg3, bool arg4);
    void method6(unsigned arg0, int arg1, int arg2, bool arg3, bool arg4);
    void method7(bool arg0, int arg1, int arg2, unsigned arg3, unsigned arg4);
    void method8(unsigned arg0, unsigned arg1, double arg2, int arg3, bool arg4);
    float method9(int arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    void method10(float arg0, float arg1, short arg2, double arg3, short arg4);
    void method11(short arg0, double arg1, float arg2, bool arg3, int arg4);
    void method12(float arg0, unsigned arg1, int arg2, short arg3, double arg4);
    void method13(int arg0, short arg1, short arg2, int arg3, bool arg4);
    void method14(short arg0, float arg1, float arg2, bool arg3, short arg4);
}
