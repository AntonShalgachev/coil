#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class71
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(bool arg0, bool arg1, bool arg2, short arg3, double arg4);
    void method1(bool arg0, bool arg1, int arg2, int arg3, bool arg4);
    void method2(unsigned arg0, short arg1, float arg2, float arg3, double arg4);
    int method3(int arg0, int arg1, unsigned arg2, unsigned arg3, short arg4);
    void method4(short arg0, unsigned arg1, double arg2, float arg3, short arg4);
    void method5(int arg0, int arg1, int arg2, unsigned arg3, int arg4);
    double method6(double arg0, short arg1, bool arg2, float arg3, float arg4);
    double method7(double arg0, short arg1, float arg2, float arg3, double arg4);
    void method8(short arg0, double arg1, float arg2, bool arg3, unsigned arg4);
    void method9(int arg0, int arg1, bool arg2, bool arg3, bool arg4);
    void method10(bool arg0, int arg1, int arg2, short arg3, int arg4);
    unsigned method11(bool arg0, unsigned arg1, double arg2, float arg3, bool arg4);
    void method12(int arg0, float arg1, double arg2, unsigned arg3, bool arg4);
    void method13(unsigned arg0, double arg1, int arg2, int arg3, unsigned arg4);
    void method14(int arg0, unsigned arg1, short arg2, unsigned arg3, int arg4);
};

namespace ns_Class71
{
    bool method0(bool arg0, bool arg1, bool arg2, short arg3, double arg4);
    void method1(bool arg0, bool arg1, int arg2, int arg3, bool arg4);
    void method2(unsigned arg0, short arg1, float arg2, float arg3, double arg4);
    int method3(int arg0, int arg1, unsigned arg2, unsigned arg3, short arg4);
    void method4(short arg0, unsigned arg1, double arg2, float arg3, short arg4);
    void method5(int arg0, int arg1, int arg2, unsigned arg3, int arg4);
    double method6(double arg0, short arg1, bool arg2, float arg3, float arg4);
    double method7(double arg0, short arg1, float arg2, float arg3, double arg4);
    void method8(short arg0, double arg1, float arg2, bool arg3, unsigned arg4);
    void method9(int arg0, int arg1, bool arg2, bool arg3, bool arg4);
    void method10(bool arg0, int arg1, int arg2, short arg3, int arg4);
    unsigned method11(bool arg0, unsigned arg1, double arg2, float arg3, bool arg4);
    void method12(int arg0, float arg1, double arg2, unsigned arg3, bool arg4);
    void method13(unsigned arg0, double arg1, int arg2, int arg3, unsigned arg4);
    void method14(int arg0, unsigned arg1, short arg2, unsigned arg3, int arg4);
}
