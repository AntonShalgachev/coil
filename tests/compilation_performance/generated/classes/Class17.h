#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class17
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(unsigned arg0, unsigned arg1, int arg2, unsigned arg3, short arg4);
    short method1(int arg0, double arg1, bool arg2, double arg3, short arg4);
    void method2(short arg0, double arg1, short arg2, double arg3, unsigned arg4);
    int method3(bool arg0, bool arg1, int arg2, int arg3, int arg4);
    void method4(int arg0, int arg1, unsigned arg2, float arg3, double arg4);
    void method5(short arg0, float arg1, double arg2, int arg3, short arg4);
    bool method6(unsigned arg0, bool arg1, unsigned arg2, int arg3, short arg4);
    void method7(unsigned arg0, bool arg1, int arg2, short arg3, double arg4);
    void method8(bool arg0, int arg1, float arg2, double arg3, bool arg4);
    void method9(bool arg0, unsigned arg1, bool arg2, unsigned arg3, bool arg4);
    short method10(bool arg0, short arg1, bool arg2, short arg3, int arg4);
    double method11(unsigned arg0, double arg1, int arg2, double arg3, float arg4);
    void method12(short arg0, float arg1, float arg2, short arg3, unsigned arg4);
    bool method13(unsigned arg0, bool arg1, double arg2, bool arg3, unsigned arg4);
    void method14(short arg0, int arg1, int arg2, unsigned arg3, bool arg4);
};

namespace ns_Class17
{
    short method0(unsigned arg0, unsigned arg1, int arg2, unsigned arg3, short arg4);
    short method1(int arg0, double arg1, bool arg2, double arg3, short arg4);
    void method2(short arg0, double arg1, short arg2, double arg3, unsigned arg4);
    int method3(bool arg0, bool arg1, int arg2, int arg3, int arg4);
    void method4(int arg0, int arg1, unsigned arg2, float arg3, double arg4);
    void method5(short arg0, float arg1, double arg2, int arg3, short arg4);
    bool method6(unsigned arg0, bool arg1, unsigned arg2, int arg3, short arg4);
    void method7(unsigned arg0, bool arg1, int arg2, short arg3, double arg4);
    void method8(bool arg0, int arg1, float arg2, double arg3, bool arg4);
    void method9(bool arg0, unsigned arg1, bool arg2, unsigned arg3, bool arg4);
    short method10(bool arg0, short arg1, bool arg2, short arg3, int arg4);
    double method11(unsigned arg0, double arg1, int arg2, double arg3, float arg4);
    void method12(short arg0, float arg1, float arg2, short arg3, unsigned arg4);
    bool method13(unsigned arg0, bool arg1, double arg2, bool arg3, unsigned arg4);
    void method14(short arg0, int arg1, int arg2, unsigned arg3, bool arg4);
}
