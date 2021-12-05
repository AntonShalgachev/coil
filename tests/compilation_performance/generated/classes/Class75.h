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
    bool method0(int arg0, short arg1, float arg2, float arg3, bool arg4);
    void method1(bool arg0, float arg1, double arg2, bool arg3, int arg4);
    void method2(short arg0, float arg1, float arg2, int arg3, unsigned arg4);
    bool method3(float arg0, bool arg1, bool arg2, float arg3, double arg4);
    double method4(double arg0, double arg1, bool arg2, float arg3, int arg4);
    void method5(int arg0, float arg1, unsigned arg2, double arg3, unsigned arg4);
    double method6(double arg0, short arg1, bool arg2, double arg3, int arg4);
    void method7(int arg0, bool arg1, int arg2, bool arg3, float arg4);
    short method8(short arg0, unsigned arg1, double arg2, unsigned arg3, float arg4);
    void method9(bool arg0, float arg1, bool arg2, int arg3, short arg4);
    void method10(short arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    void method11(double arg0, short arg1, int arg2, double arg3, short arg4);
    short method12(unsigned arg0, float arg1, double arg2, short arg3, unsigned arg4);
    void method13(unsigned arg0, short arg1, short arg2, short arg3, short arg4);
    void method14(unsigned arg0, short arg1, unsigned arg2, float arg3, int arg4);
};

namespace ns_Class75
{
    bool method0(int arg0, short arg1, float arg2, float arg3, bool arg4);
    void method1(bool arg0, float arg1, double arg2, bool arg3, int arg4);
    void method2(short arg0, float arg1, float arg2, int arg3, unsigned arg4);
    bool method3(float arg0, bool arg1, bool arg2, float arg3, double arg4);
    double method4(double arg0, double arg1, bool arg2, float arg3, int arg4);
    void method5(int arg0, float arg1, unsigned arg2, double arg3, unsigned arg4);
    double method6(double arg0, short arg1, bool arg2, double arg3, int arg4);
    void method7(int arg0, bool arg1, int arg2, bool arg3, float arg4);
    short method8(short arg0, unsigned arg1, double arg2, unsigned arg3, float arg4);
    void method9(bool arg0, float arg1, bool arg2, int arg3, short arg4);
    void method10(short arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    void method11(double arg0, short arg1, int arg2, double arg3, short arg4);
    short method12(unsigned arg0, float arg1, double arg2, short arg3, unsigned arg4);
    void method13(unsigned arg0, short arg1, short arg2, short arg3, short arg4);
    void method14(unsigned arg0, short arg1, unsigned arg2, float arg3, int arg4);
}
