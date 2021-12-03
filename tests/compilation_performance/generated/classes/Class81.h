#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class81
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(short arg0, float arg1, bool arg2, bool arg3, std::string arg4);
    void method1(std::string const& arg0, float arg1, std::string arg2, bool arg3, std::string const& arg4);
    bool method2(double arg0, unsigned arg1, unsigned arg2, std::string arg3, bool arg4);
    void method3(std::string_view arg0, float arg1, std::string const& arg2, std::string arg3, unsigned arg4);
    unsigned method4(unsigned arg0, std::string arg1, std::string arg2, unsigned arg3, unsigned arg4);
    std::string const& method5(double arg0, bool arg1, std::string const& arg2, unsigned arg3, std::string const& arg4);
    void method6(int arg0, std::string arg1, std::string const& arg2, std::string_view arg3, std::string const& arg4);
    void method7(std::string const& arg0, bool arg1, float arg2, double arg3, unsigned arg4);
    void method8(int arg0, std::string const& arg1, short arg2, short arg3, unsigned arg4);
    void method9(double arg0, int arg1, float arg2, int arg3, bool arg4);
    void method10(float arg0, double arg1, std::string const& arg2, bool arg3, int arg4);
    float method11(std::string const& arg0, float arg1, unsigned arg2, std::string arg3, float arg4);
    void method12(short arg0, bool arg1, std::string_view arg2, float arg3, bool arg4);
    void method13(int arg0, std::string const& arg1, short arg2, std::string_view arg3, bool arg4);
    double method14(std::string arg0, float arg1, std::string const& arg2, double arg3, float arg4);
};

namespace ns_Class81
{
    float method0(short arg0, float arg1, bool arg2, bool arg3, std::string arg4);
    void method1(std::string const& arg0, float arg1, std::string arg2, bool arg3, std::string const& arg4);
    bool method2(double arg0, unsigned arg1, unsigned arg2, std::string arg3, bool arg4);
    void method3(std::string_view arg0, float arg1, std::string const& arg2, std::string arg3, unsigned arg4);
    unsigned method4(unsigned arg0, std::string arg1, std::string arg2, unsigned arg3, unsigned arg4);
    std::string const& method5(double arg0, bool arg1, std::string const& arg2, unsigned arg3, std::string const& arg4);
    void method6(int arg0, std::string arg1, std::string const& arg2, std::string_view arg3, std::string const& arg4);
    void method7(std::string const& arg0, bool arg1, float arg2, double arg3, unsigned arg4);
    void method8(int arg0, std::string const& arg1, short arg2, short arg3, unsigned arg4);
    void method9(double arg0, int arg1, float arg2, int arg3, bool arg4);
    void method10(float arg0, double arg1, std::string const& arg2, bool arg3, int arg4);
    float method11(std::string const& arg0, float arg1, unsigned arg2, std::string arg3, float arg4);
    void method12(short arg0, bool arg1, std::string_view arg2, float arg3, bool arg4);
    void method13(int arg0, std::string const& arg1, short arg2, std::string_view arg3, bool arg4);
    double method14(std::string arg0, float arg1, std::string const& arg2, double arg3, float arg4);
}
