#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class29
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, unsigned arg1, bool arg2, float arg3, double arg4);
    unsigned method1(unsigned arg0, short arg1, int arg2, unsigned arg3, float arg4);
    void method2(unsigned arg0, bool arg1, int arg2, int arg3, double arg4);
    short method3(bool arg0, bool arg1, int arg2, double arg3, short arg4);
    double method4(unsigned arg0, double arg1, short arg2, int arg3, double arg4);
    float method5(bool arg0, unsigned arg1, float arg2, double arg3, int arg4);
    unsigned method6(bool arg0, unsigned arg1, double arg2, float arg3, int arg4);
    double method7(short arg0, bool arg1, unsigned arg2, double arg3, bool arg4);
    short method8(unsigned arg0, bool arg1, short arg2, short arg3, int arg4);
    bool method9(bool arg0, double arg1, bool arg2, unsigned arg3, double arg4);
    void method10(double arg0, float arg1, double arg2, bool arg3, double arg4);
    void method11(bool arg0, bool arg1, unsigned arg2, unsigned arg3, float arg4);
    int method12(double arg0, int arg1, float arg2, double arg3, int arg4);
    void method13(int arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    float method14(float arg0, bool arg1, float arg2, float arg3, bool arg4);
};

namespace ns_Class29
{
    void method0(short arg0, unsigned arg1, bool arg2, float arg3, double arg4);
    unsigned method1(unsigned arg0, short arg1, int arg2, unsigned arg3, float arg4);
    void method2(unsigned arg0, bool arg1, int arg2, int arg3, double arg4);
    short method3(bool arg0, bool arg1, int arg2, double arg3, short arg4);
    double method4(unsigned arg0, double arg1, short arg2, int arg3, double arg4);
    float method5(bool arg0, unsigned arg1, float arg2, double arg3, int arg4);
    unsigned method6(bool arg0, unsigned arg1, double arg2, float arg3, int arg4);
    double method7(short arg0, bool arg1, unsigned arg2, double arg3, bool arg4);
    short method8(unsigned arg0, bool arg1, short arg2, short arg3, int arg4);
    bool method9(bool arg0, double arg1, bool arg2, unsigned arg3, double arg4);
    void method10(double arg0, float arg1, double arg2, bool arg3, double arg4);
    void method11(bool arg0, bool arg1, unsigned arg2, unsigned arg3, float arg4);
    int method12(double arg0, int arg1, float arg2, double arg3, int arg4);
    void method13(int arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    float method14(float arg0, bool arg1, float arg2, float arg3, bool arg4);
}
