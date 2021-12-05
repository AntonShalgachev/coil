#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class88
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(unsigned arg0, float arg1, float arg2, float arg3, short arg4);
    int method1(int arg0, float arg1, float arg2, float arg3, short arg4);
    void method2(double arg0, bool arg1, double arg2, float arg3, float arg4);
    int method3(bool arg0, int arg1, short arg2, bool arg3, int arg4);
    void method4(double arg0, unsigned arg1, double arg2, double arg3, float arg4);
    double method5(bool arg0, double arg1, short arg2, unsigned arg3, bool arg4);
    void method6(int arg0, double arg1, int arg2, int arg3, double arg4);
    void method7(unsigned arg0, double arg1, float arg2, int arg3, short arg4);
    double method8(double arg0, short arg1, short arg2, double arg3, unsigned arg4);
    void method9(unsigned arg0, unsigned arg1, short arg2, int arg3, bool arg4);
    bool method10(int arg0, bool arg1, bool arg2, short arg3, bool arg4);
    void method11(bool arg0, double arg1, int arg2, unsigned arg3, short arg4);
    bool method12(float arg0, short arg1, short arg2, bool arg3, bool arg4);
    int method13(int arg0, int arg1, int arg2, int arg3, bool arg4);
    void method14(unsigned arg0, float arg1, unsigned arg2, short arg3, double arg4);
};

namespace ns_Class88
{
    short method0(unsigned arg0, float arg1, float arg2, float arg3, short arg4);
    int method1(int arg0, float arg1, float arg2, float arg3, short arg4);
    void method2(double arg0, bool arg1, double arg2, float arg3, float arg4);
    int method3(bool arg0, int arg1, short arg2, bool arg3, int arg4);
    void method4(double arg0, unsigned arg1, double arg2, double arg3, float arg4);
    double method5(bool arg0, double arg1, short arg2, unsigned arg3, bool arg4);
    void method6(int arg0, double arg1, int arg2, int arg3, double arg4);
    void method7(unsigned arg0, double arg1, float arg2, int arg3, short arg4);
    double method8(double arg0, short arg1, short arg2, double arg3, unsigned arg4);
    void method9(unsigned arg0, unsigned arg1, short arg2, int arg3, bool arg4);
    bool method10(int arg0, bool arg1, bool arg2, short arg3, bool arg4);
    void method11(bool arg0, double arg1, int arg2, unsigned arg3, short arg4);
    bool method12(float arg0, short arg1, short arg2, bool arg3, bool arg4);
    int method13(int arg0, int arg1, int arg2, int arg3, bool arg4);
    void method14(unsigned arg0, float arg1, unsigned arg2, short arg3, double arg4);
}
