#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class43
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(bool arg0, std::string arg1, std::string const& arg2, unsigned arg3, short arg4);
    void method1(unsigned arg0, std::string arg1, int arg2, unsigned arg3, unsigned arg4);
    void method2(float arg0, float arg1, bool arg2, unsigned arg3, int arg4);
    void method3(double arg0, int arg1, std::string arg2, short arg3, double arg4);
    std::string_view method4(std::string arg0, std::string arg1, std::string const& arg2, std::string arg3, std::string_view arg4);
    void method5(short arg0, std::string_view arg1, double arg2, std::string_view arg3, double arg4);
    void method6(short arg0, std::string_view arg1, float arg2, int arg3, int arg4);
    void method7(int arg0, double arg1, bool arg2, std::string arg3, std::string_view arg4);
    void method8(std::string arg0, double arg1, std::string arg2, short arg3, bool arg4);
    void method9(unsigned arg0, std::string_view arg1, float arg2, double arg3, short arg4);
    void method10(std::string const& arg0, int arg1, std::string_view arg2, std::string arg3, bool arg4);
    unsigned method11(unsigned arg0, unsigned arg1, bool arg2, std::string arg3, float arg4);
    void method12(float arg0, double arg1, double arg2, std::string arg3, float arg4);
    std::string method13(int arg0, std::string_view arg1, std::string arg2, short arg3, bool arg4);
    void method14(unsigned arg0, int arg1, unsigned arg2, bool arg3, double arg4);
};

namespace ns_Class43
{
    void method0(bool arg0, std::string arg1, std::string const& arg2, unsigned arg3, short arg4);
    void method1(unsigned arg0, std::string arg1, int arg2, unsigned arg3, unsigned arg4);
    void method2(float arg0, float arg1, bool arg2, unsigned arg3, int arg4);
    void method3(double arg0, int arg1, std::string arg2, short arg3, double arg4);
    std::string_view method4(std::string arg0, std::string arg1, std::string const& arg2, std::string arg3, std::string_view arg4);
    void method5(short arg0, std::string_view arg1, double arg2, std::string_view arg3, double arg4);
    void method6(short arg0, std::string_view arg1, float arg2, int arg3, int arg4);
    void method7(int arg0, double arg1, bool arg2, std::string arg3, std::string_view arg4);
    void method8(std::string arg0, double arg1, std::string arg2, short arg3, bool arg4);
    void method9(unsigned arg0, std::string_view arg1, float arg2, double arg3, short arg4);
    void method10(std::string const& arg0, int arg1, std::string_view arg2, std::string arg3, bool arg4);
    unsigned method11(unsigned arg0, unsigned arg1, bool arg2, std::string arg3, float arg4);
    void method12(float arg0, double arg1, double arg2, std::string arg3, float arg4);
    std::string method13(int arg0, std::string_view arg1, std::string arg2, short arg3, bool arg4);
    void method14(unsigned arg0, int arg1, unsigned arg2, bool arg3, double arg4);
}
