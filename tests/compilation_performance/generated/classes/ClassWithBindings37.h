#pragma once

// Generated with seed '88005553572'

#include "../../Common.h"

#include "ClassWithBindings3.h"
#include "ClassWithBindings8.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings24.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings56.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings89.h"
#include "ClassWithBindings92.h"

class ClassWithBindings37
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
    void method0(double arg0, float arg1, int arg2, bool arg3, unsigned arg4);
    void method1(double arg0, int arg1, short arg2, bool arg3, bool arg4);
    void method2(unsigned arg0, unsigned arg1, bool arg2, unsigned arg3, double arg4);
    bool method3(double arg0, short arg1, bool arg2, short arg3, unsigned arg4);
    unsigned method4(short arg0, double arg1, unsigned arg2, unsigned arg3, short arg4);
    bool method5(bool arg0, float arg1, unsigned arg2, double arg3, short arg4);
    short method6(float arg0, short arg1, bool arg2, unsigned arg3, bool arg4);
    void method7(int arg0, bool arg1, bool arg2, int arg3, float arg4);
    unsigned method8(bool arg0, unsigned arg1, short arg2, double arg3, int arg4);
    bool method9(bool arg0, short arg1, float arg2, float arg3, float arg4);
    unsigned method10(short arg0, int arg1, unsigned arg2, unsigned arg3, float arg4);
    int method11(short arg0, bool arg1, int arg2, bool arg3, short arg4);
    void method12(unsigned arg0, double arg1, double arg2, float arg3, short arg4);
    int method13(int arg0, bool arg1, double arg2, unsigned arg3, float arg4);
    bool method14(bool arg0, unsigned arg1, int arg2, int arg3, bool arg4);

    bool memberVariable0{};
    unsigned memberVariable1{};
    double memberVariable2{};
    bool memberVariable3{};
    int memberVariable4{};
    float memberVariable5{};
    float memberVariable6{};
    int memberVariable7{};
    unsigned memberVariable8{};
    short memberVariable9{};
    int memberVariable10{};
    double memberVariable11{};
    bool memberVariable12{};
    int memberVariable13{};
    unsigned memberVariable14{};

    static short function0(short arg0, short arg1, int arg2, short arg3, double arg4);
    static void function1(unsigned arg0, float arg1, bool arg2, float arg3, bool arg4);
    static void function2(double arg0, int arg1, short arg2, double arg3, int arg4);
    static unsigned function3(unsigned arg0, unsigned arg1, bool arg2, float arg3, float arg4);
    static short function4(float arg0, unsigned arg1, short arg2, int arg3, unsigned arg4);
    static int function5(int arg0, double arg1, bool arg2, double arg3, int arg4);
    static unsigned function6(bool arg0, short arg1, float arg2, double arg3, unsigned arg4);
    static int function7(double arg0, int arg1, int arg2, float arg3, int arg4);
    static bool function8(double arg0, bool arg1, short arg2, bool arg3, bool arg4);
    static float function9(float arg0, int arg1, float arg2, float arg3, int arg4);
    static void function10(short arg0, float arg1, short arg2, double arg3, short arg4);
    static void function11(short arg0, int arg1, bool arg2, float arg3, bool arg4);
    static int function12(double arg0, int arg1, int arg2, short arg3, bool arg4);
    static void function13(unsigned arg0, bool arg1, short arg2, bool arg3, float arg4);
    static short function14(double arg0, short arg1, int arg2, bool arg3, float arg4);

    inline static int variable0{};
    inline static bool variable1{};
    inline static float variable2{};
    inline static int variable3{};
    inline static bool variable4{};
    inline static unsigned variable5{};
    inline static int variable6{};
    inline static float variable7{};
    inline static short variable8{};
    inline static double variable9{};
    inline static int variable10{};
    inline static bool variable11{};
    inline static float variable12{};
    inline static float variable13{};
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
