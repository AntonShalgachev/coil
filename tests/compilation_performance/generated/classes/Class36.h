#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class36
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(unsigned arg0, int arg1, float arg2, std::string_view arg3, bool arg4);
    void method1(unsigned arg0, std::string arg1, std::string const& arg2, unsigned arg3, std::string arg4);
    float method2(int arg0, unsigned arg1, short arg2, float arg3, float arg4);
    short method3(std::string const& arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
    int method4(int arg0, unsigned arg1, short arg2, std::string const& arg3, double arg4);
    void method5(float arg0, std::string arg1, unsigned arg2, std::string_view arg3, std::string arg4);
    void method6(float arg0, std::string const& arg1, std::string arg2, std::string const& arg3, float arg4);
    void method7(int arg0, float arg1, unsigned arg2, std::string const& arg3, double arg4);
    void method8(float arg0, std::string const& arg1, int arg2, std::string_view arg3, std::string const& arg4);
    std::string method9(short arg0, bool arg1, std::string arg2, short arg3, unsigned arg4);
    void method10(std::string_view arg0, bool arg1, std::string arg2, std::string arg3, std::string arg4);
    float method11(float arg0, unsigned arg1, float arg2, float arg3, unsigned arg4);
    double method12(float arg0, float arg1, short arg2, double arg3, std::string arg4);
    int method13(short arg0, int arg1, std::string const& arg2, std::string arg3, std::string const& arg4);
    void method14(float arg0, unsigned arg1, short arg2, short arg3, unsigned arg4);
};

namespace ns_Class36
{
    bool method0(unsigned arg0, int arg1, float arg2, std::string_view arg3, bool arg4);
    void method1(unsigned arg0, std::string arg1, std::string const& arg2, unsigned arg3, std::string arg4);
    float method2(int arg0, unsigned arg1, short arg2, float arg3, float arg4);
    short method3(std::string const& arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
    int method4(int arg0, unsigned arg1, short arg2, std::string const& arg3, double arg4);
    void method5(float arg0, std::string arg1, unsigned arg2, std::string_view arg3, std::string arg4);
    void method6(float arg0, std::string const& arg1, std::string arg2, std::string const& arg3, float arg4);
    void method7(int arg0, float arg1, unsigned arg2, std::string const& arg3, double arg4);
    void method8(float arg0, std::string const& arg1, int arg2, std::string_view arg3, std::string const& arg4);
    std::string method9(short arg0, bool arg1, std::string arg2, short arg3, unsigned arg4);
    void method10(std::string_view arg0, bool arg1, std::string arg2, std::string arg3, std::string arg4);
    float method11(float arg0, unsigned arg1, float arg2, float arg3, unsigned arg4);
    double method12(float arg0, float arg1, short arg2, double arg3, std::string arg4);
    int method13(short arg0, int arg1, std::string const& arg2, std::string arg3, std::string const& arg4);
    void method14(float arg0, unsigned arg1, short arg2, short arg3, unsigned arg4);
}
