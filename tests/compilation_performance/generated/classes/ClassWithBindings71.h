#pragma once

// Generated with seed '88005553606'

#include "../../Common.h"

#include "ClassWithBindings4.h"
#include "ClassWithBindings8.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings67.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings75.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings86.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings91.h"
#include "ClassWithBindings95.h"

class ClassWithBindings71
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
    unsigned method0(unsigned arg0, bool arg1, bool arg2, float arg3, bool arg4);
    void method1(float arg0, bool arg1, bool arg2, int arg3, bool arg4);
    void method2(int arg0, float arg1, int arg2, float arg3, short arg4);
    void method3(double arg0, unsigned arg1, float arg2, int arg3, bool arg4);
    int method4(int arg0, bool arg1, int arg2, double arg3, double arg4);
    void method5(double arg0, double arg1, unsigned arg2, short arg3, int arg4);
    unsigned method6(unsigned arg0, unsigned arg1, double arg2, float arg3, unsigned arg4);
    double method7(float arg0, double arg1, int arg2, float arg3, short arg4);
    unsigned method8(int arg0, unsigned arg1, int arg2, int arg3, unsigned arg4);
    void method9(short arg0, bool arg1, short arg2, bool arg3, float arg4);
    short method10(unsigned arg0, int arg1, short arg2, double arg3, double arg4);
    void method11(float arg0, bool arg1, short arg2, int arg3, unsigned arg4);
    void method12(bool arg0, unsigned arg1, double arg2, unsigned arg3, unsigned arg4);
    bool method13(double arg0, unsigned arg1, short arg2, bool arg3, double arg4);
    unsigned method14(int arg0, short arg1, unsigned arg2, bool arg3, short arg4);

    unsigned memberVariable0{};
    short memberVariable1{};
    unsigned memberVariable2{};
    bool memberVariable3{};
    bool memberVariable4{};
    double memberVariable5{};
    short memberVariable6{};
    short memberVariable7{};
    unsigned memberVariable8{};
    int memberVariable9{};
    double memberVariable10{};
    int memberVariable11{};
    bool memberVariable12{};
    int memberVariable13{};
    float memberVariable14{};

    static void function0(int arg0, unsigned arg1, int arg2, bool arg3, bool arg4);
    static int function1(bool arg0, int arg1, int arg2, bool arg3, float arg4);
    static short function2(unsigned arg0, int arg1, short arg2, short arg3, float arg4);
    static float function3(short arg0, int arg1, float arg2, float arg3, float arg4);
    static void function4(float arg0, short arg1, double arg2, bool arg3, int arg4);
    static void function5(short arg0, bool arg1, short arg2, float arg3, unsigned arg4);
    static void function6(unsigned arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    static float function7(double arg0, bool arg1, float arg2, short arg3, unsigned arg4);
    static void function8(int arg0, double arg1, double arg2, short arg3, double arg4);
    static double function9(double arg0, float arg1, float arg2, unsigned arg3, double arg4);
    static void function10(unsigned arg0, unsigned arg1, unsigned arg2, int arg3, short arg4);
    static void function11(int arg0, int arg1, short arg2, float arg3, int arg4);
    static void function12(float arg0, float arg1, double arg2, bool arg3, unsigned arg4);
    static unsigned function13(unsigned arg0, short arg1, float arg2, bool arg3, float arg4);
    static int function14(double arg0, short arg1, int arg2, float arg3, float arg4);

    inline static unsigned variable0{};
    inline static short variable1{};
    inline static bool variable2{};
    inline static unsigned variable3{};
    inline static double variable4{};
    inline static float variable5{};
    inline static double variable6{};
    inline static int variable7{};
    inline static bool variable8{};
    inline static unsigned variable9{};
    inline static float variable10{};
    inline static short variable11{};
    inline static bool variable12{};
    inline static int variable13{};
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
