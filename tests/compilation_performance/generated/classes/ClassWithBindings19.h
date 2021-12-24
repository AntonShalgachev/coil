#pragma once

// Generated with seed '88005553554'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings3.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings22.h"
#include "ClassWithBindings28.h"
#include "ClassWithBindings31.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings44.h"
#include "ClassWithBindings46.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings58.h"
#include "ClassWithBindings60.h"
#include "ClassWithBindings71.h"
#include "ClassWithBindings72.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings90.h"
#include "ClassWithBindings91.h"
#include "ClassWithBindings94.h"
#include "ClassWithBindings96.h"
#include "ClassWithBindings98.h"

class ClassWithBindings19
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
    void method0(short arg0, bool arg1, short arg2, unsigned arg3, short arg4);
    int method1(float arg0, int arg1, int arg2, unsigned arg3, int arg4);
    void method2(int arg0, int arg1, bool arg2, short arg3, int arg4);
    short method3(float arg0, float arg1, short arg2, bool arg3, unsigned arg4);
    unsigned method4(double arg0, bool arg1, double arg2, double arg3, unsigned arg4);
    bool method5(bool arg0, float arg1, int arg2, bool arg3, bool arg4);
    void method6(bool arg0, bool arg1, unsigned arg2, int arg3, int arg4);
    short method7(float arg0, double arg1, short arg2, bool arg3, double arg4);
    void method8(int arg0, bool arg1, unsigned arg2, unsigned arg3, float arg4);
    float method9(short arg0, float arg1, unsigned arg2, int arg3, float arg4);
    void method10(unsigned arg0, bool arg1, int arg2, bool arg3, bool arg4);
    short method11(unsigned arg0, unsigned arg1, bool arg2, int arg3, short arg4);
    void method12(int arg0, short arg1, double arg2, short arg3, bool arg4);
    double method13(double arg0, bool arg1, unsigned arg2, short arg3, bool arg4);
    double method14(unsigned arg0, float arg1, short arg2, short arg3, double arg4);

    float memberVariable0{};
    unsigned memberVariable1{};
    unsigned memberVariable2{};
    float memberVariable3{};
    int memberVariable4{};
    unsigned memberVariable5{};
    bool memberVariable6{};
    float memberVariable7{};
    float memberVariable8{};
    int memberVariable9{};
    unsigned memberVariable10{};
    short memberVariable11{};
    float memberVariable12{};
    int memberVariable13{};
    float memberVariable14{};

    static double function0(double arg0, float arg1, unsigned arg2, int arg3, unsigned arg4);
    static int function1(unsigned arg0, double arg1, float arg2, int arg3, bool arg4);
    static void function2(int arg0, int arg1, float arg2, double arg3, float arg4);
    static bool function3(unsigned arg0, short arg1, unsigned arg2, short arg3, bool arg4);
    static void function4(unsigned arg0, float arg1, short arg2, double arg3, bool arg4);
    static void function5(double arg0, unsigned arg1, double arg2, double arg3, float arg4);
    static void function6(unsigned arg0, double arg1, float arg2, bool arg3, unsigned arg4);
    static void function7(unsigned arg0, double arg1, short arg2, float arg3, int arg4);
    static int function8(int arg0, float arg1, short arg2, unsigned arg3, short arg4);
    static void function9(int arg0, int arg1, float arg2, bool arg3, unsigned arg4);
    static int function10(float arg0, short arg1, int arg2, unsigned arg3, unsigned arg4);
    static float function11(short arg0, float arg1, double arg2, float arg3, float arg4);
    static void function12(unsigned arg0, bool arg1, double arg2, bool arg3, int arg4);
    static void function13(int arg0, float arg1, short arg2, int arg3, float arg4);
    static float function14(int arg0, float arg1, bool arg2, double arg3, float arg4);

    inline static int variable0{};
    inline static float variable1{};
    inline static float variable2{};
    inline static double variable3{};
    inline static int variable4{};
    inline static unsigned variable5{};
    inline static unsigned variable6{};
    inline static float variable7{};
    inline static double variable8{};
    inline static bool variable9{};
    inline static int variable10{};
    inline static double variable11{};
    inline static double variable12{};
    inline static short variable13{};
    inline static double variable14{};

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
