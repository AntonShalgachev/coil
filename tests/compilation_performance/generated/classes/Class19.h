#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class19
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(int arg0, unsigned arg1, unsigned arg2, int arg3, std::string arg4);
    short method1(float arg0, std::string_view arg1, short arg2, bool arg3, short arg4);
    float method2(std::string_view arg0, unsigned arg1, float arg2, int arg3, float arg4);
    bool method3(unsigned arg0, float arg1, bool arg2, bool arg3, std::string_view arg4);
    bool method4(unsigned arg0, unsigned arg1, double arg2, bool arg3, std::string const& arg4);
    void method5(std::string arg0, std::string_view arg1, float arg2, bool arg3, std::string const& arg4);
    void method6(bool arg0, double arg1, short arg2, float arg3, bool arg4);
    std::string_view method7(unsigned arg0, std::string_view arg1, std::string arg2, unsigned arg3, std::string arg4);
    float method8(double arg0, short arg1, float arg2, int arg3, bool arg4);
    void method9(std::string const& arg0, std::string arg1, short arg2, bool arg3, float arg4);
    void method10(std::string arg0, float arg1, short arg2, short arg3, bool arg4);
    void method11(double arg0, unsigned arg1, bool arg2, int arg3, short arg4);
    void method12(int arg0, std::string arg1, float arg2, float arg3, short arg4);
    void method13(std::string arg0, short arg1, int arg2, std::string const& arg3, unsigned arg4);
    void method14(int arg0, float arg1, std::string const& arg2, bool arg3, short arg4);
};

namespace ns_Class19
{
    unsigned method0(int arg0, unsigned arg1, unsigned arg2, int arg3, std::string arg4);
    short method1(float arg0, std::string_view arg1, short arg2, bool arg3, short arg4);
    float method2(std::string_view arg0, unsigned arg1, float arg2, int arg3, float arg4);
    bool method3(unsigned arg0, float arg1, bool arg2, bool arg3, std::string_view arg4);
    bool method4(unsigned arg0, unsigned arg1, double arg2, bool arg3, std::string const& arg4);
    void method5(std::string arg0, std::string_view arg1, float arg2, bool arg3, std::string const& arg4);
    void method6(bool arg0, double arg1, short arg2, float arg3, bool arg4);
    std::string_view method7(unsigned arg0, std::string_view arg1, std::string arg2, unsigned arg3, std::string arg4);
    float method8(double arg0, short arg1, float arg2, int arg3, bool arg4);
    void method9(std::string const& arg0, std::string arg1, short arg2, bool arg3, float arg4);
    void method10(std::string arg0, float arg1, short arg2, short arg3, bool arg4);
    void method11(double arg0, unsigned arg1, bool arg2, int arg3, short arg4);
    void method12(int arg0, std::string arg1, float arg2, float arg3, short arg4);
    void method13(std::string arg0, short arg1, int arg2, std::string const& arg3, unsigned arg4);
    void method14(int arg0, float arg1, std::string const& arg2, bool arg3, short arg4);
}
