#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class32
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    void method1(unsigned arg0, bool arg1, unsigned arg2, bool arg3, bool arg4);
    unsigned method2(double arg0, short arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    bool method3(unsigned arg0, unsigned arg1, bool arg2, bool arg3, bool arg4);
    bool method4(float arg0, bool arg1, unsigned arg2, unsigned arg3, short arg4);
    void method5(bool arg0, short arg1, bool arg2, int arg3, unsigned arg4);
    bool method6(short arg0, bool arg1, float arg2, short arg3, short arg4);
    void method7(short arg0, float arg1, float arg2, float arg3, double arg4);
    unsigned method8(double arg0, double arg1, short arg2, short arg3, unsigned arg4);
    float method9(bool arg0, short arg1, float arg2, float arg3, float arg4);
    void method10(short arg0, short arg1, short arg2, double arg3, unsigned arg4);
    void method11(short arg0, double arg1, float arg2, short arg3, unsigned arg4);
    void method12(double arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    bool method13(double arg0, bool arg1, bool arg2, unsigned arg3, int arg4);
    unsigned method14(float arg0, bool arg1, unsigned arg2, bool arg3, unsigned arg4);
};

namespace ns_Class32
{
    void method0(int arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    void method1(unsigned arg0, bool arg1, unsigned arg2, bool arg3, bool arg4);
    unsigned method2(double arg0, short arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    bool method3(unsigned arg0, unsigned arg1, bool arg2, bool arg3, bool arg4);
    bool method4(float arg0, bool arg1, unsigned arg2, unsigned arg3, short arg4);
    void method5(bool arg0, short arg1, bool arg2, int arg3, unsigned arg4);
    bool method6(short arg0, bool arg1, float arg2, short arg3, short arg4);
    void method7(short arg0, float arg1, float arg2, float arg3, double arg4);
    unsigned method8(double arg0, double arg1, short arg2, short arg3, unsigned arg4);
    float method9(bool arg0, short arg1, float arg2, float arg3, float arg4);
    void method10(short arg0, short arg1, short arg2, double arg3, unsigned arg4);
    void method11(short arg0, double arg1, float arg2, short arg3, unsigned arg4);
    void method12(double arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    bool method13(double arg0, bool arg1, bool arg2, unsigned arg3, int arg4);
    unsigned method14(float arg0, bool arg1, unsigned arg2, bool arg3, unsigned arg4);
}
