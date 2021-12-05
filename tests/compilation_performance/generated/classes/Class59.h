#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class59
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(float arg0, short arg1, unsigned arg2, float arg3, int arg4);
    int method1(bool arg0, unsigned arg1, int arg2, float arg3, unsigned arg4);
    unsigned method2(int arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    float method3(float arg0, unsigned arg1, short arg2, float arg3, float arg4);
    int method4(unsigned arg0, float arg1, int arg2, unsigned arg3, unsigned arg4);
    float method5(bool arg0, double arg1, float arg2, double arg3, double arg4);
    void method6(int arg0, double arg1, short arg2, unsigned arg3, double arg4);
    float method7(short arg0, double arg1, float arg2, int arg3, unsigned arg4);
    short method8(short arg0, short arg1, short arg2, bool arg3, float arg4);
    bool method9(float arg0, float arg1, float arg2, bool arg3, float arg4);
    void method10(bool arg0, double arg1, double arg2, bool arg3, int arg4);
    double method11(float arg0, float arg1, double arg2, double arg3, unsigned arg4);
    void method12(unsigned arg0, bool arg1, float arg2, short arg3, short arg4);
    int method13(short arg0, bool arg1, int arg2, short arg3, double arg4);
    void method14(int arg0, short arg1, double arg2, bool arg3, short arg4);
};

namespace ns_Class59
{
    int method0(float arg0, short arg1, unsigned arg2, float arg3, int arg4);
    int method1(bool arg0, unsigned arg1, int arg2, float arg3, unsigned arg4);
    unsigned method2(int arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    float method3(float arg0, unsigned arg1, short arg2, float arg3, float arg4);
    int method4(unsigned arg0, float arg1, int arg2, unsigned arg3, unsigned arg4);
    float method5(bool arg0, double arg1, float arg2, double arg3, double arg4);
    void method6(int arg0, double arg1, short arg2, unsigned arg3, double arg4);
    float method7(short arg0, double arg1, float arg2, int arg3, unsigned arg4);
    short method8(short arg0, short arg1, short arg2, bool arg3, float arg4);
    bool method9(float arg0, float arg1, float arg2, bool arg3, float arg4);
    void method10(bool arg0, double arg1, double arg2, bool arg3, int arg4);
    double method11(float arg0, float arg1, double arg2, double arg3, unsigned arg4);
    void method12(unsigned arg0, bool arg1, float arg2, short arg3, short arg4);
    int method13(short arg0, bool arg1, int arg2, short arg3, double arg4);
    void method14(int arg0, short arg1, double arg2, bool arg3, short arg4);
}
