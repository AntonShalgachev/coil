#pragma once

// Generated with seed '88005553544'

#include "../../Common.h"

#include "ClassWithBindings10.h"
#include "ClassWithBindings16.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings48.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings91.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings95.h"
#include "ClassWithBindings98.h"

class ClassWithBindings9
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
    void method0(float arg0, bool arg1, double arg2, double arg3, bool arg4);
    float method1(bool arg0, float arg1, float arg2, bool arg3, int arg4);
    bool method2(float arg0, float arg1, bool arg2, double arg3, bool arg4);
    int method3(double arg0, int arg1, unsigned arg2, unsigned arg3, int arg4);
    void method4(bool arg0, int arg1, float arg2, bool arg3, short arg4);
    short method5(bool arg0, bool arg1, float arg2, unsigned arg3, short arg4);
    void method6(unsigned arg0, unsigned arg1, unsigned arg2, bool arg3, int arg4);
    unsigned method7(bool arg0, unsigned arg1, bool arg2, double arg3, float arg4);
    void method8(short arg0, double arg1, bool arg2, float arg3, float arg4);
    bool method9(float arg0, unsigned arg1, int arg2, bool arg3, short arg4);
    double method10(bool arg0, bool arg1, double arg2, unsigned arg3, bool arg4);
    void method11(unsigned arg0, float arg1, bool arg2, unsigned arg3, float arg4);
    void method12(unsigned arg0, double arg1, double arg2, bool arg3, double arg4);
    void method13(bool arg0, unsigned arg1, short arg2, int arg3, double arg4);
    float method14(int arg0, float arg1, float arg2, int arg3, double arg4);

    double memberVariable0{};
    double memberVariable1{};
    float memberVariable2{};
    double memberVariable3{};
    bool memberVariable4{};
    int memberVariable5{};
    short memberVariable6{};
    int memberVariable7{};
    unsigned memberVariable8{};
    bool memberVariable9{};
    double memberVariable10{};
    unsigned memberVariable11{};
    short memberVariable12{};
    float memberVariable13{};
    double memberVariable14{};

    static double function0(int arg0, unsigned arg1, double arg2, short arg3, float arg4);
    static unsigned function1(short arg0, int arg1, unsigned arg2, unsigned arg3, float arg4);
    static short function2(double arg0, short arg1, bool arg2, short arg3, bool arg4);
    static double function3(int arg0, double arg1, double arg2, double arg3, double arg4);
    static void function4(bool arg0, float arg1, int arg2, int arg3, float arg4);
    static unsigned function5(int arg0, int arg1, short arg2, unsigned arg3, int arg4);
    static unsigned function6(double arg0, unsigned arg1, unsigned arg2, double arg3, float arg4);
    static double function7(bool arg0, double arg1, bool arg2, double arg3, unsigned arg4);
    static void function8(double arg0, float arg1, bool arg2, bool arg3, bool arg4);
    static void function9(short arg0, int arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    static void function10(short arg0, short arg1, double arg2, float arg3, float arg4);
    static int function11(short arg0, double arg1, bool arg2, int arg3, double arg4);
    static void function12(double arg0, short arg1, bool arg2, int arg3, float arg4);
    static void function13(short arg0, double arg1, double arg2, float arg3, short arg4);
    static void function14(double arg0, float arg1, int arg2, float arg3, short arg4);

    inline static float variable0{};
    inline static unsigned variable1{};
    inline static bool variable2{};
    inline static int variable3{};
    inline static double variable4{};
    inline static unsigned variable5{};
    inline static int variable6{};
    inline static int variable7{};
    inline static bool variable8{};
    inline static short variable9{};
    inline static short variable10{};
    inline static short variable11{};
    inline static double variable12{};
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
