#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class1
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(std::string arg0, double arg1, std::string arg2, std::string_view arg3, short arg4);
    void method1(double arg0, std::string arg1, std::string const& arg2, std::string const& arg3, float arg4);
    float method2(unsigned arg0, std::string const& arg1, std::string arg2, float arg3, std::string arg4);
    void method3(short arg0, double arg1, std::string arg2, short arg3, std::string_view arg4);
    void method4(float arg0, std::string arg1, int arg2, float arg3, unsigned arg4);
    short method5(float arg0, std::string const& arg1, std::string const& arg2, short arg3, float arg4);
    bool method6(std::string_view arg0, std::string_view arg1, bool arg2, double arg3, std::string arg4);
    bool method7(bool arg0, unsigned arg1, float arg2, bool arg3, bool arg4);
    void method8(int arg0, std::string_view arg1, std::string arg2, int arg3, unsigned arg4);
    void method9(std::string arg0, int arg1, double arg2, short arg3, std::string arg4);
    void method10(bool arg0, int arg1, int arg2, unsigned arg3, std::string const& arg4);
    void method11(int arg0, std::string_view arg1, std::string const& arg2, double arg3, std::string arg4);
    void method12(int arg0, double arg1, int arg2, std::string const& arg3, unsigned arg4);
    void method13(std::string_view arg0, std::string arg1, std::string_view arg2, std::string arg3, std::string_view arg4);
    std::string_view method14(std::string_view arg0, float arg1, double arg2, std::string_view arg3, bool arg4);
};

namespace ns_Class1
{
    double method0(std::string arg0, double arg1, std::string arg2, std::string_view arg3, short arg4);
    void method1(double arg0, std::string arg1, std::string const& arg2, std::string const& arg3, float arg4);
    float method2(unsigned arg0, std::string const& arg1, std::string arg2, float arg3, std::string arg4);
    void method3(short arg0, double arg1, std::string arg2, short arg3, std::string_view arg4);
    void method4(float arg0, std::string arg1, int arg2, float arg3, unsigned arg4);
    short method5(float arg0, std::string const& arg1, std::string const& arg2, short arg3, float arg4);
    bool method6(std::string_view arg0, std::string_view arg1, bool arg2, double arg3, std::string arg4);
    bool method7(bool arg0, unsigned arg1, float arg2, bool arg3, bool arg4);
    void method8(int arg0, std::string_view arg1, std::string arg2, int arg3, unsigned arg4);
    void method9(std::string arg0, int arg1, double arg2, short arg3, std::string arg4);
    void method10(bool arg0, int arg1, int arg2, unsigned arg3, std::string const& arg4);
    void method11(int arg0, std::string_view arg1, std::string const& arg2, double arg3, std::string arg4);
    void method12(int arg0, double arg1, int arg2, std::string const& arg3, unsigned arg4);
    void method13(std::string_view arg0, std::string arg1, std::string_view arg2, std::string arg3, std::string_view arg4);
    std::string_view method14(std::string_view arg0, float arg1, double arg2, std::string_view arg3, bool arg4);
}
