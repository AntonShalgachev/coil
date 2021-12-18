#pragma once

// Generated with seed '88005553600'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings2.h"
#include "ClassWithBindings7.h"
#include "ClassWithBindings10.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings67.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings78.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings94.h"

class ClassWithBindings65
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
    double method0(float arg0, double arg1, unsigned arg2, double arg3, short arg4);
    void method1(int arg0, bool arg1, double arg2, short arg3, unsigned arg4);
    float method2(short arg0, bool arg1, float arg2, float arg3, unsigned arg4);
    unsigned method3(short arg0, unsigned arg1, float arg2, bool arg3, short arg4);
    void method4(bool arg0, int arg1, int arg2, float arg3, double arg4);
    bool method5(int arg0, bool arg1, unsigned arg2, double arg3, bool arg4);
    void method6(int arg0, bool arg1, unsigned arg2, double arg3, int arg4);
    void method7(unsigned arg0, float arg1, bool arg2, unsigned arg3, int arg4);
    void method8(bool arg0, short arg1, bool arg2, bool arg3, unsigned arg4);
    void method9(int arg0, int arg1, bool arg2, float arg3, float arg4);
    void method10(unsigned arg0, bool arg1, float arg2, float arg3, bool arg4);
    bool method11(float arg0, bool arg1, bool arg2, short arg3, short arg4);
    void method12(int arg0, unsigned arg1, double arg2, short arg3, unsigned arg4);
    int method13(bool arg0, unsigned arg1, float arg2, double arg3, int arg4);
    int method14(short arg0, int arg1, unsigned arg2, double arg3, int arg4);

    bool memberVariable0{};
    double memberVariable1{};
    double memberVariable2{};
    int memberVariable3{};
    unsigned memberVariable4{};
    int memberVariable5{};
    double memberVariable6{};
    double memberVariable7{};
    bool memberVariable8{};
    double memberVariable9{};
    bool memberVariable10{};
    unsigned memberVariable11{};
    double memberVariable12{};
    double memberVariable13{};
    bool memberVariable14{};

    static void function0(double arg0, double arg1, unsigned arg2, short arg3, int arg4);
    static int function1(int arg0, bool arg1, bool arg2, int arg3, unsigned arg4);
    static void function2(bool arg0, bool arg1, double arg2, int arg3, double arg4);
    static void function3(float arg0, unsigned arg1, float arg2, int arg3, int arg4);
    static double function4(float arg0, int arg1, double arg2, float arg3, float arg4);
    static void function5(unsigned arg0, float arg1, double arg2, bool arg3, bool arg4);
    static void function6(int arg0, short arg1, float arg2, short arg3, bool arg4);
    static void function7(unsigned arg0, bool arg1, bool arg2, int arg3, double arg4);
    static int function8(short arg0, int arg1, bool arg2, bool arg3, int arg4);
    static void function9(short arg0, unsigned arg1, bool arg2, int arg3, double arg4);
    static double function10(bool arg0, double arg1, int arg2, short arg3, bool arg4);
    static short function11(short arg0, short arg1, int arg2, unsigned arg3, short arg4);
    static unsigned function12(int arg0, unsigned arg1, float arg2, short arg3, unsigned arg4);
    static void function13(unsigned arg0, double arg1, bool arg2, double arg3, int arg4);
    static void function14(short arg0, int arg1, double arg2, double arg3, float arg4);

    inline static float variable0{};
    inline static short variable1{};
    inline static bool variable2{};
    inline static double variable3{};
    inline static short variable4{};
    inline static int variable5{};
    inline static int variable6{};
    inline static bool variable7{};
    inline static unsigned variable8{};
    inline static float variable9{};
    inline static bool variable10{};
    inline static unsigned variable11{};
    inline static float variable12{};
    inline static short variable13{};
    inline static double variable14{};

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
