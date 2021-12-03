#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class22
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(std::string_view arg0, float arg1, unsigned arg2, bool arg3, short arg4);
    float method1(short arg0, std::string arg1, float arg2, std::string const& arg3, int arg4);
    void method2(float arg0, short arg1, std::string_view arg2, unsigned arg3, short arg4);
    int method3(double arg0, int arg1, std::string const& arg2, unsigned arg3, bool arg4);
    void method4(std::string_view arg0, short arg1, std::string const& arg2, unsigned arg3, std::string arg4);
    void method5(bool arg0, std::string const& arg1, std::string arg2, double arg3, double arg4);
    std::string_view method6(short arg0, std::string const& arg1, short arg2, std::string_view arg3, int arg4);
    void method7(std::string const& arg0, bool arg1, std::string_view arg2, double arg3, std::string arg4);
    unsigned method8(double arg0, float arg1, std::string_view arg2, bool arg3, unsigned arg4);
    short method9(int arg0, unsigned arg1, double arg2, double arg3, short arg4);
    unsigned method10(unsigned arg0, unsigned arg1, float arg2, std::string arg3, bool arg4);
    bool method11(std::string arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    std::string const& method12(int arg0, std::string arg1, std::string_view arg2, std::string_view arg3, std::string const& arg4);
    void method13(int arg0, bool arg1, bool arg2, bool arg3, double arg4);
    std::string const& method14(std::string const& arg0, std::string arg1, bool arg2, std::string arg3, bool arg4);
};

namespace ns_Class22
{
    short method0(std::string_view arg0, float arg1, unsigned arg2, bool arg3, short arg4);
    float method1(short arg0, std::string arg1, float arg2, std::string const& arg3, int arg4);
    void method2(float arg0, short arg1, std::string_view arg2, unsigned arg3, short arg4);
    int method3(double arg0, int arg1, std::string const& arg2, unsigned arg3, bool arg4);
    void method4(std::string_view arg0, short arg1, std::string const& arg2, unsigned arg3, std::string arg4);
    void method5(bool arg0, std::string const& arg1, std::string arg2, double arg3, double arg4);
    std::string_view method6(short arg0, std::string const& arg1, short arg2, std::string_view arg3, int arg4);
    void method7(std::string const& arg0, bool arg1, std::string_view arg2, double arg3, std::string arg4);
    unsigned method8(double arg0, float arg1, std::string_view arg2, bool arg3, unsigned arg4);
    short method9(int arg0, unsigned arg1, double arg2, double arg3, short arg4);
    unsigned method10(unsigned arg0, unsigned arg1, float arg2, std::string arg3, bool arg4);
    bool method11(std::string arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    std::string const& method12(int arg0, std::string arg1, std::string_view arg2, std::string_view arg3, std::string const& arg4);
    void method13(int arg0, bool arg1, bool arg2, bool arg3, double arg4);
    std::string const& method14(std::string const& arg0, std::string arg1, bool arg2, std::string arg3, bool arg4);
}
