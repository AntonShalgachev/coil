#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class92
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, double arg1, bool arg2, std::string_view arg3, unsigned arg4);
    bool method1(bool arg0, int arg1, short arg2, int arg3, std::string const& arg4);
    float method2(std::string_view arg0, short arg1, std::string_view arg2, float arg3, bool arg4);
    void method3(int arg0, std::string const& arg1, float arg2, std::string const& arg3, bool arg4);
    void method4(int arg0, short arg1, std::string_view arg2, float arg3, short arg4);
    unsigned method5(double arg0, unsigned arg1, bool arg2, int arg3, unsigned arg4);
    void method6(std::string const& arg0, std::string const& arg1, std::string const& arg2, short arg3, std::string_view arg4);
    float method7(std::string_view arg0, std::string arg1, float arg2, double arg3, bool arg4);
    unsigned method8(double arg0, float arg1, unsigned arg2, unsigned arg3, float arg4);
    void method9(double arg0, int arg1, float arg2, int arg3, double arg4);
    float method10(std::string arg0, int arg1, float arg2, std::string arg3, int arg4);
    short method11(short arg0, std::string_view arg1, bool arg2, float arg3, unsigned arg4);
    void method12(float arg0, std::string_view arg1, std::string_view arg2, float arg3, bool arg4);
    void method13(unsigned arg0, int arg1, std::string arg2, std::string arg3, bool arg4);
    void method14(std::string arg0, short arg1, std::string const& arg2, std::string_view arg3, unsigned arg4);
};

namespace ns_Class92
{
    void method0(short arg0, double arg1, bool arg2, std::string_view arg3, unsigned arg4);
    bool method1(bool arg0, int arg1, short arg2, int arg3, std::string const& arg4);
    float method2(std::string_view arg0, short arg1, std::string_view arg2, float arg3, bool arg4);
    void method3(int arg0, std::string const& arg1, float arg2, std::string const& arg3, bool arg4);
    void method4(int arg0, short arg1, std::string_view arg2, float arg3, short arg4);
    unsigned method5(double arg0, unsigned arg1, bool arg2, int arg3, unsigned arg4);
    void method6(std::string const& arg0, std::string const& arg1, std::string const& arg2, short arg3, std::string_view arg4);
    float method7(std::string_view arg0, std::string arg1, float arg2, double arg3, bool arg4);
    unsigned method8(double arg0, float arg1, unsigned arg2, unsigned arg3, float arg4);
    void method9(double arg0, int arg1, float arg2, int arg3, double arg4);
    float method10(std::string arg0, int arg1, float arg2, std::string arg3, int arg4);
    short method11(short arg0, std::string_view arg1, bool arg2, float arg3, unsigned arg4);
    void method12(float arg0, std::string_view arg1, std::string_view arg2, float arg3, bool arg4);
    void method13(unsigned arg0, int arg1, std::string arg2, std::string arg3, bool arg4);
    void method14(std::string arg0, short arg1, std::string const& arg2, std::string_view arg3, unsigned arg4);
}
