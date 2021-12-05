#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class31
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(short arg0, double arg1, double arg2, int arg3, int arg4);
    float method1(float arg0, bool arg1, bool arg2, int arg3, float arg4);
    void method2(unsigned arg0, int arg1, float arg2, float arg3, short arg4);
    short method3(int arg0, short arg1, bool arg2, float arg3, short arg4);
    unsigned method4(unsigned arg0, float arg1, unsigned arg2, unsigned arg3, short arg4);
    bool method5(unsigned arg0, bool arg1, bool arg2, bool arg3, short arg4);
    double method6(int arg0, short arg1, double arg2, unsigned arg3, unsigned arg4);
    short method7(short arg0, int arg1, bool arg2, float arg3, float arg4);
    float method8(float arg0, unsigned arg1, short arg2, unsigned arg3, bool arg4);
    void method9(double arg0, bool arg1, double arg2, short arg3, int arg4);
    void method10(bool arg0, int arg1, float arg2, bool arg3, unsigned arg4);
    int method11(float arg0, bool arg1, int arg2, double arg3, short arg4);
    bool method12(unsigned arg0, float arg1, bool arg2, unsigned arg3, unsigned arg4);
    int method13(float arg0, unsigned arg1, double arg2, int arg3, unsigned arg4);
    void method14(unsigned arg0, double arg1, double arg2, bool arg3, bool arg4);
};

namespace ns_Class31
{
    double method0(short arg0, double arg1, double arg2, int arg3, int arg4);
    float method1(float arg0, bool arg1, bool arg2, int arg3, float arg4);
    void method2(unsigned arg0, int arg1, float arg2, float arg3, short arg4);
    short method3(int arg0, short arg1, bool arg2, float arg3, short arg4);
    unsigned method4(unsigned arg0, float arg1, unsigned arg2, unsigned arg3, short arg4);
    bool method5(unsigned arg0, bool arg1, bool arg2, bool arg3, short arg4);
    double method6(int arg0, short arg1, double arg2, unsigned arg3, unsigned arg4);
    short method7(short arg0, int arg1, bool arg2, float arg3, float arg4);
    float method8(float arg0, unsigned arg1, short arg2, unsigned arg3, bool arg4);
    void method9(double arg0, bool arg1, double arg2, short arg3, int arg4);
    void method10(bool arg0, int arg1, float arg2, bool arg3, unsigned arg4);
    int method11(float arg0, bool arg1, int arg2, double arg3, short arg4);
    bool method12(unsigned arg0, float arg1, bool arg2, unsigned arg3, unsigned arg4);
    int method13(float arg0, unsigned arg1, double arg2, int arg3, unsigned arg4);
    void method14(unsigned arg0, double arg1, double arg2, bool arg3, bool arg4);
}
