#pragma once

// Generated with seed '88005553550'

#include "../../Common.h"

#include "ClassWithBindings5.h"
#include "ClassWithBindings7.h"
#include "ClassWithBindings8.h"
#include "ClassWithBindings10.h"
#include "ClassWithBindings34.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings78.h"
#include "ClassWithBindings81.h"
#include "ClassWithBindings83.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings86.h"

class ClassWithBindings15
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
    float method0(double arg0, double arg1, double arg2, float arg3, double arg4);
    void method1(int arg0, short arg1, bool arg2, unsigned arg3, float arg4);
    bool method2(bool arg0, double arg1, short arg2, int arg3, double arg4);
    short method3(unsigned arg0, short arg1, double arg2, short arg3, int arg4);
    float method4(bool arg0, int arg1, unsigned arg2, float arg3, bool arg4);
    void method5(double arg0, double arg1, unsigned arg2, bool arg3, float arg4);
    void method6(int arg0, float arg1, bool arg2, unsigned arg3, double arg4);
    void method7(bool arg0, float arg1, double arg2, double arg3, unsigned arg4);
    float method8(bool arg0, float arg1, double arg2, float arg3, float arg4);
    double method9(unsigned arg0, double arg1, unsigned arg2, int arg3, short arg4);
    short method10(bool arg0, short arg1, unsigned arg2, short arg3, int arg4);
    bool method11(int arg0, bool arg1, int arg2, double arg3, short arg4);
    void method12(short arg0, double arg1, short arg2, float arg3, short arg4);
    void method13(short arg0, short arg1, unsigned arg2, float arg3, unsigned arg4);
    void method14(double arg0, double arg1, int arg2, short arg3, float arg4);

    double memberVariable0{};
    int memberVariable1{};
    short memberVariable2{};
    double memberVariable3{};
    unsigned memberVariable4{};
    unsigned memberVariable5{};
    bool memberVariable6{};
    unsigned memberVariable7{};
    float memberVariable8{};
    double memberVariable9{};
    unsigned memberVariable10{};
    double memberVariable11{};
    float memberVariable12{};
    unsigned memberVariable13{};
    short memberVariable14{};

    static void function0(bool arg0, bool arg1, short arg2, int arg3, double arg4);
    static void function1(float arg0, short arg1, float arg2, int arg3, bool arg4);
    static short function2(short arg0, bool arg1, short arg2, double arg3, short arg4);
    static void function3(float arg0, float arg1, bool arg2, short arg3, double arg4);
    static void function4(float arg0, int arg1, double arg2, short arg3, float arg4);
    static void function5(double arg0, float arg1, int arg2, float arg3, short arg4);
    static int function6(short arg0, unsigned arg1, int arg2, unsigned arg3, int arg4);
    static void function7(unsigned arg0, int arg1, float arg2, unsigned arg3, int arg4);
    static unsigned function8(int arg0, float arg1, unsigned arg2, double arg3, unsigned arg4);
    static void function9(float arg0, int arg1, float arg2, double arg3, bool arg4);
    static void function10(int arg0, int arg1, short arg2, unsigned arg3, bool arg4);
    static unsigned function11(unsigned arg0, double arg1, short arg2, unsigned arg3, double arg4);
    static unsigned function12(short arg0, short arg1, unsigned arg2, bool arg3, int arg4);
    static unsigned function13(double arg0, short arg1, double arg2, unsigned arg3, int arg4);
    static float function14(unsigned arg0, float arg1, double arg2, unsigned arg3, double arg4);

    inline static short variable0{};
    inline static double variable1{};
    inline static unsigned variable2{};
    inline static short variable3{};
    inline static bool variable4{};
    inline static int variable5{};
    inline static float variable6{};
    inline static bool variable7{};
    inline static short variable8{};
    inline static double variable9{};
    inline static int variable10{};
    inline static short variable11{};
    inline static int variable12{};
    inline static float variable13{};
    inline static unsigned variable14{};

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
