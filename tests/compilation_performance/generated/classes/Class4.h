#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class4
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(float arg0, int arg1, int arg2, unsigned arg3, short arg4);
    float method1(bool arg0, bool arg1, int arg2, int arg3, float arg4);
    unsigned method2(bool arg0, double arg1, short arg2, unsigned arg3, unsigned arg4);
    void method3(short arg0, float arg1, int arg2, int arg3, double arg4);
    int method4(unsigned arg0, short arg1, short arg2, short arg3, int arg4);
    void method5(short arg0, int arg1, bool arg2, unsigned arg3, int arg4);
    bool method6(bool arg0, double arg1, double arg2, bool arg3, double arg4);
    unsigned method7(bool arg0, unsigned arg1, short arg2, unsigned arg3, float arg4);
    void method8(float arg0, short arg1, bool arg2, bool arg3, float arg4);
    bool method9(int arg0, bool arg1, short arg2, float arg3, double arg4);
    void method10(bool arg0, double arg1, short arg2, bool arg3, float arg4);
    void method11(float arg0, unsigned arg1, bool arg2, bool arg3, bool arg4);
    void method12(int arg0, int arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method13(int arg0, float arg1, int arg2, double arg3, short arg4);
    float method14(float arg0, float arg1, int arg2, double arg3, int arg4);
};

namespace ns_Class4
{
    short method0(float arg0, int arg1, int arg2, unsigned arg3, short arg4);
    float method1(bool arg0, bool arg1, int arg2, int arg3, float arg4);
    unsigned method2(bool arg0, double arg1, short arg2, unsigned arg3, unsigned arg4);
    void method3(short arg0, float arg1, int arg2, int arg3, double arg4);
    int method4(unsigned arg0, short arg1, short arg2, short arg3, int arg4);
    void method5(short arg0, int arg1, bool arg2, unsigned arg3, int arg4);
    bool method6(bool arg0, double arg1, double arg2, bool arg3, double arg4);
    unsigned method7(bool arg0, unsigned arg1, short arg2, unsigned arg3, float arg4);
    void method8(float arg0, short arg1, bool arg2, bool arg3, float arg4);
    bool method9(int arg0, bool arg1, short arg2, float arg3, double arg4);
    void method10(bool arg0, double arg1, short arg2, bool arg3, float arg4);
    void method11(float arg0, unsigned arg1, bool arg2, bool arg3, bool arg4);
    void method12(int arg0, int arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method13(int arg0, float arg1, int arg2, double arg3, short arg4);
    float method14(float arg0, float arg1, int arg2, double arg3, int arg4);
}
