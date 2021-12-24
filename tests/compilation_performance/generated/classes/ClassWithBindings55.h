#pragma once

// Generated with seed '88005553590'

#include "../../Common.h"

#include "ClassWithBindings6.h"
#include "ClassWithBindings7.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings22.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings78.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings86.h"
#include "ClassWithBindings95.h"
#include "ClassWithBindings96.h"
#include "ClassWithBindings99.h"

class ClassWithBindings55
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
    void method0(int arg0, unsigned arg1, bool arg2, int arg3, unsigned arg4);
    void method1(short arg0, bool arg1, float arg2, unsigned arg3, float arg4);
    double method2(short arg0, unsigned arg1, float arg2, double arg3, bool arg4);
    void method3(float arg0, bool arg1, short arg2, int arg3, unsigned arg4);
    double method4(double arg0, int arg1, double arg2, double arg3, short arg4);
    double method5(double arg0, short arg1, unsigned arg2, double arg3, float arg4);
    short method6(unsigned arg0, short arg1, short arg2, unsigned arg3, short arg4);
    int method7(int arg0, bool arg1, short arg2, bool arg3, int arg4);
    void method8(short arg0, short arg1, int arg2, float arg3, bool arg4);
    void method9(int arg0, int arg1, unsigned arg2, double arg3, bool arg4);
    void method10(bool arg0, float arg1, bool arg2, bool arg3, double arg4);
    bool method11(double arg0, short arg1, float arg2, double arg3, bool arg4);
    void method12(unsigned arg0, float arg1, bool arg2, double arg3, short arg4);
    void method13(bool arg0, double arg1, short arg2, float arg3, float arg4);
    void method14(unsigned arg0, double arg1, unsigned arg2, int arg3, float arg4);

    unsigned memberVariable0{};
    double memberVariable1{};
    bool memberVariable2{};
    unsigned memberVariable3{};
    short memberVariable4{};
    float memberVariable5{};
    short memberVariable6{};
    double memberVariable7{};
    float memberVariable8{};
    double memberVariable9{};
    int memberVariable10{};
    float memberVariable11{};
    unsigned memberVariable12{};
    float memberVariable13{};
    double memberVariable14{};

    static short function0(bool arg0, double arg1, double arg2, int arg3, short arg4);
    static void function1(double arg0, int arg1, float arg2, double arg3, short arg4);
    static void function2(double arg0, int arg1, double arg2, short arg3, unsigned arg4);
    static void function3(double arg0, float arg1, float arg2, float arg3, unsigned arg4);
    static double function4(double arg0, bool arg1, double arg2, unsigned arg3, unsigned arg4);
    static void function5(bool arg0, float arg1, int arg2, bool arg3, short arg4);
    static void function6(bool arg0, float arg1, bool arg2, short arg3, int arg4);
    static unsigned function7(int arg0, int arg1, int arg2, float arg3, unsigned arg4);
    static void function8(double arg0, float arg1, float arg2, unsigned arg3, short arg4);
    static bool function9(float arg0, bool arg1, unsigned arg2, double arg3, int arg4);
    static int function10(int arg0, float arg1, bool arg2, float arg3, float arg4);
    static int function11(short arg0, float arg1, double arg2, int arg3, double arg4);
    static void function12(short arg0, bool arg1, double arg2, short arg3, int arg4);
    static void function13(float arg0, double arg1, short arg2, int arg3, double arg4);
    static bool function14(float arg0, short arg1, double arg2, float arg3, bool arg4);

    inline static unsigned variable0{};
    inline static float variable1{};
    inline static unsigned variable2{};
    inline static int variable3{};
    inline static unsigned variable4{};
    inline static unsigned variable5{};
    inline static unsigned variable6{};
    inline static short variable7{};
    inline static bool variable8{};
    inline static float variable9{};
    inline static unsigned variable10{};
    inline static bool variable11{};
    inline static short variable12{};
    inline static int variable13{};
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
