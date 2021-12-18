#pragma once

// Generated with seed '88005553593'

#include "../../Common.h"

#include "ClassWithBindings9.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings22.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings34.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings57.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings86.h"
#include "ClassWithBindings95.h"

class ClassWithBindings58
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
    void method0(double arg0, short arg1, bool arg2, unsigned arg3, short arg4);
    void method1(bool arg0, bool arg1, bool arg2, int arg3, unsigned arg4);
    bool method2(bool arg0, bool arg1, short arg2, float arg3, bool arg4);
    float method3(short arg0, unsigned arg1, float arg2, int arg3, float arg4);
    void method4(double arg0, float arg1, bool arg2, short arg3, float arg4);
    void method5(unsigned arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    void method6(float arg0, unsigned arg1, float arg2, double arg3, float arg4);
    void method7(int arg0, bool arg1, int arg2, float arg3, float arg4);
    void method8(bool arg0, short arg1, short arg2, unsigned arg3, double arg4);
    void method9(float arg0, int arg1, unsigned arg2, short arg3, short arg4);
    void method10(unsigned arg0, short arg1, unsigned arg2, double arg3, double arg4);
    void method11(short arg0, bool arg1, float arg2, double arg3, double arg4);
    int method12(int arg0, int arg1, float arg2, float arg3, int arg4);
    bool method13(bool arg0, short arg1, bool arg2, short arg3, short arg4);
    void method14(short arg0, unsigned arg1, double arg2, double arg3, int arg4);

    int memberVariable0{};
    bool memberVariable1{};
    short memberVariable2{};
    bool memberVariable3{};
    short memberVariable4{};
    short memberVariable5{};
    bool memberVariable6{};
    int memberVariable7{};
    bool memberVariable8{};
    short memberVariable9{};
    short memberVariable10{};
    bool memberVariable11{};
    double memberVariable12{};
    short memberVariable13{};
    float memberVariable14{};

    static void function0(short arg0, bool arg1, short arg2, unsigned arg3, unsigned arg4);
    static int function1(double arg0, int arg1, float arg2, int arg3, double arg4);
    static void function2(float arg0, double arg1, float arg2, short arg3, int arg4);
    static double function3(unsigned arg0, short arg1, short arg2, double arg3, short arg4);
    static bool function4(int arg0, int arg1, unsigned arg2, bool arg3, float arg4);
    static void function5(double arg0, unsigned arg1, bool arg2, unsigned arg3, float arg4);
    static bool function6(int arg0, unsigned arg1, short arg2, unsigned arg3, bool arg4);
    static short function7(int arg0, int arg1, short arg2, bool arg3, float arg4);
    static bool function8(double arg0, bool arg1, double arg2, short arg3, bool arg4);
    static short function9(bool arg0, bool arg1, short arg2, float arg3, short arg4);
    static bool function10(float arg0, short arg1, int arg2, float arg3, bool arg4);
    static void function11(bool arg0, bool arg1, bool arg2, unsigned arg3, double arg4);
    static int function12(double arg0, double arg1, unsigned arg2, int arg3, double arg4);
    static int function13(int arg0, float arg1, float arg2, short arg3, int arg4);
    static double function14(unsigned arg0, bool arg1, unsigned arg2, double arg3, unsigned arg4);

    inline static bool variable0{};
    inline static bool variable1{};
    inline static int variable2{};
    inline static int variable3{};
    inline static unsigned variable4{};
    inline static bool variable5{};
    inline static double variable6{};
    inline static double variable7{};
    inline static unsigned variable8{};
    inline static bool variable9{};
    inline static bool variable10{};
    inline static int variable11{};
    inline static double variable12{};
    inline static unsigned variable13{};
    inline static int variable14{};

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
