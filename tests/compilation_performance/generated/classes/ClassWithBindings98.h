#pragma once

// Generated with seed '88005553633'

#include "../../Common.h"

#include "ClassWithBindings13.h"
#include "ClassWithBindings16.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings48.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings56.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings67.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings89.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings99.h"

class ClassWithBindings98
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
    short method0(short arg0, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method1(short arg0, double arg1, int arg2, bool arg3, bool arg4);
    void method2(bool arg0, bool arg1, unsigned arg2, short arg3, int arg4);
    void method3(bool arg0, short arg1, unsigned arg2, int arg3, unsigned arg4);
    void method4(double arg0, short arg1, int arg2, bool arg3, int arg4);
    void method5(int arg0, double arg1, float arg2, int arg3, int arg4);
    int method6(short arg0, unsigned arg1, float arg2, short arg3, int arg4);
    void method7(bool arg0, short arg1, double arg2, float arg3, double arg4);
    int method8(double arg0, int arg1, short arg2, bool arg3, int arg4);
    double method9(float arg0, double arg1, double arg2, float arg3, float arg4);
    bool method10(double arg0, short arg1, bool arg2, unsigned arg3, double arg4);
    void method11(int arg0, unsigned arg1, double arg2, bool arg3, unsigned arg4);
    void method12(double arg0, short arg1, double arg2, bool arg3, unsigned arg4);
    void method13(unsigned arg0, float arg1, double arg2, float arg3, unsigned arg4);
    void method14(short arg0, float arg1, short arg2, unsigned arg3, float arg4);

    unsigned memberVariable0{};
    bool memberVariable1{};
    short memberVariable2{};
    unsigned memberVariable3{};
    bool memberVariable4{};
    int memberVariable5{};
    double memberVariable6{};
    int memberVariable7{};
    bool memberVariable8{};
    int memberVariable9{};
    unsigned memberVariable10{};
    double memberVariable11{};
    unsigned memberVariable12{};
    double memberVariable13{};
    int memberVariable14{};

    static void function0(unsigned arg0, unsigned arg1, unsigned arg2, bool arg3, bool arg4);
    static void function1(bool arg0, short arg1, double arg2, float arg3, bool arg4);
    static void function2(unsigned arg0, int arg1, float arg2, short arg3, float arg4);
    static unsigned function3(float arg0, bool arg1, bool arg2, float arg3, unsigned arg4);
    static unsigned function4(double arg0, int arg1, bool arg2, double arg3, unsigned arg4);
    static unsigned function5(short arg0, int arg1, unsigned arg2, unsigned arg3, float arg4);
    static void function6(unsigned arg0, float arg1, int arg2, int arg3, unsigned arg4);
    static unsigned function7(float arg0, unsigned arg1, unsigned arg2, float arg3, bool arg4);
    static bool function8(double arg0, int arg1, float arg2, bool arg3, bool arg4);
    static int function9(unsigned arg0, bool arg1, bool arg2, unsigned arg3, int arg4);
    static int function10(double arg0, unsigned arg1, double arg2, int arg3, int arg4);
    static unsigned function11(bool arg0, double arg1, bool arg2, double arg3, unsigned arg4);
    static float function12(float arg0, float arg1, double arg2, short arg3, int arg4);
    static short function13(short arg0, bool arg1, unsigned arg2, unsigned arg3, double arg4);
    static short function14(double arg0, short arg1, double arg2, bool arg3, unsigned arg4);

    inline static double variable0{};
    inline static float variable1{};
    inline static bool variable2{};
    inline static double variable3{};
    inline static short variable4{};
    inline static double variable5{};
    inline static short variable6{};
    inline static bool variable7{};
    inline static unsigned variable8{};
    inline static int variable9{};
    inline static bool variable10{};
    inline static short variable11{};
    inline static int variable12{};
    inline static unsigned variable13{};
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
