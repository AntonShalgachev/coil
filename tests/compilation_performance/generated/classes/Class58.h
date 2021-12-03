#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class58
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(std::string const& arg0, unsigned arg1, std::string arg2, short arg3, bool arg4);
    void method1(std::string const& arg0, short arg1, short arg2, unsigned arg3, int arg4);
    void method2(unsigned arg0, short arg1, short arg2, unsigned arg3, std::string arg4);
    bool method3(bool arg0, short arg1, float arg2, std::string const& arg3, unsigned arg4);
    bool method4(int arg0, bool arg1, double arg2, std::string_view arg3, int arg4);
    int method5(double arg0, int arg1, double arg2, float arg3, std::string const& arg4);
    void method6(bool arg0, std::string_view arg1, bool arg2, std::string const& arg3, float arg4);
    std::string_view method7(double arg0, unsigned arg1, std::string_view arg2, std::string const& arg3, std::string arg4);
    void method8(unsigned arg0, bool arg1, std::string const& arg2, int arg3, float arg4);
    void method9(int arg0, std::string_view arg1, double arg2, float arg3, float arg4);
    void method10(short arg0, int arg1, int arg2, std::string_view arg3, std::string const& arg4);
    void method11(std::string const& arg0, std::string_view arg1, bool arg2, bool arg3, std::string arg4);
    int method12(bool arg0, std::string arg1, unsigned arg2, std::string const& arg3, int arg4);
    bool method13(std::string_view arg0, std::string const& arg1, int arg2, bool arg3, float arg4);
    std::string method14(double arg0, std::string const& arg1, double arg2, bool arg3, std::string arg4);
};

namespace ns_Class58
{
    void method0(std::string const& arg0, unsigned arg1, std::string arg2, short arg3, bool arg4);
    void method1(std::string const& arg0, short arg1, short arg2, unsigned arg3, int arg4);
    void method2(unsigned arg0, short arg1, short arg2, unsigned arg3, std::string arg4);
    bool method3(bool arg0, short arg1, float arg2, std::string const& arg3, unsigned arg4);
    bool method4(int arg0, bool arg1, double arg2, std::string_view arg3, int arg4);
    int method5(double arg0, int arg1, double arg2, float arg3, std::string const& arg4);
    void method6(bool arg0, std::string_view arg1, bool arg2, std::string const& arg3, float arg4);
    std::string_view method7(double arg0, unsigned arg1, std::string_view arg2, std::string const& arg3, std::string arg4);
    void method8(unsigned arg0, bool arg1, std::string const& arg2, int arg3, float arg4);
    void method9(int arg0, std::string_view arg1, double arg2, float arg3, float arg4);
    void method10(short arg0, int arg1, int arg2, std::string_view arg3, std::string const& arg4);
    void method11(std::string const& arg0, std::string_view arg1, bool arg2, bool arg3, std::string arg4);
    int method12(bool arg0, std::string arg1, unsigned arg2, std::string const& arg3, int arg4);
    bool method13(std::string_view arg0, std::string const& arg1, int arg2, bool arg3, float arg4);
    std::string method14(double arg0, std::string const& arg1, double arg2, bool arg3, std::string arg4);
}
