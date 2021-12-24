#pragma once

// Generated with seed '88005553536'

#include "../../Common.h"

#include "ClassWithBindings2.h"
#include "ClassWithBindings4.h"
#include "ClassWithBindings6.h"
#include "ClassWithBindings8.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings75.h"
#include "ClassWithBindings88.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings93.h"
#include "ClassWithBindings99.h"

class ClassWithBindings1
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
    bool method0(double arg0, bool arg1, bool arg2, int arg3, short arg4);
    void method1(unsigned arg0, short arg1, double arg2, double arg3, float arg4);
    void method2(int arg0, double arg1, unsigned arg2, short arg3, short arg4);
    int method3(short arg0, float arg1, int arg2, short arg3, short arg4);
    double method4(double arg0, double arg1, int arg2, double arg3, double arg4);
    unsigned method5(short arg0, unsigned arg1, double arg2, bool arg3, int arg4);
    float method6(bool arg0, float arg1, short arg2, float arg3, short arg4);
    bool method7(bool arg0, int arg1, unsigned arg2, double arg3, bool arg4);
    void method8(double arg0, int arg1, short arg2, short arg3, bool arg4);
    short method9(int arg0, int arg1, short arg2, double arg3, unsigned arg4);
    unsigned method10(short arg0, float arg1, float arg2, double arg3, unsigned arg4);
    bool method11(double arg0, short arg1, double arg2, bool arg3, bool arg4);
    unsigned method12(bool arg0, unsigned arg1, float arg2, float arg3, unsigned arg4);
    void method13(short arg0, bool arg1, int arg2, float arg3, double arg4);
    double method14(int arg0, short arg1, double arg2, short arg3, unsigned arg4);

    float memberVariable0{};
    short memberVariable1{};
    bool memberVariable2{};
    float memberVariable3{};
    bool memberVariable4{};
    unsigned memberVariable5{};
    unsigned memberVariable6{};
    double memberVariable7{};
    int memberVariable8{};
    float memberVariable9{};
    int memberVariable10{};
    bool memberVariable11{};
    unsigned memberVariable12{};
    int memberVariable13{};
    short memberVariable14{};

    static double function0(unsigned arg0, short arg1, double arg2, short arg3, int arg4);
    static void function1(bool arg0, float arg1, short arg2, double arg3, int arg4);
    static short function2(short arg0, double arg1, bool arg2, bool arg3, int arg4);
    static void function3(short arg0, double arg1, double arg2, double arg3, double arg4);
    static void function4(int arg0, short arg1, float arg2, int arg3, double arg4);
    static int function5(bool arg0, int arg1, int arg2, unsigned arg3, int arg4);
    static double function6(float arg0, int arg1, int arg2, double arg3, float arg4);
    static void function7(float arg0, float arg1, float arg2, unsigned arg3, bool arg4);
    static void function8(float arg0, bool arg1, unsigned arg2, bool arg3, unsigned arg4);
    static void function9(unsigned arg0, bool arg1, double arg2, bool arg3, int arg4);
    static void function10(short arg0, bool arg1, float arg2, int arg3, unsigned arg4);
    static short function11(bool arg0, short arg1, short arg2, unsigned arg3, short arg4);
    static float function12(double arg0, float arg1, bool arg2, bool arg3, double arg4);
    static short function13(int arg0, float arg1, short arg2, unsigned arg3, bool arg4);
    static int function14(float arg0, short arg1, int arg2, double arg3, double arg4);

    inline static int variable0{};
    inline static double variable1{};
    inline static bool variable2{};
    inline static double variable3{};
    inline static bool variable4{};
    inline static unsigned variable5{};
    inline static bool variable6{};
    inline static short variable7{};
    inline static bool variable8{};
    inline static double variable9{};
    inline static bool variable10{};
    inline static bool variable11{};
    inline static unsigned variable12{};
    inline static bool variable13{};
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
