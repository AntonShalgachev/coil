#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class32
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(bool arg0, std::string arg1, short arg2, bool arg3, short arg4);
    void method1(std::string const& arg0, std::string const& arg1, float arg2, short arg3, unsigned arg4);
    void method2(std::string const& arg0, double arg1, double arg2, float arg3, bool arg4);
    void method3(float arg0, std::string arg1, std::string const& arg2, bool arg3, unsigned arg4);
    void method4(std::string const& arg0, std::string_view arg1, bool arg2, float arg3, int arg4);
    double method5(double arg0, bool arg1, float arg2, int arg3, bool arg4);
    std::string_view method6(double arg0, unsigned arg1, std::string_view arg2, int arg3, std::string_view arg4);
    int method7(std::string const& arg0, int arg1, double arg2, float arg3, bool arg4);
    void method8(int arg0, bool arg1, short arg2, std::string_view arg3, int arg4);
    void method9(double arg0, double arg1, std::string_view arg2, std::string_view arg3, std::string_view arg4);
    void method10(short arg0, short arg1, bool arg2, std::string arg3, bool arg4);
    double method11(short arg0, double arg1, double arg2, std::string_view arg3, float arg4);
    std::string method12(double arg0, std::string arg1, bool arg2, std::string const& arg3, std::string const& arg4);
    void method13(double arg0, float arg1, std::string arg2, std::string arg3, float arg4);
    std::string method14(std::string arg0, bool arg1, short arg2, float arg3, std::string arg4);
};

namespace ns_Class32
{
    short method0(bool arg0, std::string arg1, short arg2, bool arg3, short arg4);
    void method1(std::string const& arg0, std::string const& arg1, float arg2, short arg3, unsigned arg4);
    void method2(std::string const& arg0, double arg1, double arg2, float arg3, bool arg4);
    void method3(float arg0, std::string arg1, std::string const& arg2, bool arg3, unsigned arg4);
    void method4(std::string const& arg0, std::string_view arg1, bool arg2, float arg3, int arg4);
    double method5(double arg0, bool arg1, float arg2, int arg3, bool arg4);
    std::string_view method6(double arg0, unsigned arg1, std::string_view arg2, int arg3, std::string_view arg4);
    int method7(std::string const& arg0, int arg1, double arg2, float arg3, bool arg4);
    void method8(int arg0, bool arg1, short arg2, std::string_view arg3, int arg4);
    void method9(double arg0, double arg1, std::string_view arg2, std::string_view arg3, std::string_view arg4);
    void method10(short arg0, short arg1, bool arg2, std::string arg3, bool arg4);
    double method11(short arg0, double arg1, double arg2, std::string_view arg3, float arg4);
    std::string method12(double arg0, std::string arg1, bool arg2, std::string const& arg3, std::string const& arg4);
    void method13(double arg0, float arg1, std::string arg2, std::string arg3, float arg4);
    std::string method14(std::string arg0, bool arg1, short arg2, float arg3, std::string arg4);
}
