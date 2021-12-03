#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class90
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string method0(unsigned arg0, short arg1, short arg2, std::string arg3, short arg4);
    void method1(short arg0, double arg1, bool arg2, short arg3, unsigned arg4);
    void method2(std::string_view arg0, short arg1, std::string arg2, short arg3, short arg4);
    void method3(std::string const& arg0, std::string_view arg1, float arg2, int arg3, short arg4);
    std::string const& method4(std::string const& arg0, std::string const& arg1, short arg2, std::string arg3, unsigned arg4);
    void method5(std::string const& arg0, unsigned arg1, unsigned arg2, float arg3, std::string arg4);
    void method6(std::string_view arg0, short arg1, short arg2, std::string arg3, double arg4);
    void method7(double arg0, std::string arg1, bool arg2, double arg3, int arg4);
    bool method8(std::string arg0, std::string arg1, bool arg2, bool arg3, std::string arg4);
    bool method9(bool arg0, std::string const& arg1, float arg2, short arg3, bool arg4);
    void method10(short arg0, float arg1, double arg2, bool arg3, std::string const& arg4);
    short method11(bool arg0, short arg1, short arg2, bool arg3, int arg4);
    void method12(std::string const& arg0, double arg1, std::string const& arg2, double arg3, short arg4);
    double method13(double arg0, bool arg1, unsigned arg2, bool arg3, bool arg4);
    void method14(float arg0, std::string const& arg1, std::string_view arg2, std::string arg3, bool arg4);
};

namespace ns_Class90
{
    std::string method0(unsigned arg0, short arg1, short arg2, std::string arg3, short arg4);
    void method1(short arg0, double arg1, bool arg2, short arg3, unsigned arg4);
    void method2(std::string_view arg0, short arg1, std::string arg2, short arg3, short arg4);
    void method3(std::string const& arg0, std::string_view arg1, float arg2, int arg3, short arg4);
    std::string const& method4(std::string const& arg0, std::string const& arg1, short arg2, std::string arg3, unsigned arg4);
    void method5(std::string const& arg0, unsigned arg1, unsigned arg2, float arg3, std::string arg4);
    void method6(std::string_view arg0, short arg1, short arg2, std::string arg3, double arg4);
    void method7(double arg0, std::string arg1, bool arg2, double arg3, int arg4);
    bool method8(std::string arg0, std::string arg1, bool arg2, bool arg3, std::string arg4);
    bool method9(bool arg0, std::string const& arg1, float arg2, short arg3, bool arg4);
    void method10(short arg0, float arg1, double arg2, bool arg3, std::string const& arg4);
    short method11(bool arg0, short arg1, short arg2, bool arg3, int arg4);
    void method12(std::string const& arg0, double arg1, std::string const& arg2, double arg3, short arg4);
    double method13(double arg0, bool arg1, unsigned arg2, bool arg3, bool arg4);
    void method14(float arg0, std::string const& arg1, std::string_view arg2, std::string arg3, bool arg4);
}
