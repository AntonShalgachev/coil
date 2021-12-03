#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class39
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(std::string_view arg0, double arg1, unsigned arg2, float arg3, int arg4);
    void method1(int arg0, unsigned arg1, std::string const& arg2, float arg3, unsigned arg4);
    void method2(unsigned arg0, int arg1, std::string arg2, unsigned arg3, short arg4);
    void method3(int arg0, short arg1, unsigned arg2, unsigned arg3, bool arg4);
    int method4(int arg0, int arg1, bool arg2, std::string arg3, std::string arg4);
    void method5(double arg0, std::string_view arg1, unsigned arg2, double arg3, float arg4);
    int method6(int arg0, double arg1, short arg2, float arg3, float arg4);
    void method7(std::string arg0, std::string_view arg1, double arg2, std::string arg3, short arg4);
    void method8(float arg0, int arg1, float arg2, std::string_view arg3, std::string arg4);
    void method9(float arg0, unsigned arg1, double arg2, std::string arg3, bool arg4);
    void method10(std::string const& arg0, bool arg1, unsigned arg2, short arg3, double arg4);
    void method11(unsigned arg0, std::string_view arg1, int arg2, bool arg3, unsigned arg4);
    void method12(double arg0, bool arg1, std::string arg2, std::string const& arg3, unsigned arg4);
    void method13(float arg0, float arg1, int arg2, float arg3, std::string_view arg4);
    std::string method14(bool arg0, short arg1, std::string_view arg2, std::string arg3, std::string arg4);
};

namespace ns_Class39
{
    unsigned method0(std::string_view arg0, double arg1, unsigned arg2, float arg3, int arg4);
    void method1(int arg0, unsigned arg1, std::string const& arg2, float arg3, unsigned arg4);
    void method2(unsigned arg0, int arg1, std::string arg2, unsigned arg3, short arg4);
    void method3(int arg0, short arg1, unsigned arg2, unsigned arg3, bool arg4);
    int method4(int arg0, int arg1, bool arg2, std::string arg3, std::string arg4);
    void method5(double arg0, std::string_view arg1, unsigned arg2, double arg3, float arg4);
    int method6(int arg0, double arg1, short arg2, float arg3, float arg4);
    void method7(std::string arg0, std::string_view arg1, double arg2, std::string arg3, short arg4);
    void method8(float arg0, int arg1, float arg2, std::string_view arg3, std::string arg4);
    void method9(float arg0, unsigned arg1, double arg2, std::string arg3, bool arg4);
    void method10(std::string const& arg0, bool arg1, unsigned arg2, short arg3, double arg4);
    void method11(unsigned arg0, std::string_view arg1, int arg2, bool arg3, unsigned arg4);
    void method12(double arg0, bool arg1, std::string arg2, std::string const& arg3, unsigned arg4);
    void method13(float arg0, float arg1, int arg2, float arg3, std::string_view arg4);
    std::string method14(bool arg0, short arg1, std::string_view arg2, std::string arg3, std::string arg4);
}
