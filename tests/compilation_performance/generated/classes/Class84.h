#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class84
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, short arg1, float arg2, std::string const& arg3, std::string const& arg4);
    std::string const& method1(double arg0, std::string const& arg1, double arg2, std::string_view arg3, std::string arg4);
    double method2(float arg0, std::string arg1, std::string_view arg2, int arg3, double arg4);
    int method3(unsigned arg0, int arg1, float arg2, unsigned arg3, double arg4);
    int method4(bool arg0, bool arg1, std::string const& arg2, bool arg3, int arg4);
    void method5(bool arg0, int arg1, double arg2, unsigned arg3, std::string_view arg4);
    void method6(std::string const& arg0, unsigned arg1, unsigned arg2, int arg3, int arg4);
    void method7(unsigned arg0, int arg1, float arg2, float arg3, short arg4);
    void method8(int arg0, std::string arg1, std::string_view arg2, unsigned arg3, int arg4);
    void method9(std::string_view arg0, std::string const& arg1, unsigned arg2, unsigned arg3, short arg4);
    void method10(unsigned arg0, std::string arg1, float arg2, float arg3, double arg4);
    std::string const& method11(bool arg0, std::string const& arg1, std::string const& arg2, std::string const& arg3, bool arg4);
    void method12(int arg0, double arg1, double arg2, float arg3, std::string_view arg4);
    int method13(float arg0, double arg1, int arg2, std::string arg3, bool arg4);
    short method14(unsigned arg0, std::string_view arg1, short arg2, std::string_view arg3, bool arg4);
};

namespace ns_Class84
{
    void method0(short arg0, short arg1, float arg2, std::string const& arg3, std::string const& arg4);
    std::string const& method1(double arg0, std::string const& arg1, double arg2, std::string_view arg3, std::string arg4);
    double method2(float arg0, std::string arg1, std::string_view arg2, int arg3, double arg4);
    int method3(unsigned arg0, int arg1, float arg2, unsigned arg3, double arg4);
    int method4(bool arg0, bool arg1, std::string const& arg2, bool arg3, int arg4);
    void method5(bool arg0, int arg1, double arg2, unsigned arg3, std::string_view arg4);
    void method6(std::string const& arg0, unsigned arg1, unsigned arg2, int arg3, int arg4);
    void method7(unsigned arg0, int arg1, float arg2, float arg3, short arg4);
    void method8(int arg0, std::string arg1, std::string_view arg2, unsigned arg3, int arg4);
    void method9(std::string_view arg0, std::string const& arg1, unsigned arg2, unsigned arg3, short arg4);
    void method10(unsigned arg0, std::string arg1, float arg2, float arg3, double arg4);
    std::string const& method11(bool arg0, std::string const& arg1, std::string const& arg2, std::string const& arg3, bool arg4);
    void method12(int arg0, double arg1, double arg2, float arg3, std::string_view arg4);
    int method13(float arg0, double arg1, int arg2, std::string arg3, bool arg4);
    short method14(unsigned arg0, std::string_view arg1, short arg2, std::string_view arg3, bool arg4);
}
