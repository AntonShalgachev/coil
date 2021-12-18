#pragma once

// Generated with seed '88005553580'

#include "../../Common.h"

#include "ClassWithBindings9.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings16.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings67.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings75.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings80.h"
#include "ClassWithBindings81.h"
#include "ClassWithBindings87.h"
#include "ClassWithBindings88.h"
#include "ClassWithBindings91.h"

class ClassWithBindings45
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
    double method0(bool arg0, int arg1, double arg2, float arg3, bool arg4);
    void method1(bool arg0, short arg1, float arg2, int arg3, short arg4);
    void method2(float arg0, float arg1, int arg2, float arg3, unsigned arg4);
    void method3(double arg0, double arg1, short arg2, unsigned arg3, float arg4);
    void method4(float arg0, bool arg1, int arg2, float arg3, short arg4);
    unsigned method5(float arg0, unsigned arg1, unsigned arg2, double arg3, unsigned arg4);
    double method6(double arg0, double arg1, float arg2, float arg3, bool arg4);
    void method7(int arg0, short arg1, float arg2, int arg3, float arg4);
    unsigned method8(unsigned arg0, bool arg1, double arg2, unsigned arg3, float arg4);
    float method9(short arg0, bool arg1, double arg2, unsigned arg3, float arg4);
    unsigned method10(unsigned arg0, float arg1, int arg2, unsigned arg3, double arg4);
    void method11(bool arg0, double arg1, double arg2, int arg3, double arg4);
    double method12(double arg0, short arg1, short arg2, bool arg3, short arg4);
    double method13(float arg0, double arg1, double arg2, double arg3, bool arg4);
    void method14(bool arg0, short arg1, unsigned arg2, int arg3, bool arg4);

    float memberVariable0{};
    unsigned memberVariable1{};
    bool memberVariable2{};
    int memberVariable3{};
    unsigned memberVariable4{};
    double memberVariable5{};
    double memberVariable6{};
    double memberVariable7{};
    bool memberVariable8{};
    double memberVariable9{};
    int memberVariable10{};
    int memberVariable11{};
    unsigned memberVariable12{};
    double memberVariable13{};
    bool memberVariable14{};

    static void function0(int arg0, float arg1, int arg2, unsigned arg3, short arg4);
    static void function1(bool arg0, unsigned arg1, short arg2, unsigned arg3, int arg4);
    static void function2(bool arg0, bool arg1, double arg2, int arg3, unsigned arg4);
    static unsigned function3(short arg0, int arg1, unsigned arg2, bool arg3, double arg4);
    static void function4(int arg0, int arg1, unsigned arg2, short arg3, bool arg4);
    static double function5(bool arg0, unsigned arg1, double arg2, bool arg3, int arg4);
    static void function6(short arg0, float arg1, unsigned arg2, double arg3, double arg4);
    static double function7(double arg0, int arg1, double arg2, float arg3, double arg4);
    static void function8(unsigned arg0, float arg1, double arg2, unsigned arg3, short arg4);
    static void function9(int arg0, bool arg1, bool arg2, int arg3, bool arg4);
    static void function10(double arg0, unsigned arg1, float arg2, bool arg3, double arg4);
    static void function11(float arg0, int arg1, int arg2, unsigned arg3, unsigned arg4);
    static int function12(int arg0, int arg1, float arg2, int arg3, double arg4);
    static float function13(int arg0, double arg1, float arg2, unsigned arg3, double arg4);
    static void function14(short arg0, short arg1, bool arg2, int arg3, short arg4);

    inline static int variable0{};
    inline static float variable1{};
    inline static int variable2{};
    inline static bool variable3{};
    inline static bool variable4{};
    inline static int variable5{};
    inline static float variable6{};
    inline static float variable7{};
    inline static short variable8{};
    inline static float variable9{};
    inline static int variable10{};
    inline static bool variable11{};
    inline static int variable12{};
    inline static short variable13{};
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
