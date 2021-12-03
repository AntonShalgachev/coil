#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class30
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(int arg0, std::string const& arg1, float arg2, float arg3, std::string arg4);
    void method1(unsigned arg0, std::string arg1, unsigned arg2, double arg3, int arg4);
    void method2(float arg0, std::string_view arg1, int arg2, double arg3, int arg4);
    void method3(std::string arg0, std::string arg1, double arg2, std::string const& arg3, float arg4);
    void method4(int arg0, double arg1, std::string_view arg2, std::string_view arg3, unsigned arg4);
    std::string method5(std::string arg0, int arg1, std::string arg2, bool arg3, std::string const& arg4);
    std::string_view method6(short arg0, std::string_view arg1, std::string_view arg2, std::string_view arg3, unsigned arg4);
    float method7(std::string arg0, short arg1, float arg2, unsigned arg3, std::string arg4);
    void method8(int arg0, double arg1, bool arg2, short arg3, unsigned arg4);
    void method9(int arg0, int arg1, std::string const& arg2, std::string_view arg3, short arg4);
    bool method10(bool arg0, bool arg1, std::string arg2, bool arg3, float arg4);
    float method11(float arg0, float arg1, int arg2, unsigned arg3, double arg4);
    void method12(bool arg0, double arg1, std::string arg2, short arg3, short arg4);
    void method13(std::string const& arg0, std::string_view arg1, float arg2, int arg3, short arg4);
    int method14(int arg0, short arg1, double arg2, std::string arg3, std::string arg4);
};

namespace ns_Class30
{
    float method0(int arg0, std::string const& arg1, float arg2, float arg3, std::string arg4);
    void method1(unsigned arg0, std::string arg1, unsigned arg2, double arg3, int arg4);
    void method2(float arg0, std::string_view arg1, int arg2, double arg3, int arg4);
    void method3(std::string arg0, std::string arg1, double arg2, std::string const& arg3, float arg4);
    void method4(int arg0, double arg1, std::string_view arg2, std::string_view arg3, unsigned arg4);
    std::string method5(std::string arg0, int arg1, std::string arg2, bool arg3, std::string const& arg4);
    std::string_view method6(short arg0, std::string_view arg1, std::string_view arg2, std::string_view arg3, unsigned arg4);
    float method7(std::string arg0, short arg1, float arg2, unsigned arg3, std::string arg4);
    void method8(int arg0, double arg1, bool arg2, short arg3, unsigned arg4);
    void method9(int arg0, int arg1, std::string const& arg2, std::string_view arg3, short arg4);
    bool method10(bool arg0, bool arg1, std::string arg2, bool arg3, float arg4);
    float method11(float arg0, float arg1, int arg2, unsigned arg3, double arg4);
    void method12(bool arg0, double arg1, std::string arg2, short arg3, short arg4);
    void method13(std::string const& arg0, std::string_view arg1, float arg2, int arg3, short arg4);
    int method14(int arg0, short arg1, double arg2, std::string arg3, std::string arg4);
}
