#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class72
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(float arg0, float arg1, int arg2, bool arg3, short arg4);
    void method1(float arg0, unsigned arg1, short arg2, float arg3, float arg4);
    void method2(float arg0, int arg1, int arg2, int arg3, bool arg4);
    void method3(double arg0, double arg1, float arg2, bool arg3, float arg4);
    double method4(int arg0, float arg1, double arg2, unsigned arg3, int arg4);
    void method5(double arg0, float arg1, bool arg2, short arg3, unsigned arg4);
    bool method6(bool arg0, int arg1, bool arg2, double arg3, short arg4);
    short method7(bool arg0, short arg1, unsigned arg2, float arg3, double arg4);
    unsigned method8(unsigned arg0, float arg1, int arg2, bool arg3, short arg4);
    void method9(short arg0, int arg1, float arg2, short arg3, float arg4);
    double method10(float arg0, unsigned arg1, short arg2, double arg3, int arg4);
    float method11(float arg0, double arg1, float arg2, unsigned arg3, int arg4);
    unsigned method12(float arg0, short arg1, short arg2, double arg3, unsigned arg4);
    float method13(double arg0, bool arg1, int arg2, float arg3, bool arg4);
    float method14(float arg0, bool arg1, float arg2, bool arg3, int arg4);
};

namespace ns_Class72
{
    bool method0(float arg0, float arg1, int arg2, bool arg3, short arg4);
    void method1(float arg0, unsigned arg1, short arg2, float arg3, float arg4);
    void method2(float arg0, int arg1, int arg2, int arg3, bool arg4);
    void method3(double arg0, double arg1, float arg2, bool arg3, float arg4);
    double method4(int arg0, float arg1, double arg2, unsigned arg3, int arg4);
    void method5(double arg0, float arg1, bool arg2, short arg3, unsigned arg4);
    bool method6(bool arg0, int arg1, bool arg2, double arg3, short arg4);
    short method7(bool arg0, short arg1, unsigned arg2, float arg3, double arg4);
    unsigned method8(unsigned arg0, float arg1, int arg2, bool arg3, short arg4);
    void method9(short arg0, int arg1, float arg2, short arg3, float arg4);
    double method10(float arg0, unsigned arg1, short arg2, double arg3, int arg4);
    float method11(float arg0, double arg1, float arg2, unsigned arg3, int arg4);
    unsigned method12(float arg0, short arg1, short arg2, double arg3, unsigned arg4);
    float method13(double arg0, bool arg1, int arg2, float arg3, bool arg4);
    float method14(float arg0, bool arg1, float arg2, bool arg3, int arg4);
}
