#pragma once

// Generated with seed '88005553634'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings6.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings18.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings48.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings73.h"
#include "ClassWithBindings78.h"
#include "ClassWithBindings92.h"

class ClassWithBindings99
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
    float method0(int arg0, float arg1, double arg2, float arg3, double arg4);
    short method1(int arg0, double arg1, short arg2, float arg3, float arg4);
    void method2(int arg0, unsigned arg1, short arg2, unsigned arg3, float arg4);
    short method3(short arg0, double arg1, double arg2, float arg3, short arg4);
    short method4(bool arg0, float arg1, int arg2, int arg3, short arg4);
    void method5(int arg0, unsigned arg1, int arg2, bool arg3, unsigned arg4);
    int method6(int arg0, double arg1, int arg2, bool arg3, float arg4);
    int method7(int arg0, float arg1, double arg2, bool arg3, bool arg4);
    void method8(double arg0, int arg1, double arg2, bool arg3, float arg4);
    unsigned method9(double arg0, unsigned arg1, short arg2, bool arg3, double arg4);
    short method10(short arg0, short arg1, unsigned arg2, short arg3, bool arg4);
    double method11(short arg0, bool arg1, double arg2, short arg3, double arg4);
    short method12(float arg0, double arg1, short arg2, short arg3, float arg4);
    void method13(unsigned arg0, short arg1, unsigned arg2, bool arg3, short arg4);
    void method14(short arg0, bool arg1, int arg2, bool arg3, int arg4);

    double memberVariable0{};
    double memberVariable1{};
    float memberVariable2{};
    bool memberVariable3{};
    int memberVariable4{};
    unsigned memberVariable5{};
    short memberVariable6{};
    double memberVariable7{};
    bool memberVariable8{};
    unsigned memberVariable9{};
    float memberVariable10{};
    short memberVariable11{};
    double memberVariable12{};
    bool memberVariable13{};
    bool memberVariable14{};

    static void function0(double arg0, float arg1, double arg2, float arg3, int arg4);
    static void function1(unsigned arg0, unsigned arg1, unsigned arg2, float arg3, bool arg4);
    static void function2(unsigned arg0, float arg1, short arg2, short arg3, int arg4);
    static float function3(unsigned arg0, int arg1, float arg2, float arg3, float arg4);
    static void function4(int arg0, short arg1, bool arg2, bool arg3, bool arg4);
    static unsigned function5(int arg0, float arg1, float arg2, bool arg3, unsigned arg4);
    static void function6(int arg0, short arg1, int arg2, unsigned arg3, short arg4);
    static unsigned function7(unsigned arg0, double arg1, double arg2, int arg3, double arg4);
    static void function8(bool arg0, int arg1, short arg2, float arg3, double arg4);
    static float function9(double arg0, double arg1, bool arg2, float arg3, int arg4);
    static void function10(bool arg0, short arg1, float arg2, unsigned arg3, unsigned arg4);
    static void function11(unsigned arg0, float arg1, float arg2, short arg3, int arg4);
    static int function12(bool arg0, short arg1, double arg2, float arg3, int arg4);
    static short function13(unsigned arg0, short arg1, double arg2, short arg3, bool arg4);
    static void function14(float arg0, double arg1, short arg2, unsigned arg3, double arg4);

    inline static unsigned variable0{};
    inline static unsigned variable1{};
    inline static float variable2{};
    inline static unsigned variable3{};
    inline static double variable4{};
    inline static double variable5{};
    inline static int variable6{};
    inline static short variable7{};
    inline static short variable8{};
    inline static bool variable9{};
    inline static double variable10{};
    inline static double variable11{};
    inline static int variable12{};
    inline static bool variable13{};
    inline static int variable14{};

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
