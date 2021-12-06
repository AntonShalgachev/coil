#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class8
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(bool arg0, unsigned arg1, double arg2, bool arg3, bool arg4);
    unsigned method1(double arg0, unsigned arg1, unsigned arg2, bool arg3, short arg4);
    unsigned method2(unsigned arg0, bool arg1, double arg2, int arg3, short arg4);
    float method3(int arg0, float arg1, int arg2, float arg3, double arg4);
    void method4(unsigned arg0, unsigned arg1, float arg2, float arg3, int arg4);
    float method5(double arg0, int arg1, float arg2, short arg3, int arg4);
    short method6(short arg0, short arg1, bool arg2, bool arg3, int arg4);
    void method7(unsigned arg0, short arg1, unsigned arg2, short arg3, int arg4);
    void method8(int arg0, short arg1, int arg2, double arg3, bool arg4);
    void method9(unsigned arg0, int arg1, float arg2, bool arg3, unsigned arg4);
    float method10(int arg0, unsigned arg1, short arg2, bool arg3, float arg4);
    void method11(double arg0, float arg1, unsigned arg2, float arg3, bool arg4);
    int method12(float arg0, int arg1, float arg2, int arg3, short arg4);
    void method13(int arg0, float arg1, double arg2, double arg3, short arg4);
    bool method14(float arg0, float arg1, double arg2, short arg3, bool arg4);
};

namespace ns_Class8
{
    bool method0(bool arg0, unsigned arg1, double arg2, bool arg3, bool arg4);
    unsigned method1(double arg0, unsigned arg1, unsigned arg2, bool arg3, short arg4);
    unsigned method2(unsigned arg0, bool arg1, double arg2, int arg3, short arg4);
    float method3(int arg0, float arg1, int arg2, float arg3, double arg4);
    void method4(unsigned arg0, unsigned arg1, float arg2, float arg3, int arg4);
    float method5(double arg0, int arg1, float arg2, short arg3, int arg4);
    short method6(short arg0, short arg1, bool arg2, bool arg3, int arg4);
    void method7(unsigned arg0, short arg1, unsigned arg2, short arg3, int arg4);
    void method8(int arg0, short arg1, int arg2, double arg3, bool arg4);
    void method9(unsigned arg0, int arg1, float arg2, bool arg3, unsigned arg4);
    float method10(int arg0, unsigned arg1, short arg2, bool arg3, float arg4);
    void method11(double arg0, float arg1, unsigned arg2, float arg3, bool arg4);
    int method12(float arg0, int arg1, float arg2, int arg3, short arg4);
    void method13(int arg0, float arg1, double arg2, double arg3, short arg4);
    bool method14(float arg0, float arg1, double arg2, short arg3, bool arg4);
}
