#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class62
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(std::string const& arg0, int arg1, std::string const& arg2, unsigned arg3, bool arg4);
    float method1(int arg0, double arg1, unsigned arg2, double arg3, float arg4);
    void method2(float arg0, short arg1, unsigned arg2, float arg3, unsigned arg4);
    short method3(short arg0, double arg1, double arg2, int arg3, bool arg4);
    void method4(std::string arg0, unsigned arg1, bool arg2, double arg3, std::string arg4);
    void method5(bool arg0, short arg1, double arg2, std::string const& arg3, unsigned arg4);
    float method6(short arg0, float arg1, double arg2, unsigned arg3, float arg4);
    void method7(float arg0, bool arg1, std::string_view arg2, float arg3, std::string const& arg4);
    short method8(std::string_view arg0, std::string arg1, float arg2, short arg3, std::string_view arg4);
    bool method9(std::string_view arg0, short arg1, std::string arg2, bool arg3, std::string arg4);
    void method10(short arg0, std::string const& arg1, std::string arg2, std::string const& arg3, short arg4);
    void method11(std::string const& arg0, short arg1, bool arg2, std::string_view arg3, float arg4);
    std::string const& method12(std::string_view arg0, float arg1, std::string const& arg2, float arg3, short arg4);
    void method13(std::string_view arg0, double arg1, std::string const& arg2, std::string const& arg3, float arg4);
    int method14(float arg0, unsigned arg1, int arg2, std::string_view arg3, int arg4);
};

namespace ns_Class62
{
    bool method0(std::string const& arg0, int arg1, std::string const& arg2, unsigned arg3, bool arg4);
    float method1(int arg0, double arg1, unsigned arg2, double arg3, float arg4);
    void method2(float arg0, short arg1, unsigned arg2, float arg3, unsigned arg4);
    short method3(short arg0, double arg1, double arg2, int arg3, bool arg4);
    void method4(std::string arg0, unsigned arg1, bool arg2, double arg3, std::string arg4);
    void method5(bool arg0, short arg1, double arg2, std::string const& arg3, unsigned arg4);
    float method6(short arg0, float arg1, double arg2, unsigned arg3, float arg4);
    void method7(float arg0, bool arg1, std::string_view arg2, float arg3, std::string const& arg4);
    short method8(std::string_view arg0, std::string arg1, float arg2, short arg3, std::string_view arg4);
    bool method9(std::string_view arg0, short arg1, std::string arg2, bool arg3, std::string arg4);
    void method10(short arg0, std::string const& arg1, std::string arg2, std::string const& arg3, short arg4);
    void method11(std::string const& arg0, short arg1, bool arg2, std::string_view arg3, float arg4);
    std::string const& method12(std::string_view arg0, float arg1, std::string const& arg2, float arg3, short arg4);
    void method13(std::string_view arg0, double arg1, std::string const& arg2, std::string const& arg3, float arg4);
    int method14(float arg0, unsigned arg1, int arg2, std::string_view arg3, int arg4);
}
