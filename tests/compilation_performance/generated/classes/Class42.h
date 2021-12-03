#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class42
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    bool method0(std::string const& arg0, std::string arg1, std::string_view arg2, bool arg3, std::string arg4);
    void method1(std::string const& arg0, double arg1, int arg2, float arg3, bool arg4);
    int method2(unsigned arg0, std::string const& arg1, double arg2, unsigned arg3, int arg4);
    short method3(double arg0, std::string_view arg1, float arg2, short arg3, std::string const& arg4);
    void method4(std::string arg0, float arg1, std::string_view arg2, double arg3, short arg4);
    bool method5(std::string arg0, bool arg1, std::string arg2, float arg3, short arg4);
    bool method6(int arg0, float arg1, bool arg2, std::string const& arg3, short arg4);
    short method7(short arg0, bool arg1, double arg2, bool arg3, int arg4);
    void method8(float arg0, bool arg1, std::string const& arg2, short arg3, std::string_view arg4);
    void method9(double arg0, unsigned arg1, unsigned arg2, std::string const& arg3, bool arg4);
    void method10(float arg0, std::string_view arg1, double arg2, std::string arg3, int arg4);
    short method11(float arg0, unsigned arg1, short arg2, short arg3, float arg4);
    float method12(float arg0, float arg1, float arg2, bool arg3, unsigned arg4);
    void method13(std::string arg0, int arg1, std::string const& arg2, int arg3, int arg4);
    void method14(unsigned arg0, int arg1, unsigned arg2, std::string arg3, unsigned arg4);
};

namespace ns_Class42
{
    bool method0(std::string const& arg0, std::string arg1, std::string_view arg2, bool arg3, std::string arg4);
    void method1(std::string const& arg0, double arg1, int arg2, float arg3, bool arg4);
    int method2(unsigned arg0, std::string const& arg1, double arg2, unsigned arg3, int arg4);
    short method3(double arg0, std::string_view arg1, float arg2, short arg3, std::string const& arg4);
    void method4(std::string arg0, float arg1, std::string_view arg2, double arg3, short arg4);
    bool method5(std::string arg0, bool arg1, std::string arg2, float arg3, short arg4);
    bool method6(int arg0, float arg1, bool arg2, std::string const& arg3, short arg4);
    short method7(short arg0, bool arg1, double arg2, bool arg3, int arg4);
    void method8(float arg0, bool arg1, std::string const& arg2, short arg3, std::string_view arg4);
    void method9(double arg0, unsigned arg1, unsigned arg2, std::string const& arg3, bool arg4);
    void method10(float arg0, std::string_view arg1, double arg2, std::string arg3, int arg4);
    short method11(float arg0, unsigned arg1, short arg2, short arg3, float arg4);
    float method12(float arg0, float arg1, float arg2, bool arg3, unsigned arg4);
    void method13(std::string arg0, int arg1, std::string const& arg2, int arg3, int arg4);
    void method14(unsigned arg0, int arg1, unsigned arg2, std::string arg3, unsigned arg4);
}
