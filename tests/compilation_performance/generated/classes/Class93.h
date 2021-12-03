#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class93
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string method0(std::string arg0, bool arg1, std::string arg2, double arg3, std::string const& arg4);
    void method1(float arg0, bool arg1, double arg2, unsigned arg3, std::string arg4);
    void method2(float arg0, double arg1, std::string_view arg2, std::string const& arg3, int arg4);
    unsigned method3(unsigned arg0, short arg1, unsigned arg2, short arg3, std::string const& arg4);
    void method4(short arg0, short arg1, short arg2, double arg3, float arg4);
    std::string_view method5(unsigned arg0, std::string_view arg1, double arg2, std::string arg3, std::string_view arg4);
    void method6(bool arg0, std::string arg1, double arg2, bool arg3, short arg4);
    void method7(std::string const& arg0, std::string_view arg1, int arg2, short arg3, std::string_view arg4);
    void method8(std::string const& arg0, float arg1, bool arg2, unsigned arg3, std::string arg4);
    short method9(short arg0, float arg1, bool arg2, short arg3, std::string arg4);
    void method10(std::string const& arg0, int arg1, std::string arg2, std::string const& arg3, unsigned arg4);
    void method11(int arg0, short arg1, unsigned arg2, std::string arg3, double arg4);
    void method12(std::string arg0, double arg1, float arg2, std::string_view arg3, std::string_view arg4);
    std::string const& method13(std::string_view arg0, std::string const& arg1, std::string const& arg2, short arg3, double arg4);
    double method14(bool arg0, std::string const& arg1, bool arg2, bool arg3, double arg4);
};

namespace ns_Class93
{
    std::string method0(std::string arg0, bool arg1, std::string arg2, double arg3, std::string const& arg4);
    void method1(float arg0, bool arg1, double arg2, unsigned arg3, std::string arg4);
    void method2(float arg0, double arg1, std::string_view arg2, std::string const& arg3, int arg4);
    unsigned method3(unsigned arg0, short arg1, unsigned arg2, short arg3, std::string const& arg4);
    void method4(short arg0, short arg1, short arg2, double arg3, float arg4);
    std::string_view method5(unsigned arg0, std::string_view arg1, double arg2, std::string arg3, std::string_view arg4);
    void method6(bool arg0, std::string arg1, double arg2, bool arg3, short arg4);
    void method7(std::string const& arg0, std::string_view arg1, int arg2, short arg3, std::string_view arg4);
    void method8(std::string const& arg0, float arg1, bool arg2, unsigned arg3, std::string arg4);
    short method9(short arg0, float arg1, bool arg2, short arg3, std::string arg4);
    void method10(std::string const& arg0, int arg1, std::string arg2, std::string const& arg3, unsigned arg4);
    void method11(int arg0, short arg1, unsigned arg2, std::string arg3, double arg4);
    void method12(std::string arg0, double arg1, float arg2, std::string_view arg3, std::string_view arg4);
    std::string const& method13(std::string_view arg0, std::string const& arg1, std::string const& arg2, short arg3, double arg4);
    double method14(bool arg0, std::string const& arg1, bool arg2, bool arg3, double arg4);
}
