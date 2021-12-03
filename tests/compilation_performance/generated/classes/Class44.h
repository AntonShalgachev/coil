#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class44
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    std::string const& method0(std::string const& arg0, float arg1, int arg2, short arg3, std::string arg4);
    unsigned method1(int arg0, std::string const& arg1, double arg2, unsigned arg3, unsigned arg4);
    double method2(double arg0, unsigned arg1, int arg2, std::string const& arg3, float arg4);
    std::string_view method3(float arg0, short arg1, std::string_view arg2, unsigned arg3, bool arg4);
    bool method4(short arg0, bool arg1, short arg2, bool arg3, double arg4);
    void method5(int arg0, bool arg1, std::string arg2, int arg3, int arg4);
    void method6(float arg0, float arg1, std::string const& arg2, bool arg3, bool arg4);
    void method7(short arg0, double arg1, float arg2, double arg3, bool arg4);
    void method8(int arg0, std::string const& arg1, short arg2, float arg3, unsigned arg4);
    void method9(std::string arg0, bool arg1, unsigned arg2, float arg3, std::string const& arg4);
    void method10(short arg0, double arg1, bool arg2, int arg3, int arg4);
    void method11(std::string_view arg0, double arg1, int arg2, float arg3, std::string const& arg4);
    void method12(bool arg0, double arg1, int arg2, unsigned arg3, std::string_view arg4);
    void method13(float arg0, unsigned arg1, std::string arg2, std::string_view arg3, std::string const& arg4);
    void method14(unsigned arg0, unsigned arg1, float arg2, unsigned arg3, float arg4);
};

namespace ns_Class44
{
    std::string const& method0(std::string const& arg0, float arg1, int arg2, short arg3, std::string arg4);
    unsigned method1(int arg0, std::string const& arg1, double arg2, unsigned arg3, unsigned arg4);
    double method2(double arg0, unsigned arg1, int arg2, std::string const& arg3, float arg4);
    std::string_view method3(float arg0, short arg1, std::string_view arg2, unsigned arg3, bool arg4);
    bool method4(short arg0, bool arg1, short arg2, bool arg3, double arg4);
    void method5(int arg0, bool arg1, std::string arg2, int arg3, int arg4);
    void method6(float arg0, float arg1, std::string const& arg2, bool arg3, bool arg4);
    void method7(short arg0, double arg1, float arg2, double arg3, bool arg4);
    void method8(int arg0, std::string const& arg1, short arg2, float arg3, unsigned arg4);
    void method9(std::string arg0, bool arg1, unsigned arg2, float arg3, std::string const& arg4);
    void method10(short arg0, double arg1, bool arg2, int arg3, int arg4);
    void method11(std::string_view arg0, double arg1, int arg2, float arg3, std::string const& arg4);
    void method12(bool arg0, double arg1, int arg2, unsigned arg3, std::string_view arg4);
    void method13(float arg0, unsigned arg1, std::string arg2, std::string_view arg3, std::string const& arg4);
    void method14(unsigned arg0, unsigned arg1, float arg2, unsigned arg3, float arg4);
}
