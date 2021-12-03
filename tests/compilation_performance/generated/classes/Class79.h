#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class79
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, std::string arg1, std::string_view arg2, std::string arg3, short arg4);
    void method1(unsigned arg0, bool arg1, int arg2, std::string arg3, std::string const& arg4);
    void method2(int arg0, std::string const& arg1, short arg2, short arg3, short arg4);
    void method3(std::string const& arg0, std::string const& arg1, bool arg2, double arg3, unsigned arg4);
    void method4(int arg0, unsigned arg1, std::string_view arg2, int arg3, int arg4);
    std::string_view method5(std::string arg0, int arg1, std::string_view arg2, bool arg3, double arg4);
    void method6(short arg0, std::string_view arg1, std::string const& arg2, float arg3, bool arg4);
    void method7(bool arg0, unsigned arg1, unsigned arg2, int arg3, double arg4);
    void method8(double arg0, std::string_view arg1, int arg2, std::string arg3, std::string_view arg4);
    void method9(std::string_view arg0, std::string const& arg1, unsigned arg2, std::string const& arg3, short arg4);
    void method10(short arg0, std::string const& arg1, bool arg2, double arg3, float arg4);
    void method11(float arg0, std::string_view arg1, unsigned arg2, float arg3, float arg4);
    void method12(bool arg0, std::string const& arg1, unsigned arg2, double arg3, double arg4);
    void method13(bool arg0, std::string arg1, unsigned arg2, double arg3, bool arg4);
    std::string_view method14(int arg0, double arg1, int arg2, std::string_view arg3, int arg4);
};

namespace ns_Class79
{
    void method0(short arg0, std::string arg1, std::string_view arg2, std::string arg3, short arg4);
    void method1(unsigned arg0, bool arg1, int arg2, std::string arg3, std::string const& arg4);
    void method2(int arg0, std::string const& arg1, short arg2, short arg3, short arg4);
    void method3(std::string const& arg0, std::string const& arg1, bool arg2, double arg3, unsigned arg4);
    void method4(int arg0, unsigned arg1, std::string_view arg2, int arg3, int arg4);
    std::string_view method5(std::string arg0, int arg1, std::string_view arg2, bool arg3, double arg4);
    void method6(short arg0, std::string_view arg1, std::string const& arg2, float arg3, bool arg4);
    void method7(bool arg0, unsigned arg1, unsigned arg2, int arg3, double arg4);
    void method8(double arg0, std::string_view arg1, int arg2, std::string arg3, std::string_view arg4);
    void method9(std::string_view arg0, std::string const& arg1, unsigned arg2, std::string const& arg3, short arg4);
    void method10(short arg0, std::string const& arg1, bool arg2, double arg3, float arg4);
    void method11(float arg0, std::string_view arg1, unsigned arg2, float arg3, float arg4);
    void method12(bool arg0, std::string const& arg1, unsigned arg2, double arg3, double arg4);
    void method13(bool arg0, std::string arg1, unsigned arg2, double arg3, bool arg4);
    std::string_view method14(int arg0, double arg1, int arg2, std::string_view arg3, int arg4);
}
