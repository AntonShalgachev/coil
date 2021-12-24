#pragma once

// Generated with seed '88005553632'

#include "../../Common.h"

#include "ClassWithBindings11.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings20.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings48.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings83.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings88.h"
#include "ClassWithBindings92.h"

class ClassWithBindings97
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
    void method0(int arg0, bool arg1, bool arg2, bool arg3, double arg4);
    void method1(double arg0, short arg1, unsigned arg2, unsigned arg3, short arg4);
    void method2(bool arg0, unsigned arg1, short arg2, bool arg3, int arg4);
    short method3(unsigned arg0, bool arg1, short arg2, double arg3, short arg4);
    void method4(double arg0, unsigned arg1, int arg2, short arg3, int arg4);
    void method5(bool arg0, short arg1, double arg2, short arg3, unsigned arg4);
    void method6(float arg0, float arg1, bool arg2, int arg3, bool arg4);
    int method7(int arg0, int arg1, float arg2, int arg3, int arg4);
    int method8(unsigned arg0, int arg1, bool arg2, int arg3, float arg4);
    unsigned method9(short arg0, unsigned arg1, unsigned arg2, bool arg3, unsigned arg4);
    void method10(float arg0, int arg1, bool arg2, unsigned arg3, bool arg4);
    unsigned method11(unsigned arg0, unsigned arg1, short arg2, float arg3, bool arg4);
    void method12(double arg0, double arg1, bool arg2, short arg3, int arg4);
    void method13(double arg0, bool arg1, float arg2, bool arg3, double arg4);
    void method14(double arg0, float arg1, double arg2, int arg3, bool arg4);

    int memberVariable0{};
    float memberVariable1{};
    int memberVariable2{};
    unsigned memberVariable3{};
    int memberVariable4{};
    int memberVariable5{};
    short memberVariable6{};
    unsigned memberVariable7{};
    bool memberVariable8{};
    short memberVariable9{};
    unsigned memberVariable10{};
    bool memberVariable11{};
    int memberVariable12{};
    unsigned memberVariable13{};
    double memberVariable14{};

    static void function0(int arg0, bool arg1, int arg2, double arg3, unsigned arg4);
    static float function1(float arg0, unsigned arg1, bool arg2, double arg3, bool arg4);
    static void function2(double arg0, int arg1, unsigned arg2, bool arg3, short arg4);
    static bool function3(short arg0, float arg1, bool arg2, unsigned arg3, int arg4);
    static bool function4(float arg0, unsigned arg1, short arg2, bool arg3, bool arg4);
    static float function5(float arg0, double arg1, double arg2, short arg3, short arg4);
    static float function6(bool arg0, float arg1, double arg2, float arg3, float arg4);
    static void function7(bool arg0, short arg1, unsigned arg2, short arg3, short arg4);
    static void function8(unsigned arg0, float arg1, float arg2, int arg3, double arg4);
    static void function9(int arg0, unsigned arg1, short arg2, short arg3, short arg4);
    static void function10(int arg0, float arg1, bool arg2, double arg3, float arg4);
    static short function11(double arg0, float arg1, short arg2, double arg3, short arg4);
    static double function12(int arg0, double arg1, bool arg2, unsigned arg3, float arg4);
    static void function13(bool arg0, float arg1, bool arg2, float arg3, bool arg4);
    static void function14(int arg0, double arg1, float arg2, double arg3, unsigned arg4);

    inline static bool variable0{};
    inline static short variable1{};
    inline static int variable2{};
    inline static double variable3{};
    inline static double variable4{};
    inline static int variable5{};
    inline static unsigned variable6{};
    inline static bool variable7{};
    inline static float variable8{};
    inline static bool variable9{};
    inline static float variable10{};
    inline static unsigned variable11{};
    inline static short variable12{};
    inline static double variable13{};
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
