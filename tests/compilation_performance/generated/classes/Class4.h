#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class4
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, float arg1, int arg2, unsigned arg3, short arg4);
    void method1(bool arg0, bool arg1, bool arg2, bool arg3, std::string arg4);
    void method2(std::string arg0, float arg1, std::string const& arg2, short arg3, int arg4);
    short method3(double arg0, std::string_view arg1, std::string const& arg2, float arg3, short arg4);
    void method4(unsigned arg0, std::string_view arg1, bool arg2, unsigned arg3, double arg4);
    void method5(std::string arg0, std::string_view arg1, double arg2, bool arg3, std::string arg4);
    void method6(short arg0, short arg1, unsigned arg2, short arg3, std::string const& arg4);
    std::string_view method7(float arg0, std::string_view arg1, bool arg2, unsigned arg3, short arg4);
    std::string_view method8(unsigned arg0, std::string_view arg1, bool arg2, double arg3, unsigned arg4);
    void method9(double arg0, double arg1, std::string_view arg2, short arg3, bool arg4);
    void method10(std::string arg0, bool arg1, std::string_view arg2, short arg3, double arg4);
    std::string const& method11(short arg0, std::string const& arg1, int arg2, double arg3, double arg4);
    void method12(std::string const& arg0, double arg1, int arg2, double arg3, bool arg4);
    int method13(short arg0, int arg1, float arg2, bool arg3, bool arg4);
    void method14(std::string_view arg0, float arg1, std::string const& arg2, std::string arg3, double arg4);
};

namespace ns_Class4
{
    void method0(double arg0, float arg1, int arg2, unsigned arg3, short arg4);
    void method1(bool arg0, bool arg1, bool arg2, bool arg3, std::string arg4);
    void method2(std::string arg0, float arg1, std::string const& arg2, short arg3, int arg4);
    short method3(double arg0, std::string_view arg1, std::string const& arg2, float arg3, short arg4);
    void method4(unsigned arg0, std::string_view arg1, bool arg2, unsigned arg3, double arg4);
    void method5(std::string arg0, std::string_view arg1, double arg2, bool arg3, std::string arg4);
    void method6(short arg0, short arg1, unsigned arg2, short arg3, std::string const& arg4);
    std::string_view method7(float arg0, std::string_view arg1, bool arg2, unsigned arg3, short arg4);
    std::string_view method8(unsigned arg0, std::string_view arg1, bool arg2, double arg3, unsigned arg4);
    void method9(double arg0, double arg1, std::string_view arg2, short arg3, bool arg4);
    void method10(std::string arg0, bool arg1, std::string_view arg2, short arg3, double arg4);
    std::string const& method11(short arg0, std::string const& arg1, int arg2, double arg3, double arg4);
    void method12(std::string const& arg0, double arg1, int arg2, double arg3, bool arg4);
    int method13(short arg0, int arg1, float arg2, bool arg3, bool arg4);
    void method14(std::string_view arg0, float arg1, std::string const& arg2, std::string arg3, double arg4);
}
