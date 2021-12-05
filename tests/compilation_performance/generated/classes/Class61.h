#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class61
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(int arg0, unsigned arg1, double arg2, unsigned arg3, bool arg4);
    void method1(double arg0, short arg1, int arg2, short arg3, int arg4);
    void method2(short arg0, float arg1, double arg2, double arg3, unsigned arg4);
    float method3(int arg0, bool arg1, unsigned arg2, float arg3, double arg4);
    void method4(unsigned arg0, short arg1, bool arg2, unsigned arg3, double arg4);
    double method5(unsigned arg0, int arg1, float arg2, double arg3, float arg4);
    bool method6(unsigned arg0, short arg1, double arg2, float arg3, bool arg4);
    int method7(float arg0, short arg1, int arg2, short arg3, unsigned arg4);
    int method8(float arg0, int arg1, int arg2, short arg3, bool arg4);
    void method9(unsigned arg0, bool arg1, int arg2, double arg3, float arg4);
    void method10(double arg0, short arg1, int arg2, bool arg3, int arg4);
    unsigned method11(unsigned arg0, unsigned arg1, short arg2, float arg3, unsigned arg4);
    void method12(int arg0, int arg1, int arg2, bool arg3, float arg4);
    void method13(float arg0, float arg1, unsigned arg2, unsigned arg3, bool arg4);
    bool method14(float arg0, bool arg1, short arg2, short arg3, short arg4);
};

namespace ns_Class61
{
    unsigned method0(int arg0, unsigned arg1, double arg2, unsigned arg3, bool arg4);
    void method1(double arg0, short arg1, int arg2, short arg3, int arg4);
    void method2(short arg0, float arg1, double arg2, double arg3, unsigned arg4);
    float method3(int arg0, bool arg1, unsigned arg2, float arg3, double arg4);
    void method4(unsigned arg0, short arg1, bool arg2, unsigned arg3, double arg4);
    double method5(unsigned arg0, int arg1, float arg2, double arg3, float arg4);
    bool method6(unsigned arg0, short arg1, double arg2, float arg3, bool arg4);
    int method7(float arg0, short arg1, int arg2, short arg3, unsigned arg4);
    int method8(float arg0, int arg1, int arg2, short arg3, bool arg4);
    void method9(unsigned arg0, bool arg1, int arg2, double arg3, float arg4);
    void method10(double arg0, short arg1, int arg2, bool arg3, int arg4);
    unsigned method11(unsigned arg0, unsigned arg1, short arg2, float arg3, unsigned arg4);
    void method12(int arg0, int arg1, int arg2, bool arg3, float arg4);
    void method13(float arg0, float arg1, unsigned arg2, unsigned arg3, bool arg4);
    bool method14(float arg0, bool arg1, short arg2, short arg3, short arg4);
}
