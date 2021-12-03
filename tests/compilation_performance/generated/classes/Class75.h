#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class75
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(std::string arg0, std::string_view arg1, std::string arg2, int arg3, float arg4);
    double method1(std::string const& arg0, int arg1, float arg2, float arg3, double arg4);
    void method2(int arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method3(short arg0, std::string arg1, bool arg2, std::string arg3, bool arg4);
    void method4(unsigned arg0, bool arg1, int arg2, float arg3, unsigned arg4);
    double method5(short arg0, bool arg1, double arg2, std::string_view arg3, std::string_view arg4);
    unsigned method6(bool arg0, unsigned arg1, bool arg2, int arg3, int arg4);
    void method7(std::string arg0, std::string const& arg1, unsigned arg2, double arg3, std::string arg4);
    std::string_view method8(std::string const& arg0, short arg1, bool arg2, std::string const& arg3, std::string_view arg4);
    short method9(short arg0, float arg1, short arg2, int arg3, bool arg4);
    short method10(std::string_view arg0, short arg1, unsigned arg2, float arg3, std::string const& arg4);
    int method11(int arg0, std::string const& arg1, float arg2, bool arg3, double arg4);
    std::string_view method12(double arg0, double arg1, std::string_view arg2, float arg3, short arg4);
    bool method13(bool arg0, std::string arg1, bool arg2, double arg3, unsigned arg4);
    std::string method14(std::string arg0, double arg1, unsigned arg2, double arg3, std::string const& arg4);
};

namespace ns_Class75
{
    void method0(std::string arg0, std::string_view arg1, std::string arg2, int arg3, float arg4);
    double method1(std::string const& arg0, int arg1, float arg2, float arg3, double arg4);
    void method2(int arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method3(short arg0, std::string arg1, bool arg2, std::string arg3, bool arg4);
    void method4(unsigned arg0, bool arg1, int arg2, float arg3, unsigned arg4);
    double method5(short arg0, bool arg1, double arg2, std::string_view arg3, std::string_view arg4);
    unsigned method6(bool arg0, unsigned arg1, bool arg2, int arg3, int arg4);
    void method7(std::string arg0, std::string const& arg1, unsigned arg2, double arg3, std::string arg4);
    std::string_view method8(std::string const& arg0, short arg1, bool arg2, std::string const& arg3, std::string_view arg4);
    short method9(short arg0, float arg1, short arg2, int arg3, bool arg4);
    short method10(std::string_view arg0, short arg1, unsigned arg2, float arg3, std::string const& arg4);
    int method11(int arg0, std::string const& arg1, float arg2, bool arg3, double arg4);
    std::string_view method12(double arg0, double arg1, std::string_view arg2, float arg3, short arg4);
    bool method13(bool arg0, std::string arg1, bool arg2, double arg3, unsigned arg4);
    std::string method14(std::string arg0, double arg1, unsigned arg2, double arg3, std::string const& arg4);
}
