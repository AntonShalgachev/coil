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
    void method0(double arg0, double arg1, short arg2, int arg3, float arg4);
    void method1(short arg0, float arg1, float arg2, unsigned arg3, short arg4);
    void method2(unsigned arg0, bool arg1, bool arg2, int arg3, float arg4);
    void method3(bool arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    float method4(short arg0, double arg1, float arg2, float arg3, int arg4);
    bool method5(short arg0, unsigned arg1, bool arg2, bool arg3, bool arg4);
    short method6(short arg0, double arg1, unsigned arg2, float arg3, unsigned arg4);
    bool method7(bool arg0, double arg1, float arg2, float arg3, bool arg4);
    unsigned method8(unsigned arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method9(float arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    void method10(int arg0, int arg1, int arg2, double arg3, float arg4);
    void method11(float arg0, short arg1, short arg2, double arg3, float arg4);
    void method12(unsigned arg0, int arg1, short arg2, bool arg3, short arg4);
    void method13(unsigned arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    float method14(double arg0, float arg1, short arg2, double arg3, unsigned arg4);
};

namespace ns_Class52
{
    void method0(double arg0, double arg1, short arg2, int arg3, float arg4);
    void method1(short arg0, float arg1, float arg2, unsigned arg3, short arg4);
    void method2(unsigned arg0, bool arg1, bool arg2, int arg3, float arg4);
    void method3(bool arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    float method4(short arg0, double arg1, float arg2, float arg3, int arg4);
    bool method5(short arg0, unsigned arg1, bool arg2, bool arg3, bool arg4);
    short method6(short arg0, double arg1, unsigned arg2, float arg3, unsigned arg4);
    bool method7(bool arg0, double arg1, float arg2, float arg3, bool arg4);
    unsigned method8(unsigned arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method9(float arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    void method10(int arg0, int arg1, int arg2, double arg3, float arg4);
    void method11(float arg0, short arg1, short arg2, double arg3, float arg4);
    void method12(unsigned arg0, int arg1, short arg2, bool arg3, short arg4);
    void method13(unsigned arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    float method14(double arg0, float arg1, short arg2, double arg3, unsigned arg4);
}
