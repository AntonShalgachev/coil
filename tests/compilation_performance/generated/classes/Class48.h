#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class48
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string method0(double arg0, unsigned arg1, std::string_view arg2, std::string arg3, bool arg4);
    void method1(std::string const& arg0, float arg1, unsigned arg2, short arg3, float arg4);
    unsigned method2(short arg0, short arg1, std::string arg2, unsigned arg3, double arg4);
    void method3(float arg0, double arg1, bool arg2, short arg3, std::string arg4);
    bool method4(bool arg0, float arg1, double arg2, float arg3, unsigned arg4);
    int method5(unsigned arg0, int arg1, unsigned arg2, std::string_view arg3, short arg4);
    void method6(double arg0, bool arg1, std::string const& arg2, unsigned arg3, float arg4);
    float method7(int arg0, float arg1, bool arg2, float arg3, int arg4);
    double method8(double arg0, int arg1, short arg2, short arg3, int arg4);
    void method9(int arg0, short arg1, float arg2, std::string arg3, unsigned arg4);
    int method10(std::string arg0, unsigned arg1, short arg2, int arg3, float arg4);
    void method11(double arg0, unsigned arg1, double arg2, bool arg3, bool arg4);
    void method12(unsigned arg0, std::string arg1, unsigned arg2, double arg3, std::string_view arg4);
    void method13(unsigned arg0, std::string const& arg1, short arg2, short arg3, std::string const& arg4);
    bool method14(std::string_view arg0, bool arg1, float arg2, short arg3, double arg4);
};

namespace ns_Class48
{
    std::string method0(double arg0, unsigned arg1, std::string_view arg2, std::string arg3, bool arg4);
    void method1(std::string const& arg0, float arg1, unsigned arg2, short arg3, float arg4);
    unsigned method2(short arg0, short arg1, std::string arg2, unsigned arg3, double arg4);
    void method3(float arg0, double arg1, bool arg2, short arg3, std::string arg4);
    bool method4(bool arg0, float arg1, double arg2, float arg3, unsigned arg4);
    int method5(unsigned arg0, int arg1, unsigned arg2, std::string_view arg3, short arg4);
    void method6(double arg0, bool arg1, std::string const& arg2, unsigned arg3, float arg4);
    float method7(int arg0, float arg1, bool arg2, float arg3, int arg4);
    double method8(double arg0, int arg1, short arg2, short arg3, int arg4);
    void method9(int arg0, short arg1, float arg2, std::string arg3, unsigned arg4);
    int method10(std::string arg0, unsigned arg1, short arg2, int arg3, float arg4);
    void method11(double arg0, unsigned arg1, double arg2, bool arg3, bool arg4);
    void method12(unsigned arg0, std::string arg1, unsigned arg2, double arg3, std::string_view arg4);
    void method13(unsigned arg0, std::string const& arg1, short arg2, short arg3, std::string const& arg4);
    bool method14(std::string_view arg0, bool arg1, float arg2, short arg3, double arg4);
}
