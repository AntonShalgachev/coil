#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class35
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(double arg0, short arg1, double arg2, double arg3, int arg4);
    short method1(float arg0, short arg1, short arg2, short arg3, double arg4);
    bool method2(bool arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    double method3(double arg0, unsigned arg1, bool arg2, unsigned arg3, unsigned arg4);
    bool method4(int arg0, bool arg1, bool arg2, unsigned arg3, double arg4);
    bool method5(short arg0, float arg1, double arg2, short arg3, bool arg4);
    short method6(unsigned arg0, bool arg1, float arg2, short arg3, int arg4);
    float method7(float arg0, float arg1, float arg2, bool arg3, float arg4);
    void method8(double arg0, float arg1, float arg2, int arg3, float arg4);
    int method9(short arg0, int arg1, float arg2, double arg3, int arg4);
    void method10(bool arg0, unsigned arg1, float arg2, float arg3, short arg4);
    unsigned method11(bool arg0, short arg1, int arg2, unsigned arg3, short arg4);
    short method12(unsigned arg0, short arg1, unsigned arg2, double arg3, bool arg4);
    void method13(int arg0, float arg1, bool arg2, short arg3, float arg4);
    void method14(short arg0, int arg1, unsigned arg2, short arg3, double arg4);
};

namespace ns_Class35
{
    double method0(double arg0, short arg1, double arg2, double arg3, int arg4);
    short method1(float arg0, short arg1, short arg2, short arg3, double arg4);
    bool method2(bool arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    double method3(double arg0, unsigned arg1, bool arg2, unsigned arg3, unsigned arg4);
    bool method4(int arg0, bool arg1, bool arg2, unsigned arg3, double arg4);
    bool method5(short arg0, float arg1, double arg2, short arg3, bool arg4);
    short method6(unsigned arg0, bool arg1, float arg2, short arg3, int arg4);
    float method7(float arg0, float arg1, float arg2, bool arg3, float arg4);
    void method8(double arg0, float arg1, float arg2, int arg3, float arg4);
    int method9(short arg0, int arg1, float arg2, double arg3, int arg4);
    void method10(bool arg0, unsigned arg1, float arg2, float arg3, short arg4);
    unsigned method11(bool arg0, short arg1, int arg2, unsigned arg3, short arg4);
    short method12(unsigned arg0, short arg1, unsigned arg2, double arg3, bool arg4);
    void method13(int arg0, float arg1, bool arg2, short arg3, float arg4);
    void method14(short arg0, int arg1, unsigned arg2, short arg3, double arg4);
}
