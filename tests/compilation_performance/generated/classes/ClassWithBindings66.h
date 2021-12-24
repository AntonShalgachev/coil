#pragma once

// Generated with seed '88005553601'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings16.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings43.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings76.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings93.h"
#include "ClassWithBindings95.h"

class ClassWithBindings66
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
    void method0(float arg0, double arg1, unsigned arg2, double arg3, float arg4);
    void method1(short arg0, bool arg1, float arg2, int arg3, bool arg4);
    unsigned method2(short arg0, bool arg1, short arg2, unsigned arg3, short arg4);
    void method3(float arg0, bool arg1, float arg2, int arg3, double arg4);
    void method4(double arg0, bool arg1, float arg2, bool arg3, int arg4);
    int method5(short arg0, double arg1, bool arg2, bool arg3, int arg4);
    unsigned method6(unsigned arg0, double arg1, unsigned arg2, float arg3, short arg4);
    double method7(int arg0, int arg1, short arg2, double arg3, float arg4);
    void method8(float arg0, short arg1, float arg2, int arg3, float arg4);
    unsigned method9(unsigned arg0, float arg1, short arg2, double arg3, int arg4);
    float method10(short arg0, double arg1, float arg2, unsigned arg3, float arg4);
    short method11(short arg0, unsigned arg1, int arg2, short arg3, int arg4);
    unsigned method12(bool arg0, bool arg1, unsigned arg2, unsigned arg3, double arg4);
    bool method13(short arg0, bool arg1, unsigned arg2, int arg3, bool arg4);
    void method14(unsigned arg0, unsigned arg1, float arg2, double arg3, int arg4);

    float memberVariable0{};
    int memberVariable1{};
    bool memberVariable2{};
    float memberVariable3{};
    bool memberVariable4{};
    bool memberVariable5{};
    short memberVariable6{};
    short memberVariable7{};
    double memberVariable8{};
    unsigned memberVariable9{};
    int memberVariable10{};
    bool memberVariable11{};
    unsigned memberVariable12{};
    double memberVariable13{};
    int memberVariable14{};

    static int function0(bool arg0, bool arg1, int arg2, short arg3, unsigned arg4);
    static short function1(bool arg0, unsigned arg1, bool arg2, short arg3, unsigned arg4);
    static void function2(int arg0, unsigned arg1, double arg2, int arg3, int arg4);
    static void function3(float arg0, int arg1, unsigned arg2, bool arg3, float arg4);
    static void function4(double arg0, unsigned arg1, unsigned arg2, short arg3, double arg4);
    static void function5(double arg0, unsigned arg1, int arg2, unsigned arg3, int arg4);
    static void function6(double arg0, short arg1, double arg2, bool arg3, float arg4);
    static short function7(short arg0, bool arg1, float arg2, bool arg3, short arg4);
    static int function8(float arg0, int arg1, short arg2, int arg3, short arg4);
    static unsigned function9(unsigned arg0, double arg1, bool arg2, unsigned arg3, unsigned arg4);
    static unsigned function10(bool arg0, unsigned arg1, bool arg2, float arg3, bool arg4);
    static void function11(float arg0, double arg1, short arg2, float arg3, bool arg4);
    static void function12(short arg0, bool arg1, unsigned arg2, float arg3, bool arg4);
    static short function13(short arg0, int arg1, double arg2, bool arg3, short arg4);
    static unsigned function14(unsigned arg0, int arg1, double arg2, double arg3, bool arg4);

    inline static bool variable0{};
    inline static bool variable1{};
    inline static bool variable2{};
    inline static float variable3{};
    inline static unsigned variable4{};
    inline static short variable5{};
    inline static short variable6{};
    inline static bool variable7{};
    inline static bool variable8{};
    inline static double variable9{};
    inline static short variable10{};
    inline static bool variable11{};
    inline static double variable12{};
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
