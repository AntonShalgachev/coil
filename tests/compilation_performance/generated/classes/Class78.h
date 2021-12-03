#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class78
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(bool arg0, std::string const& arg1, float arg2, std::string_view arg3, std::string const& arg4);
    double method1(std::string arg0, short arg1, bool arg2, double arg3, double arg4);
    void method2(int arg0, std::string_view arg1, std::string const& arg2, short arg3, int arg4);
    void method3(bool arg0, float arg1, bool arg2, double arg3, bool arg4);
    void method4(int arg0, unsigned arg1, short arg2, short arg3, std::string arg4);
    std::string_view method5(double arg0, std::string_view arg1, unsigned arg2, std::string const& arg3, double arg4);
    void method6(double arg0, unsigned arg1, std::string arg2, std::string arg3, std::string arg4);
    unsigned method7(unsigned arg0, float arg1, unsigned arg2, unsigned arg3, float arg4);
    std::string_view method8(unsigned arg0, std::string_view arg1, short arg2, double arg3, double arg4);
    std::string method9(std::string_view arg0, std::string_view arg1, bool arg2, std::string arg3, std::string arg4);
    short method10(short arg0, int arg1, bool arg2, int arg3, double arg4);
    std::string method11(std::string_view arg0, std::string arg1, float arg2, std::string arg3, std::string_view arg4);
    void method12(std::string_view arg0, std::string const& arg1, int arg2, double arg3, int arg4);
    double method13(float arg0, int arg1, std::string const& arg2, std::string const& arg3, double arg4);
    void method14(std::string_view arg0, int arg1, short arg2, float arg3, std::string_view arg4);
};

namespace ns_Class78
{
    void method0(bool arg0, std::string const& arg1, float arg2, std::string_view arg3, std::string const& arg4);
    double method1(std::string arg0, short arg1, bool arg2, double arg3, double arg4);
    void method2(int arg0, std::string_view arg1, std::string const& arg2, short arg3, int arg4);
    void method3(bool arg0, float arg1, bool arg2, double arg3, bool arg4);
    void method4(int arg0, unsigned arg1, short arg2, short arg3, std::string arg4);
    std::string_view method5(double arg0, std::string_view arg1, unsigned arg2, std::string const& arg3, double arg4);
    void method6(double arg0, unsigned arg1, std::string arg2, std::string arg3, std::string arg4);
    unsigned method7(unsigned arg0, float arg1, unsigned arg2, unsigned arg3, float arg4);
    std::string_view method8(unsigned arg0, std::string_view arg1, short arg2, double arg3, double arg4);
    std::string method9(std::string_view arg0, std::string_view arg1, bool arg2, std::string arg3, std::string arg4);
    short method10(short arg0, int arg1, bool arg2, int arg3, double arg4);
    std::string method11(std::string_view arg0, std::string arg1, float arg2, std::string arg3, std::string_view arg4);
    void method12(std::string_view arg0, std::string const& arg1, int arg2, double arg3, int arg4);
    double method13(float arg0, int arg1, std::string const& arg2, std::string const& arg3, double arg4);
    void method14(std::string_view arg0, int arg1, short arg2, float arg3, std::string_view arg4);
}
