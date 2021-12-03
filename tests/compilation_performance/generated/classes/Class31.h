#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class31
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, std::string_view arg1, double arg2, double arg3, short arg4);
    short method1(std::string_view arg0, unsigned arg1, bool arg2, std::string const& arg3, short arg4);
    void method2(std::string const& arg0, bool arg1, short arg2, unsigned arg3, bool arg4);
    void method3(std::string arg0, int arg1, std::string arg2, double arg3, int arg4);
    float method4(int arg0, float arg1, std::string_view arg2, bool arg3, unsigned arg4);
    int method5(short arg0, std::string arg1, double arg2, std::string const& arg3, int arg4);
    void method6(double arg0, double arg1, bool arg2, short arg3, std::string arg4);
    double method7(bool arg0, short arg1, double arg2, double arg3, std::string arg4);
    void method8(std::string const& arg0, float arg1, float arg2, std::string arg3, bool arg4);
    float method9(std::string const& arg0, int arg1, float arg2, bool arg3, short arg4);
    std::string method10(std::string arg0, double arg1, double arg2, float arg3, std::string_view arg4);
    std::string_view method11(bool arg0, float arg1, bool arg2, std::string_view arg3, std::string arg4);
    void method12(float arg0, int arg1, unsigned arg2, int arg3, float arg4);
    void method13(std::string const& arg0, int arg1, short arg2, bool arg3, unsigned arg4);
    void method14(std::string const& arg0, unsigned arg1, float arg2, double arg3, bool arg4);
};

namespace ns_Class31
{
    void method0(float arg0, std::string_view arg1, double arg2, double arg3, short arg4);
    short method1(std::string_view arg0, unsigned arg1, bool arg2, std::string const& arg3, short arg4);
    void method2(std::string const& arg0, bool arg1, short arg2, unsigned arg3, bool arg4);
    void method3(std::string arg0, int arg1, std::string arg2, double arg3, int arg4);
    float method4(int arg0, float arg1, std::string_view arg2, bool arg3, unsigned arg4);
    int method5(short arg0, std::string arg1, double arg2, std::string const& arg3, int arg4);
    void method6(double arg0, double arg1, bool arg2, short arg3, std::string arg4);
    double method7(bool arg0, short arg1, double arg2, double arg3, std::string arg4);
    void method8(std::string const& arg0, float arg1, float arg2, std::string arg3, bool arg4);
    float method9(std::string const& arg0, int arg1, float arg2, bool arg3, short arg4);
    std::string method10(std::string arg0, double arg1, double arg2, float arg3, std::string_view arg4);
    std::string_view method11(bool arg0, float arg1, bool arg2, std::string_view arg3, std::string arg4);
    void method12(float arg0, int arg1, unsigned arg2, int arg3, float arg4);
    void method13(std::string const& arg0, int arg1, short arg2, bool arg3, unsigned arg4);
    void method14(std::string const& arg0, unsigned arg1, float arg2, double arg3, bool arg4);
}
