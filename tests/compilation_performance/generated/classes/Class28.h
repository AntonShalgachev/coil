#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class28
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, unsigned arg1, std::string arg2, double arg3, unsigned arg4);
    void method1(float arg0, double arg1, std::string_view arg2, std::string_view arg3, float arg4);
    void method2(unsigned arg0, short arg1, int arg2, std::string_view arg3, std::string const& arg4);
    void method3(std::string_view arg0, float arg1, std::string_view arg2, int arg3, int arg4);
    void method4(unsigned arg0, std::string_view arg1, double arg2, std::string arg3, std::string_view arg4);
    void method5(short arg0, int arg1, short arg2, bool arg3, short arg4);
    bool method6(float arg0, double arg1, bool arg2, std::string const& arg3, short arg4);
    unsigned method7(unsigned arg0, short arg1, float arg2, float arg3, int arg4);
    bool method8(std::string const& arg0, float arg1, bool arg2, bool arg3, double arg4);
    bool method9(std::string const& arg0, bool arg1, bool arg2, double arg3, bool arg4);
    short method10(short arg0, bool arg1, short arg2, bool arg3, double arg4);
    void method11(short arg0, float arg1, std::string const& arg2, double arg3, std::string_view arg4);
    void method12(float arg0, bool arg1, unsigned arg2, std::string arg3, unsigned arg4);
    void method13(int arg0, bool arg1, short arg2, short arg3, bool arg4);
    void method14(float arg0, std::string arg1, std::string arg2, std::string arg3, float arg4);
};

namespace ns_Class28
{
    void method0(double arg0, unsigned arg1, std::string arg2, double arg3, unsigned arg4);
    void method1(float arg0, double arg1, std::string_view arg2, std::string_view arg3, float arg4);
    void method2(unsigned arg0, short arg1, int arg2, std::string_view arg3, std::string const& arg4);
    void method3(std::string_view arg0, float arg1, std::string_view arg2, int arg3, int arg4);
    void method4(unsigned arg0, std::string_view arg1, double arg2, std::string arg3, std::string_view arg4);
    void method5(short arg0, int arg1, short arg2, bool arg3, short arg4);
    bool method6(float arg0, double arg1, bool arg2, std::string const& arg3, short arg4);
    unsigned method7(unsigned arg0, short arg1, float arg2, float arg3, int arg4);
    bool method8(std::string const& arg0, float arg1, bool arg2, bool arg3, double arg4);
    bool method9(std::string const& arg0, bool arg1, bool arg2, double arg3, bool arg4);
    short method10(short arg0, bool arg1, short arg2, bool arg3, double arg4);
    void method11(short arg0, float arg1, std::string const& arg2, double arg3, std::string_view arg4);
    void method12(float arg0, bool arg1, unsigned arg2, std::string arg3, unsigned arg4);
    void method13(int arg0, bool arg1, short arg2, short arg3, bool arg4);
    void method14(float arg0, std::string arg1, std::string arg2, std::string arg3, float arg4);
}
