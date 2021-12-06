#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class87
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(unsigned arg0, bool arg1, bool arg2, float arg3, unsigned arg4);
    bool method1(bool arg0, short arg1, unsigned arg2, bool arg3, double arg4);
    void method2(short arg0, float arg1, bool arg2, double arg3, bool arg4);
    double method3(double arg0, short arg1, double arg2, int arg3, double arg4);
    short method4(short arg0, double arg1, unsigned arg2, short arg3, int arg4);
    bool method5(short arg0, unsigned arg1, bool arg2, short arg3, float arg4);
    void method6(int arg0, bool arg1, double arg2, float arg3, bool arg4);
    bool method7(bool arg0, float arg1, int arg2, unsigned arg3, int arg4);
    void method8(double arg0, double arg1, bool arg2, int arg3, int arg4);
    short method9(short arg0, bool arg1, unsigned arg2, float arg3, unsigned arg4);
    short method10(short arg0, float arg1, bool arg2, int arg3, float arg4);
    bool method11(short arg0, bool arg1, int arg2, double arg3, short arg4);
    void method12(unsigned arg0, unsigned arg1, bool arg2, int arg3, double arg4);
    void method13(short arg0, bool arg1, bool arg2, double arg3, int arg4);
    void method14(short arg0, short arg1, short arg2, double arg3, short arg4);
};

namespace ns_Class87
{
    bool method0(unsigned arg0, bool arg1, bool arg2, float arg3, unsigned arg4);
    bool method1(bool arg0, short arg1, unsigned arg2, bool arg3, double arg4);
    void method2(short arg0, float arg1, bool arg2, double arg3, bool arg4);
    double method3(double arg0, short arg1, double arg2, int arg3, double arg4);
    short method4(short arg0, double arg1, unsigned arg2, short arg3, int arg4);
    bool method5(short arg0, unsigned arg1, bool arg2, short arg3, float arg4);
    void method6(int arg0, bool arg1, double arg2, float arg3, bool arg4);
    bool method7(bool arg0, float arg1, int arg2, unsigned arg3, int arg4);
    void method8(double arg0, double arg1, bool arg2, int arg3, int arg4);
    short method9(short arg0, bool arg1, unsigned arg2, float arg3, unsigned arg4);
    short method10(short arg0, float arg1, bool arg2, int arg3, float arg4);
    bool method11(short arg0, bool arg1, int arg2, double arg3, short arg4);
    void method12(unsigned arg0, unsigned arg1, bool arg2, int arg3, double arg4);
    void method13(short arg0, bool arg1, bool arg2, double arg3, int arg4);
    void method14(short arg0, short arg1, short arg2, double arg3, short arg4);
}
