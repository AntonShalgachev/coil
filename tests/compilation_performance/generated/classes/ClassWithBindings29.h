#pragma once

// Generated with seed '88005553564'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings8.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings24.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings42.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings78.h"
#include "ClassWithBindings81.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings86.h"
#include "ClassWithBindings89.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings97.h"

class ClassWithBindings29
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
    void method0(unsigned arg0, float arg1, float arg2, bool arg3, int arg4);
    unsigned method1(short arg0, unsigned arg1, unsigned arg2, short arg3, int arg4);
    short method2(short arg0, short arg1, short arg2, int arg3, int arg4);
    unsigned method3(float arg0, unsigned arg1, unsigned arg2, short arg3, short arg4);
    double method4(float arg0, int arg1, float arg2, double arg3, bool arg4);
    bool method5(bool arg0, int arg1, bool arg2, bool arg3, bool arg4);
    double method6(short arg0, int arg1, bool arg2, int arg3, double arg4);
    double method7(float arg0, unsigned arg1, bool arg2, float arg3, double arg4);
    void method8(double arg0, double arg1, short arg2, double arg3, double arg4);
    void method9(short arg0, double arg1, bool arg2, short arg3, short arg4);
    short method10(double arg0, short arg1, short arg2, unsigned arg3, float arg4);
    void method11(unsigned arg0, unsigned arg1, unsigned arg2, float arg3, unsigned arg4);
    void method12(short arg0, unsigned arg1, unsigned arg2, unsigned arg3, double arg4);
    unsigned method13(float arg0, unsigned arg1, unsigned arg2, double arg3, double arg4);
    unsigned method14(double arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);

    float memberVariable0{};
    int memberVariable1{};
    unsigned memberVariable2{};
    unsigned memberVariable3{};
    bool memberVariable4{};
    bool memberVariable5{};
    unsigned memberVariable6{};
    unsigned memberVariable7{};
    short memberVariable8{};
    double memberVariable9{};
    int memberVariable10{};
    bool memberVariable11{};
    double memberVariable12{};
    bool memberVariable13{};
    int memberVariable14{};

    static void function0(int arg0, float arg1, float arg2, float arg3, double arg4);
    static unsigned function1(short arg0, short arg1, double arg2, unsigned arg3, unsigned arg4);
    static bool function2(double arg0, short arg1, float arg2, short arg3, bool arg4);
    static void function3(bool arg0, bool arg1, double arg2, double arg3, int arg4);
    static void function4(short arg0, int arg1, short arg2, unsigned arg3, short arg4);
    static short function5(int arg0, unsigned arg1, float arg2, short arg3, double arg4);
    static unsigned function6(unsigned arg0, short arg1, short arg2, unsigned arg3, unsigned arg4);
    static void function7(int arg0, float arg1, double arg2, bool arg3, short arg4);
    static void function8(float arg0, unsigned arg1, int arg2, float arg3, float arg4);
    static void function9(double arg0, short arg1, unsigned arg2, double arg3, float arg4);
    static void function10(bool arg0, unsigned arg1, int arg2, bool arg3, unsigned arg4);
    static int function11(float arg0, float arg1, unsigned arg2, double arg3, int arg4);
    static void function12(int arg0, bool arg1, bool arg2, int arg3, double arg4);
    static void function13(unsigned arg0, double arg1, unsigned arg2, int arg3, float arg4);
    static float function14(double arg0, double arg1, int arg2, bool arg3, float arg4);

    inline static bool variable0{};
    inline static short variable1{};
    inline static unsigned variable2{};
    inline static short variable3{};
    inline static bool variable4{};
    inline static float variable5{};
    inline static bool variable6{};
    inline static int variable7{};
    inline static short variable8{};
    inline static int variable9{};
    inline static unsigned variable10{};
    inline static unsigned variable11{};
    inline static short variable12{};
    inline static float variable13{};
    inline static short variable14{};

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
