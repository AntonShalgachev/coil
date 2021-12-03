#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class70
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(std::string const& arg0, short arg1, double arg2, int arg3, std::string const& arg4);
    void method1(short arg0, short arg1, unsigned arg2, std::string_view arg3, std::string arg4);
    std::string method2(std::string_view arg0, std::string arg1, short arg2, unsigned arg3, double arg4);
    bool method3(bool arg0, bool arg1, std::string_view arg2, bool arg3, float arg4);
    void method4(unsigned arg0, std::string const& arg1, std::string_view arg2, std::string arg3, double arg4);
    void method5(std::string arg0, float arg1, unsigned arg2, int arg3, std::string arg4);
    std::string method6(double arg0, int arg1, std::string arg2, double arg3, short arg4);
    bool method7(float arg0, std::string_view arg1, float arg2, double arg3, bool arg4);
    unsigned method8(std::string const& arg0, unsigned arg1, short arg2, double arg3, bool arg4);
    std::string method9(std::string arg0, unsigned arg1, double arg2, float arg3, int arg4);
    int method10(double arg0, unsigned arg1, short arg2, int arg3, std::string const& arg4);
    std::string_view method11(std::string const& arg0, std::string_view arg1, std::string_view arg2, std::string arg3, unsigned arg4);
    std::string_view method12(std::string_view arg0, std::string arg1, std::string_view arg2, short arg3, std::string_view arg4);
    void method13(short arg0, float arg1, double arg2, double arg3, std::string const& arg4);
    void method14(int arg0, unsigned arg1, double arg2, unsigned arg3, std::string_view arg4);
};

namespace ns_Class70
{
    int method0(std::string const& arg0, short arg1, double arg2, int arg3, std::string const& arg4);
    void method1(short arg0, short arg1, unsigned arg2, std::string_view arg3, std::string arg4);
    std::string method2(std::string_view arg0, std::string arg1, short arg2, unsigned arg3, double arg4);
    bool method3(bool arg0, bool arg1, std::string_view arg2, bool arg3, float arg4);
    void method4(unsigned arg0, std::string const& arg1, std::string_view arg2, std::string arg3, double arg4);
    void method5(std::string arg0, float arg1, unsigned arg2, int arg3, std::string arg4);
    std::string method6(double arg0, int arg1, std::string arg2, double arg3, short arg4);
    bool method7(float arg0, std::string_view arg1, float arg2, double arg3, bool arg4);
    unsigned method8(std::string const& arg0, unsigned arg1, short arg2, double arg3, bool arg4);
    std::string method9(std::string arg0, unsigned arg1, double arg2, float arg3, int arg4);
    int method10(double arg0, unsigned arg1, short arg2, int arg3, std::string const& arg4);
    std::string_view method11(std::string const& arg0, std::string_view arg1, std::string_view arg2, std::string arg3, unsigned arg4);
    std::string_view method12(std::string_view arg0, std::string arg1, std::string_view arg2, short arg3, std::string_view arg4);
    void method13(short arg0, float arg1, double arg2, double arg3, std::string const& arg4);
    void method14(int arg0, unsigned arg1, double arg2, unsigned arg3, std::string_view arg4);
}
