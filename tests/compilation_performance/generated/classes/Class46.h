#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class46
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, float arg1, double arg2, unsigned arg3, float arg4);
    int method1(double arg0, float arg1, int arg2, unsigned arg3, short arg4);
    unsigned method2(double arg0, double arg1, unsigned arg2, short arg3, float arg4);
    void method3(short arg0, bool arg1, short arg2, unsigned arg3, short arg4);
    short method4(float arg0, short arg1, float arg2, bool arg3, bool arg4);
    void method5(short arg0, double arg1, double arg2, int arg3, short arg4);
    void method6(short arg0, float arg1, double arg2, int arg3, short arg4);
    unsigned method7(unsigned arg0, unsigned arg1, int arg2, unsigned arg3, int arg4);
    bool method8(short arg0, short arg1, bool arg2, bool arg3, bool arg4);
    unsigned method9(unsigned arg0, unsigned arg1, int arg2, int arg3, short arg4);
    void method10(short arg0, bool arg1, unsigned arg2, double arg3, int arg4);
    void method11(short arg0, bool arg1, bool arg2, short arg3, int arg4);
    void method12(double arg0, short arg1, float arg2, short arg3, bool arg4);
    bool method13(bool arg0, float arg1, bool arg2, double arg3, bool arg4);
    void method14(double arg0, short arg1, bool arg2, int arg3, bool arg4);
};

namespace ns_Class46
{
    void method0(float arg0, float arg1, double arg2, unsigned arg3, float arg4);
    int method1(double arg0, float arg1, int arg2, unsigned arg3, short arg4);
    unsigned method2(double arg0, double arg1, unsigned arg2, short arg3, float arg4);
    void method3(short arg0, bool arg1, short arg2, unsigned arg3, short arg4);
    short method4(float arg0, short arg1, float arg2, bool arg3, bool arg4);
    void method5(short arg0, double arg1, double arg2, int arg3, short arg4);
    void method6(short arg0, float arg1, double arg2, int arg3, short arg4);
    unsigned method7(unsigned arg0, unsigned arg1, int arg2, unsigned arg3, int arg4);
    bool method8(short arg0, short arg1, bool arg2, bool arg3, bool arg4);
    unsigned method9(unsigned arg0, unsigned arg1, int arg2, int arg3, short arg4);
    void method10(short arg0, bool arg1, unsigned arg2, double arg3, int arg4);
    void method11(short arg0, bool arg1, bool arg2, short arg3, int arg4);
    void method12(double arg0, short arg1, float arg2, short arg3, bool arg4);
    bool method13(bool arg0, float arg1, bool arg2, double arg3, bool arg4);
    void method14(double arg0, short arg1, bool arg2, int arg3, bool arg4);
}
