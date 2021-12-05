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
    double method0(double arg0, unsigned arg1, double arg2, short arg3, double arg4);
    void method1(bool arg0, bool arg1, float arg2, short arg3, double arg4);
    void method2(int arg0, double arg1, double arg2, double arg3, int arg4);
    void method3(float arg0, unsigned arg1, double arg2, short arg3, int arg4);
    double method4(bool arg0, double arg1, unsigned arg2, short arg3, unsigned arg4);
    void method5(double arg0, bool arg1, float arg2, unsigned arg3, short arg4);
    bool method6(int arg0, double arg1, unsigned arg2, float arg3, bool arg4);
    void method7(bool arg0, short arg1, short arg2, double arg3, short arg4);
    short method8(unsigned arg0, short arg1, float arg2, unsigned arg3, double arg4);
    void method9(short arg0, float arg1, float arg2, int arg3, unsigned arg4);
    bool method10(unsigned arg0, bool arg1, double arg2, unsigned arg3, bool arg4);
    short method11(unsigned arg0, short arg1, short arg2, short arg3, double arg4);
    int method12(int arg0, short arg1, short arg2, unsigned arg3, int arg4);
    void method13(double arg0, bool arg1, float arg2, bool arg3, unsigned arg4);
    void method14(bool arg0, bool arg1, float arg2, short arg3, double arg4);
};

namespace ns_Class11
{
    double method0(double arg0, unsigned arg1, double arg2, short arg3, double arg4);
    void method1(bool arg0, bool arg1, float arg2, short arg3, double arg4);
    void method2(int arg0, double arg1, double arg2, double arg3, int arg4);
    void method3(float arg0, unsigned arg1, double arg2, short arg3, int arg4);
    double method4(bool arg0, double arg1, unsigned arg2, short arg3, unsigned arg4);
    void method5(double arg0, bool arg1, float arg2, unsigned arg3, short arg4);
    bool method6(int arg0, double arg1, unsigned arg2, float arg3, bool arg4);
    void method7(bool arg0, short arg1, short arg2, double arg3, short arg4);
    short method8(unsigned arg0, short arg1, float arg2, unsigned arg3, double arg4);
    void method9(short arg0, float arg1, float arg2, int arg3, unsigned arg4);
    bool method10(unsigned arg0, bool arg1, double arg2, unsigned arg3, bool arg4);
    short method11(unsigned arg0, short arg1, short arg2, short arg3, double arg4);
    int method12(int arg0, short arg1, short arg2, unsigned arg3, int arg4);
    void method13(double arg0, bool arg1, float arg2, bool arg3, unsigned arg4);
    void method14(bool arg0, bool arg1, float arg2, short arg3, double arg4);
}
