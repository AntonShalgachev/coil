#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class60
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string method0(std::string const& arg0, int arg1, short arg2, float arg3, std::string arg4);
    float method1(float arg0, std::string arg1, std::string arg2, std::string_view arg3, bool arg4);
    void method2(double arg0, bool arg1, bool arg2, std::string arg3, std::string arg4);
    void method3(double arg0, float arg1, std::string arg2, bool arg3, std::string_view arg4);
    double method4(float arg0, int arg1, double arg2, std::string arg3, int arg4);
    float method5(double arg0, std::string const& arg1, bool arg2, std::string_view arg3, float arg4);
    void method6(bool arg0, std::string const& arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method7(short arg0, unsigned arg1, float arg2, short arg3, std::string_view arg4);
    void method8(int arg0, unsigned arg1, int arg2, unsigned arg3, std::string const& arg4);
    void method9(short arg0, unsigned arg1, double arg2, std::string_view arg3, double arg4);
    void method10(unsigned arg0, std::string arg1, unsigned arg2, float arg3, unsigned arg4);
    void method11(std::string_view arg0, bool arg1, int arg2, std::string const& arg3, float arg4);
    float method12(bool arg0, float arg1, int arg2, std::string arg3, double arg4);
    void method13(bool arg0, std::string_view arg1, bool arg2, double arg3, std::string_view arg4);
    std::string const& method14(std::string_view arg0, int arg1, std::string arg2, std::string const& arg3, float arg4);
};

namespace ns_Class60
{
    std::string method0(std::string const& arg0, int arg1, short arg2, float arg3, std::string arg4);
    float method1(float arg0, std::string arg1, std::string arg2, std::string_view arg3, bool arg4);
    void method2(double arg0, bool arg1, bool arg2, std::string arg3, std::string arg4);
    void method3(double arg0, float arg1, std::string arg2, bool arg3, std::string_view arg4);
    double method4(float arg0, int arg1, double arg2, std::string arg3, int arg4);
    float method5(double arg0, std::string const& arg1, bool arg2, std::string_view arg3, float arg4);
    void method6(bool arg0, std::string const& arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method7(short arg0, unsigned arg1, float arg2, short arg3, std::string_view arg4);
    void method8(int arg0, unsigned arg1, int arg2, unsigned arg3, std::string const& arg4);
    void method9(short arg0, unsigned arg1, double arg2, std::string_view arg3, double arg4);
    void method10(unsigned arg0, std::string arg1, unsigned arg2, float arg3, unsigned arg4);
    void method11(std::string_view arg0, bool arg1, int arg2, std::string const& arg3, float arg4);
    float method12(bool arg0, float arg1, int arg2, std::string arg3, double arg4);
    void method13(bool arg0, std::string_view arg1, bool arg2, double arg3, std::string_view arg4);
    std::string const& method14(std::string_view arg0, int arg1, std::string arg2, std::string const& arg3, float arg4);
}
