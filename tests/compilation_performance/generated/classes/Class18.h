#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class18
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(std::string arg0, std::string arg1, bool arg2, bool arg3, short arg4);
    void method1(float arg0, bool arg1, std::string_view arg2, float arg3, std::string const& arg4);
    unsigned method2(unsigned arg0, bool arg1, short arg2, bool arg3, std::string arg4);
    std::string method3(bool arg0, short arg1, std::string arg2, std::string arg3, bool arg4);
    void method4(std::string_view arg0, std::string const& arg1, double arg2, short arg3, short arg4);
    void method5(double arg0, int arg1, short arg2, short arg3, double arg4);
    void method6(std::string const& arg0, int arg1, std::string_view arg2, std::string arg3, unsigned arg4);
    float method7(float arg0, std::string arg1, std::string const& arg2, std::string const& arg3, double arg4);
    void method8(std::string const& arg0, short arg1, std::string_view arg2, std::string_view arg3, short arg4);
    void method9(short arg0, unsigned arg1, bool arg2, std::string const& arg3, std::string const& arg4);
    void method10(double arg0, float arg1, double arg2, unsigned arg3, short arg4);
    void method11(double arg0, float arg1, int arg2, float arg3, unsigned arg4);
    void method12(bool arg0, float arg1, short arg2, std::string const& arg3, std::string const& arg4);
    std::string const& method13(int arg0, bool arg1, unsigned arg2, int arg3, std::string const& arg4);
    short method14(std::string_view arg0, float arg1, short arg2, short arg3, short arg4);
};

namespace ns_Class18
{
    short method0(std::string arg0, std::string arg1, bool arg2, bool arg3, short arg4);
    void method1(float arg0, bool arg1, std::string_view arg2, float arg3, std::string const& arg4);
    unsigned method2(unsigned arg0, bool arg1, short arg2, bool arg3, std::string arg4);
    std::string method3(bool arg0, short arg1, std::string arg2, std::string arg3, bool arg4);
    void method4(std::string_view arg0, std::string const& arg1, double arg2, short arg3, short arg4);
    void method5(double arg0, int arg1, short arg2, short arg3, double arg4);
    void method6(std::string const& arg0, int arg1, std::string_view arg2, std::string arg3, unsigned arg4);
    float method7(float arg0, std::string arg1, std::string const& arg2, std::string const& arg3, double arg4);
    void method8(std::string const& arg0, short arg1, std::string_view arg2, std::string_view arg3, short arg4);
    void method9(short arg0, unsigned arg1, bool arg2, std::string const& arg3, std::string const& arg4);
    void method10(double arg0, float arg1, double arg2, unsigned arg3, short arg4);
    void method11(double arg0, float arg1, int arg2, float arg3, unsigned arg4);
    void method12(bool arg0, float arg1, short arg2, std::string const& arg3, std::string const& arg4);
    std::string const& method13(int arg0, bool arg1, unsigned arg2, int arg3, std::string const& arg4);
    short method14(std::string_view arg0, float arg1, short arg2, short arg3, short arg4);
}
