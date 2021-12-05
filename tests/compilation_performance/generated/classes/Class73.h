#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class73
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(bool arg0, short arg1, unsigned arg2, short arg3, unsigned arg4);
    double method1(double arg0, float arg1, short arg2, int arg3, bool arg4);
    short method2(bool arg0, short arg1, unsigned arg2, float arg3, float arg4);
    void method3(unsigned arg0, int arg1, unsigned arg2, double arg3, unsigned arg4);
    bool method4(int arg0, int arg1, bool arg2, unsigned arg3, bool arg4);
    bool method5(int arg0, short arg1, bool arg2, short arg3, short arg4);
    int method6(int arg0, float arg1, double arg2, unsigned arg3, short arg4);
    int method7(int arg0, int arg1, double arg2, int arg3, unsigned arg4);
    void method8(int arg0, int arg1, unsigned arg2, float arg3, float arg4);
    bool method9(bool arg0, short arg1, short arg2, double arg3, short arg4);
    bool method10(bool arg0, bool arg1, double arg2, int arg3, bool arg4);
    short method11(unsigned arg0, short arg1, bool arg2, short arg3, unsigned arg4);
    int method12(short arg0, bool arg1, int arg2, int arg3, short arg4);
    double method13(bool arg0, unsigned arg1, double arg2, unsigned arg3, double arg4);
    double method14(unsigned arg0, unsigned arg1, double arg2, double arg3, bool arg4);
};

namespace ns_Class73
{
    void method0(bool arg0, short arg1, unsigned arg2, short arg3, unsigned arg4);
    double method1(double arg0, float arg1, short arg2, int arg3, bool arg4);
    short method2(bool arg0, short arg1, unsigned arg2, float arg3, float arg4);
    void method3(unsigned arg0, int arg1, unsigned arg2, double arg3, unsigned arg4);
    bool method4(int arg0, int arg1, bool arg2, unsigned arg3, bool arg4);
    bool method5(int arg0, short arg1, bool arg2, short arg3, short arg4);
    int method6(int arg0, float arg1, double arg2, unsigned arg3, short arg4);
    int method7(int arg0, int arg1, double arg2, int arg3, unsigned arg4);
    void method8(int arg0, int arg1, unsigned arg2, float arg3, float arg4);
    bool method9(bool arg0, short arg1, short arg2, double arg3, short arg4);
    bool method10(bool arg0, bool arg1, double arg2, int arg3, bool arg4);
    short method11(unsigned arg0, short arg1, bool arg2, short arg3, unsigned arg4);
    int method12(short arg0, bool arg1, int arg2, int arg3, short arg4);
    double method13(bool arg0, unsigned arg1, double arg2, unsigned arg3, double arg4);
    double method14(unsigned arg0, unsigned arg1, double arg2, double arg3, bool arg4);
}
