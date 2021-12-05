#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class27
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, float arg1, bool arg2, double arg3, float arg4);
    void method1(unsigned arg0, bool arg1, short arg2, float arg3, float arg4);
    short method2(short arg0, short arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method3(short arg0, float arg1, int arg2, double arg3, bool arg4);
    void method4(double arg0, double arg1, int arg2, bool arg3, int arg4);
    void method5(short arg0, short arg1, bool arg2, short arg3, int arg4);
    void method6(double arg0, double arg1, bool arg2, int arg3, short arg4);
    int method7(int arg0, double arg1, unsigned arg2, int arg3, int arg4);
    void method8(unsigned arg0, float arg1, double arg2, unsigned arg3, float arg4);
    bool method9(bool arg0, float arg1, short arg2, unsigned arg3, float arg4);
    bool method10(bool arg0, int arg1, int arg2, bool arg3, bool arg4);
    void method11(int arg0, short arg1, unsigned arg2, bool arg3, float arg4);
    unsigned method12(unsigned arg0, float arg1, double arg2, bool arg3, float arg4);
    void method13(float arg0, int arg1, bool arg2, float arg3, unsigned arg4);
    void method14(unsigned arg0, unsigned arg1, unsigned arg2, double arg3, double arg4);
};

namespace ns_Class27
{
    void method0(unsigned arg0, float arg1, bool arg2, double arg3, float arg4);
    void method1(unsigned arg0, bool arg1, short arg2, float arg3, float arg4);
    short method2(short arg0, short arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method3(short arg0, float arg1, int arg2, double arg3, bool arg4);
    void method4(double arg0, double arg1, int arg2, bool arg3, int arg4);
    void method5(short arg0, short arg1, bool arg2, short arg3, int arg4);
    void method6(double arg0, double arg1, bool arg2, int arg3, short arg4);
    int method7(int arg0, double arg1, unsigned arg2, int arg3, int arg4);
    void method8(unsigned arg0, float arg1, double arg2, unsigned arg3, float arg4);
    bool method9(bool arg0, float arg1, short arg2, unsigned arg3, float arg4);
    bool method10(bool arg0, int arg1, int arg2, bool arg3, bool arg4);
    void method11(int arg0, short arg1, unsigned arg2, bool arg3, float arg4);
    unsigned method12(unsigned arg0, float arg1, double arg2, bool arg3, float arg4);
    void method13(float arg0, int arg1, bool arg2, float arg3, unsigned arg4);
    void method14(unsigned arg0, unsigned arg1, unsigned arg2, double arg3, double arg4);
}
