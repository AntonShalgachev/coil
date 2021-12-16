#pragma once

// Generated with seed '88005553551'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings3.h"
#include "ClassWithBindings5.h"
#include "ClassWithBindings9.h"
#include "ClassWithBindings12.h"
#include "ClassWithBindings15.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings20.h"
#include "ClassWithBindings27.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings33.h"
#include "ClassWithBindings35.h"
#include "ClassWithBindings40.h"
#include "ClassWithBindings52.h"
#include "ClassWithBindings65.h"
#include "ClassWithBindings74.h"
#include "ClassWithBindings87.h"
#include "ClassWithBindings88.h"
#include "ClassWithBindings95.h"
#include "ClassWithBindings96.h"

class ClassWithBindings16
{
public:
    void work();

#ifdef DEBUG_BINDINGS
    void registerBindings(GeneralBindings& bindings);
#endif

    static std::optional<float> workInternally(std::vector<std::string> const& values);

private:
    short method0(double arg0, double arg1, bool arg2, short arg3, double arg4);
    bool method1(bool arg0, short arg1, float arg2, bool arg3, bool arg4);
    unsigned method2(short arg0, double arg1, unsigned arg2, short arg3, unsigned arg4);
    int method3(short arg0, bool arg1, double arg2, int arg3, float arg4);
    void method4(double arg0, int arg1, bool arg2, double arg3, double arg4);
    void method5(double arg0, float arg1, double arg2, bool arg3, unsigned arg4);
    short method6(int arg0, bool arg1, short arg2, short arg3, double arg4);
    short method7(short arg0, bool arg1, double arg2, short arg3, unsigned arg4);
    void method8(double arg0, bool arg1, float arg2, unsigned arg3, int arg4);
    int method9(float arg0, int arg1, double arg2, int arg3, float arg4);
    void method10(float arg0, bool arg1, int arg2, bool arg3, double arg4);
    void method11(int arg0, short arg1, short arg2, unsigned arg3, float arg4);
    void method12(float arg0, bool arg1, short arg2, double arg3, float arg4);
    bool method13(short arg0, int arg1, bool arg2, double arg3, bool arg4);
    unsigned method14(double arg0, short arg1, bool arg2, short arg3, unsigned arg4);

    int memberVariable0{};
    short memberVariable1{};
    int memberVariable2{};
    double memberVariable3{};
    int memberVariable4{};
    bool memberVariable5{};
    float memberVariable6{};
    short memberVariable7{};
    unsigned memberVariable8{};
    double memberVariable9{};
    bool memberVariable10{};
    unsigned memberVariable11{};
    int memberVariable12{};
    double memberVariable13{};
    float memberVariable14{};

    static void function0(unsigned arg0, double arg1, double arg2, short arg3, short arg4);
    static double function1(double arg0, short arg1, short arg2, bool arg3, bool arg4);
    static unsigned function2(short arg0, unsigned arg1, float arg2, int arg3, float arg4);
    static bool function3(bool arg0, short arg1, int arg2, unsigned arg3, bool arg4);
    static bool function4(bool arg0, bool arg1, int arg2, double arg3, float arg4);
    static double function5(short arg0, bool arg1, int arg2, double arg3, bool arg4);
    static double function6(unsigned arg0, double arg1, double arg2, double arg3, float arg4);
    static void function7(double arg0, unsigned arg1, double arg2, short arg3, int arg4);
    static unsigned function8(unsigned arg0, double arg1, double arg2, short arg3, bool arg4);
    static void function9(short arg0, double arg1, short arg2, float arg3, double arg4);
    static int function10(float arg0, int arg1, double arg2, int arg3, int arg4);
    static void function11(int arg0, unsigned arg1, int arg2, bool arg3, unsigned arg4);
    static void function12(unsigned arg0, float arg1, bool arg2, unsigned arg3, bool arg4);
    static short function13(double arg0, short arg1, bool arg2, unsigned arg3, int arg4);
    static void function14(unsigned arg0, unsigned arg1, int arg2, double arg3, unsigned arg4);

    inline static short variable0{};
    inline static double variable1{};
    inline static unsigned variable2{};
    inline static bool variable3{};
    inline static bool variable4{};
    inline static unsigned variable5{};
    inline static float variable6{};
    inline static float variable7{};
    inline static double variable8{};
    inline static float variable9{};
    inline static double variable10{};
    inline static unsigned variable11{};
    inline static bool variable12{};
    inline static double variable13{};
    inline static bool variable14{};
};
