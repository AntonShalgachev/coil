#pragma once

// Generated with seed '88005553595'

#include "../../Common.h"

#include "ClassWithBindings1.h"
#include "ClassWithBindings2.h"
#include "ClassWithBindings6.h"
#include "ClassWithBindings11.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings18.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings81.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings96.h"
#include "ClassWithBindings98.h"

class ClassWithBindings60
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
    void method0(int arg0, double arg1, int arg2, unsigned arg3, double arg4);
    void method1(double arg0, int arg1, int arg2, int arg3, unsigned arg4);
    short method2(int arg0, short arg1, unsigned arg2, unsigned arg3, double arg4);
    unsigned method3(bool arg0, double arg1, float arg2, unsigned arg3, int arg4);
    double method4(short arg0, short arg1, unsigned arg2, unsigned arg3, double arg4);
    void method5(short arg0, unsigned arg1, float arg2, float arg3, double arg4);
    unsigned method6(unsigned arg0, short arg1, unsigned arg2, short arg3, short arg4);
    void method7(unsigned arg0, double arg1, short arg2, int arg3, int arg4);
    int method8(unsigned arg0, int arg1, int arg2, int arg3, double arg4);
    float method9(bool arg0, bool arg1, float arg2, unsigned arg3, int arg4);
    int method10(int arg0, float arg1, int arg2, short arg3, bool arg4);
    void method11(double arg0, double arg1, short arg2, bool arg3, double arg4);
    short method12(float arg0, short arg1, short arg2, bool arg3, short arg4);
    void method13(double arg0, float arg1, unsigned arg2, bool arg3, short arg4);
    void method14(double arg0, bool arg1, short arg2, float arg3, bool arg4);

    float memberVariable0{};
    float memberVariable1{};
    bool memberVariable2{};
    bool memberVariable3{};
    bool memberVariable4{};
    bool memberVariable5{};
    short memberVariable6{};
    double memberVariable7{};
    float memberVariable8{};
    unsigned memberVariable9{};
    bool memberVariable10{};
    short memberVariable11{};
    float memberVariable12{};
    bool memberVariable13{};
    double memberVariable14{};

    static int function0(float arg0, int arg1, short arg2, float arg3, double arg4);
    static void function1(short arg0, int arg1, int arg2, short arg3, short arg4);
    static void function2(float arg0, bool arg1, unsigned arg2, bool arg3, bool arg4);
    static int function3(double arg0, int arg1, bool arg2, double arg3, int arg4);
    static float function4(bool arg0, bool arg1, float arg2, float arg3, bool arg4);
    static void function5(double arg0, int arg1, int arg2, unsigned arg3, double arg4);
    static double function6(int arg0, double arg1, short arg2, bool arg3, double arg4);
    static bool function7(bool arg0, bool arg1, short arg2, double arg3, bool arg4);
    static float function8(float arg0, int arg1, short arg2, bool arg3, bool arg4);
    static double function9(bool arg0, double arg1, int arg2, short arg3, short arg4);
    static void function10(unsigned arg0, bool arg1, short arg2, double arg3, double arg4);
    static void function11(float arg0, bool arg1, short arg2, float arg3, double arg4);
    static int function12(float arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    static void function13(int arg0, int arg1, bool arg2, unsigned arg3, short arg4);
    static void function14(int arg0, short arg1, float arg2, float arg3, double arg4);

    inline static float variable0{};
    inline static int variable1{};
    inline static float variable2{};
    inline static double variable3{};
    inline static short variable4{};
    inline static double variable5{};
    inline static unsigned variable6{};
    inline static short variable7{};
    inline static short variable8{};
    inline static float variable9{};
    inline static unsigned variable10{};
    inline static unsigned variable11{};
    inline static unsigned variable12{};
    inline static float variable13{};
    inline static float variable14{};

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
