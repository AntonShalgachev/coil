#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class50
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(short arg0, double arg1, bool arg2, bool arg3, unsigned arg4);
    void method1(unsigned arg0, bool arg1, int arg2, unsigned arg3, unsigned arg4);
    void method2(float arg0, bool arg1, short arg2, bool arg3, unsigned arg4);
    unsigned method3(unsigned arg0, bool arg1, int arg2, short arg3, unsigned arg4);
    void method4(int arg0, float arg1, bool arg2, short arg3, int arg4);
    void method5(int arg0, int arg1, int arg2, double arg3, int arg4);
    unsigned method6(unsigned arg0, unsigned arg1, short arg2, short arg3, unsigned arg4);
    bool method7(bool arg0, bool arg1, double arg2, bool arg3, unsigned arg4);
    bool method8(bool arg0, int arg1, short arg2, double arg3, bool arg4);
    int method9(int arg0, unsigned arg1, float arg2, double arg3, bool arg4);
    void method10(int arg0, unsigned arg1, bool arg2, unsigned arg3, bool arg4);
    void method11(double arg0, int arg1, int arg2, double arg3, float arg4);
    short method12(bool arg0, int arg1, short arg2, float arg3, int arg4);
    void method13(unsigned arg0, double arg1, short arg2, unsigned arg3, bool arg4);
    unsigned method14(short arg0, unsigned arg1, double arg2, bool arg3, short arg4);
};

namespace ns_Class50
{
    short method0(short arg0, double arg1, bool arg2, bool arg3, unsigned arg4);
    void method1(unsigned arg0, bool arg1, int arg2, unsigned arg3, unsigned arg4);
    void method2(float arg0, bool arg1, short arg2, bool arg3, unsigned arg4);
    unsigned method3(unsigned arg0, bool arg1, int arg2, short arg3, unsigned arg4);
    void method4(int arg0, float arg1, bool arg2, short arg3, int arg4);
    void method5(int arg0, int arg1, int arg2, double arg3, int arg4);
    unsigned method6(unsigned arg0, unsigned arg1, short arg2, short arg3, unsigned arg4);
    bool method7(bool arg0, bool arg1, double arg2, bool arg3, unsigned arg4);
    bool method8(bool arg0, int arg1, short arg2, double arg3, bool arg4);
    int method9(int arg0, unsigned arg1, float arg2, double arg3, bool arg4);
    void method10(int arg0, unsigned arg1, bool arg2, unsigned arg3, bool arg4);
    void method11(double arg0, int arg1, int arg2, double arg3, float arg4);
    short method12(bool arg0, int arg1, short arg2, float arg3, int arg4);
    void method13(unsigned arg0, double arg1, short arg2, unsigned arg3, bool arg4);
    unsigned method14(short arg0, unsigned arg1, double arg2, bool arg3, short arg4);
}
