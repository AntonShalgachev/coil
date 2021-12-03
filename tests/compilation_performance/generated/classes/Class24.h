#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class24
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(short arg0, std::string const& arg1, std::string arg2, int arg3, double arg4);
    std::string method1(int arg0, float arg1, std::string arg2, float arg3, int arg4);
    float method2(short arg0, bool arg1, float arg2, std::string arg3, double arg4);
    short method3(bool arg0, int arg1, short arg2, std::string const& arg3, int arg4);
    double method4(double arg0, int arg1, std::string const& arg2, float arg3, double arg4);
    void method5(std::string arg0, int arg1, float arg2, int arg3, std::string_view arg4);
    std::string method6(bool arg0, float arg1, std::string arg2, std::string const& arg3, short arg4);
    short method7(short arg0, unsigned arg1, std::string arg2, bool arg3, bool arg4);
    void method8(int arg0, float arg1, std::string const& arg2, int arg3, unsigned arg4);
    bool method9(short arg0, bool arg1, unsigned arg2, float arg3, std::string_view arg4);
    bool method10(bool arg0, unsigned arg1, std::string_view arg2, std::string_view arg3, unsigned arg4);
    void method11(std::string_view arg0, bool arg1, std::string_view arg2, double arg3, double arg4);
    short method12(short arg0, double arg1, bool arg2, std::string_view arg3, std::string const& arg4);
    void method13(std::string const& arg0, float arg1, double arg2, int arg3, short arg4);
    std::string method14(std::string arg0, double arg1, double arg2, short arg3, unsigned arg4);
};

namespace ns_Class24
{
    double method0(short arg0, std::string const& arg1, std::string arg2, int arg3, double arg4);
    std::string method1(int arg0, float arg1, std::string arg2, float arg3, int arg4);
    float method2(short arg0, bool arg1, float arg2, std::string arg3, double arg4);
    short method3(bool arg0, int arg1, short arg2, std::string const& arg3, int arg4);
    double method4(double arg0, int arg1, std::string const& arg2, float arg3, double arg4);
    void method5(std::string arg0, int arg1, float arg2, int arg3, std::string_view arg4);
    std::string method6(bool arg0, float arg1, std::string arg2, std::string const& arg3, short arg4);
    short method7(short arg0, unsigned arg1, std::string arg2, bool arg3, bool arg4);
    void method8(int arg0, float arg1, std::string const& arg2, int arg3, unsigned arg4);
    bool method9(short arg0, bool arg1, unsigned arg2, float arg3, std::string_view arg4);
    bool method10(bool arg0, unsigned arg1, std::string_view arg2, std::string_view arg3, unsigned arg4);
    void method11(std::string_view arg0, bool arg1, std::string_view arg2, double arg3, double arg4);
    short method12(short arg0, double arg1, bool arg2, std::string_view arg3, std::string const& arg4);
    void method13(std::string const& arg0, float arg1, double arg2, int arg3, short arg4);
    std::string method14(std::string arg0, double arg1, double arg2, short arg3, unsigned arg4);
}
