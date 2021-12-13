#pragma once

// Generated with seed '88005553548'

#include "../../Common.h"

#include "Class1.h"
#include "Class2.h"
#include "Class20.h"
#include "Class21.h"
#include "Class34.h"
#include "Class37.h"
#include "Class42.h"
#include "Class49.h"
#include "Class50.h"
#include "Class51.h"
#include "Class52.h"
#include "Class61.h"
#include "Class64.h"
#include "Class65.h"
#include "Class79.h"
#include "Class80.h"
#include "Class85.h"
#include "Class94.h"
#include "Class96.h"
#include "Class98.h"

class Class13
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, bool arg1, unsigned arg2, bool arg3, short arg4);
    int method1(short arg0, float arg1, bool arg2, float arg3, int arg4);
    short method2(short arg0, int arg1, double arg2, unsigned arg3, short arg4);
    short method3(float arg0, bool arg1, short arg2, bool arg3, unsigned arg4);
    float method4(float arg0, int arg1, bool arg2, bool arg3, float arg4);
    unsigned method5(unsigned arg0, unsigned arg1, short arg2, unsigned arg3, unsigned arg4);
    void method6(unsigned arg0, short arg1, int arg2, int arg3, int arg4);
    bool method7(int arg0, bool arg1, unsigned arg2, double arg3, double arg4);
    double method8(float arg0, bool arg1, double arg2, short arg3, int arg4);
    void method9(bool arg0, float arg1, bool arg2, unsigned arg3, double arg4);
    float method10(float arg0, double arg1, float arg2, short arg3, double arg4);
    void method11(unsigned arg0, unsigned arg1, bool arg2, short arg3, int arg4);
    int method12(int arg0, short arg1, double arg2, int arg3, short arg4);
    void method13(short arg0, int arg1, short arg2, double arg3, float arg4);
    bool method14(int arg0, bool arg1, bool arg2, int arg3, bool arg4);

    float memberVariable0{};
    unsigned memberVariable1{};
    unsigned memberVariable2{};
    short memberVariable3{};
    float memberVariable4{};
    double memberVariable5{};
    int memberVariable6{};
    double memberVariable7{};
    bool memberVariable8{};
    unsigned memberVariable9{};
    short memberVariable10{};
    short memberVariable11{};
    short memberVariable12{};
    float memberVariable13{};
    unsigned memberVariable14{};

    static unsigned function0(double arg0, int arg1, short arg2, short arg3, unsigned arg4);
    static unsigned function1(bool arg0, float arg1, float arg2, double arg3, unsigned arg4);
    static bool function2(unsigned arg0, double arg1, bool arg2, bool arg3, short arg4);
    static bool function3(double arg0, float arg1, int arg2, unsigned arg3, bool arg4);
    static void function4(short arg0, double arg1, unsigned arg2, bool arg3, bool arg4);
    static float function5(float arg0, bool arg1, bool arg2, bool arg3, float arg4);
    static bool function6(int arg0, unsigned arg1, bool arg2, short arg3, short arg4);
    static void function7(double arg0, bool arg1, int arg2, unsigned arg3, bool arg4);
    static float function8(float arg0, float arg1, bool arg2, float arg3, unsigned arg4);
    static short function9(short arg0, bool arg1, short arg2, short arg3, unsigned arg4);
    static void function10(int arg0, float arg1, bool arg2, double arg3, int arg4);
    static bool function11(int arg0, float arg1, unsigned arg2, unsigned arg3, bool arg4);
    static short function12(float arg0, short arg1, double arg2, float arg3, double arg4);
    static void function13(float arg0, double arg1, double arg2, int arg3, float arg4);
    static unsigned function14(int arg0, int arg1, bool arg2, unsigned arg3, double arg4);

    inline static double variable0{};
    inline static int variable1{};
    inline static short variable2{};
    inline static unsigned variable3{};
    inline static bool variable4{};
    inline static unsigned variable5{};
    inline static int variable6{};
    inline static float variable7{};
    inline static int variable8{};
    inline static int variable9{};
    inline static float variable10{};
    inline static double variable11{};
    inline static short variable12{};
    inline static double variable13{};
    inline static short variable14{};
};
