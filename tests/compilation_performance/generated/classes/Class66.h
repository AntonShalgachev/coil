#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class66
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(bool arg0, bool arg1, double arg2, double arg3, bool arg4);
    unsigned method1(double arg0, double arg1, unsigned arg2, unsigned arg3, double arg4);
    void method2(short arg0, float arg1, double arg2, unsigned arg3, bool arg4);
    unsigned method3(short arg0, unsigned arg1, double arg2, unsigned arg3, double arg4);
    void method4(unsigned arg0, unsigned arg1, float arg2, double arg3, float arg4);
    void method5(double arg0, bool arg1, int arg2, short arg3, bool arg4);
    bool method6(float arg0, short arg1, float arg2, double arg3, bool arg4);
    float method7(float arg0, float arg1, bool arg2, bool arg3, short arg4);
    void method8(unsigned arg0, unsigned arg1, unsigned arg2, double arg3, int arg4);
    void method9(unsigned arg0, bool arg1, unsigned arg2, unsigned arg3, int arg4);
    void method10(int arg0, unsigned arg1, bool arg2, float arg3, int arg4);
    void method11(bool arg0, unsigned arg1, bool arg2, bool arg3, double arg4);
    void method12(short arg0, unsigned arg1, double arg2, bool arg3, int arg4);
    void method13(unsigned arg0, double arg1, short arg2, double arg3, short arg4);
    void method14(float arg0, int arg1, unsigned arg2, short arg3, unsigned arg4);
};

namespace ns_Class66
{
    bool method0(bool arg0, bool arg1, double arg2, double arg3, bool arg4);
    unsigned method1(double arg0, double arg1, unsigned arg2, unsigned arg3, double arg4);
    void method2(short arg0, float arg1, double arg2, unsigned arg3, bool arg4);
    unsigned method3(short arg0, unsigned arg1, double arg2, unsigned arg3, double arg4);
    void method4(unsigned arg0, unsigned arg1, float arg2, double arg3, float arg4);
    void method5(double arg0, bool arg1, int arg2, short arg3, bool arg4);
    bool method6(float arg0, short arg1, float arg2, double arg3, bool arg4);
    float method7(float arg0, float arg1, bool arg2, bool arg3, short arg4);
    void method8(unsigned arg0, unsigned arg1, unsigned arg2, double arg3, int arg4);
    void method9(unsigned arg0, bool arg1, unsigned arg2, unsigned arg3, int arg4);
    void method10(int arg0, unsigned arg1, bool arg2, float arg3, int arg4);
    void method11(bool arg0, unsigned arg1, bool arg2, bool arg3, double arg4);
    void method12(short arg0, unsigned arg1, double arg2, bool arg3, int arg4);
    void method13(unsigned arg0, double arg1, short arg2, double arg3, short arg4);
    void method14(float arg0, int arg1, unsigned arg2, short arg3, unsigned arg4);
}
