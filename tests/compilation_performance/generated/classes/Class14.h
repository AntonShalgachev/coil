#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class14
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(unsigned arg0, float arg1, std::string_view arg2, int arg3, std::string arg4);
    std::string_view method1(double arg0, float arg1, bool arg2, double arg3, std::string_view arg4);
    double method2(double arg0, std::string arg1, std::string_view arg2, std::string arg3, std::string arg4);
    void method3(int arg0, int arg1, float arg2, std::string_view arg3, std::string arg4);
    std::string const& method4(std::string const& arg0, double arg1, unsigned arg2, std::string const& arg3, short arg4);
    void method5(short arg0, int arg1, short arg2, unsigned arg3, int arg4);
    void method6(bool arg0, double arg1, std::string_view arg2, float arg3, short arg4);
    short method7(short arg0, bool arg1, std::string_view arg2, short arg3, std::string arg4);
    double method8(float arg0, short arg1, double arg2, short arg3, int arg4);
    double method9(bool arg0, double arg1, std::string_view arg2, float arg3, unsigned arg4);
    void method10(short arg0, std::string arg1, std::string const& arg2, std::string_view arg3, std::string arg4);
    void method11(std::string arg0, std::string_view arg1, bool arg2, float arg3, std::string arg4);
    unsigned method12(unsigned arg0, unsigned arg1, int arg2, int arg3, float arg4);
    void method13(short arg0, double arg1, bool arg2, bool arg3, std::string_view arg4);
    double method14(std::string arg0, double arg1, double arg2, int arg3, unsigned arg4);
};

namespace ns_Class14
{
    int method0(unsigned arg0, float arg1, std::string_view arg2, int arg3, std::string arg4);
    std::string_view method1(double arg0, float arg1, bool arg2, double arg3, std::string_view arg4);
    double method2(double arg0, std::string arg1, std::string_view arg2, std::string arg3, std::string arg4);
    void method3(int arg0, int arg1, float arg2, std::string_view arg3, std::string arg4);
    std::string const& method4(std::string const& arg0, double arg1, unsigned arg2, std::string const& arg3, short arg4);
    void method5(short arg0, int arg1, short arg2, unsigned arg3, int arg4);
    void method6(bool arg0, double arg1, std::string_view arg2, float arg3, short arg4);
    short method7(short arg0, bool arg1, std::string_view arg2, short arg3, std::string arg4);
    double method8(float arg0, short arg1, double arg2, short arg3, int arg4);
    double method9(bool arg0, double arg1, std::string_view arg2, float arg3, unsigned arg4);
    void method10(short arg0, std::string arg1, std::string const& arg2, std::string_view arg3, std::string arg4);
    void method11(std::string arg0, std::string_view arg1, bool arg2, float arg3, std::string arg4);
    unsigned method12(unsigned arg0, unsigned arg1, int arg2, int arg3, float arg4);
    void method13(short arg0, double arg1, bool arg2, bool arg3, std::string_view arg4);
    double method14(std::string arg0, double arg1, double arg2, int arg3, unsigned arg4);
}
