#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class83
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(std::string_view arg0, short arg1, unsigned arg2, bool arg3, std::string arg4);
    std::string const& method1(std::string_view arg0, bool arg1, std::string const& arg2, std::string_view arg3, std::string const& arg4);
    void method2(unsigned arg0, std::string const& arg1, bool arg2, double arg3, int arg4);
    bool method3(bool arg0, std::string arg1, unsigned arg2, short arg3, double arg4);
    void method4(std::string const& arg0, std::string_view arg1, double arg2, std::string arg3, bool arg4);
    void method5(double arg0, unsigned arg1, double arg2, unsigned arg3, std::string_view arg4);
    std::string method6(std::string arg0, int arg1, short arg2, float arg3, double arg4);
    void method7(float arg0, bool arg1, short arg2, unsigned arg3, unsigned arg4);
    void method8(short arg0, std::string_view arg1, short arg2, int arg3, unsigned arg4);
    void method9(unsigned arg0, int arg1, bool arg2, unsigned arg3, short arg4);
    void method10(short arg0, unsigned arg1, float arg2, bool arg3, double arg4);
    void method11(double arg0, std::string arg1, short arg2, bool arg3, int arg4);
    unsigned method12(unsigned arg0, bool arg1, short arg2, std::string arg3, std::string const& arg4);
    short method13(std::string const& arg0, std::string arg1, std::string_view arg2, std::string_view arg3, short arg4);
    unsigned method14(int arg0, std::string_view arg1, std::string arg2, short arg3, unsigned arg4);
};

namespace ns_Class83
{
    unsigned method0(std::string_view arg0, short arg1, unsigned arg2, bool arg3, std::string arg4);
    std::string const& method1(std::string_view arg0, bool arg1, std::string const& arg2, std::string_view arg3, std::string const& arg4);
    void method2(unsigned arg0, std::string const& arg1, bool arg2, double arg3, int arg4);
    bool method3(bool arg0, std::string arg1, unsigned arg2, short arg3, double arg4);
    void method4(std::string const& arg0, std::string_view arg1, double arg2, std::string arg3, bool arg4);
    void method5(double arg0, unsigned arg1, double arg2, unsigned arg3, std::string_view arg4);
    std::string method6(std::string arg0, int arg1, short arg2, float arg3, double arg4);
    void method7(float arg0, bool arg1, short arg2, unsigned arg3, unsigned arg4);
    void method8(short arg0, std::string_view arg1, short arg2, int arg3, unsigned arg4);
    void method9(unsigned arg0, int arg1, bool arg2, unsigned arg3, short arg4);
    void method10(short arg0, unsigned arg1, float arg2, bool arg3, double arg4);
    void method11(double arg0, std::string arg1, short arg2, bool arg3, int arg4);
    unsigned method12(unsigned arg0, bool arg1, short arg2, std::string arg3, std::string const& arg4);
    short method13(std::string const& arg0, std::string arg1, std::string_view arg2, std::string_view arg3, short arg4);
    unsigned method14(int arg0, std::string_view arg1, std::string arg2, short arg3, unsigned arg4);
}
