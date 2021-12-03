#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class27
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, bool arg1, int arg2, unsigned arg3, unsigned arg4);
    void method1(std::string_view arg0, int arg1, unsigned arg2, short arg3, short arg4);
    void method2(double arg0, std::string arg1, float arg2, bool arg3, float arg4);
    float method3(unsigned arg0, bool arg1, int arg2, bool arg3, float arg4);
    bool method4(std::string_view arg0, int arg1, double arg2, double arg3, bool arg4);
    void method5(short arg0, bool arg1, int arg2, int arg3, bool arg4);
    void method6(bool arg0, float arg1, float arg2, std::string arg3, short arg4);
    short method7(short arg0, double arg1, unsigned arg2, std::string_view arg3, short arg4);
    void method8(float arg0, short arg1, bool arg2, double arg3, std::string const& arg4);
    double method9(std::string const& arg0, double arg1, int arg2, double arg3, int arg4);
    std::string method10(float arg0, double arg1, std::string const& arg2, std::string arg3, int arg4);
    unsigned method11(unsigned arg0, int arg1, int arg2, std::string arg3, short arg4);
    std::string method12(std::string arg0, short arg1, int arg2, bool arg3, bool arg4);
    unsigned method13(std::string_view arg0, std::string arg1, std::string const& arg2, unsigned arg3, float arg4);
    unsigned method14(std::string_view arg0, bool arg1, float arg2, std::string_view arg3, unsigned arg4);
};

namespace ns_Class27
{
    void method0(int arg0, bool arg1, int arg2, unsigned arg3, unsigned arg4);
    void method1(std::string_view arg0, int arg1, unsigned arg2, short arg3, short arg4);
    void method2(double arg0, std::string arg1, float arg2, bool arg3, float arg4);
    float method3(unsigned arg0, bool arg1, int arg2, bool arg3, float arg4);
    bool method4(std::string_view arg0, int arg1, double arg2, double arg3, bool arg4);
    void method5(short arg0, bool arg1, int arg2, int arg3, bool arg4);
    void method6(bool arg0, float arg1, float arg2, std::string arg3, short arg4);
    short method7(short arg0, double arg1, unsigned arg2, std::string_view arg3, short arg4);
    void method8(float arg0, short arg1, bool arg2, double arg3, std::string const& arg4);
    double method9(std::string const& arg0, double arg1, int arg2, double arg3, int arg4);
    std::string method10(float arg0, double arg1, std::string const& arg2, std::string arg3, int arg4);
    unsigned method11(unsigned arg0, int arg1, int arg2, std::string arg3, short arg4);
    std::string method12(std::string arg0, short arg1, int arg2, bool arg3, bool arg4);
    unsigned method13(std::string_view arg0, std::string arg1, std::string const& arg2, unsigned arg3, float arg4);
    unsigned method14(std::string_view arg0, bool arg1, float arg2, std::string_view arg3, unsigned arg4);
}
