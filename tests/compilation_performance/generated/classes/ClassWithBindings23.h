#pragma once

// Generated with seed '88005553558'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings11.h"
#include "ClassWithBindings16.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings45.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings54.h"
#include "ClassWithBindings56.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings81.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings96.h"

class ClassWithBindings23
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
    void method0(float arg0, short arg1, short arg2, unsigned arg3, int arg4);
    void method1(float arg0, float arg1, int arg2, bool arg3, unsigned arg4);
    int method2(double arg0, float arg1, unsigned arg2, int arg3, int arg4);
    void method3(short arg0, short arg1, bool arg2, float arg3, bool arg4);
    void method4(float arg0, short arg1, unsigned arg2, unsigned arg3, int arg4);
    void method5(bool arg0, int arg1, double arg2, unsigned arg3, double arg4);
    void method6(bool arg0, double arg1, int arg2, float arg3, int arg4);
    void method7(double arg0, bool arg1, int arg2, bool arg3, float arg4);
    double method8(double arg0, bool arg1, float arg2, float arg3, bool arg4);
    unsigned method9(int arg0, unsigned arg1, bool arg2, float arg3, short arg4);
    void method10(int arg0, int arg1, unsigned arg2, int arg3, float arg4);
    short method11(int arg0, short arg1, bool arg2, unsigned arg3, short arg4);
    bool method12(float arg0, bool arg1, short arg2, bool arg3, bool arg4);
    double method13(double arg0, unsigned arg1, unsigned arg2, int arg3, float arg4);
    int method14(float arg0, float arg1, int arg2, double arg3, int arg4);

    bool memberVariable0{};
    unsigned memberVariable1{};
    int memberVariable2{};
    unsigned memberVariable3{};
    double memberVariable4{};
    double memberVariable5{};
    bool memberVariable6{};
    int memberVariable7{};
    int memberVariable8{};
    float memberVariable9{};
    unsigned memberVariable10{};
    short memberVariable11{};
    short memberVariable12{};
    short memberVariable13{};
    float memberVariable14{};

    static bool function0(float arg0, bool arg1, float arg2, double arg3, short arg4);
    static void function1(short arg0, double arg1, int arg2, float arg3, short arg4);
    static void function2(short arg0, short arg1, unsigned arg2, int arg3, double arg4);
    static short function3(double arg0, short arg1, short arg2, bool arg3, float arg4);
    static unsigned function4(unsigned arg0, double arg1, int arg2, int arg3, short arg4);
    static void function5(float arg0, int arg1, bool arg2, float arg3, short arg4);
    static void function6(float arg0, double arg1, bool arg2, double arg3, float arg4);
    static double function7(unsigned arg0, short arg1, float arg2, short arg3, double arg4);
    static void function8(short arg0, unsigned arg1, bool arg2, int arg3, float arg4);
    static bool function9(short arg0, float arg1, short arg2, float arg3, bool arg4);
    static void function10(short arg0, float arg1, int arg2, int arg3, unsigned arg4);
    static void function11(short arg0, float arg1, short arg2, unsigned arg3, int arg4);
    static void function12(short arg0, int arg1, float arg2, unsigned arg3, unsigned arg4);
    static bool function13(unsigned arg0, bool arg1, bool arg2, unsigned arg3, int arg4);
    static unsigned function14(bool arg0, unsigned arg1, unsigned arg2, int arg3, int arg4);

    inline static bool variable0{};
    inline static float variable1{};
    inline static unsigned variable2{};
    inline static short variable3{};
    inline static bool variable4{};
    inline static double variable5{};
    inline static int variable6{};
    inline static double variable7{};
    inline static short variable8{};
    inline static unsigned variable9{};
    inline static int variable10{};
    inline static double variable11{};
    inline static short variable12{};
    inline static float variable13{};
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
