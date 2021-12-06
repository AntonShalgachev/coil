#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class22
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, short arg1, bool arg2, float arg3, unsigned arg4);
    bool method1(int arg0, bool arg1, double arg2, short arg3, unsigned arg4);
    short method2(unsigned arg0, short arg1, int arg2, bool arg3, short arg4);
    void method3(bool arg0, double arg1, float arg2, unsigned arg3, short arg4);
    double method4(unsigned arg0, double arg1, double arg2, bool arg3, int arg4);
    int method5(int arg0, short arg1, bool arg2, int arg3, int arg4);
    void method6(float arg0, bool arg1, short arg2, unsigned arg3, float arg4);
    void method7(double arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    short method8(short arg0, bool arg1, bool arg2, int arg3, double arg4);
    void method9(short arg0, int arg1, unsigned arg2, double arg3, bool arg4);
    int method10(double arg0, short arg1, int arg2, unsigned arg3, int arg4);
    void method11(short arg0, bool arg1, int arg2, float arg3, double arg4);
    void method12(float arg0, short arg1, float arg2, float arg3, double arg4);
    float method13(unsigned arg0, float arg1, bool arg2, int arg3, float arg4);
    double method14(int arg0, float arg1, double arg2, bool arg3, bool arg4);
};

namespace ns_Class22
{
    void method0(unsigned arg0, short arg1, bool arg2, float arg3, unsigned arg4);
    bool method1(int arg0, bool arg1, double arg2, short arg3, unsigned arg4);
    short method2(unsigned arg0, short arg1, int arg2, bool arg3, short arg4);
    void method3(bool arg0, double arg1, float arg2, unsigned arg3, short arg4);
    double method4(unsigned arg0, double arg1, double arg2, bool arg3, int arg4);
    int method5(int arg0, short arg1, bool arg2, int arg3, int arg4);
    void method6(float arg0, bool arg1, short arg2, unsigned arg3, float arg4);
    void method7(double arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    short method8(short arg0, bool arg1, bool arg2, int arg3, double arg4);
    void method9(short arg0, int arg1, unsigned arg2, double arg3, bool arg4);
    int method10(double arg0, short arg1, int arg2, unsigned arg3, int arg4);
    void method11(short arg0, bool arg1, int arg2, float arg3, double arg4);
    void method12(float arg0, short arg1, float arg2, float arg3, double arg4);
    float method13(unsigned arg0, float arg1, bool arg2, int arg3, float arg4);
    double method14(int arg0, float arg1, double arg2, bool arg3, bool arg4);
}
