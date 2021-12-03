#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class63
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(bool arg0, float arg1, std::string_view arg2, std::string_view arg3, double arg4);
    short method1(short arg0, std::string arg1, short arg2, std::string_view arg3, int arg4);
    void method2(std::string arg0, int arg1, std::string_view arg2, unsigned arg3, unsigned arg4);
    void method3(unsigned arg0, std::string const& arg1, double arg2, std::string arg3, unsigned arg4);
    void method4(std::string const& arg0, std::string arg1, unsigned arg2, short arg3, int arg4);
    void method5(std::string arg0, int arg1, bool arg2, bool arg3, short arg4);
    void method6(double arg0, unsigned arg1, short arg2, std::string_view arg3, std::string_view arg4);
    void method7(double arg0, int arg1, unsigned arg2, unsigned arg3, double arg4);
    void method8(unsigned arg0, bool arg1, std::string const& arg2, std::string arg3, double arg4);
    bool method9(bool arg0, std::string const& arg1, int arg2, unsigned arg3, std::string_view arg4);
    bool method10(int arg0, unsigned arg1, short arg2, bool arg3, bool arg4);
    bool method11(bool arg0, std::string_view arg1, int arg2, std::string const& arg3, std::string_view arg4);
    void method12(std::string const& arg0, double arg1, std::string const& arg2, std::string arg3, int arg4);
    void method13(unsigned arg0, std::string const& arg1, unsigned arg2, bool arg3, float arg4);
    short method14(std::string arg0, std::string arg1, std::string arg2, double arg3, short arg4);
};

namespace ns_Class63
{
    void method0(bool arg0, float arg1, std::string_view arg2, std::string_view arg3, double arg4);
    short method1(short arg0, std::string arg1, short arg2, std::string_view arg3, int arg4);
    void method2(std::string arg0, int arg1, std::string_view arg2, unsigned arg3, unsigned arg4);
    void method3(unsigned arg0, std::string const& arg1, double arg2, std::string arg3, unsigned arg4);
    void method4(std::string const& arg0, std::string arg1, unsigned arg2, short arg3, int arg4);
    void method5(std::string arg0, int arg1, bool arg2, bool arg3, short arg4);
    void method6(double arg0, unsigned arg1, short arg2, std::string_view arg3, std::string_view arg4);
    void method7(double arg0, int arg1, unsigned arg2, unsigned arg3, double arg4);
    void method8(unsigned arg0, bool arg1, std::string const& arg2, std::string arg3, double arg4);
    bool method9(bool arg0, std::string const& arg1, int arg2, unsigned arg3, std::string_view arg4);
    bool method10(int arg0, unsigned arg1, short arg2, bool arg3, bool arg4);
    bool method11(bool arg0, std::string_view arg1, int arg2, std::string const& arg3, std::string_view arg4);
    void method12(std::string const& arg0, double arg1, std::string const& arg2, std::string arg3, int arg4);
    void method13(unsigned arg0, std::string const& arg1, unsigned arg2, bool arg3, float arg4);
    short method14(std::string arg0, std::string arg1, std::string arg2, double arg3, short arg4);
}
