#pragma once

// Generated with seed '88005553603'

#include "../../Common.h"

#include "ClassWithBindings7.h"
#include "ClassWithBindings11.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings63.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings95.h"
#include "ClassWithBindings96.h"

class ClassWithBindings68
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
    void method0(float arg0, float arg1, unsigned arg2, short arg3, float arg4);
    void method1(short arg0, double arg1, int arg2, unsigned arg3, bool arg4);
    unsigned method2(unsigned arg0, bool arg1, double arg2, unsigned arg3, unsigned arg4);
    float method3(float arg0, float arg1, float arg2, unsigned arg3, bool arg4);
    unsigned method4(short arg0, float arg1, bool arg2, unsigned arg3, double arg4);
    void method5(unsigned arg0, float arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    unsigned method6(unsigned arg0, bool arg1, float arg2, float arg3, float arg4);
    void method7(short arg0, double arg1, double arg2, bool arg3, float arg4);
    void method8(bool arg0, float arg1, float arg2, short arg3, bool arg4);
    void method9(short arg0, int arg1, bool arg2, double arg3, int arg4);
    float method10(float arg0, int arg1, float arg2, float arg3, double arg4);
    void method11(double arg0, double arg1, double arg2, float arg3, short arg4);
    int method12(bool arg0, bool arg1, int arg2, int arg3, float arg4);
    void method13(unsigned arg0, int arg1, bool arg2, int arg3, double arg4);
    void method14(short arg0, short arg1, float arg2, int arg3, double arg4);

    unsigned memberVariable0{};
    int memberVariable1{};
    unsigned memberVariable2{};
    unsigned memberVariable3{};
    bool memberVariable4{};
    double memberVariable5{};
    int memberVariable6{};
    double memberVariable7{};
    unsigned memberVariable8{};
    double memberVariable9{};
    float memberVariable10{};
    float memberVariable11{};
    double memberVariable12{};
    short memberVariable13{};
    short memberVariable14{};

    static short function0(int arg0, short arg1, double arg2, short arg3, short arg4);
    static int function1(int arg0, unsigned arg1, bool arg2, int arg3, bool arg4);
    static bool function2(bool arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    static float function3(float arg0, double arg1, int arg2, float arg3, unsigned arg4);
    static void function4(short arg0, double arg1, unsigned arg2, unsigned arg3, bool arg4);
    static void function5(float arg0, unsigned arg1, double arg2, float arg3, double arg4);
    static void function6(unsigned arg0, float arg1, unsigned arg2, short arg3, bool arg4);
    static void function7(bool arg0, double arg1, float arg2, float arg3, int arg4);
    static int function8(bool arg0, bool arg1, int arg2, unsigned arg3, int arg4);
    static void function9(double arg0, short arg1, bool arg2, float arg3, bool arg4);
    static int function10(int arg0, bool arg1, bool arg2, bool arg3, int arg4);
    static double function11(bool arg0, bool arg1, double arg2, double arg3, int arg4);
    static bool function12(unsigned arg0, short arg1, short arg2, int arg3, bool arg4);
    static void function13(int arg0, short arg1, short arg2, int arg3, short arg4);
    static void function14(int arg0, bool arg1, double arg2, int arg3, short arg4);

    inline static int variable0{};
    inline static int variable1{};
    inline static short variable2{};
    inline static bool variable3{};
    inline static float variable4{};
    inline static int variable5{};
    inline static double variable6{};
    inline static int variable7{};
    inline static unsigned variable8{};
    inline static double variable9{};
    inline static bool variable10{};
    inline static float variable11{};
    inline static float variable12{};
    inline static int variable13{};
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
