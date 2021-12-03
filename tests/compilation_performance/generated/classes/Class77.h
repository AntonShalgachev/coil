#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class77
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string_view method0(std::string arg0, std::string_view arg1, std::string const& arg2, int arg3, std::string const& arg4);
    std::string method1(std::string arg0, bool arg1, short arg2, int arg3, unsigned arg4);
    float method2(unsigned arg0, float arg1, double arg2, std::string_view arg3, std::string const& arg4);
    void method3(float arg0, std::string_view arg1, std::string arg2, unsigned arg3, std::string arg4);
    void method4(int arg0, double arg1, unsigned arg2, std::string const& arg3, std::string arg4);
    void method5(bool arg0, std::string const& arg1, unsigned arg2, int arg3, double arg4);
    void method6(short arg0, std::string const& arg1, int arg2, short arg3, bool arg4);
    float method7(float arg0, std::string arg1, unsigned arg2, float arg3, bool arg4);
    int method8(std::string_view arg0, int arg1, std::string_view arg2, std::string arg3, short arg4);
    void method9(float arg0, std::string arg1, float arg2, std::string_view arg3, std::string_view arg4);
    void method10(float arg0, std::string arg1, std::string const& arg2, short arg3, float arg4);
    short method11(bool arg0, double arg1, short arg2, std::string arg3, float arg4);
    void method12(double arg0, unsigned arg1, std::string arg2, bool arg3, std::string const& arg4);
    void method13(float arg0, std::string const& arg1, int arg2, std::string_view arg3, std::string arg4);
    void method14(std::string arg0, std::string arg1, std::string arg2, std::string arg3, int arg4);
};

namespace ns_Class77
{
    std::string_view method0(std::string arg0, std::string_view arg1, std::string const& arg2, int arg3, std::string const& arg4);
    std::string method1(std::string arg0, bool arg1, short arg2, int arg3, unsigned arg4);
    float method2(unsigned arg0, float arg1, double arg2, std::string_view arg3, std::string const& arg4);
    void method3(float arg0, std::string_view arg1, std::string arg2, unsigned arg3, std::string arg4);
    void method4(int arg0, double arg1, unsigned arg2, std::string const& arg3, std::string arg4);
    void method5(bool arg0, std::string const& arg1, unsigned arg2, int arg3, double arg4);
    void method6(short arg0, std::string const& arg1, int arg2, short arg3, bool arg4);
    float method7(float arg0, std::string arg1, unsigned arg2, float arg3, bool arg4);
    int method8(std::string_view arg0, int arg1, std::string_view arg2, std::string arg3, short arg4);
    void method9(float arg0, std::string arg1, float arg2, std::string_view arg3, std::string_view arg4);
    void method10(float arg0, std::string arg1, std::string const& arg2, short arg3, float arg4);
    short method11(bool arg0, double arg1, short arg2, std::string arg3, float arg4);
    void method12(double arg0, unsigned arg1, std::string arg2, bool arg3, std::string const& arg4);
    void method13(float arg0, std::string const& arg1, int arg2, std::string_view arg3, std::string arg4);
    void method14(std::string arg0, std::string arg1, std::string arg2, std::string arg3, int arg4);
}
