#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class96
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string_view method0(std::string arg0, std::string_view arg1, bool arg2, short arg3, std::string_view arg4);
    std::string const& method1(short arg0, std::string const& arg1, bool arg2, short arg3, bool arg4);
    void method2(double arg0, std::string_view arg1, std::string arg2, std::string const& arg3, double arg4);
    float method3(float arg0, bool arg1, int arg2, short arg3, short arg4);
    short method4(short arg0, int arg1, std::string arg2, bool arg3, double arg4);
    void method5(std::string arg0, unsigned arg1, int arg2, int arg3, std::string arg4);
    std::string method6(std::string_view arg0, std::string const& arg1, std::string arg2, unsigned arg3, std::string arg4);
    void method7(int arg0, std::string const& arg1, float arg2, std::string const& arg3, bool arg4);
    double method8(float arg0, std::string arg1, double arg2, std::string_view arg3, std::string_view arg4);
    void method9(std::string const& arg0, std::string const& arg1, short arg2, double arg3, std::string_view arg4);
    int method10(bool arg0, short arg1, short arg2, int arg3, int arg4);
    short method11(int arg0, short arg1, short arg2, short arg3, short arg4);
    void method12(std::string arg0, bool arg1, std::string_view arg2, double arg3, int arg4);
    void method13(std::string_view arg0, int arg1, unsigned arg2, std::string_view arg3, bool arg4);
    void method14(int arg0, double arg1, std::string arg2, short arg3, std::string_view arg4);
};

namespace ns_Class96
{
    std::string_view method0(std::string arg0, std::string_view arg1, bool arg2, short arg3, std::string_view arg4);
    std::string const& method1(short arg0, std::string const& arg1, bool arg2, short arg3, bool arg4);
    void method2(double arg0, std::string_view arg1, std::string arg2, std::string const& arg3, double arg4);
    float method3(float arg0, bool arg1, int arg2, short arg3, short arg4);
    short method4(short arg0, int arg1, std::string arg2, bool arg3, double arg4);
    void method5(std::string arg0, unsigned arg1, int arg2, int arg3, std::string arg4);
    std::string method6(std::string_view arg0, std::string const& arg1, std::string arg2, unsigned arg3, std::string arg4);
    void method7(int arg0, std::string const& arg1, float arg2, std::string const& arg3, bool arg4);
    double method8(float arg0, std::string arg1, double arg2, std::string_view arg3, std::string_view arg4);
    void method9(std::string const& arg0, std::string const& arg1, short arg2, double arg3, std::string_view arg4);
    int method10(bool arg0, short arg1, short arg2, int arg3, int arg4);
    short method11(int arg0, short arg1, short arg2, short arg3, short arg4);
    void method12(std::string arg0, bool arg1, std::string_view arg2, double arg3, int arg4);
    void method13(std::string_view arg0, int arg1, unsigned arg2, std::string_view arg3, bool arg4);
    void method14(int arg0, double arg1, std::string arg2, short arg3, std::string_view arg4);
}
