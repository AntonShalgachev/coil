#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class61
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(bool arg0, unsigned arg1, int arg2, unsigned arg3, int arg4);
    short method1(short arg0, int arg1, short arg2, double arg3, bool arg4);
    void method2(bool arg0, unsigned arg1, int arg2, double arg3, double arg4);
    bool method3(bool arg0, short arg1, bool arg2, short arg3, bool arg4);
    double method4(int arg0, double arg1, double arg2, unsigned arg3, double arg4);
    float method5(short arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    void method6(float arg0, float arg1, unsigned arg2, short arg3, int arg4);
    bool method7(float arg0, bool arg1, double arg2, double arg3, unsigned arg4);
    void method8(unsigned arg0, short arg1, bool arg2, int arg3, int arg4);
    int method9(int arg0, bool arg1, int arg2, double arg3, double arg4);
    void method10(double arg0, int arg1, unsigned arg2, double arg3, int arg4);
    void method11(int arg0, unsigned arg1, double arg2, int arg3, unsigned arg4);
    void method12(short arg0, unsigned arg1, double arg2, double arg3, unsigned arg4);
    double method13(float arg0, unsigned arg1, int arg2, bool arg3, double arg4);
    bool method14(short arg0, bool arg1, unsigned arg2, unsigned arg3, bool arg4);
};

namespace ns_Class61
{
    unsigned method0(bool arg0, unsigned arg1, int arg2, unsigned arg3, int arg4);
    short method1(short arg0, int arg1, short arg2, double arg3, bool arg4);
    void method2(bool arg0, unsigned arg1, int arg2, double arg3, double arg4);
    bool method3(bool arg0, short arg1, bool arg2, short arg3, bool arg4);
    double method4(int arg0, double arg1, double arg2, unsigned arg3, double arg4);
    float method5(short arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    void method6(float arg0, float arg1, unsigned arg2, short arg3, int arg4);
    bool method7(float arg0, bool arg1, double arg2, double arg3, unsigned arg4);
    void method8(unsigned arg0, short arg1, bool arg2, int arg3, int arg4);
    int method9(int arg0, bool arg1, int arg2, double arg3, double arg4);
    void method10(double arg0, int arg1, unsigned arg2, double arg3, int arg4);
    void method11(int arg0, unsigned arg1, double arg2, int arg3, unsigned arg4);
    void method12(short arg0, unsigned arg1, double arg2, double arg3, unsigned arg4);
    double method13(float arg0, unsigned arg1, int arg2, bool arg3, double arg4);
    bool method14(short arg0, bool arg1, unsigned arg2, unsigned arg3, bool arg4);
}
