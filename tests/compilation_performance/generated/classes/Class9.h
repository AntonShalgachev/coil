#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class9
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(short arg0, bool arg1, float arg2, unsigned arg3, double arg4);
    int method1(int arg0, int arg1, short arg2, short arg3, float arg4);
    short method2(short arg0, unsigned arg1, unsigned arg2, float arg3, short arg4);
    void method3(unsigned arg0, bool arg1, short arg2, short arg3, short arg4);
    double method4(unsigned arg0, double arg1, short arg2, short arg3, bool arg4);
    void method5(unsigned arg0, int arg1, float arg2, float arg3, bool arg4);
    void method6(double arg0, float arg1, int arg2, int arg3, unsigned arg4);
    short method7(bool arg0, short arg1, bool arg2, double arg3, short arg4);
    void method8(double arg0, double arg1, float arg2, unsigned arg3, double arg4);
    unsigned method9(unsigned arg0, int arg1, float arg2, double arg3, short arg4);
    float method10(int arg0, unsigned arg1, float arg2, int arg3, bool arg4);
    bool method11(int arg0, double arg1, bool arg2, short arg3, float arg4);
    void method12(float arg0, unsigned arg1, double arg2, short arg3, double arg4);
    void method13(float arg0, int arg1, float arg2, bool arg3, unsigned arg4);
    int method14(int arg0, unsigned arg1, int arg2, short arg3, float arg4);
};

namespace ns_Class9
{
    float method0(short arg0, bool arg1, float arg2, unsigned arg3, double arg4);
    int method1(int arg0, int arg1, short arg2, short arg3, float arg4);
    short method2(short arg0, unsigned arg1, unsigned arg2, float arg3, short arg4);
    void method3(unsigned arg0, bool arg1, short arg2, short arg3, short arg4);
    double method4(unsigned arg0, double arg1, short arg2, short arg3, bool arg4);
    void method5(unsigned arg0, int arg1, float arg2, float arg3, bool arg4);
    void method6(double arg0, float arg1, int arg2, int arg3, unsigned arg4);
    short method7(bool arg0, short arg1, bool arg2, double arg3, short arg4);
    void method8(double arg0, double arg1, float arg2, unsigned arg3, double arg4);
    unsigned method9(unsigned arg0, int arg1, float arg2, double arg3, short arg4);
    float method10(int arg0, unsigned arg1, float arg2, int arg3, bool arg4);
    bool method11(int arg0, double arg1, bool arg2, short arg3, float arg4);
    void method12(float arg0, unsigned arg1, double arg2, short arg3, double arg4);
    void method13(float arg0, int arg1, float arg2, bool arg3, unsigned arg4);
    int method14(int arg0, unsigned arg1, int arg2, short arg3, float arg4);
}
