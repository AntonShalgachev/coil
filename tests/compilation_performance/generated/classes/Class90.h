#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class90
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(int arg0, double arg1, bool arg2, double arg3, bool arg4);
    void method1(unsigned arg0, short arg1, double arg2, float arg3, float arg4);
    short method2(int arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    void method3(float arg0, unsigned arg1, short arg2, double arg3, short arg4);
    unsigned method4(float arg0, unsigned arg1, double arg2, short arg3, unsigned arg4);
    void method5(int arg0, float arg1, unsigned arg2, int arg3, short arg4);
    void method6(float arg0, double arg1, float arg2, unsigned arg3, float arg4);
    double method7(int arg0, int arg1, double arg2, unsigned arg3, int arg4);
    double method8(short arg0, double arg1, short arg2, bool arg3, double arg4);
    void method9(short arg0, int arg1, bool arg2, short arg3, unsigned arg4);
    void method10(bool arg0, float arg1, bool arg2, bool arg3, unsigned arg4);
    short method11(double arg0, float arg1, int arg2, bool arg3, short arg4);
    unsigned method12(double arg0, bool arg1, unsigned arg2, unsigned arg3, int arg4);
    void method13(double arg0, int arg1, double arg2, unsigned arg3, float arg4);
    void method14(float arg0, float arg1, double arg2, double arg3, double arg4);
};

namespace ns_Class90
{
    bool method0(int arg0, double arg1, bool arg2, double arg3, bool arg4);
    void method1(unsigned arg0, short arg1, double arg2, float arg3, float arg4);
    short method2(int arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    void method3(float arg0, unsigned arg1, short arg2, double arg3, short arg4);
    unsigned method4(float arg0, unsigned arg1, double arg2, short arg3, unsigned arg4);
    void method5(int arg0, float arg1, unsigned arg2, int arg3, short arg4);
    void method6(float arg0, double arg1, float arg2, unsigned arg3, float arg4);
    double method7(int arg0, int arg1, double arg2, unsigned arg3, int arg4);
    double method8(short arg0, double arg1, short arg2, bool arg3, double arg4);
    void method9(short arg0, int arg1, bool arg2, short arg3, unsigned arg4);
    void method10(bool arg0, float arg1, bool arg2, bool arg3, unsigned arg4);
    short method11(double arg0, float arg1, int arg2, bool arg3, short arg4);
    unsigned method12(double arg0, bool arg1, unsigned arg2, unsigned arg3, int arg4);
    void method13(double arg0, int arg1, double arg2, unsigned arg3, float arg4);
    void method14(float arg0, float arg1, double arg2, double arg3, double arg4);
}
