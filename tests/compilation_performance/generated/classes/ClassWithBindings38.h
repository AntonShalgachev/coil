#pragma once

// Generated with seed '88005553573'

#include "../../Common.h"

#include "ClassWithBindings2.h"
#include "ClassWithBindings3.h"
#include "ClassWithBindings6.h"
#include "ClassWithBindings7.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings24.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings86.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings91.h"
#include "ClassWithBindings96.h"
#include "ClassWithBindings99.h"

class ClassWithBindings38
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
    unsigned method0(float arg0, unsigned arg1, short arg2, double arg3, float arg4);
    bool method1(unsigned arg0, short arg1, bool arg2, bool arg3, short arg4);
    void method2(short arg0, bool arg1, short arg2, short arg3, bool arg4);
    float method3(bool arg0, float arg1, bool arg2, int arg3, double arg4);
    int method4(int arg0, short arg1, int arg2, bool arg3, int arg4);
    void method5(float arg0, bool arg1, double arg2, float arg3, double arg4);
    void method6(double arg0, short arg1, short arg2, double arg3, float arg4);
    void method7(bool arg0, int arg1, short arg2, bool arg3, bool arg4);
    float method8(float arg0, double arg1, short arg2, int arg3, float arg4);
    short method9(short arg0, double arg1, float arg2, int arg3, short arg4);
    void method10(unsigned arg0, short arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method11(int arg0, double arg1, short arg2, float arg3, unsigned arg4);
    void method12(int arg0, float arg1, short arg2, float arg3, int arg4);
    void method13(short arg0, float arg1, unsigned arg2, unsigned arg3, double arg4);
    unsigned method14(float arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);

    double memberVariable0{};
    int memberVariable1{};
    short memberVariable2{};
    unsigned memberVariable3{};
    bool memberVariable4{};
    bool memberVariable5{};
    short memberVariable6{};
    short memberVariable7{};
    double memberVariable8{};
    int memberVariable9{};
    double memberVariable10{};
    short memberVariable11{};
    float memberVariable12{};
    unsigned memberVariable13{};
    double memberVariable14{};

    static bool function0(double arg0, double arg1, bool arg2, float arg3, float arg4);
    static int function1(double arg0, int arg1, unsigned arg2, short arg3, bool arg4);
    static void function2(int arg0, int arg1, float arg2, int arg3, bool arg4);
    static bool function3(unsigned arg0, bool arg1, double arg2, unsigned arg3, unsigned arg4);
    static bool function4(int arg0, short arg1, short arg2, float arg3, bool arg4);
    static void function5(double arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    static void function6(int arg0, double arg1, int arg2, double arg3, int arg4);
    static void function7(double arg0, bool arg1, bool arg2, double arg3, unsigned arg4);
    static void function8(float arg0, float arg1, bool arg2, float arg3, int arg4);
    static void function9(short arg0, bool arg1, int arg2, double arg3, bool arg4);
    static void function10(short arg0, double arg1, float arg2, unsigned arg3, unsigned arg4);
    static void function11(bool arg0, short arg1, double arg2, bool arg3, float arg4);
    static int function12(short arg0, double arg1, double arg2, float arg3, int arg4);
    static int function13(bool arg0, unsigned arg1, int arg2, unsigned arg3, double arg4);
    static unsigned function14(bool arg0, int arg1, unsigned arg2, int arg3, short arg4);

    inline static float variable0{};
    inline static int variable1{};
    inline static double variable2{};
    inline static double variable3{};
    inline static float variable4{};
    inline static float variable5{};
    inline static double variable6{};
    inline static short variable7{};
    inline static short variable8{};
    inline static short variable9{};
    inline static bool variable10{};
    inline static bool variable11{};
    inline static float variable12{};
    inline static int variable13{};
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
