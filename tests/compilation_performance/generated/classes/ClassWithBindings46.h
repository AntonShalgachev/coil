#pragma once

// Generated with seed '88005553581'

#include "../../Common.h"

#include "ClassWithBindings5.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings17.h"
#include "ClassWithBindings29.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings34.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings47.h"
#include "ClassWithBindings50.h"
#include "ClassWithBindings56.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings64.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings69.h"
#include "ClassWithBindings75.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings87.h"

class ClassWithBindings46
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
    double method0(unsigned arg0, double arg1, int arg2, double arg3, double arg4);
    void method1(short arg0, float arg1, double arg2, bool arg3, short arg4);
    void method2(short arg0, unsigned arg1, bool arg2, int arg3, unsigned arg4);
    bool method3(bool arg0, unsigned arg1, bool arg2, int arg3, bool arg4);
    unsigned method4(bool arg0, unsigned arg1, unsigned arg2, int arg3, unsigned arg4);
    unsigned method5(float arg0, double arg1, float arg2, unsigned arg3, double arg4);
    void method6(float arg0, int arg1, short arg2, int arg3, unsigned arg4);
    void method7(unsigned arg0, float arg1, bool arg2, bool arg3, double arg4);
    void method8(double arg0, short arg1, short arg2, short arg3, unsigned arg4);
    void method9(double arg0, float arg1, short arg2, double arg3, unsigned arg4);
    int method10(bool arg0, int arg1, unsigned arg2, unsigned arg3, short arg4);
    unsigned method11(unsigned arg0, float arg1, double arg2, unsigned arg3, bool arg4);
    void method12(unsigned arg0, float arg1, float arg2, double arg3, short arg4);
    unsigned method13(unsigned arg0, unsigned arg1, double arg2, unsigned arg3, float arg4);
    void method14(float arg0, unsigned arg1, short arg2, short arg3, double arg4);

    float memberVariable0{};
    short memberVariable1{};
    int memberVariable2{};
    short memberVariable3{};
    unsigned memberVariable4{};
    bool memberVariable5{};
    float memberVariable6{};
    float memberVariable7{};
    short memberVariable8{};
    bool memberVariable9{};
    unsigned memberVariable10{};
    double memberVariable11{};
    int memberVariable12{};
    float memberVariable13{};
    float memberVariable14{};

    static void function0(int arg0, int arg1, unsigned arg2, double arg3, double arg4);
    static void function1(float arg0, short arg1, short arg2, short arg3, short arg4);
    static void function2(bool arg0, float arg1, int arg2, int arg3, double arg4);
    static bool function3(double arg0, unsigned arg1, double arg2, int arg3, bool arg4);
    static void function4(int arg0, int arg1, float arg2, int arg3, float arg4);
    static void function5(float arg0, int arg1, float arg2, short arg3, double arg4);
    static unsigned function6(int arg0, bool arg1, bool arg2, int arg3, unsigned arg4);
    static int function7(bool arg0, int arg1, double arg2, bool arg3, int arg4);
    static void function8(float arg0, double arg1, float arg2, bool arg3, int arg4);
    static unsigned function9(bool arg0, bool arg1, float arg2, unsigned arg3, short arg4);
    static void function10(float arg0, unsigned arg1, bool arg2, double arg3, unsigned arg4);
    static void function11(short arg0, float arg1, short arg2, bool arg3, short arg4);
    static void function12(unsigned arg0, short arg1, unsigned arg2, bool arg3, bool arg4);
    static void function13(unsigned arg0, double arg1, unsigned arg2, short arg3, bool arg4);
    static bool function14(double arg0, bool arg1, bool arg2, short arg3, bool arg4);

    inline static double variable0{};
    inline static bool variable1{};
    inline static double variable2{};
    inline static double variable3{};
    inline static int variable4{};
    inline static bool variable5{};
    inline static float variable6{};
    inline static float variable7{};
    inline static bool variable8{};
    inline static bool variable9{};
    inline static unsigned variable10{};
    inline static double variable11{};
    inline static double variable12{};
    inline static float variable13{};
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
