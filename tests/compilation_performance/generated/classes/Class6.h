#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class6
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(bool arg0, int arg1, short arg2, std::string arg3, float arg4);
    void method1(bool arg0, float arg1, std::string_view arg2, bool arg3, unsigned arg4);
    float method2(float arg0, short arg1, short arg2, std::string arg3, int arg4);
    void method3(short arg0, std::string const& arg1, int arg2, short arg3, float arg4);
    void method4(double arg0, std::string const& arg1, std::string_view arg2, std::string const& arg3, short arg4);
    std::string_view method5(unsigned arg0, int arg1, std::string_view arg2, float arg3, short arg4);
    void method6(std::string const& arg0, short arg1, float arg2, bool arg3, float arg4);
    void method7(std::string const& arg0, std::string const& arg1, std::string_view arg2, std::string_view arg3, unsigned arg4);
    void method8(std::string_view arg0, std::string const& arg1, double arg2, bool arg3, float arg4);
    double method9(bool arg0, std::string arg1, bool arg2, double arg3, unsigned arg4);
    void method10(unsigned arg0, int arg1, unsigned arg2, double arg3, int arg4);
    void method11(int arg0, std::string_view arg1, std::string_view arg2, bool arg3, float arg4);
    std::string_view method12(unsigned arg0, double arg1, std::string_view arg2, std::string_view arg3, std::string const& arg4);
    void method13(std::string const& arg0, short arg1, unsigned arg2, std::string const& arg3, float arg4);
    void method14(short arg0, bool arg1, double arg2, double arg3, std::string const& arg4);
};

namespace ns_Class6
{
    short method0(bool arg0, int arg1, short arg2, std::string arg3, float arg4);
    void method1(bool arg0, float arg1, std::string_view arg2, bool arg3, unsigned arg4);
    float method2(float arg0, short arg1, short arg2, std::string arg3, int arg4);
    void method3(short arg0, std::string const& arg1, int arg2, short arg3, float arg4);
    void method4(double arg0, std::string const& arg1, std::string_view arg2, std::string const& arg3, short arg4);
    std::string_view method5(unsigned arg0, int arg1, std::string_view arg2, float arg3, short arg4);
    void method6(std::string const& arg0, short arg1, float arg2, bool arg3, float arg4);
    void method7(std::string const& arg0, std::string const& arg1, std::string_view arg2, std::string_view arg3, unsigned arg4);
    void method8(std::string_view arg0, std::string const& arg1, double arg2, bool arg3, float arg4);
    double method9(bool arg0, std::string arg1, bool arg2, double arg3, unsigned arg4);
    void method10(unsigned arg0, int arg1, unsigned arg2, double arg3, int arg4);
    void method11(int arg0, std::string_view arg1, std::string_view arg2, bool arg3, float arg4);
    std::string_view method12(unsigned arg0, double arg1, std::string_view arg2, std::string_view arg3, std::string const& arg4);
    void method13(std::string const& arg0, short arg1, unsigned arg2, std::string const& arg3, float arg4);
    void method14(short arg0, bool arg1, double arg2, double arg3, std::string const& arg4);
}
