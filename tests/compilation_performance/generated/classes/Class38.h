#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class38
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, double arg1, int arg2, double arg3, double arg4);
    float method1(std::string arg0, int arg1, float arg2, unsigned arg3, double arg4);
    std::string const& method2(std::string const& arg0, std::string arg1, short arg2, short arg3, std::string const& arg4);
    float method3(float arg0, std::string arg1, std::string const& arg2, std::string_view arg3, std::string arg4);
    std::string_view method4(std::string const& arg0, std::string_view arg1, double arg2, int arg3, std::string const& arg4);
    void method5(int arg0, short arg1, int arg2, std::string_view arg3, std::string_view arg4);
    float method6(std::string_view arg0, double arg1, std::string arg2, float arg3, float arg4);
    void method7(float arg0, short arg1, int arg2, std::string_view arg3, double arg4);
    bool method8(unsigned arg0, bool arg1, unsigned arg2, short arg3, unsigned arg4);
    void method9(short arg0, short arg1, int arg2, double arg3, std::string const& arg4);
    short method10(unsigned arg0, float arg1, unsigned arg2, short arg3, std::string const& arg4);
    void method11(float arg0, bool arg1, float arg2, std::string arg3, float arg4);
    void method12(std::string_view arg0, int arg1, std::string const& arg2, short arg3, float arg4);
    std::string_view method13(std::string_view arg0, std::string const& arg1, short arg2, int arg3, std::string_view arg4);
    float method14(std::string_view arg0, short arg1, float arg2, float arg3, bool arg4);
};

namespace ns_Class38
{
    void method0(short arg0, double arg1, int arg2, double arg3, double arg4);
    float method1(std::string arg0, int arg1, float arg2, unsigned arg3, double arg4);
    std::string const& method2(std::string const& arg0, std::string arg1, short arg2, short arg3, std::string const& arg4);
    float method3(float arg0, std::string arg1, std::string const& arg2, std::string_view arg3, std::string arg4);
    std::string_view method4(std::string const& arg0, std::string_view arg1, double arg2, int arg3, std::string const& arg4);
    void method5(int arg0, short arg1, int arg2, std::string_view arg3, std::string_view arg4);
    float method6(std::string_view arg0, double arg1, std::string arg2, float arg3, float arg4);
    void method7(float arg0, short arg1, int arg2, std::string_view arg3, double arg4);
    bool method8(unsigned arg0, bool arg1, unsigned arg2, short arg3, unsigned arg4);
    void method9(short arg0, short arg1, int arg2, double arg3, std::string const& arg4);
    short method10(unsigned arg0, float arg1, unsigned arg2, short arg3, std::string const& arg4);
    void method11(float arg0, bool arg1, float arg2, std::string arg3, float arg4);
    void method12(std::string_view arg0, int arg1, std::string const& arg2, short arg3, float arg4);
    std::string_view method13(std::string_view arg0, std::string const& arg1, short arg2, int arg3, std::string_view arg4);
    float method14(std::string_view arg0, short arg1, float arg2, float arg3, bool arg4);
}
