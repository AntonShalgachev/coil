#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class54
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(std::string const& arg0, short arg1, std::string arg2, int arg3, unsigned arg4);
    double method1(double arg0, double arg1, int arg2, std::string_view arg3, unsigned arg4);
    void method2(bool arg0, double arg1, bool arg2, int arg3, float arg4);
    unsigned method3(unsigned arg0, bool arg1, unsigned arg2, bool arg3, bool arg4);
    void method4(unsigned arg0, int arg1, std::string_view arg2, double arg3, std::string const& arg4);
    std::string_view method5(std::string_view arg0, int arg1, std::string arg2, std::string arg3, short arg4);
    int method6(double arg0, short arg1, float arg2, double arg3, int arg4);
    void method7(unsigned arg0, double arg1, float arg2, std::string_view arg3, unsigned arg4);
    std::string method8(short arg0, std::string arg1, std::string_view arg2, std::string_view arg3, int arg4);
    std::string method9(float arg0, std::string arg1, bool arg2, std::string arg3, int arg4);
    std::string const& method10(std::string const& arg0, std::string_view arg1, std::string arg2, short arg3, float arg4);
    float method11(double arg0, short arg1, std::string const& arg2, unsigned arg3, float arg4);
    float method12(bool arg0, double arg1, float arg2, unsigned arg3, float arg4);
    unsigned method13(float arg0, std::string const& arg1, unsigned arg2, bool arg3, unsigned arg4);
    std::string method14(std::string const& arg0, unsigned arg1, std::string_view arg2, std::string arg3, int arg4);
};

namespace ns_Class54
{
    void method0(std::string const& arg0, short arg1, std::string arg2, int arg3, unsigned arg4);
    double method1(double arg0, double arg1, int arg2, std::string_view arg3, unsigned arg4);
    void method2(bool arg0, double arg1, bool arg2, int arg3, float arg4);
    unsigned method3(unsigned arg0, bool arg1, unsigned arg2, bool arg3, bool arg4);
    void method4(unsigned arg0, int arg1, std::string_view arg2, double arg3, std::string const& arg4);
    std::string_view method5(std::string_view arg0, int arg1, std::string arg2, std::string arg3, short arg4);
    int method6(double arg0, short arg1, float arg2, double arg3, int arg4);
    void method7(unsigned arg0, double arg1, float arg2, std::string_view arg3, unsigned arg4);
    std::string method8(short arg0, std::string arg1, std::string_view arg2, std::string_view arg3, int arg4);
    std::string method9(float arg0, std::string arg1, bool arg2, std::string arg3, int arg4);
    std::string const& method10(std::string const& arg0, std::string_view arg1, std::string arg2, short arg3, float arg4);
    float method11(double arg0, short arg1, std::string const& arg2, unsigned arg3, float arg4);
    float method12(bool arg0, double arg1, float arg2, unsigned arg3, float arg4);
    unsigned method13(float arg0, std::string const& arg1, unsigned arg2, bool arg3, unsigned arg4);
    std::string method14(std::string const& arg0, unsigned arg1, std::string_view arg2, std::string arg3, int arg4);
}
