#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class65
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(double arg0, bool arg1, int arg2, int arg3, double arg4);
    void method1(float arg0, double arg1, unsigned arg2, int arg3, unsigned arg4);
    int method2(unsigned arg0, int arg1, unsigned arg2, float arg3, short arg4);
    short method3(int arg0, unsigned arg1, double arg2, short arg3, unsigned arg4);
    bool method4(unsigned arg0, bool arg1, float arg2, int arg3, short arg4);
    int method5(int arg0, double arg1, bool arg2, bool arg3, int arg4);
    void method6(bool arg0, int arg1, bool arg2, bool arg3, int arg4);
    float method7(float arg0, int arg1, float arg2, float arg3, float arg4);
    void method8(int arg0, double arg1, float arg2, int arg3, unsigned arg4);
    void method9(float arg0, bool arg1, float arg2, bool arg3, unsigned arg4);
    short method10(int arg0, short arg1, double arg2, double arg3, double arg4);
    void method11(bool arg0, double arg1, short arg2, float arg3, double arg4);
    void method12(unsigned arg0, unsigned arg1, double arg2, int arg3, float arg4);
    short method13(unsigned arg0, unsigned arg1, unsigned arg2, short arg3, float arg4);
    int method14(bool arg0, short arg1, int arg2, float arg3, float arg4);
};

namespace ns_Class65
{
    double method0(double arg0, bool arg1, int arg2, int arg3, double arg4);
    void method1(float arg0, double arg1, unsigned arg2, int arg3, unsigned arg4);
    int method2(unsigned arg0, int arg1, unsigned arg2, float arg3, short arg4);
    short method3(int arg0, unsigned arg1, double arg2, short arg3, unsigned arg4);
    bool method4(unsigned arg0, bool arg1, float arg2, int arg3, short arg4);
    int method5(int arg0, double arg1, bool arg2, bool arg3, int arg4);
    void method6(bool arg0, int arg1, bool arg2, bool arg3, int arg4);
    float method7(float arg0, int arg1, float arg2, float arg3, float arg4);
    void method8(int arg0, double arg1, float arg2, int arg3, unsigned arg4);
    void method9(float arg0, bool arg1, float arg2, bool arg3, unsigned arg4);
    short method10(int arg0, short arg1, double arg2, double arg3, double arg4);
    void method11(bool arg0, double arg1, short arg2, float arg3, double arg4);
    void method12(unsigned arg0, unsigned arg1, double arg2, int arg3, float arg4);
    short method13(unsigned arg0, unsigned arg1, unsigned arg2, short arg3, float arg4);
    int method14(bool arg0, short arg1, int arg2, float arg3, float arg4);
}
