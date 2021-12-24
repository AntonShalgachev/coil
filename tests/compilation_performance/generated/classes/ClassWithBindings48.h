#pragma once

// Generated with seed '88005553583'

#include "../../Common.h"

#include "ClassWithBindings5.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings75.h"
#include "ClassWithBindings76.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings78.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings93.h"
#include "ClassWithBindings95.h"

class ClassWithBindings48
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
    void method0(float arg0, int arg1, short arg2, int arg3, double arg4);
    int method1(double arg0, bool arg1, unsigned arg2, int arg3, int arg4);
    void method2(int arg0, double arg1, int arg2, float arg3, short arg4);
    void method3(int arg0, unsigned arg1, double arg2, unsigned arg3, int arg4);
    void method4(short arg0, short arg1, short arg2, int arg3, short arg4);
    void method5(double arg0, short arg1, short arg2, double arg3, unsigned arg4);
    unsigned method6(bool arg0, float arg1, bool arg2, unsigned arg3, double arg4);
    unsigned method7(float arg0, short arg1, unsigned arg2, double arg3, float arg4);
    void method8(double arg0, bool arg1, double arg2, int arg3, unsigned arg4);
    int method9(int arg0, float arg1, bool arg2, float arg3, bool arg4);
    short method10(short arg0, int arg1, unsigned arg2, bool arg3, int arg4);
    void method11(bool arg0, double arg1, double arg2, unsigned arg3, int arg4);
    short method12(bool arg0, unsigned arg1, short arg2, bool arg3, float arg4);
    void method13(short arg0, int arg1, unsigned arg2, int arg3, int arg4);
    double method14(float arg0, float arg1, double arg2, bool arg3, double arg4);

    double memberVariable0{};
    short memberVariable1{};
    unsigned memberVariable2{};
    int memberVariable3{};
    int memberVariable4{};
    float memberVariable5{};
    int memberVariable6{};
    unsigned memberVariable7{};
    bool memberVariable8{};
    bool memberVariable9{};
    unsigned memberVariable10{};
    double memberVariable11{};
    int memberVariable12{};
    float memberVariable13{};
    int memberVariable14{};

    static unsigned function0(unsigned arg0, int arg1, short arg2, int arg3, int arg4);
    static int function1(float arg0, int arg1, short arg2, double arg3, int arg4);
    static double function2(double arg0, double arg1, short arg2, float arg3, int arg4);
    static float function3(bool arg0, bool arg1, float arg2, unsigned arg3, int arg4);
    static double function4(double arg0, bool arg1, unsigned arg2, unsigned arg3, float arg4);
    static bool function5(unsigned arg0, bool arg1, float arg2, unsigned arg3, short arg4);
    static unsigned function6(unsigned arg0, int arg1, unsigned arg2, float arg3, bool arg4);
    static int function7(short arg0, int arg1, unsigned arg2, float arg3, double arg4);
    static unsigned function8(bool arg0, unsigned arg1, unsigned arg2, short arg3, unsigned arg4);
    static short function9(double arg0, unsigned arg1, double arg2, unsigned arg3, short arg4);
    static void function10(short arg0, double arg1, int arg2, double arg3, short arg4);
    static int function11(short arg0, bool arg1, int arg2, int arg3, double arg4);
    static void function12(bool arg0, unsigned arg1, unsigned arg2, float arg3, unsigned arg4);
    static unsigned function13(short arg0, double arg1, float arg2, unsigned arg3, unsigned arg4);
    static void function14(unsigned arg0, bool arg1, short arg2, int arg3, double arg4);

    inline static short variable0{};
    inline static bool variable1{};
    inline static int variable2{};
    inline static unsigned variable3{};
    inline static short variable4{};
    inline static double variable5{};
    inline static short variable6{};
    inline static int variable7{};
    inline static bool variable8{};
    inline static int variable9{};
    inline static int variable10{};
    inline static double variable11{};
    inline static double variable12{};
    inline static unsigned variable13{};
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
