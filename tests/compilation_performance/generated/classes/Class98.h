#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class98
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, short arg1, float arg2, bool arg3, unsigned arg4);
    int method1(int arg0, unsigned arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method2(unsigned arg0, double arg1, double arg2, float arg3, float arg4);
    void method3(double arg0, unsigned arg1, double arg2, bool arg3, int arg4);
    short method4(int arg0, bool arg1, unsigned arg2, short arg3, double arg4);
    void method5(int arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    double method6(bool arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    void method7(bool arg0, float arg1, int arg2, bool arg3, double arg4);
    void method8(bool arg0, bool arg1, bool arg2, short arg3, double arg4);
    int method9(int arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    double method10(unsigned arg0, double arg1, int arg2, short arg3, short arg4);
    void method11(float arg0, unsigned arg1, int arg2, unsigned arg3, bool arg4);
    void method12(short arg0, short arg1, short arg2, unsigned arg3, short arg4);
    bool method13(bool arg0, bool arg1, float arg2, float arg3, int arg4);
    double method14(float arg0, unsigned arg1, bool arg2, double arg3, unsigned arg4);
};

namespace ns_Class98
{
    void method0(short arg0, short arg1, float arg2, bool arg3, unsigned arg4);
    int method1(int arg0, unsigned arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method2(unsigned arg0, double arg1, double arg2, float arg3, float arg4);
    void method3(double arg0, unsigned arg1, double arg2, bool arg3, int arg4);
    short method4(int arg0, bool arg1, unsigned arg2, short arg3, double arg4);
    void method5(int arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    double method6(bool arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    void method7(bool arg0, float arg1, int arg2, bool arg3, double arg4);
    void method8(bool arg0, bool arg1, bool arg2, short arg3, double arg4);
    int method9(int arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    double method10(unsigned arg0, double arg1, int arg2, short arg3, short arg4);
    void method11(float arg0, unsigned arg1, int arg2, unsigned arg3, bool arg4);
    void method12(short arg0, short arg1, short arg2, unsigned arg3, short arg4);
    bool method13(bool arg0, bool arg1, float arg2, float arg3, int arg4);
    double method14(float arg0, unsigned arg1, bool arg2, double arg3, unsigned arg4);
}
