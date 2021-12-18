#pragma once

// Generated with seed '88005553622'

#include "../../Common.h"

#include "ClassWithBindings2.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings42.h"
#include "ClassWithBindings43.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings94.h"
#include "ClassWithBindings99.h"

class ClassWithBindings87
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
    bool method0(double arg0, int arg1, float arg2, unsigned arg3, bool arg4);
    void method1(unsigned arg0, short arg1, int arg2, short arg3, double arg4);
    void method2(bool arg0, short arg1, double arg2, float arg3, unsigned arg4);
    unsigned method3(unsigned arg0, double arg1, int arg2, float arg3, short arg4);
    void method4(short arg0, bool arg1, float arg2, unsigned arg3, bool arg4);
    int method5(int arg0, float arg1, unsigned arg2, unsigned arg3, double arg4);
    void method6(float arg0, short arg1, int arg2, unsigned arg3, float arg4);
    void method7(bool arg0, float arg1, short arg2, short arg3, int arg4);
    short method8(short arg0, float arg1, bool arg2, double arg3, short arg4);
    void method9(short arg0, int arg1, float arg2, float arg3, double arg4);
    short method10(double arg0, short arg1, float arg2, unsigned arg3, short arg4);
    void method11(double arg0, int arg1, bool arg2, short arg3, short arg4);
    unsigned method12(bool arg0, unsigned arg1, int arg2, unsigned arg3, double arg4);
    void method13(bool arg0, double arg1, float arg2, bool arg3, short arg4);
    void method14(int arg0, int arg1, int arg2, int arg3, double arg4);

    short memberVariable0{};
    short memberVariable1{};
    bool memberVariable2{};
    double memberVariable3{};
    float memberVariable4{};
    unsigned memberVariable5{};
    short memberVariable6{};
    short memberVariable7{};
    unsigned memberVariable8{};
    bool memberVariable9{};
    float memberVariable10{};
    unsigned memberVariable11{};
    short memberVariable12{};
    int memberVariable13{};
    short memberVariable14{};

    static void function0(float arg0, double arg1, double arg2, double arg3, int arg4);
    static void function1(double arg0, float arg1, bool arg2, unsigned arg3, unsigned arg4);
    static void function2(short arg0, bool arg1, unsigned arg2, unsigned arg3, short arg4);
    static bool function3(int arg0, bool arg1, bool arg2, double arg3, bool arg4);
    static void function4(bool arg0, bool arg1, int arg2, bool arg3, double arg4);
    static void function5(bool arg0, int arg1, double arg2, float arg3, int arg4);
    static void function6(float arg0, float arg1, unsigned arg2, bool arg3, bool arg4);
    static void function7(unsigned arg0, bool arg1, float arg2, double arg3, int arg4);
    static void function8(bool arg0, float arg1, unsigned arg2, int arg3, short arg4);
    static bool function9(short arg0, short arg1, bool arg2, short arg3, int arg4);
    static void function10(double arg0, short arg1, int arg2, double arg3, short arg4);
    static void function11(int arg0, float arg1, int arg2, bool arg3, bool arg4);
    static void function12(float arg0, float arg1, short arg2, float arg3, double arg4);
    static double function13(double arg0, float arg1, unsigned arg2, short arg3, short arg4);
    static int function14(short arg0, int arg1, int arg2, unsigned arg3, short arg4);

    inline static float variable0{};
    inline static float variable1{};
    inline static unsigned variable2{};
    inline static double variable3{};
    inline static short variable4{};
    inline static unsigned variable5{};
    inline static float variable6{};
    inline static double variable7{};
    inline static double variable8{};
    inline static float variable9{};
    inline static bool variable10{};
    inline static bool variable11{};
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
