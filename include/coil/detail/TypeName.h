#pragma once

#include "StringView.h"

namespace coil
{
    // This is the expected signature of the class
    // template<typename T>
    // struct TypeName
    // {
    //     static coil::StringView name()
    //     {
    //         return "T";
    //     }
    // };

    template<typename T, typename = void>
    struct TypeName;
}

#define COIL_CREATE_TYPE_NAME_DECLARATION(T) \
    template<>                               \
    struct coil::TypeName<T>                 \
    {                                        \
        static StringView name();            \
    }

#define COIL_CREATE_TYPE_NAME_DEFINITION(T, str) \
    coil::StringView coil::TypeName<T>::name()   \
    {                                            \
        return str;                              \
    }

#define COIL_CREATE_TYPE_NAME(T, str) \
    template<>                        \
    struct coil::TypeName<T>          \
    {                                 \
        static StringView name()      \
        {                             \
            return str;               \
        }                             \
    }

namespace coil
{
    class String;
    class StringView;
}

COIL_CREATE_TYPE_NAME_DECLARATION(void);
COIL_CREATE_TYPE_NAME_DECLARATION(bool);

COIL_CREATE_TYPE_NAME_DECLARATION(char);
COIL_CREATE_TYPE_NAME_DECLARATION(signed char);
COIL_CREATE_TYPE_NAME_DECLARATION(unsigned char);
COIL_CREATE_TYPE_NAME_DECLARATION(short);
COIL_CREATE_TYPE_NAME_DECLARATION(unsigned short);
COIL_CREATE_TYPE_NAME_DECLARATION(int);
COIL_CREATE_TYPE_NAME_DECLARATION(unsigned int);
COIL_CREATE_TYPE_NAME_DECLARATION(long);
COIL_CREATE_TYPE_NAME_DECLARATION(unsigned long);
COIL_CREATE_TYPE_NAME_DECLARATION(long long);
COIL_CREATE_TYPE_NAME_DECLARATION(unsigned long long);

COIL_CREATE_TYPE_NAME_DECLARATION(float);
COIL_CREATE_TYPE_NAME_DECLARATION(double);
COIL_CREATE_TYPE_NAME_DECLARATION(long double);

COIL_CREATE_TYPE_NAME_DECLARATION(coil::String);
COIL_CREATE_TYPE_NAME_DECLARATION(coil::StringView);
