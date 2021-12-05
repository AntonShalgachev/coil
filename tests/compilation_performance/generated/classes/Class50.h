#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class50
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(unsigned arg0, unsigned arg1, int arg2, double arg3, unsigned arg4);
    void method1(short arg0, short arg1, unsigned arg2, float arg3, bool arg4);
    void method2(int arg0, short arg1, bool arg2, unsigned arg3, float arg4);
    short method3(unsigned arg0, bool arg1, unsigned arg2, bool arg3, short arg4);
    short method4(short arg0, float arg1, unsigned arg2, unsigned arg3, short arg4);
    void method5(int arg0, int arg1, short arg2, short arg3, bool arg4);
    int method6(bool arg0, double arg1, int arg2, int arg3, bool arg4);
    bool method7(float arg0, bool arg1, bool arg2, unsigned arg3, float arg4);
    short method8(short arg0, float arg1, float arg2, int arg3, int arg4);
    void method9(float arg0, double arg1, double arg2, unsigned arg3, short arg4);
    float method10(int arg0, float arg1, int arg2, unsigned arg3, short arg4);
    short method11(double arg0, float arg1, unsigned arg2, short arg3, unsigned arg4);
    void method12(short arg0, int arg1, double arg2, float arg3, unsigned arg4);
    void method13(unsigned arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    short method14(int arg0, double arg1, short arg2, short arg3, int arg4);
};

namespace ns_Class50
{
    int method0(unsigned arg0, unsigned arg1, int arg2, double arg3, unsigned arg4);
    void method1(short arg0, short arg1, unsigned arg2, float arg3, bool arg4);
    void method2(int arg0, short arg1, bool arg2, unsigned arg3, float arg4);
    short method3(unsigned arg0, bool arg1, unsigned arg2, bool arg3, short arg4);
    short method4(short arg0, float arg1, unsigned arg2, unsigned arg3, short arg4);
    void method5(int arg0, int arg1, short arg2, short arg3, bool arg4);
    int method6(bool arg0, double arg1, int arg2, int arg3, bool arg4);
    bool method7(float arg0, bool arg1, bool arg2, unsigned arg3, float arg4);
    short method8(short arg0, float arg1, float arg2, int arg3, int arg4);
    void method9(float arg0, double arg1, double arg2, unsigned arg3, short arg4);
    float method10(int arg0, float arg1, int arg2, unsigned arg3, short arg4);
    short method11(double arg0, float arg1, unsigned arg2, short arg3, unsigned arg4);
    void method12(short arg0, int arg1, double arg2, float arg3, unsigned arg4);
    void method13(unsigned arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    short method14(int arg0, double arg1, short arg2, short arg3, int arg4);
}
