#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class28
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, int arg1, bool arg2, short arg3, short arg4);
    bool method1(int arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    void method2(unsigned arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    int method3(int arg0, short arg1, int arg2, double arg3, short arg4);
    void method4(short arg0, double arg1, short arg2, bool arg3, short arg4);
    int method5(unsigned arg0, short arg1, int arg2, int arg3, int arg4);
    double method6(bool arg0, float arg1, double arg2, float arg3, bool arg4);
    float method7(int arg0, unsigned arg1, float arg2, int arg3, float arg4);
    void method8(bool arg0, unsigned arg1, unsigned arg2, double arg3, short arg4);
    void method9(int arg0, int arg1, double arg2, short arg3, float arg4);
    short method10(bool arg0, float arg1, short arg2, float arg3, bool arg4);
    double method11(double arg0, double arg1, bool arg2, float arg3, double arg4);
    unsigned method12(int arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    void method13(int arg0, int arg1, short arg2, bool arg3, float arg4);
    bool method14(bool arg0, short arg1, bool arg2, short arg3, int arg4);
};

namespace ns_Class28
{
    void method0(float arg0, int arg1, bool arg2, short arg3, short arg4);
    bool method1(int arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    void method2(unsigned arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    int method3(int arg0, short arg1, int arg2, double arg3, short arg4);
    void method4(short arg0, double arg1, short arg2, bool arg3, short arg4);
    int method5(unsigned arg0, short arg1, int arg2, int arg3, int arg4);
    double method6(bool arg0, float arg1, double arg2, float arg3, bool arg4);
    float method7(int arg0, unsigned arg1, float arg2, int arg3, float arg4);
    void method8(bool arg0, unsigned arg1, unsigned arg2, double arg3, short arg4);
    void method9(int arg0, int arg1, double arg2, short arg3, float arg4);
    short method10(bool arg0, float arg1, short arg2, float arg3, bool arg4);
    double method11(double arg0, double arg1, bool arg2, float arg3, double arg4);
    unsigned method12(int arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    void method13(int arg0, int arg1, short arg2, bool arg3, float arg4);
    bool method14(bool arg0, short arg1, bool arg2, short arg3, int arg4);
}
