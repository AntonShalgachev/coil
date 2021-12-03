#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class87
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string_view method0(bool arg0, bool arg1, short arg2, std::string_view arg3, bool arg4);
    float method1(std::string const& arg0, double arg1, std::string arg2, float arg3, std::string const& arg4);
    void method2(unsigned arg0, short arg1, float arg2, std::string arg3, int arg4);
    std::string const& method3(std::string const& arg0, std::string arg1, std::string arg2, int arg3, unsigned arg4);
    float method4(double arg0, std::string_view arg1, int arg2, double arg3, float arg4);
    void method5(short arg0, std::string arg1, std::string_view arg2, int arg3, int arg4);
    std::string const& method6(bool arg0, short arg1, double arg2, std::string const& arg3, int arg4);
    void method7(short arg0, std::string_view arg1, double arg2, short arg3, unsigned arg4);
    double method8(int arg0, unsigned arg1, double arg2, unsigned arg3, float arg4);
    void method9(bool arg0, std::string arg1, std::string_view arg2, float arg3, std::string_view arg4);
    float method10(std::string const& arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    void method11(double arg0, int arg1, std::string_view arg2, std::string const& arg3, int arg4);
    void method12(std::string arg0, std::string arg1, std::string_view arg2, int arg3, int arg4);
    void method13(double arg0, int arg1, double arg2, short arg3, float arg4);
    void method14(float arg0, bool arg1, std::string arg2, short arg3, int arg4);
};

namespace ns_Class87
{
    std::string_view method0(bool arg0, bool arg1, short arg2, std::string_view arg3, bool arg4);
    float method1(std::string const& arg0, double arg1, std::string arg2, float arg3, std::string const& arg4);
    void method2(unsigned arg0, short arg1, float arg2, std::string arg3, int arg4);
    std::string const& method3(std::string const& arg0, std::string arg1, std::string arg2, int arg3, unsigned arg4);
    float method4(double arg0, std::string_view arg1, int arg2, double arg3, float arg4);
    void method5(short arg0, std::string arg1, std::string_view arg2, int arg3, int arg4);
    std::string const& method6(bool arg0, short arg1, double arg2, std::string const& arg3, int arg4);
    void method7(short arg0, std::string_view arg1, double arg2, short arg3, unsigned arg4);
    double method8(int arg0, unsigned arg1, double arg2, unsigned arg3, float arg4);
    void method9(bool arg0, std::string arg1, std::string_view arg2, float arg3, std::string_view arg4);
    float method10(std::string const& arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    void method11(double arg0, int arg1, std::string_view arg2, std::string const& arg3, int arg4);
    void method12(std::string arg0, std::string arg1, std::string_view arg2, int arg3, int arg4);
    void method13(double arg0, int arg1, double arg2, short arg3, float arg4);
    void method14(float arg0, bool arg1, std::string arg2, short arg3, int arg4);
}
