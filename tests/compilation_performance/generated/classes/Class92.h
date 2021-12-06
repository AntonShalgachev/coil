#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class92
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, bool arg1, bool arg2, short arg3, int arg4);
    short method1(int arg0, double arg1, short arg2, bool arg3, short arg4);
    int method2(float arg0, int arg1, int arg2, bool arg3, float arg4);
    unsigned method3(unsigned arg0, short arg1, unsigned arg2, bool arg3, double arg4);
    float method4(float arg0, short arg1, float arg2, short arg3, unsigned arg4);
    bool method5(bool arg0, bool arg1, unsigned arg2, bool arg3, float arg4);
    bool method6(bool arg0, bool arg1, unsigned arg2, float arg3, int arg4);
    void method7(bool arg0, bool arg1, double arg2, unsigned arg3, unsigned arg4);
    double method8(float arg0, double arg1, int arg2, float arg3, int arg4);
    void method9(unsigned arg0, int arg1, int arg2, double arg3, short arg4);
    void method10(float arg0, unsigned arg1, bool arg2, bool arg3, double arg4);
    int method11(unsigned arg0, short arg1, int arg2, int arg3, short arg4);
    void method12(unsigned arg0, short arg1, bool arg2, float arg3, int arg4);
    float method13(int arg0, float arg1, float arg2, int arg3, float arg4);
    void method14(float arg0, bool arg1, unsigned arg2, float arg3, double arg4);
};

namespace ns_Class92
{
    unsigned method0(unsigned arg0, bool arg1, bool arg2, short arg3, int arg4);
    short method1(int arg0, double arg1, short arg2, bool arg3, short arg4);
    int method2(float arg0, int arg1, int arg2, bool arg3, float arg4);
    unsigned method3(unsigned arg0, short arg1, unsigned arg2, bool arg3, double arg4);
    float method4(float arg0, short arg1, float arg2, short arg3, unsigned arg4);
    bool method5(bool arg0, bool arg1, unsigned arg2, bool arg3, float arg4);
    bool method6(bool arg0, bool arg1, unsigned arg2, float arg3, int arg4);
    void method7(bool arg0, bool arg1, double arg2, unsigned arg3, unsigned arg4);
    double method8(float arg0, double arg1, int arg2, float arg3, int arg4);
    void method9(unsigned arg0, int arg1, int arg2, double arg3, short arg4);
    void method10(float arg0, unsigned arg1, bool arg2, bool arg3, double arg4);
    int method11(unsigned arg0, short arg1, int arg2, int arg3, short arg4);
    void method12(unsigned arg0, short arg1, bool arg2, float arg3, int arg4);
    float method13(int arg0, float arg1, float arg2, int arg3, float arg4);
    void method14(float arg0, bool arg1, unsigned arg2, float arg3, double arg4);
}
