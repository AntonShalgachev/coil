#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class80
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(std::string arg0, std::string const& arg1, std::string const& arg2, int arg3, short arg4);
    bool method1(unsigned arg0, std::string_view arg1, short arg2, double arg3, bool arg4);
    void method2(bool arg0, float arg1, std::string_view arg2, float arg3, std::string_view arg4);
    short method3(std::string const& arg0, short arg1, std::string arg2, float arg3, short arg4);
    std::string const& method4(std::string const& arg0, short arg1, std::string arg2, float arg3, std::string const& arg4);
    std::string method5(std::string arg0, bool arg1, double arg2, std::string arg3, unsigned arg4);
    short method6(std::string_view arg0, double arg1, short arg2, float arg3, float arg4);
    void method7(double arg0, short arg1, double arg2, unsigned arg3, bool arg4);
    void method8(double arg0, short arg1, bool arg2, std::string_view arg3, std::string arg4);
    void method9(short arg0, short arg1, std::string const& arg2, bool arg3, double arg4);
    void method10(std::string arg0, double arg1, unsigned arg2, std::string arg3, bool arg4);
    void method11(float arg0, short arg1, int arg2, double arg3, bool arg4);
    void method12(std::string arg0, short arg1, std::string arg2, double arg3, unsigned arg4);
    void method13(int arg0, unsigned arg1, unsigned arg2, std::string_view arg3, float arg4);
    std::string_view method14(short arg0, int arg1, std::string_view arg2, std::string const& arg3, bool arg4);
};

namespace ns_Class80
{
    int method0(std::string arg0, std::string const& arg1, std::string const& arg2, int arg3, short arg4);
    bool method1(unsigned arg0, std::string_view arg1, short arg2, double arg3, bool arg4);
    void method2(bool arg0, float arg1, std::string_view arg2, float arg3, std::string_view arg4);
    short method3(std::string const& arg0, short arg1, std::string arg2, float arg3, short arg4);
    std::string const& method4(std::string const& arg0, short arg1, std::string arg2, float arg3, std::string const& arg4);
    std::string method5(std::string arg0, bool arg1, double arg2, std::string arg3, unsigned arg4);
    short method6(std::string_view arg0, double arg1, short arg2, float arg3, float arg4);
    void method7(double arg0, short arg1, double arg2, unsigned arg3, bool arg4);
    void method8(double arg0, short arg1, bool arg2, std::string_view arg3, std::string arg4);
    void method9(short arg0, short arg1, std::string const& arg2, bool arg3, double arg4);
    void method10(std::string arg0, double arg1, unsigned arg2, std::string arg3, bool arg4);
    void method11(float arg0, short arg1, int arg2, double arg3, bool arg4);
    void method12(std::string arg0, short arg1, std::string arg2, double arg3, unsigned arg4);
    void method13(int arg0, unsigned arg1, unsigned arg2, std::string_view arg3, float arg4);
    std::string_view method14(short arg0, int arg1, std::string_view arg2, std::string const& arg3, bool arg4);
}
