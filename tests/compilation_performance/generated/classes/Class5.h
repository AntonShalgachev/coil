#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class5
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(std::string arg0, short arg1, std::string_view arg2, std::string_view arg3, float arg4);
    float method1(std::string arg0, std::string arg1, float arg2, int arg3, float arg4);
    std::string const& method2(short arg0, int arg1, double arg2, std::string arg3, std::string const& arg4);
    void method3(short arg0, std::string_view arg1, std::string const& arg2, double arg3, unsigned arg4);
    void method4(float arg0, short arg1, std::string arg2, int arg3, std::string const& arg4);
    void method5(float arg0, short arg1, short arg2, double arg3, float arg4);
    bool method6(short arg0, int arg1, short arg2, bool arg3, std::string const& arg4);
    void method7(std::string arg0, short arg1, short arg2, short arg3, bool arg4);
    void method8(double arg0, double arg1, bool arg2, double arg3, std::string const& arg4);
    std::string method9(double arg0, bool arg1, unsigned arg2, std::string arg3, std::string const& arg4);
    unsigned method10(unsigned arg0, unsigned arg1, std::string const& arg2, double arg3, std::string arg4);
    void method11(double arg0, int arg1, std::string arg2, bool arg3, short arg4);
    std::string method12(std::string_view arg0, std::string arg1, int arg2, std::string arg3, bool arg4);
    void method13(double arg0, bool arg1, unsigned arg2, std::string const& arg3, int arg4);
    void method14(std::string const& arg0, double arg1, std::string arg2, std::string const& arg3, short arg4);
};

namespace ns_Class5
{
    float method0(std::string arg0, short arg1, std::string_view arg2, std::string_view arg3, float arg4);
    float method1(std::string arg0, std::string arg1, float arg2, int arg3, float arg4);
    std::string const& method2(short arg0, int arg1, double arg2, std::string arg3, std::string const& arg4);
    void method3(short arg0, std::string_view arg1, std::string const& arg2, double arg3, unsigned arg4);
    void method4(float arg0, short arg1, std::string arg2, int arg3, std::string const& arg4);
    void method5(float arg0, short arg1, short arg2, double arg3, float arg4);
    bool method6(short arg0, int arg1, short arg2, bool arg3, std::string const& arg4);
    void method7(std::string arg0, short arg1, short arg2, short arg3, bool arg4);
    void method8(double arg0, double arg1, bool arg2, double arg3, std::string const& arg4);
    std::string method9(double arg0, bool arg1, unsigned arg2, std::string arg3, std::string const& arg4);
    unsigned method10(unsigned arg0, unsigned arg1, std::string const& arg2, double arg3, std::string arg4);
    void method11(double arg0, int arg1, std::string arg2, bool arg3, short arg4);
    std::string method12(std::string_view arg0, std::string arg1, int arg2, std::string arg3, bool arg4);
    void method13(double arg0, bool arg1, unsigned arg2, std::string const& arg3, int arg4);
    void method14(std::string const& arg0, double arg1, std::string arg2, std::string const& arg3, short arg4);
}
