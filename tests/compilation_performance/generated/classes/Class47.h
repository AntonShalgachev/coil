#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class47
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, double arg1, bool arg2, unsigned arg3, unsigned arg4);
    float method1(double arg0, float arg1, bool arg2, float arg3, int arg4);
    void method2(unsigned arg0, unsigned arg1, int arg2, float arg3, bool arg4);
    void method3(int arg0, int arg1, short arg2, double arg3, unsigned arg4);
    bool method4(short arg0, bool arg1, bool arg2, unsigned arg3, double arg4);
    void method5(short arg0, float arg1, short arg2, double arg3, bool arg4);
    unsigned method6(unsigned arg0, bool arg1, bool arg2, bool arg3, double arg4);
    bool method7(double arg0, bool arg1, int arg2, short arg3, bool arg4);
    void method8(double arg0, float arg1, short arg2, short arg3, bool arg4);
    double method9(short arg0, double arg1, short arg2, bool arg3, int arg4);
    unsigned method10(double arg0, unsigned arg1, float arg2, unsigned arg3, unsigned arg4);
    bool method11(double arg0, short arg1, int arg2, bool arg3, bool arg4);
    void method12(int arg0, short arg1, unsigned arg2, int arg3, short arg4);
    unsigned method13(unsigned arg0, int arg1, double arg2, short arg3, int arg4);
    void method14(int arg0, double arg1, float arg2, int arg3, float arg4);
};

namespace ns_Class47
{
    void method0(int arg0, double arg1, bool arg2, unsigned arg3, unsigned arg4);
    float method1(double arg0, float arg1, bool arg2, float arg3, int arg4);
    void method2(unsigned arg0, unsigned arg1, int arg2, float arg3, bool arg4);
    void method3(int arg0, int arg1, short arg2, double arg3, unsigned arg4);
    bool method4(short arg0, bool arg1, bool arg2, unsigned arg3, double arg4);
    void method5(short arg0, float arg1, short arg2, double arg3, bool arg4);
    unsigned method6(unsigned arg0, bool arg1, bool arg2, bool arg3, double arg4);
    bool method7(double arg0, bool arg1, int arg2, short arg3, bool arg4);
    void method8(double arg0, float arg1, short arg2, short arg3, bool arg4);
    double method9(short arg0, double arg1, short arg2, bool arg3, int arg4);
    unsigned method10(double arg0, unsigned arg1, float arg2, unsigned arg3, unsigned arg4);
    bool method11(double arg0, short arg1, int arg2, bool arg3, bool arg4);
    void method12(int arg0, short arg1, unsigned arg2, int arg3, short arg4);
    unsigned method13(unsigned arg0, int arg1, double arg2, short arg3, int arg4);
    void method14(int arg0, double arg1, float arg2, int arg3, float arg4);
}
