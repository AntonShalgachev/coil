#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class76
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, unsigned arg1, bool arg2, float arg3, double arg4);
    bool method1(double arg0, int arg1, double arg2, int arg3, bool arg4);
    void method2(short arg0, int arg1, int arg2, bool arg3, bool arg4);
    int method3(bool arg0, int arg1, int arg2, int arg3, float arg4);
    bool method4(float arg0, bool arg1, float arg2, short arg3, bool arg4);
    void method5(int arg0, int arg1, short arg2, int arg3, unsigned arg4);
    void method6(double arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    void method7(short arg0, bool arg1, unsigned arg2, bool arg3, bool arg4);
    void method8(int arg0, bool arg1, int arg2, float arg3, bool arg4);
    void method9(float arg0, int arg1, double arg2, float arg3, unsigned arg4);
    int method10(short arg0, unsigned arg1, unsigned arg2, int arg3, short arg4);
    void method11(short arg0, double arg1, int arg2, short arg3, float arg4);
    short method12(short arg0, double arg1, bool arg2, double arg3, float arg4);
    void method13(double arg0, short arg1, int arg2, int arg3, short arg4);
    unsigned method14(unsigned arg0, short arg1, short arg2, double arg3, float arg4);
};

namespace ns_Class76
{
    void method0(short arg0, unsigned arg1, bool arg2, float arg3, double arg4);
    bool method1(double arg0, int arg1, double arg2, int arg3, bool arg4);
    void method2(short arg0, int arg1, int arg2, bool arg3, bool arg4);
    int method3(bool arg0, int arg1, int arg2, int arg3, float arg4);
    bool method4(float arg0, bool arg1, float arg2, short arg3, bool arg4);
    void method5(int arg0, int arg1, short arg2, int arg3, unsigned arg4);
    void method6(double arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    void method7(short arg0, bool arg1, unsigned arg2, bool arg3, bool arg4);
    void method8(int arg0, bool arg1, int arg2, float arg3, bool arg4);
    void method9(float arg0, int arg1, double arg2, float arg3, unsigned arg4);
    int method10(short arg0, unsigned arg1, unsigned arg2, int arg3, short arg4);
    void method11(short arg0, double arg1, int arg2, short arg3, float arg4);
    short method12(short arg0, double arg1, bool arg2, double arg3, float arg4);
    void method13(double arg0, short arg1, int arg2, int arg3, short arg4);
    unsigned method14(unsigned arg0, short arg1, short arg2, double arg3, float arg4);
}
