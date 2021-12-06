#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class63
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, unsigned arg1, bool arg2, double arg3, double arg4);
    int method1(bool arg0, bool arg1, short arg2, int arg3, unsigned arg4);
    bool method2(double arg0, bool arg1, float arg2, float arg3, int arg4);
    void method3(int arg0, double arg1, short arg2, short arg3, bool arg4);
    void method4(short arg0, double arg1, float arg2, int arg3, float arg4);
    void method5(short arg0, bool arg1, double arg2, int arg3, int arg4);
    bool method6(float arg0, bool arg1, bool arg2, short arg3, int arg4);
    void method7(unsigned arg0, double arg1, int arg2, short arg3, short arg4);
    unsigned method8(bool arg0, double arg1, int arg2, unsigned arg3, double arg4);
    void method9(int arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    void method10(unsigned arg0, int arg1, bool arg2, bool arg3, double arg4);
    void method11(unsigned arg0, unsigned arg1, double arg2, short arg3, double arg4);
    unsigned method12(unsigned arg0, unsigned arg1, bool arg2, float arg3, bool arg4);
    void method13(float arg0, double arg1, short arg2, short arg3, unsigned arg4);
    void method14(short arg0, int arg1, int arg2, double arg3, int arg4);
};

namespace ns_Class63
{
    void method0(unsigned arg0, unsigned arg1, bool arg2, double arg3, double arg4);
    int method1(bool arg0, bool arg1, short arg2, int arg3, unsigned arg4);
    bool method2(double arg0, bool arg1, float arg2, float arg3, int arg4);
    void method3(int arg0, double arg1, short arg2, short arg3, bool arg4);
    void method4(short arg0, double arg1, float arg2, int arg3, float arg4);
    void method5(short arg0, bool arg1, double arg2, int arg3, int arg4);
    bool method6(float arg0, bool arg1, bool arg2, short arg3, int arg4);
    void method7(unsigned arg0, double arg1, int arg2, short arg3, short arg4);
    unsigned method8(bool arg0, double arg1, int arg2, unsigned arg3, double arg4);
    void method9(int arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    void method10(unsigned arg0, int arg1, bool arg2, bool arg3, double arg4);
    void method11(unsigned arg0, unsigned arg1, double arg2, short arg3, double arg4);
    unsigned method12(unsigned arg0, unsigned arg1, bool arg2, float arg3, bool arg4);
    void method13(float arg0, double arg1, short arg2, short arg3, unsigned arg4);
    void method14(short arg0, int arg1, int arg2, double arg3, int arg4);
}
