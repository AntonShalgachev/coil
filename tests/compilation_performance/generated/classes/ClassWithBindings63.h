#pragma once

// Generated with seed '88005553598'

#include "../../Common.h"

#include "ClassWithBindings8.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings16.h"
#include "ClassWithBindings20.h"
#include "ClassWithBindings22.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings76.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings93.h"
#include "ClassWithBindings95.h"
#include "ClassWithBindings97.h"
#include "ClassWithBindings99.h"

class ClassWithBindings63
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
    void method0(unsigned arg0, float arg1, short arg2, unsigned arg3, int arg4);
    void method1(short arg0, unsigned arg1, double arg2, unsigned arg3, int arg4);
    void method2(short arg0, int arg1, int arg2, double arg3, double arg4);
    float method3(float arg0, int arg1, unsigned arg2, double arg3, float arg4);
    void method4(double arg0, bool arg1, double arg2, double arg3, short arg4);
    bool method5(unsigned arg0, bool arg1, float arg2, int arg3, double arg4);
    void method6(double arg0, int arg1, unsigned arg2, double arg3, short arg4);
    void method7(double arg0, double arg1, double arg2, short arg3, unsigned arg4);
    float method8(short arg0, short arg1, float arg2, double arg3, float arg4);
    float method9(float arg0, int arg1, short arg2, float arg3, double arg4);
    int method10(int arg0, bool arg1, int arg2, unsigned arg3, short arg4);
    void method11(unsigned arg0, float arg1, short arg2, int arg3, float arg4);
    void method12(unsigned arg0, bool arg1, float arg2, int arg3, short arg4);
    unsigned method13(float arg0, short arg1, int arg2, unsigned arg3, int arg4);
    bool method14(bool arg0, int arg1, short arg2, int arg3, bool arg4);

    double memberVariable0{};
    unsigned memberVariable1{};
    bool memberVariable2{};
    int memberVariable3{};
    float memberVariable4{};
    bool memberVariable5{};
    bool memberVariable6{};
    short memberVariable7{};
    double memberVariable8{};
    float memberVariable9{};
    short memberVariable10{};
    bool memberVariable11{};
    double memberVariable12{};
    float memberVariable13{};
    unsigned memberVariable14{};

    static short function0(short arg0, int arg1, short arg2, unsigned arg3, unsigned arg4);
    static int function1(float arg0, float arg1, double arg2, int arg3, int arg4);
    static unsigned function2(short arg0, int arg1, unsigned arg2, short arg3, double arg4);
    static void function3(int arg0, short arg1, int arg2, double arg3, unsigned arg4);
    static unsigned function4(int arg0, unsigned arg1, float arg2, unsigned arg3, int arg4);
    static double function5(float arg0, int arg1, double arg2, short arg3, double arg4);
    static void function6(float arg0, bool arg1, double arg2, unsigned arg3, bool arg4);
    static short function7(double arg0, short arg1, short arg2, short arg3, unsigned arg4);
    static void function8(double arg0, double arg1, unsigned arg2, int arg3, unsigned arg4);
    static void function9(double arg0, int arg1, float arg2, unsigned arg3, int arg4);
    static void function10(unsigned arg0, short arg1, short arg2, bool arg3, int arg4);
    static void function11(double arg0, int arg1, double arg2, float arg3, int arg4);
    static float function12(int arg0, bool arg1, float arg2, short arg3, double arg4);
    static double function13(float arg0, double arg1, int arg2, short arg3, float arg4);
    static void function14(double arg0, float arg1, short arg2, short arg3, double arg4);

    inline static bool variable0{};
    inline static short variable1{};
    inline static bool variable2{};
    inline static float variable3{};
    inline static short variable4{};
    inline static int variable5{};
    inline static float variable6{};
    inline static short variable7{};
    inline static int variable8{};
    inline static float variable9{};
    inline static float variable10{};
    inline static bool variable11{};
    inline static short variable12{};
    inline static bool variable13{};
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
