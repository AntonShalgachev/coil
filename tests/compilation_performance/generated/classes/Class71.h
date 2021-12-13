#pragma once

// Generated with seed '88005553606'

#include "../../Common.h"

#include "Class4.h"
#include "Class8.h"
#include "Class9.h"
#include "Class13.h"
#include "Class26.h"
#include "Class41.h"
#include "Class46.h"
#include "Class47.h"
#include "Class59.h"
#include "Class60.h"
#include "Class62.h"
#include "Class66.h"
#include "Class67.h"
#include "Class74.h"
#include "Class75.h"
#include "Class85.h"
#include "Class86.h"
#include "Class90.h"
#include "Class91.h"
#include "Class95.h"

class Class71
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    unsigned method0(unsigned arg0, bool arg1, bool arg2, float arg3, bool arg4);
    void method1(float arg0, bool arg1, bool arg2, int arg3, bool arg4);
    void method2(int arg0, float arg1, int arg2, float arg3, short arg4);
    void method3(double arg0, unsigned arg1, float arg2, int arg3, bool arg4);
    int method4(int arg0, bool arg1, int arg2, double arg3, double arg4);
    void method5(double arg0, double arg1, unsigned arg2, short arg3, int arg4);
    unsigned method6(unsigned arg0, unsigned arg1, double arg2, float arg3, unsigned arg4);
    double method7(float arg0, double arg1, int arg2, float arg3, short arg4);
    unsigned method8(int arg0, unsigned arg1, int arg2, int arg3, unsigned arg4);
    void method9(short arg0, bool arg1, short arg2, bool arg3, float arg4);
    short method10(unsigned arg0, int arg1, short arg2, double arg3, double arg4);
    void method11(float arg0, bool arg1, short arg2, int arg3, unsigned arg4);
    void method12(bool arg0, unsigned arg1, double arg2, unsigned arg3, unsigned arg4);
    bool method13(double arg0, unsigned arg1, short arg2, bool arg3, double arg4);
    unsigned method14(int arg0, short arg1, unsigned arg2, bool arg3, short arg4);

    unsigned memberVariable0{};
    short memberVariable1{};
    unsigned memberVariable2{};
    bool memberVariable3{};
    bool memberVariable4{};
    double memberVariable5{};
    short memberVariable6{};
    short memberVariable7{};
    unsigned memberVariable8{};
    int memberVariable9{};
    double memberVariable10{};
    int memberVariable11{};
    bool memberVariable12{};
    int memberVariable13{};
    float memberVariable14{};

    static void function0(int arg0, unsigned arg1, int arg2, bool arg3, bool arg4);
    static int function1(bool arg0, int arg1, int arg2, bool arg3, float arg4);
    static short function2(unsigned arg0, int arg1, short arg2, short arg3, float arg4);
    static float function3(short arg0, int arg1, float arg2, float arg3, float arg4);
    static void function4(float arg0, short arg1, double arg2, bool arg3, int arg4);
    static void function5(short arg0, bool arg1, short arg2, float arg3, unsigned arg4);
    static void function6(unsigned arg0, unsigned arg1, float arg2, bool arg3, float arg4);
    static float function7(double arg0, bool arg1, float arg2, short arg3, unsigned arg4);
    static void function8(int arg0, double arg1, double arg2, short arg3, double arg4);
    static double function9(double arg0, float arg1, float arg2, unsigned arg3, double arg4);
    static void function10(unsigned arg0, unsigned arg1, unsigned arg2, int arg3, short arg4);
    static void function11(int arg0, int arg1, short arg2, float arg3, int arg4);
    static void function12(float arg0, float arg1, double arg2, bool arg3, unsigned arg4);
    static unsigned function13(unsigned arg0, short arg1, float arg2, bool arg3, float arg4);
    static int function14(double arg0, short arg1, int arg2, float arg3, float arg4);

    inline static unsigned variable0{};
    inline static short variable1{};
    inline static bool variable2{};
    inline static unsigned variable3{};
    inline static double variable4{};
    inline static float variable5{};
    inline static double variable6{};
    inline static int variable7{};
    inline static bool variable8{};
    inline static unsigned variable9{};
    inline static float variable10{};
    inline static short variable11{};
    inline static bool variable12{};
    inline static int variable13{};
    inline static short variable14{};
};
