#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class99
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(std::string_view arg0, int arg1, std::string_view arg2, int arg3, bool arg4);
    void method1(double arg0, double arg1, std::string_view arg2, float arg3, int arg4);
    void method2(short arg0, std::string const& arg1, double arg2, bool arg3, std::string_view arg4);
    void method3(double arg0, bool arg1, std::string_view arg2, int arg3, int arg4);
    void method4(int arg0, std::string const& arg1, bool arg2, bool arg3, int arg4);
    short method5(short arg0, std::string_view arg1, unsigned arg2, std::string arg3, std::string_view arg4);
    void method6(bool arg0, std::string const& arg1, std::string const& arg2, double arg3, std::string_view arg4);
    void method7(unsigned arg0, short arg1, short arg2, float arg3, bool arg4);
    std::string const& method8(std::string const& arg0, std::string const& arg1, int arg2, std::string_view arg3, int arg4);
    void method9(std::string const& arg0, bool arg1, float arg2, unsigned arg3, float arg4);
    short method10(short arg0, bool arg1, std::string_view arg2, std::string_view arg3, std::string const& arg4);
    void method11(int arg0, bool arg1, std::string arg2, short arg3, unsigned arg4);
    void method12(double arg0, bool arg1, bool arg2, bool arg3, unsigned arg4);
    std::string const& method13(unsigned arg0, short arg1, std::string_view arg2, float arg3, std::string const& arg4);
    std::string const& method14(unsigned arg0, std::string const& arg1, float arg2, float arg3, short arg4);
};

namespace ns_Class99
{
    void method0(std::string_view arg0, int arg1, std::string_view arg2, int arg3, bool arg4);
    void method1(double arg0, double arg1, std::string_view arg2, float arg3, int arg4);
    void method2(short arg0, std::string const& arg1, double arg2, bool arg3, std::string_view arg4);
    void method3(double arg0, bool arg1, std::string_view arg2, int arg3, int arg4);
    void method4(int arg0, std::string const& arg1, bool arg2, bool arg3, int arg4);
    short method5(short arg0, std::string_view arg1, unsigned arg2, std::string arg3, std::string_view arg4);
    void method6(bool arg0, std::string const& arg1, std::string const& arg2, double arg3, std::string_view arg4);
    void method7(unsigned arg0, short arg1, short arg2, float arg3, bool arg4);
    std::string const& method8(std::string const& arg0, std::string const& arg1, int arg2, std::string_view arg3, int arg4);
    void method9(std::string const& arg0, bool arg1, float arg2, unsigned arg3, float arg4);
    short method10(short arg0, bool arg1, std::string_view arg2, std::string_view arg3, std::string const& arg4);
    void method11(int arg0, bool arg1, std::string arg2, short arg3, unsigned arg4);
    void method12(double arg0, bool arg1, bool arg2, bool arg3, unsigned arg4);
    std::string const& method13(unsigned arg0, short arg1, std::string_view arg2, float arg3, std::string const& arg4);
    std::string const& method14(unsigned arg0, std::string const& arg1, float arg2, float arg3, short arg4);
}
