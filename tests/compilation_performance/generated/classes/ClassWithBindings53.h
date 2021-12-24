#pragma once

// Generated with seed '88005553588'

#include "../../Common.h"

#include "ClassWithBindings8.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings10.h"
#include "ClassWithBindings11.h"
#include "ClassWithBindings13.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings36.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings51.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings55.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings66.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings88.h"
#include "ClassWithBindings99.h"

class ClassWithBindings53
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
    void method0(float arg0, short arg1, double arg2, unsigned arg3, bool arg4);
    unsigned method1(double arg0, unsigned arg1, bool arg2, float arg3, int arg4);
    float method2(float arg0, unsigned arg1, float arg2, double arg3, bool arg4);
    int method3(float arg0, int arg1, double arg2, int arg3, unsigned arg4);
    double method4(unsigned arg0, float arg1, double arg2, unsigned arg3, short arg4);
    double method5(float arg0, unsigned arg1, float arg2, double arg3, short arg4);
    void method6(short arg0, unsigned arg1, short arg2, float arg3, short arg4);
    void method7(int arg0, bool arg1, bool arg2, int arg3, unsigned arg4);
    void method8(unsigned arg0, bool arg1, short arg2, short arg3, bool arg4);
    float method9(double arg0, float arg1, float arg2, unsigned arg3, double arg4);
    void method10(double arg0, bool arg1, short arg2, short arg3, unsigned arg4);
    void method11(float arg0, bool arg1, short arg2, bool arg3, bool arg4);
    void method12(bool arg0, int arg1, double arg2, float arg3, bool arg4);
    short method13(short arg0, int arg1, int arg2, double arg3, int arg4);
    void method14(short arg0, double arg1, int arg2, short arg3, unsigned arg4);

    int memberVariable0{};
    int memberVariable1{};
    short memberVariable2{};
    float memberVariable3{};
    unsigned memberVariable4{};
    int memberVariable5{};
    short memberVariable6{};
    bool memberVariable7{};
    int memberVariable8{};
    short memberVariable9{};
    unsigned memberVariable10{};
    short memberVariable11{};
    bool memberVariable12{};
    short memberVariable13{};
    double memberVariable14{};

    static unsigned function0(short arg0, unsigned arg1, bool arg2, short arg3, double arg4);
    static int function1(float arg0, short arg1, double arg2, int arg3, bool arg4);
    static void function2(float arg0, bool arg1, bool arg2, int arg3, short arg4);
    static bool function3(double arg0, double arg1, bool arg2, unsigned arg3, int arg4);
    static void function4(short arg0, float arg1, int arg2, short arg3, int arg4);
    static int function5(bool arg0, int arg1, int arg2, int arg3, unsigned arg4);
    static void function6(int arg0, float arg1, double arg2, float arg3, double arg4);
    static void function7(float arg0, int arg1, short arg2, bool arg3, float arg4);
    static void function8(unsigned arg0, int arg1, bool arg2, short arg3, short arg4);
    static void function9(short arg0, bool arg1, double arg2, double arg3, float arg4);
    static short function10(short arg0, bool arg1, short arg2, int arg3, short arg4);
    static void function11(short arg0, int arg1, float arg2, bool arg3, unsigned arg4);
    static void function12(int arg0, double arg1, unsigned arg2, short arg3, double arg4);
    static void function13(unsigned arg0, double arg1, int arg2, int arg3, float arg4);
    static void function14(short arg0, int arg1, bool arg2, int arg3, short arg4);

    inline static int variable0{};
    inline static float variable1{};
    inline static short variable2{};
    inline static int variable3{};
    inline static float variable4{};
    inline static short variable5{};
    inline static short variable6{};
    inline static bool variable7{};
    inline static short variable8{};
    inline static bool variable9{};
    inline static bool variable10{};
    inline static float variable11{};
    inline static float variable12{};
    inline static float variable13{};
    inline static float variable14{};

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
