#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class78
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, double arg1, double arg2, float arg3, unsigned arg4);
    unsigned method1(unsigned arg0, unsigned arg1, bool arg2, unsigned arg3, int arg4);
    void method2(unsigned arg0, short arg1, int arg2, float arg3, unsigned arg4);
    short method3(unsigned arg0, short arg1, short arg2, bool arg3, double arg4);
    void method4(double arg0, double arg1, unsigned arg2, double arg3, float arg4);
    float method5(unsigned arg0, bool arg1, unsigned arg2, float arg3, double arg4);
    void method6(unsigned arg0, float arg1, unsigned arg2, double arg3, bool arg4);
    double method7(short arg0, short arg1, float arg2, double arg3, double arg4);
    short method8(unsigned arg0, float arg1, short arg2, short arg3, double arg4);
    float method9(int arg0, unsigned arg1, float arg2, float arg3, short arg4);
    unsigned method10(bool arg0, double arg1, unsigned arg2, unsigned arg3, double arg4);
    void method11(float arg0, double arg1, double arg2, unsigned arg3, bool arg4);
    bool method12(short arg0, int arg1, bool arg2, float arg3, int arg4);
    int method13(int arg0, bool arg1, int arg2, unsigned arg3, int arg4);
    void method14(bool arg0, int arg1, short arg2, short arg3, short arg4);
};

namespace ns_Class78
{
    void method0(int arg0, double arg1, double arg2, float arg3, unsigned arg4);
    unsigned method1(unsigned arg0, unsigned arg1, bool arg2, unsigned arg3, int arg4);
    void method2(unsigned arg0, short arg1, int arg2, float arg3, unsigned arg4);
    short method3(unsigned arg0, short arg1, short arg2, bool arg3, double arg4);
    void method4(double arg0, double arg1, unsigned arg2, double arg3, float arg4);
    float method5(unsigned arg0, bool arg1, unsigned arg2, float arg3, double arg4);
    void method6(unsigned arg0, float arg1, unsigned arg2, double arg3, bool arg4);
    double method7(short arg0, short arg1, float arg2, double arg3, double arg4);
    short method8(unsigned arg0, float arg1, short arg2, short arg3, double arg4);
    float method9(int arg0, unsigned arg1, float arg2, float arg3, short arg4);
    unsigned method10(bool arg0, double arg1, unsigned arg2, unsigned arg3, double arg4);
    void method11(float arg0, double arg1, double arg2, unsigned arg3, bool arg4);
    bool method12(short arg0, int arg1, bool arg2, float arg3, int arg4);
    int method13(int arg0, bool arg1, int arg2, unsigned arg3, int arg4);
    void method14(bool arg0, int arg1, short arg2, short arg3, short arg4);
}
