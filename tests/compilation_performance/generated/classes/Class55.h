#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class55
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(std::string_view arg0, unsigned arg1, bool arg2, std::string_view arg3, bool arg4);
    void method1(std::string const& arg0, int arg1, std::string_view arg2, std::string const& arg3, unsigned arg4);
    std::string_view method2(float arg0, std::string_view arg1, double arg2, double arg3, std::string_view arg4);
    std::string const& method3(std::string const& arg0, int arg1, int arg2, short arg3, bool arg4);
    void method4(int arg0, std::string arg1, std::string const& arg2, short arg3, short arg4);
    std::string_view method5(std::string_view arg0, unsigned arg1, float arg2, int arg3, std::string const& arg4);
    void method6(bool arg0, std::string const& arg1, bool arg2, short arg3, std::string_view arg4);
    void method7(std::string const& arg0, bool arg1, std::string_view arg2, float arg3, int arg4);
    void method8(float arg0, float arg1, unsigned arg2, int arg3, double arg4);
    float method9(std::string arg0, std::string_view arg1, bool arg2, float arg3, std::string const& arg4);
    void method10(double arg0, float arg1, float arg2, float arg3, bool arg4);
    bool method11(int arg0, bool arg1, unsigned arg2, float arg3, short arg4);
    std::string const& method12(double arg0, int arg1, std::string const& arg2, bool arg3, int arg4);
    short method13(bool arg0, std::string const& arg1, std::string const& arg2, short arg3, short arg4);
    int method14(float arg0, float arg1, std::string arg2, bool arg3, int arg4);
};

namespace ns_Class55
{
    void method0(std::string_view arg0, unsigned arg1, bool arg2, std::string_view arg3, bool arg4);
    void method1(std::string const& arg0, int arg1, std::string_view arg2, std::string const& arg3, unsigned arg4);
    std::string_view method2(float arg0, std::string_view arg1, double arg2, double arg3, std::string_view arg4);
    std::string const& method3(std::string const& arg0, int arg1, int arg2, short arg3, bool arg4);
    void method4(int arg0, std::string arg1, std::string const& arg2, short arg3, short arg4);
    std::string_view method5(std::string_view arg0, unsigned arg1, float arg2, int arg3, std::string const& arg4);
    void method6(bool arg0, std::string const& arg1, bool arg2, short arg3, std::string_view arg4);
    void method7(std::string const& arg0, bool arg1, std::string_view arg2, float arg3, int arg4);
    void method8(float arg0, float arg1, unsigned arg2, int arg3, double arg4);
    float method9(std::string arg0, std::string_view arg1, bool arg2, float arg3, std::string const& arg4);
    void method10(double arg0, float arg1, float arg2, float arg3, bool arg4);
    bool method11(int arg0, bool arg1, unsigned arg2, float arg3, short arg4);
    std::string const& method12(double arg0, int arg1, std::string const& arg2, bool arg3, int arg4);
    short method13(bool arg0, std::string const& arg1, std::string const& arg2, short arg3, short arg4);
    int method14(float arg0, float arg1, std::string arg2, bool arg3, int arg4);
}
