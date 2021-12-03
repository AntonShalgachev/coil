#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class86
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, unsigned arg1, std::string arg2, std::string_view arg3, std::string arg4);
    void method1(double arg0, double arg1, short arg2, float arg3, double arg4);
    double method2(double arg0, std::string const& arg1, int arg2, float arg3, float arg4);
    void method3(std::string arg0, short arg1, float arg2, short arg3, std::string const& arg4);
    unsigned method4(std::string arg0, unsigned arg1, float arg2, float arg3, unsigned arg4);
    bool method5(bool arg0, bool arg1, float arg2, std::string arg3, std::string arg4);
    std::string method6(bool arg0, std::string arg1, bool arg2, bool arg3, double arg4);
    int method7(std::string_view arg0, bool arg1, int arg2, std::string arg3, float arg4);
    void method8(bool arg0, std::string arg1, std::string const& arg2, double arg3, double arg4);
    void method9(unsigned arg0, double arg1, unsigned arg2, double arg3, float arg4);
    double method10(bool arg0, short arg1, double arg2, unsigned arg3, std::string const& arg4);
    float method11(double arg0, float arg1, double arg2, bool arg3, std::string_view arg4);
    bool method12(int arg0, bool arg1, std::string const& arg2, bool arg3, unsigned arg4);
    void method13(std::string_view arg0, double arg1, std::string arg2, std::string_view arg3, float arg4);
    void method14(std::string arg0, unsigned arg1, std::string const& arg2, std::string_view arg3, std::string const& arg4);
};

namespace ns_Class86
{
    unsigned method0(unsigned arg0, unsigned arg1, std::string arg2, std::string_view arg3, std::string arg4);
    void method1(double arg0, double arg1, short arg2, float arg3, double arg4);
    double method2(double arg0, std::string const& arg1, int arg2, float arg3, float arg4);
    void method3(std::string arg0, short arg1, float arg2, short arg3, std::string const& arg4);
    unsigned method4(std::string arg0, unsigned arg1, float arg2, float arg3, unsigned arg4);
    bool method5(bool arg0, bool arg1, float arg2, std::string arg3, std::string arg4);
    std::string method6(bool arg0, std::string arg1, bool arg2, bool arg3, double arg4);
    int method7(std::string_view arg0, bool arg1, int arg2, std::string arg3, float arg4);
    void method8(bool arg0, std::string arg1, std::string const& arg2, double arg3, double arg4);
    void method9(unsigned arg0, double arg1, unsigned arg2, double arg3, float arg4);
    double method10(bool arg0, short arg1, double arg2, unsigned arg3, std::string const& arg4);
    float method11(double arg0, float arg1, double arg2, bool arg3, std::string_view arg4);
    bool method12(int arg0, bool arg1, std::string const& arg2, bool arg3, unsigned arg4);
    void method13(std::string_view arg0, double arg1, std::string arg2, std::string_view arg3, float arg4);
    void method14(std::string arg0, unsigned arg1, std::string const& arg2, std::string_view arg3, std::string const& arg4);
}
