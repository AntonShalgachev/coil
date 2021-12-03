#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class71
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(std::string arg0, float arg1, std::string_view arg2, double arg3, bool arg4);
    void method1(unsigned arg0, std::string arg1, float arg2, std::string const& arg3, int arg4);
    void method2(unsigned arg0, int arg1, std::string const& arg2, std::string arg3, unsigned arg4);
    void method3(float arg0, float arg1, short arg2, std::string arg3, short arg4);
    void method4(double arg0, unsigned arg1, short arg2, int arg3, std::string_view arg4);
    float method5(std::string const& arg0, unsigned arg1, unsigned arg2, float arg3, std::string_view arg4);
    void method6(unsigned arg0, int arg1, bool arg2, float arg3, bool arg4);
    void method7(bool arg0, unsigned arg1, std::string arg2, unsigned arg3, double arg4);
    std::string method8(double arg0, unsigned arg1, unsigned arg2, std::string arg3, float arg4);
    void method9(float arg0, int arg1, short arg2, std::string const& arg3, bool arg4);
    void method10(std::string const& arg0, float arg1, int arg2, float arg3, short arg4);
    void method11(float arg0, std::string const& arg1, std::string arg2, std::string_view arg3, float arg4);
    short method12(std::string_view arg0, std::string const& arg1, short arg2, std::string_view arg3, short arg4);
    void method13(double arg0, std::string arg1, bool arg2, std::string const& arg3, unsigned arg4);
    void method14(std::string arg0, std::string arg1, int arg2, std::string const& arg3, float arg4);
};

namespace ns_Class71
{
    double method0(std::string arg0, float arg1, std::string_view arg2, double arg3, bool arg4);
    void method1(unsigned arg0, std::string arg1, float arg2, std::string const& arg3, int arg4);
    void method2(unsigned arg0, int arg1, std::string const& arg2, std::string arg3, unsigned arg4);
    void method3(float arg0, float arg1, short arg2, std::string arg3, short arg4);
    void method4(double arg0, unsigned arg1, short arg2, int arg3, std::string_view arg4);
    float method5(std::string const& arg0, unsigned arg1, unsigned arg2, float arg3, std::string_view arg4);
    void method6(unsigned arg0, int arg1, bool arg2, float arg3, bool arg4);
    void method7(bool arg0, unsigned arg1, std::string arg2, unsigned arg3, double arg4);
    std::string method8(double arg0, unsigned arg1, unsigned arg2, std::string arg3, float arg4);
    void method9(float arg0, int arg1, short arg2, std::string const& arg3, bool arg4);
    void method10(std::string const& arg0, float arg1, int arg2, float arg3, short arg4);
    void method11(float arg0, std::string const& arg1, std::string arg2, std::string_view arg3, float arg4);
    short method12(std::string_view arg0, std::string const& arg1, short arg2, std::string_view arg3, short arg4);
    void method13(double arg0, std::string arg1, bool arg2, std::string const& arg3, unsigned arg4);
    void method14(std::string arg0, std::string arg1, int arg2, std::string const& arg3, float arg4);
}
