#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class66
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, bool arg1, short arg2, int arg3, unsigned arg4);
    void method1(float arg0, std::string_view arg1, std::string const& arg2, std::string arg3, std::string arg4);
    void method2(bool arg0, double arg1, float arg2, std::string arg3, float arg4);
    void method3(std::string arg0, int arg1, unsigned arg2, float arg3, std::string const& arg4);
    std::string method4(std::string const& arg0, int arg1, std::string const& arg2, bool arg3, std::string arg4);
    std::string method5(float arg0, short arg1, double arg2, std::string arg3, std::string arg4);
    std::string method6(std::string_view arg0, float arg1, unsigned arg2, bool arg3, std::string arg4);
    std::string const& method7(float arg0, std::string const& arg1, double arg2, double arg3, std::string const& arg4);
    void method8(short arg0, short arg1, short arg2, std::string const& arg3, short arg4);
    void method9(bool arg0, short arg1, std::string arg2, std::string arg3, unsigned arg4);
    std::string method10(bool arg0, std::string arg1, float arg2, std::string const& arg3, unsigned arg4);
    void method11(int arg0, std::string_view arg1, int arg2, std::string const& arg3, unsigned arg4);
    float method12(float arg0, std::string const& arg1, double arg2, float arg3, float arg4);
    double method13(int arg0, bool arg1, short arg2, int arg3, double arg4);
    std::string_view method14(double arg0, short arg1, std::string arg2, std::string_view arg3, float arg4);
};

namespace ns_Class66
{
    void method0(float arg0, bool arg1, short arg2, int arg3, unsigned arg4);
    void method1(float arg0, std::string_view arg1, std::string const& arg2, std::string arg3, std::string arg4);
    void method2(bool arg0, double arg1, float arg2, std::string arg3, float arg4);
    void method3(std::string arg0, int arg1, unsigned arg2, float arg3, std::string const& arg4);
    std::string method4(std::string const& arg0, int arg1, std::string const& arg2, bool arg3, std::string arg4);
    std::string method5(float arg0, short arg1, double arg2, std::string arg3, std::string arg4);
    std::string method6(std::string_view arg0, float arg1, unsigned arg2, bool arg3, std::string arg4);
    std::string const& method7(float arg0, std::string const& arg1, double arg2, double arg3, std::string const& arg4);
    void method8(short arg0, short arg1, short arg2, std::string const& arg3, short arg4);
    void method9(bool arg0, short arg1, std::string arg2, std::string arg3, unsigned arg4);
    std::string method10(bool arg0, std::string arg1, float arg2, std::string const& arg3, unsigned arg4);
    void method11(int arg0, std::string_view arg1, int arg2, std::string const& arg3, unsigned arg4);
    float method12(float arg0, std::string const& arg1, double arg2, float arg3, float arg4);
    double method13(int arg0, bool arg1, short arg2, int arg3, double arg4);
    std::string_view method14(double arg0, short arg1, std::string arg2, std::string_view arg3, float arg4);
}
