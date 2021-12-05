#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class33
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, float arg1, bool arg2, float arg3, bool arg4);
    void method1(float arg0, short arg1, float arg2, short arg3, unsigned arg4);
    int method2(unsigned arg0, short arg1, int arg2, float arg3, short arg4);
    void method3(bool arg0, float arg1, double arg2, bool arg3, unsigned arg4);
    unsigned method4(bool arg0, bool arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    bool method5(double arg0, int arg1, int arg2, bool arg3, bool arg4);
    void method6(bool arg0, short arg1, double arg2, int arg3, int arg4);
    int method7(int arg0, short arg1, unsigned arg2, bool arg3, bool arg4);
    short method8(unsigned arg0, unsigned arg1, short arg2, short arg3, int arg4);
    void method9(double arg0, unsigned arg1, double arg2, bool arg3, float arg4);
    void method10(float arg0, short arg1, float arg2, bool arg3, double arg4);
    int method11(float arg0, int arg1, unsigned arg2, int arg3, bool arg4);
    unsigned method12(int arg0, short arg1, unsigned arg2, short arg3, float arg4);
    short method13(float arg0, double arg1, short arg2, float arg3, unsigned arg4);
    float method14(int arg0, unsigned arg1, int arg2, unsigned arg3, float arg4);
};

namespace ns_Class33
{
    void method0(int arg0, float arg1, bool arg2, float arg3, bool arg4);
    void method1(float arg0, short arg1, float arg2, short arg3, unsigned arg4);
    int method2(unsigned arg0, short arg1, int arg2, float arg3, short arg4);
    void method3(bool arg0, float arg1, double arg2, bool arg3, unsigned arg4);
    unsigned method4(bool arg0, bool arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    bool method5(double arg0, int arg1, int arg2, bool arg3, bool arg4);
    void method6(bool arg0, short arg1, double arg2, int arg3, int arg4);
    int method7(int arg0, short arg1, unsigned arg2, bool arg3, bool arg4);
    short method8(unsigned arg0, unsigned arg1, short arg2, short arg3, int arg4);
    void method9(double arg0, unsigned arg1, double arg2, bool arg3, float arg4);
    void method10(float arg0, short arg1, float arg2, bool arg3, double arg4);
    int method11(float arg0, int arg1, unsigned arg2, int arg3, bool arg4);
    unsigned method12(int arg0, short arg1, unsigned arg2, short arg3, float arg4);
    short method13(float arg0, double arg1, short arg2, float arg3, unsigned arg4);
    float method14(int arg0, unsigned arg1, int arg2, unsigned arg3, float arg4);
}
