#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class56
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(bool arg0, unsigned arg1, unsigned arg2, bool arg3, int arg4);
    unsigned method1(float arg0, bool arg1, int arg2, float arg3, unsigned arg4);
    void method2(short arg0, float arg1, short arg2, short arg3, bool arg4);
    void method3(short arg0, float arg1, short arg2, unsigned arg3, double arg4);
    void method4(int arg0, int arg1, int arg2, float arg3, short arg4);
    void method5(unsigned arg0, double arg1, int arg2, unsigned arg3, bool arg4);
    void method6(int arg0, bool arg1, bool arg2, short arg3, int arg4);
    void method7(double arg0, bool arg1, bool arg2, bool arg3, unsigned arg4);
    bool method8(int arg0, float arg1, bool arg2, double arg3, unsigned arg4);
    float method9(short arg0, bool arg1, unsigned arg2, float arg3, bool arg4);
    int method10(short arg0, float arg1, int arg2, double arg3, short arg4);
    void method11(unsigned arg0, float arg1, double arg2, int arg3, unsigned arg4);
    void method12(double arg0, int arg1, double arg2, bool arg3, double arg4);
    void method13(short arg0, float arg1, bool arg2, double arg3, short arg4);
    void method14(bool arg0, double arg1, double arg2, int arg3, int arg4);
};

namespace ns_Class56
{
    bool method0(bool arg0, unsigned arg1, unsigned arg2, bool arg3, int arg4);
    unsigned method1(float arg0, bool arg1, int arg2, float arg3, unsigned arg4);
    void method2(short arg0, float arg1, short arg2, short arg3, bool arg4);
    void method3(short arg0, float arg1, short arg2, unsigned arg3, double arg4);
    void method4(int arg0, int arg1, int arg2, float arg3, short arg4);
    void method5(unsigned arg0, double arg1, int arg2, unsigned arg3, bool arg4);
    void method6(int arg0, bool arg1, bool arg2, short arg3, int arg4);
    void method7(double arg0, bool arg1, bool arg2, bool arg3, unsigned arg4);
    bool method8(int arg0, float arg1, bool arg2, double arg3, unsigned arg4);
    float method9(short arg0, bool arg1, unsigned arg2, float arg3, bool arg4);
    int method10(short arg0, float arg1, int arg2, double arg3, short arg4);
    void method11(unsigned arg0, float arg1, double arg2, int arg3, unsigned arg4);
    void method12(double arg0, int arg1, double arg2, bool arg3, double arg4);
    void method13(short arg0, float arg1, bool arg2, double arg3, short arg4);
    void method14(bool arg0, double arg1, double arg2, int arg3, int arg4);
}
