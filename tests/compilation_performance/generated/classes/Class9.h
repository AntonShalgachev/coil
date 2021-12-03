#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class9
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, std::string arg1, int arg2, int arg3, std::string arg4);
    void method1(short arg0, bool arg1, int arg2, bool arg3, std::string arg4);
    void method2(double arg0, std::string arg1, std::string arg2, std::string const& arg3, bool arg4);
    unsigned method3(float arg0, std::string const& arg1, unsigned arg2, bool arg3, unsigned arg4);
    double method4(bool arg0, double arg1, std::string_view arg2, int arg3, std::string const& arg4);
    double method5(std::string_view arg0, unsigned arg1, bool arg2, std::string_view arg3, double arg4);
    void method6(std::string const& arg0, unsigned arg1, std::string arg2, bool arg3, std::string_view arg4);
    double method7(std::string_view arg0, std::string const& arg1, double arg2, std::string arg3, std::string arg4);
    void method8(std::string const& arg0, std::string_view arg1, std::string const& arg2, std::string arg3, unsigned arg4);
    void method9(float arg0, std::string_view arg1, std::string_view arg2, std::string const& arg3, int arg4);
    std::string_view method10(std::string_view arg0, std::string const& arg1, float arg2, double arg3, std::string const& arg4);
    std::string method11(int arg0, std::string arg1, int arg2, double arg3, std::string_view arg4);
    void method12(unsigned arg0, std::string arg1, short arg2, float arg3, float arg4);
    void method13(std::string arg0, std::string_view arg1, float arg2, bool arg3, std::string_view arg4);
    void method14(std::string const& arg0, short arg1, int arg2, std::string const& arg3, int arg4);
};

namespace ns_Class9
{
    void method0(double arg0, std::string arg1, int arg2, int arg3, std::string arg4);
    void method1(short arg0, bool arg1, int arg2, bool arg3, std::string arg4);
    void method2(double arg0, std::string arg1, std::string arg2, std::string const& arg3, bool arg4);
    unsigned method3(float arg0, std::string const& arg1, unsigned arg2, bool arg3, unsigned arg4);
    double method4(bool arg0, double arg1, std::string_view arg2, int arg3, std::string const& arg4);
    double method5(std::string_view arg0, unsigned arg1, bool arg2, std::string_view arg3, double arg4);
    void method6(std::string const& arg0, unsigned arg1, std::string arg2, bool arg3, std::string_view arg4);
    double method7(std::string_view arg0, std::string const& arg1, double arg2, std::string arg3, std::string arg4);
    void method8(std::string const& arg0, std::string_view arg1, std::string const& arg2, std::string arg3, unsigned arg4);
    void method9(float arg0, std::string_view arg1, std::string_view arg2, std::string const& arg3, int arg4);
    std::string_view method10(std::string_view arg0, std::string const& arg1, float arg2, double arg3, std::string const& arg4);
    std::string method11(int arg0, std::string arg1, int arg2, double arg3, std::string_view arg4);
    void method12(unsigned arg0, std::string arg1, short arg2, float arg3, float arg4);
    void method13(std::string arg0, std::string_view arg1, float arg2, bool arg3, std::string_view arg4);
    void method14(std::string const& arg0, short arg1, int arg2, std::string const& arg3, int arg4);
}
