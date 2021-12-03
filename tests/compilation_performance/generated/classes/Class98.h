#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class98
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(std::string arg0, unsigned arg1, int arg2, unsigned arg3, double arg4);
    void method1(unsigned arg0, float arg1, int arg2, std::string_view arg3, short arg4);
    void method2(std::string const& arg0, std::string const& arg1, int arg2, short arg3, float arg4);
    void method3(std::string arg0, bool arg1, float arg2, std::string_view arg3, std::string arg4);
    float method4(float arg0, int arg1, std::string_view arg2, float arg3, std::string_view arg4);
    short method5(std::string_view arg0, std::string_view arg1, std::string_view arg2, int arg3, short arg4);
    void method6(unsigned arg0, double arg1, unsigned arg2, unsigned arg3, short arg4);
    double method7(double arg0, int arg1, unsigned arg2, unsigned arg3, std::string arg4);
    void method8(std::string const& arg0, short arg1, int arg2, int arg3, bool arg4);
    void method9(std::string arg0, std::string const& arg1, std::string arg2, unsigned arg3, float arg4);
    unsigned method10(float arg0, std::string_view arg1, float arg2, std::string_view arg3, unsigned arg4);
    int method11(std::string const& arg0, int arg1, double arg2, double arg3, std::string arg4);
    void method12(bool arg0, double arg1, bool arg2, double arg3, bool arg4);
    std::string method13(std::string_view arg0, std::string_view arg1, double arg2, short arg3, std::string arg4);
    int method14(int arg0, short arg1, unsigned arg2, float arg3, std::string const& arg4);
};

namespace ns_Class98
{
    void method0(std::string arg0, unsigned arg1, int arg2, unsigned arg3, double arg4);
    void method1(unsigned arg0, float arg1, int arg2, std::string_view arg3, short arg4);
    void method2(std::string const& arg0, std::string const& arg1, int arg2, short arg3, float arg4);
    void method3(std::string arg0, bool arg1, float arg2, std::string_view arg3, std::string arg4);
    float method4(float arg0, int arg1, std::string_view arg2, float arg3, std::string_view arg4);
    short method5(std::string_view arg0, std::string_view arg1, std::string_view arg2, int arg3, short arg4);
    void method6(unsigned arg0, double arg1, unsigned arg2, unsigned arg3, short arg4);
    double method7(double arg0, int arg1, unsigned arg2, unsigned arg3, std::string arg4);
    void method8(std::string const& arg0, short arg1, int arg2, int arg3, bool arg4);
    void method9(std::string arg0, std::string const& arg1, std::string arg2, unsigned arg3, float arg4);
    unsigned method10(float arg0, std::string_view arg1, float arg2, std::string_view arg3, unsigned arg4);
    int method11(std::string const& arg0, int arg1, double arg2, double arg3, std::string arg4);
    void method12(bool arg0, double arg1, bool arg2, double arg3, bool arg4);
    std::string method13(std::string_view arg0, std::string_view arg1, double arg2, short arg3, std::string arg4);
    int method14(int arg0, short arg1, unsigned arg2, float arg3, std::string const& arg4);
}
