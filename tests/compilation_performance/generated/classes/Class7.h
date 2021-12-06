#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class7
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, unsigned arg1, unsigned arg2, short arg3, int arg4);
    void method1(float arg0, bool arg1, double arg2, short arg3, float arg4);
    int method2(float arg0, unsigned arg1, short arg2, short arg3, int arg4);
    void method3(int arg0, short arg1, unsigned arg2, int arg3, unsigned arg4);
    void method4(unsigned arg0, bool arg1, short arg2, double arg3, int arg4);
    void method5(int arg0, unsigned arg1, double arg2, double arg3, float arg4);
    bool method6(int arg0, bool arg1, short arg2, unsigned arg3, bool arg4);
    void method7(float arg0, short arg1, unsigned arg2, float arg3, double arg4);
    void method8(unsigned arg0, short arg1, float arg2, short arg3, unsigned arg4);
    void method9(float arg0, float arg1, unsigned arg2, double arg3, double arg4);
    float method10(bool arg0, float arg1, unsigned arg2, int arg3, double arg4);
    void method11(unsigned arg0, short arg1, int arg2, double arg3, bool arg4);
    float method12(int arg0, bool arg1, int arg2, float arg3, float arg4);
    unsigned method13(unsigned arg0, int arg1, float arg2, unsigned arg3, short arg4);
    unsigned method14(unsigned arg0, float arg1, bool arg2, unsigned arg3, bool arg4);
};

namespace ns_Class7
{
    void method0(int arg0, unsigned arg1, unsigned arg2, short arg3, int arg4);
    void method1(float arg0, bool arg1, double arg2, short arg3, float arg4);
    int method2(float arg0, unsigned arg1, short arg2, short arg3, int arg4);
    void method3(int arg0, short arg1, unsigned arg2, int arg3, unsigned arg4);
    void method4(unsigned arg0, bool arg1, short arg2, double arg3, int arg4);
    void method5(int arg0, unsigned arg1, double arg2, double arg3, float arg4);
    bool method6(int arg0, bool arg1, short arg2, unsigned arg3, bool arg4);
    void method7(float arg0, short arg1, unsigned arg2, float arg3, double arg4);
    void method8(unsigned arg0, short arg1, float arg2, short arg3, unsigned arg4);
    void method9(float arg0, float arg1, unsigned arg2, double arg3, double arg4);
    float method10(bool arg0, float arg1, unsigned arg2, int arg3, double arg4);
    void method11(unsigned arg0, short arg1, int arg2, double arg3, bool arg4);
    float method12(int arg0, bool arg1, int arg2, float arg3, float arg4);
    unsigned method13(unsigned arg0, int arg1, float arg2, unsigned arg3, short arg4);
    unsigned method14(unsigned arg0, float arg1, bool arg2, unsigned arg3, bool arg4);
}
