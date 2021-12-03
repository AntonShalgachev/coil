#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class94
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(std::string_view arg0, bool arg1, bool arg2, short arg3, short arg4);
    int method1(int arg0, std::string const& arg1, int arg2, unsigned arg3, unsigned arg4);
    float method2(std::string arg0, short arg1, double arg2, bool arg3, float arg4);
    void method3(short arg0, std::string_view arg1, float arg2, short arg3, float arg4);
    void method4(bool arg0, int arg1, unsigned arg2, std::string const& arg3, std::string const& arg4);
    bool method5(double arg0, short arg1, short arg2, bool arg3, short arg4);
    int method6(int arg0, std::string const& arg1, short arg2, float arg3, bool arg4);
    double method7(float arg0, double arg1, int arg2, unsigned arg3, float arg4);
    short method8(bool arg0, std::string arg1, float arg2, short arg3, float arg4);
    std::string method9(short arg0, unsigned arg1, std::string arg2, int arg3, float arg4);
    std::string method10(unsigned arg0, std::string const& arg1, int arg2, int arg3, std::string arg4);
    int method11(float arg0, float arg1, std::string arg2, int arg3, std::string_view arg4);
    void method12(double arg0, unsigned arg1, double arg2, short arg3, bool arg4);
    unsigned method13(std::string_view arg0, unsigned arg1, std::string arg2, float arg3, short arg4);
    std::string const& method14(float arg0, bool arg1, std::string arg2, unsigned arg3, std::string const& arg4);
};

namespace ns_Class94
{
    void method0(std::string_view arg0, bool arg1, bool arg2, short arg3, short arg4);
    int method1(int arg0, std::string const& arg1, int arg2, unsigned arg3, unsigned arg4);
    float method2(std::string arg0, short arg1, double arg2, bool arg3, float arg4);
    void method3(short arg0, std::string_view arg1, float arg2, short arg3, float arg4);
    void method4(bool arg0, int arg1, unsigned arg2, std::string const& arg3, std::string const& arg4);
    bool method5(double arg0, short arg1, short arg2, bool arg3, short arg4);
    int method6(int arg0, std::string const& arg1, short arg2, float arg3, bool arg4);
    double method7(float arg0, double arg1, int arg2, unsigned arg3, float arg4);
    short method8(bool arg0, std::string arg1, float arg2, short arg3, float arg4);
    std::string method9(short arg0, unsigned arg1, std::string arg2, int arg3, float arg4);
    std::string method10(unsigned arg0, std::string const& arg1, int arg2, int arg3, std::string arg4);
    int method11(float arg0, float arg1, std::string arg2, int arg3, std::string_view arg4);
    void method12(double arg0, unsigned arg1, double arg2, short arg3, bool arg4);
    unsigned method13(std::string_view arg0, unsigned arg1, std::string arg2, float arg3, short arg4);
    std::string const& method14(float arg0, bool arg1, std::string arg2, unsigned arg3, std::string const& arg4);
}
