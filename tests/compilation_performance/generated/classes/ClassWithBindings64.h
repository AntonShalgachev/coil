#pragma once

// Generated with seed '88005553599'

#include "../../Common.h"

#include "ClassWithBindings2.h"
#include "ClassWithBindings3.h"
#include "ClassWithBindings8.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings43.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings56.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings89.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings91.h"

class ClassWithBindings64
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
    void method0(float arg0, bool arg1, float arg2, unsigned arg3, unsigned arg4);
    unsigned method1(unsigned arg0, unsigned arg1, float arg2, int arg3, float arg4);
    void method2(float arg0, bool arg1, int arg2, float arg3, bool arg4);
    void method3(float arg0, float arg1, float arg2, int arg3, double arg4);
    void method4(bool arg0, bool arg1, float arg2, bool arg3, bool arg4);
    unsigned method5(double arg0, float arg1, unsigned arg2, double arg3, unsigned arg4);
    bool method6(bool arg0, double arg1, unsigned arg2, bool arg3, float arg4);
    void method7(double arg0, bool arg1, double arg2, int arg3, float arg4);
    bool method8(unsigned arg0, float arg1, bool arg2, int arg3, unsigned arg4);
    void method9(short arg0, short arg1, float arg2, int arg3, int arg4);
    int method10(short arg0, double arg1, double arg2, int arg3, double arg4);
    short method11(int arg0, short arg1, short arg2, double arg3, bool arg4);
    float method12(bool arg0, short arg1, float arg2, bool arg3, float arg4);
    void method13(short arg0, short arg1, double arg2, short arg3, short arg4);
    short method14(short arg0, bool arg1, short arg2, double arg3, double arg4);

    short memberVariable0{};
    bool memberVariable1{};
    float memberVariable2{};
    int memberVariable3{};
    float memberVariable4{};
    bool memberVariable5{};
    float memberVariable6{};
    float memberVariable7{};
    short memberVariable8{};
    short memberVariable9{};
    short memberVariable10{};
    int memberVariable11{};
    int memberVariable12{};
    float memberVariable13{};
    unsigned memberVariable14{};

    static float function0(bool arg0, double arg1, float arg2, unsigned arg3, int arg4);
    static void function1(float arg0, short arg1, int arg2, bool arg3, unsigned arg4);
    static int function2(int arg0, short arg1, unsigned arg2, short arg3, int arg4);
    static void function3(bool arg0, bool arg1, bool arg2, double arg3, float arg4);
    static void function4(short arg0, short arg1, short arg2, bool arg3, short arg4);
    static short function5(unsigned arg0, short arg1, unsigned arg2, int arg3, short arg4);
    static int function6(int arg0, unsigned arg1, float arg2, unsigned arg3, float arg4);
    static void function7(bool arg0, int arg1, int arg2, bool arg3, unsigned arg4);
    static bool function8(bool arg0, short arg1, short arg2, short arg3, double arg4);
    static unsigned function9(bool arg0, bool arg1, int arg2, unsigned arg3, int arg4);
    static double function10(float arg0, double arg1, float arg2, short arg3, double arg4);
    static double function11(unsigned arg0, double arg1, bool arg2, bool arg3, int arg4);
    static unsigned function12(int arg0, unsigned arg1, unsigned arg2, short arg3, float arg4);
    static double function13(bool arg0, double arg1, short arg2, float arg3, short arg4);
    static unsigned function14(unsigned arg0, float arg1, double arg2, int arg3, unsigned arg4);

    inline static unsigned variable0{};
    inline static short variable1{};
    inline static bool variable2{};
    inline static int variable3{};
    inline static int variable4{};
    inline static int variable5{};
    inline static short variable6{};
    inline static float variable7{};
    inline static short variable8{};
    inline static unsigned variable9{};
    inline static float variable10{};
    inline static float variable11{};
    inline static unsigned variable12{};
    inline static unsigned variable13{};
    inline static int variable14{};

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
