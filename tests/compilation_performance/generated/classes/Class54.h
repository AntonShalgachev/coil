#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class54
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(double arg0, float arg1, double arg2, short arg3, int arg4);
    void method1(short arg0, short arg1, unsigned arg2, bool arg3, double arg4);
    bool method2(double arg0, int arg1, double arg2, bool arg3, bool arg4);
    float method3(float arg0, int arg1, float arg2, short arg3, double arg4);
    bool method4(int arg0, bool arg1, int arg2, float arg3, float arg4);
    float method5(int arg0, float arg1, bool arg2, int arg3, double arg4);
    bool method6(int arg0, bool arg1, bool arg2, float arg3, float arg4);
    void method7(bool arg0, bool arg1, double arg2, int arg3, float arg4);
    void method8(float arg0, bool arg1, double arg2, bool arg3, float arg4);
    void method9(float arg0, int arg1, bool arg2, int arg3, double arg4);
    unsigned method10(unsigned arg0, unsigned arg1, int arg2, bool arg3, double arg4);
    void method11(double arg0, bool arg1, unsigned arg2, int arg3, unsigned arg4);
    void method12(float arg0, bool arg1, double arg2, bool arg3, double arg4);
    void method13(int arg0, int arg1, float arg2, int arg3, short arg4);
    int method14(int arg0, unsigned arg1, bool arg2, float arg3, int arg4);
};

namespace ns_Class54
{
    int method0(double arg0, float arg1, double arg2, short arg3, int arg4);
    void method1(short arg0, short arg1, unsigned arg2, bool arg3, double arg4);
    bool method2(double arg0, int arg1, double arg2, bool arg3, bool arg4);
    float method3(float arg0, int arg1, float arg2, short arg3, double arg4);
    bool method4(int arg0, bool arg1, int arg2, float arg3, float arg4);
    float method5(int arg0, float arg1, bool arg2, int arg3, double arg4);
    bool method6(int arg0, bool arg1, bool arg2, float arg3, float arg4);
    void method7(bool arg0, bool arg1, double arg2, int arg3, float arg4);
    void method8(float arg0, bool arg1, double arg2, bool arg3, float arg4);
    void method9(float arg0, int arg1, bool arg2, int arg3, double arg4);
    unsigned method10(unsigned arg0, unsigned arg1, int arg2, bool arg3, double arg4);
    void method11(double arg0, bool arg1, unsigned arg2, int arg3, unsigned arg4);
    void method12(float arg0, bool arg1, double arg2, bool arg3, double arg4);
    void method13(int arg0, int arg1, float arg2, int arg3, short arg4);
    int method14(int arg0, unsigned arg1, bool arg2, float arg3, int arg4);
}
