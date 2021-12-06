#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class96
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(double arg0, unsigned arg1, float arg2, bool arg3, double arg4);
    void method1(float arg0, double arg1, float arg2, short arg3, bool arg4);
    bool method2(bool arg0, bool arg1, unsigned arg2, double arg3, unsigned arg4);
    void method3(double arg0, int arg1, int arg2, float arg3, int arg4);
    bool method4(int arg0, double arg1, unsigned arg2, bool arg3, int arg4);
    double method5(double arg0, double arg1, double arg2, unsigned arg3, int arg4);
    int method6(unsigned arg0, int arg1, float arg2, unsigned arg3, float arg4);
    void method7(bool arg0, short arg1, double arg2, bool arg3, float arg4);
    short method8(float arg0, short arg1, bool arg2, double arg3, unsigned arg4);
    void method9(float arg0, unsigned arg1, bool arg2, bool arg3, float arg4);
    double method10(unsigned arg0, int arg1, double arg2, short arg3, unsigned arg4);
    bool method11(bool arg0, float arg1, bool arg2, short arg3, double arg4);
    void method12(unsigned arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    void method13(short arg0, float arg1, int arg2, unsigned arg3, float arg4);
    int method14(int arg0, int arg1, double arg2, int arg3, bool arg4);
};

namespace ns_Class96
{
    float method0(double arg0, unsigned arg1, float arg2, bool arg3, double arg4);
    void method1(float arg0, double arg1, float arg2, short arg3, bool arg4);
    bool method2(bool arg0, bool arg1, unsigned arg2, double arg3, unsigned arg4);
    void method3(double arg0, int arg1, int arg2, float arg3, int arg4);
    bool method4(int arg0, double arg1, unsigned arg2, bool arg3, int arg4);
    double method5(double arg0, double arg1, double arg2, unsigned arg3, int arg4);
    int method6(unsigned arg0, int arg1, float arg2, unsigned arg3, float arg4);
    void method7(bool arg0, short arg1, double arg2, bool arg3, float arg4);
    short method8(float arg0, short arg1, bool arg2, double arg3, unsigned arg4);
    void method9(float arg0, unsigned arg1, bool arg2, bool arg3, float arg4);
    double method10(unsigned arg0, int arg1, double arg2, short arg3, unsigned arg4);
    bool method11(bool arg0, float arg1, bool arg2, short arg3, double arg4);
    void method12(unsigned arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    void method13(short arg0, float arg1, int arg2, unsigned arg3, float arg4);
    int method14(int arg0, int arg1, double arg2, int arg3, bool arg4);
}
