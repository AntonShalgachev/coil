#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class84
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(int arg0, float arg1, int arg2, bool arg3, double arg4);
    float method1(bool arg0, float arg1, float arg2, float arg3, bool arg4);
    void method2(short arg0, float arg1, int arg2, double arg3, double arg4);
    unsigned method3(int arg0, unsigned arg1, unsigned arg2, double arg3, short arg4);
    void method4(double arg0, int arg1, short arg2, int arg3, unsigned arg4);
    void method5(double arg0, double arg1, int arg2, short arg3, int arg4);
    void method6(float arg0, float arg1, unsigned arg2, unsigned arg3, short arg4);
    unsigned method7(unsigned arg0, unsigned arg1, int arg2, short arg3, unsigned arg4);
    void method8(short arg0, double arg1, unsigned arg2, float arg3, double arg4);
    int method9(short arg0, short arg1, int arg2, bool arg3, int arg4);
    bool method10(short arg0, float arg1, int arg2, bool arg3, unsigned arg4);
    void method11(unsigned arg0, unsigned arg1, double arg2, bool arg3, unsigned arg4);
    double method12(unsigned arg0, double arg1, short arg2, double arg3, int arg4);
    void method13(double arg0, float arg1, short arg2, float arg3, int arg4);
    bool method14(double arg0, bool arg1, short arg2, float arg3, bool arg4);
};

namespace ns_Class84
{
    int method0(int arg0, float arg1, int arg2, bool arg3, double arg4);
    float method1(bool arg0, float arg1, float arg2, float arg3, bool arg4);
    void method2(short arg0, float arg1, int arg2, double arg3, double arg4);
    unsigned method3(int arg0, unsigned arg1, unsigned arg2, double arg3, short arg4);
    void method4(double arg0, int arg1, short arg2, int arg3, unsigned arg4);
    void method5(double arg0, double arg1, int arg2, short arg3, int arg4);
    void method6(float arg0, float arg1, unsigned arg2, unsigned arg3, short arg4);
    unsigned method7(unsigned arg0, unsigned arg1, int arg2, short arg3, unsigned arg4);
    void method8(short arg0, double arg1, unsigned arg2, float arg3, double arg4);
    int method9(short arg0, short arg1, int arg2, bool arg3, int arg4);
    bool method10(short arg0, float arg1, int arg2, bool arg3, unsigned arg4);
    void method11(unsigned arg0, unsigned arg1, double arg2, bool arg3, unsigned arg4);
    double method12(unsigned arg0, double arg1, short arg2, double arg3, int arg4);
    void method13(double arg0, float arg1, short arg2, float arg3, int arg4);
    bool method14(double arg0, bool arg1, short arg2, float arg3, bool arg4);
}
