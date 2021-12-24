#pragma once

// Generated with seed '88005553614'

#include "../../Common.h"

#include "ClassWithBindings2.h"
#include "ClassWithBindings4.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings8.h"
#include "ClassWithBindings11.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings22.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings97.h"
#include "ClassWithBindings99.h"

class ClassWithBindings79
{
public:
    void work();

#if USE_COIL
    void registerBindings(coil::Bindings& bindings);
#endif

#if USE_MANUAL
    void registerBindings(DumbBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(double arg0, double arg1, bool arg2, double arg3, double arg4);
    void method1(float arg0, short arg1, short arg2, short arg3, int arg4);
    void method2(double arg0, float arg1, short arg2, int arg3, double arg4);
    void method3(unsigned arg0, short arg1, unsigned arg2, bool arg3, bool arg4);
    float method4(float arg0, bool arg1, bool arg2, unsigned arg3, float arg4);
    void method5(short arg0, bool arg1, unsigned arg2, int arg3, int arg4);
    void method6(bool arg0, double arg1, short arg2, short arg3, int arg4);
    unsigned method7(short arg0, unsigned arg1, double arg2, unsigned arg3, bool arg4);
    void method8(double arg0, unsigned arg1, unsigned arg2, bool arg3, int arg4);
    unsigned method9(double arg0, unsigned arg1, double arg2, bool arg3, int arg4);
    double method10(int arg0, int arg1, double arg2, double arg3, double arg4);
    float method11(float arg0, float arg1, int arg2, bool arg3, double arg4);
    void method12(bool arg0, short arg1, int arg2, int arg3, short arg4);
    void method13(bool arg0, float arg1, unsigned arg2, short arg3, short arg4);
    void method14(bool arg0, bool arg1, int arg2, short arg3, short arg4);

    int memberVariable0{};
    unsigned memberVariable1{};
    unsigned memberVariable2{};
    float memberVariable3{};
    short memberVariable4{};
    int memberVariable5{};
    float memberVariable6{};
    bool memberVariable7{};
    double memberVariable8{};
    bool memberVariable9{};
    double memberVariable10{};
    float memberVariable11{};
    double memberVariable12{};
    int memberVariable13{};
    bool memberVariable14{};

    static void function0(int arg0, unsigned arg1, float arg2, float arg3, int arg4);
    static unsigned function1(float arg0, unsigned arg1, int arg2, float arg3, bool arg4);
    static void function2(float arg0, double arg1, double arg2, int arg3, float arg4);
    static void function3(short arg0, short arg1, short arg2, bool arg3, unsigned arg4);
    static float function4(int arg0, unsigned arg1, double arg2, double arg3, float arg4);
    static float function5(double arg0, short arg1, float arg2, float arg3, float arg4);
    static float function6(double arg0, short arg1, unsigned arg2, bool arg3, float arg4);
    static short function7(unsigned arg0, short arg1, unsigned arg2, int arg3, double arg4);
    static void function8(double arg0, int arg1, unsigned arg2, short arg3, unsigned arg4);
    static int function9(bool arg0, float arg1, bool arg2, int arg3, float arg4);
    static bool function10(float arg0, bool arg1, short arg2, int arg3, double arg4);
    static void function11(float arg0, short arg1, double arg2, int arg3, float arg4);
    static unsigned function12(short arg0, unsigned arg1, short arg2, short arg3, unsigned arg4);
    static int function13(double arg0, double arg1, int arg2, float arg3, double arg4);
    static void function14(double arg0, double arg1, short arg2, bool arg3, float arg4);

    inline static float variable0{};
    inline static float variable1{};
    inline static int variable2{};
    inline static double variable3{};
    inline static bool variable4{};
    inline static float variable5{};
    inline static float variable6{};
    inline static float variable7{};
    inline static short variable8{};
    inline static float variable9{};
    inline static float variable10{};
    inline static bool variable11{};
    inline static short variable12{};
    inline static float variable13{};
    inline static bool variable14{};

#if USE_MANUAL
    std::string method0Command(std::vector<std::string> const& arguments);
    std::string method1Command(std::vector<std::string> const& arguments);
    std::string method2Command(std::vector<std::string> const& arguments);
    std::string method3Command(std::vector<std::string> const& arguments);
    std::string method4Command(std::vector<std::string> const& arguments);
    std::string method5Command(std::vector<std::string> const& arguments);
    std::string method6Command(std::vector<std::string> const& arguments);
    std::string method7Command(std::vector<std::string> const& arguments);
    std::string method8Command(std::vector<std::string> const& arguments);
    std::string method9Command(std::vector<std::string> const& arguments);
    std::string method10Command(std::vector<std::string> const& arguments);
    std::string method11Command(std::vector<std::string> const& arguments);
    std::string method12Command(std::vector<std::string> const& arguments);
    std::string method13Command(std::vector<std::string> const& arguments);
    std::string method14Command(std::vector<std::string> const& arguments);

    std::string memberVariable0Command(std::vector<std::string> const& arguments);
    std::string memberVariable1Command(std::vector<std::string> const& arguments);
    std::string memberVariable2Command(std::vector<std::string> const& arguments);
    std::string memberVariable3Command(std::vector<std::string> const& arguments);
    std::string memberVariable4Command(std::vector<std::string> const& arguments);
    std::string memberVariable5Command(std::vector<std::string> const& arguments);
    std::string memberVariable6Command(std::vector<std::string> const& arguments);
    std::string memberVariable7Command(std::vector<std::string> const& arguments);
    std::string memberVariable8Command(std::vector<std::string> const& arguments);
    std::string memberVariable9Command(std::vector<std::string> const& arguments);
    std::string memberVariable10Command(std::vector<std::string> const& arguments);
    std::string memberVariable11Command(std::vector<std::string> const& arguments);
    std::string memberVariable12Command(std::vector<std::string> const& arguments);
    std::string memberVariable13Command(std::vector<std::string> const& arguments);
    std::string memberVariable14Command(std::vector<std::string> const& arguments);

    static std::string function0Command(std::vector<std::string> const& arguments);
    static std::string function1Command(std::vector<std::string> const& arguments);
    static std::string function2Command(std::vector<std::string> const& arguments);
    static std::string function3Command(std::vector<std::string> const& arguments);
    static std::string function4Command(std::vector<std::string> const& arguments);
    static std::string function5Command(std::vector<std::string> const& arguments);
    static std::string function6Command(std::vector<std::string> const& arguments);
    static std::string function7Command(std::vector<std::string> const& arguments);
    static std::string function8Command(std::vector<std::string> const& arguments);
    static std::string function9Command(std::vector<std::string> const& arguments);
    static std::string function10Command(std::vector<std::string> const& arguments);
    static std::string function11Command(std::vector<std::string> const& arguments);
    static std::string function12Command(std::vector<std::string> const& arguments);
    static std::string function13Command(std::vector<std::string> const& arguments);
    static std::string function14Command(std::vector<std::string> const& arguments);

    static std::string variable0Command(std::vector<std::string> const& arguments);
    static std::string variable1Command(std::vector<std::string> const& arguments);
    static std::string variable2Command(std::vector<std::string> const& arguments);
    static std::string variable3Command(std::vector<std::string> const& arguments);
    static std::string variable4Command(std::vector<std::string> const& arguments);
    static std::string variable5Command(std::vector<std::string> const& arguments);
    static std::string variable6Command(std::vector<std::string> const& arguments);
    static std::string variable7Command(std::vector<std::string> const& arguments);
    static std::string variable8Command(std::vector<std::string> const& arguments);
    static std::string variable9Command(std::vector<std::string> const& arguments);
    static std::string variable10Command(std::vector<std::string> const& arguments);
    static std::string variable11Command(std::vector<std::string> const& arguments);
    static std::string variable12Command(std::vector<std::string> const& arguments);
    static std::string variable13Command(std::vector<std::string> const& arguments);
    static std::string variable14Command(std::vector<std::string> const& arguments);
#endif
};
