#pragma once

// Generated with seed '88005553625'

#include "../../Common.h"

#include "ClassWithBindings3.h"
#include "ClassWithBindings7.h"
#include "ClassWithBindings20.h"
#include "ClassWithBindings24.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings34.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings39.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings61.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings75.h"
#include "ClassWithBindings83.h"
#include "ClassWithBindings84.h"
#include "ClassWithBindings95.h"
#include "ClassWithBindings96.h"
#include "ClassWithBindings97.h"

class ClassWithBindings90
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
    void method0(double arg0, bool arg1, float arg2, double arg3, short arg4);
    void method1(double arg0, double arg1, short arg2, int arg3, float arg4);
    void method2(double arg0, double arg1, bool arg2, short arg3, float arg4);
    int method3(int arg0, int arg1, unsigned arg2, int arg3, bool arg4);
    void method4(bool arg0, int arg1, int arg2, int arg3, float arg4);
    void method5(short arg0, unsigned arg1, short arg2, unsigned arg3, short arg4);
    short method6(bool arg0, double arg1, unsigned arg2, unsigned arg3, short arg4);
    void method7(bool arg0, int arg1, double arg2, short arg3, double arg4);
    double method8(bool arg0, double arg1, float arg2, bool arg3, float arg4);
    float method9(float arg0, short arg1, float arg2, int arg3, float arg4);
    void method10(short arg0, int arg1, short arg2, bool arg3, float arg4);
    int method11(short arg0, bool arg1, int arg2, int arg3, bool arg4);
    void method12(unsigned arg0, unsigned arg1, short arg2, short arg3, int arg4);
    short method13(double arg0, short arg1, float arg2, float arg3, unsigned arg4);
    void method14(int arg0, int arg1, bool arg2, bool arg3, double arg4);

    short memberVariable0{};
    short memberVariable1{};
    bool memberVariable2{};
    int memberVariable3{};
    short memberVariable4{};
    double memberVariable5{};
    unsigned memberVariable6{};
    float memberVariable7{};
    float memberVariable8{};
    unsigned memberVariable9{};
    double memberVariable10{};
    double memberVariable11{};
    unsigned memberVariable12{};
    bool memberVariable13{};
    float memberVariable14{};

    static void function0(double arg0, short arg1, float arg2, short arg3, double arg4);
    static void function1(short arg0, float arg1, short arg2, short arg3, int arg4);
    static void function2(short arg0, double arg1, short arg2, float arg3, double arg4);
    static void function3(bool arg0, bool arg1, double arg2, unsigned arg3, double arg4);
    static bool function4(double arg0, double arg1, bool arg2, int arg3, bool arg4);
    static void function5(bool arg0, int arg1, double arg2, float arg3, unsigned arg4);
    static bool function6(short arg0, unsigned arg1, bool arg2, short arg3, double arg4);
    static void function7(short arg0, int arg1, float arg2, unsigned arg3, int arg4);
    static void function8(short arg0, int arg1, short arg2, bool arg3, float arg4);
    static int function9(int arg0, bool arg1, short arg2, bool arg3, unsigned arg4);
    static unsigned function10(double arg0, int arg1, short arg2, unsigned arg3, unsigned arg4);
    static void function11(bool arg0, bool arg1, double arg2, bool arg3, bool arg4);
    static void function12(double arg0, unsigned arg1, short arg2, int arg3, int arg4);
    static double function13(double arg0, bool arg1, int arg2, double arg3, bool arg4);
    static bool function14(bool arg0, double arg1, bool arg2, float arg3, bool arg4);

    inline static unsigned variable0{};
    inline static double variable1{};
    inline static int variable2{};
    inline static float variable3{};
    inline static bool variable4{};
    inline static float variable5{};
    inline static double variable6{};
    inline static int variable7{};
    inline static short variable8{};
    inline static bool variable9{};
    inline static short variable10{};
    inline static unsigned variable11{};
    inline static bool variable12{};
    inline static bool variable13{};
    inline static bool variable14{};

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
