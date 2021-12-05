#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class36
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, short arg1, int arg2, bool arg3, double arg4);
    double method1(double arg0, unsigned arg1, short arg2, double arg3, bool arg4);
    int method2(int arg0, int arg1, float arg2, bool arg3, bool arg4);
    void method3(unsigned arg0, int arg1, int arg2, short arg3, double arg4);
    short method4(float arg0, unsigned arg1, short arg2, int arg3, double arg4);
    void method5(short arg0, double arg1, short arg2, double arg3, bool arg4);
    int method6(short arg0, short arg1, int arg2, double arg3, int arg4);
    bool method7(double arg0, double arg1, float arg2, unsigned arg3, bool arg4);
    int method8(short arg0, short arg1, int arg2, float arg3, int arg4);
    unsigned method9(unsigned arg0, short arg1, unsigned arg2, double arg3, int arg4);
    void method10(float arg0, bool arg1, short arg2, unsigned arg3, bool arg4);
    unsigned method11(unsigned arg0, float arg1, short arg2, float arg3, double arg4);
    int method12(int arg0, bool arg1, int arg2, short arg3, bool arg4);
    void method13(bool arg0, short arg1, unsigned arg2, int arg3, float arg4);
    int method14(int arg0, int arg1, unsigned arg2, bool arg3, unsigned arg4);
};

namespace ns_Class36
{
    void method0(double arg0, short arg1, int arg2, bool arg3, double arg4);
    double method1(double arg0, unsigned arg1, short arg2, double arg3, bool arg4);
    int method2(int arg0, int arg1, float arg2, bool arg3, bool arg4);
    void method3(unsigned arg0, int arg1, int arg2, short arg3, double arg4);
    short method4(float arg0, unsigned arg1, short arg2, int arg3, double arg4);
    void method5(short arg0, double arg1, short arg2, double arg3, bool arg4);
    int method6(short arg0, short arg1, int arg2, double arg3, int arg4);
    bool method7(double arg0, double arg1, float arg2, unsigned arg3, bool arg4);
    int method8(short arg0, short arg1, int arg2, float arg3, int arg4);
    unsigned method9(unsigned arg0, short arg1, unsigned arg2, double arg3, int arg4);
    void method10(float arg0, bool arg1, short arg2, unsigned arg3, bool arg4);
    unsigned method11(unsigned arg0, float arg1, short arg2, float arg3, double arg4);
    int method12(int arg0, bool arg1, int arg2, short arg3, bool arg4);
    void method13(bool arg0, short arg1, unsigned arg2, int arg3, float arg4);
    int method14(int arg0, int arg1, unsigned arg2, bool arg3, unsigned arg4);
}
