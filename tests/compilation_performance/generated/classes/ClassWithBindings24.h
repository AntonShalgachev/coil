#pragma once

// Generated with seed '88005553559'

#include "../../Common.h"

#include "ClassWithBindings3.h"
#include "ClassWithBindings6.h"
#include "ClassWithBindings11.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings43.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings48.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings76.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings86.h"
#include "ClassWithBindings87.h"
#include "ClassWithBindings88.h"
#include "ClassWithBindings89.h"
#include "ClassWithBindings99.h"

class ClassWithBindings24
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
    short method0(double arg0, unsigned arg1, unsigned arg2, short arg3, int arg4);
    unsigned method1(int arg0, unsigned arg1, bool arg2, int arg3, double arg4);
    void method2(float arg0, bool arg1, unsigned arg2, bool arg3, short arg4);
    void method3(short arg0, int arg1, short arg2, float arg3, short arg4);
    bool method4(int arg0, float arg1, bool arg2, double arg3, bool arg4);
    int method5(short arg0, int arg1, double arg2, short arg3, unsigned arg4);
    int method6(double arg0, int arg1, int arg2, float arg3, bool arg4);
    double method7(short arg0, short arg1, double arg2, short arg3, short arg4);
    void method8(unsigned arg0, double arg1, bool arg2, bool arg3, bool arg4);
    unsigned method9(unsigned arg0, unsigned arg1, short arg2, int arg3, float arg4);
    int method10(bool arg0, short arg1, int arg2, float arg3, double arg4);
    double method11(float arg0, float arg1, unsigned arg2, double arg3, double arg4);
    float method12(bool arg0, float arg1, short arg2, int arg3, short arg4);
    void method13(short arg0, double arg1, unsigned arg2, int arg3, double arg4);
    short method14(double arg0, double arg1, unsigned arg2, unsigned arg3, short arg4);

    short memberVariable0{};
    short memberVariable1{};
    bool memberVariable2{};
    short memberVariable3{};
    unsigned memberVariable4{};
    int memberVariable5{};
    unsigned memberVariable6{};
    float memberVariable7{};
    double memberVariable8{};
    unsigned memberVariable9{};
    unsigned memberVariable10{};
    bool memberVariable11{};
    short memberVariable12{};
    double memberVariable13{};
    unsigned memberVariable14{};

    static double function0(unsigned arg0, bool arg1, float arg2, double arg3, short arg4);
    static void function1(float arg0, short arg1, unsigned arg2, short arg3, bool arg4);
    static float function2(float arg0, double arg1, short arg2, bool arg3, short arg4);
    static void function3(bool arg0, float arg1, double arg2, unsigned arg3, float arg4);
    static void function4(short arg0, double arg1, short arg2, short arg3, int arg4);
    static int function5(unsigned arg0, short arg1, float arg2, int arg3, int arg4);
    static void function6(bool arg0, bool arg1, double arg2, short arg3, unsigned arg4);
    static void function7(bool arg0, double arg1, int arg2, unsigned arg3, bool arg4);
    static void function8(double arg0, unsigned arg1, unsigned arg2, int arg3, float arg4);
    static double function9(unsigned arg0, short arg1, double arg2, bool arg3, double arg4);
    static double function10(int arg0, bool arg1, unsigned arg2, double arg3, int arg4);
    static void function11(float arg0, float arg1, float arg2, unsigned arg3, int arg4);
    static bool function12(double arg0, bool arg1, bool arg2, short arg3, unsigned arg4);
    static double function13(int arg0, short arg1, double arg2, double arg3, short arg4);
    static int function14(short arg0, double arg1, float arg2, int arg3, int arg4);

    inline static bool variable0{};
    inline static short variable1{};
    inline static bool variable2{};
    inline static int variable3{};
    inline static short variable4{};
    inline static double variable5{};
    inline static unsigned variable6{};
    inline static float variable7{};
    inline static unsigned variable8{};
    inline static bool variable9{};
    inline static float variable10{};
    inline static float variable11{};
    inline static int variable12{};
    inline static int variable13{};
    inline static float variable14{};

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
