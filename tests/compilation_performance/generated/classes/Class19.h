#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class19
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(bool arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    void method1(int arg0, bool arg1, short arg2, unsigned arg3, double arg4);
    int method2(unsigned arg0, int arg1, double arg2, int arg3, bool arg4);
    void method3(short arg0, unsigned arg1, float arg2, float arg3, double arg4);
    void method4(unsigned arg0, double arg1, int arg2, double arg3, bool arg4);
    void method5(unsigned arg0, double arg1, bool arg2, float arg3, float arg4);
    void method6(short arg0, int arg1, unsigned arg2, short arg3, bool arg4);
    bool method7(bool arg0, double arg1, bool arg2, bool arg3, float arg4);
    short method8(bool arg0, bool arg1, short arg2, int arg3, unsigned arg4);
    double method9(double arg0, unsigned arg1, short arg2, unsigned arg3, unsigned arg4);
    void method10(int arg0, short arg1, unsigned arg2, double arg3, short arg4);
    short method11(bool arg0, short arg1, int arg2, bool arg3, float arg4);
    unsigned method12(unsigned arg0, unsigned arg1, short arg2, double arg3, bool arg4);
    int method13(short arg0, short arg1, int arg2, unsigned arg3, unsigned arg4);
    short method14(short arg0, int arg1, unsigned arg2, int arg3, float arg4);
};

namespace ns_Class19
{
    bool method0(bool arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    void method1(int arg0, bool arg1, short arg2, unsigned arg3, double arg4);
    int method2(unsigned arg0, int arg1, double arg2, int arg3, bool arg4);
    void method3(short arg0, unsigned arg1, float arg2, float arg3, double arg4);
    void method4(unsigned arg0, double arg1, int arg2, double arg3, bool arg4);
    void method5(unsigned arg0, double arg1, bool arg2, float arg3, float arg4);
    void method6(short arg0, int arg1, unsigned arg2, short arg3, bool arg4);
    bool method7(bool arg0, double arg1, bool arg2, bool arg3, float arg4);
    short method8(bool arg0, bool arg1, short arg2, int arg3, unsigned arg4);
    double method9(double arg0, unsigned arg1, short arg2, unsigned arg3, unsigned arg4);
    void method10(int arg0, short arg1, unsigned arg2, double arg3, short arg4);
    short method11(bool arg0, short arg1, int arg2, bool arg3, float arg4);
    unsigned method12(unsigned arg0, unsigned arg1, short arg2, double arg3, bool arg4);
    int method13(short arg0, short arg1, int arg2, unsigned arg3, unsigned arg4);
    short method14(short arg0, int arg1, unsigned arg2, int arg3, float arg4);
}
