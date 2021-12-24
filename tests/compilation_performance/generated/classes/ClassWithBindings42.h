#pragma once

// Generated with seed '88005553577'

#include "../../Common.h"

#include "ClassWithBindings4.h"
#include "ClassWithBindings10.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings22.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings56.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings67.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings75.h"
#include "ClassWithBindings79.h"

class ClassWithBindings42
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
    double method0(double arg0, int arg1, unsigned arg2, short arg3, bool arg4);
    bool method1(bool arg0, bool arg1, bool arg2, bool arg3, float arg4);
    void method2(bool arg0, double arg1, float arg2, float arg3, int arg4);
    void method3(int arg0, short arg1, bool arg2, int arg3, short arg4);
    void method4(short arg0, int arg1, bool arg2, unsigned arg3, int arg4);
    int method5(int arg0, float arg1, unsigned arg2, int arg3, float arg4);
    void method6(int arg0, int arg1, short arg2, float arg3, unsigned arg4);
    void method7(bool arg0, short arg1, double arg2, short arg3, bool arg4);
    bool method8(bool arg0, short arg1, short arg2, int arg3, bool arg4);
    double method9(bool arg0, bool arg1, int arg2, double arg3, short arg4);
    void method10(unsigned arg0, bool arg1, double arg2, unsigned arg3, short arg4);
    short method11(float arg0, unsigned arg1, unsigned arg2, int arg3, short arg4);
    int method12(int arg0, int arg1, float arg2, double arg3, short arg4);
    float method13(unsigned arg0, int arg1, bool arg2, float arg3, short arg4);
    void method14(unsigned arg0, bool arg1, short arg2, int arg3, short arg4);

    int memberVariable0{};
    float memberVariable1{};
    bool memberVariable2{};
    bool memberVariable3{};
    int memberVariable4{};
    double memberVariable5{};
    double memberVariable6{};
    int memberVariable7{};
    float memberVariable8{};
    short memberVariable9{};
    float memberVariable10{};
    unsigned memberVariable11{};
    bool memberVariable12{};
    unsigned memberVariable13{};
    bool memberVariable14{};

    static void function0(bool arg0, float arg1, short arg2, int arg3, bool arg4);
    static void function1(unsigned arg0, short arg1, short arg2, bool arg3, int arg4);
    static void function2(float arg0, short arg1, float arg2, float arg3, float arg4);
    static void function3(float arg0, bool arg1, double arg2, double arg3, short arg4);
    static short function4(short arg0, unsigned arg1, int arg2, float arg3, short arg4);
    static float function5(float arg0, float arg1, bool arg2, bool arg3, bool arg4);
    static void function6(double arg0, short arg1, int arg2, bool arg3, short arg4);
    static void function7(short arg0, short arg1, short arg2, float arg3, short arg4);
    static void function8(unsigned arg0, int arg1, short arg2, double arg3, short arg4);
    static int function9(unsigned arg0, int arg1, float arg2, double arg3, unsigned arg4);
    static unsigned function10(int arg0, short arg1, bool arg2, unsigned arg3, unsigned arg4);
    static float function11(float arg0, int arg1, bool arg2, bool arg3, short arg4);
    static void function12(int arg0, double arg1, short arg2, double arg3, int arg4);
    static double function13(short arg0, short arg1, float arg2, double arg3, float arg4);
    static unsigned function14(unsigned arg0, unsigned arg1, unsigned arg2, int arg3, unsigned arg4);

    inline static short variable0{};
    inline static unsigned variable1{};
    inline static short variable2{};
    inline static short variable3{};
    inline static unsigned variable4{};
    inline static short variable5{};
    inline static double variable6{};
    inline static int variable7{};
    inline static unsigned variable8{};
    inline static bool variable9{};
    inline static short variable10{};
    inline static float variable11{};
    inline static short variable12{};
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
