#pragma once

// Generated with seed '88005553548'

#include "../../Common.h"

#include "ClassWithBindings1.h"
#include "ClassWithBindings2.h"
#include "ClassWithBindings20.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings34.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings42.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings79.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings85.h"
#include "ClassWithBindings94.h"
#include "ClassWithBindings96.h"
#include "ClassWithBindings98.h"

class ClassWithBindings13
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
    unsigned method0(unsigned arg0, bool arg1, unsigned arg2, bool arg3, short arg4);
    int method1(short arg0, float arg1, bool arg2, float arg3, int arg4);
    short method2(short arg0, int arg1, double arg2, unsigned arg3, short arg4);
    short method3(float arg0, bool arg1, short arg2, bool arg3, unsigned arg4);
    float method4(float arg0, int arg1, bool arg2, bool arg3, float arg4);
    unsigned method5(unsigned arg0, unsigned arg1, short arg2, unsigned arg3, unsigned arg4);
    void method6(unsigned arg0, short arg1, int arg2, int arg3, int arg4);
    bool method7(int arg0, bool arg1, unsigned arg2, double arg3, double arg4);
    double method8(float arg0, bool arg1, double arg2, short arg3, int arg4);
    void method9(bool arg0, float arg1, bool arg2, unsigned arg3, double arg4);
    float method10(float arg0, double arg1, float arg2, short arg3, double arg4);
    void method11(unsigned arg0, unsigned arg1, bool arg2, short arg3, int arg4);
    int method12(int arg0, short arg1, double arg2, int arg3, short arg4);
    void method13(short arg0, int arg1, short arg2, double arg3, float arg4);
    bool method14(int arg0, bool arg1, bool arg2, int arg3, bool arg4);

    float memberVariable0{};
    unsigned memberVariable1{};
    unsigned memberVariable2{};
    short memberVariable3{};
    float memberVariable4{};
    double memberVariable5{};
    int memberVariable6{};
    double memberVariable7{};
    bool memberVariable8{};
    unsigned memberVariable9{};
    short memberVariable10{};
    short memberVariable11{};
    short memberVariable12{};
    float memberVariable13{};
    unsigned memberVariable14{};

    static unsigned function0(double arg0, int arg1, short arg2, short arg3, unsigned arg4);
    static unsigned function1(bool arg0, float arg1, float arg2, double arg3, unsigned arg4);
    static bool function2(unsigned arg0, double arg1, bool arg2, bool arg3, short arg4);
    static bool function3(double arg0, float arg1, int arg2, unsigned arg3, bool arg4);
    static void function4(short arg0, double arg1, unsigned arg2, bool arg3, bool arg4);
    static float function5(float arg0, bool arg1, bool arg2, bool arg3, float arg4);
    static bool function6(int arg0, unsigned arg1, bool arg2, short arg3, short arg4);
    static void function7(double arg0, bool arg1, int arg2, unsigned arg3, bool arg4);
    static float function8(float arg0, float arg1, bool arg2, float arg3, unsigned arg4);
    static short function9(short arg0, bool arg1, short arg2, short arg3, unsigned arg4);
    static void function10(int arg0, float arg1, bool arg2, double arg3, int arg4);
    static bool function11(int arg0, float arg1, unsigned arg2, unsigned arg3, bool arg4);
    static short function12(float arg0, short arg1, double arg2, float arg3, double arg4);
    static void function13(float arg0, double arg1, double arg2, int arg3, float arg4);
    static unsigned function14(int arg0, int arg1, bool arg2, unsigned arg3, double arg4);

    inline static double variable0{};
    inline static int variable1{};
    inline static short variable2{};
    inline static unsigned variable3{};
    inline static bool variable4{};
    inline static unsigned variable5{};
    inline static int variable6{};
    inline static float variable7{};
    inline static int variable8{};
    inline static int variable9{};
    inline static float variable10{};
    inline static double variable11{};
    inline static short variable12{};
    inline static double variable13{};
    inline static short variable14{};

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
