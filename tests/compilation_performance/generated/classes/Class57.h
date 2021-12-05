#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class57
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, float arg1, double arg2, unsigned arg3, short arg4);
    bool method1(bool arg0, unsigned arg1, double arg2, float arg3, float arg4);
    bool method2(bool arg0, int arg1, bool arg2, double arg3, double arg4);
    int method3(int arg0, short arg1, unsigned arg2, short arg3, float arg4);
    void method4(int arg0, bool arg1, int arg2, short arg3, bool arg4);
    void method5(bool arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    void method6(short arg0, bool arg1, bool arg2, int arg3, bool arg4);
    void method7(short arg0, double arg1, short arg2, float arg3, bool arg4);
    void method8(bool arg0, int arg1, int arg2, int arg3, short arg4);
    void method9(double arg0, bool arg1, bool arg2, bool arg3, int arg4);
    double method10(unsigned arg0, double arg1, unsigned arg2, double arg3, bool arg4);
    void method11(short arg0, double arg1, int arg2, int arg3, double arg4);
    int method12(int arg0, unsigned arg1, short arg2, bool arg3, int arg4);
    void method13(unsigned arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    bool method14(short arg0, bool arg1, short arg2, int arg3, float arg4);
};

namespace ns_Class57
{
    void method0(double arg0, float arg1, double arg2, unsigned arg3, short arg4);
    bool method1(bool arg0, unsigned arg1, double arg2, float arg3, float arg4);
    bool method2(bool arg0, int arg1, bool arg2, double arg3, double arg4);
    int method3(int arg0, short arg1, unsigned arg2, short arg3, float arg4);
    void method4(int arg0, bool arg1, int arg2, short arg3, bool arg4);
    void method5(bool arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    void method6(short arg0, bool arg1, bool arg2, int arg3, bool arg4);
    void method7(short arg0, double arg1, short arg2, float arg3, bool arg4);
    void method8(bool arg0, int arg1, int arg2, int arg3, short arg4);
    void method9(double arg0, bool arg1, bool arg2, bool arg3, int arg4);
    double method10(unsigned arg0, double arg1, unsigned arg2, double arg3, bool arg4);
    void method11(short arg0, double arg1, int arg2, int arg3, double arg4);
    int method12(int arg0, unsigned arg1, short arg2, bool arg3, int arg4);
    void method13(unsigned arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    bool method14(short arg0, bool arg1, short arg2, int arg3, float arg4);
}
