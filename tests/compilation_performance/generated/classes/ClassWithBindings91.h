#pragma once

// Generated with seed '88005553626'

#include "../../Common.h"

#include "ClassWithBindings12.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings24.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings63.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings81.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings86.h"

class ClassWithBindings91
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
    int method0(float arg0, double arg1, int arg2, int arg3, float arg4);
    void method1(bool arg0, unsigned arg1, int arg2, bool arg3, int arg4);
    void method2(bool arg0, unsigned arg1, int arg2, double arg3, double arg4);
    double method3(double arg0, bool arg1, bool arg2, int arg3, float arg4);
    void method4(int arg0, int arg1, unsigned arg2, float arg3, int arg4);
    bool method5(bool arg0, int arg1, short arg2, unsigned arg3, double arg4);
    void method6(short arg0, double arg1, double arg2, int arg3, unsigned arg4);
    short method7(double arg0, short arg1, bool arg2, short arg3, bool arg4);
    void method8(short arg0, unsigned arg1, unsigned arg2, double arg3, unsigned arg4);
    void method9(bool arg0, short arg1, double arg2, short arg3, short arg4);
    double method10(double arg0, int arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method11(bool arg0, short arg1, float arg2, unsigned arg3, short arg4);
    void method12(unsigned arg0, short arg1, short arg2, float arg3, int arg4);
    void method13(bool arg0, double arg1, float arg2, int arg3, double arg4);
    short method14(short arg0, bool arg1, short arg2, float arg3, short arg4);

    unsigned memberVariable0{};
    float memberVariable1{};
    short memberVariable2{};
    short memberVariable3{};
    int memberVariable4{};
    int memberVariable5{};
    short memberVariable6{};
    int memberVariable7{};
    int memberVariable8{};
    float memberVariable9{};
    bool memberVariable10{};
    float memberVariable11{};
    int memberVariable12{};
    short memberVariable13{};
    short memberVariable14{};

    static void function0(unsigned arg0, int arg1, double arg2, double arg3, float arg4);
    static void function1(unsigned arg0, unsigned arg1, float arg2, unsigned arg3, short arg4);
    static double function2(float arg0, double arg1, int arg2, double arg3, float arg4);
    static void function3(unsigned arg0, short arg1, bool arg2, float arg3, short arg4);
    static double function4(float arg0, short arg1, bool arg2, short arg3, double arg4);
    static void function5(float arg0, unsigned arg1, double arg2, int arg3, bool arg4);
    static double function6(int arg0, bool arg1, short arg2, double arg3, bool arg4);
    static void function7(double arg0, int arg1, double arg2, short arg3, int arg4);
    static int function8(short arg0, bool arg1, short arg2, unsigned arg3, int arg4);
    static unsigned function9(int arg0, short arg1, unsigned arg2, bool arg3, float arg4);
    static void function10(float arg0, float arg1, bool arg2, float arg3, unsigned arg4);
    static int function11(int arg0, double arg1, double arg2, double arg3, short arg4);
    static void function12(int arg0, bool arg1, short arg2, double arg3, bool arg4);
    static float function13(int arg0, int arg1, short arg2, double arg3, float arg4);
    static double function14(double arg0, short arg1, unsigned arg2, double arg3, unsigned arg4);

    inline static float variable0{};
    inline static bool variable1{};
    inline static double variable2{};
    inline static double variable3{};
    inline static unsigned variable4{};
    inline static float variable5{};
    inline static int variable6{};
    inline static int variable7{};
    inline static double variable8{};
    inline static short variable9{};
    inline static short variable10{};
    inline static int variable11{};
    inline static unsigned variable12{};
    inline static float variable13{};
    inline static double variable14{};

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
