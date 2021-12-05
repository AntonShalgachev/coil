#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class42
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, unsigned arg1, unsigned arg2, float arg3, bool arg4);
    short method1(short arg0, float arg1, double arg2, bool arg3, bool arg4);
    void method2(int arg0, int arg1, float arg2, short arg3, int arg4);
    void method3(unsigned arg0, double arg1, float arg2, bool arg3, double arg4);
    void method4(double arg0, float arg1, int arg2, double arg3, short arg4);
    double method5(bool arg0, double arg1, int arg2, int arg3, float arg4);
    float method6(float arg0, unsigned arg1, bool arg2, float arg3, double arg4);
    float method7(double arg0, float arg1, unsigned arg2, int arg3, float arg4);
    float method8(int arg0, unsigned arg1, float arg2, int arg3, float arg4);
    double method9(double arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    bool method10(unsigned arg0, bool arg1, short arg2, bool arg3, bool arg4);
    void method11(unsigned arg0, bool arg1, bool arg2, bool arg3, double arg4);
    bool method12(bool arg0, short arg1, int arg2, bool arg3, short arg4);
    bool method13(int arg0, bool arg1, double arg2, bool arg3, unsigned arg4);
    unsigned method14(unsigned arg0, short arg1, unsigned arg2, double arg3, bool arg4);
};

namespace ns_Class42
{
    void method0(float arg0, unsigned arg1, unsigned arg2, float arg3, bool arg4);
    short method1(short arg0, float arg1, double arg2, bool arg3, bool arg4);
    void method2(int arg0, int arg1, float arg2, short arg3, int arg4);
    void method3(unsigned arg0, double arg1, float arg2, bool arg3, double arg4);
    void method4(double arg0, float arg1, int arg2, double arg3, short arg4);
    double method5(bool arg0, double arg1, int arg2, int arg3, float arg4);
    float method6(float arg0, unsigned arg1, bool arg2, float arg3, double arg4);
    float method7(double arg0, float arg1, unsigned arg2, int arg3, float arg4);
    float method8(int arg0, unsigned arg1, float arg2, int arg3, float arg4);
    double method9(double arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    bool method10(unsigned arg0, bool arg1, short arg2, bool arg3, bool arg4);
    void method11(unsigned arg0, bool arg1, bool arg2, bool arg3, double arg4);
    bool method12(bool arg0, short arg1, int arg2, bool arg3, short arg4);
    bool method13(int arg0, bool arg1, double arg2, bool arg3, unsigned arg4);
    unsigned method14(unsigned arg0, short arg1, unsigned arg2, double arg3, bool arg4);
}
