#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class94
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, short arg1, int arg2, short arg3, int arg4);
    short method1(short arg0, short arg1, short arg2, unsigned arg3, unsigned arg4);
    void method2(bool arg0, double arg1, double arg2, double arg3, bool arg4);
    short method3(short arg0, float arg1, double arg2, bool arg3, int arg4);
    void method4(short arg0, bool arg1, unsigned arg2, unsigned arg3, float arg4);
    unsigned method5(float arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    double method6(short arg0, double arg1, float arg2, double arg3, float arg4);
    void method7(bool arg0, unsigned arg1, bool arg2, float arg3, int arg4);
    float method8(short arg0, short arg1, short arg2, float arg3, float arg4);
    void method9(double arg0, unsigned arg1, int arg2, float arg3, unsigned arg4);
    void method10(int arg0, bool arg1, bool arg2, short arg3, bool arg4);
    void method11(unsigned arg0, unsigned arg1, unsigned arg2, double arg3, unsigned arg4);
    bool method12(bool arg0, unsigned arg1, float arg2, double arg3, int arg4);
    void method13(unsigned arg0, unsigned arg1, int arg2, float arg3, bool arg4);
    void method14(bool arg0, short arg1, double arg2, float arg3, int arg4);
};

namespace ns_Class94
{
    void method0(unsigned arg0, short arg1, int arg2, short arg3, int arg4);
    short method1(short arg0, short arg1, short arg2, unsigned arg3, unsigned arg4);
    void method2(bool arg0, double arg1, double arg2, double arg3, bool arg4);
    short method3(short arg0, float arg1, double arg2, bool arg3, int arg4);
    void method4(short arg0, bool arg1, unsigned arg2, unsigned arg3, float arg4);
    unsigned method5(float arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    double method6(short arg0, double arg1, float arg2, double arg3, float arg4);
    void method7(bool arg0, unsigned arg1, bool arg2, float arg3, int arg4);
    float method8(short arg0, short arg1, short arg2, float arg3, float arg4);
    void method9(double arg0, unsigned arg1, int arg2, float arg3, unsigned arg4);
    void method10(int arg0, bool arg1, bool arg2, short arg3, bool arg4);
    void method11(unsigned arg0, unsigned arg1, unsigned arg2, double arg3, unsigned arg4);
    bool method12(bool arg0, unsigned arg1, float arg2, double arg3, int arg4);
    void method13(unsigned arg0, unsigned arg1, int arg2, float arg3, bool arg4);
    void method14(bool arg0, short arg1, double arg2, float arg3, int arg4);
}
