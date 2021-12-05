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
    double method0(short arg0, double arg1, short arg2, float arg3, bool arg4);
    bool method1(bool arg0, bool arg1, float arg2, bool arg3, bool arg4);
    void method2(float arg0, double arg1, short arg2, unsigned arg3, bool arg4);
    int method3(int arg0, short arg1, float arg2, float arg3, int arg4);
    void method4(unsigned arg0, int arg1, float arg2, short arg3, unsigned arg4);
    void method5(int arg0, int arg1, unsigned arg2, unsigned arg3, int arg4);
    float method6(float arg0, int arg1, float arg2, unsigned arg3, float arg4);
    void method7(bool arg0, unsigned arg1, bool arg2, unsigned arg3, float arg4);
    short method8(short arg0, unsigned arg1, float arg2, short arg3, short arg4);
    void method9(int arg0, unsigned arg1, unsigned arg2, float arg3, float arg4);
    double method10(float arg0, float arg1, int arg2, unsigned arg3, double arg4);
    float method11(double arg0, bool arg1, float arg2, unsigned arg3, short arg4);
    unsigned method12(short arg0, double arg1, double arg2, int arg3, unsigned arg4);
    int method13(short arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    bool method14(float arg0, unsigned arg1, bool arg2, bool arg3, short arg4);
};

namespace ns_Class78
{
    double method0(short arg0, double arg1, short arg2, float arg3, bool arg4);
    bool method1(bool arg0, bool arg1, float arg2, bool arg3, bool arg4);
    void method2(float arg0, double arg1, short arg2, unsigned arg3, bool arg4);
    int method3(int arg0, short arg1, float arg2, float arg3, int arg4);
    void method4(unsigned arg0, int arg1, float arg2, short arg3, unsigned arg4);
    void method5(int arg0, int arg1, unsigned arg2, unsigned arg3, int arg4);
    float method6(float arg0, int arg1, float arg2, unsigned arg3, float arg4);
    void method7(bool arg0, unsigned arg1, bool arg2, unsigned arg3, float arg4);
    short method8(short arg0, unsigned arg1, float arg2, short arg3, short arg4);
    void method9(int arg0, unsigned arg1, unsigned arg2, float arg3, float arg4);
    double method10(float arg0, float arg1, int arg2, unsigned arg3, double arg4);
    float method11(double arg0, bool arg1, float arg2, unsigned arg3, short arg4);
    unsigned method12(short arg0, double arg1, double arg2, int arg3, unsigned arg4);
    int method13(short arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    bool method14(float arg0, unsigned arg1, bool arg2, bool arg3, short arg4);
}
