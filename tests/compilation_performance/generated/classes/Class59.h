#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class59
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, short arg1, short arg2, double arg3, bool arg4);
    short method1(int arg0, float arg1, int arg2, short arg3, short arg4);
    int method2(bool arg0, float arg1, int arg2, unsigned arg3, short arg4);
    void method3(bool arg0, double arg1, short arg2, double arg3, short arg4);
    double method4(int arg0, unsigned arg1, short arg2, double arg3, float arg4);
    unsigned method5(unsigned arg0, short arg1, int arg2, unsigned arg3, double arg4);
    bool method6(bool arg0, int arg1, bool arg2, int arg3, int arg4);
    double method7(double arg0, bool arg1, double arg2, int arg3, int arg4);
    void method8(int arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    void method9(int arg0, bool arg1, float arg2, double arg3, double arg4);
    void method10(short arg0, bool arg1, short arg2, int arg3, int arg4);
    bool method11(double arg0, bool arg1, bool arg2, unsigned arg3, unsigned arg4);
    short method12(unsigned arg0, int arg1, short arg2, short arg3, short arg4);
    unsigned method13(float arg0, unsigned arg1, int arg2, short arg3, short arg4);
    void method14(double arg0, short arg1, double arg2, double arg3, float arg4);
};

namespace ns_Class59
{
    void method0(double arg0, short arg1, short arg2, double arg3, bool arg4);
    short method1(int arg0, float arg1, int arg2, short arg3, short arg4);
    int method2(bool arg0, float arg1, int arg2, unsigned arg3, short arg4);
    void method3(bool arg0, double arg1, short arg2, double arg3, short arg4);
    double method4(int arg0, unsigned arg1, short arg2, double arg3, float arg4);
    unsigned method5(unsigned arg0, short arg1, int arg2, unsigned arg3, double arg4);
    bool method6(bool arg0, int arg1, bool arg2, int arg3, int arg4);
    double method7(double arg0, bool arg1, double arg2, int arg3, int arg4);
    void method8(int arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    void method9(int arg0, bool arg1, float arg2, double arg3, double arg4);
    void method10(short arg0, bool arg1, short arg2, int arg3, int arg4);
    bool method11(double arg0, bool arg1, bool arg2, unsigned arg3, unsigned arg4);
    short method12(unsigned arg0, int arg1, short arg2, short arg3, short arg4);
    unsigned method13(float arg0, unsigned arg1, int arg2, short arg3, short arg4);
    void method14(double arg0, short arg1, double arg2, double arg3, float arg4);
}
