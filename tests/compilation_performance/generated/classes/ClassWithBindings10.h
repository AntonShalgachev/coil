#pragma once

// Generated with seed '88005553545'

#include "../../Common.h"

#include "ClassWithBindings1.h"
#include "ClassWithBindings2.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings6.h"
#include "ClassWithBindings16.h"
#include "ClassWithBindings23.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings43.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings76.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings83.h"

class ClassWithBindings10
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
    void method0(int arg0, int arg1, short arg2, float arg3, float arg4);
    void method1(float arg0, double arg1, int arg2, unsigned arg3, unsigned arg4);
    void method2(float arg0, bool arg1, bool arg2, int arg3, bool arg4);
    void method3(bool arg0, double arg1, float arg2, short arg3, float arg4);
    void method4(int arg0, bool arg1, double arg2, float arg3, short arg4);
    void method5(int arg0, short arg1, unsigned arg2, unsigned arg3, bool arg4);
    void method6(short arg0, unsigned arg1, float arg2, bool arg3, short arg4);
    void method7(float arg0, double arg1, double arg2, short arg3, int arg4);
    void method8(double arg0, double arg1, bool arg2, int arg3, float arg4);
    float method9(unsigned arg0, unsigned arg1, float arg2, unsigned arg3, double arg4);
    bool method10(bool arg0, bool arg1, short arg2, int arg3, float arg4);
    void method11(float arg0, int arg1, double arg2, short arg3, int arg4);
    double method12(float arg0, float arg1, unsigned arg2, double arg3, bool arg4);
    void method13(bool arg0, float arg1, int arg2, float arg3, double arg4);
    int method14(float arg0, int arg1, short arg2, short arg3, unsigned arg4);

    double memberVariable0{};
    float memberVariable1{};
    unsigned memberVariable2{};
    bool memberVariable3{};
    unsigned memberVariable4{};
    int memberVariable5{};
    short memberVariable6{};
    bool memberVariable7{};
    bool memberVariable8{};
    double memberVariable9{};
    bool memberVariable10{};
    int memberVariable11{};
    float memberVariable12{};
    int memberVariable13{};
    double memberVariable14{};

    static unsigned function0(int arg0, float arg1, float arg2, unsigned arg3, unsigned arg4);
    static void function1(int arg0, double arg1, double arg2, double arg3, unsigned arg4);
    static short function2(float arg0, float arg1, short arg2, bool arg3, int arg4);
    static void function3(unsigned arg0, short arg1, bool arg2, int arg3, unsigned arg4);
    static double function4(int arg0, short arg1, double arg2, bool arg3, float arg4);
    static void function5(unsigned arg0, short arg1, short arg2, float arg3, short arg4);
    static void function6(bool arg0, bool arg1, short arg2, double arg3, bool arg4);
    static bool function7(double arg0, int arg1, bool arg2, int arg3, double arg4);
    static int function8(unsigned arg0, int arg1, unsigned arg2, bool arg3, int arg4);
    static int function9(int arg0, int arg1, short arg2, unsigned arg3, double arg4);
    static unsigned function10(unsigned arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    static void function11(float arg0, double arg1, short arg2, bool arg3, bool arg4);
    static double function12(unsigned arg0, double arg1, unsigned arg2, short arg3, int arg4);
    static void function13(int arg0, double arg1, int arg2, short arg3, float arg4);
    static int function14(float arg0, int arg1, unsigned arg2, unsigned arg3, int arg4);

    inline static unsigned variable0{};
    inline static int variable1{};
    inline static bool variable2{};
    inline static float variable3{};
    inline static double variable4{};
    inline static int variable5{};
    inline static bool variable6{};
    inline static bool variable7{};
    inline static unsigned variable8{};
    inline static unsigned variable9{};
    inline static short variable10{};
    inline static float variable11{};
    inline static unsigned variable12{};
    inline static int variable13{};
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
