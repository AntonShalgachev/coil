#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class40
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(float arg0, int arg1, bool arg2, bool arg3, short arg4);
    float method1(double arg0, float arg1, float arg2, int arg3, short arg4);
    short method2(bool arg0, int arg1, short arg2, float arg3, double arg4);
    short method3(bool arg0, bool arg1, int arg2, bool arg3, short arg4);
    float method4(unsigned arg0, float arg1, unsigned arg2, float arg3, short arg4);
    void method5(unsigned arg0, double arg1, unsigned arg2, short arg3, float arg4);
    void method6(int arg0, short arg1, unsigned arg2, bool arg3, bool arg4);
    void method7(int arg0, int arg1, float arg2, float arg3, short arg4);
    double method8(float arg0, double arg1, unsigned arg2, float arg3, short arg4);
    double method9(double arg0, short arg1, float arg2, int arg3, int arg4);
    short method10(float arg0, short arg1, bool arg2, double arg3, short arg4);
    int method11(float arg0, short arg1, double arg2, int arg3, unsigned arg4);
    int method12(int arg0, unsigned arg1, unsigned arg2, bool arg3, short arg4);
    unsigned method13(bool arg0, double arg1, unsigned arg2, double arg3, double arg4);
    void method14(double arg0, double arg1, bool arg2, short arg3, int arg4);
};

namespace ns_Class40
{
    bool method0(float arg0, int arg1, bool arg2, bool arg3, short arg4);
    float method1(double arg0, float arg1, float arg2, int arg3, short arg4);
    short method2(bool arg0, int arg1, short arg2, float arg3, double arg4);
    short method3(bool arg0, bool arg1, int arg2, bool arg3, short arg4);
    float method4(unsigned arg0, float arg1, unsigned arg2, float arg3, short arg4);
    void method5(unsigned arg0, double arg1, unsigned arg2, short arg3, float arg4);
    void method6(int arg0, short arg1, unsigned arg2, bool arg3, bool arg4);
    void method7(int arg0, int arg1, float arg2, float arg3, short arg4);
    double method8(float arg0, double arg1, unsigned arg2, float arg3, short arg4);
    double method9(double arg0, short arg1, float arg2, int arg3, int arg4);
    short method10(float arg0, short arg1, bool arg2, double arg3, short arg4);
    int method11(float arg0, short arg1, double arg2, int arg3, unsigned arg4);
    int method12(int arg0, unsigned arg1, unsigned arg2, bool arg3, short arg4);
    unsigned method13(bool arg0, double arg1, unsigned arg2, double arg3, double arg4);
    void method14(double arg0, double arg1, bool arg2, short arg3, int arg4);
}
