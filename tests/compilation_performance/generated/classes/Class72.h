#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class72
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(int arg0, std::string const& arg1, std::string const& arg2, int arg3, unsigned arg4);
    std::string_view method1(float arg0, std::string_view arg1, int arg2, unsigned arg3, int arg4);
    void method2(float arg0, bool arg1, bool arg2, std::string arg3, float arg4);
    double method3(double arg0, unsigned arg1, unsigned arg2, double arg3, bool arg4);
    void method4(int arg0, unsigned arg1, double arg2, unsigned arg3, std::string arg4);
    void method5(int arg0, short arg1, std::string_view arg2, std::string arg3, float arg4);
    std::string method6(std::string const& arg0, double arg1, bool arg2, std::string arg3, std::string_view arg4);
    void method7(std::string_view arg0, std::string const& arg1, bool arg2, int arg3, short arg4);
    void method8(std::string const& arg0, std::string_view arg1, std::string const& arg2, std::string arg3, std::string arg4);
    void method9(short arg0, short arg1, unsigned arg2, bool arg3, int arg4);
    bool method10(float arg0, bool arg1, unsigned arg2, float arg3, double arg4);
    void method11(bool arg0, short arg1, short arg2, double arg3, int arg4);
    double method12(double arg0, std::string arg1, int arg2, short arg3, std::string const& arg4);
    double method13(int arg0, int arg1, double arg2, double arg3, float arg4);
    void method14(unsigned arg0, std::string_view arg1, double arg2, short arg3, float arg4);
};

namespace ns_Class72
{
    int method0(int arg0, std::string const& arg1, std::string const& arg2, int arg3, unsigned arg4);
    std::string_view method1(float arg0, std::string_view arg1, int arg2, unsigned arg3, int arg4);
    void method2(float arg0, bool arg1, bool arg2, std::string arg3, float arg4);
    double method3(double arg0, unsigned arg1, unsigned arg2, double arg3, bool arg4);
    void method4(int arg0, unsigned arg1, double arg2, unsigned arg3, std::string arg4);
    void method5(int arg0, short arg1, std::string_view arg2, std::string arg3, float arg4);
    std::string method6(std::string const& arg0, double arg1, bool arg2, std::string arg3, std::string_view arg4);
    void method7(std::string_view arg0, std::string const& arg1, bool arg2, int arg3, short arg4);
    void method8(std::string const& arg0, std::string_view arg1, std::string const& arg2, std::string arg3, std::string arg4);
    void method9(short arg0, short arg1, unsigned arg2, bool arg3, int arg4);
    bool method10(float arg0, bool arg1, unsigned arg2, float arg3, double arg4);
    void method11(bool arg0, short arg1, short arg2, double arg3, int arg4);
    double method12(double arg0, std::string arg1, int arg2, short arg3, std::string const& arg4);
    double method13(int arg0, int arg1, double arg2, double arg3, float arg4);
    void method14(unsigned arg0, std::string_view arg1, double arg2, short arg3, float arg4);
}
