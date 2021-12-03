#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class59
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(std::string arg0, std::string arg1, short arg2, std::string_view arg3, std::string arg4);
    float method1(float arg0, int arg1, double arg2, unsigned arg3, bool arg4);
    double method2(std::string_view arg0, float arg1, double arg2, bool arg3, double arg4);
    void method3(std::string_view arg0, short arg1, std::string arg2, int arg3, double arg4);
    double method4(unsigned arg0, float arg1, std::string arg2, std::string_view arg3, double arg4);
    void method5(short arg0, std::string arg1, float arg2, bool arg3, bool arg4);
    float method6(std::string arg0, std::string_view arg1, short arg2, bool arg3, float arg4);
    std::string const& method7(std::string const& arg0, bool arg1, bool arg2, std::string arg3, std::string_view arg4);
    void method8(double arg0, float arg1, std::string arg2, std::string arg3, std::string const& arg4);
    double method9(std::string arg0, std::string arg1, double arg2, bool arg3, short arg4);
    unsigned method10(std::string const& arg0, int arg1, unsigned arg2, float arg3, unsigned arg4);
    std::string_view method11(std::string_view arg0, double arg1, std::string_view arg2, bool arg3, short arg4);
    void method12(std::string arg0, bool arg1, int arg2, int arg3, unsigned arg4);
    short method13(double arg0, short arg1, short arg2, std::string const& arg3, unsigned arg4);
    float method14(std::string arg0, bool arg1, float arg2, std::string_view arg3, std::string const& arg4);
};

namespace ns_Class59
{
    short method0(std::string arg0, std::string arg1, short arg2, std::string_view arg3, std::string arg4);
    float method1(float arg0, int arg1, double arg2, unsigned arg3, bool arg4);
    double method2(std::string_view arg0, float arg1, double arg2, bool arg3, double arg4);
    void method3(std::string_view arg0, short arg1, std::string arg2, int arg3, double arg4);
    double method4(unsigned arg0, float arg1, std::string arg2, std::string_view arg3, double arg4);
    void method5(short arg0, std::string arg1, float arg2, bool arg3, bool arg4);
    float method6(std::string arg0, std::string_view arg1, short arg2, bool arg3, float arg4);
    std::string const& method7(std::string const& arg0, bool arg1, bool arg2, std::string arg3, std::string_view arg4);
    void method8(double arg0, float arg1, std::string arg2, std::string arg3, std::string const& arg4);
    double method9(std::string arg0, std::string arg1, double arg2, bool arg3, short arg4);
    unsigned method10(std::string const& arg0, int arg1, unsigned arg2, float arg3, unsigned arg4);
    std::string_view method11(std::string_view arg0, double arg1, std::string_view arg2, bool arg3, short arg4);
    void method12(std::string arg0, bool arg1, int arg2, int arg3, unsigned arg4);
    short method13(double arg0, short arg1, short arg2, std::string const& arg3, unsigned arg4);
    float method14(std::string arg0, bool arg1, float arg2, std::string_view arg3, std::string const& arg4);
}
