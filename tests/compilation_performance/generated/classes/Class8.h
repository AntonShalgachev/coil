#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class8
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(float arg0, bool arg1, int arg2, float arg3, std::string const& arg4);
    void method1(double arg0, std::string_view arg1, std::string arg2, std::string arg3, int arg4);
    void method2(float arg0, short arg1, int arg2, int arg3, bool arg4);
    int method3(std::string_view arg0, bool arg1, double arg2, double arg3, int arg4);
    void method4(std::string_view arg0, std::string arg1, std::string arg2, int arg3, std::string const& arg4);
    void method5(std::string_view arg0, short arg1, bool arg2, bool arg3, bool arg4);
    void method6(double arg0, std::string_view arg1, bool arg2, double arg3, unsigned arg4);
    void method7(double arg0, int arg1, int arg2, unsigned arg3, float arg4);
    void method8(std::string_view arg0, bool arg1, float arg2, short arg3, double arg4);
    void method9(short arg0, int arg1, short arg2, double arg3, double arg4);
    std::string method10(std::string arg0, std::string arg1, short arg2, bool arg3, std::string const& arg4);
    float method11(std::string arg0, bool arg1, int arg2, float arg3, float arg4);
    std::string const& method12(std::string arg0, std::string const& arg1, short arg2, double arg3, short arg4);
    double method13(std::string const& arg0, std::string_view arg1, float arg2, double arg3, double arg4);
    void method14(std::string arg0, int arg1, int arg2, float arg3, unsigned arg4);
};

namespace ns_Class8
{
    int method0(float arg0, bool arg1, int arg2, float arg3, std::string const& arg4);
    void method1(double arg0, std::string_view arg1, std::string arg2, std::string arg3, int arg4);
    void method2(float arg0, short arg1, int arg2, int arg3, bool arg4);
    int method3(std::string_view arg0, bool arg1, double arg2, double arg3, int arg4);
    void method4(std::string_view arg0, std::string arg1, std::string arg2, int arg3, std::string const& arg4);
    void method5(std::string_view arg0, short arg1, bool arg2, bool arg3, bool arg4);
    void method6(double arg0, std::string_view arg1, bool arg2, double arg3, unsigned arg4);
    void method7(double arg0, int arg1, int arg2, unsigned arg3, float arg4);
    void method8(std::string_view arg0, bool arg1, float arg2, short arg3, double arg4);
    void method9(short arg0, int arg1, short arg2, double arg3, double arg4);
    std::string method10(std::string arg0, std::string arg1, short arg2, bool arg3, std::string const& arg4);
    float method11(std::string arg0, bool arg1, int arg2, float arg3, float arg4);
    std::string const& method12(std::string arg0, std::string const& arg1, short arg2, double arg3, short arg4);
    double method13(std::string const& arg0, std::string_view arg1, float arg2, double arg3, double arg4);
    void method14(std::string arg0, int arg1, int arg2, float arg3, unsigned arg4);
}
