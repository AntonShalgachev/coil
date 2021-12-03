#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class74
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string method0(std::string arg0, double arg1, float arg2, std::string arg3, bool arg4);
    void method1(unsigned arg0, int arg1, short arg2, short arg3, std::string_view arg4);
    void method2(short arg0, std::string_view arg1, std::string const& arg2, std::string_view arg3, short arg4);
    bool method3(bool arg0, bool arg1, bool arg2, bool arg3, std::string arg4);
    std::string const& method4(std::string arg0, std::string const& arg1, std::string const& arg2, std::string const& arg3, std::string const& arg4);
    void method5(unsigned arg0, int arg1, std::string arg2, double arg3, double arg4);
    float method6(unsigned arg0, float arg1, std::string arg2, bool arg3, float arg4);
    double method7(double arg0, double arg1, std::string const& arg2, bool arg3, float arg4);
    void method8(double arg0, int arg1, unsigned arg2, unsigned arg3, bool arg4);
    float method9(int arg0, float arg1, int arg2, std::string_view arg3, std::string arg4);
    void method10(double arg0, std::string const& arg1, float arg2, unsigned arg3, float arg4);
    double method11(unsigned arg0, double arg1, std::string const& arg2, unsigned arg3, short arg4);
    short method12(int arg0, int arg1, short arg2, bool arg3, double arg4);
    void method13(std::string const& arg0, int arg1, int arg2, double arg3, int arg4);
    short method14(std::string arg0, unsigned arg1, short arg2, unsigned arg3, std::string arg4);
};

namespace ns_Class74
{
    std::string method0(std::string arg0, double arg1, float arg2, std::string arg3, bool arg4);
    void method1(unsigned arg0, int arg1, short arg2, short arg3, std::string_view arg4);
    void method2(short arg0, std::string_view arg1, std::string const& arg2, std::string_view arg3, short arg4);
    bool method3(bool arg0, bool arg1, bool arg2, bool arg3, std::string arg4);
    std::string const& method4(std::string arg0, std::string const& arg1, std::string const& arg2, std::string const& arg3, std::string const& arg4);
    void method5(unsigned arg0, int arg1, std::string arg2, double arg3, double arg4);
    float method6(unsigned arg0, float arg1, std::string arg2, bool arg3, float arg4);
    double method7(double arg0, double arg1, std::string const& arg2, bool arg3, float arg4);
    void method8(double arg0, int arg1, unsigned arg2, unsigned arg3, bool arg4);
    float method9(int arg0, float arg1, int arg2, std::string_view arg3, std::string arg4);
    void method10(double arg0, std::string const& arg1, float arg2, unsigned arg3, float arg4);
    double method11(unsigned arg0, double arg1, std::string const& arg2, unsigned arg3, short arg4);
    short method12(int arg0, int arg1, short arg2, bool arg3, double arg4);
    void method13(std::string const& arg0, int arg1, int arg2, double arg3, int arg4);
    short method14(std::string arg0, unsigned arg1, short arg2, unsigned arg3, std::string arg4);
}
