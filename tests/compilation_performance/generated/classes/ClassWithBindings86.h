#pragma once

// Generated with seed '88005553621'

#include "../../Common.h"

#include "ClassWithBindings11.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings42.h"
#include "ClassWithBindings43.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings63.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings93.h"

class ClassWithBindings86
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
    double method0(double arg0, unsigned arg1, unsigned arg2, float arg3, double arg4);
    void method1(int arg0, int arg1, short arg2, short arg3, double arg4);
    void method2(double arg0, float arg1, short arg2, double arg3, int arg4);
    unsigned method3(double arg0, int arg1, unsigned arg2, int arg3, bool arg4);
    void method4(float arg0, double arg1, int arg2, short arg3, float arg4);
    double method5(double arg0, short arg1, short arg2, double arg3, unsigned arg4);
    float method6(float arg0, short arg1, short arg2, short arg3, unsigned arg4);
    void method7(bool arg0, float arg1, float arg2, int arg3, int arg4);
    void method8(int arg0, unsigned arg1, int arg2, double arg3, bool arg4);
    void method9(short arg0, float arg1, float arg2, int arg3, float arg4);
    float method10(short arg0, double arg1, float arg2, float arg3, short arg4);
    short method11(short arg0, int arg1, float arg2, unsigned arg3, float arg4);
    void method12(bool arg0, unsigned arg1, unsigned arg2, unsigned arg3, bool arg4);
    double method13(short arg0, double arg1, double arg2, double arg3, bool arg4);
    double method14(unsigned arg0, float arg1, int arg2, double arg3, bool arg4);

    int memberVariable0{};
    double memberVariable1{};
    unsigned memberVariable2{};
    float memberVariable3{};
    bool memberVariable4{};
    short memberVariable5{};
    unsigned memberVariable6{};
    int memberVariable7{};
    bool memberVariable8{};
    int memberVariable9{};
    short memberVariable10{};
    float memberVariable11{};
    double memberVariable12{};
    double memberVariable13{};
    double memberVariable14{};

    static float function0(short arg0, short arg1, short arg2, float arg3, short arg4);
    static void function1(bool arg0, float arg1, float arg2, unsigned arg3, bool arg4);
    static void function2(int arg0, bool arg1, unsigned arg2, double arg3, double arg4);
    static void function3(int arg0, float arg1, unsigned arg2, bool arg3, bool arg4);
    static void function4(unsigned arg0, short arg1, float arg2, int arg3, unsigned arg4);
    static short function5(double arg0, int arg1, short arg2, short arg3, int arg4);
    static void function6(unsigned arg0, int arg1, int arg2, float arg3, bool arg4);
    static int function7(int arg0, float arg1, int arg2, int arg3, short arg4);
    static double function8(bool arg0, int arg1, unsigned arg2, double arg3, float arg4);
    static void function9(int arg0, int arg1, short arg2, bool arg3, unsigned arg4);
    static void function10(bool arg0, double arg1, int arg2, bool arg3, short arg4);
    static void function11(unsigned arg0, double arg1, double arg2, float arg3, double arg4);
    static void function12(double arg0, float arg1, short arg2, float arg3, double arg4);
    static void function13(unsigned arg0, bool arg1, short arg2, bool arg3, bool arg4);
    static float function14(int arg0, double arg1, float arg2, double arg3, short arg4);

    inline static float variable0{};
    inline static float variable1{};
    inline static double variable2{};
    inline static double variable3{};
    inline static float variable4{};
    inline static short variable5{};
    inline static double variable6{};
    inline static float variable7{};
    inline static int variable8{};
    inline static bool variable9{};
    inline static short variable10{};
    inline static bool variable11{};
    inline static int variable12{};
    inline static float variable13{};
    inline static unsigned variable14{};

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
