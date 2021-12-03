#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class2
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string method0(double arg0, double arg1, double arg2, int arg3, std::string arg4);
    int method1(int arg0, double arg1, double arg2, int arg3, double arg4);
    int method2(float arg0, std::string_view arg1, unsigned arg2, std::string const& arg3, int arg4);
    void method3(std::string arg0, unsigned arg1, double arg2, int arg3, std::string const& arg4);
    void method4(std::string arg0, std::string arg1, std::string const& arg2, unsigned arg3, int arg4);
    void method5(int arg0, unsigned arg1, short arg2, int arg3, unsigned arg4);
    void method6(unsigned arg0, unsigned arg1, std::string const& arg2, float arg3, std::string const& arg4);
    std::string const& method7(float arg0, std::string_view arg1, double arg2, float arg3, std::string const& arg4);
    int method8(int arg0, short arg1, int arg2, float arg3, unsigned arg4);
    unsigned method9(unsigned arg0, bool arg1, short arg2, unsigned arg3, unsigned arg4);
    void method10(unsigned arg0, unsigned arg1, int arg2, int arg3, std::string_view arg4);
    float method11(float arg0, std::string_view arg1, int arg2, std::string arg3, bool arg4);
    std::string method12(bool arg0, float arg1, std::string arg2, int arg3, std::string_view arg4);
    void method13(bool arg0, short arg1, std::string_view arg2, std::string_view arg3, short arg4);
    void method14(std::string arg0, float arg1, float arg2, std::string const& arg3, bool arg4);
};

namespace ns_Class2
{
    std::string method0(double arg0, double arg1, double arg2, int arg3, std::string arg4);
    int method1(int arg0, double arg1, double arg2, int arg3, double arg4);
    int method2(float arg0, std::string_view arg1, unsigned arg2, std::string const& arg3, int arg4);
    void method3(std::string arg0, unsigned arg1, double arg2, int arg3, std::string const& arg4);
    void method4(std::string arg0, std::string arg1, std::string const& arg2, unsigned arg3, int arg4);
    void method5(int arg0, unsigned arg1, short arg2, int arg3, unsigned arg4);
    void method6(unsigned arg0, unsigned arg1, std::string const& arg2, float arg3, std::string const& arg4);
    std::string const& method7(float arg0, std::string_view arg1, double arg2, float arg3, std::string const& arg4);
    int method8(int arg0, short arg1, int arg2, float arg3, unsigned arg4);
    unsigned method9(unsigned arg0, bool arg1, short arg2, unsigned arg3, unsigned arg4);
    void method10(unsigned arg0, unsigned arg1, int arg2, int arg3, std::string_view arg4);
    float method11(float arg0, std::string_view arg1, int arg2, std::string arg3, bool arg4);
    std::string method12(bool arg0, float arg1, std::string arg2, int arg3, std::string_view arg4);
    void method13(bool arg0, short arg1, std::string_view arg2, std::string_view arg3, short arg4);
    void method14(std::string arg0, float arg1, float arg2, std::string const& arg3, bool arg4);
}
