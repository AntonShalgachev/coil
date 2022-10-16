#pragma once

namespace coil
{
    float strtof(const char* s, char** p);
    double strtod(const char* s, char** p);
    long double strtold(const char* s, char** p);

    long strtol(const char* s, char** p, int base);
    unsigned long strtoul(const char* s, char** p, int base);
    long long strtoll(const char* s, char** p, int base);
    unsigned long long strtoull(const char* s, char** p, int base);
}
