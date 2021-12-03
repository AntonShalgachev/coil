#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class33
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, bool arg1, unsigned arg2, std::string const& arg3, float arg4);
    void method1(unsigned arg0, bool arg1, std::string_view arg2, int arg3, std::string const& arg4);
    short method2(std::string arg0, short arg1, unsigned arg2, float arg3, float arg4);
    double method3(double arg0, int arg1, std::string const& arg2, int arg3, unsigned arg4);
    void method4(unsigned arg0, float arg1, float arg2, std::string_view arg3, float arg4);
    void method5(unsigned arg0, double arg1, bool arg2, short arg3, std::string_view arg4);
    void method6(bool arg0, float arg1, unsigned arg2, std::string const& arg3, short arg4);
    std::string method7(std::string_view arg0, bool arg1, bool arg2, bool arg3, std::string arg4);
    short method8(std::string arg0, int arg1, float arg2, short arg3, bool arg4);
    float method9(bool arg0, unsigned arg1, short arg2, float arg3, std::string arg4);
    void method10(std::string_view arg0, int arg1, unsigned arg2, int arg3, short arg4);
    void method11(short arg0, float arg1, double arg2, std::string const& arg3, std::string const& arg4);
    std::string const& method12(std::string const& arg0, float arg1, int arg2, bool arg3, short arg4);
    void method13(int arg0, unsigned arg1, std::string const& arg2, short arg3, std::string_view arg4);
    int method14(std::string arg0, int arg1, float arg2, bool arg3, float arg4);
};

namespace ns_Class33
{
    void method0(double arg0, bool arg1, unsigned arg2, std::string const& arg3, float arg4);
    void method1(unsigned arg0, bool arg1, std::string_view arg2, int arg3, std::string const& arg4);
    short method2(std::string arg0, short arg1, unsigned arg2, float arg3, float arg4);
    double method3(double arg0, int arg1, std::string const& arg2, int arg3, unsigned arg4);
    void method4(unsigned arg0, float arg1, float arg2, std::string_view arg3, float arg4);
    void method5(unsigned arg0, double arg1, bool arg2, short arg3, std::string_view arg4);
    void method6(bool arg0, float arg1, unsigned arg2, std::string const& arg3, short arg4);
    std::string method7(std::string_view arg0, bool arg1, bool arg2, bool arg3, std::string arg4);
    short method8(std::string arg0, int arg1, float arg2, short arg3, bool arg4);
    float method9(bool arg0, unsigned arg1, short arg2, float arg3, std::string arg4);
    void method10(std::string_view arg0, int arg1, unsigned arg2, int arg3, short arg4);
    void method11(short arg0, float arg1, double arg2, std::string const& arg3, std::string const& arg4);
    std::string const& method12(std::string const& arg0, float arg1, int arg2, bool arg3, short arg4);
    void method13(int arg0, unsigned arg1, std::string const& arg2, short arg3, std::string_view arg4);
    int method14(std::string arg0, int arg1, float arg2, bool arg3, float arg4);
}
