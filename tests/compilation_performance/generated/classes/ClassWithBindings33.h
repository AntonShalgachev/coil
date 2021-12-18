#pragma once

// Generated with seed '88005553568'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings1.h"
#include "ClassWithBindings2.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings76.h"
#include "ClassWithBindings78.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings88.h"
#include "ClassWithBindings89.h"

class ClassWithBindings33
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
    double method0(short arg0, int arg1, double arg2, float arg3, float arg4);
    float method1(int arg0, float arg1, double arg2, int arg3, float arg4);
    void method2(short arg0, int arg1, float arg2, short arg3, bool arg4);
    short method3(short arg0, unsigned arg1, unsigned arg2, double arg3, int arg4);
    int method4(int arg0, unsigned arg1, short arg2, short arg3, int arg4);
    int method5(int arg0, short arg1, double arg2, bool arg3, unsigned arg4);
    void method6(unsigned arg0, short arg1, short arg2, float arg3, int arg4);
    void method7(double arg0, unsigned arg1, short arg2, unsigned arg3, short arg4);
    int method8(int arg0, short arg1, int arg2, unsigned arg3, unsigned arg4);
    void method9(bool arg0, int arg1, double arg2, unsigned arg3, int arg4);
    float method10(float arg0, unsigned arg1, float arg2, int arg3, float arg4);
    bool method11(unsigned arg0, double arg1, int arg2, short arg3, bool arg4);
    void method12(double arg0, bool arg1, short arg2, short arg3, bool arg4);
    short method13(int arg0, bool arg1, short arg2, short arg3, short arg4);
    short method14(int arg0, short arg1, short arg2, int arg3, short arg4);

    unsigned memberVariable0{};
    short memberVariable1{};
    float memberVariable2{};
    float memberVariable3{};
    float memberVariable4{};
    unsigned memberVariable5{};
    double memberVariable6{};
    unsigned memberVariable7{};
    bool memberVariable8{};
    float memberVariable9{};
    bool memberVariable10{};
    double memberVariable11{};
    bool memberVariable12{};
    float memberVariable13{};
    double memberVariable14{};

    static int function0(float arg0, double arg1, int arg2, double arg3, int arg4);
    static float function1(unsigned arg0, bool arg1, bool arg2, unsigned arg3, float arg4);
    static void function2(double arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    static bool function3(unsigned arg0, bool arg1, short arg2, bool arg3, double arg4);
    static float function4(bool arg0, bool arg1, short arg2, float arg3, short arg4);
    static void function5(int arg0, short arg1, float arg2, int arg3, short arg4);
    static void function6(double arg0, int arg1, double arg2, unsigned arg3, float arg4);
    static void function7(int arg0, double arg1, double arg2, double arg3, bool arg4);
    static float function8(int arg0, unsigned arg1, unsigned arg2, double arg3, float arg4);
    static double function9(double arg0, bool arg1, short arg2, int arg3, double arg4);
    static bool function10(double arg0, bool arg1, short arg2, int arg3, bool arg4);
    static float function11(short arg0, bool arg1, bool arg2, float arg3, double arg4);
    static short function12(int arg0, int arg1, bool arg2, short arg3, short arg4);
    static short function13(unsigned arg0, short arg1, double arg2, short arg3, float arg4);
    static unsigned function14(short arg0, unsigned arg1, unsigned arg2, float arg3, unsigned arg4);

    inline static unsigned variable0{};
    inline static int variable1{};
    inline static bool variable2{};
    inline static double variable3{};
    inline static int variable4{};
    inline static bool variable5{};
    inline static short variable6{};
    inline static bool variable7{};
    inline static short variable8{};
    inline static bool variable9{};
    inline static unsigned variable10{};
    inline static int variable11{};
    inline static double variable12{};
    inline static bool variable13{};
    inline static double variable14{};

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
