#pragma once

// Generated with seed '88005553596'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings3.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings43.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings81.h"
#include "ClassWithBindings85.h"

class ClassWithBindings61
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
    void method0(int arg0, int arg1, double arg2, int arg3, int arg4);
    void method1(short arg0, unsigned arg1, float arg2, short arg3, short arg4);
    int method2(int arg0, short arg1, short arg2, int arg3, bool arg4);
    int method3(double arg0, double arg1, bool arg2, float arg3, int arg4);
    short method4(short arg0, double arg1, int arg2, float arg3, short arg4);
    void method5(double arg0, int arg1, short arg2, double arg3, short arg4);
    void method6(int arg0, int arg1, double arg2, int arg3, int arg4);
    bool method7(bool arg0, unsigned arg1, unsigned arg2, float arg3, short arg4);
    int method8(double arg0, double arg1, unsigned arg2, int arg3, float arg4);
    void method9(float arg0, float arg1, int arg2, bool arg3, int arg4);
    unsigned method10(bool arg0, double arg1, short arg2, float arg3, unsigned arg4);
    bool method11(int arg0, bool arg1, unsigned arg2, bool arg3, double arg4);
    double method12(double arg0, float arg1, double arg2, unsigned arg3, double arg4);
    void method13(float arg0, unsigned arg1, int arg2, bool arg3, double arg4);
    void method14(int arg0, unsigned arg1, short arg2, float arg3, unsigned arg4);

    double memberVariable0{};
    float memberVariable1{};
    int memberVariable2{};
    short memberVariable3{};
    bool memberVariable4{};
    short memberVariable5{};
    float memberVariable6{};
    bool memberVariable7{};
    short memberVariable8{};
    unsigned memberVariable9{};
    float memberVariable10{};
    bool memberVariable11{};
    double memberVariable12{};
    float memberVariable13{};
    double memberVariable14{};

    static void function0(float arg0, bool arg1, double arg2, double arg3, bool arg4);
    static void function1(short arg0, double arg1, unsigned arg2, short arg3, double arg4);
    static int function2(float arg0, int arg1, float arg2, float arg3, bool arg4);
    static void function3(double arg0, float arg1, double arg2, unsigned arg3, short arg4);
    static void function4(unsigned arg0, bool arg1, unsigned arg2, int arg3, short arg4);
    static void function5(bool arg0, float arg1, short arg2, float arg3, short arg4);
    static unsigned function6(int arg0, int arg1, unsigned arg2, int arg3, short arg4);
    static void function7(double arg0, int arg1, double arg2, short arg3, short arg4);
    static float function8(float arg0, float arg1, unsigned arg2, double arg3, short arg4);
    static void function9(double arg0, unsigned arg1, unsigned arg2, bool arg3, int arg4);
    static double function10(short arg0, double arg1, unsigned arg2, double arg3, double arg4);
    static float function11(float arg0, short arg1, double arg2, unsigned arg3, float arg4);
    static bool function12(short arg0, bool arg1, int arg2, float arg3, double arg4);
    static float function13(int arg0, float arg1, unsigned arg2, short arg3, unsigned arg4);
    static bool function14(bool arg0, short arg1, bool arg2, short arg3, unsigned arg4);

    inline static short variable0{};
    inline static int variable1{};
    inline static bool variable2{};
    inline static short variable3{};
    inline static bool variable4{};
    inline static float variable5{};
    inline static float variable6{};
    inline static float variable7{};
    inline static unsigned variable8{};
    inline static unsigned variable9{};
    inline static float variable10{};
    inline static int variable11{};
    inline static unsigned variable12{};
    inline static bool variable13{};
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
