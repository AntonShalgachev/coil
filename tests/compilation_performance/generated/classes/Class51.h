#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class51
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, short arg1, std::string const& arg2, unsigned arg3, std::string const& arg4);
    void method1(bool arg0, unsigned arg1, float arg2, unsigned arg3, short arg4);
    float method2(std::string arg0, int arg1, std::string arg2, float arg3, std::string_view arg4);
    void method3(float arg0, std::string arg1, int arg2, int arg3, std::string arg4);
    void method4(std::string const& arg0, std::string const& arg1, bool arg2, std::string_view arg3, unsigned arg4);
    short method5(std::string const& arg0, bool arg1, std::string arg2, short arg3, unsigned arg4);
    void method6(double arg0, unsigned arg1, std::string_view arg2, unsigned arg3, float arg4);
    bool method7(bool arg0, double arg1, bool arg2, std::string const& arg3, short arg4);
    void method8(bool arg0, double arg1, float arg2, double arg3, short arg4);
    short method9(int arg0, bool arg1, unsigned arg2, unsigned arg3, short arg4);
    void method10(float arg0, unsigned arg1, std::string arg2, std::string const& arg3, std::string_view arg4);
    int method11(bool arg0, int arg1, std::string const& arg2, short arg3, int arg4);
    void method12(unsigned arg0, std::string const& arg1, float arg2, short arg3, double arg4);
    bool method13(std::string_view arg0, bool arg1, std::string_view arg2, std::string arg3, unsigned arg4);
    double method14(double arg0, int arg1, double arg2, short arg3, float arg4);
};

namespace ns_Class51
{
    void method0(double arg0, short arg1, std::string const& arg2, unsigned arg3, std::string const& arg4);
    void method1(bool arg0, unsigned arg1, float arg2, unsigned arg3, short arg4);
    float method2(std::string arg0, int arg1, std::string arg2, float arg3, std::string_view arg4);
    void method3(float arg0, std::string arg1, int arg2, int arg3, std::string arg4);
    void method4(std::string const& arg0, std::string const& arg1, bool arg2, std::string_view arg3, unsigned arg4);
    short method5(std::string const& arg0, bool arg1, std::string arg2, short arg3, unsigned arg4);
    void method6(double arg0, unsigned arg1, std::string_view arg2, unsigned arg3, float arg4);
    bool method7(bool arg0, double arg1, bool arg2, std::string const& arg3, short arg4);
    void method8(bool arg0, double arg1, float arg2, double arg3, short arg4);
    short method9(int arg0, bool arg1, unsigned arg2, unsigned arg3, short arg4);
    void method10(float arg0, unsigned arg1, std::string arg2, std::string const& arg3, std::string_view arg4);
    int method11(bool arg0, int arg1, std::string const& arg2, short arg3, int arg4);
    void method12(unsigned arg0, std::string const& arg1, float arg2, short arg3, double arg4);
    bool method13(std::string_view arg0, bool arg1, std::string_view arg2, std::string arg3, unsigned arg4);
    double method14(double arg0, int arg1, double arg2, short arg3, float arg4);
}
