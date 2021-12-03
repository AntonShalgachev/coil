#pragma once
#include <vector>
#include <string>
#include <string_view>
#include <optional>

#include "../../Common.h"

class Class89
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    float method0(int arg0, float arg1, float arg2, double arg3, unsigned arg4);
    void method1(unsigned arg0, std::string_view arg1, std::string_view arg2, int arg3, bool arg4);
    void method2(unsigned arg0, std::string_view arg1, short arg2, std::string_view arg3, short arg4);
    std::string_view method3(float arg0, bool arg1, int arg2, unsigned arg3, std::string_view arg4);
    void method4(bool arg0, bool arg1, bool arg2, std::string_view arg3, double arg4);
    void method5(short arg0, unsigned arg1, double arg2, bool arg3, unsigned arg4);
    void method6(int arg0, int arg1, bool arg2, std::string_view arg3, short arg4);
    std::string_view method7(float arg0, int arg1, std::string_view arg2, float arg3, bool arg4);
    bool method8(bool arg0, short arg1, double arg2, std::string const& arg3, short arg4);
    void method9(std::string const& arg0, short arg1, int arg2, double arg3, std::string const& arg4);
    std::string const& method10(short arg0, unsigned arg1, short arg2, std::string const& arg3, unsigned arg4);
    void method11(int arg0, short arg1, unsigned arg2, bool arg3, double arg4);
    bool method12(std::string const& arg0, std::string arg1, bool arg2, float arg3, float arg4);
    void method13(int arg0, std::string arg1, short arg2, unsigned arg3, unsigned arg4);
    void method14(std::string const& arg0, std::string const& arg1, std::string_view arg2, bool arg3, float arg4);
};

namespace ns_Class89
{
    float method0(int arg0, float arg1, float arg2, double arg3, unsigned arg4);
    void method1(unsigned arg0, std::string_view arg1, std::string_view arg2, int arg3, bool arg4);
    void method2(unsigned arg0, std::string_view arg1, short arg2, std::string_view arg3, short arg4);
    std::string_view method3(float arg0, bool arg1, int arg2, unsigned arg3, std::string_view arg4);
    void method4(bool arg0, bool arg1, bool arg2, std::string_view arg3, double arg4);
    void method5(short arg0, unsigned arg1, double arg2, bool arg3, unsigned arg4);
    void method6(int arg0, int arg1, bool arg2, std::string_view arg3, short arg4);
    std::string_view method7(float arg0, int arg1, std::string_view arg2, float arg3, bool arg4);
    bool method8(bool arg0, short arg1, double arg2, std::string const& arg3, short arg4);
    void method9(std::string const& arg0, short arg1, int arg2, double arg3, std::string const& arg4);
    std::string const& method10(short arg0, unsigned arg1, short arg2, std::string const& arg3, unsigned arg4);
    void method11(int arg0, short arg1, unsigned arg2, bool arg3, double arg4);
    bool method12(std::string const& arg0, std::string arg1, bool arg2, float arg3, float arg4);
    void method13(int arg0, std::string arg1, short arg2, unsigned arg3, unsigned arg4);
    void method14(std::string const& arg0, std::string const& arg1, std::string_view arg2, bool arg3, float arg4);
}
