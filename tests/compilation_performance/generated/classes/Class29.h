#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class29
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string_view method0(float arg0, float arg1, std::string_view arg2, float arg3, float arg4);
    void method1(unsigned arg0, bool arg1, float arg2, double arg3, short arg4);
    int method2(std::string const& arg0, std::string arg1, bool arg2, int arg3, std::string const& arg4);
    std::string const& method3(int arg0, unsigned arg1, double arg2, std::string_view arg3, std::string const& arg4);
    void method4(std::string_view arg0, unsigned arg1, double arg2, int arg3, std::string const& arg4);
    void method5(unsigned arg0, std::string const& arg1, std::string_view arg2, double arg3, std::string_view arg4);
    short method6(std::string const& arg0, std::string arg1, bool arg2, bool arg3, short arg4);
    double method7(std::string const& arg0, double arg1, std::string const& arg2, std::string arg3, unsigned arg4);
    unsigned method8(unsigned arg0, bool arg1, int arg2, unsigned arg3, unsigned arg4);
    void method9(int arg0, double arg1, float arg2, int arg3, double arg4);
    void method10(std::string arg0, double arg1, double arg2, unsigned arg3, short arg4);
    unsigned method11(std::string arg0, short arg1, int arg2, double arg3, unsigned arg4);
    void method12(unsigned arg0, std::string const& arg1, std::string_view arg2, float arg3, double arg4);
    void method13(bool arg0, std::string_view arg1, std::string const& arg2, double arg3, std::string const& arg4);
    void method14(bool arg0, double arg1, std::string_view arg2, std::string_view arg3, std::string const& arg4);
};

namespace ns_Class29
{
    std::string_view method0(float arg0, float arg1, std::string_view arg2, float arg3, float arg4);
    void method1(unsigned arg0, bool arg1, float arg2, double arg3, short arg4);
    int method2(std::string const& arg0, std::string arg1, bool arg2, int arg3, std::string const& arg4);
    std::string const& method3(int arg0, unsigned arg1, double arg2, std::string_view arg3, std::string const& arg4);
    void method4(std::string_view arg0, unsigned arg1, double arg2, int arg3, std::string const& arg4);
    void method5(unsigned arg0, std::string const& arg1, std::string_view arg2, double arg3, std::string_view arg4);
    short method6(std::string const& arg0, std::string arg1, bool arg2, bool arg3, short arg4);
    double method7(std::string const& arg0, double arg1, std::string const& arg2, std::string arg3, unsigned arg4);
    unsigned method8(unsigned arg0, bool arg1, int arg2, unsigned arg3, unsigned arg4);
    void method9(int arg0, double arg1, float arg2, int arg3, double arg4);
    void method10(std::string arg0, double arg1, double arg2, unsigned arg3, short arg4);
    unsigned method11(std::string arg0, short arg1, int arg2, double arg3, unsigned arg4);
    void method12(unsigned arg0, std::string const& arg1, std::string_view arg2, float arg3, double arg4);
    void method13(bool arg0, std::string_view arg1, std::string const& arg2, double arg3, std::string const& arg4);
    void method14(bool arg0, double arg1, std::string_view arg2, std::string_view arg3, std::string const& arg4);
}
