#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class95
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(std::string const& arg0, short arg1, bool arg2, float arg3, bool arg4);
    void method1(std::string_view arg0, std::string const& arg1, std::string_view arg2, std::string_view arg3, short arg4);
    void method2(short arg0, unsigned arg1, unsigned arg2, bool arg3, std::string_view arg4);
    unsigned method3(unsigned arg0, float arg1, bool arg2, std::string const& arg3, std::string const& arg4);
    double method4(float arg0, double arg1, std::string const& arg2, float arg3, short arg4);
    void method5(std::string arg0, std::string const& arg1, double arg2, std::string_view arg3, double arg4);
    std::string_view method6(float arg0, short arg1, bool arg2, std::string_view arg3, double arg4);
    std::string_view method7(bool arg0, float arg1, float arg2, float arg3, std::string_view arg4);
    void method8(std::string const& arg0, std::string const& arg1, std::string_view arg2, unsigned arg3, std::string arg4);
    double method9(float arg0, double arg1, double arg2, std::string_view arg3, int arg4);
    float method10(std::string arg0, int arg1, float arg2, std::string const& arg3, bool arg4);
    unsigned method11(std::string arg0, int arg1, bool arg2, std::string_view arg3, unsigned arg4);
    void method12(std::string_view arg0, std::string arg1, std::string arg2, double arg3, bool arg4);
    void method13(bool arg0, float arg1, short arg2, bool arg3, short arg4);
    std::string_view method14(int arg0, int arg1, int arg2, short arg3, std::string_view arg4);
};

namespace ns_Class95
{
    bool method0(std::string const& arg0, short arg1, bool arg2, float arg3, bool arg4);
    void method1(std::string_view arg0, std::string const& arg1, std::string_view arg2, std::string_view arg3, short arg4);
    void method2(short arg0, unsigned arg1, unsigned arg2, bool arg3, std::string_view arg4);
    unsigned method3(unsigned arg0, float arg1, bool arg2, std::string const& arg3, std::string const& arg4);
    double method4(float arg0, double arg1, std::string const& arg2, float arg3, short arg4);
    void method5(std::string arg0, std::string const& arg1, double arg2, std::string_view arg3, double arg4);
    std::string_view method6(float arg0, short arg1, bool arg2, std::string_view arg3, double arg4);
    std::string_view method7(bool arg0, float arg1, float arg2, float arg3, std::string_view arg4);
    void method8(std::string const& arg0, std::string const& arg1, std::string_view arg2, unsigned arg3, std::string arg4);
    double method9(float arg0, double arg1, double arg2, std::string_view arg3, int arg4);
    float method10(std::string arg0, int arg1, float arg2, std::string const& arg3, bool arg4);
    unsigned method11(std::string arg0, int arg1, bool arg2, std::string_view arg3, unsigned arg4);
    void method12(std::string_view arg0, std::string arg1, std::string arg2, double arg3, bool arg4);
    void method13(bool arg0, float arg1, short arg2, bool arg3, short arg4);
    std::string_view method14(int arg0, int arg1, int arg2, short arg3, std::string_view arg4);
}
