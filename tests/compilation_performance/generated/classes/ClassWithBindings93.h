#pragma once

// Generated with seed '88005553628'

#include "../../Common.h"

#include "ClassWithBindings8.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings34.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings67.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings97.h"
#include "ClassWithBindings99.h"

class ClassWithBindings93
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
    unsigned method0(unsigned arg0, int arg1, unsigned arg2, unsigned arg3, int arg4);
    void method1(short arg0, double arg1, unsigned arg2, short arg3, bool arg4);
    void method2(double arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    void method3(int arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    void method4(short arg0, float arg1, int arg2, bool arg3, short arg4);
    short method5(double arg0, short arg1, double arg2, int arg3, short arg4);
    void method6(float arg0, int arg1, bool arg2, float arg3, bool arg4);
    void method7(unsigned arg0, int arg1, int arg2, int arg3, int arg4);
    void method8(float arg0, double arg1, bool arg2, unsigned arg3, double arg4);
    void method9(double arg0, float arg1, double arg2, float arg3, unsigned arg4);
    void method10(float arg0, unsigned arg1, bool arg2, int arg3, unsigned arg4);
    float method11(int arg0, float arg1, bool arg2, double arg3, int arg4);
    unsigned method12(unsigned arg0, unsigned arg1, double arg2, unsigned arg3, bool arg4);
    void method13(int arg0, float arg1, double arg2, unsigned arg3, double arg4);
    short method14(short arg0, int arg1, short arg2, int arg3, int arg4);

    double memberVariable0{};
    unsigned memberVariable1{};
    short memberVariable2{};
    short memberVariable3{};
    unsigned memberVariable4{};
    int memberVariable5{};
    float memberVariable6{};
    double memberVariable7{};
    unsigned memberVariable8{};
    float memberVariable9{};
    unsigned memberVariable10{};
    unsigned memberVariable11{};
    unsigned memberVariable12{};
    double memberVariable13{};
    bool memberVariable14{};

    static unsigned function0(unsigned arg0, int arg1, unsigned arg2, short arg3, bool arg4);
    static unsigned function1(bool arg0, bool arg1, unsigned arg2, double arg3, unsigned arg4);
    static void function2(bool arg0, float arg1, int arg2, short arg3, int arg4);
    static void function3(float arg0, int arg1, double arg2, unsigned arg3, short arg4);
    static short function4(double arg0, double arg1, bool arg2, short arg3, double arg4);
    static int function5(int arg0, double arg1, double arg2, int arg3, int arg4);
    static double function6(double arg0, double arg1, double arg2, double arg3, int arg4);
    static void function7(float arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    static short function8(int arg0, short arg1, short arg2, short arg3, short arg4);
    static void function9(double arg0, bool arg1, double arg2, float arg3, float arg4);
    static void function10(double arg0, short arg1, short arg2, unsigned arg3, int arg4);
    static int function11(float arg0, unsigned arg1, bool arg2, int arg3, float arg4);
    static void function12(bool arg0, float arg1, double arg2, float arg3, int arg4);
    static void function13(double arg0, unsigned arg1, short arg2, int arg3, float arg4);
    static void function14(bool arg0, double arg1, float arg2, bool arg3, float arg4);

    inline static unsigned variable0{};
    inline static double variable1{};
    inline static short variable2{};
    inline static unsigned variable3{};
    inline static unsigned variable4{};
    inline static unsigned variable5{};
    inline static double variable6{};
    inline static short variable7{};
    inline static float variable8{};
    inline static bool variable9{};
    inline static unsigned variable10{};
    inline static bool variable11{};
    inline static unsigned variable12{};
    inline static short variable13{};
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
