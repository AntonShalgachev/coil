#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class79
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, unsigned arg1, float arg2, float arg3, unsigned arg4);
    bool method1(bool arg0, float arg1, float arg2, int arg3, double arg4);
    int method2(int arg0, int arg1, short arg2, float arg3, double arg4);
    void method3(short arg0, short arg1, int arg2, bool arg3, bool arg4);
    void method4(int arg0, unsigned arg1, bool arg2, double arg3, bool arg4);
    void method5(int arg0, bool arg1, short arg2, double arg3, unsigned arg4);
    double method6(double arg0, short arg1, unsigned arg2, double arg3, short arg4);
    void method7(double arg0, unsigned arg1, short arg2, unsigned arg3, int arg4);
    void method8(unsigned arg0, float arg1, int arg2, unsigned arg3, bool arg4);
    void method9(bool arg0, unsigned arg1, unsigned arg2, float arg3, float arg4);
    unsigned method10(short arg0, float arg1, unsigned arg2, float arg3, float arg4);
    void method11(short arg0, bool arg1, unsigned arg2, double arg3, double arg4);
    void method12(short arg0, unsigned arg1, int arg2, double arg3, double arg4);
    void method13(unsigned arg0, int arg1, float arg2, double arg3, float arg4);
    void method14(short arg0, short arg1, int arg2, bool arg3, bool arg4);
};

namespace ns_Class79
{
    void method0(float arg0, unsigned arg1, float arg2, float arg3, unsigned arg4);
    bool method1(bool arg0, float arg1, float arg2, int arg3, double arg4);
    int method2(int arg0, int arg1, short arg2, float arg3, double arg4);
    void method3(short arg0, short arg1, int arg2, bool arg3, bool arg4);
    void method4(int arg0, unsigned arg1, bool arg2, double arg3, bool arg4);
    void method5(int arg0, bool arg1, short arg2, double arg3, unsigned arg4);
    double method6(double arg0, short arg1, unsigned arg2, double arg3, short arg4);
    void method7(double arg0, unsigned arg1, short arg2, unsigned arg3, int arg4);
    void method8(unsigned arg0, float arg1, int arg2, unsigned arg3, bool arg4);
    void method9(bool arg0, unsigned arg1, unsigned arg2, float arg3, float arg4);
    unsigned method10(short arg0, float arg1, unsigned arg2, float arg3, float arg4);
    void method11(short arg0, bool arg1, unsigned arg2, double arg3, double arg4);
    void method12(short arg0, unsigned arg1, int arg2, double arg3, double arg4);
    void method13(unsigned arg0, int arg1, float arg2, double arg3, float arg4);
    void method14(short arg0, short arg1, int arg2, bool arg3, bool arg4);
}
