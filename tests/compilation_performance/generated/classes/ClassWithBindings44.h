#pragma once

// Generated with seed '88005553579'

#include "../../Common.h"

#include "ClassWithBindings1.h"
#include "ClassWithBindings3.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings7.h"
#include "ClassWithBindings21.h"
#include "ClassWithBindings24.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings30.h"
#include "ClassWithBindings37.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings41.h"
#include "ClassWithBindings43.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings56.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings82.h"
#include "ClassWithBindings92.h"
#include "ClassWithBindings95.h"
#include "ClassWithBindings97.h"

class ClassWithBindings44
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(bool arg0, bool arg1, float arg2, unsigned arg3, float arg4);
    bool method1(float arg0, bool arg1, float arg2, unsigned arg3, double arg4);
    void method2(bool arg0, bool arg1, unsigned arg2, int arg3, bool arg4);
    void method3(float arg0, bool arg1, float arg2, double arg3, unsigned arg4);
    short method4(float arg0, short arg1, int arg2, float arg3, float arg4);
    void method5(float arg0, double arg1, bool arg2, unsigned arg3, bool arg4);
    void method6(int arg0, short arg1, short arg2, double arg3, float arg4);
    short method7(bool arg0, short arg1, int arg2, float arg3, double arg4);
    void method8(int arg0, float arg1, unsigned arg2, bool arg3, double arg4);
    float method9(double arg0, bool arg1, double arg2, float arg3, double arg4);
    void method10(double arg0, float arg1, double arg2, bool arg3, unsigned arg4);
    bool method11(double arg0, bool arg1, bool arg2, int arg3, float arg4);
    void method12(bool arg0, short arg1, double arg2, short arg3, unsigned arg4);
    void method13(unsigned arg0, double arg1, unsigned arg2, double arg3, bool arg4);
    float method14(bool arg0, float arg1, float arg2, short arg3, bool arg4);

    double memberVariable0{};
    unsigned memberVariable1{};
    int memberVariable2{};
    int memberVariable3{};
    bool memberVariable4{};
    int memberVariable5{};
    float memberVariable6{};
    unsigned memberVariable7{};
    bool memberVariable8{};
    unsigned memberVariable9{};
    bool memberVariable10{};
    int memberVariable11{};
    int memberVariable12{};
    bool memberVariable13{};
    unsigned memberVariable14{};

    static void function0(short arg0, unsigned arg1, unsigned arg2, float arg3, double arg4);
    static void function1(unsigned arg0, float arg1, float arg2, float arg3, short arg4);
    static unsigned function2(double arg0, int arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    static void function3(unsigned arg0, bool arg1, short arg2, float arg3, int arg4);
    static void function4(short arg0, unsigned arg1, short arg2, float arg3, float arg4);
    static float function5(float arg0, float arg1, bool arg2, double arg3, unsigned arg4);
    static void function6(short arg0, double arg1, float arg2, float arg3, int arg4);
    static short function7(short arg0, float arg1, bool arg2, short arg3, double arg4);
    static bool function8(double arg0, float arg1, int arg2, bool arg3, bool arg4);
    static double function9(bool arg0, int arg1, double arg2, bool arg3, int arg4);
    static void function10(float arg0, int arg1, bool arg2, float arg3, bool arg4);
    static short function11(short arg0, short arg1, short arg2, bool arg3, double arg4);
    static bool function12(bool arg0, short arg1, bool arg2, short arg3, bool arg4);
    static void function13(short arg0, int arg1, float arg2, unsigned arg3, int arg4);
    static void function14(unsigned arg0, unsigned arg1, double arg2, double arg3, bool arg4);

    inline static float variable0{};
    inline static unsigned variable1{};
    inline static unsigned variable2{};
    inline static bool variable3{};
    inline static int variable4{};
    inline static unsigned variable5{};
    inline static float variable6{};
    inline static bool variable7{};
    inline static double variable8{};
    inline static float variable9{};
    inline static int variable10{};
    inline static bool variable11{};
    inline static unsigned variable12{};
    inline static double variable13{};
    inline static int variable14{};
};
