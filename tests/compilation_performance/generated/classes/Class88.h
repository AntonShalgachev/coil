#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class88
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(std::string const& arg0, std::string arg1, std::string arg2, std::string_view arg3, std::string_view arg4);
    short method1(short arg0, short arg1, short arg2, double arg3, short arg4);
    void method2(int arg0, std::string const& arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method3(unsigned arg0, unsigned arg1, unsigned arg2, bool arg3, bool arg4);
    std::string method4(std::string const& arg0, std::string arg1, double arg2, std::string const& arg3, short arg4);
    short method5(double arg0, short arg1, bool arg2, double arg3, short arg4);
    bool method6(double arg0, bool arg1, std::string arg2, short arg3, int arg4);
    unsigned method7(std::string const& arg0, bool arg1, double arg2, double arg3, unsigned arg4);
    void method8(short arg0, short arg1, unsigned arg2, std::string const& arg3, std::string arg4);
    void method9(int arg0, bool arg1, std::string const& arg2, bool arg3, short arg4);
    float method10(float arg0, int arg1, int arg2, float arg3, float arg4);
    float method11(std::string_view arg0, float arg1, double arg2, std::string_view arg3, int arg4);
    bool method12(bool arg0, bool arg1, unsigned arg2, short arg3, std::string const& arg4);
    void method13(bool arg0, float arg1, std::string arg2, float arg3, bool arg4);
    std::string_view method14(std::string const& arg0, double arg1, bool arg2, std::string_view arg3, bool arg4);
};

namespace ns_Class88
{
    void method0(std::string const& arg0, std::string arg1, std::string arg2, std::string_view arg3, std::string_view arg4);
    short method1(short arg0, short arg1, short arg2, double arg3, short arg4);
    void method2(int arg0, std::string const& arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method3(unsigned arg0, unsigned arg1, unsigned arg2, bool arg3, bool arg4);
    std::string method4(std::string const& arg0, std::string arg1, double arg2, std::string const& arg3, short arg4);
    short method5(double arg0, short arg1, bool arg2, double arg3, short arg4);
    bool method6(double arg0, bool arg1, std::string arg2, short arg3, int arg4);
    unsigned method7(std::string const& arg0, bool arg1, double arg2, double arg3, unsigned arg4);
    void method8(short arg0, short arg1, unsigned arg2, std::string const& arg3, std::string arg4);
    void method9(int arg0, bool arg1, std::string const& arg2, bool arg3, short arg4);
    float method10(float arg0, int arg1, int arg2, float arg3, float arg4);
    float method11(std::string_view arg0, float arg1, double arg2, std::string_view arg3, int arg4);
    bool method12(bool arg0, bool arg1, unsigned arg2, short arg3, std::string const& arg4);
    void method13(bool arg0, float arg1, std::string arg2, float arg3, bool arg4);
    std::string_view method14(std::string const& arg0, double arg1, bool arg2, std::string_view arg3, bool arg4);
}
