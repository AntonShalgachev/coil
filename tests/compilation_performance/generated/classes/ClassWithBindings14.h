#pragma once

// Generated with seed '88005553549'

#include "../../Common.h"

#include "ClassWithBindings6.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings48.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings63.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings87.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings93.h"

class ClassWithBindings14
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
    void method0(int arg0, int arg1, bool arg2, double arg3, short arg4);
    void method1(bool arg0, double arg1, float arg2, int arg3, float arg4);
    int method2(float arg0, short arg1, unsigned arg2, int arg3, short arg4);
    void method3(short arg0, int arg1, int arg2, short arg3, int arg4);
    short method4(bool arg0, short arg1, short arg2, float arg3, int arg4);
    void method5(short arg0, short arg1, bool arg2, unsigned arg3, double arg4);
    void method6(bool arg0, float arg1, short arg2, unsigned arg3, bool arg4);
    void method7(int arg0, short arg1, unsigned arg2, short arg3, bool arg4);
    double method8(float arg0, double arg1, short arg2, bool arg3, short arg4);
    void method9(double arg0, short arg1, int arg2, short arg3, unsigned arg4);
    float method10(float arg0, bool arg1, float arg2, int arg3, bool arg4);
    bool method11(bool arg0, float arg1, unsigned arg2, int arg3, bool arg4);
    int method12(int arg0, float arg1, double arg2, unsigned arg3, short arg4);
    short method13(double arg0, float arg1, double arg2, short arg3, float arg4);
    float method14(float arg0, int arg1, short arg2, float arg3, unsigned arg4);

    double memberVariable0{};
    short memberVariable1{};
    unsigned memberVariable2{};
    unsigned memberVariable3{};
    int memberVariable4{};
    bool memberVariable5{};
    bool memberVariable6{};
    unsigned memberVariable7{};
    unsigned memberVariable8{};
    short memberVariable9{};
    unsigned memberVariable10{};
    bool memberVariable11{};
    short memberVariable12{};
    float memberVariable13{};
    unsigned memberVariable14{};

    static short function0(unsigned arg0, short arg1, unsigned arg2, short arg3, bool arg4);
    static unsigned function1(bool arg0, unsigned arg1, unsigned arg2, int arg3, int arg4);
    static void function2(bool arg0, unsigned arg1, unsigned arg2, unsigned arg3, double arg4);
    static unsigned function3(double arg0, double arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    static float function4(int arg0, float arg1, float arg2, short arg3, unsigned arg4);
    static float function5(bool arg0, unsigned arg1, float arg2, double arg3, bool arg4);
    static void function6(int arg0, double arg1, short arg2, bool arg3, float arg4);
    static void function7(float arg0, float arg1, bool arg2, unsigned arg3, double arg4);
    static void function8(unsigned arg0, bool arg1, int arg2, double arg3, int arg4);
    static void function9(short arg0, short arg1, float arg2, short arg3, unsigned arg4);
    static short function10(short arg0, double arg1, unsigned arg2, short arg3, bool arg4);
    static void function11(short arg0, bool arg1, double arg2, short arg3, int arg4);
    static void function12(int arg0, short arg1, unsigned arg2, int arg3, short arg4);
    static void function13(double arg0, float arg1, int arg2, unsigned arg3, float arg4);
    static void function14(float arg0, float arg1, bool arg2, short arg3, unsigned arg4);

    inline static bool variable0{};
    inline static float variable1{};
    inline static float variable2{};
    inline static double variable3{};
    inline static double variable4{};
    inline static bool variable5{};
    inline static short variable6{};
    inline static unsigned variable7{};
    inline static int variable8{};
    inline static int variable9{};
    inline static float variable10{};
    inline static bool variable11{};
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
