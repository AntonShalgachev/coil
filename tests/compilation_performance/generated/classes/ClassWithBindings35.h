#pragma once

// Generated with seed '88005553570'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings75.h"
#include "ClassWithBindings76.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings89.h"
#include "ClassWithBindings94.h"
#include "ClassWithBindings96.h"

class ClassWithBindings35
{
public:
    void work();

#if USE_COIL
    void registerBindings(coil::Bindings& bindings);
#endif

#if USE_MANUAL
    void registerBindings(DumbBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(short arg0, bool arg1, double arg2, double arg3, unsigned arg4);
    void method1(bool arg0, bool arg1, unsigned arg2, double arg3, int arg4);
    void method2(short arg0, bool arg1, double arg2, unsigned arg3, bool arg4);
    void method3(short arg0, double arg1, double arg2, float arg3, unsigned arg4);
    int method4(float arg0, short arg1, unsigned arg2, int arg3, float arg4);
    bool method5(unsigned arg0, short arg1, bool arg2, int arg3, float arg4);
    double method6(unsigned arg0, double arg1, double arg2, double arg3, bool arg4);
    unsigned method7(double arg0, int arg1, bool arg2, short arg3, unsigned arg4);
    double method8(float arg0, bool arg1, float arg2, double arg3, double arg4);
    void method9(float arg0, short arg1, double arg2, bool arg3, short arg4);
    float method10(short arg0, int arg1, float arg2, bool arg3, bool arg4);
    void method11(double arg0, int arg1, float arg2, short arg3, float arg4);
    bool method12(bool arg0, float arg1, short arg2, bool arg3, bool arg4);
    float method13(float arg0, float arg1, unsigned arg2, float arg3, float arg4);
    void method14(int arg0, short arg1, bool arg2, bool arg3, unsigned arg4);

    double memberVariable0{};
    int memberVariable1{};
    float memberVariable2{};
    double memberVariable3{};
    int memberVariable4{};
    short memberVariable5{};
    double memberVariable6{};
    unsigned memberVariable7{};
    short memberVariable8{};
    bool memberVariable9{};
    float memberVariable10{};
    float memberVariable11{};
    double memberVariable12{};
    float memberVariable13{};
    int memberVariable14{};

    static void function0(int arg0, int arg1, unsigned arg2, unsigned arg3, double arg4);
    static void function1(bool arg0, short arg1, bool arg2, unsigned arg3, float arg4);
    static int function2(double arg0, short arg1, double arg2, int arg3, int arg4);
    static void function3(int arg0, short arg1, unsigned arg2, float arg3, int arg4);
    static short function4(unsigned arg0, int arg1, bool arg2, short arg3, bool arg4);
    static unsigned function5(bool arg0, short arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    static void function6(short arg0, double arg1, float arg2, int arg3, float arg4);
    static short function7(short arg0, float arg1, bool arg2, short arg3, short arg4);
    static double function8(double arg0, int arg1, unsigned arg2, bool arg3, int arg4);
    static void function9(bool arg0, short arg1, bool arg2, short arg3, float arg4);
    static void function10(float arg0, short arg1, unsigned arg2, int arg3, int arg4);
    static double function11(float arg0, double arg1, float arg2, bool arg3, unsigned arg4);
    static void function12(int arg0, bool arg1, bool arg2, double arg3, float arg4);
    static void function13(bool arg0, int arg1, float arg2, int arg3, short arg4);
    static void function14(double arg0, bool arg1, float arg2, bool arg3, float arg4);

    inline static double variable0{};
    inline static int variable1{};
    inline static bool variable2{};
    inline static double variable3{};
    inline static short variable4{};
    inline static unsigned variable5{};
    inline static bool variable6{};
    inline static float variable7{};
    inline static float variable8{};
    inline static int variable9{};
    inline static bool variable10{};
    inline static int variable11{};
    inline static double variable12{};
    inline static double variable13{};
    inline static int variable14{};

#if USE_MANUAL
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
