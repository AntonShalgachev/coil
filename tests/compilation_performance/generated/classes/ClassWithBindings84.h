#pragma once

// Generated with seed '88005553619'

#include "../../Common.h"

#include "ClassWithBindings2.h"
#include "ClassWithBindings4.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings11.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings67.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings96.h"

class ClassWithBindings84
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
    float method0(int arg0, float arg1, bool arg2, int arg3, unsigned arg4);
    unsigned method1(double arg0, unsigned arg1, float arg2, unsigned arg3, int arg4);
    short method2(double arg0, int arg1, int arg2, double arg3, short arg4);
    void method3(short arg0, double arg1, int arg2, unsigned arg3, double arg4);
    int method4(int arg0, bool arg1, double arg2, int arg3, double arg4);
    void method5(int arg0, bool arg1, int arg2, unsigned arg3, double arg4);
    void method6(bool arg0, short arg1, short arg2, bool arg3, int arg4);
    void method7(double arg0, int arg1, double arg2, int arg3, unsigned arg4);
    int method8(double arg0, double arg1, float arg2, int arg3, double arg4);
    void method9(bool arg0, double arg1, float arg2, float arg3, double arg4);
    void method10(bool arg0, bool arg1, bool arg2, double arg3, short arg4);
    void method11(float arg0, double arg1, unsigned arg2, double arg3, unsigned arg4);
    float method12(short arg0, float arg1, short arg2, double arg3, short arg4);
    void method13(bool arg0, short arg1, int arg2, float arg3, int arg4);
    void method14(short arg0, short arg1, float arg2, unsigned arg3, bool arg4);

    unsigned memberVariable0{};
    bool memberVariable1{};
    float memberVariable2{};
    unsigned memberVariable3{};
    float memberVariable4{};
    short memberVariable5{};
    float memberVariable6{};
    unsigned memberVariable7{};
    float memberVariable8{};
    double memberVariable9{};
    int memberVariable10{};
    short memberVariable11{};
    short memberVariable12{};
    float memberVariable13{};
    unsigned memberVariable14{};

    static bool function0(bool arg0, unsigned arg1, short arg2, bool arg3, double arg4);
    static void function1(short arg0, float arg1, float arg2, short arg3, int arg4);
    static void function2(double arg0, short arg1, float arg2, unsigned arg3, int arg4);
    static void function3(int arg0, int arg1, int arg2, float arg3, float arg4);
    static float function4(short arg0, float arg1, int arg2, bool arg3, bool arg4);
    static double function5(double arg0, float arg1, short arg2, bool arg3, unsigned arg4);
    static short function6(double arg0, short arg1, float arg2, bool arg3, short arg4);
    static void function7(short arg0, bool arg1, unsigned arg2, unsigned arg3, float arg4);
    static void function8(bool arg0, bool arg1, short arg2, int arg3, int arg4);
    static void function9(bool arg0, short arg1, short arg2, float arg3, bool arg4);
    static bool function10(bool arg0, bool arg1, unsigned arg2, float arg3, double arg4);
    static unsigned function11(unsigned arg0, float arg1, bool arg2, unsigned arg3, unsigned arg4);
    static void function12(unsigned arg0, float arg1, double arg2, bool arg3, short arg4);
    static unsigned function13(unsigned arg0, bool arg1, unsigned arg2, short arg3, short arg4);
    static bool function14(short arg0, bool arg1, double arg2, bool arg3, short arg4);

    inline static float variable0{};
    inline static bool variable1{};
    inline static int variable2{};
    inline static unsigned variable3{};
    inline static int variable4{};
    inline static short variable5{};
    inline static bool variable6{};
    inline static float variable7{};
    inline static int variable8{};
    inline static double variable9{};
    inline static short variable10{};
    inline static bool variable11{};
    inline static short variable12{};
    inline static unsigned variable13{};
    inline static unsigned variable14{};

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
