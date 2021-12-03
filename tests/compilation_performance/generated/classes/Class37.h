#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class37
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(short arg0, double arg1, std::string const& arg2, bool arg3, bool arg4);
    bool method1(unsigned arg0, bool arg1, std::string_view arg2, std::string_view arg3, std::string_view arg4);
    void method2(short arg0, unsigned arg1, float arg2, bool arg3, std::string arg4);
    void method3(std::string arg0, short arg1, std::string const& arg2, std::string arg3, bool arg4);
    void method4(short arg0, bool arg1, std::string const& arg2, unsigned arg3, double arg4);
    void method5(std::string_view arg0, bool arg1, bool arg2, double arg3, bool arg4);
    bool method6(double arg0, std::string arg1, double arg2, bool arg3, std::string const& arg4);
    void method7(int arg0, std::string arg1, std::string arg2, double arg3, short arg4);
    bool method8(bool arg0, int arg1, std::string const& arg2, short arg3, short arg4);
    void method9(float arg0, unsigned arg1, bool arg2, short arg3, std::string arg4);
    double method10(int arg0, std::string const& arg1, double arg2, int arg3, short arg4);
    void method11(bool arg0, std::string_view arg1, float arg2, short arg3, short arg4);
    void method12(int arg0, short arg1, short arg2, std::string const& arg3, unsigned arg4);
    std::string method13(unsigned arg0, unsigned arg1, std::string_view arg2, double arg3, std::string arg4);
    std::string method14(short arg0, std::string arg1, std::string arg2, std::string arg3, int arg4);
};

namespace ns_Class37
{
    double method0(short arg0, double arg1, std::string const& arg2, bool arg3, bool arg4);
    bool method1(unsigned arg0, bool arg1, std::string_view arg2, std::string_view arg3, std::string_view arg4);
    void method2(short arg0, unsigned arg1, float arg2, bool arg3, std::string arg4);
    void method3(std::string arg0, short arg1, std::string const& arg2, std::string arg3, bool arg4);
    void method4(short arg0, bool arg1, std::string const& arg2, unsigned arg3, double arg4);
    void method5(std::string_view arg0, bool arg1, bool arg2, double arg3, bool arg4);
    bool method6(double arg0, std::string arg1, double arg2, bool arg3, std::string const& arg4);
    void method7(int arg0, std::string arg1, std::string arg2, double arg3, short arg4);
    bool method8(bool arg0, int arg1, std::string const& arg2, short arg3, short arg4);
    void method9(float arg0, unsigned arg1, bool arg2, short arg3, std::string arg4);
    double method10(int arg0, std::string const& arg1, double arg2, int arg3, short arg4);
    void method11(bool arg0, std::string_view arg1, float arg2, short arg3, short arg4);
    void method12(int arg0, short arg1, short arg2, std::string const& arg3, unsigned arg4);
    std::string method13(unsigned arg0, unsigned arg1, std::string_view arg2, double arg3, std::string arg4);
    std::string method14(short arg0, std::string arg1, std::string arg2, std::string arg3, int arg4);
}
