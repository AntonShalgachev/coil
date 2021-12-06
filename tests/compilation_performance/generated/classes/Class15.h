#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class15
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(bool arg0, short arg1, float arg2, bool arg3, unsigned arg4);
    float method1(bool arg0, short arg1, double arg2, short arg3, float arg4);
    short method2(bool arg0, int arg1, short arg2, short arg3, unsigned arg4);
    void method3(double arg0, int arg1, short arg2, double arg3, unsigned arg4);
    void method4(double arg0, short arg1, float arg2, int arg3, double arg4);
    double method5(float arg0, bool arg1, double arg2, float arg3, double arg4);
    void method6(bool arg0, bool arg1, short arg2, double arg3, bool arg4);
    int method7(int arg0, float arg1, bool arg2, bool arg3, short arg4);
    int method8(int arg0, float arg1, bool arg2, int arg3, unsigned arg4);
    bool method9(short arg0, bool arg1, bool arg2, float arg3, short arg4);
    void method10(unsigned arg0, double arg1, float arg2, bool arg3, unsigned arg4);
    unsigned method11(unsigned arg0, float arg1, unsigned arg2, int arg3, short arg4);
    void method12(unsigned arg0, int arg1, double arg2, double arg3, int arg4);
    unsigned method13(double arg0, short arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method14(unsigned arg0, unsigned arg1, float arg2, bool arg3, short arg4);
};

namespace ns_Class15
{
    void method0(bool arg0, short arg1, float arg2, bool arg3, unsigned arg4);
    float method1(bool arg0, short arg1, double arg2, short arg3, float arg4);
    short method2(bool arg0, int arg1, short arg2, short arg3, unsigned arg4);
    void method3(double arg0, int arg1, short arg2, double arg3, unsigned arg4);
    void method4(double arg0, short arg1, float arg2, int arg3, double arg4);
    double method5(float arg0, bool arg1, double arg2, float arg3, double arg4);
    void method6(bool arg0, bool arg1, short arg2, double arg3, bool arg4);
    int method7(int arg0, float arg1, bool arg2, bool arg3, short arg4);
    int method8(int arg0, float arg1, bool arg2, int arg3, unsigned arg4);
    bool method9(short arg0, bool arg1, bool arg2, float arg3, short arg4);
    void method10(unsigned arg0, double arg1, float arg2, bool arg3, unsigned arg4);
    unsigned method11(unsigned arg0, float arg1, unsigned arg2, int arg3, short arg4);
    void method12(unsigned arg0, int arg1, double arg2, double arg3, int arg4);
    unsigned method13(double arg0, short arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method14(unsigned arg0, unsigned arg1, float arg2, bool arg3, short arg4);
}
