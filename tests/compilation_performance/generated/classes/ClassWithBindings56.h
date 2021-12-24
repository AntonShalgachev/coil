#pragma once

// Generated with seed '88005553591'

#include "../../Common.h"

#include "ClassWithBindings0.h"
#include "ClassWithBindings8.h"
#include "ClassWithBindings14.h"
#include "ClassWithBindings18.h"
#include "ClassWithBindings19.h"
#include "ClassWithBindings20.h"
#include "ClassWithBindings24.h"
#include "ClassWithBindings25.h"
#include "ClassWithBindings32.h"
#include "ClassWithBindings38.h"
#include "ClassWithBindings49.h"
#include "ClassWithBindings53.h"
#include "ClassWithBindings59.h"
#include "ClassWithBindings63.h"
#include "ClassWithBindings68.h"
#include "ClassWithBindings70.h"
#include "ClassWithBindings77.h"
#include "ClassWithBindings91.h"
#include "ClassWithBindings94.h"
#include "ClassWithBindings98.h"

class ClassWithBindings56
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
    void method0(bool arg0, float arg1, int arg2, bool arg3, int arg4);
    void method1(short arg0, double arg1, double arg2, bool arg3, short arg4);
    short method2(short arg0, int arg1, short arg2, double arg3, double arg4);
    void method3(unsigned arg0, int arg1, short arg2, float arg3, unsigned arg4);
    void method4(float arg0, int arg1, int arg2, float arg3, bool arg4);
    short method5(bool arg0, unsigned arg1, int arg2, double arg3, short arg4);
    void method6(double arg0, bool arg1, unsigned arg2, int arg3, short arg4);
    void method7(short arg0, unsigned arg1, float arg2, double arg3, short arg4);
    float method8(short arg0, float arg1, bool arg2, float arg3, double arg4);
    void method9(unsigned arg0, short arg1, short arg2, bool arg3, int arg4);
    void method10(bool arg0, short arg1, float arg2, unsigned arg3, int arg4);
    unsigned method11(float arg0, bool arg1, short arg2, short arg3, unsigned arg4);
    void method12(double arg0, float arg1, int arg2, unsigned arg3, short arg4);
    void method13(float arg0, double arg1, int arg2, unsigned arg3, bool arg4);
    short method14(short arg0, unsigned arg1, short arg2, short arg3, bool arg4);

    bool memberVariable0{};
    short memberVariable1{};
    int memberVariable2{};
    bool memberVariable3{};
    double memberVariable4{};
    float memberVariable5{};
    unsigned memberVariable6{};
    int memberVariable7{};
    int memberVariable8{};
    double memberVariable9{};
    unsigned memberVariable10{};
    int memberVariable11{};
    short memberVariable12{};
    bool memberVariable13{};
    short memberVariable14{};

    static void function0(float arg0, double arg1, unsigned arg2, int arg3, short arg4);
    static unsigned function1(float arg0, unsigned arg1, int arg2, unsigned arg3, float arg4);
    static void function2(unsigned arg0, unsigned arg1, short arg2, double arg3, bool arg4);
    static void function3(bool arg0, float arg1, float arg2, float arg3, float arg4);
    static double function4(int arg0, float arg1, unsigned arg2, double arg3, int arg4);
    static void function5(bool arg0, short arg1, unsigned arg2, unsigned arg3, unsigned arg4);
    static void function6(short arg0, short arg1, bool arg2, short arg3, bool arg4);
    static void function7(short arg0, short arg1, short arg2, double arg3, short arg4);
    static void function8(float arg0, int arg1, unsigned arg2, bool arg3, short arg4);
    static double function9(double arg0, double arg1, float arg2, bool arg3, int arg4);
    static void function10(double arg0, double arg1, double arg2, unsigned arg3, bool arg4);
    static float function11(double arg0, short arg1, double arg2, float arg3, double arg4);
    static void function12(int arg0, int arg1, double arg2, double arg3, unsigned arg4);
    static void function13(float arg0, float arg1, short arg2, short arg3, double arg4);
    static void function14(float arg0, bool arg1, bool arg2, int arg3, unsigned arg4);

    inline static bool variable0{};
    inline static float variable1{};
    inline static bool variable2{};
    inline static double variable3{};
    inline static double variable4{};
    inline static int variable5{};
    inline static int variable6{};
    inline static short variable7{};
    inline static float variable8{};
    inline static int variable9{};
    inline static double variable10{};
    inline static float variable11{};
    inline static float variable12{};
    inline static int variable13{};
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
