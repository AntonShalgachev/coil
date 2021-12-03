#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class61
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(std::string_view arg0, unsigned arg1, float arg2, int arg3, std::string const& arg4);
    void method1(int arg0, std::string const& arg1, bool arg2, int arg3, bool arg4);
    void method2(std::string const& arg0, bool arg1, unsigned arg2, float arg3, unsigned arg4);
    void method3(std::string_view arg0, int arg1, std::string_view arg2, double arg3, std::string_view arg4);
    void method4(short arg0, double arg1, std::string_view arg2, bool arg3, double arg4);
    void method5(std::string_view arg0, float arg1, float arg2, std::string_view arg3, std::string arg4);
    unsigned method6(int arg0, unsigned arg1, int arg2, std::string arg3, unsigned arg4);
    bool method7(bool arg0, bool arg1, std::string const& arg2, double arg3, std::string_view arg4);
    bool method8(float arg0, bool arg1, bool arg2, std::string const& arg3, std::string_view arg4);
    bool method9(int arg0, std::string_view arg1, bool arg2, bool arg3, bool arg4);
    void method10(unsigned arg0, bool arg1, std::string_view arg2, bool arg3, float arg4);
    void method11(bool arg0, std::string_view arg1, bool arg2, short arg3, double arg4);
    void method12(std::string arg0, bool arg1, std::string_view arg2, unsigned arg3, std::string const& arg4);
    void method13(bool arg0, std::string_view arg1, std::string arg2, std::string const& arg3, unsigned arg4);
    std::string method14(int arg0, double arg1, bool arg2, std::string arg3, float arg4);
};

namespace ns_Class61
{
    int method0(std::string_view arg0, unsigned arg1, float arg2, int arg3, std::string const& arg4);
    void method1(int arg0, std::string const& arg1, bool arg2, int arg3, bool arg4);
    void method2(std::string const& arg0, bool arg1, unsigned arg2, float arg3, unsigned arg4);
    void method3(std::string_view arg0, int arg1, std::string_view arg2, double arg3, std::string_view arg4);
    void method4(short arg0, double arg1, std::string_view arg2, bool arg3, double arg4);
    void method5(std::string_view arg0, float arg1, float arg2, std::string_view arg3, std::string arg4);
    unsigned method6(int arg0, unsigned arg1, int arg2, std::string arg3, unsigned arg4);
    bool method7(bool arg0, bool arg1, std::string const& arg2, double arg3, std::string_view arg4);
    bool method8(float arg0, bool arg1, bool arg2, std::string const& arg3, std::string_view arg4);
    bool method9(int arg0, std::string_view arg1, bool arg2, bool arg3, bool arg4);
    void method10(unsigned arg0, bool arg1, std::string_view arg2, bool arg3, float arg4);
    void method11(bool arg0, std::string_view arg1, bool arg2, short arg3, double arg4);
    void method12(std::string arg0, bool arg1, std::string_view arg2, unsigned arg3, std::string const& arg4);
    void method13(bool arg0, std::string_view arg1, std::string arg2, std::string const& arg3, unsigned arg4);
    std::string method14(int arg0, double arg1, bool arg2, std::string arg3, float arg4);
}
