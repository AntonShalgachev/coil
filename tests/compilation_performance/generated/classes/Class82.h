#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class82
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string const& method0(std::string const& arg0, std::string const& arg1, std::string_view arg2, int arg3, short arg4);
    std::string_view method1(std::string const& arg0, int arg1, std::string_view arg2, int arg3, float arg4);
    int method2(std::string_view arg0, unsigned arg1, double arg2, std::string const& arg3, int arg4);
    float method3(std::string const& arg0, std::string_view arg1, std::string_view arg2, double arg3, float arg4);
    float method4(std::string arg0, float arg1, unsigned arg2, std::string_view arg3, double arg4);
    void method5(std::string const& arg0, std::string arg1, short arg2, std::string_view arg3, std::string_view arg4);
    int method6(std::string_view arg0, int arg1, std::string const& arg2, short arg3, float arg4);
    void method7(double arg0, short arg1, int arg2, int arg3, std::string const& arg4);
    void method8(std::string_view arg0, std::string arg1, std::string_view arg2, std::string arg3, std::string arg4);
    void method9(float arg0, float arg1, int arg2, int arg3, bool arg4);
    void method10(int arg0, std::string const& arg1, double arg2, std::string const& arg3, std::string_view arg4);
    int method11(std::string_view arg0, double arg1, int arg2, short arg3, unsigned arg4);
    void method12(std::string arg0, std::string arg1, bool arg2, std::string_view arg3, bool arg4);
    void method13(std::string_view arg0, std::string_view arg1, unsigned arg2, bool arg3, float arg4);
    void method14(bool arg0, int arg1, short arg2, float arg3, double arg4);
};

namespace ns_Class82
{
    std::string const& method0(std::string const& arg0, std::string const& arg1, std::string_view arg2, int arg3, short arg4);
    std::string_view method1(std::string const& arg0, int arg1, std::string_view arg2, int arg3, float arg4);
    int method2(std::string_view arg0, unsigned arg1, double arg2, std::string const& arg3, int arg4);
    float method3(std::string const& arg0, std::string_view arg1, std::string_view arg2, double arg3, float arg4);
    float method4(std::string arg0, float arg1, unsigned arg2, std::string_view arg3, double arg4);
    void method5(std::string const& arg0, std::string arg1, short arg2, std::string_view arg3, std::string_view arg4);
    int method6(std::string_view arg0, int arg1, std::string const& arg2, short arg3, float arg4);
    void method7(double arg0, short arg1, int arg2, int arg3, std::string const& arg4);
    void method8(std::string_view arg0, std::string arg1, std::string_view arg2, std::string arg3, std::string arg4);
    void method9(float arg0, float arg1, int arg2, int arg3, bool arg4);
    void method10(int arg0, std::string const& arg1, double arg2, std::string const& arg3, std::string_view arg4);
    int method11(std::string_view arg0, double arg1, int arg2, short arg3, unsigned arg4);
    void method12(std::string arg0, std::string arg1, bool arg2, std::string_view arg3, bool arg4);
    void method13(std::string_view arg0, std::string_view arg1, unsigned arg2, bool arg3, float arg4);
    void method14(bool arg0, int arg1, short arg2, float arg3, double arg4);
}
