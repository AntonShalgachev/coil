#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class25
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(std::string_view arg0, double arg1, int arg2, int arg3, std::string arg4);
    int method1(std::string const& arg0, int arg1, int arg2, std::string const& arg3, std::string const& arg4);
    void method2(unsigned arg0, bool arg1, bool arg2, short arg3, std::string_view arg4);
    unsigned method3(std::string_view arg0, unsigned arg1, unsigned arg2, std::string arg3, bool arg4);
    double method4(unsigned arg0, short arg1, double arg2, double arg3, bool arg4);
    void method5(float arg0, std::string const& arg1, std::string_view arg2, double arg3, std::string_view arg4);
    int method6(std::string_view arg0, int arg1, bool arg2, std::string arg3, int arg4);
    float method7(int arg0, std::string const& arg1, float arg2, unsigned arg3, short arg4);
    float method8(std::string const& arg0, std::string const& arg1, unsigned arg2, float arg3, bool arg4);
    std::string_view method9(short arg0, std::string arg1, std::string_view arg2, std::string arg3, std::string const& arg4);
    void method10(bool arg0, int arg1, float arg2, unsigned arg3, float arg4);
    void method11(double arg0, unsigned arg1, std::string arg2, double arg3, bool arg4);
    float method12(short arg0, short arg1, std::string_view arg2, float arg3, float arg4);
    bool method13(float arg0, float arg1, double arg2, double arg3, bool arg4);
    unsigned method14(int arg0, unsigned arg1, std::string const& arg2, std::string const& arg3, bool arg4);
};

namespace ns_Class25
{
    void method0(std::string_view arg0, double arg1, int arg2, int arg3, std::string arg4);
    int method1(std::string const& arg0, int arg1, int arg2, std::string const& arg3, std::string const& arg4);
    void method2(unsigned arg0, bool arg1, bool arg2, short arg3, std::string_view arg4);
    unsigned method3(std::string_view arg0, unsigned arg1, unsigned arg2, std::string arg3, bool arg4);
    double method4(unsigned arg0, short arg1, double arg2, double arg3, bool arg4);
    void method5(float arg0, std::string const& arg1, std::string_view arg2, double arg3, std::string_view arg4);
    int method6(std::string_view arg0, int arg1, bool arg2, std::string arg3, int arg4);
    float method7(int arg0, std::string const& arg1, float arg2, unsigned arg3, short arg4);
    float method8(std::string const& arg0, std::string const& arg1, unsigned arg2, float arg3, bool arg4);
    std::string_view method9(short arg0, std::string arg1, std::string_view arg2, std::string arg3, std::string const& arg4);
    void method10(bool arg0, int arg1, float arg2, unsigned arg3, float arg4);
    void method11(double arg0, unsigned arg1, std::string arg2, double arg3, bool arg4);
    float method12(short arg0, short arg1, std::string_view arg2, float arg3, float arg4);
    bool method13(float arg0, float arg1, double arg2, double arg3, bool arg4);
    unsigned method14(int arg0, unsigned arg1, std::string const& arg2, std::string const& arg3, bool arg4);
}
