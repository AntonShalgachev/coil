#pragma once

// Generated with seed '88005553623'

#include "../../Common.h"

#include "ClassWithBindings9.h"
#include "ClassWithBindings11.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings43.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings78.h"
#include "ClassWithBindings81.h"
#include "ClassWithBindings83.h"
#include "ClassWithBindings91.h"
#include "ClassWithBindings93.h"
#include "ClassWithBindings94.h"

class ClassWithBindings88
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
    double method0(unsigned arg0, int arg1, unsigned arg2, double arg3, double arg4);
    void method1(double arg0, bool arg1, short arg2, bool arg3, short arg4);
    void method2(unsigned arg0, int arg1, short arg2, bool arg3, float arg4);
    int method3(short arg0, double arg1, unsigned arg2, int arg3, int arg4);
    float method4(int arg0, int arg1, float arg2, bool arg3, bool arg4);
    int method5(short arg0, int arg1, int arg2, double arg3, float arg4);
    int method6(double arg0, double arg1, unsigned arg2, int arg3, unsigned arg4);
    void method7(double arg0, unsigned arg1, short arg2, unsigned arg3, int arg4);
    bool method8(short arg0, double arg1, unsigned arg2, short arg3, bool arg4);
    void method9(float arg0, bool arg1, float arg2, float arg3, short arg4);
    float method10(float arg0, bool arg1, double arg2, double arg3, double arg4);
    unsigned method11(unsigned arg0, bool arg1, short arg2, double arg3, int arg4);
    int method12(float arg0, int arg1, float arg2, int arg3, bool arg4);
    void method13(bool arg0, int arg1, bool arg2, float arg3, float arg4);
    int method14(int arg0, unsigned arg1, unsigned arg2, float arg3, unsigned arg4);

    int memberVariable0{};
    float memberVariable1{};
    double memberVariable2{};
    int memberVariable3{};
    double memberVariable4{};
    int memberVariable5{};
    unsigned memberVariable6{};
    float memberVariable7{};
    int memberVariable8{};
    bool memberVariable9{};
    unsigned memberVariable10{};
    int memberVariable11{};
    double memberVariable12{};
    bool memberVariable13{};
    bool memberVariable14{};

    static void function0(double arg0, float arg1, double arg2, bool arg3, double arg4);
    static void function1(float arg0, double arg1, double arg2, unsigned arg3, float arg4);
    static double function2(float arg0, float arg1, unsigned arg2, double arg3, float arg4);
    static float function3(unsigned arg0, unsigned arg1, short arg2, float arg3, float arg4);
    static void function4(short arg0, double arg1, double arg2, bool arg3, short arg4);
    static void function5(unsigned arg0, double arg1, unsigned arg2, float arg3, float arg4);
    static void function6(short arg0, float arg1, float arg2, double arg3, bool arg4);
    static void function7(int arg0, double arg1, short arg2, int arg3, short arg4);
    static float function8(bool arg0, short arg1, double arg2, float arg3, float arg4);
    static int function9(int arg0, short arg1, short arg2, unsigned arg3, double arg4);
    static void function10(bool arg0, unsigned arg1, short arg2, double arg3, bool arg4);
    static double function11(double arg0, unsigned arg1, unsigned arg2, double arg3, bool arg4);
    static void function12(int arg0, unsigned arg1, float arg2, unsigned arg3, int arg4);
    static void function13(float arg0, float arg1, bool arg2, float arg3, short arg4);
    static void function14(bool arg0, float arg1, int arg2, int arg3, int arg4);

    inline static short variable0{};
    inline static int variable1{};
    inline static bool variable2{};
    inline static unsigned variable3{};
    inline static bool variable4{};
    inline static short variable5{};
    inline static double variable6{};
    inline static short variable7{};
    inline static int variable8{};
    inline static float variable9{};
    inline static short variable10{};
    inline static unsigned variable11{};
    inline static unsigned variable12{};
    inline static short variable13{};
    inline static unsigned variable14{};

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
