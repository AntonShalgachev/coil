#pragma once

// Generated with seed '88005553578'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings10.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings91.h"
#include "ClassWithBindings96.h"
#include "ClassWithBindings98.h"

class ClassWithBindings43
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
    int method0(unsigned arg0, double arg1, int arg2, int arg3, unsigned arg4);
    double method1(bool arg0, float arg1, int arg2, double arg3, bool arg4);
    int method2(int arg0, double arg1, bool arg2, double arg3, float arg4);
    void method3(float arg0, bool arg1, short arg2, short arg3, double arg4);
    float method4(double arg0, bool arg1, float arg2, bool arg3, short arg4);
    double method5(float arg0, unsigned arg1, bool arg2, double arg3, int arg4);
    void method6(float arg0, bool arg1, bool arg2, short arg3, float arg4);
    void method7(unsigned arg0, float arg1, double arg2, short arg3, bool arg4);
    void method8(double arg0, int arg1, short arg2, double arg3, int arg4);
    bool method9(float arg0, double arg1, bool arg2, bool arg3, bool arg4);
    void method10(unsigned arg0, unsigned arg1, int arg2, int arg3, double arg4);
    void method11(unsigned arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    void method12(float arg0, short arg1, float arg2, short arg3, double arg4);
    unsigned method13(unsigned arg0, unsigned arg1, double arg2, double arg3, float arg4);
    unsigned method14(short arg0, unsigned arg1, float arg2, double arg3, int arg4);

    double memberVariable0{};
    int memberVariable1{};
    float memberVariable2{};
    float memberVariable3{};
    int memberVariable4{};
    short memberVariable5{};
    bool memberVariable6{};
    unsigned memberVariable7{};
    unsigned memberVariable8{};
    int memberVariable9{};
    bool memberVariable10{};
    unsigned memberVariable11{};
    int memberVariable12{};
    double memberVariable13{};
    float memberVariable14{};

    static bool function0(bool arg0, short arg1, float arg2, int arg3, float arg4);
    static void function1(bool arg0, unsigned arg1, double arg2, short arg3, short arg4);
    static void function2(int arg0, double arg1, int arg2, double arg3, short arg4);
    static int function3(bool arg0, int arg1, float arg2, int arg3, double arg4);
    static bool function4(bool arg0, double arg1, bool arg2, short arg3, float arg4);
    static void function5(bool arg0, int arg1, int arg2, unsigned arg3, int arg4);
    static void function6(bool arg0, int arg1, short arg2, int arg3, short arg4);
    static double function7(unsigned arg0, short arg1, double arg2, int arg3, bool arg4);
    static float function8(short arg0, unsigned arg1, float arg2, double arg3, float arg4);
    static float function9(bool arg0, float arg1, double arg2, unsigned arg3, bool arg4);
    static unsigned function10(int arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    static unsigned function11(unsigned arg0, int arg1, short arg2, double arg3, int arg4);
    static int function12(bool arg0, int arg1, double arg2, float arg3, double arg4);
    static void function13(double arg0, float arg1, double arg2, short arg3, double arg4);
    static short function14(short arg0, float arg1, float arg2, int arg3, short arg4);

    inline static bool variable0{};
    inline static short variable1{};
    inline static bool variable2{};
    inline static double variable3{};
    inline static double variable4{};
    inline static unsigned variable5{};
    inline static unsigned variable6{};
    inline static int variable7{};
    inline static unsigned variable8{};
    inline static int variable9{};
    inline static unsigned variable10{};
    inline static int variable11{};
    inline static double variable12{};
    inline static unsigned variable13{};
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
