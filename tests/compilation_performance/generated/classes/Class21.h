#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class21
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string_view method0(std::string const& arg0, bool arg1, double arg2, std::string_view arg3, bool arg4);
    std::string const& method1(float arg0, unsigned arg1, std::string arg2, std::string const& arg3, unsigned arg4);
    std::string method2(std::string arg0, std::string const& arg1, bool arg2, int arg3, unsigned arg4);
    std::string method3(std::string arg0, unsigned arg1, double arg2, std::string const& arg3, int arg4);
    void method4(short arg0, short arg1, short arg2, int arg3, bool arg4);
    void method5(std::string const& arg0, double arg1, bool arg2, bool arg3, bool arg4);
    std::string const& method6(std::string arg0, short arg1, std::string const& arg2, std::string const& arg3, bool arg4);
    void method7(std::string_view arg0, std::string arg1, double arg2, float arg3, int arg4);
    void method8(float arg0, int arg1, double arg2, double arg3, std::string arg4);
    bool method9(std::string arg0, double arg1, bool arg2, std::string arg3, double arg4);
    void method10(std::string const& arg0, float arg1, std::string arg2, float arg3, std::string const& arg4);
    float method11(unsigned arg0, short arg1, float arg2, unsigned arg3, unsigned arg4);
    void method12(short arg0, bool arg1, int arg2, int arg3, unsigned arg4);
    void method13(std::string const& arg0, double arg1, float arg2, float arg3, unsigned arg4);
    void method14(bool arg0, std::string const& arg1, bool arg2, int arg3, std::string const& arg4);
};

namespace ns_Class21
{
    std::string_view method0(std::string const& arg0, bool arg1, double arg2, std::string_view arg3, bool arg4);
    std::string const& method1(float arg0, unsigned arg1, std::string arg2, std::string const& arg3, unsigned arg4);
    std::string method2(std::string arg0, std::string const& arg1, bool arg2, int arg3, unsigned arg4);
    std::string method3(std::string arg0, unsigned arg1, double arg2, std::string const& arg3, int arg4);
    void method4(short arg0, short arg1, short arg2, int arg3, bool arg4);
    void method5(std::string const& arg0, double arg1, bool arg2, bool arg3, bool arg4);
    std::string const& method6(std::string arg0, short arg1, std::string const& arg2, std::string const& arg3, bool arg4);
    void method7(std::string_view arg0, std::string arg1, double arg2, float arg3, int arg4);
    void method8(float arg0, int arg1, double arg2, double arg3, std::string arg4);
    bool method9(std::string arg0, double arg1, bool arg2, std::string arg3, double arg4);
    void method10(std::string const& arg0, float arg1, std::string arg2, float arg3, std::string const& arg4);
    float method11(unsigned arg0, short arg1, float arg2, unsigned arg3, unsigned arg4);
    void method12(short arg0, bool arg1, int arg2, int arg3, unsigned arg4);
    void method13(std::string const& arg0, double arg1, float arg2, float arg3, unsigned arg4);
    void method14(bool arg0, std::string const& arg1, bool arg2, int arg3, std::string const& arg4);
}
