#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class12
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(short arg0, int arg1, float arg2, int arg3, unsigned arg4);
    bool method1(double arg0, short arg1, bool arg2, int arg3, float arg4);
    void method2(double arg0, int arg1, int arg2, float arg3, int arg4);
    void method3(short arg0, short arg1, short arg2, short arg3, short arg4);
    double method4(unsigned arg0, double arg1, float arg2, bool arg3, float arg4);
    void method5(double arg0, bool arg1, bool arg2, short arg3, short arg4);
    double method6(float arg0, double arg1, float arg2, unsigned arg3, double arg4);
    bool method7(short arg0, unsigned arg1, bool arg2, short arg3, int arg4);
    void method8(short arg0, bool arg1, short arg2, int arg3, unsigned arg4);
    int method9(int arg0, double arg1, short arg2, bool arg3, bool arg4);
    bool method10(int arg0, bool arg1, float arg2, float arg3, unsigned arg4);
    void method11(unsigned arg0, bool arg1, int arg2, float arg3, unsigned arg4);
    bool method12(float arg0, double arg1, bool arg2, int arg3, short arg4);
    void method13(float arg0, int arg1, int arg2, float arg3, bool arg4);
    void method14(short arg0, double arg1, float arg2, int arg3, int arg4);
};

namespace ns_Class12
{
    int method0(short arg0, int arg1, float arg2, int arg3, unsigned arg4);
    bool method1(double arg0, short arg1, bool arg2, int arg3, float arg4);
    void method2(double arg0, int arg1, int arg2, float arg3, int arg4);
    void method3(short arg0, short arg1, short arg2, short arg3, short arg4);
    double method4(unsigned arg0, double arg1, float arg2, bool arg3, float arg4);
    void method5(double arg0, bool arg1, bool arg2, short arg3, short arg4);
    double method6(float arg0, double arg1, float arg2, unsigned arg3, double arg4);
    bool method7(short arg0, unsigned arg1, bool arg2, short arg3, int arg4);
    void method8(short arg0, bool arg1, short arg2, int arg3, unsigned arg4);
    int method9(int arg0, double arg1, short arg2, bool arg3, bool arg4);
    bool method10(int arg0, bool arg1, float arg2, float arg3, unsigned arg4);
    void method11(unsigned arg0, bool arg1, int arg2, float arg3, unsigned arg4);
    bool method12(float arg0, double arg1, bool arg2, int arg3, short arg4);
    void method13(float arg0, int arg1, int arg2, float arg3, bool arg4);
    void method14(short arg0, double arg1, float arg2, int arg3, int arg4);
}
