#pragma once

// Generated with seed '88005553561'

#include "../../Common.h"

#include "ClassWithBindings21.h"
#include "ClassWithBindings22.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings42.h"
#include "ClassWithBindings43.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings48.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings63.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings83.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings89.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings94.h"

class ClassWithBindings26
{
public:
    void work();

#if USE_COIL
    void registerBindings(coil::Bindings& bindings);
#endif

#if USE_MANUAL
    void registerBindings(DumbBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(int arg0, float arg1, float arg2, int arg3, unsigned arg4);
    int method1(int arg0, int arg1, double arg2, double arg3, int arg4);
    void method2(int arg0, float arg1, int arg2, double arg3, int arg4);
    void method3(short arg0, unsigned arg1, int arg2, bool arg3, double arg4);
    void method4(float arg0, float arg1, unsigned arg2, unsigned arg3, double arg4);
    unsigned method5(bool arg0, unsigned arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method6(double arg0, int arg1, bool arg2, int arg3, float arg4);
    bool method7(float arg0, double arg1, int arg2, float arg3, bool arg4);
    void method8(bool arg0, short arg1, unsigned arg2, double arg3, bool arg4);
    unsigned method9(unsigned arg0, short arg1, double arg2, bool arg3, double arg4);
    short method10(double arg0, short arg1, unsigned arg2, bool arg3, bool arg4);
    void method11(short arg0, double arg1, short arg2, short arg3, double arg4);
    double method12(double arg0, double arg1, float arg2, short arg3, short arg4);
    unsigned method13(bool arg0, short arg1, unsigned arg2, unsigned arg3, short arg4);
    float method14(unsigned arg0, bool arg1, float arg2, short arg3, float arg4);

    float memberVariable0{};
    int memberVariable1{};
    int memberVariable2{};
    unsigned memberVariable3{};
    float memberVariable4{};
    short memberVariable5{};
    bool memberVariable6{};
    int memberVariable7{};
    double memberVariable8{};
    unsigned memberVariable9{};
    float memberVariable10{};
    int memberVariable11{};
    short memberVariable12{};
    unsigned memberVariable13{};
    bool memberVariable14{};

    static void function0(unsigned arg0, unsigned arg1, bool arg2, int arg3, float arg4);
    static void function1(double arg0, float arg1, short arg2, unsigned arg3, double arg4);
    static bool function2(short arg0, short arg1, bool arg2, float arg3, int arg4);
    static bool function3(bool arg0, bool arg1, bool arg2, short arg3, bool arg4);
    static void function4(int arg0, float arg1, int arg2, double arg3, double arg4);
    static void function5(unsigned arg0, int arg1, double arg2, double arg3, short arg4);
    static unsigned function6(short arg0, float arg1, short arg2, unsigned arg3, float arg4);
    static void function7(int arg0, double arg1, short arg2, double arg3, bool arg4);
    static float function8(float arg0, float arg1, float arg2, unsigned arg3, double arg4);
    static void function9(unsigned arg0, float arg1, double arg2, bool arg3, int arg4);
    static int function10(double arg0, short arg1, double arg2, int arg3, int arg4);
    static void function11(short arg0, double arg1, double arg2, float arg3, unsigned arg4);
    static void function12(short arg0, int arg1, bool arg2, float arg3, bool arg4);
    static void function13(bool arg0, short arg1, double arg2, bool arg3, int arg4);
    static void function14(int arg0, unsigned arg1, short arg2, bool arg3, double arg4);

    inline static bool variable0{};
    inline static short variable1{};
    inline static short variable2{};
    inline static unsigned variable3{};
    inline static float variable4{};
    inline static short variable5{};
    inline static int variable6{};
    inline static unsigned variable7{};
    inline static double variable8{};
    inline static bool variable9{};
    inline static bool variable10{};
    inline static unsigned variable11{};
    inline static short variable12{};
    inline static int variable13{};
    inline static bool variable14{};

#if USE_MANUAL
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
