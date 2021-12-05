#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class8
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, unsigned arg1, int arg2, int arg3, float arg4);
    void method1(unsigned arg0, double arg1, double arg2, float arg3, int arg4);
    void method2(bool arg0, float arg1, unsigned arg2, int arg3, bool arg4);
    unsigned method3(double arg0, double arg1, unsigned arg2, float arg3, unsigned arg4);
    void method4(float arg0, double arg1, short arg2, short arg3, bool arg4);
    unsigned method5(unsigned arg0, unsigned arg1, double arg2, unsigned arg3, short arg4);
    void method6(bool arg0, int arg1, int arg2, unsigned arg3, float arg4);
    int method7(double arg0, int arg1, unsigned arg2, float arg3, double arg4);
    int method8(int arg0, int arg1, float arg2, short arg3, unsigned arg4);
    float method9(int arg0, float arg1, float arg2, bool arg3, unsigned arg4);
    bool method10(float arg0, bool arg1, double arg2, short arg3, float arg4);
    void method11(unsigned arg0, float arg1, unsigned arg2, unsigned arg3, double arg4);
    int method12(unsigned arg0, int arg1, double arg2, bool arg3, bool arg4);
    unsigned method13(float arg0, unsigned arg1, int arg2, unsigned arg3, int arg4);
    bool method14(bool arg0, float arg1, float arg2, bool arg3, short arg4);
};

namespace ns_Class8
{
    void method0(unsigned arg0, unsigned arg1, int arg2, int arg3, float arg4);
    void method1(unsigned arg0, double arg1, double arg2, float arg3, int arg4);
    void method2(bool arg0, float arg1, unsigned arg2, int arg3, bool arg4);
    unsigned method3(double arg0, double arg1, unsigned arg2, float arg3, unsigned arg4);
    void method4(float arg0, double arg1, short arg2, short arg3, bool arg4);
    unsigned method5(unsigned arg0, unsigned arg1, double arg2, unsigned arg3, short arg4);
    void method6(bool arg0, int arg1, int arg2, unsigned arg3, float arg4);
    int method7(double arg0, int arg1, unsigned arg2, float arg3, double arg4);
    int method8(int arg0, int arg1, float arg2, short arg3, unsigned arg4);
    float method9(int arg0, float arg1, float arg2, bool arg3, unsigned arg4);
    bool method10(float arg0, bool arg1, double arg2, short arg3, float arg4);
    void method11(unsigned arg0, float arg1, unsigned arg2, unsigned arg3, double arg4);
    int method12(unsigned arg0, int arg1, double arg2, bool arg3, bool arg4);
    unsigned method13(float arg0, unsigned arg1, int arg2, unsigned arg3, int arg4);
    bool method14(bool arg0, float arg1, float arg2, bool arg3, short arg4);
}
