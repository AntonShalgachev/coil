#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class73
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(bool arg0, unsigned arg1, unsigned arg2, float arg3, std::string const& arg4);
    double method1(std::string_view arg0, bool arg1, double arg2, std::string_view arg3, std::string const& arg4);
    std::string method2(double arg0, bool arg1, std::string arg2, int arg3, std::string arg4);
    int method3(short arg0, unsigned arg1, bool arg2, int arg3, bool arg4);
    void method4(int arg0, bool arg1, std::string const& arg2, std::string arg3, std::string arg4);
    std::string_view method5(int arg0, double arg1, std::string arg2, std::string_view arg3, double arg4);
    int method6(int arg0, bool arg1, int arg2, double arg3, int arg4);
    bool method7(bool arg0, double arg1, float arg2, std::string_view arg3, bool arg4);
    void method8(bool arg0, float arg1, short arg2, std::string const& arg3, std::string_view arg4);
    short method9(short arg0, int arg1, double arg2, std::string const& arg3, std::string_view arg4);
    void method10(std::string arg0, std::string const& arg1, std::string arg2, int arg3, int arg4);
    void method11(int arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    void method12(double arg0, unsigned arg1, float arg2, bool arg3, int arg4);
    void method13(float arg0, double arg1, unsigned arg2, std::string_view arg3, std::string const& arg4);
    void method14(std::string_view arg0, std::string_view arg1, unsigned arg2, int arg3, int arg4);
};

namespace ns_Class73
{
    unsigned method0(bool arg0, unsigned arg1, unsigned arg2, float arg3, std::string const& arg4);
    double method1(std::string_view arg0, bool arg1, double arg2, std::string_view arg3, std::string const& arg4);
    std::string method2(double arg0, bool arg1, std::string arg2, int arg3, std::string arg4);
    int method3(short arg0, unsigned arg1, bool arg2, int arg3, bool arg4);
    void method4(int arg0, bool arg1, std::string const& arg2, std::string arg3, std::string arg4);
    std::string_view method5(int arg0, double arg1, std::string arg2, std::string_view arg3, double arg4);
    int method6(int arg0, bool arg1, int arg2, double arg3, int arg4);
    bool method7(bool arg0, double arg1, float arg2, std::string_view arg3, bool arg4);
    void method8(bool arg0, float arg1, short arg2, std::string const& arg3, std::string_view arg4);
    short method9(short arg0, int arg1, double arg2, std::string const& arg3, std::string_view arg4);
    void method10(std::string arg0, std::string const& arg1, std::string arg2, int arg3, int arg4);
    void method11(int arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    void method12(double arg0, unsigned arg1, float arg2, bool arg3, int arg4);
    void method13(float arg0, double arg1, unsigned arg2, std::string_view arg3, std::string const& arg4);
    void method14(std::string_view arg0, std::string_view arg1, unsigned arg2, int arg3, int arg4);
}
