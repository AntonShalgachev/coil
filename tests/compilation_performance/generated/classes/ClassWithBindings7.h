#pragma once

// Generated with seed '88005553542'

#include "../../Common.h"

#include "ClassWithBindings6.h"
#include "ClassWithBindings10.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings24.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings26.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings76.h"

class ClassWithBindings7
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
    unsigned method0(short arg0, bool arg1, unsigned arg2, unsigned arg3, float arg4);
    bool method1(bool arg0, int arg1, double arg2, float arg3, float arg4);
    double method2(short arg0, short arg1, int arg2, double arg3, unsigned arg4);
    float method3(double arg0, double arg1, double arg2, float arg3, short arg4);
    void method4(double arg0, float arg1, unsigned arg2, float arg3, double arg4);
    void method5(float arg0, int arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method6(double arg0, double arg1, short arg2, float arg3, float arg4);
    void method7(bool arg0, float arg1, short arg2, short arg3, int arg4);
    short method8(double arg0, short arg1, float arg2, int arg3, int arg4);
    unsigned method9(float arg0, unsigned arg1, double arg2, short arg3, bool arg4);
    double method10(unsigned arg0, double arg1, double arg2, unsigned arg3, double arg4);
    double method11(float arg0, double arg1, float arg2, unsigned arg3, bool arg4);
    void method12(double arg0, double arg1, short arg2, unsigned arg3, double arg4);
    void method13(bool arg0, float arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    void method14(int arg0, double arg1, int arg2, double arg3, unsigned arg4);

    float memberVariable0{};
    float memberVariable1{};
    unsigned memberVariable2{};
    bool memberVariable3{};
    unsigned memberVariable4{};
    unsigned memberVariable5{};
    double memberVariable6{};
    double memberVariable7{};
    int memberVariable8{};
    bool memberVariable9{};
    int memberVariable10{};
    short memberVariable11{};
    unsigned memberVariable12{};
    short memberVariable13{};
    double memberVariable14{};

    static void function0(unsigned arg0, short arg1, bool arg2, short arg3, int arg4);
    static short function1(float arg0, short arg1, bool arg2, short arg3, int arg4);
    static void function2(unsigned arg0, bool arg1, double arg2, bool arg3, unsigned arg4);
    static void function3(short arg0, unsigned arg1, unsigned arg2, unsigned arg3, float arg4);
    static int function4(bool arg0, unsigned arg1, unsigned arg2, short arg3, int arg4);
    static unsigned function5(short arg0, bool arg1, unsigned arg2, float arg3, short arg4);
    static short function6(double arg0, bool arg1, int arg2, short arg3, unsigned arg4);
    static void function7(int arg0, double arg1, int arg2, unsigned arg3, short arg4);
    static unsigned function8(unsigned arg0, float arg1, double arg2, unsigned arg3, double arg4);
    static void function9(short arg0, bool arg1, double arg2, float arg3, int arg4);
    static void function10(short arg0, bool arg1, bool arg2, double arg3, double arg4);
    static unsigned function11(unsigned arg0, double arg1, unsigned arg2, bool arg3, int arg4);
    static void function12(int arg0, short arg1, double arg2, float arg3, unsigned arg4);
    static void function13(short arg0, bool arg1, int arg2, float arg3, bool arg4);
    static bool function14(bool arg0, short arg1, short arg2, float arg3, float arg4);

    inline static int variable0{};
    inline static unsigned variable1{};
    inline static unsigned variable2{};
    inline static unsigned variable3{};
    inline static double variable4{};
    inline static int variable5{};
    inline static double variable6{};
    inline static short variable7{};
    inline static short variable8{};
    inline static short variable9{};
    inline static double variable10{};
    inline static int variable11{};
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
