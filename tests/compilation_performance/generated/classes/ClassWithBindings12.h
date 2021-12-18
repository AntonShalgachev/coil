#pragma once

// Generated with seed '88005553547'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings2.h"
#include "ClassWithBindings4.h"
#include "ClassWithBindings7.h"
#include "ClassWithBindings8.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings43.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings56.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings94.h"

class ClassWithBindings12
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
    bool method0(bool arg0, short arg1, int arg2, unsigned arg3, short arg4);
    void method1(bool arg0, short arg1, unsigned arg2, double arg3, int arg4);
    void method2(int arg0, int arg1, double arg2, float arg3, unsigned arg4);
    void method3(float arg0, bool arg1, double arg2, short arg3, float arg4);
    void method4(short arg0, int arg1, int arg2, unsigned arg3, int arg4);
    void method5(double arg0, unsigned arg1, unsigned arg2, short arg3, short arg4);
    void method6(int arg0, float arg1, short arg2, short arg3, double arg4);
    bool method7(double arg0, int arg1, bool arg2, unsigned arg3, bool arg4);
    void method8(float arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    short method9(bool arg0, int arg1, float arg2, unsigned arg3, short arg4);
    void method10(short arg0, short arg1, int arg2, short arg3, int arg4);
    void method11(bool arg0, bool arg1, short arg2, short arg3, bool arg4);
    float method12(short arg0, double arg1, float arg2, double arg3, unsigned arg4);
    short method13(short arg0, short arg1, unsigned arg2, bool arg3, short arg4);
    int method14(bool arg0, float arg1, bool arg2, double arg3, int arg4);

    int memberVariable0{};
    bool memberVariable1{};
    float memberVariable2{};
    bool memberVariable3{};
    int memberVariable4{};
    int memberVariable5{};
    unsigned memberVariable6{};
    float memberVariable7{};
    double memberVariable8{};
    unsigned memberVariable9{};
    int memberVariable10{};
    float memberVariable11{};
    int memberVariable12{};
    double memberVariable13{};
    bool memberVariable14{};

    static int function0(int arg0, int arg1, double arg2, float arg3, double arg4);
    static void function1(short arg0, bool arg1, unsigned arg2, int arg3, bool arg4);
    static void function2(double arg0, short arg1, short arg2, bool arg3, short arg4);
    static void function3(bool arg0, double arg1, int arg2, double arg3, bool arg4);
    static void function4(short arg0, bool arg1, float arg2, int arg3, bool arg4);
    static bool function5(bool arg0, float arg1, double arg2, bool arg3, unsigned arg4);
    static unsigned function6(unsigned arg0, double arg1, bool arg2, double arg3, int arg4);
    static void function7(double arg0, unsigned arg1, float arg2, int arg3, float arg4);
    static void function8(double arg0, short arg1, int arg2, float arg3, short arg4);
    static void function9(float arg0, bool arg1, short arg2, float arg3, float arg4);
    static void function10(short arg0, double arg1, unsigned arg2, unsigned arg3, double arg4);
    static void function11(unsigned arg0, short arg1, float arg2, unsigned arg3, int arg4);
    static void function12(bool arg0, bool arg1, int arg2, float arg3, double arg4);
    static void function13(bool arg0, unsigned arg1, short arg2, double arg3, bool arg4);
    static int function14(bool arg0, int arg1, short arg2, float arg3, int arg4);

    inline static float variable0{};
    inline static int variable1{};
    inline static float variable2{};
    inline static short variable3{};
    inline static bool variable4{};
    inline static int variable5{};
    inline static short variable6{};
    inline static int variable7{};
    inline static float variable8{};
    inline static short variable9{};
    inline static unsigned variable10{};
    inline static float variable11{};
    inline static double variable12{};
    inline static int variable13{};
    inline static bool variable14{};

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
