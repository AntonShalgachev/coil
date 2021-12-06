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
    float method0(float arg0, float arg1, unsigned arg2, unsigned arg3, short arg4);
    int method1(int arg0, int arg1, unsigned arg2, double arg3, int arg4);
    void method2(double arg0, unsigned arg1, double arg2, double arg3, double arg4);
    void method3(bool arg0, bool arg1, double arg2, short arg3, int arg4);
    short method4(bool arg0, unsigned arg1, double arg2, float arg3, short arg4);
    void method5(float arg0, int arg1, float arg2, float arg3, short arg4);
    bool method6(int arg0, float arg1, int arg2, bool arg3, float arg4);
    short method7(short arg0, unsigned arg1, double arg2, int arg3, bool arg4);
    void method8(bool arg0, double arg1, short arg2, float arg3, int arg4);
    double method9(double arg0, float arg1, double arg2, unsigned arg3, float arg4);
    short method10(unsigned arg0, short arg1, float arg2, bool arg3, double arg4);
    short method11(float arg0, short arg1, bool arg2, double arg3, short arg4);
    void method12(short arg0, float arg1, double arg2, bool arg3, int arg4);
    void method13(bool arg0, bool arg1, bool arg2, bool arg3, double arg4);
    short method14(double arg0, float arg1, short arg2, int arg3, bool arg4);
};

namespace ns_Class72
{
    float method0(float arg0, float arg1, unsigned arg2, unsigned arg3, short arg4);
    int method1(int arg0, int arg1, unsigned arg2, double arg3, int arg4);
    void method2(double arg0, unsigned arg1, double arg2, double arg3, double arg4);
    void method3(bool arg0, bool arg1, double arg2, short arg3, int arg4);
    short method4(bool arg0, unsigned arg1, double arg2, float arg3, short arg4);
    void method5(float arg0, int arg1, float arg2, float arg3, short arg4);
    bool method6(int arg0, float arg1, int arg2, bool arg3, float arg4);
    short method7(short arg0, unsigned arg1, double arg2, int arg3, bool arg4);
    void method8(bool arg0, double arg1, short arg2, float arg3, int arg4);
    double method9(double arg0, float arg1, double arg2, unsigned arg3, float arg4);
    short method10(unsigned arg0, short arg1, float arg2, bool arg3, double arg4);
    short method11(float arg0, short arg1, bool arg2, double arg3, short arg4);
    void method12(short arg0, float arg1, double arg2, bool arg3, int arg4);
    void method13(bool arg0, bool arg1, bool arg2, bool arg3, double arg4);
    short method14(double arg0, float arg1, short arg2, int arg3, bool arg4);
}
