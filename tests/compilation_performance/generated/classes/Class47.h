#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class47
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(float arg0, bool arg1, short arg2, unsigned arg3, unsigned arg4);
    int method1(int arg0, int arg1, double arg2, short arg3, int arg4);
    void method2(float arg0, std::string arg1, short arg2, std::string const& arg3, std::string_view arg4);
    float method3(std::string arg0, float arg1, float arg2, float arg3, std::string_view arg4);
    void method4(std::string const& arg0, bool arg1, float arg2, bool arg3, std::string_view arg4);
    std::string_view method5(std::string_view arg0, std::string const& arg1, bool arg2, bool arg3, float arg4);
    void method6(std::string_view arg0, bool arg1, int arg2, float arg3, std::string arg4);
    bool method7(std::string const& arg0, bool arg1, int arg2, std::string const& arg3, short arg4);
    std::string method8(std::string arg0, bool arg1, short arg2, int arg3, std::string arg4);
    void method9(int arg0, short arg1, std::string_view arg2, unsigned arg3, std::string arg4);
    void method10(int arg0, float arg1, std::string const& arg2, bool arg3, double arg4);
    short method11(double arg0, short arg1, float arg2, unsigned arg3, std::string const& arg4);
    float method12(unsigned arg0, std::string const& arg1, short arg2, double arg3, float arg4);
    std::string_view method13(short arg0, short arg1, std::string arg2, std::string_view arg3, bool arg4);
    double method14(std::string const& arg0, std::string const& arg1, std::string const& arg2, float arg3, double arg4);
};

namespace ns_Class47
{
    short method0(float arg0, bool arg1, short arg2, unsigned arg3, unsigned arg4);
    int method1(int arg0, int arg1, double arg2, short arg3, int arg4);
    void method2(float arg0, std::string arg1, short arg2, std::string const& arg3, std::string_view arg4);
    float method3(std::string arg0, float arg1, float arg2, float arg3, std::string_view arg4);
    void method4(std::string const& arg0, bool arg1, float arg2, bool arg3, std::string_view arg4);
    std::string_view method5(std::string_view arg0, std::string const& arg1, bool arg2, bool arg3, float arg4);
    void method6(std::string_view arg0, bool arg1, int arg2, float arg3, std::string arg4);
    bool method7(std::string const& arg0, bool arg1, int arg2, std::string const& arg3, short arg4);
    std::string method8(std::string arg0, bool arg1, short arg2, int arg3, std::string arg4);
    void method9(int arg0, short arg1, std::string_view arg2, unsigned arg3, std::string arg4);
    void method10(int arg0, float arg1, std::string const& arg2, bool arg3, double arg4);
    short method11(double arg0, short arg1, float arg2, unsigned arg3, std::string const& arg4);
    float method12(unsigned arg0, std::string const& arg1, short arg2, double arg3, float arg4);
    std::string_view method13(short arg0, short arg1, std::string arg2, std::string_view arg3, bool arg4);
    double method14(std::string const& arg0, std::string const& arg1, std::string const& arg2, float arg3, double arg4);
}
