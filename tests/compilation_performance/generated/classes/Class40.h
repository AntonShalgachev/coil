#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class40
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, unsigned arg1, float arg2, float arg3, std::string arg4);
    void method1(bool arg0, unsigned arg1, float arg2, double arg3, int arg4);
    bool method2(bool arg0, double arg1, bool arg2, bool arg3, double arg4);
    double method3(double arg0, std::string const& arg1, std::string arg2, double arg3, int arg4);
    std::string method4(float arg0, std::string_view arg1, bool arg2, unsigned arg3, std::string arg4);
    float method5(double arg0, std::string arg1, bool arg2, float arg3, double arg4);
    void method6(double arg0, short arg1, float arg2, std::string arg3, short arg4);
    std::string const& method7(std::string const& arg0, std::string arg1, short arg2, std::string const& arg3, std::string arg4);
    void method8(int arg0, short arg1, std::string arg2, std::string const& arg3, short arg4);
    void method9(std::string_view arg0, int arg1, std::string_view arg2, double arg3, int arg4);
    void method10(std::string arg0, std::string arg1, std::string const& arg2, short arg3, float arg4);
    void method11(float arg0, bool arg1, unsigned arg2, std::string arg3, std::string const& arg4);
    void method12(int arg0, bool arg1, unsigned arg2, short arg3, std::string_view arg4);
    std::string const& method13(unsigned arg0, bool arg1, std::string arg2, std::string const& arg3, std::string arg4);
    void method14(std::string_view arg0, std::string const& arg1, unsigned arg2, float arg3, std::string const& arg4);
};

namespace ns_Class40
{
    void method0(float arg0, unsigned arg1, float arg2, float arg3, std::string arg4);
    void method1(bool arg0, unsigned arg1, float arg2, double arg3, int arg4);
    bool method2(bool arg0, double arg1, bool arg2, bool arg3, double arg4);
    double method3(double arg0, std::string const& arg1, std::string arg2, double arg3, int arg4);
    std::string method4(float arg0, std::string_view arg1, bool arg2, unsigned arg3, std::string arg4);
    float method5(double arg0, std::string arg1, bool arg2, float arg3, double arg4);
    void method6(double arg0, short arg1, float arg2, std::string arg3, short arg4);
    std::string const& method7(std::string const& arg0, std::string arg1, short arg2, std::string const& arg3, std::string arg4);
    void method8(int arg0, short arg1, std::string arg2, std::string const& arg3, short arg4);
    void method9(std::string_view arg0, int arg1, std::string_view arg2, double arg3, int arg4);
    void method10(std::string arg0, std::string arg1, std::string const& arg2, short arg3, float arg4);
    void method11(float arg0, bool arg1, unsigned arg2, std::string arg3, std::string const& arg4);
    void method12(int arg0, bool arg1, unsigned arg2, short arg3, std::string_view arg4);
    std::string const& method13(unsigned arg0, bool arg1, std::string arg2, std::string const& arg3, std::string arg4);
    void method14(std::string_view arg0, std::string const& arg1, unsigned arg2, float arg3, std::string const& arg4);
}
