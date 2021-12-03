#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class50
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, std::string arg1, std::string arg2, double arg3, std::string const& arg4);
    short method1(unsigned arg0, std::string arg1, short arg2, std::string_view arg3, short arg4);
    void method2(int arg0, short arg1, short arg2, int arg3, std::string const& arg4);
    void method3(unsigned arg0, std::string_view arg1, short arg2, bool arg3, std::string const& arg4);
    void method4(double arg0, double arg1, int arg2, std::string_view arg3, int arg4);
    void method5(std::string arg0, short arg1, std::string_view arg2, double arg3, float arg4);
    short method6(short arg0, int arg1, unsigned arg2, unsigned arg3, short arg4);
    unsigned method7(unsigned arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    void method8(unsigned arg0, unsigned arg1, float arg2, std::string const& arg3, std::string arg4);
    std::string method9(std::string const& arg0, std::string arg1, short arg2, double arg3, float arg4);
    std::string_view method10(double arg0, bool arg1, float arg2, short arg3, std::string_view arg4);
    float method11(short arg0, std::string_view arg1, float arg2, short arg3, short arg4);
    void method12(std::string arg0, std::string const& arg1, std::string_view arg2, int arg3, std::string_view arg4);
    void method13(double arg0, std::string arg1, std::string arg2, float arg3, int arg4);
    void method14(std::string_view arg0, std::string_view arg1, std::string_view arg2, int arg3, int arg4);
};

namespace ns_Class50
{
    unsigned method0(unsigned arg0, std::string arg1, std::string arg2, double arg3, std::string const& arg4);
    short method1(unsigned arg0, std::string arg1, short arg2, std::string_view arg3, short arg4);
    void method2(int arg0, short arg1, short arg2, int arg3, std::string const& arg4);
    void method3(unsigned arg0, std::string_view arg1, short arg2, bool arg3, std::string const& arg4);
    void method4(double arg0, double arg1, int arg2, std::string_view arg3, int arg4);
    void method5(std::string arg0, short arg1, std::string_view arg2, double arg3, float arg4);
    short method6(short arg0, int arg1, unsigned arg2, unsigned arg3, short arg4);
    unsigned method7(unsigned arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    void method8(unsigned arg0, unsigned arg1, float arg2, std::string const& arg3, std::string arg4);
    std::string method9(std::string const& arg0, std::string arg1, short arg2, double arg3, float arg4);
    std::string_view method10(double arg0, bool arg1, float arg2, short arg3, std::string_view arg4);
    float method11(short arg0, std::string_view arg1, float arg2, short arg3, short arg4);
    void method12(std::string arg0, std::string const& arg1, std::string_view arg2, int arg3, std::string_view arg4);
    void method13(double arg0, std::string arg1, std::string arg2, float arg3, int arg4);
    void method14(std::string_view arg0, std::string_view arg1, std::string_view arg2, int arg3, int arg4);
}
