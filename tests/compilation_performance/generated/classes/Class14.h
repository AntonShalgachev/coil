#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class14
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(int arg0, bool arg1, int arg2, bool arg3, unsigned arg4);
    bool method1(float arg0, double arg1, bool arg2, bool arg3, int arg4);
    void method2(bool arg0, unsigned arg1, bool arg2, bool arg3, unsigned arg4);
    float method3(short arg0, int arg1, bool arg2, unsigned arg3, float arg4);
    bool method4(float arg0, short arg1, short arg2, bool arg3, short arg4);
    bool method5(float arg0, double arg1, int arg2, int arg3, bool arg4);
    double method6(int arg0, short arg1, float arg2, double arg3, float arg4);
    unsigned method7(unsigned arg0, bool arg1, unsigned arg2, double arg3, double arg4);
    void method8(int arg0, bool arg1, short arg2, unsigned arg3, int arg4);
    short method9(bool arg0, double arg1, double arg2, int arg3, short arg4);
    float method10(float arg0, double arg1, float arg2, double arg3, float arg4);
    void method11(bool arg0, float arg1, int arg2, int arg3, bool arg4);
    void method12(bool arg0, float arg1, short arg2, unsigned arg3, double arg4);
    void method13(float arg0, bool arg1, unsigned arg2, short arg3, bool arg4);
    float method14(double arg0, unsigned arg1, float arg2, unsigned arg3, double arg4);
};

namespace ns_Class14
{
    unsigned method0(int arg0, bool arg1, int arg2, bool arg3, unsigned arg4);
    bool method1(float arg0, double arg1, bool arg2, bool arg3, int arg4);
    void method2(bool arg0, unsigned arg1, bool arg2, bool arg3, unsigned arg4);
    float method3(short arg0, int arg1, bool arg2, unsigned arg3, float arg4);
    bool method4(float arg0, short arg1, short arg2, bool arg3, short arg4);
    bool method5(float arg0, double arg1, int arg2, int arg3, bool arg4);
    double method6(int arg0, short arg1, float arg2, double arg3, float arg4);
    unsigned method7(unsigned arg0, bool arg1, unsigned arg2, double arg3, double arg4);
    void method8(int arg0, bool arg1, short arg2, unsigned arg3, int arg4);
    short method9(bool arg0, double arg1, double arg2, int arg3, short arg4);
    float method10(float arg0, double arg1, float arg2, double arg3, float arg4);
    void method11(bool arg0, float arg1, int arg2, int arg3, bool arg4);
    void method12(bool arg0, float arg1, short arg2, unsigned arg3, double arg4);
    void method13(float arg0, bool arg1, unsigned arg2, short arg3, bool arg4);
    float method14(double arg0, unsigned arg1, float arg2, unsigned arg3, double arg4);
}
