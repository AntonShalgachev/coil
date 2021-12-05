#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class62
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, double arg1, int arg2, double arg3, short arg4);
    void method1(float arg0, bool arg1, bool arg2, float arg3, float arg4);
    void method2(float arg0, double arg1, bool arg2, short arg3, short arg4);
    unsigned method3(unsigned arg0, unsigned arg1, float arg2, short arg3, double arg4);
    int method4(int arg0, float arg1, float arg2, bool arg3, int arg4);
    float method5(unsigned arg0, float arg1, bool arg2, double arg3, unsigned arg4);
    double method6(short arg0, unsigned arg1, unsigned arg2, double arg3, short arg4);
    unsigned method7(bool arg0, float arg1, bool arg2, short arg3, unsigned arg4);
    void method8(short arg0, int arg1, float arg2, float arg3, bool arg4);
    void method9(float arg0, float arg1, float arg2, double arg3, int arg4);
    void method10(int arg0, bool arg1, unsigned arg2, short arg3, float arg4);
    short method11(float arg0, double arg1, unsigned arg2, short arg3, int arg4);
    void method12(double arg0, float arg1, double arg2, short arg3, int arg4);
    bool method13(bool arg0, float arg1, bool arg2, double arg3, bool arg4);
    bool method14(double arg0, int arg1, float arg2, bool arg3, bool arg4);
};

namespace ns_Class62
{
    void method0(unsigned arg0, double arg1, int arg2, double arg3, short arg4);
    void method1(float arg0, bool arg1, bool arg2, float arg3, float arg4);
    void method2(float arg0, double arg1, bool arg2, short arg3, short arg4);
    unsigned method3(unsigned arg0, unsigned arg1, float arg2, short arg3, double arg4);
    int method4(int arg0, float arg1, float arg2, bool arg3, int arg4);
    float method5(unsigned arg0, float arg1, bool arg2, double arg3, unsigned arg4);
    double method6(short arg0, unsigned arg1, unsigned arg2, double arg3, short arg4);
    unsigned method7(bool arg0, float arg1, bool arg2, short arg3, unsigned arg4);
    void method8(short arg0, int arg1, float arg2, float arg3, bool arg4);
    void method9(float arg0, float arg1, float arg2, double arg3, int arg4);
    void method10(int arg0, bool arg1, unsigned arg2, short arg3, float arg4);
    short method11(float arg0, double arg1, unsigned arg2, short arg3, int arg4);
    void method12(double arg0, float arg1, double arg2, short arg3, int arg4);
    bool method13(bool arg0, float arg1, bool arg2, double arg3, bool arg4);
    bool method14(double arg0, int arg1, float arg2, bool arg3, bool arg4);
}
