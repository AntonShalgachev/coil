#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class75
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(short arg0, bool arg1, short arg2, short arg3, short arg4);
    void method1(short arg0, int arg1, bool arg2, double arg3, unsigned arg4);
    void method2(bool arg0, double arg1, short arg2, int arg3, float arg4);
    void method3(double arg0, double arg1, int arg2, int arg3, int arg4);
    void method4(float arg0, unsigned arg1, bool arg2, bool arg3, unsigned arg4);
    void method5(short arg0, unsigned arg1, bool arg2, double arg3, unsigned arg4);
    unsigned method6(int arg0, unsigned arg1, int arg2, unsigned arg3, int arg4);
    void method7(int arg0, bool arg1, double arg2, int arg3, bool arg4);
    int method8(double arg0, float arg1, int arg2, int arg3, short arg4);
    double method9(double arg0, short arg1, float arg2, int arg3, bool arg4);
    void method10(short arg0, short arg1, unsigned arg2, int arg3, unsigned arg4);
    void method11(short arg0, short arg1, int arg2, bool arg3, short arg4);
    short method12(double arg0, short arg1, short arg2, int arg3, unsigned arg4);
    void method13(unsigned arg0, unsigned arg1, short arg2, float arg3, double arg4);
    bool method14(unsigned arg0, bool arg1, short arg2, bool arg3, unsigned arg4);
};

namespace ns_Class75
{
    short method0(short arg0, bool arg1, short arg2, short arg3, short arg4);
    void method1(short arg0, int arg1, bool arg2, double arg3, unsigned arg4);
    void method2(bool arg0, double arg1, short arg2, int arg3, float arg4);
    void method3(double arg0, double arg1, int arg2, int arg3, int arg4);
    void method4(float arg0, unsigned arg1, bool arg2, bool arg3, unsigned arg4);
    void method5(short arg0, unsigned arg1, bool arg2, double arg3, unsigned arg4);
    unsigned method6(int arg0, unsigned arg1, int arg2, unsigned arg3, int arg4);
    void method7(int arg0, bool arg1, double arg2, int arg3, bool arg4);
    int method8(double arg0, float arg1, int arg2, int arg3, short arg4);
    double method9(double arg0, short arg1, float arg2, int arg3, bool arg4);
    void method10(short arg0, short arg1, unsigned arg2, int arg3, unsigned arg4);
    void method11(short arg0, short arg1, int arg2, bool arg3, short arg4);
    short method12(double arg0, short arg1, short arg2, int arg3, unsigned arg4);
    void method13(unsigned arg0, unsigned arg1, short arg2, float arg3, double arg4);
    bool method14(unsigned arg0, bool arg1, short arg2, bool arg3, unsigned arg4);
}
