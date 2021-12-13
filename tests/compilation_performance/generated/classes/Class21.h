#pragma once

// Generated with seed '88005553556'

#include "../../Common.h"

#include "Class0.h"
#include "Class5.h"
#include "Class9.h"
#include "Class26.h"
#include "Class37.h"
#include "Class39.h"
#include "Class41.h"
#include "Class42.h"
#include "Class48.h"
#include "Class49.h"
#include "Class54.h"
#include "Class57.h"
#include "Class58.h"
#include "Class59.h"
#include "Class68.h"
#include "Class71.h"
#include "Class73.h"
#include "Class75.h"
#include "Class90.h"
#include "Class98.h"

class Class21
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    void method0(unsigned arg0, float arg1, double arg2, double arg3, float arg4);
    void method1(unsigned arg0, unsigned arg1, bool arg2, short arg3, bool arg4);
    void method2(int arg0, bool arg1, double arg2, double arg3, short arg4);
    void method3(int arg0, bool arg1, float arg2, unsigned arg3, bool arg4);
    bool method4(unsigned arg0, double arg1, bool arg2, unsigned arg3, short arg4);
    short method5(short arg0, short arg1, int arg2, short arg3, bool arg4);
    bool method6(bool arg0, int arg1, short arg2, int arg3, bool arg4);
    void method7(float arg0, short arg1, double arg2, float arg3, bool arg4);
    void method8(short arg0, short arg1, short arg2, int arg3, double arg4);
    void method9(unsigned arg0, double arg1, int arg2, short arg3, unsigned arg4);
    void method10(int arg0, unsigned arg1, bool arg2, bool arg3, unsigned arg4);
    short method11(int arg0, int arg1, float arg2, short arg3, float arg4);
    void method12(short arg0, unsigned arg1, unsigned arg2, unsigned arg3, int arg4);
    void method13(unsigned arg0, bool arg1, short arg2, short arg3, double arg4);
    void method14(short arg0, short arg1, bool arg2, short arg3, int arg4);

    short memberVariable0{};
    bool memberVariable1{};
    bool memberVariable2{};
    int memberVariable3{};
    bool memberVariable4{};
    int memberVariable5{};
    float memberVariable6{};
    unsigned memberVariable7{};
    float memberVariable8{};
    int memberVariable9{};
    unsigned memberVariable10{};
    unsigned memberVariable11{};
    unsigned memberVariable12{};
    double memberVariable13{};
    double memberVariable14{};

    static float function0(float arg0, float arg1, unsigned arg2, double arg3, unsigned arg4);
    static void function1(short arg0, short arg1, int arg2, bool arg3, double arg4);
    static void function2(unsigned arg0, float arg1, short arg2, int arg3, short arg4);
    static void function3(short arg0, float arg1, bool arg2, int arg3, double arg4);
    static double function4(bool arg0, int arg1, unsigned arg2, double arg3, int arg4);
    static int function5(unsigned arg0, double arg1, double arg2, int arg3, bool arg4);
    static bool function6(bool arg0, bool arg1, double arg2, double arg3, double arg4);
    static unsigned function7(short arg0, float arg1, float arg2, unsigned arg3, float arg4);
    static int function8(int arg0, short arg1, double arg2, unsigned arg3, short arg4);
    static void function9(float arg0, bool arg1, int arg2, short arg3, double arg4);
    static float function10(float arg0, unsigned arg1, short arg2, double arg3, bool arg4);
    static void function11(bool arg0, bool arg1, float arg2, float arg3, short arg4);
    static void function12(unsigned arg0, float arg1, int arg2, double arg3, double arg4);
    static float function13(float arg0, int arg1, float arg2, double arg3, float arg4);
    static int function14(int arg0, int arg1, short arg2, double arg3, int arg4);

    inline static short variable0{};
    inline static unsigned variable1{};
    inline static bool variable2{};
    inline static int variable3{};
    inline static unsigned variable4{};
    inline static double variable5{};
    inline static int variable6{};
    inline static unsigned variable7{};
    inline static short variable8{};
    inline static bool variable9{};
    inline static short variable10{};
    inline static float variable11{};
    inline static bool variable12{};
    inline static double variable13{};
    inline static unsigned variable14{};
};
