#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class49
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(std::string_view arg0, std::string arg1, short arg2, std::string arg3, float arg4);
    void method1(int arg0, double arg1, std::string const& arg2, int arg3, std::string const& arg4);
    void method2(bool arg0, bool arg1, int arg2, short arg3, std::string const& arg4);
    void method3(short arg0, unsigned arg1, int arg2, bool arg3, bool arg4);
    void method4(bool arg0, short arg1, std::string const& arg2, unsigned arg3, short arg4);
    bool method5(bool arg0, std::string arg1, short arg2, double arg3, short arg4);
    double method6(float arg0, double arg1, std::string arg2, double arg3, double arg4);
    short method7(std::string arg0, short arg1, int arg2, float arg3, int arg4);
    void method8(int arg0, short arg1, double arg2, std::string_view arg3, int arg4);
    double method9(unsigned arg0, std::string arg1, int arg2, double arg3, std::string_view arg4);
    double method10(unsigned arg0, double arg1, std::string arg2, std::string_view arg3, double arg4);
    void method11(short arg0, std::string const& arg1, double arg2, std::string const& arg3, short arg4);
    float method12(int arg0, int arg1, float arg2, std::string_view arg3, float arg4);
    float method13(int arg0, int arg1, double arg2, std::string const& arg3, float arg4);
    void method14(short arg0, double arg1, int arg2, short arg3, float arg4);
};

namespace ns_Class49
{
    float method0(std::string_view arg0, std::string arg1, short arg2, std::string arg3, float arg4);
    void method1(int arg0, double arg1, std::string const& arg2, int arg3, std::string const& arg4);
    void method2(bool arg0, bool arg1, int arg2, short arg3, std::string const& arg4);
    void method3(short arg0, unsigned arg1, int arg2, bool arg3, bool arg4);
    void method4(bool arg0, short arg1, std::string const& arg2, unsigned arg3, short arg4);
    bool method5(bool arg0, std::string arg1, short arg2, double arg3, short arg4);
    double method6(float arg0, double arg1, std::string arg2, double arg3, double arg4);
    short method7(std::string arg0, short arg1, int arg2, float arg3, int arg4);
    void method8(int arg0, short arg1, double arg2, std::string_view arg3, int arg4);
    double method9(unsigned arg0, std::string arg1, int arg2, double arg3, std::string_view arg4);
    double method10(unsigned arg0, double arg1, std::string arg2, std::string_view arg3, double arg4);
    void method11(short arg0, std::string const& arg1, double arg2, std::string const& arg3, short arg4);
    float method12(int arg0, int arg1, float arg2, std::string_view arg3, float arg4);
    float method13(int arg0, int arg1, double arg2, std::string const& arg3, float arg4);
    void method14(short arg0, double arg1, int arg2, short arg3, float arg4);
}
