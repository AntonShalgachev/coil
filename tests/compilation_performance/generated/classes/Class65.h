#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class65
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, float arg1, unsigned arg2, unsigned arg3, short arg4);
    void method1(short arg0, float arg1, int arg2, int arg3, bool arg4);
    short method2(bool arg0, double arg1, float arg2, short arg3, std::string_view arg4);
    void method3(std::string const& arg0, double arg1, double arg2, double arg3, std::string arg4);
    std::string const& method4(float arg0, std::string const& arg1, unsigned arg2, double arg3, int arg4);
    void method5(std::string const& arg0, std::string const& arg1, std::string_view arg2, bool arg3, bool arg4);
    void method6(unsigned arg0, unsigned arg1, double arg2, short arg3, unsigned arg4);
    void method7(std::string const& arg0, short arg1, bool arg2, float arg3, unsigned arg4);
    void method8(std::string arg0, float arg1, bool arg2, std::string const& arg3, bool arg4);
    void method9(std::string arg0, unsigned arg1, int arg2, int arg3, std::string const& arg4);
    unsigned method10(unsigned arg0, std::string const& arg1, unsigned arg2, std::string arg3, std::string_view arg4);
    void method11(unsigned arg0, double arg1, int arg2, short arg3, std::string_view arg4);
    void method12(unsigned arg0, short arg1, std::string_view arg2, double arg3, bool arg4);
    void method13(std::string arg0, int arg1, float arg2, std::string_view arg3, std::string const& arg4);
    std::string method14(std::string_view arg0, std::string arg1, unsigned arg2, unsigned arg3, double arg4);
};

namespace ns_Class65
{
    void method0(int arg0, float arg1, unsigned arg2, unsigned arg3, short arg4);
    void method1(short arg0, float arg1, int arg2, int arg3, bool arg4);
    short method2(bool arg0, double arg1, float arg2, short arg3, std::string_view arg4);
    void method3(std::string const& arg0, double arg1, double arg2, double arg3, std::string arg4);
    std::string const& method4(float arg0, std::string const& arg1, unsigned arg2, double arg3, int arg4);
    void method5(std::string const& arg0, std::string const& arg1, std::string_view arg2, bool arg3, bool arg4);
    void method6(unsigned arg0, unsigned arg1, double arg2, short arg3, unsigned arg4);
    void method7(std::string const& arg0, short arg1, bool arg2, float arg3, unsigned arg4);
    void method8(std::string arg0, float arg1, bool arg2, std::string const& arg3, bool arg4);
    void method9(std::string arg0, unsigned arg1, int arg2, int arg3, std::string const& arg4);
    unsigned method10(unsigned arg0, std::string const& arg1, unsigned arg2, std::string arg3, std::string_view arg4);
    void method11(unsigned arg0, double arg1, int arg2, short arg3, std::string_view arg4);
    void method12(unsigned arg0, short arg1, std::string_view arg2, double arg3, bool arg4);
    void method13(std::string arg0, int arg1, float arg2, std::string_view arg3, std::string const& arg4);
    std::string method14(std::string_view arg0, std::string arg1, unsigned arg2, unsigned arg3, double arg4);
}
