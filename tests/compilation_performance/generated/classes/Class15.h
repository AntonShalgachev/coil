#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class15
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(bool arg0, int arg1, std::string arg2, bool arg3, bool arg4);
    short method1(unsigned arg0, std::string_view arg1, short arg2, unsigned arg3, short arg4);
    void method2(std::string const& arg0, double arg1, float arg2, float arg3, std::string arg4);
    void method3(std::string arg0, std::string const& arg1, float arg2, double arg3, std::string arg4);
    void method4(unsigned arg0, bool arg1, bool arg2, std::string_view arg3, short arg4);
    short method5(unsigned arg0, std::string const& arg1, int arg2, std::string const& arg3, short arg4);
    std::string_view method6(float arg0, int arg1, std::string_view arg2, std::string_view arg3, double arg4);
    void method7(bool arg0, std::string_view arg1, float arg2, bool arg3, bool arg4);
    void method8(double arg0, std::string const& arg1, std::string arg2, std::string const& arg3, double arg4);
    void method9(short arg0, std::string_view arg1, std::string arg2, double arg3, std::string arg4);
    void method10(unsigned arg0, std::string arg1, std::string const& arg2, double arg3, bool arg4);
    void method11(unsigned arg0, std::string const& arg1, double arg2, std::string const& arg3, unsigned arg4);
    float method12(std::string const& arg0, unsigned arg1, unsigned arg2, short arg3, float arg4);
    void method13(unsigned arg0, double arg1, double arg2, std::string const& arg3, short arg4);
    int method14(float arg0, bool arg1, bool arg2, int arg3, short arg4);
};

namespace ns_Class15
{
    void method0(bool arg0, int arg1, std::string arg2, bool arg3, bool arg4);
    short method1(unsigned arg0, std::string_view arg1, short arg2, unsigned arg3, short arg4);
    void method2(std::string const& arg0, double arg1, float arg2, float arg3, std::string arg4);
    void method3(std::string arg0, std::string const& arg1, float arg2, double arg3, std::string arg4);
    void method4(unsigned arg0, bool arg1, bool arg2, std::string_view arg3, short arg4);
    short method5(unsigned arg0, std::string const& arg1, int arg2, std::string const& arg3, short arg4);
    std::string_view method6(float arg0, int arg1, std::string_view arg2, std::string_view arg3, double arg4);
    void method7(bool arg0, std::string_view arg1, float arg2, bool arg3, bool arg4);
    void method8(double arg0, std::string const& arg1, std::string arg2, std::string const& arg3, double arg4);
    void method9(short arg0, std::string_view arg1, std::string arg2, double arg3, std::string arg4);
    void method10(unsigned arg0, std::string arg1, std::string const& arg2, double arg3, bool arg4);
    void method11(unsigned arg0, std::string const& arg1, double arg2, std::string const& arg3, unsigned arg4);
    float method12(std::string const& arg0, unsigned arg1, unsigned arg2, short arg3, float arg4);
    void method13(unsigned arg0, double arg1, double arg2, std::string const& arg3, short arg4);
    int method14(float arg0, bool arg1, bool arg2, int arg3, short arg4);
}
