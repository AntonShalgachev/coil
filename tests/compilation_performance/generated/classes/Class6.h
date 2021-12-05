#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class6
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, bool arg1, double arg2, float arg3, unsigned arg4);
    void method1(int arg0, int arg1, double arg2, unsigned arg3, short arg4);
    bool method2(bool arg0, bool arg1, bool arg2, bool arg3, short arg4);
    float method3(float arg0, short arg1, float arg2, float arg3, int arg4);
    void method4(bool arg0, double arg1, unsigned arg2, float arg3, unsigned arg4);
    void method5(bool arg0, double arg1, unsigned arg2, unsigned arg3, bool arg4);
    short method6(double arg0, short arg1, bool arg2, short arg3, unsigned arg4);
    void method7(short arg0, double arg1, short arg2, unsigned arg3, unsigned arg4);
    void method8(unsigned arg0, unsigned arg1, unsigned arg2, int arg3, double arg4);
    bool method9(bool arg0, bool arg1, short arg2, double arg3, bool arg4);
    void method10(double arg0, double arg1, double arg2, double arg3, float arg4);
    void method11(float arg0, float arg1, unsigned arg2, bool arg3, unsigned arg4);
    double method12(bool arg0, bool arg1, double arg2, float arg3, short arg4);
    void method13(bool arg0, float arg1, float arg2, float arg3, float arg4);
    double method14(float arg0, double arg1, short arg2, int arg3, float arg4);
};

namespace ns_Class6
{
    void method0(short arg0, bool arg1, double arg2, float arg3, unsigned arg4);
    void method1(int arg0, int arg1, double arg2, unsigned arg3, short arg4);
    bool method2(bool arg0, bool arg1, bool arg2, bool arg3, short arg4);
    float method3(float arg0, short arg1, float arg2, float arg3, int arg4);
    void method4(bool arg0, double arg1, unsigned arg2, float arg3, unsigned arg4);
    void method5(bool arg0, double arg1, unsigned arg2, unsigned arg3, bool arg4);
    short method6(double arg0, short arg1, bool arg2, short arg3, unsigned arg4);
    void method7(short arg0, double arg1, short arg2, unsigned arg3, unsigned arg4);
    void method8(unsigned arg0, unsigned arg1, unsigned arg2, int arg3, double arg4);
    bool method9(bool arg0, bool arg1, short arg2, double arg3, bool arg4);
    void method10(double arg0, double arg1, double arg2, double arg3, float arg4);
    void method11(float arg0, float arg1, unsigned arg2, bool arg3, unsigned arg4);
    double method12(bool arg0, bool arg1, double arg2, float arg3, short arg4);
    void method13(bool arg0, float arg1, float arg2, float arg3, float arg4);
    double method14(float arg0, double arg1, short arg2, int arg3, float arg4);
}
