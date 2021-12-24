#pragma once

// Generated with seed '88005553594'

#include "../../Common.h"

#include "ClassWithBindings8.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings24.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings43.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings48.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings75.h"
#include "ClassWithBindings76.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings95.h"
#include "ClassWithBindings97.h"
#include "ClassWithBindings99.h"

class ClassWithBindings59
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
    void method0(float arg0, bool arg1, double arg2, int arg3, bool arg4);
    void method1(float arg0, short arg1, unsigned arg2, unsigned arg3, bool arg4);
    short method2(float arg0, short arg1, int arg2, short arg3, bool arg4);
    float method3(unsigned arg0, float arg1, short arg2, double arg3, short arg4);
    void method4(bool arg0, float arg1, double arg2, unsigned arg3, int arg4);
    double method5(double arg0, bool arg1, bool arg2, unsigned arg3, int arg4);
    void method6(double arg0, unsigned arg1, unsigned arg2, short arg3, bool arg4);
    int method7(double arg0, int arg1, double arg2, int arg3, short arg4);
    void method8(short arg0, float arg1, short arg2, float arg3, bool arg4);
    void method9(short arg0, unsigned arg1, double arg2, bool arg3, bool arg4);
    void method10(double arg0, double arg1, float arg2, short arg3, float arg4);
    void method11(float arg0, bool arg1, int arg2, int arg3, double arg4);
    void method12(short arg0, float arg1, unsigned arg2, bool arg3, float arg4);
    unsigned method13(bool arg0, unsigned arg1, double arg2, bool arg3, unsigned arg4);
    int method14(unsigned arg0, double arg1, unsigned arg2, float arg3, int arg4);

    bool memberVariable0{};
    float memberVariable1{};
    int memberVariable2{};
    unsigned memberVariable3{};
    float memberVariable4{};
    float memberVariable5{};
    unsigned memberVariable6{};
    double memberVariable7{};
    float memberVariable8{};
    double memberVariable9{};
    short memberVariable10{};
    unsigned memberVariable11{};
    short memberVariable12{};
    int memberVariable13{};
    unsigned memberVariable14{};

    static short function0(int arg0, unsigned arg1, float arg2, short arg3, double arg4);
    static void function1(short arg0, unsigned arg1, int arg2, double arg3, double arg4);
    static double function2(float arg0, double arg1, unsigned arg2, double arg3, bool arg4);
    static void function3(unsigned arg0, double arg1, float arg2, unsigned arg3, float arg4);
    static void function4(bool arg0, unsigned arg1, double arg2, unsigned arg3, short arg4);
    static void function5(float arg0, short arg1, float arg2, bool arg3, float arg4);
    static double function6(double arg0, float arg1, double arg2, double arg3, float arg4);
    static double function7(unsigned arg0, double arg1, bool arg2, bool arg3, short arg4);
    static bool function8(unsigned arg0, bool arg1, bool arg2, double arg3, float arg4);
    static unsigned function9(float arg0, short arg1, double arg2, unsigned arg3, unsigned arg4);
    static void function10(short arg0, short arg1, short arg2, float arg3, float arg4);
    static short function11(short arg0, float arg1, unsigned arg2, bool arg3, short arg4);
    static void function12(short arg0, double arg1, unsigned arg2, bool arg3, int arg4);
    static float function13(float arg0, unsigned arg1, float arg2, bool arg3, double arg4);
    static void function14(float arg0, short arg1, unsigned arg2, float arg3, int arg4);

    inline static bool variable0{};
    inline static double variable1{};
    inline static short variable2{};
    inline static double variable3{};
    inline static float variable4{};
    inline static bool variable5{};
    inline static bool variable6{};
    inline static float variable7{};
    inline static short variable8{};
    inline static float variable9{};
    inline static short variable10{};
    inline static bool variable11{};
    inline static int variable12{};
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
