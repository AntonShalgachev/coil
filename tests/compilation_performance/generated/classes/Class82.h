#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class82
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(bool arg0, double arg1, double arg2, float arg3, float arg4);
    void method1(unsigned arg0, int arg1, short arg2, int arg3, unsigned arg4);
    unsigned method2(bool arg0, unsigned arg1, bool arg2, short arg3, unsigned arg4);
    unsigned method3(int arg0, unsigned arg1, float arg2, unsigned arg3, int arg4);
    unsigned method4(double arg0, unsigned arg1, unsigned arg2, bool arg3, unsigned arg4);
    double method5(short arg0, float arg1, double arg2, float arg3, short arg4);
    void method6(double arg0, short arg1, short arg2, double arg3, short arg4);
    unsigned method7(int arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    int method8(bool arg0, double arg1, int arg2, short arg3, unsigned arg4);
    void method9(double arg0, float arg1, float arg2, bool arg3, int arg4);
    void method10(double arg0, double arg1, double arg2, bool arg3, float arg4);
    void method11(bool arg0, double arg1, short arg2, float arg3, bool arg4);
    int method12(int arg0, float arg1, short arg2, int arg3, unsigned arg4);
    bool method13(bool arg0, float arg1, float arg2, float arg3, bool arg4);
    void method14(short arg0, int arg1, unsigned arg2, unsigned arg3, bool arg4);
};

namespace ns_Class82
{
    double method0(bool arg0, double arg1, double arg2, float arg3, float arg4);
    void method1(unsigned arg0, int arg1, short arg2, int arg3, unsigned arg4);
    unsigned method2(bool arg0, unsigned arg1, bool arg2, short arg3, unsigned arg4);
    unsigned method3(int arg0, unsigned arg1, float arg2, unsigned arg3, int arg4);
    unsigned method4(double arg0, unsigned arg1, unsigned arg2, bool arg3, unsigned arg4);
    double method5(short arg0, float arg1, double arg2, float arg3, short arg4);
    void method6(double arg0, short arg1, short arg2, double arg3, short arg4);
    unsigned method7(int arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    int method8(bool arg0, double arg1, int arg2, short arg3, unsigned arg4);
    void method9(double arg0, float arg1, float arg2, bool arg3, int arg4);
    void method10(double arg0, double arg1, double arg2, bool arg3, float arg4);
    void method11(bool arg0, double arg1, short arg2, float arg3, bool arg4);
    int method12(int arg0, float arg1, short arg2, int arg3, unsigned arg4);
    bool method13(bool arg0, float arg1, float arg2, float arg3, bool arg4);
    void method14(short arg0, int arg1, unsigned arg2, unsigned arg3, bool arg4);
}
