#pragma once

// Generated with seed '88005553539'

#include "../../Common.h"

#include "ClassWithBindings1.h"
#include "ClassWithBindings8.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings18.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings34.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings63.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings88.h"
#include "ClassWithBindings92.h"

class ClassWithBindings4
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
    void method0(int arg0, int arg1, unsigned arg2, short arg3, short arg4);
    void method1(bool arg0, double arg1, int arg2, int arg3, int arg4);
    float method2(double arg0, int arg1, float arg2, float arg3, float arg4);
    void method3(double arg0, bool arg1, short arg2, int arg3, bool arg4);
    void method4(double arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    unsigned method5(unsigned arg0, short arg1, bool arg2, short arg3, bool arg4);
    void method6(double arg0, float arg1, bool arg2, short arg3, float arg4);
    float method7(bool arg0, bool arg1, float arg2, unsigned arg3, bool arg4);
    void method8(int arg0, short arg1, int arg2, bool arg3, int arg4);
    bool method9(short arg0, double arg1, bool arg2, float arg3, short arg4);
    void method10(short arg0, float arg1, short arg2, bool arg3, double arg4);
    unsigned method11(unsigned arg0, short arg1, unsigned arg2, double arg3, float arg4);
    unsigned method12(unsigned arg0, unsigned arg1, short arg2, short arg3, bool arg4);
    void method13(float arg0, unsigned arg1, int arg2, short arg3, double arg4);
    bool method14(unsigned arg0, bool arg1, double arg2, unsigned arg3, double arg4);

    bool memberVariable0{};
    short memberVariable1{};
    unsigned memberVariable2{};
    unsigned memberVariable3{};
    int memberVariable4{};
    double memberVariable5{};
    float memberVariable6{};
    short memberVariable7{};
    float memberVariable8{};
    unsigned memberVariable9{};
    int memberVariable10{};
    float memberVariable11{};
    double memberVariable12{};
    float memberVariable13{};
    double memberVariable14{};

    static void function0(float arg0, short arg1, double arg2, unsigned arg3, short arg4);
    static void function1(int arg0, unsigned arg1, double arg2, bool arg3, float arg4);
    static void function2(double arg0, int arg1, unsigned arg2, unsigned arg3, int arg4);
    static short function3(bool arg0, float arg1, short arg2, short arg3, int arg4);
    static unsigned function4(unsigned arg0, short arg1, unsigned arg2, unsigned arg3, short arg4);
    static int function5(int arg0, bool arg1, int arg2, float arg3, short arg4);
    static void function6(double arg0, double arg1, bool arg2, short arg3, unsigned arg4);
    static void function7(double arg0, double arg1, int arg2, bool arg3, short arg4);
    static void function8(double arg0, float arg1, short arg2, int arg3, float arg4);
    static void function9(bool arg0, short arg1, short arg2, double arg3, double arg4);
    static int function10(int arg0, bool arg1, bool arg2, int arg3, bool arg4);
    static bool function11(float arg0, int arg1, bool arg2, bool arg3, float arg4);
    static int function12(unsigned arg0, float arg1, int arg2, float arg3, int arg4);
    static bool function13(unsigned arg0, int arg1, unsigned arg2, bool arg3, bool arg4);
    static int function14(short arg0, int arg1, unsigned arg2, int arg3, bool arg4);

    inline static int variable0{};
    inline static short variable1{};
    inline static float variable2{};
    inline static double variable3{};
    inline static int variable4{};
    inline static double variable5{};
    inline static double variable6{};
    inline static short variable7{};
    inline static short variable8{};
    inline static bool variable9{};
    inline static int variable10{};
    inline static double variable11{};
    inline static double variable12{};
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
