#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class17
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, std::string_view arg1, std::string const& arg2, short arg3, short arg4);
    std::string method1(std::string const& arg0, double arg1, std::string arg2, int arg3, double arg4);
    int method2(bool arg0, int arg1, std::string_view arg2, int arg3, unsigned arg4);
    void method3(short arg0, std::string arg1, short arg2, bool arg3, unsigned arg4);
    void method4(int arg0, std::string arg1, std::string arg2, std::string arg3, bool arg4);
    float method5(unsigned arg0, std::string arg1, bool arg2, float arg3, std::string_view arg4);
    void method6(std::string const& arg0, bool arg1, unsigned arg2, short arg3, std::string arg4);
    void method7(double arg0, bool arg1, float arg2, bool arg3, int arg4);
    void method8(float arg0, std::string const& arg1, int arg2, float arg3, float arg4);
    void method9(std::string arg0, unsigned arg1, std::string arg2, bool arg3, double arg4);
    void method10(bool arg0, short arg1, double arg2, bool arg3, unsigned arg4);
    std::string_view method11(std::string_view arg0, std::string const& arg1, short arg2, unsigned arg3, std::string const& arg4);
    void method12(double arg0, std::string_view arg1, short arg2, float arg3, bool arg4);
    void method13(float arg0, std::string_view arg1, unsigned arg2, float arg3, short arg4);
    void method14(double arg0, std::string_view arg1, std::string_view arg2, int arg3, int arg4);
};

namespace ns_Class17
{
    void method0(short arg0, std::string_view arg1, std::string const& arg2, short arg3, short arg4);
    std::string method1(std::string const& arg0, double arg1, std::string arg2, int arg3, double arg4);
    int method2(bool arg0, int arg1, std::string_view arg2, int arg3, unsigned arg4);
    void method3(short arg0, std::string arg1, short arg2, bool arg3, unsigned arg4);
    void method4(int arg0, std::string arg1, std::string arg2, std::string arg3, bool arg4);
    float method5(unsigned arg0, std::string arg1, bool arg2, float arg3, std::string_view arg4);
    void method6(std::string const& arg0, bool arg1, unsigned arg2, short arg3, std::string arg4);
    void method7(double arg0, bool arg1, float arg2, bool arg3, int arg4);
    void method8(float arg0, std::string const& arg1, int arg2, float arg3, float arg4);
    void method9(std::string arg0, unsigned arg1, std::string arg2, bool arg3, double arg4);
    void method10(bool arg0, short arg1, double arg2, bool arg3, unsigned arg4);
    std::string_view method11(std::string_view arg0, std::string const& arg1, short arg2, unsigned arg3, std::string const& arg4);
    void method12(double arg0, std::string_view arg1, short arg2, float arg3, bool arg4);
    void method13(float arg0, std::string_view arg1, unsigned arg2, float arg3, short arg4);
    void method14(double arg0, std::string_view arg1, std::string_view arg2, int arg3, int arg4);
}
