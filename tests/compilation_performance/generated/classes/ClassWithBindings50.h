#pragma once

// Generated with seed '88005553585'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings1.h"
#include "ClassWithBindings11.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings95.h"
#include "ClassWithBindings98.h"
#include "ClassWithBindings99.h"

class ClassWithBindings50
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
    void method0(unsigned arg0, float arg1, bool arg2, float arg3, short arg4);
    bool method1(bool arg0, double arg1, double arg2, unsigned arg3, bool arg4);
    int method2(int arg0, bool arg1, unsigned arg2, bool arg3, unsigned arg4);
    void method3(int arg0, unsigned arg1, unsigned arg2, double arg3, bool arg4);
    bool method4(bool arg0, double arg1, unsigned arg2, short arg3, bool arg4);
    void method5(short arg0, short arg1, bool arg2, float arg3, unsigned arg4);
    void method6(double arg0, unsigned arg1, short arg2, bool arg3, float arg4);
    int method7(int arg0, bool arg1, int arg2, double arg3, unsigned arg4);
    short method8(bool arg0, short arg1, int arg2, short arg3, short arg4);
    void method9(unsigned arg0, bool arg1, short arg2, bool arg3, int arg4);
    int method10(double arg0, bool arg1, int arg2, short arg3, unsigned arg4);
    void method11(float arg0, bool arg1, int arg2, short arg3, short arg4);
    void method12(int arg0, int arg1, float arg2, double arg3, double arg4);
    double method13(short arg0, unsigned arg1, double arg2, bool arg3, bool arg4);
    void method14(short arg0, unsigned arg1, double arg2, int arg3, float arg4);

    unsigned memberVariable0{};
    float memberVariable1{};
    double memberVariable2{};
    short memberVariable3{};
    float memberVariable4{};
    int memberVariable5{};
    unsigned memberVariable6{};
    float memberVariable7{};
    unsigned memberVariable8{};
    double memberVariable9{};
    double memberVariable10{};
    float memberVariable11{};
    short memberVariable12{};
    unsigned memberVariable13{};
    int memberVariable14{};

    static unsigned function0(double arg0, double arg1, unsigned arg2, int arg3, unsigned arg4);
    static void function1(bool arg0, bool arg1, unsigned arg2, bool arg3, short arg4);
    static bool function2(unsigned arg0, unsigned arg1, int arg2, bool arg3, bool arg4);
    static float function3(short arg0, bool arg1, double arg2, double arg3, float arg4);
    static short function4(double arg0, unsigned arg1, int arg2, float arg3, short arg4);
    static int function5(unsigned arg0, short arg1, int arg2, short arg3, short arg4);
    static void function6(float arg0, bool arg1, int arg2, float arg3, float arg4);
    static float function7(unsigned arg0, float arg1, float arg2, unsigned arg3, float arg4);
    static void function8(float arg0, int arg1, bool arg2, int arg3, int arg4);
    static void function9(float arg0, short arg1, unsigned arg2, float arg3, bool arg4);
    static float function10(float arg0, unsigned arg1, unsigned arg2, float arg3, short arg4);
    static unsigned function11(unsigned arg0, int arg1, unsigned arg2, short arg3, float arg4);
    static unsigned function12(unsigned arg0, int arg1, float arg2, int arg3, unsigned arg4);
    static int function13(double arg0, bool arg1, int arg2, double arg3, short arg4);
    static float function14(float arg0, short arg1, int arg2, float arg3, bool arg4);

    inline static double variable0{};
    inline static unsigned variable1{};
    inline static int variable2{};
    inline static bool variable3{};
    inline static bool variable4{};
    inline static double variable5{};
    inline static unsigned variable6{};
    inline static double variable7{};
    inline static unsigned variable8{};
    inline static float variable9{};
    inline static double variable10{};
    inline static int variable11{};
    inline static short variable12{};
    inline static short variable13{};
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
