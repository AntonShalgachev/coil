#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class43
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(float arg0, double arg1, bool arg2, short arg3, double arg4);
    void method1(float arg0, bool arg1, unsigned arg2, float arg3, unsigned arg4);
    void method2(int arg0, float arg1, bool arg2, unsigned arg3, float arg4);
    float method3(int arg0, bool arg1, float arg2, float arg3, int arg4);
    void method4(unsigned arg0, bool arg1, bool arg2, int arg3, unsigned arg4);
    void method5(unsigned arg0, bool arg1, bool arg2, double arg3, short arg4);
    void method6(float arg0, bool arg1, bool arg2, short arg3, float arg4);
    double method7(bool arg0, double arg1, float arg2, double arg3, unsigned arg4);
    float method8(short arg0, float arg1, double arg2, float arg3, short arg4);
    void method9(double arg0, double arg1, int arg2, float arg3, double arg4);
    void method10(double arg0, unsigned arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method11(bool arg0, double arg1, float arg2, double arg3, short arg4);
    bool method12(int arg0, bool arg1, unsigned arg2, bool arg3, int arg4);
    unsigned method13(short arg0, short arg1, unsigned arg2, unsigned arg3, float arg4);
    unsigned method14(bool arg0, int arg1, unsigned arg2, double arg3, double arg4);
};

namespace ns_Class43
{
    short method0(float arg0, double arg1, bool arg2, short arg3, double arg4);
    void method1(float arg0, bool arg1, unsigned arg2, float arg3, unsigned arg4);
    void method2(int arg0, float arg1, bool arg2, unsigned arg3, float arg4);
    float method3(int arg0, bool arg1, float arg2, float arg3, int arg4);
    void method4(unsigned arg0, bool arg1, bool arg2, int arg3, unsigned arg4);
    void method5(unsigned arg0, bool arg1, bool arg2, double arg3, short arg4);
    void method6(float arg0, bool arg1, bool arg2, short arg3, float arg4);
    double method7(bool arg0, double arg1, float arg2, double arg3, unsigned arg4);
    float method8(short arg0, float arg1, double arg2, float arg3, short arg4);
    void method9(double arg0, double arg1, int arg2, float arg3, double arg4);
    void method10(double arg0, unsigned arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method11(bool arg0, double arg1, float arg2, double arg3, short arg4);
    bool method12(int arg0, bool arg1, unsigned arg2, bool arg3, int arg4);
    unsigned method13(short arg0, short arg1, unsigned arg2, unsigned arg3, float arg4);
    unsigned method14(bool arg0, int arg1, unsigned arg2, double arg3, double arg4);
}
