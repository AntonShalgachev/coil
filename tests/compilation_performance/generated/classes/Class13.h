#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class13
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string method0(bool arg0, int arg1, std::string arg2, int arg3, unsigned arg4);
    short method1(std::string arg0, std::string_view arg1, int arg2, short arg3, float arg4);
    void method2(float arg0, int arg1, float arg2, double arg3, unsigned arg4);
    bool method3(std::string arg0, float arg1, bool arg2, std::string const& arg3, std::string arg4);
    double method4(short arg0, std::string arg1, double arg2, double arg3, std::string_view arg4);
    void method5(short arg0, std::string arg1, int arg2, std::string const& arg3, double arg4);
    double method6(int arg0, double arg1, bool arg2, std::string_view arg3, std::string_view arg4);
    void method7(unsigned arg0, short arg1, bool arg2, float arg3, bool arg4);
    float method8(std::string const& arg0, float arg1, short arg2, std::string_view arg3, float arg4);
    void method9(short arg0, short arg1, float arg2, bool arg3, std::string const& arg4);
    void method10(std::string arg0, std::string const& arg1, std::string const& arg2, short arg3, float arg4);
    void method11(std::string const& arg0, float arg1, std::string_view arg2, std::string const& arg3, std::string_view arg4);
    std::string method12(int arg0, std::string arg1, std::string arg2, float arg3, int arg4);
    std::string const& method13(bool arg0, int arg1, unsigned arg2, std::string const& arg3, bool arg4);
    short method14(short arg0, std::string arg1, unsigned arg2, std::string arg3, double arg4);
};

namespace ns_Class13
{
    std::string method0(bool arg0, int arg1, std::string arg2, int arg3, unsigned arg4);
    short method1(std::string arg0, std::string_view arg1, int arg2, short arg3, float arg4);
    void method2(float arg0, int arg1, float arg2, double arg3, unsigned arg4);
    bool method3(std::string arg0, float arg1, bool arg2, std::string const& arg3, std::string arg4);
    double method4(short arg0, std::string arg1, double arg2, double arg3, std::string_view arg4);
    void method5(short arg0, std::string arg1, int arg2, std::string const& arg3, double arg4);
    double method6(int arg0, double arg1, bool arg2, std::string_view arg3, std::string_view arg4);
    void method7(unsigned arg0, short arg1, bool arg2, float arg3, bool arg4);
    float method8(std::string const& arg0, float arg1, short arg2, std::string_view arg3, float arg4);
    void method9(short arg0, short arg1, float arg2, bool arg3, std::string const& arg4);
    void method10(std::string arg0, std::string const& arg1, std::string const& arg2, short arg3, float arg4);
    void method11(std::string const& arg0, float arg1, std::string_view arg2, std::string const& arg3, std::string_view arg4);
    std::string method12(int arg0, std::string arg1, std::string arg2, float arg3, int arg4);
    std::string const& method13(bool arg0, int arg1, unsigned arg2, std::string const& arg3, bool arg4);
    short method14(short arg0, std::string arg1, unsigned arg2, std::string arg3, double arg4);
}
