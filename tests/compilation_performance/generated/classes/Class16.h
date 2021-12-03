#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class16
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(short arg0, bool arg1, std::string arg2, bool arg3, bool arg4);
    std::string const& method1(std::string_view arg0, std::string const& arg1, double arg2, std::string const& arg3, std::string_view arg4);
    void method2(short arg0, std::string const& arg1, float arg2, int arg3, short arg4);
    void method3(std::string_view arg0, std::string const& arg1, std::string const& arg2, float arg3, int arg4);
    int method4(int arg0, std::string_view arg1, std::string arg2, std::string arg3, int arg4);
    int method5(std::string_view arg0, int arg1, std::string const& arg2, std::string arg3, float arg4);
    void method6(unsigned arg0, int arg1, std::string arg2, std::string arg3, float arg4);
    short method7(double arg0, std::string_view arg1, bool arg2, short arg3, double arg4);
    void method8(std::string const& arg0, short arg1, float arg2, std::string_view arg3, double arg4);
    void method9(double arg0, bool arg1, std::string const& arg2, std::string const& arg3, unsigned arg4);
    void method10(double arg0, unsigned arg1, std::string const& arg2, std::string arg3, bool arg4);
    std::string method11(unsigned arg0, bool arg1, int arg2, int arg3, std::string arg4);
    short method12(unsigned arg0, short arg1, int arg2, int arg3, std::string arg4);
    bool method13(float arg0, float arg1, std::string const& arg2, std::string arg3, bool arg4);
    bool method14(unsigned arg0, std::string arg1, int arg2, bool arg3, float arg4);
};

namespace ns_Class16
{
    bool method0(short arg0, bool arg1, std::string arg2, bool arg3, bool arg4);
    std::string const& method1(std::string_view arg0, std::string const& arg1, double arg2, std::string const& arg3, std::string_view arg4);
    void method2(short arg0, std::string const& arg1, float arg2, int arg3, short arg4);
    void method3(std::string_view arg0, std::string const& arg1, std::string const& arg2, float arg3, int arg4);
    int method4(int arg0, std::string_view arg1, std::string arg2, std::string arg3, int arg4);
    int method5(std::string_view arg0, int arg1, std::string const& arg2, std::string arg3, float arg4);
    void method6(unsigned arg0, int arg1, std::string arg2, std::string arg3, float arg4);
    short method7(double arg0, std::string_view arg1, bool arg2, short arg3, double arg4);
    void method8(std::string const& arg0, short arg1, float arg2, std::string_view arg3, double arg4);
    void method9(double arg0, bool arg1, std::string const& arg2, std::string const& arg3, unsigned arg4);
    void method10(double arg0, unsigned arg1, std::string const& arg2, std::string arg3, bool arg4);
    std::string method11(unsigned arg0, bool arg1, int arg2, int arg3, std::string arg4);
    short method12(unsigned arg0, short arg1, int arg2, int arg3, std::string arg4);
    bool method13(float arg0, float arg1, std::string const& arg2, std::string arg3, bool arg4);
    bool method14(unsigned arg0, std::string arg1, int arg2, bool arg3, float arg4);
}
