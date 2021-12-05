#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class5
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(short arg0, unsigned arg1, double arg2, short arg3, int arg4);
    float method1(unsigned arg0, unsigned arg1, int arg2, float arg3, float arg4);
    void method2(int arg0, float arg1, short arg2, bool arg3, short arg4);
    short method3(short arg0, double arg1, double arg2, float arg3, float arg4);
    float method4(float arg0, double arg1, bool arg2, bool arg3, unsigned arg4);
    int method5(unsigned arg0, int arg1, unsigned arg2, short arg3, int arg4);
    short method6(unsigned arg0, short arg1, float arg2, int arg3, bool arg4);
    int method7(int arg0, int arg1, int arg2, short arg3, double arg4);
    unsigned method8(double arg0, unsigned arg1, bool arg2, short arg3, float arg4);
    unsigned method9(unsigned arg0, bool arg1, bool arg2, double arg3, double arg4);
    void method10(short arg0, float arg1, bool arg2, unsigned arg3, bool arg4);
    bool method11(unsigned arg0, unsigned arg1, unsigned arg2, double arg3, bool arg4);
    void method12(unsigned arg0, float arg1, float arg2, float arg3, unsigned arg4);
    float method13(int arg0, float arg1, bool arg2, float arg3, float arg4);
    void method14(int arg0, unsigned arg1, unsigned arg2, short arg3, short arg4);
};

namespace ns_Class5
{
    int method0(short arg0, unsigned arg1, double arg2, short arg3, int arg4);
    float method1(unsigned arg0, unsigned arg1, int arg2, float arg3, float arg4);
    void method2(int arg0, float arg1, short arg2, bool arg3, short arg4);
    short method3(short arg0, double arg1, double arg2, float arg3, float arg4);
    float method4(float arg0, double arg1, bool arg2, bool arg3, unsigned arg4);
    int method5(unsigned arg0, int arg1, unsigned arg2, short arg3, int arg4);
    short method6(unsigned arg0, short arg1, float arg2, int arg3, bool arg4);
    int method7(int arg0, int arg1, int arg2, short arg3, double arg4);
    unsigned method8(double arg0, unsigned arg1, bool arg2, short arg3, float arg4);
    unsigned method9(unsigned arg0, bool arg1, bool arg2, double arg3, double arg4);
    void method10(short arg0, float arg1, bool arg2, unsigned arg3, bool arg4);
    bool method11(unsigned arg0, unsigned arg1, unsigned arg2, double arg3, bool arg4);
    void method12(unsigned arg0, float arg1, float arg2, float arg3, unsigned arg4);
    float method13(int arg0, float arg1, bool arg2, float arg3, float arg4);
    void method14(int arg0, unsigned arg1, unsigned arg2, short arg3, short arg4);
}
