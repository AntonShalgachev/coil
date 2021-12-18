#pragma once

// Generated with seed '88005553535'

#include "../../Common.h"

#include "ClassWithBindings5.h"
#include "ClassWithBindings10.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings63.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings83.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings89.h"
#include "ClassWithBindings93.h"
#include "ClassWithBindings95.h"

class ClassWithBindings0
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
    void method0(short arg0, bool arg1, double arg2, float arg3, unsigned arg4);
    short method1(bool arg0, short arg1, bool arg2, short arg3, unsigned arg4);
    void method2(bool arg0, bool arg1, double arg2, double arg3, double arg4);
    int method3(unsigned arg0, unsigned arg1, int arg2, double arg3, int arg4);
    void method4(int arg0, int arg1, unsigned arg2, int arg3, unsigned arg4);
    void method5(unsigned arg0, short arg1, int arg2, unsigned arg3, short arg4);
    void method6(unsigned arg0, double arg1, unsigned arg2, int arg3, unsigned arg4);
    int method7(int arg0, float arg1, bool arg2, bool arg3, bool arg4);
    int method8(int arg0, float arg1, int arg2, float arg3, bool arg4);
    bool method9(bool arg0, bool arg1, float arg2, unsigned arg3, float arg4);
    void method10(unsigned arg0, unsigned arg1, unsigned arg2, unsigned arg3, bool arg4);
    float method11(double arg0, float arg1, double arg2, float arg3, bool arg4);
    void method12(int arg0, unsigned arg1, unsigned arg2, unsigned arg3, double arg4);
    bool method13(double arg0, bool arg1, bool arg2, bool arg3, unsigned arg4);
    void method14(bool arg0, bool arg1, float arg2, int arg3, double arg4);

    short memberVariable0{};
    bool memberVariable1{};
    bool memberVariable2{};
    short memberVariable3{};
    bool memberVariable4{};
    int memberVariable5{};
    unsigned memberVariable6{};
    float memberVariable7{};
    short memberVariable8{};
    int memberVariable9{};
    int memberVariable10{};
    short memberVariable11{};
    short memberVariable12{};
    double memberVariable13{};
    bool memberVariable14{};

    static void function0(float arg0, unsigned arg1, int arg2, double arg3, float arg4);
    static void function1(int arg0, short arg1, unsigned arg2, float arg3, float arg4);
    static void function2(float arg0, short arg1, float arg2, double arg3, int arg4);
    static void function3(double arg0, int arg1, double arg2, double arg3, double arg4);
    static unsigned function4(unsigned arg0, int arg1, unsigned arg2, float arg3, double arg4);
    static bool function5(unsigned arg0, int arg1, short arg2, float arg3, bool arg4);
    static void function6(double arg0, float arg1, short arg2, float arg3, float arg4);
    static double function7(double arg0, short arg1, float arg2, short arg3, short arg4);
    static float function8(float arg0, float arg1, int arg2, int arg3, double arg4);
    static void function9(short arg0, short arg1, bool arg2, int arg3, float arg4);
    static unsigned function10(double arg0, bool arg1, unsigned arg2, bool arg3, unsigned arg4);
    static float function11(float arg0, float arg1, float arg2, float arg3, double arg4);
    static void function12(int arg0, unsigned arg1, double arg2, int arg3, double arg4);
    static int function13(unsigned arg0, int arg1, bool arg2, double arg3, int arg4);
    static bool function14(bool arg0, short arg1, int arg2, bool arg3, unsigned arg4);

    inline static float variable0{};
    inline static bool variable1{};
    inline static double variable2{};
    inline static short variable3{};
    inline static double variable4{};
    inline static unsigned variable5{};
    inline static unsigned variable6{};
    inline static int variable7{};
    inline static short variable8{};
    inline static unsigned variable9{};
    inline static double variable10{};
    inline static short variable11{};
    inline static double variable12{};
    inline static unsigned variable13{};
    inline static float variable14{};

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
