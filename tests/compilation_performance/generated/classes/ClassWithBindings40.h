#pragma once

// Generated with seed '88005553575'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings2.h"
#include "ClassWithBindings4.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings91.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings95.h"
#include "ClassWithBindings96.h"

class ClassWithBindings40
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
    void method0(short arg0, int arg1, double arg2, bool arg3, float arg4);
    void method1(float arg0, int arg1, int arg2, short arg3, short arg4);
    bool method2(bool arg0, short arg1, float arg2, int arg3, bool arg4);
    void method3(int arg0, unsigned arg1, bool arg2, double arg3, double arg4);
    void method4(bool arg0, unsigned arg1, float arg2, int arg3, short arg4);
    void method5(int arg0, unsigned arg1, double arg2, int arg3, float arg4);
    short method6(short arg0, double arg1, float arg2, unsigned arg3, int arg4);
    void method7(double arg0, short arg1, float arg2, float arg3, double arg4);
    void method8(bool arg0, short arg1, unsigned arg2, short arg3, short arg4);
    void method9(float arg0, float arg1, float arg2, double arg3, bool arg4);
    void method10(bool arg0, double arg1, float arg2, unsigned arg3, int arg4);
    void method11(bool arg0, bool arg1, short arg2, unsigned arg3, float arg4);
    short method12(float arg0, int arg1, short arg2, int arg3, float arg4);
    unsigned method13(unsigned arg0, unsigned arg1, float arg2, bool arg3, short arg4);
    double method14(double arg0, double arg1, short arg2, bool arg3, double arg4);

    bool memberVariable0{};
    short memberVariable1{};
    float memberVariable2{};
    float memberVariable3{};
    bool memberVariable4{};
    float memberVariable5{};
    int memberVariable6{};
    bool memberVariable7{};
    float memberVariable8{};
    unsigned memberVariable9{};
    float memberVariable10{};
    double memberVariable11{};
    int memberVariable12{};
    float memberVariable13{};
    int memberVariable14{};

    static double function0(float arg0, double arg1, short arg2, unsigned arg3, bool arg4);
    static int function1(int arg0, int arg1, bool arg2, short arg3, bool arg4);
    static void function2(unsigned arg0, float arg1, double arg2, bool arg3, double arg4);
    static void function3(short arg0, int arg1, float arg2, bool arg3, double arg4);
    static double function4(short arg0, bool arg1, double arg2, bool arg3, short arg4);
    static float function5(bool arg0, bool arg1, float arg2, float arg3, float arg4);
    static void function6(unsigned arg0, int arg1, bool arg2, float arg3, bool arg4);
    static void function7(unsigned arg0, int arg1, double arg2, double arg3, bool arg4);
    static void function8(short arg0, unsigned arg1, short arg2, int arg3, int arg4);
    static int function9(double arg0, bool arg1, int arg2, bool arg3, unsigned arg4);
    static bool function10(bool arg0, float arg1, bool arg2, int arg3, int arg4);
    static float function11(bool arg0, float arg1, float arg2, short arg3, bool arg4);
    static void function12(bool arg0, short arg1, float arg2, int arg3, short arg4);
    static float function13(short arg0, unsigned arg1, int arg2, short arg3, float arg4);
    static void function14(float arg0, float arg1, unsigned arg2, bool arg3, float arg4);

    inline static short variable0{};
    inline static double variable1{};
    inline static unsigned variable2{};
    inline static bool variable3{};
    inline static int variable4{};
    inline static float variable5{};
    inline static double variable6{};
    inline static bool variable7{};
    inline static int variable8{};
    inline static double variable9{};
    inline static bool variable10{};
    inline static short variable11{};
    inline static float variable12{};
    inline static float variable13{};
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
