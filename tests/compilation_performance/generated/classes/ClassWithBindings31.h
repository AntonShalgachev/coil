#pragma once

// Generated with seed '88005553566'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings3.h"
#include "ClassWithBindings4.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings7.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings16.h"
#include "ClassWithBindings18.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings42.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings67.h"
#include "ClassWithBindings78.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings87.h"
#include "ClassWithBindings91.h"

class ClassWithBindings31
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
    void method0(bool arg0, unsigned arg1, int arg2, unsigned arg3, float arg4);
    bool method1(bool arg0, bool arg1, short arg2, short arg3, double arg4);
    bool method2(int arg0, bool arg1, short arg2, double arg3, unsigned arg4);
    void method3(double arg0, unsigned arg1, unsigned arg2, bool arg3, double arg4);
    void method4(unsigned arg0, double arg1, double arg2, float arg3, float arg4);
    double method5(float arg0, short arg1, short arg2, double arg3, float arg4);
    float method6(bool arg0, float arg1, float arg2, int arg3, short arg4);
    void method7(unsigned arg0, short arg1, double arg2, int arg3, int arg4);
    bool method8(bool arg0, bool arg1, int arg2, int arg3, short arg4);
    unsigned method9(unsigned arg0, double arg1, bool arg2, bool arg3, float arg4);
    short method10(int arg0, float arg1, short arg2, double arg3, float arg4);
    void method11(short arg0, int arg1, float arg2, int arg3, double arg4);
    float method12(float arg0, short arg1, double arg2, double arg3, double arg4);
    double method13(short arg0, bool arg1, int arg2, unsigned arg3, double arg4);
    void method14(int arg0, int arg1, bool arg2, double arg3, unsigned arg4);

    bool memberVariable0{};
    double memberVariable1{};
    int memberVariable2{};
    int memberVariable3{};
    bool memberVariable4{};
    bool memberVariable5{};
    double memberVariable6{};
    short memberVariable7{};
    int memberVariable8{};
    int memberVariable9{};
    float memberVariable10{};
    bool memberVariable11{};
    short memberVariable12{};
    unsigned memberVariable13{};
    float memberVariable14{};

    static double function0(int arg0, float arg1, double arg2, double arg3, int arg4);
    static void function1(float arg0, int arg1, short arg2, unsigned arg3, float arg4);
    static void function2(double arg0, short arg1, int arg2, short arg3, int arg4);
    static void function3(bool arg0, int arg1, double arg2, short arg3, int arg4);
    static short function4(short arg0, double arg1, bool arg2, unsigned arg3, unsigned arg4);
    static unsigned function5(double arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    static void function6(bool arg0, float arg1, int arg2, bool arg3, short arg4);
    static void function7(double arg0, int arg1, float arg2, short arg3, int arg4);
    static unsigned function8(float arg0, unsigned arg1, float arg2, unsigned arg3, bool arg4);
    static double function9(short arg0, unsigned arg1, float arg2, double arg3, unsigned arg4);
    static short function10(double arg0, short arg1, float arg2, short arg3, short arg4);
    static void function11(int arg0, float arg1, double arg2, float arg3, float arg4);
    static void function12(unsigned arg0, short arg1, double arg2, unsigned arg3, unsigned arg4);
    static void function13(int arg0, double arg1, short arg2, float arg3, unsigned arg4);
    static bool function14(double arg0, bool arg1, unsigned arg2, bool arg3, short arg4);

    inline static bool variable0{};
    inline static unsigned variable1{};
    inline static float variable2{};
    inline static float variable3{};
    inline static unsigned variable4{};
    inline static unsigned variable5{};
    inline static unsigned variable6{};
    inline static int variable7{};
    inline static float variable8{};
    inline static bool variable9{};
    inline static double variable10{};
    inline static bool variable11{};
    inline static double variable12{};
    inline static double variable13{};
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
