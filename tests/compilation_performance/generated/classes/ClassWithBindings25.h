#pragma once

// Generated with seed '88005553560'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings2.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings18.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings75.h"
#include "ClassWithBindings89.h"
#include "ClassWithBindings97.h"
#include "ClassWithBindings98.h"

class ClassWithBindings25
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
    void method0(float arg0, short arg1, unsigned arg2, short arg3, bool arg4);
    void method1(float arg0, double arg1, short arg2, bool arg3, float arg4);
    bool method2(bool arg0, unsigned arg1, short arg2, float arg3, short arg4);
    bool method3(double arg0, double arg1, bool arg2, double arg3, int arg4);
    void method4(unsigned arg0, unsigned arg1, int arg2, double arg3, bool arg4);
    void method5(bool arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    double method6(double arg0, unsigned arg1, double arg2, short arg3, short arg4);
    void method7(float arg0, double arg1, short arg2, unsigned arg3, bool arg4);
    short method8(float arg0, unsigned arg1, unsigned arg2, bool arg3, short arg4);
    void method9(bool arg0, double arg1, short arg2, unsigned arg3, int arg4);
    float method10(float arg0, float arg1, int arg2, float arg3, bool arg4);
    short method11(bool arg0, short arg1, bool arg2, int arg3, double arg4);
    short method12(double arg0, double arg1, short arg2, short arg3, bool arg4);
    void method13(bool arg0, float arg1, unsigned arg2, short arg3, short arg4);
    unsigned method14(int arg0, float arg1, unsigned arg2, short arg3, unsigned arg4);

    bool memberVariable0{};
    double memberVariable1{};
    unsigned memberVariable2{};
    unsigned memberVariable3{};
    int memberVariable4{};
    double memberVariable5{};
    bool memberVariable6{};
    bool memberVariable7{};
    double memberVariable8{};
    unsigned memberVariable9{};
    float memberVariable10{};
    double memberVariable11{};
    float memberVariable12{};
    int memberVariable13{};
    short memberVariable14{};

    static void function0(double arg0, short arg1, unsigned arg2, short arg3, bool arg4);
    static short function1(int arg0, double arg1, bool arg2, int arg3, short arg4);
    static int function2(double arg0, float arg1, int arg2, bool arg3, unsigned arg4);
    static void function3(int arg0, bool arg1, short arg2, int arg3, bool arg4);
    static bool function4(double arg0, double arg1, bool arg2, bool arg3, int arg4);
    static short function5(bool arg0, short arg1, int arg2, int arg3, float arg4);
    static void function6(int arg0, double arg1, double arg2, short arg3, unsigned arg4);
    static unsigned function7(bool arg0, unsigned arg1, int arg2, unsigned arg3, int arg4);
    static void function8(short arg0, double arg1, unsigned arg2, float arg3, float arg4);
    static int function9(short arg0, double arg1, double arg2, int arg3, int arg4);
    static void function10(short arg0, int arg1, unsigned arg2, float arg3, float arg4);
    static unsigned function11(bool arg0, short arg1, float arg2, unsigned arg3, double arg4);
    static void function12(int arg0, int arg1, float arg2, float arg3, float arg4);
    static float function13(double arg0, unsigned arg1, int arg2, short arg3, float arg4);
    static void function14(bool arg0, double arg1, int arg2, double arg3, double arg4);

    inline static unsigned variable0{};
    inline static int variable1{};
    inline static bool variable2{};
    inline static bool variable3{};
    inline static bool variable4{};
    inline static unsigned variable5{};
    inline static short variable6{};
    inline static double variable7{};
    inline static unsigned variable8{};
    inline static float variable9{};
    inline static double variable10{};
    inline static double variable11{};
    inline static short variable12{};
    inline static double variable13{};
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
