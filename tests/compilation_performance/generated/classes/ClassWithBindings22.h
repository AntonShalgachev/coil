#pragma once

// Generated with seed '88005553557'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings3.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings6.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings16.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings43.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings62.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings78.h"
#include "ClassWithBindings93.h"

class ClassWithBindings22
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
    void method0(short arg0, double arg1, double arg2, short arg3, bool arg4);
    short method1(int arg0, short arg1, unsigned arg2, short arg3, unsigned arg4);
    void method2(int arg0, unsigned arg1, double arg2, double arg3, unsigned arg4);
    double method3(int arg0, float arg1, float arg2, unsigned arg3, double arg4);
    unsigned method4(unsigned arg0, unsigned arg1, double arg2, short arg3, bool arg4);
    float method5(int arg0, unsigned arg1, int arg2, short arg3, float arg4);
    double method6(unsigned arg0, double arg1, bool arg2, int arg3, double arg4);
    float method7(unsigned arg0, bool arg1, float arg2, unsigned arg3, int arg4);
    void method8(double arg0, int arg1, int arg2, float arg3, unsigned arg4);
    double method9(double arg0, float arg1, double arg2, double arg3, unsigned arg4);
    int method10(int arg0, unsigned arg1, float arg2, int arg3, short arg4);
    double method11(bool arg0, bool arg1, float arg2, double arg3, int arg4);
    bool method12(int arg0, short arg1, unsigned arg2, short arg3, bool arg4);
    short method13(float arg0, float arg1, unsigned arg2, short arg3, short arg4);
    void method14(float arg0, short arg1, bool arg2, unsigned arg3, int arg4);

    bool memberVariable0{};
    int memberVariable1{};
    double memberVariable2{};
    double memberVariable3{};
    double memberVariable4{};
    bool memberVariable5{};
    unsigned memberVariable6{};
    unsigned memberVariable7{};
    bool memberVariable8{};
    unsigned memberVariable9{};
    bool memberVariable10{};
    float memberVariable11{};
    double memberVariable12{};
    unsigned memberVariable13{};
    float memberVariable14{};

    static void function0(double arg0, short arg1, double arg2, float arg3, unsigned arg4);
    static void function1(bool arg0, bool arg1, short arg2, int arg3, bool arg4);
    static int function2(bool arg0, int arg1, bool arg2, short arg3, int arg4);
    static unsigned function3(unsigned arg0, unsigned arg1, bool arg2, double arg3, bool arg4);
    static int function4(double arg0, double arg1, int arg2, float arg3, int arg4);
    static void function5(bool arg0, double arg1, short arg2, short arg3, unsigned arg4);
    static void function6(double arg0, bool arg1, unsigned arg2, double arg3, double arg4);
    static double function7(double arg0, float arg1, short arg2, unsigned arg3, bool arg4);
    static double function8(double arg0, bool arg1, unsigned arg2, int arg3, short arg4);
    static void function9(bool arg0, double arg1, unsigned arg2, float arg3, double arg4);
    static void function10(float arg0, int arg1, double arg2, unsigned arg3, bool arg4);
    static void function11(bool arg0, float arg1, unsigned arg2, short arg3, float arg4);
    static void function12(int arg0, bool arg1, double arg2, unsigned arg3, float arg4);
    static void function13(float arg0, short arg1, unsigned arg2, unsigned arg3, short arg4);
    static void function14(short arg0, short arg1, double arg2, bool arg3, int arg4);

    inline static float variable0{};
    inline static unsigned variable1{};
    inline static int variable2{};
    inline static double variable3{};
    inline static unsigned variable4{};
    inline static short variable5{};
    inline static float variable6{};
    inline static int variable7{};
    inline static double variable8{};
    inline static float variable9{};
    inline static bool variable10{};
    inline static int variable11{};
    inline static int variable12{};
    inline static double variable13{};
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
