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
    void method0(unsigned arg0, unsigned arg1, double arg2, unsigned arg3, short arg4);
    void method1(int arg0, bool arg1, int arg2, float arg3, bool arg4);
    void method2(short arg0, unsigned arg1, float arg2, bool arg3, short arg4);
    unsigned method3(unsigned arg0, short arg1, short arg2, double arg3, int arg4);
    bool method4(int arg0, float arg1, double arg2, bool arg3, short arg4);
    void method5(unsigned arg0, float arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method6(int arg0, double arg1, double arg2, unsigned arg3, bool arg4);
    int method7(int arg0, short arg1, double arg2, bool arg3, int arg4);
    void method8(short arg0, bool arg1, int arg2, int arg3, float arg4);
    void method9(double arg0, float arg1, bool arg2, short arg3, int arg4);
    unsigned method10(unsigned arg0, bool arg1, unsigned arg2, bool arg3, double arg4);
    float method11(double arg0, float arg1, bool arg2, float arg3, float arg4);
    double method12(short arg0, unsigned arg1, double arg2, bool arg3, int arg4);
    int method13(int arg0, bool arg1, short arg2, unsigned arg3, bool arg4);
    short method14(float arg0, bool arg1, unsigned arg2, short arg3, unsigned arg4);
};

namespace ns_Class92
{
    void method0(unsigned arg0, unsigned arg1, double arg2, unsigned arg3, short arg4);
    void method1(int arg0, bool arg1, int arg2, float arg3, bool arg4);
    void method2(short arg0, unsigned arg1, float arg2, bool arg3, short arg4);
    unsigned method3(unsigned arg0, short arg1, short arg2, double arg3, int arg4);
    bool method4(int arg0, float arg1, double arg2, bool arg3, short arg4);
    void method5(unsigned arg0, float arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method6(int arg0, double arg1, double arg2, unsigned arg3, bool arg4);
    int method7(int arg0, short arg1, double arg2, bool arg3, int arg4);
    void method8(short arg0, bool arg1, int arg2, int arg3, float arg4);
    void method9(double arg0, float arg1, bool arg2, short arg3, int arg4);
    unsigned method10(unsigned arg0, bool arg1, unsigned arg2, bool arg3, double arg4);
    float method11(double arg0, float arg1, bool arg2, float arg3, float arg4);
    double method12(short arg0, unsigned arg1, double arg2, bool arg3, int arg4);
    int method13(int arg0, bool arg1, short arg2, unsigned arg3, bool arg4);
    short method14(float arg0, bool arg1, unsigned arg2, short arg3, unsigned arg4);
}
