#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class3
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, short arg1, unsigned arg2, int arg3, unsigned arg4);
    void method1(int arg0, double arg1, bool arg2, float arg3, int arg4);
    void method2(float arg0, float arg1, float arg2, unsigned arg3, float arg4);
    void method3(int arg0, int arg1, float arg2, bool arg3, short arg4);
    void method4(unsigned arg0, unsigned arg1, short arg2, unsigned arg3, float arg4);
    double method5(double arg0, short arg1, unsigned arg2, bool arg3, float arg4);
    void method6(int arg0, short arg1, unsigned arg2, unsigned arg3, int arg4);
    bool method7(bool arg0, unsigned arg1, unsigned arg2, double arg3, bool arg4);
    short method8(unsigned arg0, short arg1, unsigned arg2, int arg3, int arg4);
    short method9(bool arg0, short arg1, float arg2, short arg3, short arg4);
    double method10(unsigned arg0, double arg1, short arg2, double arg3, unsigned arg4);
    unsigned method11(unsigned arg0, unsigned arg1, unsigned arg2, bool arg3, int arg4);
    unsigned method12(double arg0, unsigned arg1, bool arg2, unsigned arg3, int arg4);
    void method13(unsigned arg0, float arg1, int arg2, bool arg3, double arg4);
    short method14(short arg0, short arg1, double arg2, float arg3, unsigned arg4);
};

namespace ns_Class3
{
    void method0(int arg0, short arg1, unsigned arg2, int arg3, unsigned arg4);
    void method1(int arg0, double arg1, bool arg2, float arg3, int arg4);
    void method2(float arg0, float arg1, float arg2, unsigned arg3, float arg4);
    void method3(int arg0, int arg1, float arg2, bool arg3, short arg4);
    void method4(unsigned arg0, unsigned arg1, short arg2, unsigned arg3, float arg4);
    double method5(double arg0, short arg1, unsigned arg2, bool arg3, float arg4);
    void method6(int arg0, short arg1, unsigned arg2, unsigned arg3, int arg4);
    bool method7(bool arg0, unsigned arg1, unsigned arg2, double arg3, bool arg4);
    short method8(unsigned arg0, short arg1, unsigned arg2, int arg3, int arg4);
    short method9(bool arg0, short arg1, float arg2, short arg3, short arg4);
    double method10(unsigned arg0, double arg1, short arg2, double arg3, unsigned arg4);
    unsigned method11(unsigned arg0, unsigned arg1, unsigned arg2, bool arg3, int arg4);
    unsigned method12(double arg0, unsigned arg1, bool arg2, unsigned arg3, int arg4);
    void method13(unsigned arg0, float arg1, int arg2, bool arg3, double arg4);
    short method14(short arg0, short arg1, double arg2, float arg3, unsigned arg4);
}
