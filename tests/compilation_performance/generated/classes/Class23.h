#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class23
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(std::string const& arg0, bool arg1, std::string_view arg2, unsigned arg3, bool arg4);
    double method1(double arg0, std::string_view arg1, unsigned arg2, double arg3, double arg4);
    std::string const& method2(unsigned arg0, double arg1, double arg2, int arg3, std::string const& arg4);
    std::string const& method3(std::string const& arg0, std::string_view arg1, short arg2, std::string arg3, std::string const& arg4);
    void method4(float arg0, float arg1, float arg2, std::string const& arg3, bool arg4);
    void method5(std::string const& arg0, std::string const& arg1, int arg2, std::string const& arg3, std::string_view arg4);
    void method6(std::string_view arg0, short arg1, std::string const& arg2, bool arg3, bool arg4);
    void method7(double arg0, unsigned arg1, std::string arg2, bool arg3, bool arg4);
    void method8(std::string arg0, std::string_view arg1, short arg2, bool arg3, std::string_view arg4);
    short method9(std::string arg0, std::string const& arg1, double arg2, bool arg3, short arg4);
    unsigned method10(double arg0, double arg1, unsigned arg2, std::string arg3, int arg4);
    bool method11(bool arg0, unsigned arg1, int arg2, unsigned arg3, unsigned arg4);
    void method12(bool arg0, unsigned arg1, bool arg2, unsigned arg3, short arg4);
    float method13(bool arg0, float arg1, bool arg2, bool arg3, std::string const& arg4);
    double method14(bool arg0, std::string const& arg1, short arg2, double arg3, int arg4);
};

namespace ns_Class23
{
    unsigned method0(std::string const& arg0, bool arg1, std::string_view arg2, unsigned arg3, bool arg4);
    double method1(double arg0, std::string_view arg1, unsigned arg2, double arg3, double arg4);
    std::string const& method2(unsigned arg0, double arg1, double arg2, int arg3, std::string const& arg4);
    std::string const& method3(std::string const& arg0, std::string_view arg1, short arg2, std::string arg3, std::string const& arg4);
    void method4(float arg0, float arg1, float arg2, std::string const& arg3, bool arg4);
    void method5(std::string const& arg0, std::string const& arg1, int arg2, std::string const& arg3, std::string_view arg4);
    void method6(std::string_view arg0, short arg1, std::string const& arg2, bool arg3, bool arg4);
    void method7(double arg0, unsigned arg1, std::string arg2, bool arg3, bool arg4);
    void method8(std::string arg0, std::string_view arg1, short arg2, bool arg3, std::string_view arg4);
    short method9(std::string arg0, std::string const& arg1, double arg2, bool arg3, short arg4);
    unsigned method10(double arg0, double arg1, unsigned arg2, std::string arg3, int arg4);
    bool method11(bool arg0, unsigned arg1, int arg2, unsigned arg3, unsigned arg4);
    void method12(bool arg0, unsigned arg1, bool arg2, unsigned arg3, short arg4);
    float method13(bool arg0, float arg1, bool arg2, bool arg3, std::string const& arg4);
    double method14(bool arg0, std::string const& arg1, short arg2, double arg3, int arg4);
}
