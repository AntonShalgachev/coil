#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class67
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(unsigned arg0, bool arg1, std::string arg2, short arg3, double arg4);
    bool method1(bool arg0, int arg1, bool arg2, int arg3, bool arg4);
    bool method2(bool arg0, int arg1, std::string arg2, std::string_view arg3, short arg4);
    std::string_view method3(short arg0, short arg1, std::string_view arg2, unsigned arg3, unsigned arg4);
    void method4(double arg0, std::string_view arg1, int arg2, std::string arg3, std::string_view arg4);
    void method5(std::string_view arg0, bool arg1, int arg2, std::string const& arg3, bool arg4);
    short method6(short arg0, std::string const& arg1, short arg2, double arg3, std::string const& arg4);
    std::string method7(short arg0, int arg1, bool arg2, std::string arg3, bool arg4);
    void method8(bool arg0, short arg1, std::string const& arg2, unsigned arg3, double arg4);
    bool method9(int arg0, float arg1, bool arg2, short arg3, short arg4);
    void method10(unsigned arg0, std::string arg1, float arg2, short arg3, std::string_view arg4);
    void method11(unsigned arg0, unsigned arg1, unsigned arg2, float arg3, bool arg4);
    void method12(int arg0, std::string const& arg1, bool arg2, short arg3, short arg4);
    void method13(std::string arg0, std::string_view arg1, std::string_view arg2, float arg3, std::string_view arg4);
    float method14(unsigned arg0, std::string_view arg1, unsigned arg2, float arg3, unsigned arg4);
};

namespace ns_Class67
{
    double method0(unsigned arg0, bool arg1, std::string arg2, short arg3, double arg4);
    bool method1(bool arg0, int arg1, bool arg2, int arg3, bool arg4);
    bool method2(bool arg0, int arg1, std::string arg2, std::string_view arg3, short arg4);
    std::string_view method3(short arg0, short arg1, std::string_view arg2, unsigned arg3, unsigned arg4);
    void method4(double arg0, std::string_view arg1, int arg2, std::string arg3, std::string_view arg4);
    void method5(std::string_view arg0, bool arg1, int arg2, std::string const& arg3, bool arg4);
    short method6(short arg0, std::string const& arg1, short arg2, double arg3, std::string const& arg4);
    std::string method7(short arg0, int arg1, bool arg2, std::string arg3, bool arg4);
    void method8(bool arg0, short arg1, std::string const& arg2, unsigned arg3, double arg4);
    bool method9(int arg0, float arg1, bool arg2, short arg3, short arg4);
    void method10(unsigned arg0, std::string arg1, float arg2, short arg3, std::string_view arg4);
    void method11(unsigned arg0, unsigned arg1, unsigned arg2, float arg3, bool arg4);
    void method12(int arg0, std::string const& arg1, bool arg2, short arg3, short arg4);
    void method13(std::string arg0, std::string_view arg1, std::string_view arg2, float arg3, std::string_view arg4);
    float method14(unsigned arg0, std::string_view arg1, unsigned arg2, float arg3, unsigned arg4);
}
