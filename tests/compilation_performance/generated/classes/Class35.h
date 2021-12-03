#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class35
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string method0(double arg0, int arg1, std::string arg2, std::string const& arg3, float arg4);
    short method1(int arg0, float arg1, short arg2, float arg3, short arg4);
    std::string const& method2(std::string_view arg0, double arg1, std::string const& arg2, std::string const& arg3, short arg4);
    void method3(std::string arg0, int arg1, double arg2, float arg3, double arg4);
    void method4(short arg0, std::string_view arg1, std::string_view arg2, std::string arg3, std::string arg4);
    void method5(int arg0, bool arg1, short arg2, double arg3, std::string arg4);
    std::string const& method6(short arg0, short arg1, std::string arg2, std::string const& arg3, std::string const& arg4);
    short method7(bool arg0, std::string const& arg1, std::string const& arg2, std::string_view arg3, short arg4);
    void method8(std::string const& arg0, float arg1, unsigned arg2, unsigned arg3, bool arg4);
    std::string_view method9(std::string_view arg0, std::string arg1, int arg2, std::string const& arg3, std::string const& arg4);
    double method10(std::string arg0, std::string_view arg1, double arg2, std::string arg3, std::string_view arg4);
    short method11(std::string arg0, std::string arg1, short arg2, short arg3, int arg4);
    std::string const& method12(std::string arg0, std::string_view arg1, std::string arg2, std::string const& arg3, std::string const& arg4);
    void method13(int arg0, short arg1, int arg2, float arg3, double arg4);
    void method14(short arg0, bool arg1, unsigned arg2, std::string arg3, float arg4);
};

namespace ns_Class35
{
    std::string method0(double arg0, int arg1, std::string arg2, std::string const& arg3, float arg4);
    short method1(int arg0, float arg1, short arg2, float arg3, short arg4);
    std::string const& method2(std::string_view arg0, double arg1, std::string const& arg2, std::string const& arg3, short arg4);
    void method3(std::string arg0, int arg1, double arg2, float arg3, double arg4);
    void method4(short arg0, std::string_view arg1, std::string_view arg2, std::string arg3, std::string arg4);
    void method5(int arg0, bool arg1, short arg2, double arg3, std::string arg4);
    std::string const& method6(short arg0, short arg1, std::string arg2, std::string const& arg3, std::string const& arg4);
    short method7(bool arg0, std::string const& arg1, std::string const& arg2, std::string_view arg3, short arg4);
    void method8(std::string const& arg0, float arg1, unsigned arg2, unsigned arg3, bool arg4);
    std::string_view method9(std::string_view arg0, std::string arg1, int arg2, std::string const& arg3, std::string const& arg4);
    double method10(std::string arg0, std::string_view arg1, double arg2, std::string arg3, std::string_view arg4);
    short method11(std::string arg0, std::string arg1, short arg2, short arg3, int arg4);
    std::string const& method12(std::string arg0, std::string_view arg1, std::string arg2, std::string const& arg3, std::string const& arg4);
    void method13(int arg0, short arg1, int arg2, float arg3, double arg4);
    void method14(short arg0, bool arg1, unsigned arg2, std::string arg3, float arg4);
}
