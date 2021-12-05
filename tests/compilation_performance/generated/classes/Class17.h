#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class17
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, unsigned arg1, double arg2, float arg3, unsigned arg4);
    void method1(unsigned arg0, int arg1, float arg2, bool arg3, unsigned arg4);
    void method2(int arg0, unsigned arg1, unsigned arg2, int arg3, double arg4);
    bool method3(short arg0, unsigned arg1, double arg2, unsigned arg3, bool arg4);
    bool method4(double arg0, unsigned arg1, bool arg2, double arg3, double arg4);
    void method5(unsigned arg0, double arg1, float arg2, float arg3, unsigned arg4);
    void method6(unsigned arg0, double arg1, float arg2, bool arg3, short arg4);
    void method7(unsigned arg0, bool arg1, float arg2, double arg3, bool arg4);
    void method8(short arg0, int arg1, float arg2, bool arg3, unsigned arg4);
    void method9(double arg0, unsigned arg1, unsigned arg2, bool arg3, double arg4);
    void method10(double arg0, short arg1, bool arg2, bool arg3, bool arg4);
    void method11(float arg0, int arg1, float arg2, double arg3, short arg4);
    double method12(double arg0, unsigned arg1, int arg2, int arg3, double arg4);
    short method13(short arg0, unsigned arg1, float arg2, float arg3, double arg4);
    bool method14(float arg0, bool arg1, unsigned arg2, bool arg3, unsigned arg4);
};

namespace ns_Class17
{
    void method0(short arg0, unsigned arg1, double arg2, float arg3, unsigned arg4);
    void method1(unsigned arg0, int arg1, float arg2, bool arg3, unsigned arg4);
    void method2(int arg0, unsigned arg1, unsigned arg2, int arg3, double arg4);
    bool method3(short arg0, unsigned arg1, double arg2, unsigned arg3, bool arg4);
    bool method4(double arg0, unsigned arg1, bool arg2, double arg3, double arg4);
    void method5(unsigned arg0, double arg1, float arg2, float arg3, unsigned arg4);
    void method6(unsigned arg0, double arg1, float arg2, bool arg3, short arg4);
    void method7(unsigned arg0, bool arg1, float arg2, double arg3, bool arg4);
    void method8(short arg0, int arg1, float arg2, bool arg3, unsigned arg4);
    void method9(double arg0, unsigned arg1, unsigned arg2, bool arg3, double arg4);
    void method10(double arg0, short arg1, bool arg2, bool arg3, bool arg4);
    void method11(float arg0, int arg1, float arg2, double arg3, short arg4);
    double method12(double arg0, unsigned arg1, int arg2, int arg3, double arg4);
    short method13(short arg0, unsigned arg1, float arg2, float arg3, double arg4);
    bool method14(float arg0, bool arg1, unsigned arg2, bool arg3, unsigned arg4);
}
