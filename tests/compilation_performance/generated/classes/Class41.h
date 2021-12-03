#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class41
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, std::string arg1, float arg2, int arg3, std::string const& arg4);
    unsigned method1(short arg0, bool arg1, unsigned arg2, unsigned arg3, std::string_view arg4);
    void method2(std::string arg0, float arg1, float arg2, std::string_view arg3, short arg4);
    void method3(float arg0, std::string const& arg1, std::string arg2, double arg3, bool arg4);
    double method4(std::string const& arg0, bool arg1, double arg2, unsigned arg3, std::string_view arg4);
    std::string const& method5(double arg0, short arg1, std::string const& arg2, std::string_view arg3, std::string_view arg4);
    void method6(int arg0, std::string arg1, std::string_view arg2, std::string_view arg3, int arg4);
    short method7(std::string const& arg0, short arg1, float arg2, std::string_view arg3, std::string const& arg4);
    void method8(std::string const& arg0, float arg1, std::string_view arg2, bool arg3, std::string_view arg4);
    std::string_view method9(double arg0, float arg1, double arg2, std::string_view arg3, std::string_view arg4);
    void method10(double arg0, std::string const& arg1, std::string_view arg2, int arg3, std::string const& arg4);
    void method11(unsigned arg0, float arg1, bool arg2, std::string const& arg3, std::string_view arg4);
    void method12(std::string_view arg0, double arg1, unsigned arg2, int arg3, float arg4);
    double method13(std::string arg0, short arg1, double arg2, float arg3, std::string arg4);
    float method14(std::string arg0, short arg1, std::string const& arg2, float arg3, double arg4);
};

namespace ns_Class41
{
    void method0(unsigned arg0, std::string arg1, float arg2, int arg3, std::string const& arg4);
    unsigned method1(short arg0, bool arg1, unsigned arg2, unsigned arg3, std::string_view arg4);
    void method2(std::string arg0, float arg1, float arg2, std::string_view arg3, short arg4);
    void method3(float arg0, std::string const& arg1, std::string arg2, double arg3, bool arg4);
    double method4(std::string const& arg0, bool arg1, double arg2, unsigned arg3, std::string_view arg4);
    std::string const& method5(double arg0, short arg1, std::string const& arg2, std::string_view arg3, std::string_view arg4);
    void method6(int arg0, std::string arg1, std::string_view arg2, std::string_view arg3, int arg4);
    short method7(std::string const& arg0, short arg1, float arg2, std::string_view arg3, std::string const& arg4);
    void method8(std::string const& arg0, float arg1, std::string_view arg2, bool arg3, std::string_view arg4);
    std::string_view method9(double arg0, float arg1, double arg2, std::string_view arg3, std::string_view arg4);
    void method10(double arg0, std::string const& arg1, std::string_view arg2, int arg3, std::string const& arg4);
    void method11(unsigned arg0, float arg1, bool arg2, std::string const& arg3, std::string_view arg4);
    void method12(std::string_view arg0, double arg1, unsigned arg2, int arg3, float arg4);
    double method13(std::string arg0, short arg1, double arg2, float arg3, std::string arg4);
    float method14(std::string arg0, short arg1, std::string const& arg2, float arg3, double arg4);
}
