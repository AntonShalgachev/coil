#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class76
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(float arg0, int arg1, float arg2, std::string arg3, std::string arg4);
    void method1(bool arg0, float arg1, std::string_view arg2, std::string arg3, std::string arg4);
    void method2(std::string arg0, short arg1, int arg2, short arg3, std::string arg4);
    void method3(int arg0, std::string_view arg1, std::string_view arg2, float arg3, unsigned arg4);
    float method4(std::string arg0, bool arg1, float arg2, std::string const& arg3, float arg4);
    void method5(std::string const& arg0, std::string arg1, unsigned arg2, unsigned arg3, std::string const& arg4);
    void method6(int arg0, short arg1, double arg2, std::string_view arg3, std::string arg4);
    short method7(short arg0, int arg1, std::string_view arg2, std::string const& arg3, bool arg4);
    void method8(std::string const& arg0, unsigned arg1, std::string arg2, double arg3, int arg4);
    std::string const& method9(std::string arg0, std::string_view arg1, unsigned arg2, std::string const& arg3, std::string const& arg4);
    bool method10(std::string const& arg0, std::string const& arg1, bool arg2, std::string arg3, short arg4);
    short method11(std::string_view arg0, std::string_view arg1, double arg2, short arg3, double arg4);
    void method12(float arg0, std::string const& arg1, std::string arg2, bool arg3, unsigned arg4);
    void method13(bool arg0, std::string arg1, std::string arg2, double arg3, std::string_view arg4);
    void method14(short arg0, unsigned arg1, bool arg2, std::string arg3, std::string const& arg4);
};

namespace ns_Class76
{
    void method0(float arg0, int arg1, float arg2, std::string arg3, std::string arg4);
    void method1(bool arg0, float arg1, std::string_view arg2, std::string arg3, std::string arg4);
    void method2(std::string arg0, short arg1, int arg2, short arg3, std::string arg4);
    void method3(int arg0, std::string_view arg1, std::string_view arg2, float arg3, unsigned arg4);
    float method4(std::string arg0, bool arg1, float arg2, std::string const& arg3, float arg4);
    void method5(std::string const& arg0, std::string arg1, unsigned arg2, unsigned arg3, std::string const& arg4);
    void method6(int arg0, short arg1, double arg2, std::string_view arg3, std::string arg4);
    short method7(short arg0, int arg1, std::string_view arg2, std::string const& arg3, bool arg4);
    void method8(std::string const& arg0, unsigned arg1, std::string arg2, double arg3, int arg4);
    std::string const& method9(std::string arg0, std::string_view arg1, unsigned arg2, std::string const& arg3, std::string const& arg4);
    bool method10(std::string const& arg0, std::string const& arg1, bool arg2, std::string arg3, short arg4);
    short method11(std::string_view arg0, std::string_view arg1, double arg2, short arg3, double arg4);
    void method12(float arg0, std::string const& arg1, std::string arg2, bool arg3, unsigned arg4);
    void method13(bool arg0, std::string arg1, std::string arg2, double arg3, std::string_view arg4);
    void method14(short arg0, unsigned arg1, bool arg2, std::string arg3, std::string const& arg4);
}
