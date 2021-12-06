#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class74
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(short arg0, short arg1, unsigned arg2, short arg3, double arg4);
    float method1(float arg0, short arg1, float arg2, double arg3, bool arg4);
    void method2(double arg0, short arg1, float arg2, bool arg3, unsigned arg4);
    int method3(double arg0, int arg1, int arg2, float arg3, int arg4);
    bool method4(unsigned arg0, short arg1, unsigned arg2, bool arg3, unsigned arg4);
    unsigned method5(double arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    bool method6(int arg0, short arg1, bool arg2, bool arg3, int arg4);
    double method7(unsigned arg0, double arg1, float arg2, double arg3, double arg4);
    void method8(unsigned arg0, unsigned arg1, short arg2, unsigned arg3, double arg4);
    void method9(unsigned arg0, int arg1, short arg2, float arg3, short arg4);
    short method10(float arg0, short arg1, double arg2, unsigned arg3, short arg4);
    short method11(short arg0, short arg1, bool arg2, double arg3, short arg4);
    int method12(int arg0, int arg1, double arg2, double arg3, int arg4);
    short method13(bool arg0, int arg1, double arg2, float arg3, short arg4);
    bool method14(short arg0, double arg1, int arg2, bool arg3, int arg4);
};

namespace ns_Class74
{
    double method0(short arg0, short arg1, unsigned arg2, short arg3, double arg4);
    float method1(float arg0, short arg1, float arg2, double arg3, bool arg4);
    void method2(double arg0, short arg1, float arg2, bool arg3, unsigned arg4);
    int method3(double arg0, int arg1, int arg2, float arg3, int arg4);
    bool method4(unsigned arg0, short arg1, unsigned arg2, bool arg3, unsigned arg4);
    unsigned method5(double arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    bool method6(int arg0, short arg1, bool arg2, bool arg3, int arg4);
    double method7(unsigned arg0, double arg1, float arg2, double arg3, double arg4);
    void method8(unsigned arg0, unsigned arg1, short arg2, unsigned arg3, double arg4);
    void method9(unsigned arg0, int arg1, short arg2, float arg3, short arg4);
    short method10(float arg0, short arg1, double arg2, unsigned arg3, short arg4);
    short method11(short arg0, short arg1, bool arg2, double arg3, short arg4);
    int method12(int arg0, int arg1, double arg2, double arg3, int arg4);
    short method13(bool arg0, int arg1, double arg2, float arg3, short arg4);
    bool method14(short arg0, double arg1, int arg2, bool arg3, int arg4);
}
