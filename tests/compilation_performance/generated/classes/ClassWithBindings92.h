#pragma once

// Generated with seed '88005553627'

#include "../../Common.h"

#include "ClassWithBindings7.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings81.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings86.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings95.h"

class ClassWithBindings92
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
    void method0(int arg0, double arg1, double arg2, short arg3, int arg4);
    void method1(int arg0, unsigned arg1, short arg2, unsigned arg3, float arg4);
    short method2(unsigned arg0, float arg1, short arg2, bool arg3, short arg4);
    void method3(int arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    void method4(short arg0, float arg1, unsigned arg2, bool arg3, short arg4);
    short method5(short arg0, unsigned arg1, short arg2, int arg3, unsigned arg4);
    unsigned method6(unsigned arg0, float arg1, int arg2, unsigned arg3, unsigned arg4);
    short method7(float arg0, float arg1, unsigned arg2, int arg3, short arg4);
    void method8(int arg0, unsigned arg1, int arg2, unsigned arg3, float arg4);
    double method9(double arg0, unsigned arg1, double arg2, int arg3, bool arg4);
    short method10(short arg0, short arg1, short arg2, double arg3, unsigned arg4);
    void method11(float arg0, double arg1, short arg2, bool arg3, float arg4);
    bool method12(bool arg0, short arg1, float arg2, short arg3, float arg4);
    int method13(int arg0, int arg1, double arg2, int arg3, bool arg4);
    int method14(short arg0, double arg1, bool arg2, unsigned arg3, int arg4);

    bool memberVariable0{};
    int memberVariable1{};
    double memberVariable2{};
    bool memberVariable3{};
    int memberVariable4{};
    int memberVariable5{};
    short memberVariable6{};
    float memberVariable7{};
    unsigned memberVariable8{};
    bool memberVariable9{};
    bool memberVariable10{};
    double memberVariable11{};
    int memberVariable12{};
    int memberVariable13{};
    int memberVariable14{};

    static void function0(short arg0, bool arg1, int arg2, bool arg3, bool arg4);
    static void function1(bool arg0, short arg1, double arg2, short arg3, double arg4);
    static double function2(float arg0, double arg1, float arg2, unsigned arg3, float arg4);
    static unsigned function3(float arg0, float arg1, short arg2, unsigned arg3, bool arg4);
    static void function4(float arg0, short arg1, float arg2, short arg3, int arg4);
    static void function5(int arg0, short arg1, double arg2, int arg3, int arg4);
    static short function6(short arg0, short arg1, bool arg2, bool arg3, bool arg4);
    static int function7(int arg0, bool arg1, bool arg2, int arg3, bool arg4);
    static short function8(short arg0, short arg1, float arg2, unsigned arg3, unsigned arg4);
    static unsigned function9(unsigned arg0, double arg1, double arg2, unsigned arg3, bool arg4);
    static void function10(short arg0, short arg1, short arg2, double arg3, double arg4);
    static void function11(float arg0, double arg1, unsigned arg2, unsigned arg3, short arg4);
    static void function12(float arg0, int arg1, int arg2, unsigned arg3, unsigned arg4);
    static unsigned function13(unsigned arg0, int arg1, unsigned arg2, int arg3, double arg4);
    static void function14(short arg0, short arg1, float arg2, double arg3, short arg4);

    inline static float variable0{};
    inline static int variable1{};
    inline static short variable2{};
    inline static unsigned variable3{};
    inline static short variable4{};
    inline static bool variable5{};
    inline static float variable6{};
    inline static float variable7{};
    inline static double variable8{};
    inline static float variable9{};
    inline static double variable10{};
    inline static unsigned variable11{};
    inline static short variable12{};
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
