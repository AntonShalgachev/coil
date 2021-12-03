#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class10
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string method0(std::string arg0, std::string arg1, unsigned arg2, bool arg3, double arg4);
    short method1(short arg0, bool arg1, std::string const& arg2, double arg3, std::string arg4);
    std::string_view method2(short arg0, unsigned arg1, std::string_view arg2, short arg3, bool arg4);
    void method3(short arg0, double arg1, bool arg2, float arg3, float arg4);
    void method4(bool arg0, std::string arg1, short arg2, float arg3, std::string_view arg4);
    double method5(bool arg0, int arg1, unsigned arg2, float arg3, double arg4);
    std::string const& method6(double arg0, short arg1, short arg2, int arg3, std::string const& arg4);
    void method7(bool arg0, double arg1, double arg2, unsigned arg3, std::string const& arg4);
    void method8(int arg0, short arg1, std::string_view arg2, float arg3, std::string const& arg4);
    bool method9(bool arg0, unsigned arg1, unsigned arg2, std::string_view arg3, int arg4);
    double method10(float arg0, short arg1, std::string const& arg2, double arg3, std::string arg4);
    short method11(short arg0, short arg1, float arg2, std::string const& arg3, short arg4);
    void method12(int arg0, int arg1, double arg2, short arg3, short arg4);
    void method13(std::string arg0, std::string_view arg1, int arg2, int arg3, short arg4);
    void method14(int arg0, float arg1, double arg2, short arg3, float arg4);
};

namespace ns_Class10
{
    std::string method0(std::string arg0, std::string arg1, unsigned arg2, bool arg3, double arg4);
    short method1(short arg0, bool arg1, std::string const& arg2, double arg3, std::string arg4);
    std::string_view method2(short arg0, unsigned arg1, std::string_view arg2, short arg3, bool arg4);
    void method3(short arg0, double arg1, bool arg2, float arg3, float arg4);
    void method4(bool arg0, std::string arg1, short arg2, float arg3, std::string_view arg4);
    double method5(bool arg0, int arg1, unsigned arg2, float arg3, double arg4);
    std::string const& method6(double arg0, short arg1, short arg2, int arg3, std::string const& arg4);
    void method7(bool arg0, double arg1, double arg2, unsigned arg3, std::string const& arg4);
    void method8(int arg0, short arg1, std::string_view arg2, float arg3, std::string const& arg4);
    bool method9(bool arg0, unsigned arg1, unsigned arg2, std::string_view arg3, int arg4);
    double method10(float arg0, short arg1, std::string const& arg2, double arg3, std::string arg4);
    short method11(short arg0, short arg1, float arg2, std::string const& arg3, short arg4);
    void method12(int arg0, int arg1, double arg2, short arg3, short arg4);
    void method13(std::string arg0, std::string_view arg1, int arg2, int arg3, short arg4);
    void method14(int arg0, float arg1, double arg2, short arg3, float arg4);
}
