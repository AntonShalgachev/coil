#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class69
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(std::string arg0, std::string_view arg1, bool arg2, unsigned arg3, bool arg4);
    double method1(double arg0, std::string_view arg1, float arg2, float arg3, short arg4);
    void method2(std::string arg0, short arg1, bool arg2, bool arg3, std::string const& arg4);
    double method3(std::string_view arg0, double arg1, bool arg2, double arg3, std::string arg4);
    std::string method4(bool arg0, std::string arg1, bool arg2, double arg3, std::string arg4);
    unsigned method5(std::string const& arg0, double arg1, unsigned arg2, bool arg3, unsigned arg4);
    void method6(std::string arg0, unsigned arg1, unsigned arg2, std::string arg3, std::string_view arg4);
    std::string_view method7(std::string arg0, unsigned arg1, double arg2, std::string_view arg3, bool arg4);
    unsigned method8(short arg0, unsigned arg1, double arg2, std::string const& arg3, float arg4);
    short method9(short arg0, double arg1, std::string_view arg2, std::string arg3, std::string const& arg4);
    std::string method10(unsigned arg0, double arg1, std::string arg2, std::string arg3, float arg4);
    void method11(std::string arg0, unsigned arg1, unsigned arg2, std::string const& arg3, std::string const& arg4);
    void method12(short arg0, double arg1, float arg2, float arg3, std::string const& arg4);
    std::string const& method13(double arg0, unsigned arg1, std::string_view arg2, bool arg3, std::string const& arg4);
    std::string const& method14(unsigned arg0, std::string const& arg1, std::string arg2, int arg3, int arg4);
};

namespace ns_Class69
{
    void method0(std::string arg0, std::string_view arg1, bool arg2, unsigned arg3, bool arg4);
    double method1(double arg0, std::string_view arg1, float arg2, float arg3, short arg4);
    void method2(std::string arg0, short arg1, bool arg2, bool arg3, std::string const& arg4);
    double method3(std::string_view arg0, double arg1, bool arg2, double arg3, std::string arg4);
    std::string method4(bool arg0, std::string arg1, bool arg2, double arg3, std::string arg4);
    unsigned method5(std::string const& arg0, double arg1, unsigned arg2, bool arg3, unsigned arg4);
    void method6(std::string arg0, unsigned arg1, unsigned arg2, std::string arg3, std::string_view arg4);
    std::string_view method7(std::string arg0, unsigned arg1, double arg2, std::string_view arg3, bool arg4);
    unsigned method8(short arg0, unsigned arg1, double arg2, std::string const& arg3, float arg4);
    short method9(short arg0, double arg1, std::string_view arg2, std::string arg3, std::string const& arg4);
    std::string method10(unsigned arg0, double arg1, std::string arg2, std::string arg3, float arg4);
    void method11(std::string arg0, unsigned arg1, unsigned arg2, std::string const& arg3, std::string const& arg4);
    void method12(short arg0, double arg1, float arg2, float arg3, std::string const& arg4);
    std::string const& method13(double arg0, unsigned arg1, std::string_view arg2, bool arg3, std::string const& arg4);
    std::string const& method14(unsigned arg0, std::string const& arg1, std::string arg2, int arg3, int arg4);
}
