#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class25
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, bool arg1, bool arg2, bool arg3, unsigned arg4);
    void method1(int arg0, float arg1, int arg2, bool arg3, short arg4);
    bool method2(bool arg0, short arg1, int arg2, bool arg3, float arg4);
    unsigned method3(double arg0, unsigned arg1, unsigned arg2, unsigned arg3, double arg4);
    void method4(short arg0, short arg1, float arg2, short arg3, int arg4);
    short method5(float arg0, short arg1, double arg2, double arg3, float arg4);
    float method6(double arg0, double arg1, float arg2, short arg3, int arg4);
    int method7(int arg0, float arg1, short arg2, int arg3, int arg4);
    int method8(unsigned arg0, float arg1, int arg2, unsigned arg3, int arg4);
    void method9(float arg0, unsigned arg1, unsigned arg2, short arg3, float arg4);
    unsigned method10(unsigned arg0, bool arg1, unsigned arg2, double arg3, double arg4);
    double method11(short arg0, short arg1, unsigned arg2, double arg3, unsigned arg4);
    unsigned method12(unsigned arg0, int arg1, unsigned arg2, float arg3, int arg4);
    void method13(int arg0, unsigned arg1, short arg2, double arg3, unsigned arg4);
    void method14(unsigned arg0, double arg1, short arg2, double arg3, unsigned arg4);
};

namespace ns_Class25
{
    void method0(double arg0, bool arg1, bool arg2, bool arg3, unsigned arg4);
    void method1(int arg0, float arg1, int arg2, bool arg3, short arg4);
    bool method2(bool arg0, short arg1, int arg2, bool arg3, float arg4);
    unsigned method3(double arg0, unsigned arg1, unsigned arg2, unsigned arg3, double arg4);
    void method4(short arg0, short arg1, float arg2, short arg3, int arg4);
    short method5(float arg0, short arg1, double arg2, double arg3, float arg4);
    float method6(double arg0, double arg1, float arg2, short arg3, int arg4);
    int method7(int arg0, float arg1, short arg2, int arg3, int arg4);
    int method8(unsigned arg0, float arg1, int arg2, unsigned arg3, int arg4);
    void method9(float arg0, unsigned arg1, unsigned arg2, short arg3, float arg4);
    unsigned method10(unsigned arg0, bool arg1, unsigned arg2, double arg3, double arg4);
    double method11(short arg0, short arg1, unsigned arg2, double arg3, unsigned arg4);
    unsigned method12(unsigned arg0, int arg1, unsigned arg2, float arg3, int arg4);
    void method13(int arg0, unsigned arg1, short arg2, double arg3, unsigned arg4);
    void method14(unsigned arg0, double arg1, short arg2, double arg3, unsigned arg4);
}
