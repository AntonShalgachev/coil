#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class57
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, short arg1, double arg2, float arg3, double arg4);
    bool method1(std::string_view arg0, short arg1, double arg2, int arg3, bool arg4);
    void method2(unsigned arg0, double arg1, bool arg2, std::string arg3, double arg4);
    void method3(int arg0, unsigned arg1, float arg2, float arg3, std::string arg4);
    double method4(double arg0, double arg1, bool arg2, short arg3, unsigned arg4);
    void method5(std::string arg0, short arg1, std::string const& arg2, int arg3, std::string arg4);
    unsigned method6(std::string arg0, int arg1, unsigned arg2, double arg3, short arg4);
    bool method7(bool arg0, bool arg1, bool arg2, double arg3, double arg4);
    bool method8(std::string const& arg0, bool arg1, std::string const& arg2, unsigned arg3, float arg4);
    void method9(std::string const& arg0, std::string_view arg1, std::string arg2, bool arg3, std::string arg4);
    void method10(int arg0, short arg1, std::string arg2, unsigned arg3, short arg4);
    void method11(bool arg0, float arg1, std::string arg2, double arg3, double arg4);
    void method12(std::string arg0, unsigned arg1, std::string_view arg2, double arg3, std::string_view arg4);
    void method13(std::string arg0, float arg1, std::string arg2, std::string_view arg3, std::string const& arg4);
    void method14(std::string arg0, std::string const& arg1, std::string_view arg2, bool arg3, unsigned arg4);
};

namespace ns_Class57
{
    void method0(int arg0, short arg1, double arg2, float arg3, double arg4);
    bool method1(std::string_view arg0, short arg1, double arg2, int arg3, bool arg4);
    void method2(unsigned arg0, double arg1, bool arg2, std::string arg3, double arg4);
    void method3(int arg0, unsigned arg1, float arg2, float arg3, std::string arg4);
    double method4(double arg0, double arg1, bool arg2, short arg3, unsigned arg4);
    void method5(std::string arg0, short arg1, std::string const& arg2, int arg3, std::string arg4);
    unsigned method6(std::string arg0, int arg1, unsigned arg2, double arg3, short arg4);
    bool method7(bool arg0, bool arg1, bool arg2, double arg3, double arg4);
    bool method8(std::string const& arg0, bool arg1, std::string const& arg2, unsigned arg3, float arg4);
    void method9(std::string const& arg0, std::string_view arg1, std::string arg2, bool arg3, std::string arg4);
    void method10(int arg0, short arg1, std::string arg2, unsigned arg3, short arg4);
    void method11(bool arg0, float arg1, std::string arg2, double arg3, double arg4);
    void method12(std::string arg0, unsigned arg1, std::string_view arg2, double arg3, std::string_view arg4);
    void method13(std::string arg0, float arg1, std::string arg2, std::string_view arg3, std::string const& arg4);
    void method14(std::string arg0, std::string const& arg1, std::string_view arg2, bool arg3, unsigned arg4);
}
