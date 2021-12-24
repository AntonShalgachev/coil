#pragma once

// Generated with seed '88005553608'

#include "../../Common.h"

#include "ClassWithBindings3.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings8.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings20.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings83.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings96.h"
#include "ClassWithBindings97.h"

class ClassWithBindings73
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
    int method0(int arg0, short arg1, bool arg2, float arg3, int arg4);
    double method1(short arg0, unsigned arg1, double arg2, bool arg3, int arg4);
    bool method2(double arg0, double arg1, bool arg2, double arg3, bool arg4);
    int method3(double arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    void method4(unsigned arg0, int arg1, bool arg2, short arg3, double arg4);
    float method5(unsigned arg0, float arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method6(float arg0, bool arg1, float arg2, bool arg3, unsigned arg4);
    void method7(float arg0, int arg1, bool arg2, float arg3, unsigned arg4);
    float method8(float arg0, float arg1, short arg2, float arg3, float arg4);
    void method9(float arg0, int arg1, unsigned arg2, short arg3, bool arg4);
    short method10(unsigned arg0, double arg1, unsigned arg2, bool arg3, short arg4);
    void method11(short arg0, double arg1, double arg2, double arg3, unsigned arg4);
    int method12(double arg0, bool arg1, double arg2, int arg3, unsigned arg4);
    void method13(double arg0, short arg1, unsigned arg2, float arg3, short arg4);
    void method14(float arg0, short arg1, short arg2, double arg3, int arg4);

    float memberVariable0{};
    float memberVariable1{};
    int memberVariable2{};
    bool memberVariable3{};
    short memberVariable4{};
    int memberVariable5{};
    unsigned memberVariable6{};
    int memberVariable7{};
    double memberVariable8{};
    unsigned memberVariable9{};
    bool memberVariable10{};
    unsigned memberVariable11{};
    float memberVariable12{};
    unsigned memberVariable13{};
    int memberVariable14{};

    static double function0(unsigned arg0, double arg1, unsigned arg2, bool arg3, int arg4);
    static void function1(bool arg0, unsigned arg1, double arg2, bool arg3, bool arg4);
    static float function2(short arg0, bool arg1, float arg2, int arg3, short arg4);
    static void function3(double arg0, float arg1, short arg2, bool arg3, short arg4);
    static void function4(int arg0, double arg1, float arg2, double arg3, float arg4);
    static double function5(double arg0, short arg1, bool arg2, double arg3, bool arg4);
    static void function6(unsigned arg0, bool arg1, float arg2, double arg3, unsigned arg4);
    static void function7(bool arg0, float arg1, double arg2, float arg3, int arg4);
    static unsigned function8(short arg0, bool arg1, unsigned arg2, unsigned arg3, int arg4);
    static short function9(bool arg0, float arg1, short arg2, float arg3, double arg4);
    static float function10(float arg0, double arg1, float arg2, short arg3, float arg4);
    static void function11(float arg0, short arg1, float arg2, int arg3, short arg4);
    static void function12(short arg0, short arg1, int arg2, short arg3, int arg4);
    static short function13(bool arg0, short arg1, unsigned arg2, short arg3, int arg4);
    static void function14(int arg0, double arg1, unsigned arg2, double arg3, bool arg4);

    inline static short variable0{};
    inline static short variable1{};
    inline static float variable2{};
    inline static double variable3{};
    inline static float variable4{};
    inline static unsigned variable5{};
    inline static bool variable6{};
    inline static short variable7{};
    inline static short variable8{};
    inline static bool variable9{};
    inline static unsigned variable10{};
    inline static bool variable11{};
    inline static short variable12{};
    inline static int variable13{};
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
