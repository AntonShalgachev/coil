#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class46
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(std::string const& arg0, unsigned arg1, std::string arg2, short arg3, float arg4);
    void method1(float arg0, std::string_view arg1, unsigned arg2, double arg3, bool arg4);
    float method2(float arg0, short arg1, unsigned arg2, std::string_view arg3, unsigned arg4);
    std::string method3(short arg0, bool arg1, int arg2, int arg3, std::string arg4);
    void method4(int arg0, float arg1, std::string arg2, bool arg3, bool arg4);
    int method5(bool arg0, double arg1, int arg2, double arg3, std::string arg4);
    void method6(int arg0, std::string const& arg1, unsigned arg2, float arg3, std::string_view arg4);
    int method7(bool arg0, std::string_view arg1, int arg2, std::string arg3, std::string const& arg4);
    void method8(bool arg0, bool arg1, double arg2, int arg3, short arg4);
    int method9(int arg0, int arg1, float arg2, bool arg3, std::string const& arg4);
    float method10(std::string arg0, float arg1, unsigned arg2, float arg3, double arg4);
    std::string method11(bool arg0, float arg1, std::string const& arg2, std::string arg3, float arg4);
    std::string const& method12(std::string_view arg0, short arg1, std::string arg2, std::string const& arg3, bool arg4);
    void method13(std::string arg0, unsigned arg1, std::string const& arg2, int arg3, int arg4);
    void method14(int arg0, std::string arg1, std::string arg2, double arg3, short arg4);
};

namespace ns_Class46
{
    short method0(std::string const& arg0, unsigned arg1, std::string arg2, short arg3, float arg4);
    void method1(float arg0, std::string_view arg1, unsigned arg2, double arg3, bool arg4);
    float method2(float arg0, short arg1, unsigned arg2, std::string_view arg3, unsigned arg4);
    std::string method3(short arg0, bool arg1, int arg2, int arg3, std::string arg4);
    void method4(int arg0, float arg1, std::string arg2, bool arg3, bool arg4);
    int method5(bool arg0, double arg1, int arg2, double arg3, std::string arg4);
    void method6(int arg0, std::string const& arg1, unsigned arg2, float arg3, std::string_view arg4);
    int method7(bool arg0, std::string_view arg1, int arg2, std::string arg3, std::string const& arg4);
    void method8(bool arg0, bool arg1, double arg2, int arg3, short arg4);
    int method9(int arg0, int arg1, float arg2, bool arg3, std::string const& arg4);
    float method10(std::string arg0, float arg1, unsigned arg2, float arg3, double arg4);
    std::string method11(bool arg0, float arg1, std::string const& arg2, std::string arg3, float arg4);
    std::string const& method12(std::string_view arg0, short arg1, std::string arg2, std::string const& arg3, bool arg4);
    void method13(std::string arg0, unsigned arg1, std::string const& arg2, int arg3, int arg4);
    void method14(int arg0, std::string arg1, std::string arg2, double arg3, short arg4);
}
