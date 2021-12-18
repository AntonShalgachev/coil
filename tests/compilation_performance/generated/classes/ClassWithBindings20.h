#pragma once

// Generated with seed '88005553555'

#include "../../Common.h"

#include "ClassWithBindings7.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings16.h"
#include "ClassWithBindings18.h"
#include "ClassWithBindings24.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings75.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings88.h"
#include "ClassWithBindings96.h"
#include "ClassWithBindings98.h"

class ClassWithBindings20
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

#ifdef MANUAL_DEBUG_BINDINGS
    void registerBindings(DumbBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, short arg1, int arg2, bool arg3, int arg4);
    void method1(int arg0, float arg1, bool arg2, float arg3, short arg4);
    unsigned method2(bool arg0, int arg1, bool arg2, bool arg3, unsigned arg4);
    void method3(int arg0, float arg1, float arg2, bool arg3, int arg4);
    void method4(double arg0, float arg1, double arg2, bool arg3, bool arg4);
    void method5(int arg0, float arg1, bool arg2, bool arg3, int arg4);
    void method6(float arg0, unsigned arg1, int arg2, bool arg3, short arg4);
    void method7(int arg0, int arg1, unsigned arg2, float arg3, short arg4);
    void method8(bool arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method9(double arg0, unsigned arg1, bool arg2, short arg3, float arg4);
    unsigned method10(float arg0, bool arg1, int arg2, int arg3, unsigned arg4);
    void method11(bool arg0, double arg1, bool arg2, float arg3, short arg4);
    short method12(int arg0, short arg1, short arg2, float arg3, float arg4);
    void method13(float arg0, bool arg1, double arg2, int arg3, bool arg4);
    void method14(unsigned arg0, unsigned arg1, unsigned arg2, short arg3, float arg4);

    bool memberVariable0{};
    bool memberVariable1{};
    float memberVariable2{};
    bool memberVariable3{};
    short memberVariable4{};
    double memberVariable5{};
    double memberVariable6{};
    unsigned memberVariable7{};
    short memberVariable8{};
    unsigned memberVariable9{};
    double memberVariable10{};
    float memberVariable11{};
    float memberVariable12{};
    float memberVariable13{};
    int memberVariable14{};

    static bool function0(short arg0, bool arg1, short arg2, unsigned arg3, unsigned arg4);
    static void function1(double arg0, short arg1, int arg2, int arg3, double arg4);
    static void function2(int arg0, int arg1, unsigned arg2, int arg3, float arg4);
    static void function3(int arg0, unsigned arg1, short arg2, float arg3, bool arg4);
    static bool function4(double arg0, float arg1, bool arg2, int arg3, unsigned arg4);
    static bool function5(bool arg0, double arg1, float arg2, int arg3, bool arg4);
    static void function6(int arg0, unsigned arg1, int arg2, float arg3, short arg4);
    static void function7(int arg0, double arg1, float arg2, float arg3, short arg4);
    static int function8(double arg0, bool arg1, bool arg2, short arg3, int arg4);
    static void function9(bool arg0, double arg1, unsigned arg2, short arg3, unsigned arg4);
    static void function10(unsigned arg0, double arg1, bool arg2, double arg3, double arg4);
    static bool function11(bool arg0, double arg1, unsigned arg2, double arg3, bool arg4);
    static float function12(float arg0, float arg1, float arg2, float arg3, unsigned arg4);
    static void function13(short arg0, bool arg1, int arg2, int arg3, int arg4);
    static short function14(short arg0, unsigned arg1, int arg2, bool arg3, int arg4);

    inline static double variable0{};
    inline static bool variable1{};
    inline static int variable2{};
    inline static double variable3{};
    inline static double variable4{};
    inline static unsigned variable5{};
    inline static bool variable6{};
    inline static bool variable7{};
    inline static int variable8{};
    inline static float variable9{};
    inline static float variable10{};
    inline static double variable11{};
    inline static double variable12{};
    inline static double variable13{};
    inline static float variable14{};

#ifdef MANUAL_DEBUG_BINDINGS
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
