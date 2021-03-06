#pragma once

#include "Config.h"

#include <string>
#include <string_view>

namespace coil
{
    // This is the expected signature of the class
    // template<typename T>
    // struct TypeName
    // {
    //     static std::string_view name()
    //     {
    //         return "T";
    //     }
    // };

    template<typename T, typename = void>
    struct TypeName;
}

namespace coil
{
#define COIL_CREATE_TYPE_NAME_DECLARATION(T) \
    template<>                               \
    struct TypeName<T>                       \
    {                                        \
        static std::string_view name();      \
    }

#define COIL_CREATE_TYPE_NAME_DEFINITION(T, str) \
    std::string_view TypeName<T>::name()         \
    {                                            \
        return str;                              \
    }

    COIL_CREATE_TYPE_NAME_DECLARATION(bool);

#if COIL_CONFIG_BASIC_TYPENAME
    COIL_CREATE_TYPE_NAME_DECLARATION(void);
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
    COIL_CREATE_TYPE_NAME_DECLARATION(std::string);
    COIL_CREATE_TYPE_NAME_DECLARATION(std::string_view);
#endif // COIL_CONFIG_BASIC_TYPENAME
}
