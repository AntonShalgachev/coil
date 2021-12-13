#pragma once

// Generated with seed '88005553626'

#include "../../Common.h"

#include "Class12.h"
#include "Class23.h"
#include "Class24.h"
#include "Class25.h"
#include "Class26.h"
#include "Class27.h"
#include "Class29.h"
#include "Class30.h"
#include "Class46.h"
#include "Class49.h"
#include "Class57.h"
#include "Class58.h"
#include "Class62.h"
#include "Class63.h"
#include "Class73.h"
#include "Class77.h"
#include "Class80.h"
#include "Class81.h"
#include "Class82.h"
#include "Class86.h"

class Class91
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    int method0(float arg0, double arg1, int arg2, int arg3, float arg4);
    void method1(bool arg0, unsigned arg1, int arg2, bool arg3, int arg4);
    void method2(bool arg0, unsigned arg1, int arg2, double arg3, double arg4);
    double method3(double arg0, bool arg1, bool arg2, int arg3, float arg4);
    void method4(int arg0, int arg1, unsigned arg2, float arg3, int arg4);
    bool method5(bool arg0, int arg1, short arg2, unsigned arg3, double arg4);
    void method6(short arg0, double arg1, double arg2, int arg3, unsigned arg4);
    short method7(double arg0, short arg1, bool arg2, short arg3, bool arg4);
    void method8(short arg0, unsigned arg1, unsigned arg2, double arg3, unsigned arg4);
    void method9(bool arg0, short arg1, double arg2, short arg3, short arg4);
    double method10(double arg0, int arg1, bool arg2, unsigned arg3, unsigned arg4);
    void method11(bool arg0, short arg1, float arg2, unsigned arg3, short arg4);
    void method12(unsigned arg0, short arg1, short arg2, float arg3, int arg4);
    void method13(bool arg0, double arg1, float arg2, int arg3, double arg4);
    short method14(short arg0, bool arg1, short arg2, float arg3, short arg4);

    unsigned memberVariable0{};
    float memberVariable1{};
    short memberVariable2{};
    short memberVariable3{};
    int memberVariable4{};
    int memberVariable5{};
    short memberVariable6{};
    int memberVariable7{};
    int memberVariable8{};
    float memberVariable9{};
    bool memberVariable10{};
    float memberVariable11{};
    int memberVariable12{};
    short memberVariable13{};
    short memberVariable14{};

    static void function0(unsigned arg0, int arg1, double arg2, double arg3, float arg4);
    static void function1(unsigned arg0, unsigned arg1, float arg2, unsigned arg3, short arg4);
    static double function2(float arg0, double arg1, int arg2, double arg3, float arg4);
    static void function3(unsigned arg0, short arg1, bool arg2, float arg3, short arg4);
    static double function4(float arg0, short arg1, bool arg2, short arg3, double arg4);
    static void function5(float arg0, unsigned arg1, double arg2, int arg3, bool arg4);
    static double function6(int arg0, bool arg1, short arg2, double arg3, bool arg4);
    static void function7(double arg0, int arg1, double arg2, short arg3, int arg4);
    static int function8(short arg0, bool arg1, short arg2, unsigned arg3, int arg4);
    static unsigned function9(int arg0, short arg1, unsigned arg2, bool arg3, float arg4);
    static void function10(float arg0, float arg1, bool arg2, float arg3, unsigned arg4);
    static int function11(int arg0, double arg1, double arg2, double arg3, short arg4);
    static void function12(int arg0, bool arg1, short arg2, double arg3, bool arg4);
    static float function13(int arg0, int arg1, short arg2, double arg3, float arg4);
    static double function14(double arg0, short arg1, unsigned arg2, double arg3, unsigned arg4);

    inline static float variable0{};
    inline static bool variable1{};
    inline static double variable2{};
    inline static double variable3{};
    inline static unsigned variable4{};
    inline static float variable5{};
    inline static int variable6{};
    inline static int variable7{};
    inline static double variable8{};
    inline static short variable9{};
    inline static short variable10{};
    inline static int variable11{};
    inline static unsigned variable12{};
    inline static float variable13{};
    inline static double variable14{};
};
