#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class53
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(bool arg0, short arg1, unsigned arg2, double arg3, int arg4);
    void method1(short arg0, short arg1, double arg2, float arg3, int arg4);
    void method2(float arg0, short arg1, float arg2, float arg3, float arg4);
    int method3(bool arg0, int arg1, int arg2, short arg3, int arg4);
    bool method4(float arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    void method5(float arg0, float arg1, int arg2, float arg3, short arg4);
    int method6(bool arg0, float arg1, short arg2, bool arg3, int arg4);
    void method7(short arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    void method8(bool arg0, double arg1, unsigned arg2, double arg3, int arg4);
    short method9(float arg0, short arg1, unsigned arg2, double arg3, bool arg4);
    float method10(float arg0, double arg1, unsigned arg2, short arg3, short arg4);
    void method11(unsigned arg0, float arg1, short arg2, float arg3, short arg4);
    bool method12(short arg0, bool arg1, short arg2, bool arg3, double arg4);
    void method13(unsigned arg0, float arg1, float arg2, double arg3, float arg4);
    double method14(short arg0, double arg1, double arg2, double arg3, double arg4);
};

namespace ns_Class53
{
    void method0(bool arg0, short arg1, unsigned arg2, double arg3, int arg4);
    void method1(short arg0, short arg1, double arg2, float arg3, int arg4);
    void method2(float arg0, short arg1, float arg2, float arg3, float arg4);
    int method3(bool arg0, int arg1, int arg2, short arg3, int arg4);
    bool method4(float arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    void method5(float arg0, float arg1, int arg2, float arg3, short arg4);
    int method6(bool arg0, float arg1, short arg2, bool arg3, int arg4);
    void method7(short arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    void method8(bool arg0, double arg1, unsigned arg2, double arg3, int arg4);
    short method9(float arg0, short arg1, unsigned arg2, double arg3, bool arg4);
    float method10(float arg0, double arg1, unsigned arg2, short arg3, short arg4);
    void method11(unsigned arg0, float arg1, short arg2, float arg3, short arg4);
    bool method12(short arg0, bool arg1, short arg2, bool arg3, double arg4);
    void method13(unsigned arg0, float arg1, float arg2, double arg3, float arg4);
    double method14(short arg0, double arg1, double arg2, double arg3, double arg4);
}
