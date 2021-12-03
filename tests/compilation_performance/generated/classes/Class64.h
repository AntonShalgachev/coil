#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class64
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(std::string arg0, float arg1, bool arg2, int arg3, int arg4);
    void method1(std::string const& arg0, std::string arg1, float arg2, std::string_view arg3, std::string const& arg4);
    void method2(bool arg0, float arg1, short arg2, bool arg3, double arg4);
    void method3(unsigned arg0, float arg1, std::string const& arg2, bool arg3, double arg4);
    std::string method4(std::string arg0, std::string_view arg1, std::string_view arg2, std::string_view arg3, std::string const& arg4);
    void method5(std::string_view arg0, std::string const& arg1, float arg2, bool arg3, std::string const& arg4);
    float method6(double arg0, float arg1, short arg2, int arg3, int arg4);
    void method7(bool arg0, short arg1, unsigned arg2, bool arg3, double arg4);
    void method8(std::string const& arg0, bool arg1, short arg2, std::string_view arg3, std::string_view arg4);
    void method9(short arg0, unsigned arg1, std::string_view arg2, short arg3, std::string const& arg4);
    void method10(short arg0, std::string_view arg1, std::string const& arg2, double arg3, short arg4);
    void method11(unsigned arg0, std::string arg1, float arg2, float arg3, std::string_view arg4);
    void method12(std::string_view arg0, unsigned arg1, bool arg2, std::string_view arg3, unsigned arg4);
    float method13(float arg0, int arg1, std::string arg2, short arg3, short arg4);
    std::string method14(int arg0, std::string arg1, float arg2, std::string arg3, std::string arg4);
};

namespace ns_Class64
{
    void method0(std::string arg0, float arg1, bool arg2, int arg3, int arg4);
    void method1(std::string const& arg0, std::string arg1, float arg2, std::string_view arg3, std::string const& arg4);
    void method2(bool arg0, float arg1, short arg2, bool arg3, double arg4);
    void method3(unsigned arg0, float arg1, std::string const& arg2, bool arg3, double arg4);
    std::string method4(std::string arg0, std::string_view arg1, std::string_view arg2, std::string_view arg3, std::string const& arg4);
    void method5(std::string_view arg0, std::string const& arg1, float arg2, bool arg3, std::string const& arg4);
    float method6(double arg0, float arg1, short arg2, int arg3, int arg4);
    void method7(bool arg0, short arg1, unsigned arg2, bool arg3, double arg4);
    void method8(std::string const& arg0, bool arg1, short arg2, std::string_view arg3, std::string_view arg4);
    void method9(short arg0, unsigned arg1, std::string_view arg2, short arg3, std::string const& arg4);
    void method10(short arg0, std::string_view arg1, std::string const& arg2, double arg3, short arg4);
    void method11(unsigned arg0, std::string arg1, float arg2, float arg3, std::string_view arg4);
    void method12(std::string_view arg0, unsigned arg1, bool arg2, std::string_view arg3, unsigned arg4);
    float method13(float arg0, int arg1, std::string arg2, short arg3, short arg4);
    std::string method14(int arg0, std::string arg1, float arg2, std::string arg3, std::string arg4);
}
