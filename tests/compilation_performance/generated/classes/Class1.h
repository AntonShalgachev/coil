#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class1
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, bool arg1, bool arg2, unsigned arg3, double arg4);
    void method1(int arg0, short arg1, double arg2, double arg3, int arg4);
    void method2(short arg0, int arg1, bool arg2, double arg3, int arg4);
    float method3(int arg0, float arg1, int arg2, int arg3, double arg4);
    short method4(short arg0, int arg1, unsigned arg2, int arg3, bool arg4);
    void method5(double arg0, bool arg1, int arg2, short arg3, unsigned arg4);
    float method6(int arg0, float arg1, float arg2, float arg3, int arg4);
    void method7(double arg0, short arg1, short arg2, int arg3, short arg4);
    double method8(int arg0, double arg1, int arg2, int arg3, short arg4);
    bool method9(short arg0, float arg1, double arg2, unsigned arg3, bool arg4);
    bool method10(float arg0, float arg1, int arg2, unsigned arg3, bool arg4);
    void method11(float arg0, bool arg1, bool arg2, int arg3, unsigned arg4);
    void method12(short arg0, double arg1, float arg2, short arg3, double arg4);
    unsigned method13(unsigned arg0, float arg1, int arg2, double arg3, bool arg4);
    void method14(double arg0, short arg1, double arg2, short arg3, short arg4);
};

namespace ns_Class1
{
    void method0(short arg0, bool arg1, bool arg2, unsigned arg3, double arg4);
    void method1(int arg0, short arg1, double arg2, double arg3, int arg4);
    void method2(short arg0, int arg1, bool arg2, double arg3, int arg4);
    float method3(int arg0, float arg1, int arg2, int arg3, double arg4);
    short method4(short arg0, int arg1, unsigned arg2, int arg3, bool arg4);
    void method5(double arg0, bool arg1, int arg2, short arg3, unsigned arg4);
    float method6(int arg0, float arg1, float arg2, float arg3, int arg4);
    void method7(double arg0, short arg1, short arg2, int arg3, short arg4);
    double method8(int arg0, double arg1, int arg2, int arg3, short arg4);
    bool method9(short arg0, float arg1, double arg2, unsigned arg3, bool arg4);
    bool method10(float arg0, float arg1, int arg2, unsigned arg3, bool arg4);
    void method11(float arg0, bool arg1, bool arg2, int arg3, unsigned arg4);
    void method12(short arg0, double arg1, float arg2, short arg3, double arg4);
    unsigned method13(unsigned arg0, float arg1, int arg2, double arg3, bool arg4);
    void method14(double arg0, short arg1, double arg2, short arg3, short arg4);
}
