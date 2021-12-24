#pragma once

// Generated with seed '88005553556'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings42.h"
#include "ClassWithBindings48.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings75.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings98.h"

class ClassWithBindings21
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
    void method0(unsigned arg0, float arg1, double arg2, double arg3, float arg4);
    void method1(unsigned arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
    void method2(int arg0, bool arg1, double arg2, double arg3, short arg4);
    void method3(int arg0, bool arg1, float arg2, unsigned arg3, bool arg4);
    bool method4(unsigned arg0, double arg1, bool arg2, unsigned arg3, short arg4);
    short method5(short arg0, short arg1, int arg2, short arg3, bool arg4);
    bool method6(bool arg0, int arg1, short arg2, int arg3, bool arg4);
    void method7(float arg0, short arg1, double arg2, float arg3, bool arg4);
    void method8(short arg0, short arg1, short arg2, int arg3, double arg4);
    void method9(unsigned arg0, double arg1, int arg2, short arg3, unsigned arg4);
    void method10(int arg0, unsigned arg1, bool arg2, bool arg3, unsigned arg4);
    short method11(int arg0, int arg1, float arg2, short arg3, float arg4);
    void method12(short arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    void method13(unsigned arg0, bool arg1, short arg2, short arg3, double arg4);
    void method14(short arg0, short arg1, bool arg2, short arg3, int arg4);

    short memberVariable0{};
    bool memberVariable1{};
    bool memberVariable2{};
    int memberVariable3{};
    bool memberVariable4{};
    int memberVariable5{};
    float memberVariable6{};
    unsigned memberVariable7{};
    float memberVariable8{};
    int memberVariable9{};
    unsigned memberVariable10{};
    unsigned memberVariable11{};
    unsigned memberVariable12{};
    double memberVariable13{};
    double memberVariable14{};

    static float function0(float arg0, float arg1, unsigned arg2, double arg3, unsigned arg4);
    static void function1(short arg0, short arg1, int arg2, bool arg3, double arg4);
    static void function2(unsigned arg0, float arg1, short arg2, int arg3, short arg4);
    static void function3(short arg0, float arg1, bool arg2, int arg3, double arg4);
    static double function4(bool arg0, int arg1, unsigned arg2, double arg3, int arg4);
    static int function5(unsigned arg0, double arg1, double arg2, int arg3, bool arg4);
    static bool function6(bool arg0, bool arg1, double arg2, double arg3, double arg4);
    static unsigned function7(short arg0, float arg1, float arg2, unsigned arg3, float arg4);
    static int function8(int arg0, short arg1, double arg2, unsigned arg3, short arg4);
    static void function9(float arg0, bool arg1, int arg2, short arg3, double arg4);
    static float function10(float arg0, unsigned arg1, short arg2, double arg3, bool arg4);
    static void function11(bool arg0, bool arg1, float arg2, float arg3, short arg4);
    static void function12(unsigned arg0, float arg1, int arg2, double arg3, double arg4);
    static float function13(float arg0, int arg1, float arg2, double arg3, float arg4);
    static int function14(int arg0, int arg1, short arg2, double arg3, int arg4);

    inline static short variable0{};
    inline static unsigned variable1{};
    inline static bool variable2{};
    inline static int variable3{};
    inline static unsigned variable4{};
    inline static double variable5{};
    inline static int variable6{};
    inline static unsigned variable7{};
    inline static short variable8{};
    inline static bool variable9{};
    inline static short variable10{};
    inline static float variable11{};
    inline static bool variable12{};
    inline static double variable13{};
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
