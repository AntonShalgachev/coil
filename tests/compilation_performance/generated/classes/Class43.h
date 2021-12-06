#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class43
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, short arg1, int arg2, short arg3, unsigned arg4);
    void method1(unsigned arg0, short arg1, bool arg2, float arg3, double arg4);
    double method2(double arg0, int arg1, bool arg2, double arg3, double arg4);
    void method3(float arg0, int arg1, unsigned arg2, unsigned arg3, double arg4);
    void method4(double arg0, double arg1, double arg2, unsigned arg3, int arg4);
    void method5(float arg0, double arg1, unsigned arg2, float arg3, float arg4);
    int method6(float arg0, bool arg1, unsigned arg2, double arg3, int arg4);
    short method7(unsigned arg0, unsigned arg1, bool arg2, bool arg3, short arg4);
    void method8(short arg0, int arg1, bool arg2, short arg3, int arg4);
    int method9(int arg0, short arg1, unsigned arg2, unsigned arg3, float arg4);
    unsigned method10(float arg0, short arg1, float arg2, unsigned arg3, float arg4);
    void method11(float arg0, short arg1, short arg2, float arg3, double arg4);
    bool method12(short arg0, bool arg1, bool arg2, int arg3, double arg4);
    unsigned method13(double arg0, float arg1, short arg2, short arg3, unsigned arg4);
    void method14(short arg0, unsigned arg1, float arg2, short arg3, double arg4);
};

namespace ns_Class43
{
    void method0(int arg0, short arg1, int arg2, short arg3, unsigned arg4);
    void method1(unsigned arg0, short arg1, bool arg2, float arg3, double arg4);
    double method2(double arg0, int arg1, bool arg2, double arg3, double arg4);
    void method3(float arg0, int arg1, unsigned arg2, unsigned arg3, double arg4);
    void method4(double arg0, double arg1, double arg2, unsigned arg3, int arg4);
    void method5(float arg0, double arg1, unsigned arg2, float arg3, float arg4);
    int method6(float arg0, bool arg1, unsigned arg2, double arg3, int arg4);
    short method7(unsigned arg0, unsigned arg1, bool arg2, bool arg3, short arg4);
    void method8(short arg0, int arg1, bool arg2, short arg3, int arg4);
    int method9(int arg0, short arg1, unsigned arg2, unsigned arg3, float arg4);
    unsigned method10(float arg0, short arg1, float arg2, unsigned arg3, float arg4);
    void method11(float arg0, short arg1, short arg2, float arg3, double arg4);
    bool method12(short arg0, bool arg1, bool arg2, int arg3, double arg4);
    unsigned method13(double arg0, float arg1, short arg2, short arg3, unsigned arg4);
    void method14(short arg0, unsigned arg1, float arg2, short arg3, double arg4);
}
