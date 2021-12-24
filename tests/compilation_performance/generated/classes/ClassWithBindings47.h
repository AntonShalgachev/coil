#pragma once

// Generated with seed '88005553582'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings2.h"
#include "ClassWithBindings3.h"
#include "ClassWithBindings6.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings43.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings91.h"
#include "ClassWithBindings98.h"

class ClassWithBindings47
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
    void method0(unsigned arg0, double arg1, float arg2, double arg3, float arg4);
    unsigned method1(int arg0, short arg1, unsigned arg2, unsigned arg3, short arg4);
    short method2(short arg0, bool arg1, double arg2, short arg3, double arg4);
    short method3(unsigned arg0, int arg1, double arg2, short arg3, bool arg4);
    unsigned method4(bool arg0, unsigned arg1, float arg2, short arg3, short arg4);
    void method5(float arg0, short arg1, short arg2, short arg3, double arg4);
    unsigned method6(unsigned arg0, bool arg1, unsigned arg2, int arg3, short arg4);
    double method7(int arg0, bool arg1, unsigned arg2, unsigned arg3, double arg4);
    int method8(float arg0, short arg1, bool arg2, int arg3, int arg4);
    float method9(double arg0, bool arg1, double arg2, float arg3, short arg4);
    unsigned method10(unsigned arg0, int arg1, bool arg2, int arg3, short arg4);
    void method11(unsigned arg0, unsigned arg1, float arg2, unsigned arg3, double arg4);
    unsigned method12(bool arg0, float arg1, double arg2, double arg3, unsigned arg4);
    void method13(unsigned arg0, float arg1, double arg2, double arg3, short arg4);
    float method14(bool arg0, int arg1, float arg2, double arg3, int arg4);

    int memberVariable0{};
    int memberVariable1{};
    bool memberVariable2{};
    double memberVariable3{};
    short memberVariable4{};
    unsigned memberVariable5{};
    int memberVariable6{};
    double memberVariable7{};
    int memberVariable8{};
    int memberVariable9{};
    float memberVariable10{};
    double memberVariable11{};
    bool memberVariable12{};
    double memberVariable13{};
    double memberVariable14{};

    static double function0(double arg0, unsigned arg1, float arg2, double arg3, bool arg4);
    static double function1(double arg0, double arg1, short arg2, float arg3, double arg4);
    static double function2(float arg0, double arg1, int arg2, double arg3, bool arg4);
    static double function3(unsigned arg0, double arg1, double arg2, bool arg3, short arg4);
    static float function4(float arg0, float arg1, bool arg2, int arg3, int arg4);
    static unsigned function5(float arg0, int arg1, double arg2, int arg3, unsigned arg4);
    static short function6(float arg0, double arg1, unsigned arg2, short arg3, bool arg4);
    static void function7(bool arg0, double arg1, bool arg2, double arg3, float arg4);
    static float function8(float arg0, short arg1, unsigned arg2, float arg3, float arg4);
    static bool function9(bool arg0, short arg1, unsigned arg2, bool arg3, float arg4);
    static int function10(bool arg0, double arg1, bool arg2, double arg3, int arg4);
    static void function11(bool arg0, double arg1, double arg2, float arg3, double arg4);
    static void function12(double arg0, short arg1, int arg2, int arg3, int arg4);
    static void function13(double arg0, float arg1, unsigned arg2, float arg3, double arg4);
    static void function14(float arg0, int arg1, unsigned arg2, short arg3, unsigned arg4);

    inline static short variable0{};
    inline static bool variable1{};
    inline static double variable2{};
    inline static float variable3{};
    inline static int variable4{};
    inline static int variable5{};
    inline static short variable6{};
    inline static float variable7{};
    inline static double variable8{};
    inline static int variable9{};
    inline static float variable10{};
    inline static float variable11{};
    inline static float variable12{};
    inline static short variable13{};
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
