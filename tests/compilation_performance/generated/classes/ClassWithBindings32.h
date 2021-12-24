#pragma once

// Generated with seed '88005553567'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings2.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings10.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings16.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings42.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings56.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings85.h"

class ClassWithBindings32
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
    void method0(double arg0, bool arg1, short arg2, unsigned arg3, double arg4);
    void method1(double arg0, short arg1, float arg2, int arg3, unsigned arg4);
    void method2(unsigned arg0, bool arg1, bool arg2, unsigned arg3, short arg4);
    int method3(unsigned arg0, bool arg1, int arg2, float arg3, int arg4);
    void method4(float arg0, float arg1, int arg2, float arg3, bool arg4);
    short method5(short arg0, bool arg1, float arg2, float arg3, float arg4);
    short method6(short arg0, double arg1, int arg2, double arg3, unsigned arg4);
    void method7(int arg0, int arg1, double arg2, bool arg3, double arg4);
    void method8(short arg0, int arg1, bool arg2, unsigned arg3, int arg4);
    unsigned method9(bool arg0, unsigned arg1, bool arg2, double arg3, float arg4);
    void method10(bool arg0, short arg1, short arg2, unsigned arg3, int arg4);
    bool method11(bool arg0, float arg1, bool arg2, bool arg3, short arg4);
    short method12(short arg0, double arg1, float arg2, int arg3, int arg4);
    void method13(bool arg0, short arg1, unsigned arg2, int arg3, bool arg4);
    short method14(double arg0, float arg1, short arg2, short arg3, bool arg4);

    unsigned memberVariable0{};
    float memberVariable1{};
    int memberVariable2{};
    short memberVariable3{};
    int memberVariable4{};
    short memberVariable5{};
    float memberVariable6{};
    int memberVariable7{};
    double memberVariable8{};
    float memberVariable9{};
    bool memberVariable10{};
    int memberVariable11{};
    unsigned memberVariable12{};
    short memberVariable13{};
    unsigned memberVariable14{};

    static void function0(bool arg0, double arg1, short arg2, bool arg3, unsigned arg4);
    static short function1(bool arg0, bool arg1, float arg2, bool arg3, short arg4);
    static int function2(bool arg0, bool arg1, int arg2, short arg3, short arg4);
    static float function3(bool arg0, float arg1, short arg2, double arg3, short arg4);
    static short function4(double arg0, unsigned arg1, double arg2, short arg3, bool arg4);
    static short function5(float arg0, short arg1, double arg2, short arg3, float arg4);
    static int function6(int arg0, bool arg1, unsigned arg2, float arg3, float arg4);
    static void function7(bool arg0, int arg1, float arg2, double arg3, int arg4);
    static short function8(double arg0, short arg1, double arg2, short arg3, bool arg4);
    static void function9(float arg0, float arg1, bool arg2, float arg3, short arg4);
    static double function10(double arg0, float arg1, short arg2, short arg3, short arg4);
    static short function11(short arg0, unsigned arg1, short arg2, int arg3, short arg4);
    static unsigned function12(short arg0, unsigned arg1, double arg2, bool arg3, float arg4);
    static double function13(double arg0, int arg1, double arg2, double arg3, unsigned arg4);
    static int function14(double arg0, int arg1, float arg2, float arg3, double arg4);

    inline static float variable0{};
    inline static float variable1{};
    inline static double variable2{};
    inline static float variable3{};
    inline static bool variable4{};
    inline static bool variable5{};
    inline static double variable6{};
    inline static bool variable7{};
    inline static float variable8{};
    inline static int variable9{};
    inline static double variable10{};
    inline static short variable11{};
    inline static unsigned variable12{};
    inline static int variable13{};
    inline static unsigned variable14{};

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
