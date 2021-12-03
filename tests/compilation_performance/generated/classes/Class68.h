#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class68
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(bool arg0, double arg1, double arg2, unsigned arg3, float arg4);
    void method1(std::string arg0, double arg1, short arg2, std::string const& arg3, double arg4);
    void method2(double arg0, short arg1, std::string_view arg2, bool arg3, unsigned arg4);
    std::string_view method3(std::string_view arg0, std::string_view arg1, double arg2, double arg3, float arg4);
    void method4(std::string const& arg0, std::string_view arg1, int arg2, int arg3, float arg4);
    void method5(unsigned arg0, double arg1, int arg2, float arg3, unsigned arg4);
    void method6(float arg0, std::string const& arg1, std::string const& arg2, bool arg3, std::string arg4);
    void method7(double arg0, double arg1, double arg2, double arg3, std::string const& arg4);
    void method8(std::string const& arg0, std::string const& arg1, int arg2, std::string const& arg3, bool arg4);
    std::string const& method9(double arg0, unsigned arg1, std::string const& arg2, std::string const& arg3, std::string arg4);
    std::string_view method10(int arg0, std::string_view arg1, double arg2, double arg3, std::string const& arg4);
    bool method11(std::string_view arg0, short arg1, float arg2, bool arg3, bool arg4);
    void method12(double arg0, unsigned arg1, int arg2, float arg3, unsigned arg4);
    void method13(short arg0, float arg1, int arg2, int arg3, std::string const& arg4);
    void method14(int arg0, double arg1, std::string arg2, bool arg3, unsigned arg4);
};

namespace ns_Class68
{
    unsigned method0(bool arg0, double arg1, double arg2, unsigned arg3, float arg4);
    void method1(std::string arg0, double arg1, short arg2, std::string const& arg3, double arg4);
    void method2(double arg0, short arg1, std::string_view arg2, bool arg3, unsigned arg4);
    std::string_view method3(std::string_view arg0, std::string_view arg1, double arg2, double arg3, float arg4);
    void method4(std::string const& arg0, std::string_view arg1, int arg2, int arg3, float arg4);
    void method5(unsigned arg0, double arg1, int arg2, float arg3, unsigned arg4);
    void method6(float arg0, std::string const& arg1, std::string const& arg2, bool arg3, std::string arg4);
    void method7(double arg0, double arg1, double arg2, double arg3, std::string const& arg4);
    void method8(std::string const& arg0, std::string const& arg1, int arg2, std::string const& arg3, bool arg4);
    std::string const& method9(double arg0, unsigned arg1, std::string const& arg2, std::string const& arg3, std::string arg4);
    std::string_view method10(int arg0, std::string_view arg1, double arg2, double arg3, std::string const& arg4);
    bool method11(std::string_view arg0, short arg1, float arg2, bool arg3, bool arg4);
    void method12(double arg0, unsigned arg1, int arg2, float arg3, unsigned arg4);
    void method13(short arg0, float arg1, int arg2, int arg3, std::string const& arg4);
    void method14(int arg0, double arg1, std::string arg2, bool arg3, unsigned arg4);
}
