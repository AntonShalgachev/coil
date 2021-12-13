#pragma once

// Generated with seed '88005553577'

#include "../../Common.h"

#include "Class4.h"
#include "Class10.h"
#include "Class13.h"
#include "Class19.h"
#include "Class22.h"
#include "Class23.h"
#include "Class25.h"
#include "Class33.h"
#include "Class35.h"
#include "Class39.h"
#include "Class40.h"
#include "Class46.h"
#include "Class54.h"
#include "Class56.h"
#include "Class64.h"
#include "Class67.h"
#include "Class69.h"
#include "Class72.h"
#include "Class75.h"
#include "Class79.h"

class Class42
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    double method0(double arg0, int arg1, unsigned arg2, short arg3, bool arg4);
    bool method1(bool arg0, bool arg1, bool arg2, bool arg3, float arg4);
    void method2(bool arg0, double arg1, float arg2, float arg3, int arg4);
    void method3(int arg0, short arg1, bool arg2, int arg3, short arg4);
    void method4(short arg0, int arg1, bool arg2, unsigned arg3, int arg4);
    int method5(int arg0, float arg1, unsigned arg2, int arg3, float arg4);
    void method6(int arg0, int arg1, short arg2, float arg3, unsigned arg4);
    void method7(bool arg0, short arg1, double arg2, short arg3, bool arg4);
    bool method8(bool arg0, short arg1, short arg2, int arg3, bool arg4);
    double method9(bool arg0, bool arg1, int arg2, double arg3, short arg4);
    void method10(unsigned arg0, bool arg1, double arg2, unsigned arg3, short arg4);
    short method11(float arg0, unsigned arg1, unsigned arg2, int arg3, short arg4);
    int method12(int arg0, int arg1, float arg2, double arg3, short arg4);
    float method13(unsigned arg0, int arg1, bool arg2, float arg3, short arg4);
    void method14(unsigned arg0, bool arg1, short arg2, int arg3, short arg4);

    int memberVariable0{};
    float memberVariable1{};
    bool memberVariable2{};
    bool memberVariable3{};
    int memberVariable4{};
    double memberVariable5{};
    double memberVariable6{};
    int memberVariable7{};
    float memberVariable8{};
    short memberVariable9{};
    float memberVariable10{};
    unsigned memberVariable11{};
    bool memberVariable12{};
    unsigned memberVariable13{};
    bool memberVariable14{};

    static void function0(bool arg0, float arg1, short arg2, int arg3, bool arg4);
    static void function1(unsigned arg0, short arg1, short arg2, bool arg3, int arg4);
    static void function2(float arg0, short arg1, float arg2, float arg3, float arg4);
    static void function3(float arg0, bool arg1, double arg2, double arg3, short arg4);
    static short function4(short arg0, unsigned arg1, int arg2, float arg3, short arg4);
    static float function5(float arg0, float arg1, bool arg2, bool arg3, bool arg4);
    static void function6(double arg0, short arg1, int arg2, bool arg3, short arg4);
    static void function7(short arg0, short arg1, short arg2, float arg3, short arg4);
    static void function8(unsigned arg0, int arg1, short arg2, double arg3, short arg4);
    static int function9(unsigned arg0, int arg1, float arg2, double arg3, unsigned arg4);
    static unsigned function10(int arg0, short arg1, bool arg2, unsigned arg3, unsigned arg4);
    static float function11(float arg0, int arg1, bool arg2, bool arg3, short arg4);
    static void function12(int arg0, double arg1, short arg2, double arg3, int arg4);
    static double function13(short arg0, short arg1, float arg2, double arg3, float arg4);
    static unsigned function14(unsigned arg0, unsigned arg1, unsigned arg2, int arg3, unsigned arg4);

    inline static short variable0{};
    inline static unsigned variable1{};
    inline static short variable2{};
    inline static short variable3{};
    inline static unsigned variable4{};
    inline static short variable5{};
    inline static double variable6{};
    inline static int variable7{};
    inline static unsigned variable8{};
    inline static bool variable9{};
    inline static short variable10{};
    inline static float variable11{};
    inline static short variable12{};
    inline static float variable13{};
    inline static float variable14{};
};
