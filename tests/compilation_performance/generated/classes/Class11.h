#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class11
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(double arg0, short arg1, double arg2, float arg3, float arg4);
    void method1(int arg0, unsigned arg1, bool arg2, double arg3, double arg4);
    void method2(bool arg0, double arg1, unsigned arg2, int arg3, double arg4);
    short method3(bool arg0, short arg1, float arg2, short arg3, bool arg4);
    int method4(int arg0, bool arg1, float arg2, int arg3, float arg4);
    void method5(float arg0, unsigned arg1, double arg2, float arg3, float arg4);
    unsigned method6(unsigned arg0, double arg1, bool arg2, short arg3, double arg4);
    bool method7(short arg0, unsigned arg1, int arg2, double arg3, bool arg4);
    bool method8(int arg0, int arg1, double arg2, int arg3, bool arg4);
    void method9(bool arg0, bool arg1, unsigned arg2, short arg3, int arg4);
    int method10(int arg0, bool arg1, int arg2, int arg3, float arg4);
    double method11(float arg0, double arg1, float arg2, float arg3, double arg4);
    void method12(int arg0, short arg1, short arg2, double arg3, bool arg4);
    void method13(int arg0, short arg1, bool arg2, int arg3, bool arg4);
    float method14(bool arg0, bool arg1, double arg2, int arg3, float arg4);
};

namespace ns_Class11
{
    short method0(double arg0, short arg1, double arg2, float arg3, float arg4);
    void method1(int arg0, unsigned arg1, bool arg2, double arg3, double arg4);
    void method2(bool arg0, double arg1, unsigned arg2, int arg3, double arg4);
    short method3(bool arg0, short arg1, float arg2, short arg3, bool arg4);
    int method4(int arg0, bool arg1, float arg2, int arg3, float arg4);
    void method5(float arg0, unsigned arg1, double arg2, float arg3, float arg4);
    unsigned method6(unsigned arg0, double arg1, bool arg2, short arg3, double arg4);
    bool method7(short arg0, unsigned arg1, int arg2, double arg3, bool arg4);
    bool method8(int arg0, int arg1, double arg2, int arg3, bool arg4);
    void method9(bool arg0, bool arg1, unsigned arg2, short arg3, int arg4);
    int method10(int arg0, bool arg1, int arg2, int arg3, float arg4);
    double method11(float arg0, double arg1, float arg2, float arg3, double arg4);
    void method12(int arg0, short arg1, short arg2, double arg3, bool arg4);
    void method13(int arg0, short arg1, bool arg2, int arg3, bool arg4);
    float method14(bool arg0, bool arg1, double arg2, int arg3, float arg4);
}
