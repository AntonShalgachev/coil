#pragma once

// Generated with seed '88005553569'

#include "../../Common.h"

#include "ClassWithBindings2.h"
#include "ClassWithBindings3.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings18.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings83.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings95.h"

class ClassWithBindings34
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
    void method0(float arg0, float arg1, float arg2, float arg3, bool arg4);
    void method1(int arg0, short arg1, bool arg2, int arg3, bool arg4);
    void method2(bool arg0, double arg1, bool arg2, float arg3, bool arg4);
    unsigned method3(bool arg0, float arg1, double arg2, unsigned arg3, unsigned arg4);
    void method4(short arg0, int arg1, bool arg2, bool arg3, int arg4);
    int method5(short arg0, int arg1, unsigned arg2, double arg3, bool arg4);
    int method6(int arg0, bool arg1, double arg2, bool arg3, double arg4);
    double method7(double arg0, double arg1, double arg2, bool arg3, int arg4);
    void method8(double arg0, bool arg1, bool arg2, int arg3, float arg4);
    int method9(int arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    short method10(short arg0, int arg1, float arg2, bool arg3, float arg4);
    void method11(float arg0, float arg1, float arg2, unsigned arg3, float arg4);
    void method12(unsigned arg0, unsigned arg1, bool arg2, short arg3, short arg4);
    float method13(double arg0, short arg1, short arg2, float arg3, unsigned arg4);
    unsigned method14(float arg0, unsigned arg1, int arg2, int arg3, unsigned arg4);

    int memberVariable0{};
    unsigned memberVariable1{};
    int memberVariable2{};
    int memberVariable3{};
    int memberVariable4{};
    unsigned memberVariable5{};
    bool memberVariable6{};
    float memberVariable7{};
    short memberVariable8{};
    short memberVariable9{};
    bool memberVariable10{};
    bool memberVariable11{};
    bool memberVariable12{};
    double memberVariable13{};
    short memberVariable14{};

    static double function0(float arg0, int arg1, short arg2, double arg3, float arg4);
    static void function1(bool arg0, double arg1, bool arg2, short arg3, int arg4);
    static void function2(double arg0, unsigned arg1, unsigned arg2, double arg3, bool arg4);
    static void function3(double arg0, bool arg1, unsigned arg2, float arg3, short arg4);
    static double function4(bool arg0, int arg1, int arg2, double arg3, double arg4);
    static void function5(float arg0, unsigned arg1, bool arg2, int arg3, double arg4);
    static void function6(float arg0, float arg1, double arg2, int arg3, float arg4);
    static void function7(int arg0, double arg1, int arg2, double arg3, unsigned arg4);
    static unsigned function8(short arg0, float arg1, double arg2, float arg3, unsigned arg4);
    static void function9(int arg0, int arg1, short arg2, bool arg3, int arg4);
    static void function10(short arg0, float arg1, bool arg2, double arg3, double arg4);
    static void function11(float arg0, bool arg1, unsigned arg2, unsigned arg3, int arg4);
    static double function12(bool arg0, double arg1, int arg2, bool arg3, int arg4);
    static void function13(bool arg0, unsigned arg1, float arg2, bool arg3, int arg4);
    static void function14(bool arg0, bool arg1, short arg2, unsigned arg3, unsigned arg4);

    inline static float variable0{};
    inline static short variable1{};
    inline static short variable2{};
    inline static double variable3{};
    inline static float variable4{};
    inline static unsigned variable5{};
    inline static bool variable6{};
    inline static int variable7{};
    inline static short variable8{};
    inline static float variable9{};
    inline static double variable10{};
    inline static bool variable11{};
    inline static int variable12{};
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
