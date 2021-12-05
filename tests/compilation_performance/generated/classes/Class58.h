#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class58
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(double arg0, bool arg1, short arg2, double arg3, int arg4);
    void method1(int arg0, double arg1, short arg2, float arg3, short arg4);
    void method2(int arg0, bool arg1, double arg2, int arg3, int arg4);
    void method3(short arg0, double arg1, int arg2, short arg3, int arg4);
    unsigned method4(unsigned arg0, short arg1, unsigned arg2, float arg3, double arg4);
    short method5(bool arg0, float arg1, unsigned arg2, double arg3, short arg4);
    double method6(bool arg0, double arg1, int arg2, short arg3, bool arg4);
    unsigned method7(unsigned arg0, int arg1, short arg2, float arg3, int arg4);
    bool method8(unsigned arg0, bool arg1, unsigned arg2, unsigned arg3, short arg4);
    void method9(unsigned arg0, int arg1, int arg2, float arg3, float arg4);
    void method10(bool arg0, float arg1, int arg2, unsigned arg3, int arg4);
    void method11(bool arg0, int arg1, double arg2, int arg3, float arg4);
    void method12(unsigned arg0, int arg1, double arg2, float arg3, float arg4);
    double method13(float arg0, float arg1, int arg2, int arg3, double arg4);
    void method14(bool arg0, short arg1, bool arg2, short arg3, double arg4);
};

namespace ns_Class58
{
    bool method0(double arg0, bool arg1, short arg2, double arg3, int arg4);
    void method1(int arg0, double arg1, short arg2, float arg3, short arg4);
    void method2(int arg0, bool arg1, double arg2, int arg3, int arg4);
    void method3(short arg0, double arg1, int arg2, short arg3, int arg4);
    unsigned method4(unsigned arg0, short arg1, unsigned arg2, float arg3, double arg4);
    short method5(bool arg0, float arg1, unsigned arg2, double arg3, short arg4);
    double method6(bool arg0, double arg1, int arg2, short arg3, bool arg4);
    unsigned method7(unsigned arg0, int arg1, short arg2, float arg3, int arg4);
    bool method8(unsigned arg0, bool arg1, unsigned arg2, unsigned arg3, short arg4);
    void method9(unsigned arg0, int arg1, int arg2, float arg3, float arg4);
    void method10(bool arg0, float arg1, int arg2, unsigned arg3, int arg4);
    void method11(bool arg0, int arg1, double arg2, int arg3, float arg4);
    void method12(unsigned arg0, int arg1, double arg2, float arg3, float arg4);
    double method13(float arg0, float arg1, int arg2, int arg3, double arg4);
    void method14(bool arg0, short arg1, bool arg2, short arg3, double arg4);
}
