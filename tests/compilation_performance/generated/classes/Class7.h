#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class7
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, float arg1, bool arg2, bool arg3, int arg4);
    double method1(double arg0, int arg1, double arg2, std::string arg3, std::string arg4);
    std::string const& method2(bool arg0, std::string const& arg1, std::string const& arg2, int arg3, float arg4);
    void method3(double arg0, unsigned arg1, double arg2, bool arg3, bool arg4);
    short method4(float arg0, float arg1, std::string_view arg2, short arg3, unsigned arg4);
    void method5(std::string arg0, short arg1, unsigned arg2, unsigned arg3, int arg4);
    double method6(std::string arg0, std::string const& arg1, short arg2, double arg3, int arg4);
    void method7(int arg0, std::string_view arg1, bool arg2, bool arg3, std::string_view arg4);
    float method8(float arg0, short arg1, short arg2, bool arg3, float arg4);
    float method9(short arg0, int arg1, bool arg2, std::string arg3, float arg4);
    void method10(std::string arg0, double arg1, short arg2, std::string arg3, float arg4);
    std::string method11(float arg0, int arg1, double arg2, std::string arg3, int arg4);
    void method12(double arg0, int arg1, std::string arg2, bool arg3, float arg4);
    short method13(int arg0, double arg1, short arg2, float arg3, unsigned arg4);
    std::string method14(std::string arg0, std::string arg1, double arg2, std::string const& arg3, std::string arg4);
};

namespace ns_Class7
{
    void method0(int arg0, float arg1, bool arg2, bool arg3, int arg4);
    double method1(double arg0, int arg1, double arg2, std::string arg3, std::string arg4);
    std::string const& method2(bool arg0, std::string const& arg1, std::string const& arg2, int arg3, float arg4);
    void method3(double arg0, unsigned arg1, double arg2, bool arg3, bool arg4);
    short method4(float arg0, float arg1, std::string_view arg2, short arg3, unsigned arg4);
    void method5(std::string arg0, short arg1, unsigned arg2, unsigned arg3, int arg4);
    double method6(std::string arg0, std::string const& arg1, short arg2, double arg3, int arg4);
    void method7(int arg0, std::string_view arg1, bool arg2, bool arg3, std::string_view arg4);
    float method8(float arg0, short arg1, short arg2, bool arg3, float arg4);
    float method9(short arg0, int arg1, bool arg2, std::string arg3, float arg4);
    void method10(std::string arg0, double arg1, short arg2, std::string arg3, float arg4);
    std::string method11(float arg0, int arg1, double arg2, std::string arg3, int arg4);
    void method12(double arg0, int arg1, std::string arg2, bool arg3, float arg4);
    short method13(int arg0, double arg1, short arg2, float arg3, unsigned arg4);
    std::string method14(std::string arg0, std::string arg1, double arg2, std::string const& arg3, std::string arg4);
}
