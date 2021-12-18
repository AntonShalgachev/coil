#pragma once

// Generated with seed '88005553537'

#include "../../Common.h"

#include "ClassWithBindings6.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings76.h"
#include "ClassWithBindings83.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings86.h"
#include "ClassWithBindings87.h"
#include "ClassWithBindings88.h"
#include "ClassWithBindings89.h"
#include "ClassWithBindings93.h"

class ClassWithBindings2
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
    int method0(int arg0, double arg1, unsigned arg2, short arg3, int arg4);
    void method1(double arg0, double arg1, bool arg2, short arg3, unsigned arg4);
    bool method2(short arg0, float arg1, short arg2, int arg3, bool arg4);
    void method3(float arg0, unsigned arg1, double arg2, float arg3, int arg4);
    float method4(float arg0, int arg1, unsigned arg2, unsigned arg3, short arg4);
    void method5(bool arg0, bool arg1, bool arg2, double arg3, unsigned arg4);
    void method6(int arg0, float arg1, float arg2, short arg3, float arg4);
    int method7(short arg0, short arg1, float arg2, int arg3, double arg4);
    short method8(short arg0, int arg1, bool arg2, double arg3, unsigned arg4);
    void method9(double arg0, float arg1, unsigned arg2, double arg3, float arg4);
    double method10(double arg0, unsigned arg1, double arg2, int arg3, float arg4);
    float method11(short arg0, short arg1, bool arg2, float arg3, unsigned arg4);
    void method12(float arg0, float arg1, bool arg2, short arg3, short arg4);
    void method13(double arg0, unsigned arg1, short arg2, bool arg3, bool arg4);
    void method14(double arg0, bool arg1, bool arg2, int arg3, double arg4);

    int memberVariable0{};
    unsigned memberVariable1{};
    unsigned memberVariable2{};
    short memberVariable3{};
    double memberVariable4{};
    bool memberVariable5{};
    int memberVariable6{};
    int memberVariable7{};
    float memberVariable8{};
    float memberVariable9{};
    double memberVariable10{};
    float memberVariable11{};
    bool memberVariable12{};
    unsigned memberVariable13{};
    bool memberVariable14{};

    static void function0(double arg0, bool arg1, short arg2, bool arg3, short arg4);
    static void function1(float arg0, double arg1, unsigned arg2, unsigned arg3, float arg4);
    static void function2(short arg0, float arg1, float arg2, short arg3, unsigned arg4);
    static void function3(unsigned arg0, bool arg1, bool arg2, float arg3, bool arg4);
    static short function4(bool arg0, unsigned arg1, bool arg2, short arg3, short arg4);
    static void function5(unsigned arg0, bool arg1, short arg2, unsigned arg3, short arg4);
    static void function6(short arg0, unsigned arg1, double arg2, unsigned arg3, unsigned arg4);
    static float function7(double arg0, float arg1, unsigned arg2, unsigned arg3, bool arg4);
    static void function8(unsigned arg0, int arg1, bool arg2, int arg3, float arg4);
    static bool function9(int arg0, double arg1, int arg2, float arg3, bool arg4);
    static void function10(bool arg0, unsigned arg1, short arg2, double arg3, float arg4);
    static void function11(double arg0, bool arg1, float arg2, float arg3, unsigned arg4);
    static bool function12(short arg0, bool arg1, bool arg2, short arg3, unsigned arg4);
    static void function13(int arg0, int arg1, int arg2, float arg3, int arg4);
    static void function14(bool arg0, float arg1, double arg2, float arg3, double arg4);

    inline static short variable0{};
    inline static short variable1{};
    inline static unsigned variable2{};
    inline static int variable3{};
    inline static bool variable4{};
    inline static double variable5{};
    inline static short variable6{};
    inline static short variable7{};
    inline static unsigned variable8{};
    inline static short variable9{};
    inline static float variable10{};
    inline static short variable11{};
    inline static unsigned variable12{};
    inline static int variable13{};
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
