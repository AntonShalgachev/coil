#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class53
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, bool arg1, std::string arg2, std::string arg3, unsigned arg4);
    bool method1(bool arg0, double arg1, std::string const& arg2, int arg3, double arg4);
    short method2(short arg0, short arg1, std::string_view arg2, std::string arg3, double arg4);
    std::string method3(std::string_view arg0, short arg1, std::string arg2, std::string arg3, std::string const& arg4);
    void method4(short arg0, unsigned arg1, unsigned arg2, std::string const& arg3, float arg4);
    int method5(unsigned arg0, std::string const& arg1, int arg2, std::string const& arg3, std::string const& arg4);
    void method6(std::string_view arg0, double arg1, std::string const& arg2, float arg3, unsigned arg4);
    void method7(std::string arg0, int arg1, short arg2, bool arg3, float arg4);
    float method8(std::string const& arg0, unsigned arg1, short arg2, float arg3, unsigned arg4);
    void method9(bool arg0, float arg1, std::string arg2, short arg3, float arg4);
    std::string const& method10(int arg0, double arg1, bool arg2, int arg3, std::string const& arg4);
    void method11(int arg0, float arg1, int arg2, short arg3, float arg4);
    void method12(std::string_view arg0, std::string const& arg1, double arg2, unsigned arg3, bool arg4);
    void method13(std::string const& arg0, short arg1, short arg2, double arg3, int arg4);
    unsigned method14(int arg0, int arg1, unsigned arg2, std::string arg3, int arg4);
};

namespace ns_Class53
{
    void method0(short arg0, bool arg1, std::string arg2, std::string arg3, unsigned arg4);
    bool method1(bool arg0, double arg1, std::string const& arg2, int arg3, double arg4);
    short method2(short arg0, short arg1, std::string_view arg2, std::string arg3, double arg4);
    std::string method3(std::string_view arg0, short arg1, std::string arg2, std::string arg3, std::string const& arg4);
    void method4(short arg0, unsigned arg1, unsigned arg2, std::string const& arg3, float arg4);
    int method5(unsigned arg0, std::string const& arg1, int arg2, std::string const& arg3, std::string const& arg4);
    void method6(std::string_view arg0, double arg1, std::string const& arg2, float arg3, unsigned arg4);
    void method7(std::string arg0, int arg1, short arg2, bool arg3, float arg4);
    float method8(std::string const& arg0, unsigned arg1, short arg2, float arg3, unsigned arg4);
    void method9(bool arg0, float arg1, std::string arg2, short arg3, float arg4);
    std::string const& method10(int arg0, double arg1, bool arg2, int arg3, std::string const& arg4);
    void method11(int arg0, float arg1, int arg2, short arg3, float arg4);
    void method12(std::string_view arg0, std::string const& arg1, double arg2, unsigned arg3, bool arg4);
    void method13(std::string const& arg0, short arg1, short arg2, double arg3, int arg4);
    unsigned method14(int arg0, int arg1, unsigned arg2, std::string arg3, int arg4);
}
