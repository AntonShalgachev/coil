#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class3
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(std::string arg0, double arg1, unsigned arg2, double arg3, short arg4);
    std::string method1(double arg0, std::string arg1, int arg2, int arg3, std::string const& arg4);
    void method2(bool arg0, std::string const& arg1, bool arg2, std::string const& arg3, double arg4);
    std::string_view method3(std::string arg0, std::string_view arg1, std::string_view arg2, unsigned arg3, unsigned arg4);
    unsigned method4(unsigned arg0, short arg1, double arg2, float arg3, short arg4);
    void method5(bool arg0, double arg1, bool arg2, unsigned arg3, std::string arg4);
    void method6(std::string_view arg0, short arg1, unsigned arg2, std::string const& arg3, std::string const& arg4);
    void method7(float arg0, std::string_view arg1, short arg2, short arg3, unsigned arg4);
    float method8(bool arg0, float arg1, float arg2, short arg3, std::string_view arg4);
    std::string const& method9(std::string const& arg0, double arg1, float arg2, short arg3, unsigned arg4);
    bool method10(unsigned arg0, std::string const& arg1, bool arg2, std::string_view arg3, float arg4);
    void method11(unsigned arg0, double arg1, float arg2, bool arg3, bool arg4);
    void method12(unsigned arg0, unsigned arg1, std::string const& arg2, std::string arg3, double arg4);
    int method13(std::string const& arg0, std::string_view arg1, float arg2, int arg3, float arg4);
    std::string method14(float arg0, bool arg1, std::string arg2, double arg3, int arg4);
};

namespace ns_Class3
{
    double method0(std::string arg0, double arg1, unsigned arg2, double arg3, short arg4);
    std::string method1(double arg0, std::string arg1, int arg2, int arg3, std::string const& arg4);
    void method2(bool arg0, std::string const& arg1, bool arg2, std::string const& arg3, double arg4);
    std::string_view method3(std::string arg0, std::string_view arg1, std::string_view arg2, unsigned arg3, unsigned arg4);
    unsigned method4(unsigned arg0, short arg1, double arg2, float arg3, short arg4);
    void method5(bool arg0, double arg1, bool arg2, unsigned arg3, std::string arg4);
    void method6(std::string_view arg0, short arg1, unsigned arg2, std::string const& arg3, std::string const& arg4);
    void method7(float arg0, std::string_view arg1, short arg2, short arg3, unsigned arg4);
    float method8(bool arg0, float arg1, float arg2, short arg3, std::string_view arg4);
    std::string const& method9(std::string const& arg0, double arg1, float arg2, short arg3, unsigned arg4);
    bool method10(unsigned arg0, std::string const& arg1, bool arg2, std::string_view arg3, float arg4);
    void method11(unsigned arg0, double arg1, float arg2, bool arg3, bool arg4);
    void method12(unsigned arg0, unsigned arg1, std::string const& arg2, std::string arg3, double arg4);
    int method13(std::string const& arg0, std::string_view arg1, float arg2, int arg3, float arg4);
    std::string method14(float arg0, bool arg1, std::string arg2, double arg3, int arg4);
}
