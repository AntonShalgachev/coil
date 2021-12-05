#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class21
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(bool arg0, int arg1, short arg2, unsigned arg3, double arg4);
    void method1(double arg0, short arg1, double arg2, int arg3, bool arg4);
    void method2(float arg0, double arg1, double arg2, float arg3, bool arg4);
    int method3(bool arg0, unsigned arg1, float arg2, int arg3, bool arg4);
    double method4(double arg0, double arg1, unsigned arg2, int arg3, unsigned arg4);
    float method5(short arg0, float arg1, int arg2, int arg3, short arg4);
    void method6(short arg0, float arg1, short arg2, short arg3, short arg4);
    bool method7(float arg0, bool arg1, int arg2, unsigned arg3, bool arg4);
    void method8(double arg0, unsigned arg1, float arg2, float arg3, bool arg4);
    double method9(double arg0, double arg1, double arg2, double arg3, float arg4);
    bool method10(bool arg0, int arg1, short arg2, float arg3, float arg4);
    void method11(float arg0, float arg1, double arg2, int arg3, double arg4);
    unsigned method12(double arg0, int arg1, bool arg2, float arg3, unsigned arg4);
    void method13(int arg0, bool arg1, bool arg2, double arg3, bool arg4);
    int method14(int arg0, int arg1, float arg2, double arg3, int arg4);
};

namespace ns_Class21
{
    unsigned method0(bool arg0, int arg1, short arg2, unsigned arg3, double arg4);
    void method1(double arg0, short arg1, double arg2, int arg3, bool arg4);
    void method2(float arg0, double arg1, double arg2, float arg3, bool arg4);
    int method3(bool arg0, unsigned arg1, float arg2, int arg3, bool arg4);
    double method4(double arg0, double arg1, unsigned arg2, int arg3, unsigned arg4);
    float method5(short arg0, float arg1, int arg2, int arg3, short arg4);
    void method6(short arg0, float arg1, short arg2, short arg3, short arg4);
    bool method7(float arg0, bool arg1, int arg2, unsigned arg3, bool arg4);
    void method8(double arg0, unsigned arg1, float arg2, float arg3, bool arg4);
    double method9(double arg0, double arg1, double arg2, double arg3, float arg4);
    bool method10(bool arg0, int arg1, short arg2, float arg3, float arg4);
    void method11(float arg0, float arg1, double arg2, int arg3, double arg4);
    unsigned method12(double arg0, int arg1, bool arg2, float arg3, unsigned arg4);
    void method13(int arg0, bool arg1, bool arg2, double arg3, bool arg4);
    int method14(int arg0, int arg1, float arg2, double arg3, int arg4);
}
