#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class45
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(double arg0, short arg1, bool arg2, std::string_view arg3, short arg4);
    void method1(std::string const& arg0, int arg1, float arg2, unsigned arg3, std::string const& arg4);
    double method2(short arg0, std::string_view arg1, double arg2, short arg3, std::string arg4);
    void method3(double arg0, bool arg1, std::string arg2, std::string arg3, std::string const& arg4);
    unsigned method4(std::string arg0, unsigned arg1, float arg2, int arg3, double arg4);
    void method5(int arg0, unsigned arg1, double arg2, short arg3, std::string const& arg4);
    double method6(std::string const& arg0, double arg1, std::string arg2, double arg3, float arg4);
    void method7(double arg0, unsigned arg1, float arg2, double arg3, int arg4);
    unsigned method8(std::string arg0, short arg1, unsigned arg2, int arg3, std::string arg4);
    float method9(unsigned arg0, double arg1, unsigned arg2, bool arg3, float arg4);
    void method10(unsigned arg0, std::string_view arg1, bool arg2, float arg3, bool arg4);
    void method11(std::string_view arg0, double arg1, short arg2, bool arg3, short arg4);
    void method12(float arg0, std::string arg1, std::string arg2, short arg3, std::string arg4);
    bool method13(std::string const& arg0, bool arg1, float arg2, std::string_view arg3, float arg4);
    void method14(short arg0, std::string const& arg1, std::string arg2, short arg3, std::string const& arg4);
};

namespace ns_Class45
{
    short method0(double arg0, short arg1, bool arg2, std::string_view arg3, short arg4);
    void method1(std::string const& arg0, int arg1, float arg2, unsigned arg3, std::string const& arg4);
    double method2(short arg0, std::string_view arg1, double arg2, short arg3, std::string arg4);
    void method3(double arg0, bool arg1, std::string arg2, std::string arg3, std::string const& arg4);
    unsigned method4(std::string arg0, unsigned arg1, float arg2, int arg3, double arg4);
    void method5(int arg0, unsigned arg1, double arg2, short arg3, std::string const& arg4);
    double method6(std::string const& arg0, double arg1, std::string arg2, double arg3, float arg4);
    void method7(double arg0, unsigned arg1, float arg2, double arg3, int arg4);
    unsigned method8(std::string arg0, short arg1, unsigned arg2, int arg3, std::string arg4);
    float method9(unsigned arg0, double arg1, unsigned arg2, bool arg3, float arg4);
    void method10(unsigned arg0, std::string_view arg1, bool arg2, float arg3, bool arg4);
    void method11(std::string_view arg0, double arg1, short arg2, bool arg3, short arg4);
    void method12(float arg0, std::string arg1, std::string arg2, short arg3, std::string arg4);
    bool method13(std::string const& arg0, bool arg1, float arg2, std::string_view arg3, float arg4);
    void method14(short arg0, std::string const& arg1, std::string arg2, short arg3, std::string const& arg4);
}
