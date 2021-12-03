#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class56
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string_view method0(float arg0, double arg1, std::string const& arg2, std::string_view arg3, float arg4);
    int method1(std::string_view arg0, int arg1, double arg2, short arg3, int arg4);
    std::string_view method2(std::string arg0, std::string_view arg1, double arg2, std::string_view arg3, std::string arg4);
    float method3(std::string_view arg0, float arg1, int arg2, std::string arg3, double arg4);
    void method4(unsigned arg0, short arg1, short arg2, float arg3, std::string_view arg4);
    void method5(double arg0, int arg1, double arg2, float arg3, std::string_view arg4);
    void method6(std::string_view arg0, short arg1, short arg2, std::string_view arg3, float arg4);
    void method7(int arg0, bool arg1, bool arg2, std::string_view arg3, std::string_view arg4);
    double method8(std::string_view arg0, double arg1, std::string arg2, double arg3, bool arg4);
    std::string_view method9(std::string_view arg0, std::string_view arg1, unsigned arg2, std::string_view arg3, unsigned arg4);
    void method10(std::string arg0, short arg1, short arg2, float arg3, std::string_view arg4);
    float method11(double arg0, float arg1, unsigned arg2, std::string_view arg3, std::string const& arg4);
    std::string const& method12(std::string const& arg0, std::string arg1, short arg2, bool arg3, float arg4);
    std::string const& method13(std::string arg0, std::string_view arg1, int arg2, unsigned arg3, std::string const& arg4);
    void method14(std::string arg0, double arg1, double arg2, unsigned arg3, float arg4);
};

namespace ns_Class56
{
    std::string_view method0(float arg0, double arg1, std::string const& arg2, std::string_view arg3, float arg4);
    int method1(std::string_view arg0, int arg1, double arg2, short arg3, int arg4);
    std::string_view method2(std::string arg0, std::string_view arg1, double arg2, std::string_view arg3, std::string arg4);
    float method3(std::string_view arg0, float arg1, int arg2, std::string arg3, double arg4);
    void method4(unsigned arg0, short arg1, short arg2, float arg3, std::string_view arg4);
    void method5(double arg0, int arg1, double arg2, float arg3, std::string_view arg4);
    void method6(std::string_view arg0, short arg1, short arg2, std::string_view arg3, float arg4);
    void method7(int arg0, bool arg1, bool arg2, std::string_view arg3, std::string_view arg4);
    double method8(std::string_view arg0, double arg1, std::string arg2, double arg3, bool arg4);
    std::string_view method9(std::string_view arg0, std::string_view arg1, unsigned arg2, std::string_view arg3, unsigned arg4);
    void method10(std::string arg0, short arg1, short arg2, float arg3, std::string_view arg4);
    float method11(double arg0, float arg1, unsigned arg2, std::string_view arg3, std::string const& arg4);
    std::string const& method12(std::string const& arg0, std::string arg1, short arg2, bool arg3, float arg4);
    std::string const& method13(std::string arg0, std::string_view arg1, int arg2, unsigned arg3, std::string const& arg4);
    void method14(std::string arg0, double arg1, double arg2, unsigned arg3, float arg4);
}
