#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class37
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(double arg0, double arg1, double arg2, float arg3, bool arg4);
    void method1(bool arg0, int arg1, unsigned arg2, int arg3, double arg4);
    short method2(short arg0, int arg1, int arg2, short arg3, double arg4);
    void method3(double arg0, double arg1, unsigned arg2, double arg3, int arg4);
    void method4(double arg0, bool arg1, bool arg2, int arg3, float arg4);
    float method5(unsigned arg0, int arg1, short arg2, float arg3, bool arg4);
    void method6(short arg0, double arg1, short arg2, bool arg3, int arg4);
    bool method7(double arg0, float arg1, float arg2, float arg3, bool arg4);
    void method8(unsigned arg0, float arg1, short arg2, int arg3, short arg4);
    void method9(short arg0, bool arg1, float arg2, unsigned arg3, short arg4);
    void method10(bool arg0, unsigned arg1, double arg2, unsigned arg3, int arg4);
    void method11(int arg0, int arg1, int arg2, int arg3, bool arg4);
    void method12(unsigned arg0, short arg1, float arg2, bool arg3, unsigned arg4);
    bool method13(float arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    bool method14(bool arg0, unsigned arg1, double arg2, short arg3, int arg4);
};

namespace ns_Class37
{
    double method0(double arg0, double arg1, double arg2, float arg3, bool arg4);
    void method1(bool arg0, int arg1, unsigned arg2, int arg3, double arg4);
    short method2(short arg0, int arg1, int arg2, short arg3, double arg4);
    void method3(double arg0, double arg1, unsigned arg2, double arg3, int arg4);
    void method4(double arg0, bool arg1, bool arg2, int arg3, float arg4);
    float method5(unsigned arg0, int arg1, short arg2, float arg3, bool arg4);
    void method6(short arg0, double arg1, short arg2, bool arg3, int arg4);
    bool method7(double arg0, float arg1, float arg2, float arg3, bool arg4);
    void method8(unsigned arg0, float arg1, short arg2, int arg3, short arg4);
    void method9(short arg0, bool arg1, float arg2, unsigned arg3, short arg4);
    void method10(bool arg0, unsigned arg1, double arg2, unsigned arg3, int arg4);
    void method11(int arg0, int arg1, int arg2, int arg3, bool arg4);
    void method12(unsigned arg0, short arg1, float arg2, bool arg3, unsigned arg4);
    bool method13(float arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    bool method14(bool arg0, unsigned arg1, double arg2, short arg3, int arg4);
}
