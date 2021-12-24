#pragma once

// Generated with seed '88005553540'

#include "../../Common.h"

#include "ClassWithBindings1.h"
#include "ClassWithBindings6.h"
#include "ClassWithBindings7.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings16.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings91.h"
#include "ClassWithBindings96.h"

class ClassWithBindings5
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
    unsigned method0(unsigned arg0, float arg1, float arg2, unsigned arg3, short arg4);
    bool method1(bool arg0, int arg1, bool arg2, int arg3, int arg4);
    void method2(int arg0, double arg1, double arg2, float arg3, bool arg4);
    void method3(bool arg0, short arg1, short arg2, unsigned arg3, float arg4);
    void method4(float arg0, int arg1, short arg2, int arg3, short arg4);
    void method5(float arg0, double arg1, unsigned arg2, bool arg3, unsigned arg4);
    void method6(unsigned arg0, int arg1, float arg2, short arg3, int arg4);
    float method7(double arg0, int arg1, float arg2, bool arg3, unsigned arg4);
    int method8(float arg0, int arg1, float arg2, unsigned arg3, double arg4);
    void method9(float arg0, double arg1, short arg2, int arg3, unsigned arg4);
    void method10(double arg0, short arg1, int arg2, unsigned arg3, unsigned arg4);
    void method11(double arg0, unsigned arg1, short arg2, bool arg3, bool arg4);
    void method12(int arg0, int arg1, double arg2, float arg3, unsigned arg4);
    float method13(double arg0, double arg1, float arg2, double arg3, double arg4);
    int method14(bool arg0, int arg1, bool arg2, unsigned arg3, int arg4);

    short memberVariable0{};
    double memberVariable1{};
    int memberVariable2{};
    double memberVariable3{};
    float memberVariable4{};
    unsigned memberVariable5{};
    float memberVariable6{};
    unsigned memberVariable7{};
    double memberVariable8{};
    int memberVariable9{};
    double memberVariable10{};
    double memberVariable11{};
    unsigned memberVariable12{};
    short memberVariable13{};
    bool memberVariable14{};

    static void function0(double arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    static bool function1(float arg0, int arg1, short arg2, bool arg3, int arg4);
    static short function2(unsigned arg0, short arg1, float arg2, bool arg3, short arg4);
    static float function3(float arg0, unsigned arg1, float arg2, double arg3, unsigned arg4);
    static double function4(double arg0, bool arg1, int arg2, int arg3, unsigned arg4);
    static void function5(short arg0, float arg1, double arg2, double arg3, float arg4);
    static float function6(int arg0, unsigned arg1, int arg2, float arg3, double arg4);
    static bool function7(bool arg0, bool arg1, unsigned arg2, float arg3, int arg4);
    static void function8(float arg0, float arg1, double arg2, unsigned arg3, bool arg4);
    static void function9(float arg0, short arg1, unsigned arg2, bool arg3, short arg4);
    static void function10(float arg0, short arg1, short arg2, float arg3, unsigned arg4);
    static short function11(short arg0, double arg1, double arg2, short arg3, bool arg4);
    static bool function12(unsigned arg0, unsigned arg1, int arg2, bool arg3, float arg4);
    static void function13(unsigned arg0, bool arg1, unsigned arg2, unsigned arg3, bool arg4);
    static bool function14(bool arg0, int arg1, bool arg2, int arg3, float arg4);

    inline static float variable0{};
    inline static int variable1{};
    inline static bool variable2{};
    inline static unsigned variable3{};
    inline static float variable4{};
    inline static float variable5{};
    inline static float variable6{};
    inline static double variable7{};
    inline static int variable8{};
    inline static bool variable9{};
    inline static short variable10{};
    inline static float variable11{};
    inline static double variable12{};
    inline static bool variable13{};
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
