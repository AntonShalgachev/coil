#pragma once

// Generated with seed '88005553576'

#include "../../Common.h"

#include "ClassWithBindings5.h"
#include "ClassWithBindings16.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings18.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings89.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings94.h"
#include "ClassWithBindings96.h"
#include "ClassWithBindings98.h"

class ClassWithBindings41
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
    bool method0(short arg0, unsigned arg1, double arg2, unsigned arg3, bool arg4);
    void method1(short arg0, short arg1, bool arg2, unsigned arg3, short arg4);
    void method2(int arg0, bool arg1, unsigned arg2, int arg3, int arg4);
    void method3(unsigned arg0, float arg1, int arg2, short arg3, bool arg4);
    unsigned method4(double arg0, bool arg1, unsigned arg2, bool arg3, bool arg4);
    bool method5(double arg0, float arg1, int arg2, bool arg3, bool arg4);
    float method6(short arg0, float arg1, bool arg2, float arg3, int arg4);
    void method7(bool arg0, unsigned arg1, float arg2, int arg3, unsigned arg4);
    int method8(int arg0, double arg1, float arg2, unsigned arg3, int arg4);
    bool method9(bool arg0, double arg1, double arg2, bool arg3, bool arg4);
    int method10(float arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    double method11(float arg0, bool arg1, double arg2, unsigned arg3, float arg4);
    void method12(unsigned arg0, unsigned arg1, int arg2, int arg3, bool arg4);
    int method13(int arg0, short arg1, double arg2, unsigned arg3, bool arg4);
    void method14(unsigned arg0, bool arg1, unsigned arg2, float arg3, unsigned arg4);

    bool memberVariable0{};
    int memberVariable1{};
    bool memberVariable2{};
    unsigned memberVariable3{};
    unsigned memberVariable4{};
    float memberVariable5{};
    float memberVariable6{};
    int memberVariable7{};
    short memberVariable8{};
    int memberVariable9{};
    double memberVariable10{};
    double memberVariable11{};
    double memberVariable12{};
    double memberVariable13{};
    int memberVariable14{};

    static void function0(double arg0, short arg1, double arg2, unsigned arg3, bool arg4);
    static unsigned function1(float arg0, int arg1, short arg2, unsigned arg3, float arg4);
    static int function2(float arg0, int arg1, unsigned arg2, double arg3, int arg4);
    static void function3(int arg0, float arg1, bool arg2, bool arg3, unsigned arg4);
    static void function4(unsigned arg0, double arg1, int arg2, unsigned arg3, float arg4);
    static float function5(float arg0, float arg1, bool arg2, unsigned arg3, unsigned arg4);
    static void function6(unsigned arg0, double arg1, double arg2, bool arg3, double arg4);
    static float function7(float arg0, float arg1, int arg2, float arg3, float arg4);
    static bool function8(unsigned arg0, short arg1, bool arg2, int arg3, unsigned arg4);
    static void function9(bool arg0, float arg1, double arg2, unsigned arg3, short arg4);
    static void function10(float arg0, bool arg1, bool arg2, double arg3, short arg4);
    static void function11(bool arg0, double arg1, short arg2, float arg3, float arg4);
    static unsigned function12(double arg0, int arg1, bool arg2, unsigned arg3, unsigned arg4);
    static void function13(short arg0, short arg1, unsigned arg2, unsigned arg3, float arg4);
    static void function14(short arg0, int arg1, float arg2, float arg3, bool arg4);

    inline static double variable0{};
    inline static int variable1{};
    inline static short variable2{};
    inline static double variable3{};
    inline static short variable4{};
    inline static float variable5{};
    inline static double variable6{};
    inline static unsigned variable7{};
    inline static float variable8{};
    inline static int variable9{};
    inline static unsigned variable10{};
    inline static double variable11{};
    inline static bool variable12{};
    inline static short variable13{};
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
