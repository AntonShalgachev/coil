#pragma once

// Generated with seed '88005553563'

#include "../../Common.h"

#include "ClassWithBindings12.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings97.h"

class ClassWithBindings28
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
    void method0(unsigned arg0, int arg1, bool arg2, short arg3, bool arg4);
    void method1(short arg0, int arg1, short arg2, bool arg3, double arg4);
    void method2(double arg0, int arg1, short arg2, float arg3, float arg4);
    void method3(float arg0, unsigned arg1, short arg2, unsigned arg3, short arg4);
    void method4(float arg0, short arg1, int arg2, bool arg3, bool arg4);
    float method5(bool arg0, short arg1, int arg2, int arg3, float arg4);
    void method6(bool arg0, short arg1, bool arg2, double arg3, float arg4);
    float method7(short arg0, float arg1, double arg2, unsigned arg3, short arg4);
    bool method8(unsigned arg0, float arg1, double arg2, bool arg3, float arg4);
    void method9(short arg0, float arg1, short arg2, bool arg3, short arg4);
    unsigned method10(short arg0, float arg1, float arg2, bool arg3, unsigned arg4);
    void method11(float arg0, short arg1, bool arg2, float arg3, short arg4);
    unsigned method12(unsigned arg0, bool arg1, short arg2, unsigned arg3, float arg4);
    void method13(short arg0, bool arg1, short arg2, double arg3, double arg4);
    double method14(double arg0, unsigned arg1, short arg2, float arg3, double arg4);

    unsigned memberVariable0{};
    int memberVariable1{};
    unsigned memberVariable2{};
    double memberVariable3{};
    unsigned memberVariable4{};
    int memberVariable5{};
    int memberVariable6{};
    float memberVariable7{};
    bool memberVariable8{};
    bool memberVariable9{};
    bool memberVariable10{};
    short memberVariable11{};
    int memberVariable12{};
    float memberVariable13{};
    short memberVariable14{};

    static unsigned function0(double arg0, short arg1, bool arg2, float arg3, unsigned arg4);
    static void function1(short arg0, int arg1, int arg2, short arg3, int arg4);
    static short function2(short arg0, float arg1, bool arg2, double arg3, double arg4);
    static short function3(unsigned arg0, bool arg1, int arg2, double arg3, short arg4);
    static double function4(unsigned arg0, double arg1, int arg2, short arg3, float arg4);
    static bool function5(int arg0, bool arg1, short arg2, float arg3, bool arg4);
    static void function6(double arg0, unsigned arg1, bool arg2, int arg3, unsigned arg4);
    static short function7(int arg0, short arg1, bool arg2, short arg3, bool arg4);
    static bool function8(bool arg0, unsigned arg1, double arg2, bool arg3, double arg4);
    static void function9(short arg0, int arg1, double arg2, short arg3, short arg4);
    static short function10(unsigned arg0, float arg1, float arg2, short arg3, double arg4);
    static float function11(unsigned arg0, bool arg1, float arg2, int arg3, bool arg4);
    static void function12(unsigned arg0, bool arg1, bool arg2, double arg3, bool arg4);
    static int function13(short arg0, int arg1, int arg2, unsigned arg3, unsigned arg4);
    static unsigned function14(int arg0, unsigned arg1, unsigned arg2, short arg3, unsigned arg4);

    inline static bool variable0{};
    inline static bool variable1{};
    inline static double variable2{};
    inline static short variable3{};
    inline static int variable4{};
    inline static short variable5{};
    inline static float variable6{};
    inline static int variable7{};
    inline static bool variable8{};
    inline static unsigned variable9{};
    inline static float variable10{};
    inline static double variable11{};
    inline static short variable12{};
    inline static short variable13{};
    inline static double variable14{};

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
