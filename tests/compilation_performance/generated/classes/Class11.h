#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class11
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(std::string arg0, double arg1, bool arg2, std::string const& arg3, std::string arg4);
    std::string method1(std::string_view arg0, float arg1, float arg2, std::string arg3, double arg4);
    float method2(int arg0, std::string const& arg1, short arg2, float arg3, float arg4);
    double method3(float arg0, std::string_view arg1, short arg2, double arg3, std::string arg4);
    std::string_view method4(short arg0, short arg1, bool arg2, short arg3, std::string_view arg4);
    unsigned method5(std::string arg0, unsigned arg1, std::string const& arg2, unsigned arg3, double arg4);
    void method6(std::string_view arg0, float arg1, std::string_view arg2, short arg3, short arg4);
    void method7(std::string arg0, float arg1, std::string arg2, std::string_view arg3, std::string arg4);
    void method8(int arg0, int arg1, bool arg2, short arg3, std::string_view arg4);
    std::string method9(std::string_view arg0, std::string const& arg1, std::string_view arg2, std::string arg3, double arg4);
    std::string method10(std::string arg0, double arg1, float arg2, std::string const& arg3, unsigned arg4);
    short method11(std::string arg0, std::string arg1, short arg2, bool arg3, int arg4);
    short method12(float arg0, std::string const& arg1, float arg2, short arg3, short arg4);
    void method13(short arg0, std::string arg1, bool arg2, float arg3, bool arg4);
    void method14(std::string arg0, short arg1, int arg2, std::string_view arg3, std::string_view arg4);
};

namespace ns_Class11
{
    void method0(std::string arg0, double arg1, bool arg2, std::string const& arg3, std::string arg4);
    std::string method1(std::string_view arg0, float arg1, float arg2, std::string arg3, double arg4);
    float method2(int arg0, std::string const& arg1, short arg2, float arg3, float arg4);
    double method3(float arg0, std::string_view arg1, short arg2, double arg3, std::string arg4);
    std::string_view method4(short arg0, short arg1, bool arg2, short arg3, std::string_view arg4);
    unsigned method5(std::string arg0, unsigned arg1, std::string const& arg2, unsigned arg3, double arg4);
    void method6(std::string_view arg0, float arg1, std::string_view arg2, short arg3, short arg4);
    void method7(std::string arg0, float arg1, std::string arg2, std::string_view arg3, std::string arg4);
    void method8(int arg0, int arg1, bool arg2, short arg3, std::string_view arg4);
    std::string method9(std::string_view arg0, std::string const& arg1, std::string_view arg2, std::string arg3, double arg4);
    std::string method10(std::string arg0, double arg1, float arg2, std::string const& arg3, unsigned arg4);
    short method11(std::string arg0, std::string arg1, short arg2, bool arg3, int arg4);
    short method12(float arg0, std::string const& arg1, float arg2, short arg3, short arg4);
    void method13(short arg0, std::string arg1, bool arg2, float arg3, bool arg4);
    void method14(std::string arg0, short arg1, int arg2, std::string_view arg3, std::string_view arg4);
}
