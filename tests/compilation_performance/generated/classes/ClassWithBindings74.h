#pragma once

// Generated with seed '88005553609'

#include "../../Common.h"

#include "ClassWithBindings8.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings76.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings78.h"
#include "ClassWithBindings87.h"
#include "ClassWithBindings94.h"
#include "ClassWithBindings98.h"

class ClassWithBindings74
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
    void method0(bool arg0, short arg1, short arg2, bool arg3, int arg4);
    void method1(unsigned arg0, bool arg1, short arg2, unsigned arg3, int arg4);
    void method2(unsigned arg0, float arg1, int arg2, bool arg3, unsigned arg4);
    void method3(unsigned arg0, int arg1, double arg2, int arg3, short arg4);
    void method4(unsigned arg0, short arg1, double arg2, int arg3, double arg4);
    void method5(unsigned arg0, double arg1, unsigned arg2, int arg3, int arg4);
    double method6(bool arg0, short arg1, bool arg2, double arg3, bool arg4);
    void method7(short arg0, float arg1, bool arg2, float arg3, short arg4);
    float method8(double arg0, int arg1, short arg2, float arg3, float arg4);
    void method9(int arg0, bool arg1, int arg2, short arg3, double arg4);
    short method10(int arg0, short arg1, unsigned arg2, unsigned arg3, int arg4);
    short method11(bool arg0, float arg1, short arg2, short arg3, bool arg4);
    void method12(double arg0, short arg1, bool arg2, double arg3, bool arg4);
    void method13(bool arg0, unsigned arg1, int arg2, unsigned arg3, bool arg4);
    short method14(short arg0, float arg1, bool arg2, unsigned arg3, float arg4);

    unsigned memberVariable0{};
    float memberVariable1{};
    double memberVariable2{};
    unsigned memberVariable3{};
    short memberVariable4{};
    double memberVariable5{};
    float memberVariable6{};
    int memberVariable7{};
    int memberVariable8{};
    unsigned memberVariable9{};
    int memberVariable10{};
    double memberVariable11{};
    int memberVariable12{};
    int memberVariable13{};
    short memberVariable14{};

    static void function0(int arg0, short arg1, short arg2, double arg3, int arg4);
    static short function1(double arg0, bool arg1, int arg2, short arg3, short arg4);
    static bool function2(short arg0, bool arg1, unsigned arg2, short arg3, float arg4);
    static void function3(float arg0, unsigned arg1, double arg2, short arg3, double arg4);
    static void function4(float arg0, bool arg1, short arg2, bool arg3, short arg4);
    static void function5(bool arg0, int arg1, double arg2, float arg3, double arg4);
    static void function6(bool arg0, unsigned arg1, unsigned arg2, double arg3, unsigned arg4);
    static float function7(double arg0, bool arg1, float arg2, bool arg3, unsigned arg4);
    static unsigned function8(unsigned arg0, float arg1, int arg2, unsigned arg3, unsigned arg4);
    static double function9(double arg0, int arg1, float arg2, double arg3, short arg4);
    static void function10(float arg0, int arg1, double arg2, bool arg3, unsigned arg4);
    static void function11(short arg0, int arg1, int arg2, double arg3, float arg4);
    static float function12(short arg0, bool arg1, double arg2, float arg3, short arg4);
    static void function13(int arg0, float arg1, bool arg2, short arg3, double arg4);
    static double function14(short arg0, bool arg1, double arg2, short arg3, double arg4);

    inline static short variable0{};
    inline static unsigned variable1{};
    inline static int variable2{};
    inline static int variable3{};
    inline static float variable4{};
    inline static short variable5{};
    inline static unsigned variable6{};
    inline static short variable7{};
    inline static short variable8{};
    inline static bool variable9{};
    inline static double variable10{};
    inline static unsigned variable11{};
    inline static double variable12{};
    inline static double variable13{};
    inline static bool variable14{};

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
