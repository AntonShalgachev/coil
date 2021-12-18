#pragma once

// Generated with seed '88005553611'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings7.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings22.h"
#include "ClassWithBindings24.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings56.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings67.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings83.h"
#include "ClassWithBindings96.h"
#include "ClassWithBindings99.h"

class ClassWithBindings76
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

#ifdef MANUAL_DEBUG_BINDINGS
    void registerBindings(DumbBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, bool arg1, short arg2, double arg3, int arg4);
    void method1(unsigned arg0, unsigned arg1, bool arg2, double arg3, float arg4);
    double method2(short arg0, short arg1, float arg2, double arg3, unsigned arg4);
    double method3(unsigned arg0, double arg1, int arg2, double arg3, double arg4);
    void method4(int arg0, int arg1, float arg2, float arg3, double arg4);
    short method5(short arg0, int arg1, int arg2, short arg3, short arg4);
    void method6(int arg0, unsigned arg1, int arg2, bool arg3, bool arg4);
    void method7(unsigned arg0, int arg1, short arg2, double arg3, float arg4);
    unsigned method8(float arg0, int arg1, short arg2, unsigned arg3, int arg4);
    void method9(unsigned arg0, double arg1, double arg2, bool arg3, bool arg4);
    void method10(double arg0, short arg1, float arg2, short arg3, short arg4);
    void method11(bool arg0, double arg1, unsigned arg2, unsigned arg3, int arg4);
    unsigned method12(double arg0, unsigned arg1, unsigned arg2, double arg3, unsigned arg4);
    bool method13(bool arg0, int arg1, float arg2, int arg3, unsigned arg4);
    void method14(int arg0, int arg1, unsigned arg2, float arg3, double arg4);

    double memberVariable0{};
    int memberVariable1{};
    short memberVariable2{};
    double memberVariable3{};
    bool memberVariable4{};
    bool memberVariable5{};
    unsigned memberVariable6{};
    bool memberVariable7{};
    int memberVariable8{};
    int memberVariable9{};
    double memberVariable10{};
    bool memberVariable11{};
    float memberVariable12{};
    short memberVariable13{};
    unsigned memberVariable14{};

    static bool function0(unsigned arg0, short arg1, short arg2, float arg3, bool arg4);
    static bool function1(bool arg0, double arg1, int arg2, int arg3, unsigned arg4);
    static void function2(short arg0, unsigned arg1, int arg2, float arg3, float arg4);
    static void function3(bool arg0, float arg1, short arg2, bool arg3, short arg4);
    static float function4(unsigned arg0, float arg1, bool arg2, float arg3, double arg4);
    static short function5(unsigned arg0, bool arg1, bool arg2, float arg3, short arg4);
    static void function6(int arg0, int arg1, double arg2, double arg3, bool arg4);
    static void function7(unsigned arg0, int arg1, bool arg2, short arg3, int arg4);
    static void function8(double arg0, float arg1, short arg2, bool arg3, int arg4);
    static unsigned function9(unsigned arg0, double arg1, unsigned arg2, short arg3, unsigned arg4);
    static unsigned function10(double arg0, double arg1, short arg2, double arg3, unsigned arg4);
    static double function11(double arg0, short arg1, bool arg2, double arg3, double arg4);
    static void function12(float arg0, float arg1, unsigned arg2, int arg3, short arg4);
    static void function13(bool arg0, bool arg1, double arg2, unsigned arg3, bool arg4);
    static void function14(bool arg0, int arg1, bool arg2, bool arg3, bool arg4);

    inline static float variable0{};
    inline static float variable1{};
    inline static bool variable2{};
    inline static float variable3{};
    inline static double variable4{};
    inline static double variable5{};
    inline static int variable6{};
    inline static bool variable7{};
    inline static int variable8{};
    inline static float variable9{};
    inline static float variable10{};
    inline static double variable11{};
    inline static unsigned variable12{};
    inline static short variable13{};
    inline static short variable14{};

#ifdef MANUAL_DEBUG_BINDINGS
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
