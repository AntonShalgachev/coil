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
    void method0(double arg0, unsigned arg1, int arg2, double arg3, double arg4);
    void method1(bool arg0, bool arg1, float arg2, double arg3, double arg4);
    int method2(short arg0, int arg1, double arg2, bool arg3, double arg4);
    bool method3(short arg0, bool arg1, double arg2, unsigned arg3, bool arg4);
    double method4(bool arg0, double arg1, double arg2, short arg3, int arg4);
    void method5(bool arg0, unsigned arg1, unsigned arg2, short arg3, unsigned arg4);
    bool method6(bool arg0, unsigned arg1, short arg2, int arg3, bool arg4);
    void method7(int arg0, double arg1, unsigned arg2, bool arg3, double arg4);
    void method8(float arg0, double arg1, double arg2, short arg3, float arg4);
    bool method9(short arg0, short arg1, double arg2, bool arg3, double arg4);
    void method10(unsigned arg0, int arg1, float arg2, double arg3, double arg4);
    void method11(short arg0, float arg1, unsigned arg2, int arg3, float arg4);
    void method12(float arg0, float arg1, short arg2, float arg3, double arg4);
    short method13(float arg0, unsigned arg1, unsigned arg2, short arg3, short arg4);
    unsigned method14(short arg0, unsigned arg1, double arg2, int arg3, unsigned arg4);
};

namespace ns_Class58
{
    void method0(double arg0, unsigned arg1, int arg2, double arg3, double arg4);
    void method1(bool arg0, bool arg1, float arg2, double arg3, double arg4);
    int method2(short arg0, int arg1, double arg2, bool arg3, double arg4);
    bool method3(short arg0, bool arg1, double arg2, unsigned arg3, bool arg4);
    double method4(bool arg0, double arg1, double arg2, short arg3, int arg4);
    void method5(bool arg0, unsigned arg1, unsigned arg2, short arg3, unsigned arg4);
    bool method6(bool arg0, unsigned arg1, short arg2, int arg3, bool arg4);
    void method7(int arg0, double arg1, unsigned arg2, bool arg3, double arg4);
    void method8(float arg0, double arg1, double arg2, short arg3, float arg4);
    bool method9(short arg0, short arg1, double arg2, bool arg3, double arg4);
    void method10(unsigned arg0, int arg1, float arg2, double arg3, double arg4);
    void method11(short arg0, float arg1, unsigned arg2, int arg3, float arg4);
    void method12(float arg0, float arg1, short arg2, float arg3, double arg4);
    short method13(float arg0, unsigned arg1, unsigned arg2, short arg3, short arg4);
    unsigned method14(short arg0, unsigned arg1, double arg2, int arg3, unsigned arg4);
}
