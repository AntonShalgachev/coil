#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class85
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(bool arg0, float arg1, int arg2, double arg3, bool arg4);
    void method1(float arg0, short arg1, std::string_view arg2, std::string_view arg3, float arg4);
    std::string_view method2(std::string arg0, double arg1, unsigned arg2, std::string_view arg3, std::string_view arg4);
    int method3(std::string const& arg0, int arg1, double arg2, bool arg3, float arg4);
    void method4(unsigned arg0, std::string const& arg1, int arg2, std::string_view arg3, unsigned arg4);
    int method5(bool arg0, int arg1, short arg2, int arg3, int arg4);
    void method6(bool arg0, bool arg1, int arg2, std::string const& arg3, int arg4);
    short method7(short arg0, float arg1, short arg2, double arg3, double arg4);
    short method8(short arg0, std::string_view arg1, bool arg2, std::string_view arg3, std::string arg4);
    unsigned method9(unsigned arg0, unsigned arg1, unsigned arg2, std::string arg3, std::string_view arg4);
    double method10(std::string_view arg0, bool arg1, std::string arg2, double arg3, std::string_view arg4);
    void method11(double arg0, std::string_view arg1, int arg2, unsigned arg3, std::string_view arg4);
    void method12(float arg0, std::string_view arg1, bool arg2, double arg3, std::string_view arg4);
    short method13(std::string_view arg0, short arg1, int arg2, short arg3, int arg4);
    void method14(unsigned arg0, short arg1, std::string arg2, short arg3, int arg4);
};

namespace ns_Class85
{
    double method0(bool arg0, float arg1, int arg2, double arg3, bool arg4);
    void method1(float arg0, short arg1, std::string_view arg2, std::string_view arg3, float arg4);
    std::string_view method2(std::string arg0, double arg1, unsigned arg2, std::string_view arg3, std::string_view arg4);
    int method3(std::string const& arg0, int arg1, double arg2, bool arg3, float arg4);
    void method4(unsigned arg0, std::string const& arg1, int arg2, std::string_view arg3, unsigned arg4);
    int method5(bool arg0, int arg1, short arg2, int arg3, int arg4);
    void method6(bool arg0, bool arg1, int arg2, std::string const& arg3, int arg4);
    short method7(short arg0, float arg1, short arg2, double arg3, double arg4);
    short method8(short arg0, std::string_view arg1, bool arg2, std::string_view arg3, std::string arg4);
    unsigned method9(unsigned arg0, unsigned arg1, unsigned arg2, std::string arg3, std::string_view arg4);
    double method10(std::string_view arg0, bool arg1, std::string arg2, double arg3, std::string_view arg4);
    void method11(double arg0, std::string_view arg1, int arg2, unsigned arg3, std::string_view arg4);
    void method12(float arg0, std::string_view arg1, bool arg2, double arg3, std::string_view arg4);
    short method13(std::string_view arg0, short arg1, int arg2, short arg3, int arg4);
    void method14(unsigned arg0, short arg1, std::string arg2, short arg3, int arg4);
}
