#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class52
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(float arg0, std::string const& arg1, short arg2, std::string const& arg3, int arg4);
    void method1(double arg0, int arg1, int arg2, unsigned arg3, int arg4);
    void method2(short arg0, float arg1, std::string const& arg2, std::string const& arg3, int arg4);
    void method3(int arg0, short arg1, float arg2, float arg3, double arg4);
    void method4(short arg0, std::string arg1, std::string arg2, double arg3, short arg4);
    void method5(int arg0, std::string_view arg1, std::string const& arg2, std::string arg3, double arg4);
    void method6(int arg0, float arg1, int arg2, std::string const& arg3, std::string_view arg4);
    unsigned method7(unsigned arg0, std::string_view arg1, bool arg2, unsigned arg3, unsigned arg4);
    double method8(double arg0, double arg1, float arg2, std::string arg3, int arg4);
    short method9(float arg0, unsigned arg1, double arg2, short arg3, short arg4);
    bool method10(bool arg0, unsigned arg1, float arg2, bool arg3, unsigned arg4);
    bool method11(std::string arg0, unsigned arg1, bool arg2, std::string_view arg3, double arg4);
    unsigned method12(short arg0, std::string arg1, unsigned arg2, unsigned arg3, int arg4);
    void method13(double arg0, std::string arg1, unsigned arg2, bool arg3, bool arg4);
    void method14(int arg0, bool arg1, std::string arg2, int arg3, int arg4);
};

namespace ns_Class52
{
    short method0(float arg0, std::string const& arg1, short arg2, std::string const& arg3, int arg4);
    void method1(double arg0, int arg1, int arg2, unsigned arg3, int arg4);
    void method2(short arg0, float arg1, std::string const& arg2, std::string const& arg3, int arg4);
    void method3(int arg0, short arg1, float arg2, float arg3, double arg4);
    void method4(short arg0, std::string arg1, std::string arg2, double arg3, short arg4);
    void method5(int arg0, std::string_view arg1, std::string const& arg2, std::string arg3, double arg4);
    void method6(int arg0, float arg1, int arg2, std::string const& arg3, std::string_view arg4);
    unsigned method7(unsigned arg0, std::string_view arg1, bool arg2, unsigned arg3, unsigned arg4);
    double method8(double arg0, double arg1, float arg2, std::string arg3, int arg4);
    short method9(float arg0, unsigned arg1, double arg2, short arg3, short arg4);
    bool method10(bool arg0, unsigned arg1, float arg2, bool arg3, unsigned arg4);
    bool method11(std::string arg0, unsigned arg1, bool arg2, std::string_view arg3, double arg4);
    unsigned method12(short arg0, std::string arg1, unsigned arg2, unsigned arg3, int arg4);
    void method13(double arg0, std::string arg1, unsigned arg2, bool arg3, bool arg4);
    void method14(int arg0, bool arg1, std::string arg2, int arg3, int arg4);
}
