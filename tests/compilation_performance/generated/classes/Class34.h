#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class34
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    void method1(unsigned arg0, double arg1, std::string const& arg2, unsigned arg3, short arg4);
    void method2(int arg0, bool arg1, std::string const& arg2, float arg3, double arg4);
    void method3(int arg0, int arg1, std::string const& arg2, bool arg3, bool arg4);
    void method4(float arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
    void method5(short arg0, std::string arg1, short arg2, std::string arg3, float arg4);
    bool method6(std::string const& arg0, double arg1, bool arg2, std::string const& arg3, float arg4);
    void method7(short arg0, int arg1, std::string_view arg2, int arg3, short arg4);
    void method8(bool arg0, int arg1, std::string_view arg2, std::string const& arg3, short arg4);
    void method9(float arg0, bool arg1, int arg2, std::string const& arg3, std::string arg4);
    void method10(std::string const& arg0, double arg1, int arg2, std::string const& arg3, short arg4);
    double method11(int arg0, float arg1, std::string const& arg2, int arg3, double arg4);
    void method12(float arg0, float arg1, float arg2, short arg3, int arg4);
    void method13(unsigned arg0, std::string_view arg1, double arg2, unsigned arg3, int arg4);
    void method14(std::string arg0, short arg1, int arg2, double arg3, double arg4);
};

namespace ns_Class34
{
    void method0(short arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    void method1(unsigned arg0, double arg1, std::string const& arg2, unsigned arg3, short arg4);
    void method2(int arg0, bool arg1, std::string const& arg2, float arg3, double arg4);
    void method3(int arg0, int arg1, std::string const& arg2, bool arg3, bool arg4);
    void method4(float arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
    void method5(short arg0, std::string arg1, short arg2, std::string arg3, float arg4);
    bool method6(std::string const& arg0, double arg1, bool arg2, std::string const& arg3, float arg4);
    void method7(short arg0, int arg1, std::string_view arg2, int arg3, short arg4);
    void method8(bool arg0, int arg1, std::string_view arg2, std::string const& arg3, short arg4);
    void method9(float arg0, bool arg1, int arg2, std::string const& arg3, std::string arg4);
    void method10(std::string const& arg0, double arg1, int arg2, std::string const& arg3, short arg4);
    double method11(int arg0, float arg1, std::string const& arg2, int arg3, double arg4);
    void method12(float arg0, float arg1, float arg2, short arg3, int arg4);
    void method13(unsigned arg0, std::string_view arg1, double arg2, unsigned arg3, int arg4);
    void method14(std::string arg0, short arg1, int arg2, double arg3, double arg4);
}
